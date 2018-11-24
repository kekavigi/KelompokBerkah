/* 
ADT PLAYER Untuk TUBES
dibuat oleh Fio
tanggal 18/11/2018
revisi 1
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "point.h"

typedef struct { 
	int Life; /* Nyawa Player   */
	int Money; /* Uang Player */
	POINT Posisi; /* Posisi Player */ 
} PLAYER;

/* *** Notasi Akses: Selektor PLAYER *** */
#define Health(P) (P).Life
#define Money(P) (P).Money
#define Posisi(P) (P).Posisi
#define PX(P) Absis((P).Posisi)
#define PY(P) Ordinat((P).Posisi)

void START_PLAYER(PLAYER *P);
// Buat mengeset awal game, Health Player 3, Money 0. Posisi di (4,1)

boolean HEALTH_CUKUP(PLAYER P);
// Menghasilkan true jika masih bisa main (nyawa tidak 0)

void UPDATE_MONEY(PLAYER *P, int X);
// Memperbarui keuangan player (misal pesanan berhasil). X adalah harga makanan

void UPDATE_POSISI(PLAYER *P, int X);
// Memperbarui posisi player, keterangan [1 = Go UP, 2 = Go Down, 3 = Go Left, 4 = Go Right]

void UPDATE_LIFE(PLAYER *P);
// Mengurangi Life player (Health dikurangi 1 karena ada pelanggan yang meninggalkan restoran atau antrian)

#endif

