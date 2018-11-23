/* 	File: duduk.c
	Tanggal: 17 November 2018 
	Wanul                     */
	
#include <stdio.h>
#include "duduk.h"
#include "player.h"

void SetEmpty (NoMeja *N)
/*	I.S. Sembarang
	F.S. Semua kursi di ruangan tertentu dibikin kosong */
{
	int i = 1;
	while (i <= JmlMeja)
	{
		Isi(*N,i) = 0;
		Avail(*N,i) = true;
		Sabar(*N,i) = Nil;
		Pesan(*N,i) = Nil;
	}
}		
	
boolean CekKosong (NoMeja N, int X)
// hasilnya true kalo meja N kosong
// I.S.	X diasumsikan benar
{
	return (Avail(N,X));
}

int CekKapasitas (NoMeja N, int X)
// I.S. X diasumsikan benar
{
	return (Cap(N,X));
}

void DelDuduk (NoMeja *N, int X)
/*	I.S. X diasumsikan benar. Tempat duduk tidak kosong
	F.S. Tempat duduk di meja N kosong */
{
	Isi(*N,i) = 0;
	Avail(*N,i) = true;
	Sabar(*N,i) = Nil;
	Pesan(*N,i) = Nil;
}

int JmlSabarHabis (NoMeja N)
// menghasilkan berapa yang kesabaran habis
{
	int i = 1, out = 0;
	while (i <= JmlMeja)
	{
		if (!Avail(N,i))
		{
			if (Sabar(N,i) == Habis)
			{
				out = out + 1;
			}
		}
		i = i + 1;
	}
	return (out);
}
void UpdateKesabaranDuduk (NoMeja *N)
// untuk setiap gerakan, per ruangan setiap meja kesabaran kurang 1
{
	int i = 1;
	while (i <= JmlMeja)
	{
		if (!Avail(*N,i))
		{
			Sabar(*N,i) = Sabar(*N,i) - 1;
		}
		i = i + 1;
	}
}
/* PlaceCustDuduk () ini gak perlu sama kayak di antri (PlaceCustAntri)*/

/* CekPesanan (); ini gak perlu, soalnya udah ada Pesan(N) */

/* MakeRandomPesanan (); udah tersedia di (PlaceCustAntri) */
void DelSabarDuduk (NoMeja *N, PLAYER *P)
// yang duduk dan kesabaran = 0 dihapus, nyawa kurang 1
{
	int i = 1;
	while (i <= JmlMeja)
	{
		if (!Avail(*N,i))
		{
			if (Sabar(*N,i) == Habis)
			{
				Isi(*N,i) = 0;
				Avail(*N,i) = true;
				Sabar(*N,i) = Nil;
				Pesan(*N,i) = Nil;
				Health(*P) = Health(*P) - 1;
			}
		}
		i = i + 1;
	}
}
