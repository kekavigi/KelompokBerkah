/* 	File: duduk.c
	Tanggal: 17 November 2018 
	Wanul                     */
	
#include <stdio.h>
#include <stdlib.h>
#include "duduk.h"

void SetEmptyDuduk (NoMeja *N)
/*	I.S. Sembarang
	F.S. Semua kursi di ruangan tertentu dibikin kosong */
{
	int i = 1;
	while (i <= JmlMeja)
	{
		Isi(*N,i) = 0;
		Avail(*N,i) = true;
		Sabar(*N,i) = UndDuduk;
		Pesan(*N,i) = UndDuduk;
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

void DelDuduk (Pesanan *DaftarPesanan, NoMeja *N, int X)
/*	I.S. X diasumsikan benar. Tempat duduk tidak kosong
	F.S. Tempat duduk di meja N kosong */
{
	delPesanan (DaftarPesanan, Pesan(*N,X), X);
	Isi(*N,X) = 0;
	Avail(*N,X) = true;
	Sabar(*N,X) = UndDuduk;
	Pesan(*N,X) = UndDuduk;
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

void DelSabarDuduk (Pesanan *DaftarPesanan, NoMeja *N, PLAYER *P)
// yang duduk dan kesabaran = 0 dihapus, nyawa kurang 1
{
	int i = 1;
	while (i <= JmlMeja)
	{
		if (!Avail(*N,i))
		{
			if (Sabar(*N,i) == Habis)
			{
				delPesanan (DaftarPesanan, Pesan(*N,i), i);
				Isi(*N,i) = 0;
				Avail(*N,i) = true;
				Sabar(*N,i) = UndDuduk;
				Pesan(*N,i) = UndDuduk;
				UPDATE_LIFE (P);
			}
		}
		i = i + 1;
	}
}

void IsiCap (NoMeja *N)
// ngisi capacity setiap kursi
{
	int i = 0;
	while (i <= JmlMeja)
	{
		if (i == 0)
		{
			Cap(*N,i) = 0;
		}
		else if (i%2 == 0)
		{
			Cap(*N,i) = 2;
		}
		else if (i%2 == 1)
		{
			Cap(*N,i) = 4;
		}
		i = i + 1;
	}
}

/*int main ()
{
	NoMeja N;
	SetEmptyDuduk (&N);
	printf ("%d\n", Isi(N,2));
	return 0;
}*/
