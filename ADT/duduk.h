/* 	File: duduk.h
	Tanggal: 17 November 2018 
	Wanul                     */

#ifndef DUDUK_H
#define DUDUK_H

#include "boolean.h"
/* Definisi bagian duduk */
/*	Gw definisiin variabel baru sementara nomor meja, nanti kalo ada yang
	lain juga yang definisiin variabel nomor meja gw ngikut */
// Harusnya keka yang bikin definisi meja dan kapasitas
#define JmlMeja 12
#define Nil -999
#define Habis 0

typedef struct {
	int Capacity[13];
	int Isi[13]; //ini menyatakan jumlah yang diisi dari meja
	boolean Available[13]; 	//ini menyatakan apakah meja udah didudukin apa belum
						//kalo udah didudukin bernilai false
	int Kesabaran[13];
	int Pesanan[13]; // dalam integer, ngurut sesuai urutan di tree
} NoMeja;

/* Jika N adalah NoMeja, dan i adalah nomor mejanya, maka akses elemen: */
#define Cap(N,i) (N).Capacity[(i)]
#define Isi(N,i) (N).Isi[(i)]
#define Avail(N,i) (N).Available[(i)]
#define Sabar(N,i) (N).Kesabaran[(i)]
#define Pesan(N,i) (N).Pesanan[(i)]
/* Kalo ada yang bernilai Nil, maka belom didefinisiin */

void SetEmpty (NoMeja *N);
/*	I.S. Sembarang
	F.S. Semua kursi di ruangan tertentu dibikin kosong */
	
boolean CekKosong (NoMeja N, int X);
// hasilnya true kalo meja N kosong
// I.S.	X diasumsikan benar

int CekKapasitas (NoMeja N, int X);
// I.S. X diasumsikan benar

void DelDuduk (NoMeja *N, int X);
/*	I.S. N diasumsikan benar. Tempat duduk tidak kosong
	F.S. Tempat duduk di meja N kosong */

int JmlSabarHabis (NoMeja N);
// menghasilkan berapa yang kesabaran habis

void UpdateKesabaranDuduk (NoMeja *N);
// untuk setiap gerakan, per ruangan setiap meja kesabaran kurang 1

/* PlaceCustDuduk () ini gak perlu sama kayak di antri (PlaceCustAntri)*/

/* CekPesanan (); ini gak perlu, soalnya udah ada Pesan(N) */

/* MakeRandomPesanan (); udah tersedia di (PlaceCustAntri) */
void DelSabarDuduk (NoMeja *N, PLAYER *P);
// yang duduk dan kesabaran = 0 dihapus, nyawa kurang 1

#endif
