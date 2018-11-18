/* 
NIM/Nama : 10216038/MUHAMMAD ISRO FIORDI
Nama file : jam.c
Topik : ADT Praktikum 1
Tanggal : 5/09/2018
Deskripsi : Realisasi ADT dari jam.h
*/

#include "jam.h"
#include <stdio.h>
#include <stdlib.h>

void START_JAM (JAM *J){
// Mengeset JAM jadi 0, untuk awal permainan

	*J = 0;
}

JAM J_ANTRI (JAM *J){
// Mengatur jam kesabaran antri dari pelanggan (FIX 30)

	*J = 30;
}

JAM J_DUDUK (JAM *J){
// Mengatur jam kesabaran saat pelanggan sudah duduk (50 - 70)

	*J = (rand()%21)+50;
}

boolean JAM_HABIS (JAM J){
// Menghasilkan true jika waktu 0, buat mengecek kesabaran pelanggan

	return J == 0;
}

void JADV (JAM *J){
// Memajukan 1 satuan waktu J

	*J = *J + 1;
}

void JREW (JAM *J){
// Memundurkan 1 satuan waktu J

	*J = *J - 1;
}