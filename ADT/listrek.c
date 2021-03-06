#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>


/* *** Manajemen Memori *** */
address Alokasi (infotype X){
	address P;

	/* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
	if(L==Nil){
		return 1;
	} else {
		return 0;
	}
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(List L){
	if (L != Nil) {
		if (Next(L) == Nil) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotype FirstElmt (List L){
	return Info(L);
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail(List L){
	return Next(L);
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(infotype e, List L){
	address P;
	P=Alokasi(e);
	if(P==Nil){
		return L;
	} else {
		Next(P)=L;
		L=P;
		return P;
	}
	
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List KonsB(List L, infotype e){
	address P,Last;
	P=Alokasi(e);
	if(P==Nil){
		return L;
	} else {
		if(IsEmpty(L)){
			return P;
		} else {
			Last=L;
			while(Next(Last)!=Nil){
				Last=Next(Last);
			}
			Next(Last)=P;
			return L;
			
		}

	}
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* *** Operasi Lain *** */
List Copy (List L){
	if (IsEmpty(L)) { /* Basis - 0 */
		return Nil;
	} else { /* Rekurens */
		return Konso(Info(L),Copy(Tail(L)));
	}	
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
void MCopy (List Lin, List *Lout){
	*Lout=Copy(Lin);
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
List Concat (List L1, List L2){
	if(IsEmpty(L1)&&IsEmpty(L2)){
		return Nil;
	} else if (IsEmpty(L1)){
		return Copy(L2);
	} else if( IsEmpty(L2)){
		return Copy(L1);
	}
	else {
		return Konso(FirstElmt(L1),Concat(Tail(L1),L2));
	}
	
}
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcat (List L1, List L2, List *LHsl){
	*LHsl=Concat(L1,L2);
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (List L){
	if (!IsEmpty(L)){	
		printf("%d\n",Info(L));
		PrintList(Next(L));
	}
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList (List L){
	if (IsEmpty(L)){
		return 0;
	}
	else{
		return 1 + NbElmtList(Next(L));
	}
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, infotype X){
	if (IsEmpty(L)){
		return false;	
	} 
	else /* Rekurens */
	{
		if (Info(L) == X){
			return true;	
		} else{
			return Search(Next(L),X);
		}  
	}	
}
/* Mengirim true jika X adalah anggota list, false jika tidak */
