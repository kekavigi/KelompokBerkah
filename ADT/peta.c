#include "peta.h"

POINT FindMeja(MATRIKS M, POINT P){
// akan mengembalikan posisi meja yang dekat dengan player P
/* I.S.: player di samping customer
				jika customer di left player, ada meja di left customer
				jika customer di down player, ada meja di down customer
				...*/
	if      ((!IsVal(UP(P)))   && (Elmt(M,UP(UP(P)))==MEJA))    	return UP(UP(P));
	else if ((!IsVal(LEFT(P))) && (Elmt(M,LEFT(LEFT(P)))==MEJA))  	return LEFT(LEFT(P));
	else if ((!IsVal(DOWN(P))) && (Elmt(M,DOWN(DOWN(P)))==MEJA))  	return DOWN(DOWN(P));
	else if ((!IsVal(RIGHT(P)))&& (Elmt(M,RIGHT(RIGHT(P)))==MEJA))	return RIGHT(RIGHT(P));
}

int CountObjek(MATRIKS M, POINT P, char objek){
// akan mengembalikan banyaknya objek objek di sisi (jika ada) up, left, down, dan right player;
	int banyak = 0;
	if ((!IsVal(UP(P)))    && (Elmt(M,UP(P))==objek))	 banyak++;
	if ((!IsVal(LEFT(P)))  && (Elmt(M,LEFT(P))==objek))  banyak++;
	if ((!IsVal(DOWN(P)))  && (Elmt(M,DOWN(P))==objek))  banyak++;
	if ((!IsVal(RIGHT(P))) && (Elmt(M,RIGHT(P))==objek)) banyak++;
	return banyak;
}

void IsiKursiKosong(MATRIKS *M, POINT P, int minta){
// akan mengubah state kursi kosong ke kursi penuh sebanyak minta
//
	POINT meja = FindMeja(*M, P);

	int banyakkosong = (CountObjek(*M, meja, 'C'));
	if ((CountObjek(*M, meja, 'X')==0) && banyakkosong>=minta){
		if ((minta>0) && (Elmt(*M,UP(meja))==KKOSONG)){
			Elmt(*M,UP(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (Elmt(*M,RIGHT(meja))==KKOSONG)){
			Elmt(*M,RIGHT(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (Elmt(*M,DOWN(meja)) ==KKOSONG)){
			Elmt(*M,DOWN(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (Elmt(*M,LEFT(meja)) ==KKOSONG)){
			Elmt(*M,LEFT(meja))=KPENUH;
			minta--;}
	};
}

void JadikanKursiKosong(MATRIKS *M, POINT P){
	POINT meja = FindMeja(*M,P);

	if (Elmt(*M,UP(P))==KPENUH) Elmt(*M,UP(P))=KKOSONG;
	if (Elmt(*M,LEFT(P))==KPENUH) Elmt(*M,LEFT(P))=KKOSONG;
	if (Elmt(*M,DOWN(P))==KPENUH) Elmt(*M,DOWN(P))=KKOSONG;
	if (Elmt(*M,RIGHT(P))==KPENUH) Elmt(*M,RIGHT(P))=KKOSONG;
}
// akan menjadikan semua kursi penuh di sebuah meja,
// yang di dekat posisi player P, menjadi kosong kembali
