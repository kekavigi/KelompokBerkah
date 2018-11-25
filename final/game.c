#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "peta.h"
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
#include "seeker.h"
#include "duduk.h"
#include "pesanan.h"
#include "matriks.h"
#include "queue.h"
#include "antri.h"
#include "interface.h"

/* VARIABEL GAMES    */
	PLAYER P;
	JAM GAME_CLOCK;
	MATRIKS M;
	char NAMA_PEMAIN[20] = ""; // Ini buat nama pemain
	char NAMA_KOSONG[20] = ""; // CUMA BUAT MENGECEK.
	boolean STATE_1,STATE_2,STATE_3 = false;
	int COMMAND; //PERINTAH DARI USER
	int CURRENT_ROOM; //ROOM SEKARANG PLAYER DI MANA
	BinTree Resep; // Digunakan Untuk menyimpan resep
	Stack Hand;	// Digunakan sebagai STACK tangan
	Stack Nampan; //Digunakan Sebagai STACK Nampan
	/*Variabel penyimpanan buat Nampan*/
		int Makanan;
	TabInt DPesanan; // Digunakan Sebagai Daftar Pesanan
	int ambil; // Digunakan untuk mengambil bahan secara manual
	Kata GU, GD, GL, GR, OR, PT, TK, CH1, CT1, PL, GV, RC, EX; //Digunakan sebagai penyimpan command
	NoMeja N; //Buat ngurus orang duduk
	Queue Q; //Buat ngurus orang antri
	int benda,NOMOR_MEJA,KMEJA; // keterangan benda
	POINT seek,PMEJA; //penanda seeker
	int nm, nmTab[50]; //Buat simpan nomor meja
	/*Variabel iterasi nmTab*/
		int nmT;
	/*Variabel buat cari meja*/
		int room;
 		int benda,KMEJA;
 		POINT seek,PMEJA;
	POINT Pnm; //Buat ngurus fungsi yang nyari nomor meja
	/*Variabel buat antri*/
		int J, K;
		addressQ P1;
		#define MaxAntri 50
	Pesanan DaftarPesanan; //Buat ngurus daftar pesanan
	extern PETA Ruang1;
	extern PETA Ruang2;
	extern PETA Ruang3;
	extern PETA Dapur;
	extern PETA RuangAktif;

/*Fungsi Yang Akan Digunakan*/
	void SiapkanKata();
	// Siapkan semua kata
	boolean CekCommandValid (Kata K);
	// Menghasilkan true kalo commandnya benar
	void BACA_COMMAND (int *COMMAND);
	// Prosedur ini buat translate masukan dari pengguna, dari string ke integer
	void GENERATE_PELANGGAN (JAM J, Queue *Q);
	// Prosedur ini buat generate pelanggan setiap J kelipatan 15
	void PrtPesan (Pesanan DaftarPesanan);
	// Prosedur ini buat print pesanan
	void TambahUang (PLAYER *P, NoMeja N, int X);
	// Prosedur untuk menambahkan uang ketika pesanan disampaikan ke pelanggan

