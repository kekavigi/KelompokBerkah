#include "stack.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
	Neff(*T) == 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
	return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
	return IdxMax;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
	return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxType GetLastIdx (TabInt T){
	return IdxMax;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	return Neff(T)==0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean IsFull (TabInt T){
	return Neff(T)==IdxMax;
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** TULIS ISI TABEL ********** */
void TulisArray (TabInt T){
	IdxType i;
	
	printf("[");
	if (!IsEmpty(T)){
		for (i=1; i<NbElmt(T); i++)
			printf("%d,", Elmt(T,i));
		printf("%d", Elmt(T,i));
	};
	printf("]");
}
/* Proses : belum jelas */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
boolean Search (TabInt T, ElType X){
	IdxType i;
	if (IsEmpty(T))
		return false;
	else {
		for (i=1; (i<=NbElmt(T)) && (Elmt(T,i)!=X); i++);
		return Elmt(T,i)==X;
	};
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */

ElType SearchIdx (TabInt T, ElType X){
	IdxType i;
	if (IsEmpty(T))
		return IdxUndef;
	else {
		for (i=1; (i<=NbElmt(T)) && (Elmt(T,i)!=X); i++);
		if (Elmt(T,i)==X) return i;
	};
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan index elemen X, jika tidak ada menghasilkan IdxUndef */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddElmt (TabInt * T, ElType X){
	Elmt(*T, Neff(*T)++) == X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void DelElmt(TabInt * T, ElType X){
	IdxType i;

	if (SearchIdx(*T,X) != IdxUndef)
		for (i=SearchIdx(*T,X); i<NbElmt(*T); i++)
			Elmt(T,i) = Elmt(T,i+1);
	Neff(T)--;
}
/* Proses : Menghapus elemen pertama di tabel dengan ElType X*/
/* I.S. Tabel tidak kosong */
/* F.S. Jika X ada, banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong. */

void DelLastElmt (TabInt * T, ElType * X){
	Elmt(*T, --Neff(*T)) == X;
}
/* Proses : Menghapus sebuah elemen terakhir di tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

#endif
