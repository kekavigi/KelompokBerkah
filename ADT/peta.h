#ifndef PETA_H
#define PETA_H

#include "matriks.h"

/* objek non-player di peta */
#define UBIN		'_'
#define KKOSONG 	'C'
#define KPENUH		'X'
#define MEJA		'M'

POINT FindMeja(MATRIKS M, POINT P);
// return posisi meja di sekitar point P;

int CountObjek(MATRIKS M, POINT P, char objek);
// return banyaknya objek di sekitar point P;

void IsiKursiKosong(MATRIKS *M, POINT P, int minta);
// akan mengisi kursi kosong sebanyak yang diminta
// (kalau bisa) di dekat posisi player P;

void JadikanKursiKosong(MATRIKS *M, POINT P);
// akan menjadikan kursi penuh di sebuah meja,
// di dekat posisi player P, menjadi kosong kembali

#endif