/* 	File: antri.h
	Tanggal: 17 November 2018 
	Wanul                     */

#ifndef ANTRI_H
#define ANTRI_H

#include "boolean.h"
#include "queue.h"
#include "duduk.h"
#include "player.h"
#include "jam.h"
	
void SetEmptyAntri (Queue *Q, int Max);
//I.S. Sembarang
//F.S. Sebuah Q kosong terbentuk. Kalo alokasi gagal, Q kosong.

void TambahCust (Queue *Q, jumlah J, kesabaran K);
//I.S. Q mungkin kosong, tabel tidak penuh
//F.S. Masukan di atas jadi tail baru, circular buffer.

void DelCust (PLAYER *P1, Queue *Q, addressQ *P, jumlah *J, kesabaran *K);
//I.S. Q tidak kosong
//F.S. Head dihapus, info dari head dimasukin ke variabel di atas. Nyawa kurang 1.

boolean CekSabarAntri (Queue Q);
/*	Ngecek apakah di Queue antrian udah ada yang abis kesabarannya
	Kalo ada yang abis keluarannya true */

void UpdateSabarAntri (Queue *Q);
/*	Setiap langkah yang player lakukan, bakal ngurangin sabar setiap yang antri */
// I.S. Asumsi gak ada yang kesabarannya 0

void PlaceCustAntri (NoMeja *N, int X, Queue *Q, addressQ *P, jumlah *J, kesabaran *K);
//	Ini sama persis kayak DelCust, cuma nyawanya gak ngurang dan ditempatin di meja tertentu. X nomor meja yang dituju
//	Langsung diisi informasi buat meja yang dipake di duduk.h

void GeneratePelanggan (Queue *Q);
// Buat generate pelanggan

void DelAntriSabar (Queue *Q, PLAYER *P);
// menghapus pelanggan duduk, sabar habis

#endif