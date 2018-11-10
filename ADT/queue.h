/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H

#include "boolean.h"

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef int time;
typedef int jumlah;
typedef int waiting;
typedef int kesabaran;
typedef int addressQ;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { time * T;   
				 jumlah * J;
				 waiting * W;
				 kesabaran * K;
                 addressQ HEAD;  /* alamat penghapusan */
                 addressQ TAIL;  /* alamat penambahan */
                 int MaxElQ;     /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=NilS; TAIL=NilS. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define timeHead(Q) (Q).T[(Q).HEAD]
#define jumlahHead(Q) (Q).J[(Q).HEAD]
#define waitingHead(Q) (Q).W[(Q).HEAD]
#define kesabaranHead(Q) (Q).K[(Q).HEAD]
#define timeTail(Q) (Q).T[(Q).TAIL]
#define jumlahTail(Q) (Q).J[(Q).TAIL]
#define waitingTail(Q) (Q).W[(Q).TAIL]
#define kesabaranTail(Q) (Q).K[(Q).TAIL]
#define MaxElQ(Q) (Q).MaxElQ

/* ********* Prototype ********* */
int NBElmtQueue (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

boolean IsEmptyQueue (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DealokasiQueue(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, time T, jumlah J, waiting W, kesabaran K);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelQueue (Queue * Q, addressQ * P, time * T,jumlah * J, waiting * W, kesabaran * K);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void PrintQueue(Queue Q);
/* I.S. Q sembarang */
/* Isi queue dicetak ke layar */
/* mendelete elemen sampai habis dan menuliskan semuanya ke layar */

addressQ Search(Queue Q, int jumlah);

Queue DeleteP(Queue Q, addressQ P);

#endif
