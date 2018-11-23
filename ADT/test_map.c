#include "peta.h"
#include "player.h"
#include <string.h>
#include <stdio.h>

PLAYER Human;
PETA Ruang1, Ruang2, Ruang3, Dapur, RuangAktif;

int main(){
	//inisialisasi
	MakePETA(&Ruang1, "ruang1.txt", 1, MakePOINT(5,5));
	MakePETA(&Ruang2, "ruang2.txt", 2, MakePOINT(5,5));
	MakePETA(&Ruang3, "ruang3.txt", 3, MakePOINT(5,5));
	MakePETA(&Dapur, "ruang4.txt", 4, MakePOINT(,0));
	RuangAktif = Dapur;

	START_PLAYER(*Human);

	int inp=0;
	while (inp!=-1){
		scanf("%d", &inp);

		}
	}
