#include "peta.h"
#include <string.h>

#include <stdio.h>

void MakePETA(PETA *peta, char *namafile, POINT spawn){
// membentuk sebuah peta ruangan, pokoke lengkap cuk!
	//urusan nama file
	char namafilecharmap[50];
	char namafilevaluemap[50];
	strcpy(namafilecharmap, namafile);
	strcpy(namafilevaluemap, namafile);
	strcat(namafilecharmap, ".txt");
	strcat(namafilevaluemap, "int.txt");

	MakeMATRIKS(&CharMap(*peta), 8, 8);
	BacaFileMATRIKS(&CharMap(*peta), namafilecharmap);
  MakeMATRIKS(&ValueMap(*peta), 8, 8);
	BacaFileMATRIKS(&ValueMap(*peta), namafilevaluemap);

	Spawn(*peta) = spawn;
}

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

void JadikanKursiKosong(MATRIKS *M, POINT meja){
// akan menjadikan semua state kursi penuh menjadi kursi kosong
// I.S : sisi left, down, right, dan up meja terdefinisi
// F.S : jelas
	if (Elmt(*M,UP(meja))==KPENUH) Elmt(*M,UP(meja))=KKOSONG;
	if (Elmt(*M,LEFT(meja))==KPENUH) Elmt(*M,LEFT(meja))=KKOSONG;
	if (Elmt(*M,DOWN(meja))==KPENUH) Elmt(*M,DOWN(meja))=KKOSONG;
	if (Elmt(*M,RIGHT(meja))==KPENUH) Elmt(*M,RIGHT(meja))=KKOSONG;
}

void UpdatePosisiPlayer(MATRIKS*M, POINT P){}
// akan mengubah posisi player ke posisi baru P
// I.S : P terdefinisi untuk player berpindah
// F.S : jelas

void TulisPETA(PETA peta){
		Elmt(CharMap(peta), LokPlayer(peta)) = 'P';
		TulisMATRIKS(CharMap(peta));
}

void GantiPeta(MATRIKS *M, int move){}
// akan mengubah peta yang aktif dimainkan
// F.S : jika move valid di suatu peta, peta akan berubah menjadi peta yang baru
