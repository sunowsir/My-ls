/*************************************************************************
	> File Name: init.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月31日 星期五 00时33分29秒
 ************************************************************************/

#include <cstdlib>
#include <string.h>
#include <iostream>
#include "files.h"

void init_opert(_opert_ *opert) {
    
    opert->comd_a = false;
    opert->comd_l = false;
    opert->comd_d = false;
    strcpy(opert->str_path, getenv("PWD"));

}

