/*************************************************************************
	> File Name: Parsp.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月31日 星期五 11时30分20秒
 ************************************************************************/

#include <cstring>
#include <iostream>
#include "files.h"

void pars_par(int argc, char **argv, _opert_ *opert) {
    
    for (int i = 1; i < argc; i++) {
        
        if (argv[i][0] == '-' && argv[i][1] != '-') {
            for (int j = 1; j < (int)strlen(argv[i]); j++) {
                switch (argv[i][j]) {
                    case 'a' : 
                        opert->comd_a = true;
                        break;
                    case 'l' : 
                        opert->comd_l = true;
                        break;
                    case 'p' : 
                        opert->comd_p = true;
                        strcpy(opert->str_path, argv[i + 1]);
                    if (opert->str_path[strlen(opert->str_path) - 1] != '/') {
                        strcat(opert->str_path, "/");
                    }
                        break;
                    case 'd' : 
                        opert->comd_d = true;
                        break;
                }
            }
        }
        
    }

}
