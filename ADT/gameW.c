#include <stdlib.h>
#include <stdio.h>
#include "jam.h"
#include "queue.h"
#include "mesinkata.h"
#include "antri.h"
#include "duduk.h"

/* VARIABEL GAMES    */  // TAMBAHKAN VARIABEL YANG DIBUTUHKAN DI SINI, VARIABEL GLOBAL
	PLAYER P;
	JAM GAME_CLOCK;
	MAP MAP1;
	MAP MAP2;
	MAP MAP3;
	MAP MAP4;
	Stack HAND;
	int COMMAND, nm /*no meja*/;
	Kata GU, GD, GL, GR, OR, PT, TK, CH, CT, PL, GV, RC, EX;
	NoMeja N;
	Queue Q;
	
/* Variabel untuk Queue (Antrian) */
int J, K;
addressQ P1;
#define MaxAntri 50

void SiapkanKata();
// Siapkan semua kata
boolean CekCommandValid (Kata K);
// Menghasilkan true kalo commandnya benar
void BACA_COMMAND (int *COMMAND);
// Prosedur ini buat translate masukan dari pengguna, dari string ke integer
void GENERATE_PELANGGAN (GAME_CLOCK G, Queue *Q);
// Prosedur ini buat generate pelanggan setiap G kelipatan 15
void PRINT_CREDIT();

int main (){
	/* ANTARMUKA GAME    */ // TAMPILAN PERTAMA YANG DITUNJUKKAN SAAT GAME DIMULAI
	do{
		
		
	}while (STATE_1 == true && STATE_2 == true); // KELUAR DARI LOOP INI, BISA JADI USER MILIH EXIT (STATE_2 == FALSE) ATAU START GAME DAN UDAH ADA NAMANYA (STATE_1 == FALSE)
	
	if(STATE_1){ // INI KASUS USER MEMILIH EXIT
		PRINT_CREDIT(); // INI PROSEDUR UNTUK PRINT CREDIT KITA
	}else{ // INI KASUS USER BERMAIN GAME!
	
	/* STATE AWAL GAME    */  // SET KEADAAN AWAL GAME DI SINI MISAL JAM DIMULAI DARI 0, NYAWA PLAYER 0, HAND MASIH KOSONG, KEADAAN AWAL SEMUA MAP
	START_JAM(&GAME_CLOCK);
	START_PLAYER(&P);
	SiapkanKata ();
	SetEmptyDuduk (&N);
	SetEmptyAntri (&Q, MaxAntri);
	
	/*  INI GAMEPLAY */
	do{
	BACA_COMMAND(&COMMAND); 
	//PROSEDUR UNTUK MEMBACA PERINTAH DARI USER. 
	/*
	1 : GU		5 : ORDER	9  : CT			13.EXIT
	2 : GD		6 : PUT		10 : PLACE
	3 : GL		7 : TAKE 	11 : GIVE
	4:  GR		8 : CH		12 : RECIPE
	*/
	
	if (COMMAND == 1){
		UPDATE_POSISI(PLAYER *P, int 1); // PLAYER GERAK KE ATAS, TAPI KASUS PINDAH MAP BELUM DITANGANI
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
		
	} else if (COMMAND == 2){
		UPDATE_POSISI(PLAYER *P, int 2);
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
		
	} else if (COMMAND == 3){
		UPDATE_POSISI(PLAYER *P, int 3);
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
		
	} else if (COMMAND == 4){
		UPDATE_POSISI(PLAYER *P, int 4);
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
		
	} else if (COMMAND == 5){ // ORDER
/*		NOMOR_MEJA = CARI_MEJA(Posisi(P)); // NOMOR MEJA ADALAH VARIABEL BER-TIPE INTEGER (INDEKS), JIKA MEJA TIDAK KETEMU MAKA NILAINYA (0.0)
		/*
			STATUS MEJA 
			
			1 = MEJA TERISI, BELUM DIAMBIL PESANANNYA
			2 = MEJA TERISI, SUDAH DIAMBIL PESANANNYA
			3 = MEJA KOSONG
		
		
		if(STATUS_MEJA(NOMOR_MEJA) == 1){
			AMBIL_PESANAN(N); // MENGAMBIL PESANAN
		}
*/		
		/*Di sini fungsi buat ngecek di sekitar ada meja, keluarannya nomor meja (nm)*/
		Pesan (N,nm);
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 6){ //PUT
		
		if(CEK_MEJA_NAMPAN(Posisi(P))){ // CEK MEJA NAMPAN AKAN MENGHASILKAN TRUE JIKA DI SEKITAR PLAYER ADA MEJA NAMPAN
			RACIK_MAKANAN(HAND); // ADA 2 KASUS, KASUS PERTAMA : MAKANAN DIBUAT KARENA SESUAI DENGAN RESEP. KASUS KEDUA : MAKANAN TIDAK DIBUAT, KARENA TIDAK SESUAI RESEP
		}else{
			printf("PUT hanya bisa dilakukan di meja nampan! \n");
		}
		
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 7) { //TAKE
		
		if(CEK_MEJA_BAHAN(POSISI(P))){ // CEK MEJA BAHAN AKAN MENGHASILKAN TRUE JIKA DI SEKITAR PLAYER ADA MEJA BAHAN
			NOMOR_MEJA_BAHAN = CARI_MEJA(Posisi(P)); // NOMOR MEJA  BAHAN ADALAH VARIABEL BER-TIPE INTEGER (INDEKS), JIKA MEJA TIDAK KETEMU MAKA NILAINYA (0.0)
			AMBIL_BAHAN()
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
		}
		
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 8){
		
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 9){
		
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 10){ //PLACE
		/*Di sini fungsi buat ngecek di sekitar ada meja, keluarannya nomor meja (nm)*/
		if (IsEmptyQueue(Q))
		{
			printf ("Antrian kosong.\n");
		}
		else
		{
			if (jumlahHead(Q) <= Cap(N,nm))
			{
				PlaceCustAntri (&N, nm, &Q, &P1, &J, &K);
			}
			else
			{
				printf ("Kursi tidak cukup.\n");
			}
		}
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 11){ //GIVE
		/*Asumsi nama fungsi buat ngecek A, nilainya true kalo pesanannya sama kayak Pesan(N,nm)*/
		/*Di sini fungsi buat ngecek di sekitar ada meja, keluarannya nomor meja (nm)*/
		if (/*A*/)
		{
			DelDuduk (&N,nm);
		}
		else
		{
			printf ("Pesanan tidak sesuai dengan pesanan pada meja.\n");
		}
		JADV(&GAME_CLOCK); // JAM BERTAMBAH
	} else if (COMMAND == 12){
		
	}
	
	
	GENERATE_PELANGGAN (GAME_CLOCK); // KALO JAMNYA MERUPAKAN KELIPATAN 15, AKAN MENAMBAH 1 PELANGGAN
	UpdateSabarAntri (&Q); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN DI ANTRIAN
	UpdateKesabaranDuduk (&N); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN YANG SUDAH DUDUK
	UPDATE_MAP();
	PRINT_TAMPILAN();
	}while (COMMAND != 13 && HEALTH_CUKUP(P)); // MASIH BISA MAIN SELAMA USER TIDAK MEMILIH EXIT & LIFE TIDAK 0
	
	
	
	
	
	
	}
	
	
	
	
	return 0;
}

