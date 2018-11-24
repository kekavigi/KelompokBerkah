/* ADT UNTUK PENCARIAN MEJA DAN LAIN-LAIN */

#ifndef seeker_H
#define seeker_H

#include "boolean.h"
#include "player.h"
#include "move.h"
#include "point.h"

void IsKursiMejaAda(PLAYER P, int CURRENT_ROOM, int *BENDA, POINT *PBENDA);
// Prosedur untuk memeriksa apakah di sekitar player ada meja, meja racik, kursi, meja tray.
/* 
0 = TIDAK ADA APA
1 = ADA KURSI
2 = ADA MEJA
3 = ADA MEJA TRAY

*/

void CariMeja(POINT P, int BENDA, int CURRENT_ROOM, POINT *PMEJA, int *NOMOR_MEJA, int *KMEJA); // HANYA DIPAKAI KETIKA INT BENDA = 2
// PROSEDUR UNTUK MENCARI POSISI MEJA

int CekNomorMeja(POINT P, int CURRENT_ROOM);
// Mengirimkan nomor meja di point P

int HitungKursi(int NOMOR_MEJA);
// Nomor meja menentukan berapa kursi yang tersedia di meja tersebut.


int CekMejaRacik(POINT P); // HANYA DIPAKAI KETIKA INT BENDA = 2
// Akan mengirimkan bahan yang tersedia
/*	
	"Piring", //1
    "Sendok", //2
    "Garpu", //3
	"Es Krim", //4
	"Nasi", //5
	"Roti", //6
	"Spaghetti", //7
	"Pisang", //8
	"Stroberi", //9
	"Telur", //10
	"Ayam Goreng", //11
	"Patty", //12
	"Sosis", //13
	"Bolognese", //14
	"Carbonara", //15
	"Keju", //16
	"Banana Split", //17
    "Sundae", //18
    "Nasi Telur Dadar", //19
	"Nasi Ayam Goreng", //20
	"Burger", //21
	"Hot Dog", //22
	"Spaghetti Bolognese", //23
	"Spaghetti Carbonara" //24

*/

boolean CekMejaTray(POINT P);
// Mengecek apakah ada meja tray di sekitar player



#endif