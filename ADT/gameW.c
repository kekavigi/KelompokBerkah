#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "move.h"
#include "jam.h"
#include "point.h"
#include "player.h"
#include "dataresep.h"
#include "bintree.h"
#include "stackt.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "komplitstack.h"
#include "array.h"
#include "queue.h"
#include "antri.h"
#include "duduk.h"
#include "seeker.h"
#include "pesanan.h"


/* VARIABEL GAMES    */  // TAMBAHKAN VARIABEL YANG DIBUTUHKAN DI SINI, VARIABEL GLOBAL
	PLAYER P;
	JAM GAME_CLOCK;
	char NAMA_PEMAIN[20] = ""; // Ini buat nama pemain
	char NAMA_KOSONG[20] = ""; // CUMA BUAT MENGECEK.
	boolean STATE_1,STATE_2,STATE_3 = false;
	int COMMAND; //PERINTAH DARI USER
	int CURRENT_ROOM; //ROOM SEKARANG PLAYER DI MANA
	BinTree Resep; // Digunakan Untuk menyimpan resep
	Stack Hand;	// Digunakan sebagai STACK tangan
	Stack Nampan; //Digunakan Sebagai STACK Nampan
	TabInt Pesanan; // Digunakan Sebagai Daftar Pesanan
	int ambil; // Digunakan untuk mengambil bahan secara manual
	int nm; //Digunakan sebagai nomor meja
	Kata GU, GD, GL, GR, OR, PT, TK, CH, CT, PL, GV, RC, EX; //Digunakan sebagai penyimpan command
	POINT Pnm; //Point buat fungsi cek nomor meja
	NoMeja N; //Tipe bentukan buat orang duduk
	Queue Q; //Tipe bentukan buat orang antri
		/*Variabel buat antri*/
		int J, K;
		addressQ P1;
		#define MaxAntri 50
	Pesanan DaftarPesanan; //Buat ngurus daftar pesanan
		
