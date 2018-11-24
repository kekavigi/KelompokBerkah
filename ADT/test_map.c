#include "peta.h"
#include "player.h"
#include "seeker.h"
#include <string.h>
#include <stdio.h>

int main(){
	//inisialisasi
	PLAYER Human;
	START_PLAYER(&Human);
	MakePETA(&Dapur,  "ruang4.txt", 1, Posisi(Human));
	MakePETA(&Ruang1, "ruang1.txt", 2, MakePOINT(0,0));
	MakePETA(&Ruang2, "ruang2.txt", 3, MakePOINT(0,0));
	MakePETA(&Ruang3, "ruang3.txt", 4, MakePOINT(0,0));
	RuangAktif = Dapur;

	//prog utama
	int XX=0;
	boolean running = true;
	//more inisialisasi
	int room = Rum(RuangAktif), benda, nomor_meja, kmeja;
	POINT pbenda, pmeja;

	while (running){
			printf(">> ");
			scanf("%d", &XX);
			if 				(XX<1)  running = false;
			else if 	(XX<5) {UpdatePETA(&RuangAktif, XX);
												TulisPETA(RuangAktif);
												UPDATE_POSISI_PLAYER(&Human, XX, &room);}
			else if 	(XX<10) printf("not mai task\n");
			else if 	(XX==10){printf("iyess\n");
												IsKursiMejaAda(Human, Rum(RuangAktif), &benda, &pbenda);
												printf("%d\n", benda);
												if (benda==2){
													printf("ikehh!!\n");
													CariMeja(Posisi(Human), 2, Rum(RuangAktif), &pmeja, &nomor_meja, &kmeja);
													IsiKursiKosong(&Mat(RuangAktif), pmeja, 2);};
												UpdatePETA(&RuangAktif, XX);
												TulisPETA(RuangAktif);}
		  else printf("cot");
			printf("\n");
	};

	return 0;
}
