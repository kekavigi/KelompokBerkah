#include "peta.h"
#include <string.h>
#include <stdio.h>

void MakePETA(PETA *peta, char *namafile, POINT pos){
	MakeMATRIKS(&Mat(*peta), 8, 8);
	BacaFileMATRIKS(&Mat(*peta), *namafile);
	Pos(*peta) = spawn;
}

POINT FindMeja(MATRIKS M, POINT P){
// akan mengembalikan posisi meja yang dekat dengan player P
/* I.S.: player di samping customer
				jika customer di left player, ada meja di left customer
				jika customer di down player, ada meja di down customer
				...*/
	if      ((!IsVal(UP(P)))   && (ElmtMat(M,UP(UP(P)))==MEJA))    	return UP(UP(P));
	else if ((!IsVal(LEFT(P))) && (ElmtMat(M,LEFT(LEFT(P)))==MEJA))  	return LEFT(LEFT(P));
	else if ((!IsVal(DOWN(P))) && (ElmtMat(M,DOWN(DOWN(P)))==MEJA))  	return DOWN(DOWN(P));
	else if ((!IsVal(RIGHT(P)))&& (ElmtMat(M,RIGHT(RIGHT(P)))==MEJA))	return RIGHT(RIGHT(P));
}

int CountObjek(MATRIKS M, POINT P, char objek){
// akan mengembalikan banyaknya objek objek di sisi (jika ada) up, left, down, dan right player;
	int banyak = 0;
	if ((!IsVal(UP(P)))    && (ElmtMat(M,UP(P))==objek))	 banyak++;
	if ((!IsVal(LEFT(P)))  && (ElmtMat(M,LEFT(P))==objek))  banyak++;
	if ((!IsVal(DOWN(P)))  && (ElmtMat(M,DOWN(P))==objek))  banyak++;
	if ((!IsVal(RIGHT(P))) && (ElmtMat(M,RIGHT(P))==objek)) banyak++;
	return banyak;
}

void IsiKursiKosong(MATRIKS *M, POINT P, int minta){
// akan mengubah state kursi kosong ke kursi penuh sebanyak minta
//
	POINT meja = FindMeja(*M, P);

	int banyakkosong = (CountObjek(*M, meja, 'C'));
	if ((CountObjek(*M, meja, 'X')==0) && banyakkosong>=minta){
		if ((minta>0) && (ElmtMat(*M,UP(meja))==KKOSONG)){
			ElmtMat(*M,UP(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (ElmtMat(*M,RIGHT(meja))==KKOSONG)){
			ElmtMat(*M,RIGHT(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (ElmtMat(*M,DOWN(meja)) ==KKOSONG)){
			ElmtMat(*M,DOWN(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (ElmtMat(*M,LEFT(meja)) ==KKOSONG)){
			ElmtMat(*M,LEFT(meja))=KPENUH;
			minta--;}
	};
}

void JadikanKursiKosong(MATRIKS *M, POINT meja){
// akan menjadikan semua state kursi penuh menjadi kursi kosong
// I.S : sisi left, down, right, dan up meja terdefinisi
// F.S : jelas
	if (ElmtMat(*M,UP(meja))==KPENUH) ElmtMat(*M,UP(meja))=KKOSONG;
	if (ElmtMat(*M,LEFT(meja))==KPENUH) ElmtMat(*M,LEFT(meja))=KKOSONG;
	if (ElmtMat(*M,DOWN(meja))==KPENUH) ElmtMat(*M,DOWN(meja))=KKOSONG;
	if (ElmtMat(*M,RIGHT(meja))==KPENUH) ElmtMat(*M,RIGHT(meja))=KKOSONG;
}


void TulisPETA(PETA peta){
		ElmtMat(Mat(peta), Pos(peta)) = 'P';
		TulisMATRIKS(CharMap(peta));
}

//void GantiPeta(MATRIKS *M, int move){}
// akan mengubah peta yang aktif dimainkan
// F.S : jika move valid di suatu peta, peta akan berubah menjadi peta yang baru
