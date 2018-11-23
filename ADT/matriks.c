#include "matriks.h"
#include <stdio.h>
#include <string.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (MATRIKS * M, int X, int Y){
// membentuk matriks 'kosong' berukuran X x Y
	NXEff(*M) = X;
	NYEff(*M) = Y;
}

indeks GetFirstIdx_X (MATRIKS M){return XMin;}
indeks GetFirstIdx_Y (MATRIKS M){return YMin;}
indeks GetLastIdx_X  (MATRIKS M){return NXEff(M);}
indeks GetLastIdx_Y  (MATRIKS M){return NYEff(M);}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaFileMATRIKS (MATRIKS *M, char *namafile){
// akan membentuk sebuah matriks berukuran NXEff x NYEff dari file namafile
// I.S : M sudah dibentuk, namafile ada
// F.S : jelas
	int x,y;
	START(namafile);
	for (y=1; y<=8; y++){
		for (x=1; x<=8; x++){
				Elmt(*M,MakePOINT(x,y)) = CC;
				ADV();
		}
	}
}

void TulisMATRIKS (MATRIKS M){
// akan mencetak matriks M ke layar
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
