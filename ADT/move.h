#ifndef MOVE_H
#define MOVE_H

#include "boolean.h"
#include "point.h"
#include "player.h"

void UPDATE_POSISI_PLAYER(PLAYER *P, int X, int *room);
/* MEMPERBAHARUI POSISI PLAYER DALAM GAME */

boolean IsDinding1 (POINT P);
/* Menghasilkan true jika P terletak di luar dinding (yang pasti lebih dari. Boundary X 1-8, Boundary Y 1-8) */

boolean IsMejaKursi(POINT P, int room);
/* Menghasilkan true jika posisi P adalah Kursi atau meja. Masih perlu kolaborasi sama ADT MATRIKS */

boolean IsPintu(POINT P, int room_sekarang);
/* Menghasilkan true jika di posisi P adalah Pintu. Masih perlu kolaborasi sama ADT MATRIKS */

boolean IsMove(POINT P, int room);
/* Menghasilkan True jika titik berada di map (bukan 0,Y. Bukan di X,0. Bukan di Border Map (dinding) dan gak ketabrak meja dan kursi) */

void UP1 (POINT *P, int *room_sekarang);
/* Mengirim salinan P dengan ordinat ditambah satu */

void DOWN1 (POINT *P, int *room_sekarang);
/* Mengirim salinan P dengan ordinat dikurang satu */

void LEFT1 (POINT *P, int *room_sekarang);
/* Mengirim salinan P dengan absis dikurang satu  */

void RIGHT1 (POINT *P, int *room_sekarang);
/* Mengirim salinan P dengan absis ditambah satu  */

#endif