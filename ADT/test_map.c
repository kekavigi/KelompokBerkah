#include "peta.h"
#include "player.h"
#include <string.h>
#include <stdio.h>

PLAYER Human;
PETA Ruang1, Ruang2, Ruang3, Dapur, RuangAktif;

int main(){
	//inisialisasi
	START_PLAYER(&Human);

	MakePETA(&Ruang1, "ruang1.txt", 1, MakePOINT(0,0));
	MakePETA(&Ruang2, "ruang2.txt", 2, MakePOINT(0,0));
	MakePETA(&Ruang3, "ruang3.txt", 3, MakePOINT(0,0));
	MakePETA(&Dapur,  "ruang4.txt", 4, Posisi(Human));
	RuangAktif = Dapur;

	int inp=0;
	while (inp!=-1){
		scanf("%d", &inp);
		}
}
