#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "move.h"
#include "jam.h"
#include "point.h"
#include "player.h"


/* VARIABEL GAMES    */  // TAMBAHKAN VARIABEL YANG DIBUTUHKAN DI SINI, VARIABEL GLOBAL
	PLAYER P;
	JAM GAME_CLOCK;
	char NAMA_PEMAIN[20] = ""; // Ini buat nama pemain
	char NAMA_KOSONG[20] = ""; // CUMA BUAT MENGECEK.
	boolean STATE_1,STATE_2,STATE_3 = false;
	int COMMAND; //PERINTAH DARI USER
	int CURRENT_ROOM; //ROOM SEKARANG PLAYER DI MANA

int main (){
	
/* ANTARMUKA GAME    */ // TAMPILAN PERTAMA YANG DITUNJUKKAN SAAT GAME DIMULA
	do{
		printf("\n\n\n-- ENGI'S KITCHEN EXPANSION GAME (18++) --\n\n\n");
		printf("NEW GAME\nSTART GAME\nEXIT\n\n");
		printf("Pilih Menu [1 = NEW GAME, 2 = START GAME, 3 = EXIT] :");

		scanf("%d", &COMMAND);

		if(COMMAND == 1){
			system("cls");
			printf("Nama Kamu : ");
			scanf("%s",NAMA_PEMAIN);

		}else if (COMMAND == 2){
			if (strcmp(NAMA_PEMAIN,NAMA_KOSONG) == 0){
				printf("Masukin Nama dulu Bos!\n");
				printf("Nama Kamu : ");
				scanf("%s",NAMA_PEMAIN);
				STATE_1 = true;
			}else{
				STATE_1 = true;
			}
		}else if (COMMAND == 3){
			STATE_2 = true;
		}

		system("cls");
		
	}while (!STATE_1 && !STATE_2); // KELUAR DARI LOOP INI, BISA JADI USER MILIH EXIT (STATE_2 == true) ATAU START GAME DAN UDAH ADA NAMANYA (STATE_1 == true)
	

	if(STATE_2){ // DISINI MAIN GAME!!!
		printf("THIS GAME IS CREATED BY DANDI, FIO, KEKA, WANUL.\n");

	}else if(STATE_1){
		printf("Halo %s, Selamat Bermain Engi's Kitchen Expansions (18++ Version). \n\n",NAMA_PEMAIN);

		/* STATE AWAL GAME    */  // SET KEADAAN AWAL GAME DI SINI MISAL JAM DIMULAI DARI 0, NYAWA PLAYER 0, HAND MASIH KOSONG, KEADAAN AWAL SEMUA MAP
		START_JAM(&GAME_CLOCK);
		START_PLAYER(&P);
		CURRENT_ROOM = 1;

		printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",CURRENT_ROOM,Absis(Posisi(P)),Ordinat(Posisi(P)));
		printf("Nyawa Tersisa : %d\n", Health(P));
		printf("Uang : %d\n", Money(P));
		
		/*  INI GAMEPLAY */
		do{

			// BACA_COMMAND(&COMMAND); //PROSEDUR UNTUK MEMBACA PERINTAH DARI USER, MASUKAN DARI USER BERUPA KATA, BUKAN ANGKA.
			scanf("%d",&COMMAND); 
			system("cls");

			/*
			1 : GU		5 : ORDER	9  : CT			13.EXIT
			2 : GD		6 : PUT		10 : PLACE
			3 : GL		7 : TAKE 	11 : GIVE
			4:  GR		8 : CH		12 : RECIPE
			*/
			
			if (COMMAND == 1){
				UPDATE_POSISI_PLAYER(&P, 1, &CURRENT_ROOM); // PLAYER GERAK KE ATAS
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				
			} else if (COMMAND == 2){
				UPDATE_POSISI_PLAYER(&P, 2, &CURRENT_ROOM);
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				
			} else if (COMMAND == 3){
				UPDATE_POSISI_PLAYER(&P, 3, &CURRENT_ROOM);
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				
			} else if (COMMAND == 4){
				UPDATE_POSISI_PLAYER(&P, 4, &CURRENT_ROOM);
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				
			} else if (COMMAND == 5){ // ORDER
				// NOMOR_MEJA = CARI_MEJA(Posisi(P)); // NOMOR MEJA ADALAH VARIABEL BER-TIPE INTEGER (INDEKS), JIKA MEJA TIDAK KETEMU MAKA NILAINYA (0.0)
				
				/*
					STATUS MEJA 
					
					1 = MEJA TERISI, BELUM DIAMBIL PESANANNYA
					2 = MEJA TERISI, SUDAH DIAMBIL PESANANNYA
					3 = MEJA KOSONG
				
				*/
				
				// if(STATUS_MEJA(NOMOR_MEJA) == 1){
				// 	// AMBIL_PESANAN(N); // MENGAMBIL PESANAN
				// }
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 6){ //PUT
				
				// if(CEK_MEJA_NAMPAN(Posisi(P))){ // CEK MEJA NAMPAN AKAN MENGHASILKAN TRUE JIKA DI SEKITAR PLAYER ADA MEJA NAMPAN
				// 	RACIK_MAKANAN(HAND); // ADA 2 KASUS, KASUS PERTAMA : MAKANAN DIBUAT KARENA SESUAI DENGAN RESEP. KASUS KEDUA : MAKANAN TIDAK DIBUAT, KARENA TIDAK SESUAI RESEP
				// }else{
				// 	printf("PUT hanya bisa dilakukan di meja nampan! \n");
				// }
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 7) { //TAKE
				
				// if(CEK_MEJA_BAHAN(POSISI(P))){ // CEK MEJA BAHAN AKAN MENGHASILKAN TRUE JIKA DI SEKITAR PLAYER ADA MEJA BAHAN
				// 	NOMOR_MEJA_BAHAN = CARI_MEJA(Posisi(P)); // NOMOR MEJA  BAHAN ADALAH VARIABEL BER-TIPE INTEGER (INDEKS), JIKA MEJA TIDAK KETEMU MAKA NILAINYA (0.0)
				// 	AMBIL_BAHAN()
							/*
					KETERANGAN NOMOR MEJA 
					
					1 = PIRING
					2 = SENDOK
					3 = GARPU
					4 = ES KRIM
					5 = NASI
					6 = ROTI
					7 = SPAGETHI
					8 = PISANG
					9 = STROBERI
					10 = TELUR
					11 = AYAM GORENG
					12 = PATTY 
					13 = SOSIS
					14 = BOLOGNESE
					15 = CARBONARA
					16 = KEJU
				
				*/
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 8){ //CH
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 9){ //CT
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 10){ //PLACE
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 11){ //GIVE
				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 12){ //RECIPE
				
			}

			/*  LAKUKAN UPDATE STATUS DI SINI */
			printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",CURRENT_ROOM,Absis(Posisi(P)),Ordinat(Posisi(P)));
			printf("Nyawa Tersisa : %d\n", Health(P));
			printf("Uang : %d\n", Money(P));
			printf("TICK = %d\n",GAME_CLOCK);

		}while(COMMAND != 13 && HEALTH_CUKUP(P));


	}

	return 0;
}