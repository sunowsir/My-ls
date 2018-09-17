/*************************************************************************
	> File Name: files.h
	> Author:    sunowsir
	> Mail:      sunowsir@protonmail.com
	> Created:   2018年08月31日 星期五 00时23分40秒
 ************************************************************************/

#ifndef _FILES_H
#define _FILES_H

// Storage parameter analysis result.
struct _opert_ {
    bool comd_a;
    bool comd_l;
    bool comd_p;
    bool comd_d;
    bool comd_suffix;
    bool comd_name;
    char str_path[102400];
    char str_suffix[102400];
    char str_name[102400];
    char str_way[102400];
};

// Type, Permissions and Print color of file
struct _fdata_ {
    int color;
    char tp[11];
};

// Initialization _opert_ .
void init_opert(_opert_ *);

//Initialization _fdata_
void init_fdata(_fdata_ *);

// Parsing parameters function.
void pars_par(int, char **, _opert_ *);

// Performing operations function.
void per_opert(int, _opert_ *);

// Get type , permissions and print color of file .
_fdata_ Get_TPPCF(char *);

// Get file used total
double Total(char *);

#endif
