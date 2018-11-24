#ifndef PETA_H
#define PETA_H

#include "matriks.h"
#include "array.h"

#define Mat(peta) (peta).mat
#define Pos(peta) (peta).pos
#define Stat(peta) (peta).statmej
/* objek non-player di peta */
#define UBIN    '_'
#define KKOSONG 'C'
#define KPENUH  'X'
#define MEJA    'M'

typedef struct {
	MATRIKS mat;    /* berisi karakter karakter yang bakal di print */
	POINT pos;			/* posisi player */
	int room;				/* nomor room */
	TabInt stat; /* anggap indeks meja sebagai nomor meja, setiap indeks berisi banyak kursi yang penuh */
} PETA;

// Variabel Global
PETA Ruang1, Ruang2, Ruang3, Dapur, RuangAktif;

// Pendefinisian LEFT, UP, DOWN, RIGHT.
POINT FLEFT (POINT P);
POINT FUP (POINT P);
POINT FDOWN (POINT P);
POINT FRIGHT (POINT P);

void MakePETA(PETA *peta, char *namafile, int room, POINT pos);
// membentuk sebuah peta ruangan, pokoke lengkap cuk!

POINT FindMeja(MATRIKS M, POINT P);
// akan mengembalikan posisi meja yang dekat dengan player P
/* I.S.: player di samping customer
				jika customer di left player, ada meja di left customer
				jika customer di down player, ada meja di down customer
				...*/

int CountObjek(MATRIKS M, POINT P, char objek);
// akan mengembalikan banyaknya objek objek di sisi (jika ada) up, left, down, dan right point P;

void IsiKursiKosong(MATRIKS *M, POINT meja, int minta);
// akan mengubah state kursi kosong ke kursi penuh sebanyak minta
/* I.S : player P ada disamping customer
   F.S : jika kapasitas kursi memungkinkan, state kursi kosong akan diubah
		 		 jika tidak, tidak ada yang terjadi */

void JadikanKursiKosong(MATRIKS *M, POINT P);
// akan menjadikan semua state kursi penuh menjadi kursi kosong
// I.S : sisi left, down, right, dan up meja terdefinisi
// F.S : jelas

void UpdatePETA(PETA *peta, int X);
// mengubah menjadi peta yang baru akibat gerakan X

void UpdatePelangganPETA(PETA *peta, NoMeja daftarpelanggan);
// mengubah menjadi peta yang baru akibat kesabaran pelanggan

void TulisPETA(PETA peta);
// mencetak peta ke layar

#endif