int main (){
	
/* ANTARMUKA GAME    */ // TAMPILAN PERTAMA YANG DITUNJUKKAN SAAT GAME DIMULAI
	do{
		system("cls");
		Opening (); // Menampilkan antar muka
		printf("Pilih Menu [1 = NEW GAME, 2 = START GAME, 3 = EXIT] : ");
		scanf("%d", &COMMAND);
		printf ("+--------------------------------------------------+\n");

		if(COMMAND == 1){
			system("cls");
			printf("Nama Kamu : ");
			scanf("%s",NAMA_PEMAIN);
		}else if (COMMAND == 2){
			Informasi ();
			if (strcmp(NAMA_PEMAIN,NAMA_KOSONG) == 0){
				printf("Silahkan masukkan nama Kamu terlebih dahulu.\n");
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
		Credit ();
	}else if(STATE_1){
		printf("Halo %s, selamat bermain Engi's Kitchen Expansion. Good luck!\n\n",NAMA_PEMAIN);
		/* STATE AWAL GAME    */  // SET KEADAAN AWAL GAME DI SINI MISAL JAM DIMULAI DARI 0, NYAWA PLAYER 0, HAND MASIH KOSONG, KEADAAN AWAL SEMUA MAP
		START_JAM(&GAME_CLOCK);
		START_PLAYER(&P);
		SiapkanKata();
		SetEmptyDuduk (&N);
		IsiCap (&N);
		SetEmptyAntri (&Q, MaxAntri);
		nmT = 1;
		CURRENT_ROOM = 1;
		LoadTree(&Resep); // Mengisi Resep
		MakePETA(&Dapur,  "ruang4.txt", 1, Posisi(P));
		MakePETA(&Ruang1, "ruang1.txt", 2, MakePOINT(0,0));
		MakePETA(&Ruang2, "ruang2.txt", 3, MakePOINT(0,0));
		MakePETA(&Ruang3, "ruang3.txt", 4, MakePOINT(0,0));
		RuangAktif = Dapur;
		GENERATE_PELANGGAN (GAME_CLOCK, &Q); // KALO JAMNYA MERUPAKAN KELIPATAN 15, AKAN MENAMBAH 1 PELANGGAN

		TulisPETA(RuangAktif);
		printf ("\n");
		printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",CURRENT_ROOM,Absis(Posisi(P)),Ordinat(Posisi(P)));
		printf ("\n");
		printf("Nyawa Tersisa : %d\n", Health(P));
		printf("Uang          : %d\n", Money(P));
		printf ("\n");
		
		/*  INI GAMEPLAY */
		do{
			BACA_COMMAND(&COMMAND); //PROSEDUR UNTUK MEMBACA PERINTAH DARI USER, MASUKAN DARI USER BERUPA KATA, BUKAN ANGKA.
			system("cls");
			/*
			1 : GU		5 : ORDER	9  : CT			13.EXIT
			2 : GD		6 : PUT		10 : PLACE
			3 : GL		7 : TAKE 	11 : GIVE
			4:  GR		8 : CH		12 : RECIPE
			*/
			if (COMMAND == 1){
				UPDATE_POSISI_PLAYER(&P, 1, &CURRENT_ROOM); // PLAYER GERAK KE ATAS
				system("cls");
				printf ("Player bergerak ke atas.\n\n");
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				UpdatePETA(&RuangAktif, 1);
			} else if (COMMAND == 2){
				UPDATE_POSISI_PLAYER(&P, 2, &CURRENT_ROOM);
				system("cls");
				printf ("Player bergerak ke bawah.\n\n");
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				UpdatePETA(&RuangAktif, 2);
			} else if (COMMAND == 3){
				UPDATE_POSISI_PLAYER(&P, 3, &CURRENT_ROOM);
				system("cls");
				printf ("Player bergerak ke kiri.\n\n");
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				UpdatePETA(&RuangAktif, 3);
			} else if (COMMAND == 4){
				UPDATE_POSISI_PLAYER(&P, 4, &CURRENT_ROOM);
				system("cls");
				printf ("Player bergerak ke kanan.\n\n");
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
				UpdatePETA(&RuangAktif, 4);
			} else if (COMMAND == 5){ // ORDER
				IsKursiMejaAda(P,CURRENT_ROOM,&benda,&seek);
 				if (benda == 1 || benda == 2){
 					CariMeja(seek, benda, CURRENT_ROOM, &PMEJA, &nm, &KMEJA);
 					printf("Di sekitar player ada meja yang bernomor %d, dan kapasitasnya adalah %d.\n",nm, KMEJA);
 				}else{
 					printf("\n");
					printf("Tidak ada apa-apa di sekitar player.\n");
 				}
				if (!Avail(N,nm))
				{
					addPesanan (&DaftarPesanan,Pesan(N,nm),nm);
					nmTab[nmT] = nm;
					nmT = nmT + 1;
					printf ("Pesanan telah diambil.\n\n");
				}
				else
				{
					printf ("Tidak dapat mengambil pesanan.\n");
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 6){ //PUT
				
				IsKursiMejaAda(P,CURRENT_ROOM,&benda,&seek);
				if (!CekMejaTray(seek)){
					printf("Hanya bisa memasak pada meja Tray!\n\n");
				}else if(IsFullStackt(Nampan)){
					printf("Nampan sudah Penuh\n");
				} else{
					PUT(Resep,&Hand,&Nampan);
					if(!IsEmptyStackt(Hand)){
						printf("Tidak bisa membuat menu makanan dari bahan yang ada\n");
					}
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 7) { //TAKE
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
				IsKursiMejaAda(P,CURRENT_ROOM,&benda,&seek);
				if (benda != 2){
					printf("Tidak ada meja terdekat.\n\n");
				}else if(IsFullStackt(Hand)){
					printf("Tangan Anda Penuh\n");
				} else {
					if(benda == 2){
						ambil = CekMejaRacik(seek);
						printf ("Bahan telah diambil.\n\n");
					}else{
						ambil = 0;
					}
					TAKE(&Hand,ambil);					
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 8){ //CH
				CH(&Hand);
				printf ("Bahan di hand telah dibuang.\n\n");
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 9){ //CT
				CT(&Nampan);
				printf ("Makanan pada tray telah dibuang.\n\n");				
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 10){ //PLACE
				IsKursiMejaAda(P,CURRENT_ROOM,&benda,&seek);
 				if (benda == 1 || benda == 2){
 					CariMeja(seek, benda, CURRENT_ROOM, &PMEJA, &nm, &KMEJA);
 					printf("Di sekitar player ada meja yang bernomor %d, dan kapasitasnya adalah %d.\n",nm,KMEJA);
 					printf ("\n");
 				}else{
 					printf("Tidak ada apa-apa di sekitar player.\n");
 				}
				if (IsEmptyQueue(Q))
				{
					printf ("Antrian kosong.\n");
				}
				else
				{
					if ((jumlahHead(Q) <= Cap(N,nm)) && (Avail(N,nm)))
					{
						PlaceCustAntri (&N, nm, &Q, &P1, &J, &K);
						printf ("Pelanggan telah ditempatkan pada meja.\n\n");
						IsiKursiKosong(&Mat(RuangAktif), PMEJA, jumlahHead(Q));
						UpdatePETA(&RuangAktif, COMMAND);
					}
					else
					{
						printf ("Kursi tidak bisa ditempati.\n");
						printf ("\n");
					}
				}
				JADV(&GAME_CLOCK); // JAM BERTAMBAH
			} else if (COMMAND == 11){ //GIVE
				IsKursiMejaAda(P,CURRENT_ROOM,&benda,&seek);
 				if (benda == 1 || benda == 2){
 					CariMeja(seek, benda, CURRENT_ROOM, &PMEJA, &nm, &KMEJA);
 					printf("Di sekitar player ada meja yang bernomor %d, dan kapasitasnya adalah %d.\n",nm,KMEJA);
 					printf ("\n");
 				}else{
 					printf("Tidak ada apa-apa di sekitar player.\n");
 				}
				if (InfoTop(Nampan) == (Pesan(N,nm) + 1))
				{
					TambahUang (&P, N, nm);
					DelDuduk (&DaftarPesanan,&N,nm);
					Pop (&Nampan, &Makanan);
					printf ("Makanan telah diantarkan, pelanggan pergi.\n\n");
					printf ("lolos\n");
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
			UpdatePelangganPETA(&RuangAktif, N);
			TulisPETA(RuangAktif);
			printf ("\n");
			printf("Kamu ada di ruang %d, Posisi kamu di [%d,%d]\n",CURRENT_ROOM,Absis(Posisi(P)),Ordinat(Posisi(P)));
			printf ("\n");
			printf("Nyawa Tersisa : %d\n", Health(P));
			printf("Uang          : %d\n", Money(P));
			printf("Waktu         : %d\n", GAME_CLOCK);
			
			GENERATE_PELANGGAN (GAME_CLOCK, &Q); // KALO JAMNYA MERUPAKAN KELIPATAN 15, AKAN MENAMBAH 1 PELANGGAN
			/*OUTPUT*/
			printf("Antrian:\n");
			PrintQueue(Q);
			printf ("\n\n");
			printf("HAND : \n");
			PrintStackt(Hand);	
			printf ("\n");
			printf("Nampan : \n");
			PrintStackt(Nampan);
			printf ("\n");
			printf ("Pesanan : \n");
			PrtPesan(DaftarPesanan);
			printf ("\n");

			UpdateSabarAntri (&Q); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN DI ANTRIAN
			DelAntriSabar (&Q,&P); // HAPUS PELANGGAN ANTRI, KESABARAN HABIS, NYAWA KURANG 1
			UpdateKesabaranDuduk (&N); // MENGURANGI 1 WAKTU TUNGGU TIAP PELANGGAN YANG SUDAH DUDUK
			DelSabarDuduk (&DaftarPesanan, &N, &P); //HAPUS PELANGGAN YANG DUDUK, KESABARAN HABIS
		}while(COMMAND != 13 && HEALTH_CUKUP(P));

		if (Health(P) == 0)
		{
			system("cls");
			GameOver ();
			printf ("%s telah bermain selama %d tick, dengan skor akhir %d.\n", NAMA_PEMAIN, GAME_CLOCK, Money(P));
		}
		Credit ();
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
    CreateKata("CH",&CH1);
    CreateKata("CT",&CT1);
    CreateKata("PLACE",&PL);
	CreateKata("GIVE",&GV);
	CreateKata("RECIPE",&RC);
	CreateKata("EXIT",&EX);
}

boolean CekCommandValid (Kata K)
{
	return ((IsKataSama(K,GU))||(IsKataSama(K,GD))||(IsKataSama(K,GL))||(IsKataSama(K,GR))||(IsKataSama(K,OR))||(IsKataSama(K,PT))||(IsKataSama(K,TK))||(IsKataSama(K,CH1))||(IsKataSama(K,CT1))||(IsKataSama(K,PL))||(IsKataSama(K,GV))||(IsKataSama(K,RC))||(IsKataSama(K,EX)));
}

void BACA_COMMAND (int *COMMAND)
{
	Kata K;

	do
	{
		printf ("Command : ");
		InputUser(&K);
		if (!CekCommandValid(K))
		{
			printf ("Command tidak tersedia, silahkan masukkan lagi.\n");
		}
		
	}while (!CekCommandValid(K));

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
	else if (IsKataSama(K,CH1))
	{
		*COMMAND = 8;
	}
	else if (IsKataSama(K,CT1))
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

void testmap(){


}

void GENERATE_PELANGGAN (JAM J, Queue *Q)
{
	
	if ((J%15) == 0)
	{
		GeneratePelanggan (Q);
	}
}

/*int ConvertTopTrayInt (Stack S)
{
	int i = 1; //iterasi
	while (i <= 8)
	{
		if (InfoTop(S) == menu[i])
		{
			return (i);
		}
		i = i + 1;
	}
}*/

void TambahUang (PLAYER *P, NoMeja N, int nm)
{
	if (Pesan(N,nm) == 17) //Nambahin duit dikali jumlah pelanggan
	{
		Money(*P) = Money(*P) + 40*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 18)
	{
		Money(*P) = Money(*P) + 20*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 19)
	{
		Money(*P) = Money(*P) + 30*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 20)
	{
		Money(*P) = Money(*P) + 60*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 21)
	{
		Money(*P) = Money(*P) + 70*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 22)
	{
		Money(*P) = Money(*P) + 70*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 23)
	{
		Money(*P) = Money(*P) + 100*Isi(N,nm);
	}
	else if (Pesan(N,nm) == 24)
	{
		Money(*P) = Money(*P) + 90*Isi(N,nm);
	}
}
void PrtPesan (Pesanan DaftarPesanan)
{
	int i = 1; /*iterasi*/
	int j; /*pilihan menu*/
	if (!IsEmptyPesanan(DaftarPesanan))
	{
		while (i <= Neff(DaftarPesanan))
		{
			j = Elmt(DaftarPesanan,i) - 15;
			printf ("%s, %d\n", menu[j], nmTab[i]);
			i = i + 1;
		}
	}
	else
	{
		printf ("(KOSONG)\n");
	}
}
