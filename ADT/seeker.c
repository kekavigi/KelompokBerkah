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
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
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
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
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
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
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
		}else{
			if(*BENDA == 0){
				*BENDA = 0;
			} // gak ketemu apa2
		}
	}
}


void CariMeja(POINT P, int BENDA, int CURRENT_ROOM, POINT *PMEJA, int *NOMOR_MEJA, int *KMEJA){ // HANYA DIPAKAI KETIKA INT BENDA == 1 atau 2
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
		if(CURRENT_ROOM == 2){
			return 1;
		}else if(CURRENT_ROOM == 3){
			return 5;
		}else if(CURRENT_ROOM == 4){
			return 9;
		}
	}else if( (Absis(P) == 7) && (Ordinat(P) == 7) ){
		if(CURRENT_ROOM == 2){
			return 2;
		}else if(CURRENT_ROOM == 3){
			return 6;
		}else if(CURRENT_ROOM == 4){
			return 10;
		}
	}else if( (Absis(P) == 2) && (Ordinat(P) == 2) ){
		if(CURRENT_ROOM == 2){
			return 3;
		}else if(CURRENT_ROOM == 3){
			return 7;
		}else if(CURRENT_ROOM == 4){
			return 11;
		}
	}else if( (Absis(P) == 7) && (Ordinat(P) == 2) ){
		if(CURRENT_ROOM == 2){
			return 4;
		}else if(CURRENT_ROOM == 3){
			return 8;
		}else if(CURRENT_ROOM == 4){
			return 12;
		}
	}else{
		return 0;
	}
}

int HitungKursi(int NOMOR_MEJA){
// Nomor meja menentukan berapa kursi yang tersedia di meja tersebut.

	if(NOMOR_MEJA == 1 || NOMOR_MEJA == 3 || NOMOR_MEJA == 5 || NOMOR_MEJA == 7 || NOMOR_MEJA == 9 || NOMOR_MEJA == 11){
		return 4;
	}else{
		return 2;
	}

}


int CekMejaRacik(POINT P){ // HANYA DIPAKAI KETIKA INT BENDA = 2
// Akan mengirimkan bahan yang tersedia
/*	
	"Piring", //1
    "Sendok", //2
    "Garpu", //3
	"Es Krim", //4
	"Nasi", //5
	"Roti", //6
	"Spaghetti", //7
	"Pisang", //8
	"Stroberi", //9
	"Telur", //10
	"Ayam Goreng", //11
	"Patty", //12
	"Sosis", //13
	"Bolognese", //14
	"Carbonara", //15
	"Keju", //16
	"Banana Split", //17
    "Sundae", //18
    "Nasi Telur Dadar", //19
	"Nasi Ayam Goreng", //20
	"Burger", //21
	"Hot Dog", //22
	"Spaghetti Bolognese", //23
	"Spaghetti Carbonara" //24

*/

}

boolean CekMejaTray(PLAYER P){
// Mengecek apakah ada meja tray di sekitar player

}
/*
int main(){

	PLAYER P1;
	int room;
	int command;
	int benda,NOMOR_MEJA,KMEJA;
	POINT seek,PMEJA;

	START_PLAYER(&P1);
	room = 1;

	printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",room,Absis(Posisi(P1)),Ordinat(Posisi(P1)));

	do{
		scanf("%d",&command);
		system("cls");

		if(command != 5){
			UPDATE_POSISI_PLAYER(&P1,command,&room);
		}else{
			IsKursiMejaAda(P1,room,&benda,&seek);
			if (benda == 1 || benda == 2){
				CariMeja(seek, benda, room, &PMEJA, &NOMOR_MEJA, &KMEJA);
				printf("Di sekitar player ada meja yang bernomor %d, dan kapasitasnya adalah %d.\n",NOMOR_MEJA,KMEJA);
			}else{
				printf("gak ada apa2 disekitar player\n");
			}
		}

		printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",room,Absis(Posisi(P1)),Ordinat(Posisi(P1)));
	}while(command != 6);
*/
	return 0;
}
