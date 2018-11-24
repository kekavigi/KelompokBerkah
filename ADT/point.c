/*
ADT POINT Untuk TUBES
dibuat oleh Fio
tanggal 18/11/2018
revisi 1
*/

#include "point.h"
#include <stdio.h>
#include <stdlib.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	POINT P;

	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */

	float x,y;

	scanf("%d%*c%d", &x,&y);
	*P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

	printf("(%d,%d)",Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	return(Absis(P) == 0);
}

boolean IsDinding (POINT P){
/* Menghasilkan true jika P terletak di luar dinding (yang pasti lebih dari 8) */
	return((Absis(P)>8) || (Ordinat(P)>8));
}

boolean IsVal(POINT P){
/* Menghasilkan True jika titik berada di map (bukan 0,Y. Bukan di X,0. Bukan di Border Map (dinding)) */

	return (!IsOnSbY(P) && !IsOnSbX(P) && !IsOrigin(P) && !IsDinding(P));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT UP (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT P1;

	P1 = MakePOINT(Absis(P), Ordinat(P)+1);
	if(IsVal(P1)){
		return P1;
	}else{
		printf("Offside Mas!\n");
		return P;
	}
}

POINT DOWN (POINT P){
/* Mengirim salinan P dengan ordinat dikurang satu */

	POINT P1;

	P1 = MakePOINT(Absis(P), Ordinat(P)-1);
	if(IsVal(P1)){
		return P1;
	}else{
		printf("Offside Mas!\n");
		return P;
	}
}

POINT LEFT (POINT P){
/* Mengirim salinan P dengan absis dikurang satu  */

	POINT P1;

	P1 = MakePOINT(Absis(P)-1, Ordinat(P));
	if(IsVal(P1)){
		return P1;
	}else{
		printf("Offside Mas!\n");
		return P;
	}
}

POINT RIGHT (POINT P){
/* Mengirim salinan P dengan absis ditambah satu  */

	POINT P1;

	P1 = MakePOINT(Absis(P)+1, Ordinat(P));
	if(IsVal(P1)){
		return P1;
	}else{
		printf("Offside Mas!\n");
		return P;
	}
}
