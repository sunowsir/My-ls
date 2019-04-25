/*************************************************************************
	> File Name: Get_TPPCF.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年09月17日 星期一 16时37分09秒
 ************************************************************************/

#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <iostream>
#include <sys/stat.h>

#include "files.h"

// Get Need Print Informathon of File or Directory.
void Get_NPIFD(char *path, _fdata_ *fdata, const char *stat_t) {
    //Initialization _fdata_
    init_fdata(fdata);

    // Get file detailed properties based on path and file name.
    // Get Informathon of file or directory : 28 - 32.
    struct stat file_st;
    char get_stat[800];
    strcpy(get_stat, path);
    strcat(get_stat, fdata->fname);

    if (*stat_t == 'l') {
        lstat(get_stat, &file_st);
    } else {
        stat(get_stat, &file_st);
    }
    
    // Get type of file or directory : 47 - 68.

    char *tp;
    int *co;
    long int mode;

    tp = fdata->tp;
    co = &fdata->color;
    mode = file_st.st_mode;

#ifdef S_ISLNK
#ifdef S_ISSOCK

    if (S_ISDIR(mode)) {
        tp[0]  = 'd';
        *co = 34;
    }
    else if (S_ISCHR(mode)){
        tp[0] = 'c';
        *co = 36;
    }
    else if (S_ISBLK(mode)) {
        tp[0] = 'b';
        *co = 35;
    }
    else if (S_ISFIFO(mode)) {
        tp[0] = 'p';
    }
    else if (S_ISLNK(mode)) {
        tp[0] = 'l';
        *co = 39;
    }
    else if (S_ISSOCK(mode)) {
        tp[0] = 's';
    }

#endif
#endif
    
    // Get permissions : 75 - 112 .

    if (S_IRUSR == (S_IRUSR & mode)) {
        tp[1] = 'r';
    }
    if (S_IWUSR == (S_IWUSR & mode)) {
        tp[2] = 'w';
    }
    if (S_IXUSR == (S_IXUSR & mode)) {
        tp[3] = 'x';
        if (*co == 0) {
            *co = 32;
        }
    }

    if (S_IRGRP == (S_IRGRP & mode)) {
        tp[4] = 'r';
    }
    if (S_IWGRP == (S_IWGRP & mode)) {
        tp[5] = 'w';
    }
    if (S_IXGRP == (S_IXGRP & mode)) {
        tp[6] = 'x';
        if (*co == 0) {
            *co = 32;
        }
    }

    if (S_IROTH == (S_IROTH & mode)) {
        tp[7] = 'r';
    }
    if (S_IWOTH == (S_IWOTH & mode)) {
        tp[8] = 'w';
    }
    if (S_IXOTH == (S_IXOTH & mode)) {
        tp[9] = 'x';
        if (*co == 0) {
            *co = 32;
        }
    }

    // Get link numbers.

    fdata->nlink = (int)file_st.st_nlink;

    // Use the 'getpwuid' and 'getgrgid' to get the username and group name via 'uid' and 'gid'.

    struct passwd *pwu = getpwuid(file_st.st_uid);
    struct group *pwg = getgrgid(file_st.st_gid);

    strcpy(fdata->pwn, pwu->pw_name);
    strcpy(fdata->pwg, pwg->gr_name);

    // Get blocks.
    
    fdata->blocks = (double)file_st.st_blocks;

    // Get size.
    
    fdata->size = file_st.st_size;

    // Use 'localtime' function to parse 'st_time' in the 'lstat' structure to get the last access time of the file.
    
    struct tm *tim = localtime(&file_st.st_atime);

    fdata->mon = tim->tm_mon + 1;
    fdata->mday = tim->tm_mday;
    fdata->hour = tim->tm_hour;
    fdata->min = tim->tm_min;

    return;
}