/*Fungsi Yang Akan Digunakan*/
	void SiapkanKata();
	// Siapkan semua kata
	boolean CekCommandValid (Kata K);
	// Menghasilkan true kalo commandnya benar
	void BACA_COMMAND (int *COMMAND);
	// Prosedur ini buat translate masukan dari pengguna, dari string ke integer
	void GENERATE_PELANGGAN (JAM J, Queue *Q);
	// Prosedur ini buat generate pelanggan setiap J kelipatan 15

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
		SiapkanKata ();
		SetEmptyDuduk (&N);
		SetEmptyAntri (&Q, MaxAntri);
		CURRENT_ROOM = 1;
		LoadTree(&Resep); // Mengisi Resep

		printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",CURRENT_ROOM,Absis(Posisi(P)),Ordinat(Posisi(P)));
		printf("Nyawa Tersisa : %d\n", Health(P));
		printf("Uang : %d\n", Money(P));
		
		/*  INI GAMEPLAY */
		do{

			BACA_COMMAND(&COMMAND); //PROSEDUR UNTUK MEMBACA PERINTAH DARI USER, MASUKAN DARI USER BERUPA KATA, BUKAN ANGKA.
			// scanf("%d",&COMMAND); 
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
				nm = CekNomorMeja (Pnm, CURRENT_ROOM); //ngambil nomor meja
				if (!Avail(N,nm))
				{
					addPesanan (Pesan(N,nm), nm, &DaftarPesanan);
				}
				else
				{
					printf ("Tidak dapat mengambil pesanan.\n");
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
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
				
				if(IsFullStackt(Hand)){
					printf("Tangan Anda Penuh\n");
				} else {
					printf("Masukkan bahan yang akan diambil : ");
					scanf("%d",&ambil);
					TAKE(&Hand,ambil);
					printf("HAND : \n");
					PrintStackt(Hand);					
				}

				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 8){ //CH

				CH(&Hand);
				printf("Hand : \n");
				PrintStackt(Hand);
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 9){ //CT
				
				CT(&Nampan);			
				printf("Nampan : \n");
				PrintStackt(Nampan);
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 10){ //PLACE
				nm = CekNomorMeja (Pnm, CURRENT_ROOM); //ngambil nomor meja
				if (IsEmptyQueue(Q))
				{
					printf ("Antrian kosong.\n");
				}
				else
				{
					if ((jumlahHead(Q) <= Cap(N,nm)) && (Avail(N,nm)));
					{
						PlaceCustAntri (&N, nm, &Q, &P1, &J, &K);
					}
					else
					{
						printf ("Kursi tidak bisa ditempati.\n");
					}
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 11){ //GIVE
				nm = CekNomorMeja (Pnm, CURRENT_ROOM); //ngambil nomor meja
				if (Top(Nampan) == Pesan(N,nm))
				{
					DelDuduk (&N,nm);
					if (Pesan(N,nm) == 17) //Nambahin duit dikali jumlah pelanggan
					{
						Money(P) = Money(P) + 40*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 18)
					{
						Money(P) = Money(P) + 20*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 19)
					{
						Money(P) = Money(P) + 30*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 20)
					{
						Money(P) = Money(P) + 60*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 21)
					{
						Money(P) = Money(P) + 70*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 22)
					{
						Money(P) = Money(P) + 70*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 23)
					{
						Money(P) = Money(P) + 100*Isi(N,nm);
					}
					else if (Pesan(N,nm) == 24)
					{
						Money(P) = Money(P) + 90*Isi(N,nm);
					}
				}
				else
				{
					printf ("Pesanan tidak sesuai dengan pesanan pada meja.\n");
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 12){ //RECIPE
				ShowRecipe (Resep);
			}

			/*  LAKUKAN UPDATE STATUS DI SINI */
			printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",CURRENT_ROOM,Absis(Posisi(P)),Ordinat(Posisi(P)));
			printf("Nyawa Tersisa : %d\n", Health(P));
			printf("Uang : %d\n", Money(P));
			printf("TICK = %d\n",GAME_CLOCK);
			GENERATE_PELANGGAN (GAME_CLOCK, &Q); // KALO JAMNYA MERUPAKAN KELIPATAN 15, AKAN MENAMBAH 1 PELANGGAN
			UpdateSabarAntri (&Q); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN DI ANTRIAN
			UpdateKesabaranDuduk (&N); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN YANG SUDAH DUDUK
		}while(COMMAND != 13 && HEALTH_CUKUP(P));


	}

	return 0;
}

/*Realisasi fungsi yang disebutkan di atas*/

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
	if (IsKataSama(K,GU))
	{
		*COMMAND = 1;
	}
	else if (IsKataSama(K,GD))
	{
		*COMMAND = 2;
	}
	else if (IsKataSama(K,GL))
	{
		*COMMAND = 3;
	}
	else if (IsKataSama(K,GR))
	{
		*COMMAND = 4;
	}
	else if (IsKataSama(K,OR))
	{
		*COMMAND = 5;
	}
	else if (IsKataSama(K,PT))
	{
		*COMMAND = 6;
	}
	else if (IsKataSama(K,TK))
	{
		*COMMAND = 7;
	}
	else if (IsKataSama(K,CH))
	{
		*COMMAND = 8;
	}
	else if (IsKataSama(K,CT))
	{
		*COMMAND = 9;
	}
	else if (IsKataSama(K,PL))
	{
		*COMMAND = 10;
	}
	else if (IsKataSama(K,GV))
	{
		*COMMAND = 11;
	}
	else if (IsKataSama(K,RC))
	{
		*COMMAND = 12;
	}
	else if (IsKataSama(K,EX))
	{
		*COMMAND = 13;
	}
}

void GENERATE_PELANGGAN (JAM J, Queue *Q)
{
	if (J%15 == 0)
	{
		GeneratePelanggan (Q);
	}
}
