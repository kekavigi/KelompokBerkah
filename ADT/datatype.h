#ifndef DATATYPE_H
#define DATATYPE_H 

#include "matriks.h"
#include "matriks.c"

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/
#define DataUndef -999

typedef struct{
    int Code;
    int Price; 
} Orders;

typedef struct{
    int NbPeople; //Jumlah orang dalam suatu kelompok
    int WaitTime; //Waktu menunggu di antrian
    int NbTable; //Nomor meja, jika belum mendapat meja maka bernilai TableUndef
    Orders Pesanan;
} Customer;

#define RMax 100
typedef struct{
  MATRIKS Mem[RMax+1];
} ROOM;

#define Elm(R,i) (R).Mem[(i)]

extern char bahan[25][20];

extern char menu[9][20];

//Customer emptyOrder;

/*
typedef struct{
    int TableTime; //Waktu sejak sudah duduk di meja.
    Order FoodOrder; // Berisi nama makanan/minuman yang dipesan,setiap meja hanya dapat memesan 1 jenis makanan/minuman saja.
    int NbTable; //Nomor Meja.
} Table;
*/

#endif
