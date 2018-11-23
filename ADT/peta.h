#ifndef PETA_H
#define PETA_H

#include "matriks.h"

/* objek non-player di peta */
#define CharMap(peta) (peta).char_map
#define ValueMap(peta) (peta).value_map
#define LokPlayer(peta) (peta).lokplayer

#define UBIN    '_'
#define KKOSONG 'C'
#define KPENUH  'X'
#define MEJA    'M'

typedef struct {
	MATRIKS char_map;  /* berisi karakter karakter yang bakal di print */
    MATRIKS value_map;   /* berisi angka angka yg mungkin diperlukan */
	POINT lokplayer;      /* lokasi player saat ini */
} PETA;

void MakePETA(PETA *peta, char *namafile, POINT spawn);
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

void GantiPeta(MATRIKS *M, int move);
// akan mengubah peta yang aktif dimainkan
// F.S : jika move valid di suatu peta, peta akan berubah menjadi peta yang baru

#endif