void SiapkanKata()
{
    CreateKata("GU",&GU);
    CreateKata("GD",&GD);
    CreateKata("GL",&GL);
    CreateKata("GR",&GR);
    CreateKata("ORDER",&OR);
    CreateKata("PUT",&PT);
    CreateKata("TAKE",&TK);
    CreateKata("CH",&CH);
    CreateKata("CT",&CT);
    CreateKata("PLACE",&PL);
	CreateKata("GIVE",&GV);
	CreateKata("RECIPE",&RC);
	CreateKata("EXIT",&EX);
}

boolean CekCommandValid (Kata K)
{
	return ((IsKataSama(K,GU))||(IsKataSama(K,GD))||(IsKataSama(K,GL))||(IsKataSama(K,GR))||(IsKataSama(K,OR))||(IsKataSama(K,PT))||(IsKataSama(K,TK))||(IsKataSama(K,CH))||(IsKataSama(K,CT))||(IsKataSama(K,PL))||(IsKataSama(K,GV))||(IsKataSama(K,RC))||(IsKataSama(K,EX)));
}

void BACA_COMMAND (int *COMMAND)
{
	Kata K;
	do
	{
		InputUser (&K);
		if (!CekCommandValid(K))
		{
			printf ("Command tidak tersedia, silahkan masukkan lagi.\n");
		}
		while (!CekCommandValid(K));
	}
	if (IsKataSama(K,GU)
	{
		*COMMAND = 1;
	}
	else if (IsKataSama(K,GD)
	{
		*COMMAND = 2;
	}
	else if (IsKataSama(K,GL)
	{
		*COMMAND = 3;
	}
	else if (IsKataSama(K,GR)
	{
		*COMMAND = 4;
	}
	else if (IsKataSama(K,OR)
	{
		*COMMAND = 5;
	}
	else if (IsKataSama(K,PT)
	{
		*COMMAND = 6;
	}
	else if (IsKataSama(K,TK)
	{
		*COMMAND = 7;
	}
	else if (IsKataSama(K,CH)
	{
		*COMMAND = 8;
	}
	else if (IsKataSama(K,CT)
	{
		*COMMAND = 9;
	}
	else if (IsKataSama(K,PL)
	{
		*COMMAND = 10;
	}
	else if (IsKataSama(K,GV)
	{
		*COMMAND = 11;
	}
	else if (IsKataSama(K,RC)
	{
		*COMMAND = 12;
	}
	else if (IsKataSama(K,EX)
	{
		*COMMAND = 13;
	}
}

void GENERATE_PELANGGAN (GAME_CLOCK G, Queue *Q)
{
	if (G%15 == 0)
	{
		GeneratePelanggan (Q);
	}
}
