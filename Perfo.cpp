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

void per_opert(int argc, _opert_ *opert) {

    int files_num = 0;
    DIR *dir = opendir(opert->str_path);

    if (dir == NULL) {
        cout << "Open Directory failed." << endl;
        return;
    }

    // Through 'readdir' can get the information of a file under a path pointed to by the 'DIR' type pointer and the informathon will be save in dirent structure.
    struct dirent *ptr;
    
    // Through file name can get the details of a file and save in stat structure.
    struct stat file_date;

    cout << "总用量 "  << (int)Total(opert->str_path) << endl;
    //printf("path:%s\n", opert->str_path);

    while ((ptr = readdir(dir)) != NULL) {
        if (opert->comd_a == false) {
            if (ptr->d_name[0] == '.') {
                continue;
            }
        }
        char *output = &ptr->d_name[0];
        if (opert->comd_l == true) {
            output = NULL;
        }

        // Get file detailed properties based on file name.
        lstat(ptr->d_name, &file_date);

        // Use the 'getpwuid' and 'getgrgid' to get the username and group name via 'uid' and 'gid'.
        struct passwd *pwu;
        struct group *pwg;
        pwu = getpwuid(file_date.st_uid);
        pwg = getgrgid(file_date.st_gid);

        if (opert->comd_d == true) {
            
            // Determine if the current file is a path.
            if ((file_date.st_mode & S_IFDIR) != S_IFDIR) {
                continue;
            }
        }

        // output.
        if (output != NULL) {
            cout << output << endl;
            files_num++;
        }
        else {

            // Use 'localtime' function to parse 'st_time' in the 'lstat' structure to get the last access time of the file.
            struct tm *tim = localtime(&file_date.st_atime);

            // Output file type, file owner permissions, permissions of the same group of users, permissions of other users.
            struct _fdata_ fdata = Get_TPPCF(ptr->d_name);
            printf("%s ", fdata.tp);
            //printf("tp:%s color:%d ", fdata.tp, fdata.color);

            
            // Output file numbers of link.
            printf("%d ", (int)file_date.st_nlink);
            
            // Output file owner and file group.
            printf("%s %s ", pwu->pw_name, pwg->gr_name);

            // Output file size.
            printf("%6.d ", (int)file_date.st_size);

            
            // Out put the last access time of the file.
            printf("%1.d月  %02d %02d:%02d \033[1;%dm%s\033[0m", tim->tm_mon, tim->tm_mday, tim->tm_hour, tim->tm_min, fdata.color, ptr->d_name);

            if (fdata.tp[0] == 'l') {
                char source[102400];
                struct _fdata_ sourcefd = Get_TPPCF(source);
                readlink(ptr->d_name, source, 102400);
                
                printf(" -> \033[1;%dm%s\033[0m", sourcefd.color, source);
            }
            printf("\n");

            files_num++;

        }

    }
    closedir(dir);
    cout << "total numbers:" << files_num << endl;

}
