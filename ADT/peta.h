#ifndef PETA_H
#define PETA_H

#include "matriks.h"

/* objek non-player di peta */
#define UBIN    '_'
#define KKOSONG 'C'
#define KPENUH  'X'
#define MEJA		'M'

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
// akan menjadikan kursi penuh di sebuah meja,
// di dekat posisi player P, menjadi kosong kembali

void UpdatePeta(MATRIKS*M, POINT P);

#endif
