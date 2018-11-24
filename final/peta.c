#include "peta.h"
#include <string.h>
#include <stdio.h>

PETA Ruang1;
PETA Ruang2;
PETA Ruang3;
PETA Dapur;
PETA RuangAktif;


void MakePETA(PETA *peta, char *namafile, int room, POINT pos){
	MakeMATRIKS(&Mat(*peta), 8, 8);
	BacaFileMATRIKS(&Mat(*peta), namafile);
	Pos(*peta) = pos;
	Rum(*peta) = room;
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

void UpdatePETA(PETA *peta, int X){
	PLAYER P;
	START_PLAYER(&P);
	Posisi(P) = Pos(*peta);
	int room  = Rum(*peta);

	UPDATE_POSISI_PLAYER(&P, X, &room);

	if (room!=Rum(*peta)){
			//player pindah ruangan, simpan apapun yang terjadi di RuangAktif ke Ruang yang bersesuaian
			//jika awalnya rum1, update rum1...
			if 			(Rum(*peta)==1) Dapur = *peta;
			else if (Rum(*peta)==2) Ruang1 = *peta;
			else if (Rum(*peta)==3) Ruang2 = *peta;
			else									  Ruang3  = *peta;
			//sekarang update peta, jika room=1, fetch data dapur
			if 			(room==1) *peta = Dapur;
			else if (room==2) *peta = Ruang1;
			else if (room==3) *peta = Ruang2;
			else							*peta = Ruang3;
			Rum(*peta) = room;
	};
	//kalau sudah update room peta, atau ngga ubah room peta, tinggal
	Pos(*peta) = Posisi(P);
};

void TulisPETA(PETA peta){
// mencetak peta ke layar
		ElmtMat(Mat(peta), Pos(peta)) = 'P';
		TulisMATRIKS(Mat(peta));
}