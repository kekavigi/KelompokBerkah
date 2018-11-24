#include <stdio.h>
#include <stdlib.h>
#include "seeker.h"


void IsKursiMejaAda(PLAYER P, int CURRENT_ROOM, int *BENDA, POINT *PBENDA){
// Prosedur untuk memeriksa apakah di sekitar player ada meja, meja racik, kursi, meja tray.
/*
0 = TIDAK ADA APA
1 = ADA KURSI
2 = ADA MEJA
3 = ADA MEJA TRAY
*/
	POINT seek;
	*BENDA = 0;

	if(CURRENT_ROOM != 1){
		seek = Posisi(P);
		Absis(seek) = Absis(seek)+1; // Pencarian ke Kanan
		if (IsMejaKursi(seek, CURRENT_ROOM)){
			if((Absis(seek) == 7 && Ordinat(seek)==7) || (Absis(seek) == 7 && Ordinat(seek)==2)){ // MEJA
				*BENDA = 2;
			}else{
				*BENDA = 1;
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			}
		}

		seek = Posisi(P);
		Absis(seek) = Absis(seek)-1; // Pencarian ke Kiri
		if (IsMejaKursi(seek, CURRENT_ROOM)){
			if((Absis(seek) == 7 && Ordinat(seek)==7) || (Absis(seek) == 7 && Ordinat(seek)==2)){
				*BENDA = 2;
			}else{
				*BENDA = 1;
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			}
		}

		seek = Posisi(P);
		Ordinat(seek) = Ordinat(seek)+1; // Pencarian ke atas
		if (IsMejaKursi(seek, CURRENT_ROOM)){
			if((Absis(seek) == 7 && Ordinat(seek)==7) || (Absis(seek) == 7 && Ordinat(seek)==2)){
				*BENDA = 2;
			}else{
				*BENDA = 1;
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			}
		}

		seek = Posisi(P);
		Ordinat(seek) = Ordinat(seek)-1; // Pencarian ke Bawah
		if (IsMejaKursi(seek,CURRENT_ROOM)){
			if((Absis(seek) == 7 && Ordinat(seek)==7) || (Absis(seek) == 7 && Ordinat(seek)==2)){
				*BENDA = 2; // Ketemu meja
			}else{
				*BENDA = 1; // ketemu kursi
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			}
		}

	}else{ // ada di room 1
		seek = Posisi(P);
		Ordinat(seek) = Ordinat(seek)-1; // Pencarian ke bawah
		if (IsMejaKursi(seek,CURRENT_ROOM)){
			if((Absis(seek) == 8 && Ordinat(seek)==8)){
				*BENDA = 3; // Ketemu tray
			}else{
				*BENDA = 2; // ketemu meja racik
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			} // gak ketemu apa2
		}

		seek = Posisi(P);
		Ordinat(seek) = Ordinat(seek)+1; // Pencarian ke atas
		if (IsMejaKursi(seek,CURRENT_ROOM)){
			if((Absis(seek) == 8 && Ordinat(seek)==8)){
				*BENDA = 3; // Ketemu tray
			}else{
				*BENDA = 2; // ketemu meja racik
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			} // gak ketemu apa2
		}

		seek = Posisi(P);
		Absis(seek) = Absis(seek)-1; // Pencarian ke Kiri
		if (IsMejaKursi(seek,CURRENT_ROOM)){
			if((Absis(seek) == 8 && Ordinat(seek)==8)){
				*BENDA = 3; // Ketemu tray
			}else{
				*BENDA = 2; // ketemu meja racik
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			}// gak ketemu apa2
		}

		seek = Posisi(P);
		Absis(seek) = Absis(seek)+1; // Pencarian ke Kanan
		if (IsMejaKursi(seek,CURRENT_ROOM)){
			if((Absis(seek) == 8 && Ordinat(seek)==8)){
				*BENDA = 3; // Ketemu tray
			}else{
				*BENDA = 2; // ketemu meja racik
			}
			*PBENDA = seek;
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
				*PBENDA = Posisi(P);
			} // gak ketemu apa2
		}
	}
}


void CariMeja(POINT P, int BENDA, int CURRENT_ROOM, POINT *PMEJA, int *NOMOR_MEJA, int *KMEJA){
// HANYA DIPAKAI KETIKA INT BENDA == 1 atau 2
// PROSEDUR UNTUK MENCARI POSISI MEJA, P adalah posisi kursi atau meja

	POINT seek;

	seek = P;

	if(CekNomorMeja(seek, CURRENT_ROOM) != 0){ // Kasus langsung meja
		*PMEJA = seek;
		*NOMOR_MEJA = CekNomorMeja(*PMEJA, CURRENT_ROOM);
		*KMEJA = HitungKursi(*NOMOR_MEJA);
	}else{ // P bukan posisi meja

		seek = P;
		Absis(seek) = Absis(seek) + 1; // pencarian ke kanan
		if(CekNomorMeja(seek, CURRENT_ROOM) != 0){
			*PMEJA = seek;
			*NOMOR_MEJA = CekNomorMeja(*PMEJA, CURRENT_ROOM);
			*KMEJA = HitungKursi(*NOMOR_MEJA);
		}

		seek = P;
		Absis(seek) = Absis(seek) - 1; // pencarian ke kiri
		if(CekNomorMeja(seek, CURRENT_ROOM) != 0){
			*PMEJA = seek;
			*NOMOR_MEJA = CekNomorMeja(*PMEJA, CURRENT_ROOM);
			*KMEJA = HitungKursi(*NOMOR_MEJA);
		}

		seek = P;
		Ordinat(seek) = Ordinat(seek) + 1; // pencarian ke atas
		if(CekNomorMeja(seek, CURRENT_ROOM) != 0){
			*PMEJA = seek;
			*NOMOR_MEJA = CekNomorMeja(*PMEJA, CURRENT_ROOM);
			*KMEJA = HitungKursi(*NOMOR_MEJA);
		}

		seek = P;
		Ordinat(seek) = Ordinat(seek) - 1; // pencarian ke bawah
		if(CekNomorMeja(seek, CURRENT_ROOM) != 0){
			*PMEJA = seek;
			*NOMOR_MEJA = CekNomorMeja(*PMEJA, CURRENT_ROOM);
			*KMEJA = HitungKursi(*NOMOR_MEJA);
		}
 	}
}

