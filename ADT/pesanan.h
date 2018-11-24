#ifndef PETA_H
#define PETA_H

#include "boolean.h"

#define IdxMax 100

/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

typedef int ElType; /* type indeks */
typedef int IdxType;  /* type elemen tabel */

typedef struct { 
	ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Number[IdxMax+1]; 
	int Neff;
} Pesanan; 

#define Neff(T)   (T).Neff
#define Number(T,i)   (T).Number[(i)]
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

int NbElmtP (Pesanan T);

IdxType SearchIdxP (Pesanan T, ElType X, int N);

void delPesanan(Pesanan *DaftarPesanan,ElType pesanan, int N);

void DelElmtP(Pesanan * T, ElType X, int N);

void AddElmtP(Pesanan * T, ElType X, int N);

void addPesanan(Pesanan *DaftarPesanan, ElType pesanan, int N );

#boolean cekPesananMeja(Pesanan DaftarPesanan, int P,int N);

#endif
