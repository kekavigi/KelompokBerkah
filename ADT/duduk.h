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
#define JmlMeja 4
#define Nil -999
#define Habis 0

typedef struct {
	int Nomor;
	int Capacity;
	int Isi; //ini menyatakan jumlah yang diisi dari meja
	boolean Available; 	//ini menyatakan apakah meja udah didudukin apa belum
						//kalo udah didudukin bernilai false
	int Kesabaran;
	int Pesanan; // dalam integer, ngurut sesuai urutan di tree
} NoMeja;

/* Jika N adalah NoMeja, maka akses elemen: */
#define No(N) (N).Nomor
#define Cap(N) (N).Capacity
#define Isi(N) (N).Isi
#define Avail(N) (N).Available
#define Sabar(N) (N).Kesabaran
#define Pesan(N) (N).Pesanan
/* Kalo ada yang bernilai Nil, maka belom didefinisiin */

/* Di sini gw definisiin nyawa, nanti diganti setelah liat code Fio */

void SetEmpty ();
/*	I.S. Sembarang
	F.S. Semua kursi di ruangan tertentu dibikin kosong */
	
boolean CekKosong (NoMeja N);
// hasilnya true kalo meja N kosong
// I.S.	N diasumsikan benar

int CekKapasitas (NoMeja N);
// I.S. N diasumsikan benar

void DelDuduk (NoMeja N);
/*	I.S. N diasumsikan benar. Tempat duduk tidak kosong
	F.S. Tempat duduk di meja N kosong */

boolean CekKesabaranDuduk ();
// hasilnya true kalo ada yang kesabarannya jadi 0

void UpdateKesabaranDuduk ();
// untuk setiap gerakan, per ruangan setiap meja kesabaran kurang 1

/* PlaceCustDuduk () ini gak perlu sama kayak di antri (PlaceCustAntri)*/

/* CekPesanan (); ini gak perlu, soalnya udah ada Pesan(N) */

/* MakeRandomPesanan (); udah tersedia di (PlaceCustAntri) */
void DelSabarDuduk (NoMeja N, PLAYER *P);
// yang duduk dan kesabaran = 0 dihapus, nyawa kurang 1

#endif
