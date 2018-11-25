/* 	File: interface.c
	Tanggal: 25 November 2018 
	Wanul                     */
	
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void Opening ()
{
	printf ("          +------------------------------+\n");
	printf ("          | --Engi's Kitchen Expansion-- |\n");
	printf ("          |                              |\n");
	printf ("          | Sebuah game oleh:            |\n");
	printf ("          | AL, FIO, DANDI, KEKA, WANUL  |\n");
	printf ("          +------------------------------+\n");
	printf ("          +------------------------------+\n");
	printf ("          |     Silahkan pilih menu:     |\n");
	printf ("          |     1. New Game              |\n");
	printf ("          |     2. Start Game            |\n");
	printf ("          |     3. Exit                  |\n");
	printf ("          +------------------------------+\n");
	printf ("Pastikan window Kamu dalam keadaan Fullscreen\n");
	printf ("+--------------------------------------------------+\n");
}

void Informasi ()
{
	printf ("+--------------------------------------------------+\n");
	printf ("|                    INFORMASI                     |\n");
	printf ("+--------------------------------------------------+\n");
	printf ("|Kesabaran pelanggan yang antri: 30 tick           |\n");
	printf ("|Kesabaran pelanggan yang duduk: 60-75 tick        |\n");
	printf ("|Jika kesabaran habis, nyawa kamu berkurang 1      |\n");
	printf ("|Kamu dinyatakan kalah jika nyawa kamu habis       |\n");
	printf ("|P menandakan pemain                               |\n");
	printf ("|C artinya kursi belum ditempati                   |\n");
	printf ("|X artinya kursi telah diduduki                    |\n");
	printf ("|M menandakan meja bahan                           |\n");
	printf ("|T menandakan meja tray                            |\n");
	printf ("|Lokasi meja bahan dapat diakses di file .txt      |\n");
	printf ("|Di ruang 4; 0,1,2 menandakan meja 10, 11, 12      |\n");
	printf ("+--------------------------------------------------+\n");
}

void GameOver ()
{
	printf ("+--------------------------------------------------+\n");
	printf ("|                    GAME OVER                     |\n");
	printf ("+--------------------------------------------------+\n");
}

void Credit ()
{
	printf ("+--------------------------------------------------+\n");
	printf ("|Game ini dibuat oleh AL, FIO, DANDI, KEKA, WANUL. |\n");
	printf ("|10117113 - Keka                                   |\n");
	printf ("|10215065 - Al                                     |\n");
	printf ("|10216036 - Fio                                    |\n");
	printf ("|10216079 - Wanul                                  |\n");
	printf ("|13517077 - Dandi                                  |\n");
	printf ("|Terima kasih telah bermain.                       |\n");
	printf ("+--------------------------------------------------+\n");
}