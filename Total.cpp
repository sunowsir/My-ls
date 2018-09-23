/*************************************************************************
	> File Name: Total.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年09月17日 星期一 17时02分23秒
 ************************************************************************/

#include <dirent.h>
#include <string.h>
#include <iostream>
#include <sys/stat.h>

#include "files.h"

#define max(x, y) (x > y) ? x : y

int cmp(const void *a, const void *b) {
    // Sort names by case insensitive.
    return strcasecmp((*(_fdata_ *)a).fname, (*(_fdata_ *)b).fname);
}

void Total(char *path, _mdata_ *mdata) {
    // Through 'readdir' can get the information of a file under a path pointed to by the 'DIR' type pointer and the informathon will be save in dirent structure.
    DIR *dir = opendir(path);

    if (dir == NULL) {
        printf("Open Directory failed.");
        exit(1);
    }

    // Through file name can get the details of a file and save in stat structure.
    struct dirent *ptr;

    double size_total = 0;
    int num = 0;

    while ((ptr = readdir(dir)) != NULL) {

        //save name
        strcpy(mdata->fdata[num].fname, ptr->d_name);
        
        // Get file information.
        Get_NPIFD(path, &mdata->fdata[num], "l");
        
        mdata->maxl_pwn = max(mdata->maxl_pwn, (int)strlen(mdata->fdata[num].pwn));
        mdata->maxl_pwg = max(mdata->maxl_pwg, (int)strlen(mdata->fdata[num].pwg));
        size_total += mdata->fdata[num].blocks;
        
        FILE *fp = fopen("/dev/null", "w");
        mdata->maxl_nlink = max(mdata->maxl_nlink, fprintf(fp, "%d", mdata->fdata[num].nlink));
        mdata->maxl_size = max(mdata->maxl_size, fprintf(fp, "%d", mdata->fdata[num].size));
        mdata->maxl_mon = max(mdata->maxl_mon, fprintf(fp, "%d", mdata->fdata[num].mon));
        mdata->maxl_mday = max(mdata->maxl_mday, fprintf(fp, "%d", mdata->fdata[num].mday));
        fclose(fp);
        
        num++;
    }

    closedir(dir);

    // Sort file name.
    qsort(mdata->fdata, num, sizeof(mdata->fdata[0]), cmp);

    size_total = size_total / 2.0;
    mdata->total_blocks = (int)size_total;
    mdata->fdnum = num;

    return;
}

#undef max



