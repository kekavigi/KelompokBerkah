#ifndef DATARESEP_H
#define DATARESEP_H 

#include "matriks.h"
#include "matriks.c"

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/
#define DataUndef -999

typedef struct{
    int Code;
    int Price; 
} Orders;




extern char bahan[25][20];

extern char menu[9][20];

//Customer emptyOrder;


#endif
