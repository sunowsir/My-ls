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

    // initialization.
    init_opert(&opert);

    // Parsing parameters.
    pars_par(argc, argv, &opert);

    // Performing operations.
    per_opert(argc, &opert);

    return 0;
}
