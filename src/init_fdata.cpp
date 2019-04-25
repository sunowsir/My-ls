/*************************************************************************
	> File Name: init_fdata.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年09月17日 星期一 16时28分07秒
 ************************************************************************/

#include <string.h>
#include <iostream>
#include "files.h"

void init_fdata(_fdata_ *fdata) {
    char temp[] = "----------";
    strcpy(fdata->tp, temp);
    fdata->color = 0;
}
