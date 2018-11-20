#include "matriks.h"
#include "boolean.h"

#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int X, int Y, MATRIKS * M){
	NXEff(*M) = X;
	NYEff(*M) = Y;}

boolean IsIdxValid (int i, int j){
	return ((XMin<=i) && (i<=XMax) && (YMin<=j) && (j<=YMax));}

indeks GFI_X (MATRIKS M){return XMin;}
indeks GFI_Y (MATRIKS M){return YMin;}
indeks GLI_X (MATRIKS M){return NXEff(M);}
indeks GLI_Y (MATRIKS M){return NYEff(M);}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	return ((XMin<=i) && (i<=NXEff(M)) && (YMin<=j) && (j<=NYEff(M)));}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS *M){
	int x, y;
	for (x=1; x<=NXEff(*M); x++){
		for (y=1; y<=NYEff(*M); y++){
			scanf("%d", &Elmt(*M,x,y));
		}
	}
}

void TulisMATRIKS (MATRIKS M){
	int x, y;
	for (x=1; x<=GLI_X(M); x++){
		for (y=1; y<=GLI_Y(M); y++){
			printf("%d ", Elmt(M,x,y));
		}
		printf("\n");
	}
}
