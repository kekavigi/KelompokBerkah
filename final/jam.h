/* 
ADT JAM Untuk TUBES
dibuat oleh Fio
tanggal 18/11/2018
revisi 1
*/

#ifndef JAM_H
#define JAM_H

#include "boolean.h"

/* *** Definisi TYPE JAM  *** */
typedef int JAM;

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

void START_JAM (JAM *J);
// Mengeset JAM jadi 0, untuk awal permainan

void J_ANTRI (JAM *J);
// Mengatur jam kesabaran antri dari pelanggan (FIX 30)

void J_DUDUK (JAM *J);
// Mengatur jam kesabaran saat pelanggan sudah duduk (50 - 70)

boolean JAM_HABIS (JAM J);
// Menghasilkan true jika waktu 0, buat mengecek kesabaran pelanggan

void JADV (JAM *J);
// Memajukan 1 satuan waktu J

void JREW (JAM *J);
// Memundurkan 1 satuan waktu J


#endif