/*************************************************************************
	> File Name: Get_TPPCF.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年09月17日 星期一 16时37分09秒
 ************************************************************************/

#include <iostream>
#include <sys/stat.h>

#include "files.h"
using std::cout;
using std::endl;

_fdata_ Get_TPPCF(char *fname) {

    struct _fdata_ fdata;

    init_fdata(&fdata);

    struct stat file_dates;
    long int mode;
    char *tp;
    int *co;
    lstat(fname, &file_dates);
    mode = file_dates.st_mode;
    tp = fdata.tp;
    co = &fdata.color;

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

    return fdata;

}

