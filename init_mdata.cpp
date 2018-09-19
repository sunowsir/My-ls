/*************************************************************************
	> File Name: init_mdata.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年09月19日 星期三 15时26分10秒
 ************************************************************************/

#include <iostream>
#include "files.h"

void init_mdata(_mdata_ *mdata) {
    mdata->fdnum = 0;
    mdata->maxl_nlink = 0;
    mdata->maxl_pwn = 0;
    mdata->maxl_pwg = 0;
    mdata->maxl_size = 0;
    mdata->maxl_mon = 0;
    mdata->maxl_mday = 0;
    mdata->total_blocks = 0;

    return;
}
