/*************************************************************************
	> File Name: Total.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年09月17日 星期一 17时02分23秒
 ************************************************************************/

#include <dirent.h>
#include <iostream>
#include <sys/stat.h>

#include "files.h"

double Total(char * path) {

    DIR *dir = opendir(path);
    struct dirent *ptr1;
    struct stat file_date1;
    
    double size_total = 0;

    while ((ptr1 = readdir(dir)) != NULL) {
        lstat(ptr1->d_name, &file_date1);
        size_total += (double)file_date1.st_blocks;
    }

    size_total = size_total * 512.0 / 1024.0;
    return size_total;
}