int CekNomorMeja(POINT P, int CURRENT_ROOM){
	if( (Absis(P) == 2) && (Ordinat(P) == 7) ){
		if(CURRENT_ROOM == 2)				return 1;
		else if(CURRENT_ROOM == 3)	return 5;
		else if(CURRENT_ROOM == 4)	return 9;
		}
	else if( (Absis(P) == 7) && (Ordinat(P) == 7) ){
		if(CURRENT_ROOM == 2)				return 2;
		else if(CURRENT_ROOM == 3)	return 6;
		else if(CURRENT_ROOM == 4)	return 10;
		}
	else if( (Absis(P) == 2) && (Ordinat(P) == 2) ){
		if(CURRENT_ROOM == 2)				return 3;
		else if(CURRENT_ROOM == 3)	return 7;
		else if(CURRENT_ROOM == 4)	return 11;
		}
	else if( (Absis(P) == 7) && (Ordinat(P) == 2) ){
		if(CURRENT_ROOM == 2)				return 4;
		else if(CURRENT_ROOM == 3)	return 8;
		else if(CURRENT_ROOM == 4)	return 12;
	}
	else													return 0;
}

int HitungKursi(int NOMOR_MEJA){
// Nomor meja menentukan berapa kursi yang tersedia di meja tersebut.

	if(NOMOR_MEJA == 1 || NOMOR_MEJA == 3 || NOMOR_MEJA == 5 || NOMOR_MEJA == 7 || NOMOR_MEJA == 9 || NOMOR_MEJA == 11){
		return 4;
	}else	return 2;
}


int CekMejaRacik(POINT P){
// HANYA DIPAKAI KETIKA INT BENDA = 2
// Akan mengirimkan bahan yang tersedia
	if((Absis(P) == 1 && Ordinat(P) == 1)){
		return 1; // piring
	}else if((Absis(P) == 1) && (Ordinat(P) == 2)){
		return 2; //sendok
	}else if((Absis(P) == 1) && (Ordinat(P) == 3)){
		return 3; //garpu
	}else if((Absis(P) == 1) && (Ordinat(P) == 4)){
		return 4; // Es krim
	}else if((Absis(P) == 1) && (Ordinat(P) == 5)){
		return 5; //Nasi
	}else if((Absis(P) == 1) && (Ordinat(P) == 6)){
		return 6; //Roti
	}else if((Absis(P) == 1) && (Ordinat(P) == 7)){
		return 7; //Spagheti
	}else if((Absis(P) == 1) && (Ordinat(P) == 8)){
		return 8; //Pisang
	}else if((Absis(P) == 4) && (Ordinat(P) == 1)){
		return 9; // Stroberi
	}else if((Absis(P) == 5) && (Ordinat(P) == 1)){
		return 10; // Telur
	}else if((Absis(P) == 6) && (Ordinat(P) == 1)){
		return 11; // Ayam Goreng
	}else if((Absis(P) == 7) && (Ordinat(P) == 1)){
		return 12; // Patty
	}else if((Absis(P) == 8) && (Ordinat(P) == 1)){
		return 13; // Sosis
	}else if((Absis(P) == 4) && (Ordinat(P) == 4)){
		return 14; // Bolognese
	}else if((Absis(P) == 5) && (Ordinat(P) == 4)){
		return 15; // Carbonara
	}else if((Absis(P) == 6) && (Ordinat(P) == 4)){
		return 16; // Keju
	}else{
		return 0; //Kosong
	}
}

boolean CekMejaTray(POINT P){
// Mengecek apakah ada meja tray di sekitar player
	return ((Absis(P) == 8) && (Ordinat(P) == 8));
}


//int main(){
//	PLAYER P1;
//	int room;
//	int command;
//	int benda,NOMOR_MEJA,KMEJA;
//	POINT seek,PMEJA;
//	START_PLAYER(&P1);
//	room = 1;
//	printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",room,Absis(Posisi(P1)),Ordinat(Posisi(P1)));
//	do{
//		scanf("%d",&command);
//		system("cls");
//		if(command != 5){
//			UPDATE_POSISI_PLAYER(&P1,command,&room);
//		}else{
//			IsKursiMejaAda(P1,room,&benda,&seek);
//			printf("[%d,%d]",Absis(seek), Ordinat(seek));
//			if (benda == 2 || benda == 1){
//				NOMOR_MEJA = CekMejaRacik(seek);
//				printf("Di sekitar player ada meja RACIK yang bernomor %d.\n",NOMOR_MEJA);
//			}else{
//				printf("gak ada apa2 disekitar player\n");
//			}
//			
//			if(CekMejaTray(seek)){
//				printf("Disini bisa masak makanan\n");
//			}
//		}
//		printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",room,Absis(Posisi(P1)),Ordinat(Posisi(P1)));
//	}while(command != 6);
//	return 0;
//}