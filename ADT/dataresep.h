#ifndef DATARESEP_H
#define DATARESEP_H 

#define DataUndef -999

typedef struct{
    int Code;
    int Price; 
} Orders;

#define Elm(R,i) (R).Mem[(i)]

extern char bahan[25][20];

extern char menu[9][20];



#endif
