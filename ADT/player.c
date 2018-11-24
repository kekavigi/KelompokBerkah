/*
ADT PLAYER Untuk TUBES
dibuat oleh Fio
tanggal 18/11/2018
revisi 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "player.h"

void START_PLAYER(PLAYER *P){
// Buat mengeset awal game, Health Player 3, Money 0. Posisi di (4,1)

	Health(*P) = 3;
	Money(*P)=0;
	PX(*P) = 3;
	PY(*P)= 1;
}

boolean HEALTH_CUKUP(PLAYER P){
// Menghasilkan true jika masih bisa main (nyawa tidak 0)

	return Health(P) != 0;
}

void UPDATE_MONEY(PLAYER *P, int X){
// Memperbarui keuangan player (misal pesanan berhasil). X adalah harga makanan

	Money(*P) = Money(*P) + X;
}

void UPDATE_POSISI(PLAYER *P, int X){
// Memperbarui posisi player, keterangan [1 = Go UP, 2 = Go Down, 3 = Go Left, 4 = Go Right]

	if(X == 1){
		Posisi(*P) = UP(Posisi(*P));
	}else if (X == 2){
		Posisi(*P) = DOWN(Posisi(*P));
	}else if (X == 3){
		Posisi(*P) = LEFT(Posisi(*P));
	}else if (X == 4){
		Posisi(*P) = RIGHT(Posisi(*P));
	}

}

void UPDATE_LIFE(PLAYER *P){
// Mengurangi Life player (Health dikurangi 1 karena ada pelanggan yang meninggalkan restoran atau antrian)

	Health(*P) = Health(*P)-1;
}
