/* 
ADT POINT Untuk TUBES
dibuat oleh Fio
tanggal 18/11/2018
revisi 1
*/

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y */
boolean IsDinding (POINT P);
/* Menghasilkan true jika P terletak pada dinding (yang pasti lebih dari 8) */
boolean IsVal(POINT P);
/* Menghasilkan True jika titik berada di map (bukan 0,Y. Bukan di X,0. Bukan di Border Map (dinding)) */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT UP (POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */              
POINT DOWN (POINT P);
/* Mengirim salinan P dengan ordinat dikurang satu */
POINT LEFT (POINT P);
/* Mengirim salinan P dengan absis dikurang satu  */
POINT RIGHT (POINT P);
/* Mengirim salinan P dengan absis ditambah satu  */

#endif