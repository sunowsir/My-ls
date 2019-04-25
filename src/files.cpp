/*************************************************************************
	> File Name: files.cpp
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月31日 星期五 00时29分40秒
 ************************************************************************/

#include <iostream>
#include "files.h"

int main(int argc, char ** argv) {

    _opert_ opert;
    _mdata_ mdata;

    // initialization.
    init_opert(&opert);

    // initialization.
    init_mdata(&mdata);

    // Parsing parameters.
    pars_par(argc, argv, &opert);

    // Read directory and Performing operations.
    Total(opert.str_path, &mdata);

    // Output every files or directory information.
    per_opert(&opert, &mdata);

    return 0;
}
