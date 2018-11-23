#ifndef PETA_H
#define PETA_H

#include "matriks.h"
#include "array.h"

#define Mat(peta) (peta).mat
#define Pos(peta) (peta).pos
#define StatMeja(peta) (peta).statmej

/* objek non-player di peta */
#define UBIN    '_'
#define KKOSONG 'C'
#define KPENUH  'X'
#define MEJA    'M'

typedef struct {
	MATRIKS mat;    /* berisi karakter karakter yang bakal di print */
	POINT P;					/* posisi player */
	TabInt statmej;  /* anggap indeks meja sebagai nomor meja, setiap indeks berisi banyak kursi yang penuh */
} PETA;

void MakePETA(PETA *peta, char *namafile, POINT pos);
// membentuk sebuah peta ruangan, pokoke lengkap cuk!

POINT FindMeja(MATRIKS M, POINT P);
// akan mengembalikan posisi meja yang dekat dengan player P
/* I.S.: player di samping customer
				jika customer di left player, ada meja di left customer
				jika customer di down player, ada meja di down customer
				...*/

int CountObjek(MATRIKS M, POINT P, char objek);
// akan mengembalikan banyaknya objek objek di sisi (jika ada) up, left, down, dan right player;

void IsiKursiKosong(MATRIKS *M, POINT P, int minta);
// akan mengubah state kursi kosong ke kursi penuh sebanyak minta
/* I.S : player P ada disamping customer
   F.S : jika kapasitas kursi memungkinkan, state kursi kosong akan diubah
		 		 jika tidak, tidak ada yang terjadi */

void JadikanKursiKosong(MATRIKS *M, POINT P);
// akan menjadikan semua state kursi penuh menjadi kursi kosong
// I.S : sisi left, down, right, dan up meja terdefinisi
// F.S : jelas

void UpdatePosisiPlayer(MATRIKS*M, POINT P);
// akan mengubah posisi player ke posisi baru P
// I.S : P terdefinisi untuk player berpindah
// F.S : jelas

void TulisPETA(PETA peta);

//void GantiPeta(MATRIKS *M, int move);
// akan mengubah peta yang aktif dimainkan
// F.S : jika move valid di suatu peta, peta akan berubah menjadi peta yang baru

#endif
