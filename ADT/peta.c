#include "peta.h"
#include "player.h"
#include "duduk.h"
#include "move.h"
#include <string.h>
#include <stdio.h>
#include "point.h"

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT FUP (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT P1 = MakePOINT(Absis(P), Ordinat(P)+1);
	if(IsVal(P1)) return P1;
	else	return P;
}

POINT FLEFT (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT P1 = MakePOINT(Absis(P)-1, Ordinat(P));
	if(IsVal(P1)) return P1;
	else	return P;
}

POINT FDOWN (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT P1 = MakePOINT(Absis(P), Ordinat(P)-1);
	if(IsVal(P1)) return P1;
	else	return P;
}

POINT FRIGHT (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT P1 = MakePOINT(Absis(P)+1, Ordinat(P));
	if (IsVal(P1)) return P1;
	else return P;
}


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
	if (ElmtMat(M,FUP(P))  ==objek)	 banyak++;
	if (ElmtMat(M,FLEFT(P))==objek)  banyak++;
	if (ElmtMat(M,FDOWN(P))==objek)  banyak++;
	if (ElmtMat(M,FRIGHT(P))==objek) banyak++;
	return banyak;
}

void IsiKursiKosong(MATRIKS *M, POINT meja, int minta){
// akan mengubah state kursi kosong ke kursi penuh sebanyak minta
//
	int banyakkosong = CountObjek(*M, meja, KKOSONG);
	if ((CountObjek(*M, meja, 'X')==0) && banyakkosong>=minta){
		if ((minta>0) && (ElmtMat(*M, FRIGHT(meja))==KKOSONG)){
			ElmtMat(*M, FRIGHT(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (ElmtMat(*M,FUP(meja))==KKOSONG)){
			ElmtMat(*M,FUP(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (ElmtMat(*M,FLEFT(meja))==KKOSONG)){
			ElmtMat(*M,FLEFT(meja))=KPENUH;
			minta--;}
		if ((minta>0) && (ElmtMat(*M, FUP(meja))==KKOSONG)){
			ElmtMat(*M, FUP(meja))=KPENUH;
			minta--;}
	};
}

void JadikanKursiKosong(MATRIKS *M, POINT meja){
// akan menjadikan semua state kursi penuh menjadi kursi kosong
// I.S : sisi left, down, right, dan up meja terdefinisi
// F.S : jelas
	if (ElmtMat(*M,FUP(meja))==KPENUH)    ElmtMat(*M,FUP(meja))=KKOSONG;
	if (ElmtMat(*M,FLEFT(meja))==KPENUH)  ElmtMat(*M,FLEFT(meja))=KKOSONG;
	if (ElmtMat(*M,FDOWN(meja))==KPENUH)  ElmtMat(*M,FDOWN(meja))=KKOSONG;
	if (ElmtMat(*M,FRIGHT(meja))==KPENUH) ElmtMat(*M,FRIGHT(meja))=KKOSONG;
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

void UpdatePelangganPETA(PETA *peta, NoMeja meja){
	// mengubah menjadi peta yang baru akibat kesabaran pelanggan
	//well, setiap room non-dapur punya empat meja, anggap
	POINT noA = MakePOINT(2,7);
	POINT noB = MakePOINT(7,7);
	POINT noC = MakePOINT(2,2);
	POINT noD = MakePOINT(7,2);
	// dan  so.. ini kode ugly bats dah
	if (!Avail(meja,1)  && !Sabar(meja,1))  JadikanKursiKosong(&Mat(Ruang1), noA);
	if (!Avail(meja,2)  && !Sabar(meja,2))  JadikanKursiKosong(&Mat(Ruang1), noB);
	if (!Avail(meja,3)  && !Sabar(meja,3))  JadikanKursiKosong(&Mat(Ruang1), noC);
	if (!Avail(meja,4)  && !Sabar(meja,4))  JadikanKursiKosong(&Mat(Ruang1), noD);
	if (!Avail(meja,5)  && !Sabar(meja,5))  JadikanKursiKosong(&Mat(Ruang2), noA);
	if (!Avail(meja,6)  && !Sabar(meja,6))  JadikanKursiKosong(&Mat(Ruang2), noB);
	if (!Avail(meja,7)  && !Sabar(meja,7))  JadikanKursiKosong(&Mat(Ruang2), noC);
	if (!Avail(meja,8)  && !Sabar(meja,8))  JadikanKursiKosong(&Mat(Ruang2), noD);
	if (!Avail(meja,9)  && !Sabar(meja,9))  JadikanKursiKosong(&Mat(Ruang3), noA);
	if (!Avail(meja,10) && !Sabar(meja,10)) JadikanKursiKosong(&Mat(Ruang3), noB);
	if (!Avail(meja,11) && !Sabar(meja,11)) JadikanKursiKosong(&Mat(Ruang3), noC);
	if (!Avail(meja,12) && !Sabar(meja,12)) JadikanKursiKosong(&Mat(Ruang3), noD);
}

void TulisPETA(PETA peta){
// mencetak peta ke layar
		ElmtMat(Mat(peta), Pos(peta)) = 'P';
		TulisMATRIKS(Mat(peta));
}
