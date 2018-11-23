/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "point.h"
#include "mesinkar.h"

/* Ukuran minimum dan maksimum baris (koordinat X) dan kolom (absis Y)*/
#define XMin 1
#define XMax 8
#define YMin 1
#define YMax 8

/* NXEff <= 1 dan NYEff <= 1 */
/* Indeks matriks yang digunakan: [XMin..XMax][YMin..YMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri bawah" */

typedef int indeks; /* indeks baris, kolom */
typedef struct {
	int Mem[XMax+1][YMax+1];
    int NXEff;		/* banyaknya/ukuran koordinat X yg terdefinisi */
	int NYEff;		/* banyaknya/ukuran absis Y yg terdefinisi */
} MATRIKS;

/* *** Selektor *** */
#define NXEff(M)  (M).NXEff
#define NYEff(M)  (M).NYEff
#define Elmt(M,P) (M).Mem[(P.X)][(P.Y)]

/* *** Selektor "DUNIA MATRIKS" *** */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxX (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxY (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxX (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxY (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (MATRIKS * M, int X, int Y);
// membentuk matriks 'kosong' berukuran X x Y

void BacaFileMATRIKS (MATRIKS *M, char *namafile);
// akan membentuk sebuah matriks berukuran NXEff x NYEff dari file namafile
// I.S : M sudah dibentuk, namafile ada
// F.S : jelas

void TulisMATRIKS (MATRIKS M);
// akan mencetak matriks M ke layar


#endif
