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
    char str_path[1024];
};

// Type, Permissions and Print color of file
struct _fdata_ {
    int nlink;
    int size;
    int mon;
    int mday;
    int hour;
    int min;
    int color;
    double blocks;
    char tp[11];
    char fname[800];
    char pwn[100];
    char pwg[100];
};

struct _mdata_ {
  
    int fdnum;
    int maxl_nlink;
    int maxl_pwn;
    int maxl_pwg;
    int maxl_size;
    int maxl_mon;
    int maxl_mday;
    int total_blocks;
    struct _fdata_ fdata[1000];

};

// Initialization _opert_.
void init_opert(_opert_ *);

//Initialization _fdata_.
void init_fdata(_fdata_ *);

//Initialization _fdata_.
void init_mdata(_mdata_ *);

// Parsing parameters function.
void pars_par(int, char **, _opert_ *);

// Performing operations function.
void per_opert(_opert_ *, _mdata_ *);

// Get type , permissions and print color of file .
void Get_NPIFD(char *, _fdata_ *, const char *);

// Get file used total
void Total(char * ,_mdata_ *);

#endif
