/* 	File: antri.c
	Tanggal: 17 November 2018 
	Wanul                     */
	
#include <stdio.h>
#include "duduk.h"

void SetEmpty ()
/*	I.S. Sembarang
	F.S. Semua kursi di ruangan tertentu dibikin kosong */
{
	int N = 1;
	while (N <= JmlMeja)
	{
		Isi(N) = 0;
		Avail(N) = true;
		Sabar(N) = Nil;
		Pesan(N) = Nil;
		N = N + 1;
	}
}		
	
boolean CekKosong (NoMeja N)
// hasilnya true kalo meja N kosong
// I.S.	N diasumsikan benar
{
	return (Avail(N));
}

int CekKapasitas (NoMeja N)
// I.S. N diasumsikan benar
{
	return (Cap(N));
}

void DelDuduk (NoMeja N)
/*	I.S. N diasumsikan benar. Tempat duduk tidak kosong
	F.S. Tempat duduk di meja N kosong */
{
	Isi(N) = 0;
	Avail(N) = true;
	Sabar(N) = Nil;
	Pesan(N) = Nil;
}

boolean CekKesabaranDuduk ()
// hasilnya true kalo ada yang kesabarannya jadi 0
{
	boolean cek = false;
	int N = 1;
	while (N <= JmlMeja)
	{
		if (!Avail(N))
		{
			if (Sabar(N) == Habis)
			{
				cek = true;
			}
		}
		N = N + 1;
	}
}
void UpdateKesabaranDuduk ()
// untuk setiap gerakan, per ruangan setiap meja kesabaran kurang 1
{
	int N = 1;
	while (N <= JmlMeja)
	{
		if (!Avail(N))
		{
			Sabar(N) = Sabar(N) - 1;
		}
		N = N + 1;
	}
}
/* PlaceCustDuduk () ini gak perlu sama kayak di antri (PlaceCustAntri)*/

/* CekPesanan (); ini gak perlu, soalnya udah ada Pesan(N) */

/* MakeRandomPesanan (); udah tersedia di (PlaceCustAntri) */
void DelSabarDuduk (NoMeja N, Life *L)
// yang duduk dan kesabaran = 0 dihapus, nyawa kurang 1
{
	Isi(N) = 0;
	Avail(N) = true;
	Sabar(N) = Nil;
	Pesan(N) = Nil;
	*L = *L - 1;
}