/*************************************************************************
	> File Name: Perfo.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月31日 星期五 15时04分07秒
 ************************************************************************/

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#include "files.h"

using std::cout;
using std::endl;
using std::string;

void per_opert(int argc, _opert_ *opert, _mdata_ *mdata) {
    cout << "总用量 "  << mdata->total_blocks << endl;

    for (int i = 0; i < mdata->fdnum; i++) {
        struct _fdata_ *fd = &mdata->fdata[i];

        if (opert->comd_a == false) {
            if (fd->fname[0] == '.') {
                continue;
            }
        }

        char *output = &fd->fname[0];
        if (opert->comd_l == true) {
            output = NULL;
        }

        if (opert->comd_d == true) {
            // Determine if the current file is a path.
            if (fd->tp[0] == 'd') {
                continue;
            }
        }

        // output.
        if (output != NULL) {
            cout << output << endl;
        }
        else {
            // Output file type, file owner permissions, permissions of the same group of users, permissions of other users.
            printf("%s ", fd->tp);
            
            // Output file numbers of link.
            printf("%*.d ", mdata->maxl_nlink, fd->nlink);
            
            // Output file owner and file group.
            printf("%-*s %-*s ", mdata->maxl_pwn, fd->pwn, mdata->maxl_pwg, fd->pwg);

            // Output file size.
            printf("%*.d ", mdata->maxl_size, fd->size);

            
            // Out put the last access time of the file.
            printf("%*.d月  %0*d %02d:%02d \033[1;%dm%s\033[0m", mdata->maxl_mon, fd->mon, mdata->maxl_mday, fd->mday, fd->hour, fd->min, fd->color, fd->fname);

            if (fd->tp[0] == 'l') {
                char source[10240] = "";
                struct _fdata_ sourcefd; 
                Get_NPIFD(source, "s", &sourcefd);
                readlink(fd->fname, source, 10000);
                
                printf(" -> \033[1;%dm%s\033[0m", sourcefd.color, source);
            }
            printf("\n");
        }

    }

    cout << "total numbers:" << mdata->fdnum << endl;
}
