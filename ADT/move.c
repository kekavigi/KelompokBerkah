#include <stdlib.h>
#include <stdio.h>
#include "move.h"


// void UPDATE_POSISI_PLAYER(PLAYER *P, int X, int *room);
// boolean IsDinding1 (POINT P);
// boolean IsMejaKursi(POINT P, int room);
// boolean IsPintu(POINT P, int room_sekarang);
// boolean IsMove(POINT P, int room);
// void UP1 (POINT *P, int *room_sekarang);
// void DOWN1 (POINT *P, int *room_sekarang);
// void LEFT1 (POINT *P, int *room_sekarang);
// void RIGHT1 (POINT *P, int *room_sekarang);

/* Ini Driver buat mengetes */
// int main(){
// 	PLAYER P1;
// 	int room;
// 	int command;

// 	START_PLAYER(&P1);
// 	room = 1;

// 	printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",room,Absis(Posisi(P1)),Ordinat(Posisi(P1)));

// 	do{
// 		scanf("%d",&command);

// 		UPDATE_POSISI_PLAYER(&P1,command,&room);

// 		printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",room,Absis(Posisi(P1)),Ordinat(Posisi(P1)));
// 	}while(command != 5);

// 	return 0;
// }

void UPDATE_POSISI_PLAYER(PLAYER *P, int X, int *room){
/* MEMPERBAHARUI POSISI PLAYER DALAM GAME */
	if(X == 1){
		UP1(&Posisi(*P),&(*room));
	}else if (X == 2){
		DOWN1(&Posisi(*P),&(*room));
	}else if (X == 3){
		LEFT1(&Posisi(*P),&(*room));
	}else if (X == 4){
		RIGHT1(&Posisi(*P),&(*room));
	}

}

boolean IsDinding1 (POINT P){
/* Menghasilkan true jika P terletak di luar dinding (yang pasti lebih dari. Boundary X 1-8, Boundary Y 1-8) */

	return(Absis(P)>8 || Ordinat(P)>8 || Absis(P)<1 || Ordinat(P)<1);
}

boolean IsMejaKursi(POINT P, int room){
/* Menghasilkan true jika posisi P adalah Kursi atau meja. Masih perlu kolaborasi sama ADT MATRIKS */

	if(room == 1){ //Kalo player ada di dapur komposisi ruangan agak berbeda
		return ((Absis(P) == 1) || (Absis(P)==4 && Ordinat(P)==1) ||
			    (Absis(P)==5 && Ordinat(P)==1) || (Absis(P)==6 && Ordinat(P)==1) ||
			    (Absis(P)==7 && Ordinat(P)==1) || (Absis(P)==8 && Ordinat(P)==1) ||
			    (Absis(P)==4 && Ordinat(P)==4) || (Absis(P)==5 && Ordinat(P)==4) ||
			    (Absis(P)==6 && Ordinat(P)==4) || (Absis(P)==8 && Ordinat(P)==8));
	}else{ // Selain ruangan 1 (DAPUR), posisi objek sama aja
		return ((Absis(P)==2 && Ordinat(P)==1) || (Absis(P)==3 && Ordinat(P)==2) ||
			    (Absis(P)==2 && Ordinat(P)==3) || (Absis(P)==1 && Ordinat(P)==2) ||
			    (Absis(P)==8 && Ordinat(P)==2) || (Absis(P)==7 && Ordinat(P)==2) ||
			    (Absis(P)==6 && Ordinat(P)==2) || (Absis(P)==8 && Ordinat(P)==7) ||
			    (Absis(P)==7 && Ordinat(P)==7) || (Absis(P)==6 && Ordinat(P)==7) ||
			    (Absis(P)==1 && Ordinat(P)==7) || (Absis(P)==2 && Ordinat(P)==6) ||
			    (Absis(P)==3 && Ordinat(P)==7) || (Absis(P)==2 && Ordinat(P)==8));
	}
}

boolean IsPintu(POINT P, int room_sekarang){
/* Menghasilkan true jika di posisi P adalah Pintu. Masih perlu kolaborasi sama ADT MATRIKS */
	if(room_sekarang == 1){ // Dapur
		return ( (Absis(P)==5 && Ordinat(P)==8) || (Absis(P)==8 && Ordinat(P)==5) ); // Pintu-pintu yang ada di room 1.
	}else if(room_sekarang == 2){
		return ( (Absis(P)==5 && Ordinat(P)==1) || (Absis(P)==8 && Ordinat(P)==5) ); // Pintu-pintu yang ada di room 2.
	}else if(room_sekarang == 3){
		return ( (Absis(P)==1 && Ordinat(P)==5) || (Absis(P)==5 && Ordinat(P)==1) ); // Pintu-pintu yang ada di room 3.
	}else if(room_sekarang == 4){
		return ( (Absis(P)==5 && Ordinat(P)==8) || (Absis(P)==1 && Ordinat(P)==5) ); // Pintu-pintu yang ada di room 4.
	}

}

