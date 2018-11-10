/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int ret;
    if ((Head(Q)==Nil)&&(Tail(Q)==Nil))
    {
        ret = 0;
    }
    else
    {
        ret = Tail(Q) - Head(Q) + 1;
        if (ret <= 0)
        {
            ret = ret + MaxElQ(Q);
        }
    }
    return ret;
}

boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmtQueue(Q) == MaxElQ(Q));
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */
{
    (*Q).T = (time *) malloc ((Max + 1) * sizeof(time));
    (*Q).W = (waiting *) malloc ((Max + 1) * sizeof(waiting));
    (*Q).K = (kesabaran *) malloc ((Max + 1) * sizeof(kesabaran));
    if (((*Q).T == NULL)||((*Q).W == NULL)||(*Q).K == NULL)
    {
        MaxElQ(*Q) = Nil;
    }
    else
    {
        MaxElQ(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}
/* *** Destruktor *** */
void DealokasiQueue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxElQ(*Q) = Nil;
    free((*Q).T);
    free((*Q).W);
	free((*Q).K);
	free((*Q).J);
}
/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, time T, jumlah J, waiting W, kesabaran K)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmptyQueue(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        timeHead(*Q) = T;
        jumlahHead(*Q) = J;
        waitingHead(*Q) = W;
        kesabaranHead(*Q) = K;
    }
    else
    {
        if (Tail(*Q) == MaxElQ(*Q))
        {
            Tail(*Q) = 1;
        }
        else
        {
            Tail(*Q)++;
        }
        timeTail(*Q) = T;
        jumlahHead(*Q) = J;
        waitingTail(*Q) = W;
        kesabaranTail(*Q) = K;
    }

}

void DelQueue (Queue * Q, addressQ * P, time * T, jumlah * J, waiting * W, kesabaran * K)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    Queue Qt;
    Qt = *Q;
	*T=timeHead(Qt);
	*J=jumlahHead(Qt);
	*W=waitingHead(Qt);
	*K=kesabaranHead(Qt);
	*P=Head(Qt);
	
    if (NBElmtQueue(Qt) == 1)
    {
        Head(Qt) = Nil;
        Tail(Qt) = Nil;
    }
    else
    {
        if (Head(Qt) == MaxElQ(Qt))
        {
            Head(Qt) = 1;
        }
        else
        {
            Head(Qt)++;
        }
    }
    *Q = Qt;
}

void PrintQueue(Queue Q)
/* I.S. Q sembarang */
/* Isi queue dicetak ke layar */
{	
	addressQ p;
    int t; int j; int w; int k; int i; 
    if(IsEmptyQueue(Q))
    {
		printf("_\n");
	}
    else
    {
		while (!IsEmptyQueue(Q))
		{
			DelQueue(&Q,&p,&t,&j,&w,&k);
			printf("%d\n",j);
		}
	}
}
addressQ Search(Queue Q, int jumlah)
{	
	int t,j,w,k;
	boolean found;
	addressQ P;
    if(IsEmptyQueue(Q))
    {
		return Nil;
	}
    else
    {	
    	found=false;
		while (!IsEmptyQueue(Q) && !found)
		{
			DelQueue(&Q,&P,&t,&j,&w,&k);
			if(j==jumlah){
				found=true;
			}
		}
		return P;
	}	
}


Queue DeleteP(Queue Q, addressQ P)
{
	Queue Qt;
	int t,j,w,k;
	addressQ p;
	while (!IsEmptyQueue(Q))
	{
		DelQueue(&Q,&p,&t,&j,&w,&k);
		if(p!=P){
			AddQueue(&Qt,t,j,w,k);
		}
	}	
}
