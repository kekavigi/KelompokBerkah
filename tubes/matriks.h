/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris (koordinat X) dan kolom (absis Y)*/
#define XMin 1
#define XMax 20
#define YMin 1
#define YMax 20

typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[XMax+1][YMax+1];
    int NXEff; /* banyaknya/ukuran koordinat X yg terdefinisi */
	int NYEff; /* banyaknya/ukuran absis Y yg terdefinisi */
} MATRIKS;
/* NXEff <= 1 dan NYEff <= 1 */
/* Indeks matriks yang digunakan: [XMin..XMax][YMin..YMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri bawah" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int X, int Y, MATRIKS * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran X x Y di "ujung kiri bawah" memori */
/* I.S. B dan K adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NXEff(M) (M).NXEff
#define NYEff(M) (M).NYEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxX (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxY (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxX (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxY (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M);
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/

void TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

#endif