boolean IsMove(POINT P, int room){
/* Menghasilkan True jika titik berada di map (bukan 0,Y. Bukan di X,0. Bukan di Border Map (dinding)) */

	return (!IsDinding1(P) &&  !IsMejaKursi(P,room));
}

void UP1 (POINT *P, int *room_sekarang){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT P1;

	P1 = MakePOINT(Absis(*P), Ordinat(*P)+1);
	if(IsMove(P1,*room_sekarang)){
		*P = P1;
	}else{
		if(IsDinding1(P1)){ //Jika dinding cek dlu apakah pintu
			if(IsPintu(*P,*room_sekarang)){ // Akan dicek apakah posisi player menghadap pintu, jika bener maka teleport, jika tidak tidak ada perubahan
				// TELEPORT
				Absis(*P) = 5;
				Ordinat(*P) = 1;
				if(*room_sekarang == 1){ // Player ada di room 1
					*room_sekarang = 2; // diteleport ke room 2
				}else{ // Player ada di room 4
					*room_sekarang = 3; // diteleport ke room 3
				}
			}
		}else if(IsMejaKursi(P1,*room_sekarang)){
			printf("\n\nSTATUS : Nabrak Boss\n");
		}
	}
}

void DOWN1 (POINT *P, int *room_sekarang){
/* Mengirim salinan P dengan ordinat dikurang satu */

	POINT P1;

	P1 = MakePOINT(Absis(*P), Ordinat(*P)-1);
	if(IsMove(P1,*room_sekarang)){
		*P = P1;
	}else{
		if(IsDinding1(P1)){ //Jika dinding cek dlu apakah pintu
			if(IsPintu(*P,*room_sekarang)){ // Akan dicek apakah posisi player menghadap pintu, jika bener maka teleport, jika tidak maka tidak ada perubahan
				// TELEPORT
				Absis(*P) = 5;
				Ordinat(*P) = 8;
				if(*room_sekarang == 2){ // Player ada di room 2
					*room_sekarang = 1; // diteleport ke room 1
				}else{ // Player ada di room 3
					*room_sekarang = 4; // diteleport ke room 3
				}
			}
		}else if(IsMejaKursi(P1,*room_sekarang)){
			printf("\n\nSTATUS : Nabrak Boss\n");
		}
	}
}

void LEFT1 (POINT *P, int *room_sekarang){
/* Mengirim salinan P dengan absis dikurang satu  */

	POINT P1;

	P1 = MakePOINT(Absis(*P)-1, Ordinat(*P));
	if(IsMove(P1,*room_sekarang)){
		*P = P1;
	}else{
		if(IsDinding1(P1)){ //Jika dinding cek dlu apakah pintu
			if(IsPintu(*P,*room_sekarang)){ // Akan dicek apakah posisi player menghadap pintu, jika bener maka teleport, jika tidak maka tidak ada perubahan
				// TELEPORT
				Absis(*P) = 8;
				Ordinat(*P) = 5;
				if(*room_sekarang == 4){ // Player ada di room 4
					*room_sekarang = 1; // diteleport ke room 1
				}else{ // Player ada di room 3
					*room_sekarang = 2; // diteleport ke room 2
				}
			}
		}else if(IsMejaKursi(P1,*room_sekarang)){
			printf("\n\nSTATUS : Nabrak Boss\n");
		}

	}
}

void RIGHT1 (POINT *P, int *room_sekarang){
/* Mengirim salinan P dengan absis ditambah satu  */

	POINT P1;

	P1 = MakePOINT(Absis(*P)+1, Ordinat(*P));

	if(IsMove(P1,*room_sekarang)){
		*P = P1;
	}else{
		if(IsDinding1(P1)){ //Jika dinding cek dlu apakah pintu
			if(IsPintu(*P,*room_sekarang)){ // Akan dicek apakah posisi player menghadap pintu, jika bener maka teleport, jika tidak maka tidak ada perubahan
				// TELEPORT
				Absis(*P) = 1;
				Ordinat(*P) = 5;
				if(*room_sekarang == 1){ // Player ada di room 1
					*room_sekarang = 4; // diteleport ke room 4
				}else{ // Player ada di room 2
					*room_sekarang = 3; // diteleport ke room 3
				}
			}
		}else if(IsMejaKursi(P1,*room_sekarang)){
			printf("\n\nSTATUS : Nabrak Boss\n");
		}

	}
}
