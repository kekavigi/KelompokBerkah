#include <stdlib.h>
#include <stdio.h>
//#include "peta.c"
//#include "bintree.c"
#include "array.c"
//#include "point.h"
//#include "matriks.c"
#include "handnampanresep.c"
/* VARIABEL GAMES    */  // TAMBAHKAN VARIABEL YANG DIBUTUHKAN DI SINI, VARIABEL GLOBAL
	//PLAYER P;
	//JAM GAME_CLOCK;
	//QUEUE
	//MAP MAP1;
	//MAP MAP2;
	//MAP MAP3;
	//MAP MAP4;
Stack Hand;
Stack Nampan;
TabInt Pesanan;
BinTree Resep;
int COMMAND;
int ambil;

//void PRINT_CREDIT();

int main (){
	LoadTree(&Resep);
	
	/* ANTARMUKA GAME    */ // TAMPILAN PERTAMA YANG DITUNJUKKAN SAAT GAME DIMULAI
//	do{
		
		
//	}while (STATE_1 == true && STATE_2 == true); // KELUAR DARI LOOP INI, BISA JADI USER MILIH EXIT (STATE_2 == FALSE) ATAU START GAME DAN UDAH ADA NAMANYA (STATE_1 == FALSE)
	
//	if(STATE_1){ // INI KASUS USER MEMILIH EXIT
//		PRINT_CREDIT(); // INI PROSEDUR UNTUK PRINT CREDIT KITA
//	}else{ // INI KASUS USER BERMAIN GAME!
	
	/* STATE AWAL GAME    */  // SET KEADAAN AWAL GAME DI SINI MISAL JAM DIMULAI DARI 0, NYAWA PLAYER 0, HAND MASIH KOSONG, KEADAAN AWAL SEMUA MAP
//	START_JAM(&GAME_CLOCK);
//	START_PLAYER(&P);
	
	/*  INI GAMEPLAY */
//	do{
//	BACA_COMMAND(&COMMAND); 
	//PROSEDUR UNTUK MEMBACA PERINTAH DARI USER. 
	/*
	1 : GU		5 : ORDER	9  : CT *    	13.EXIT
	2 : GD		6 : PUT	*	10 : PLACE
	3 : GL		7 : TAKE *	11 : GIVE
	4:  GR		8 : CH	*	12 : RECIPE *
 	*/
	do {
		printf("Masukkan Command : ");
		scanf("%d",&COMMAND);
		
		if (COMMAND == 1){
		//	UPDATE_POSISI(PLAYER *P, int 1); // PLAYER GERAK KE ATAS, TAPI KASUS PINDAH MAP BELUM DITANGANI
		//	JADV(&GAME_CLOCK); // JAM BERTAMBAH
			
		} else if (COMMAND == 2){
			//UPDATE_POSISI(PLAYER *P, int 2);
			//JADV(&GAME_CLOCK); // JAM BERTAMBAH
			
		} else if (COMMAND == 3){
			//UPDATE_POSISI(PLAYER *P, int 3);
			//JADV(&GAME_CLOCK); // JAM BERTAMBAH
			
		} else if (COMMAND == 4){
			//UPDATE_POSISI(PLAYER *P, int 4);
			//JADV(&GAME_CLOCK); // JAM BERTAMBAH
			
		} else if (COMMAND == 5){ // ORDER
			//NOMOR_MEJA = CARI_MEJA(Posisi(P)); // NOMOR MEJA ADALAH VARIABEL BER-TIPE INTEGER (INDEKS), JIKA MEJA TIDAK KETEMU MAKA NILAINYA (0.0)
			
			/*
				STATUS MEJA 
				
				1 = MEJA TERISI, BELUM DIAMBIL PESANANNYA
				2 = MEJA TERISI, SUDAH DIAMBIL PESANANNYA
				3 = MEJA KOSONG
			
			*/
			
		//	if(STATUS_MEJA(NOMOR_MEJA) == 1){
			//	AMBIL_PESANAN(N); // MENGAMBIL PESANAN
		//	}
			
		//	JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 6){ //PUT
			if(IsFullStackt(Nampan)){
				printf("Nampan sudah Penuh\n");
			} else{
				PUT(Resep,&Hand,&Nampan);
				if(IsEmptyStackt(Hand)){
					printf("Nampan : \n");
					PrintStackt(Nampan);
				} else {
					printf("Tidak bisa membuat menu makanan dari bahan yang ada\n");
				}
			}
			
	//		if(CEK_MEJA_NAMPAN(Posisi(P))){ // CEK MEJA NAMPAN AKAN MENGHASILKAN TRUE JIKA DI SEKITAR PLAYER ADA MEJA NAMPAN
		//		RACIK_MAKANAN(HAND); // ADA 2 KASUS, KASUS PERTAMA : MAKANAN DIBUAT KARENA SESUAI DENGAN RESEP. KASUS KEDUA : MAKANAN TIDAK DIBUAT, KARENA TIDAK SESUAI RESEP
	//		}else{
	//			printf("PUT hanya bisa dilakukan di meja nampan! \n");
	//		}
			
	//		JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 7) { //TAKE
			if(IsFullStackt(Hand)){
				printf("Tangan Anda Penuh\n");
			} else {
				printf("Masukkan bahan yang akan diambil : ");
				scanf("%d",&ambil);
				TAKE(&Hand,ambil);
				printf("HAND : \n");
				PrintStackt(Hand);					
			}

			
//			if(CEK_MEJA_BAHAN(POSISI(P))){ // CEK MEJA BAHAN AKAN MENGHASILKAN TRUE JIKA DI SEKITAR PLAYER ADA MEJA BAHAN
	//			NOMOR_MEJA_BAHAN = CARI_MEJA(Posisi(P)); // NOMOR MEJA  BAHAN ADALAH VARIABEL BER-TIPE INTEGER (INDEKS), JIKA MEJA TIDAK KETEMU MAKA NILAINYA (0.0)
	//			AMBIL_BAHAN()
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
		//	}
			
	//		JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 8){
			CH(&Hand);
			printf("Hand : \n");
			PrintStackt(Hand);	
		//	JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 9){
			CT(&Nampan);			
			printf("Nampan : \n");
			PrintStackt(Nampan);	
		//	JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 10){
			
		//	JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 11){
			
		//	JADV(&GAME_CLOCK); // JAM BERTAMBAH
		} else if (COMMAND == 12){
		//algoritma
			
			ShowBranch(Resep);
			
		}
		
		
	//	GENERATE_PELANGGAN (GAME_CLOCK); // KALO JAMNYA MERUPAKAN KELIPATAN 15, AKAN MENAMBAH 1 PELANGGAN
	//	UPDATE_KESABARAN_ANTRI(); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN DI ANTRIAN
	//	UPDATE_KESABARAN_DUDUK(); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN YANG SUDAH DUDUK
	//	UPDATE_MAP();
	//	PRINT_TAMPILAN();	
	}while (COMMAND != 13);
	
}		 // MASIH BISA MAIN SELAMA USER TIDAK MEMILIH EXIT & LIFE TIDAK 0
	
	
	
	
	

