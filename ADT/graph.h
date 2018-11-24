#ifndef GRAPH_H
#define GRAPH_H

#include "matriks.h"

#define MatGraf(graf) (graf).tetangga
#define ValGraf(graf, asal, tujuan) ElmtMat(MatGraf(graf), MakePOINT(asal, tujuan))-'0'
#define RumAktif(graf) (graf).aktif

typedef struct {
	MATRIKS tetangga;   /* berisi ketetanggaan tiap peta */
	int aktif;					/* berisi keterangan room yang aktif */
} GRAPH;

void MakeGRAPH(GRAPH *graf, int room_inisial);
// membentuk sebuah graf ketetanggaan dari namafile, dengan room yang aktif adalah room_inisial

void Teleport(GRAPH *graf, int X);
// I.S : Player sudah ada dipintu, mengecek apakah gerakan X dapat mengubah room_inisial
// F.S : jika bisa mengubah room, room yang aktif berubah, jika tidak tidak ada yang terjadi
#endif
