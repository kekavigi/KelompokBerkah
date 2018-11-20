#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int kode, MATRIKS * M){
	NXEff(*M) = 8;
	NYEff(*M) = 8;
	Kode(*M)  = kode;}

indeks GetFirstIdx_X (MATRIKS M){return XMin;}
indeks GetFirstIdx_Y (MATRIKS M){return YMin;}
indeks GetLastIdx_X  (MATRIKS M){return NXEff(M);}
indeks GetLastIdx_Y  (MATRIKS M){return NYEff(M);}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS *M){
	int x,y;
	START("ruang1.txt");

	for (y=1; y<=8; y++){
		for (x=1; x<=8; x++){
			Elmt(*M,MakePOINT(x,y)) = CC;
			ADV();
		}
	}
}

void TulisMATRIKS (MATRIKS M){
	int x, y;
	POINT P;

	P = MakePOINT(1,1);

	for (y=1; y<=8; y++){
		for (x=1; x<=8; x++){
			printf("%c", Elmt(M,MakePOINT(x,y)));
		}
		printf("\n");
	}
}

