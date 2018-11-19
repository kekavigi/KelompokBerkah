/* 	File: antri.c
	Tanggal: 17 November 2018 
	Wanul                     */
	
#include <stdio.h>
#include "antrian.h"

void SetEmptyAntri (Queue *Q, int Max)
//I.S. Sembarang
//F.S. Sebuah Q kosong terbentuk. Kalo alokasi gagal, Q kosong.
{
	CreateEmptyQueue (Q, Max);
}

void TambahCust (Queue *Q, time T, jumlah J, waiting W, kesabaran K)
//I.S. Q mungkin kosong, tabel tidak penuh
//F.S. Masukan di atas jadi tail baru, circular buffer.
{
	AddQueue (Q, T, J, W, K);
}

void DelCust (Life *L, Queue *Q, addressQ *P, time *T, jumlah *J, waiting *W, kesabaran *K)
//I.S. Q tidak kosong
//F.S. Head dihapus, info dari head dimasukin ke variabel di atas. Nyawa kurang 1.
{
	DelQueue (Q, P, T, J, W, K);
	*L = *L - 1;
}

boolean CekSabarAntri (Queue Q)
/*	Ngecek apakah di Queue antrian udah ada yang abis kesabarannya
	Kalo ada yang abis keluarannya true */
{
	boolean abis = false;
	int t, j, w, k;
	if (IsEmptyQueue(Q))
	{
		return (abis);
	}
	else
	{
		while (!IsEmptyQueue(Q) && !abis)
		{
			DelQueue (&Q, &P, &t, &j, &w, &k);
			if (k == 0)
			{
				abis = true;
			}
		}
		return (abis);
	}
}

void UpdateSabarAntri (Queue *Q)
/*	Setiap langkah yang player lakukan, bakal ngurangin sabar setiap yang antri */
// I.S. Asumsi gak ada yang kesabarannya 0
{
	//Ini gw bingung algoritmanya, tolong dibantu
}

void PlaceCustAntri (NoMeja N, Queue *Q, addressQ *P, time *T, jumlah *J, waiting *W, kesabaran *K)
//	Ini sama persis kayak DelCust, cuma nyawanya gak ngurang dan ditempatin di meja tertentu
//	Langsung diisi informasi buat meja yang dipake di duduk.h
{
	if (Cap(N) >= jumlahHead(*Q))
	{
		Avail(N) = false;
		Isi(N) = jumlahHead(*Q);
		Sabar(N) = rand() % (70 + 1 - 50) + 50;
		Pesan(N) = rand() % (8 + 1 - 1) + 1;
		DelQueue (Q, P, T, J, W, K);
	}
	else
	{
		printf("Meja tidak cukup\n");
	}
}
