#include "peta.h"
#include "player.h"
#include <string.h>
#include <stdio.h>

int main(){
	//inisialisasi
	PLAYER Human;
	START_PLAYER(&Human);
	MakePETA(&Ruang1, "ruang1.txt", 2, MakePOINT(0,0));
	MakePETA(&Ruang2, "ruang2.txt", 3, MakePOINT(0,0));
	MakePETA(&Ruang3, "ruang3.txt", 4, MakePOINT(0,0));
	MakePETA(&Dapur,  "ruang4.txt", 1, Posisi(Human));
	RuangAktif = Dapur;

	int inp;

	do {
		TulisPETA(RuangAktif);
		scanf("%d", &inp);
		UpdatePETA(&RuangAktif, inp);
	} while (inp!=-1);

	return 0;
}
