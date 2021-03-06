/* 	File: antri.c
	Tanggal: 17 November 2018 
	Wanul                     */
	
#include <stdio.h>
#include <stdlib.h>
#include "antri.h"
#include "duduk.h"

void SetEmptyAntri (Queue *Q, int Max)
//I.S. Sembarang
//F.S. Sebuah Q kosong terbentuk. Kalo alokasi gagal, Q kosong.
{
	CreateEmptyQueue (Q, Max);
}

void TambahCust (Queue *Q, jumlah J, kesabaran K)
//I.S. Q mungkin kosong, tabel tidak penuh
//F.S. Masukan di atas jadi tail baru, circular buffer.
{
	AddQueue (Q, J, K);
}

void DelCust (PLAYER *P1, Queue *Q, addressQ *P, jumlah *J, kesabaran *K)
//I.S. Q tidak kosong
//F.S. Head dihapus, info dari head dimasukin ke variabel di atas. Nyawa kurang 1.
{
	DelQueue (Q, P, J, K);
	UPDATE_LIFE (P1);
}

boolean CekSabarAntri (Queue Q)
//	Ngecek apakah di Queue antrian udah ada yang abis kesabarannya
//	Kalo ada yang abis keluarannya true
{
	boolean abis = false;
	int j, k;
	addressQ P;
	if (IsEmptyQueue(Q))
	{
		return (abis);
	}
	else
	{
		while (!IsEmptyQueue(Q) && !(abis))
		{
			DelQueue (&Q, &P, &j, &k);
			printf ("%d\n",k);
			if (k == 0)
			{
				abis = true;
			}
		}
		return (abis);
	}
}

void UpdateSabarAntri (Queue *Q)
//	Setiap langkah yang player lakukan, bakal ngurangin sabar setiap yang antri
// I.S. Asumsi gak ada yang kesabarannya 0
{
	Queue QTemp1, QTemp2;
	CreateEmptyQueue (&QTemp1, MaxElQ(*Q));
	CreateEmptyQueue (&QTemp2, MaxElQ(*Q));
	int J, K;
	addressQ P;
	CopyQueue (*Q, &QTemp1);
	while (!IsEmptyQueue(QTemp1))
	{
		kesabaranHead(QTemp1) = kesabaranHead(QTemp1) - 1;
		DelQueue(&QTemp1, &P, &J, &K);
		AddQueue(&QTemp2, J, K);
	}
	CopyQueue (QTemp2, Q);
	DealokasiQueue (&QTemp1);
	DealokasiQueue (&QTemp2);
}

void PlaceCustAntri (NoMeja *N, int X, Queue *Q, addressQ *P, jumlah *J, kesabaran *K)
//	Ini sama persis kayak DelCust, cuma nyawanya gak ngurang dan ditempatin di meja tertentu. X nomor meja yang dituju
//	Langsung diisi informasi buat meja yang dipake di duduk.h
{
	if (Cap(*N,X) >= jumlahHead(*Q))
	{
		Avail(*N,X) = false;
		Isi(*N,X) = jumlahHead(*Q);
		J_DUDUK(&Sabar(*N,X));
		Pesan(*N,X) = rand() % (24 + 1 - 17) + 17;
		DelQueue (Q, P, J, K);
	}
	else
	{
		printf("Meja tidak cukup.\n");
	}
}

void GeneratePelanggan (Queue *Q)
// Buat generate pelanggan
{
	JAM K;
	int J; // jumlah pengunjung
	J = rand() % (4 + 1 - 1) + 1;
	J_ANTRI(&K);
	AddQueue (Q,J,K);
}

void DelAntriSabar (Queue *Q, PLAYER *P)
// menghapus pelanggan duduk, sabar habis
{
	addressQ i;
	Queue Qtemp;
	CreateEmptyQueue (&Qtemp, MaxElQ(*Q));
	CopyQueue(*Q,&Qtemp);
	if(!IsEmptyQueue(*Q)){
		for(i=Head(*Q);i<=Tail(*Q);i++){
			if((Qtemp.K[i])==0){
				//Qtemp=DeleteP(*Q,i);
				printf ("Kesabaran salah satu pelanggan yang antri habis! Nyawa berkurang 1.\n");
				CopyQueue(DeleteP(Qtemp,i),&Qtemp);
				UPDATE_LIFE(P);
			}
			else if((Qtemp.K[i])==5)
			{
				printf ("Kesabaran pelanggan yang antri ke %d sisa 5.\n",i);
			}
			/*else
			{
				CopyQueue(*Q,&Qtemp);
			}*/
		}
	}
	CopyQueue(Qtemp,Q);
	DealokasiQueue (&Qtemp);
}