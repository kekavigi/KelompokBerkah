#include "pesanan.h"
#include "duduk.h"

boolean IsEmpty (Pesanan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return(Neff(T) == 0);
}

int NbElmt (Pesanan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  if (IsEmpty(T))
    return 0;
  else
    return(Neff(T));
}
void AddElmtP(Pesanan * T, ElType X, int N){
	Neff(*T)=Neff(*T)+1;
	Elmt(*T, Neff(*T)) = X;
	Number(*T,Neff(*T))=N;
	
}

IdxType SearchIdxP (Pesanan T, ElType X, int N){
	IdxType i;
	if (IsEmpty(T))
		return IdxUndef;
	else {
		for (i=1; (i<=NbElmt(T)) && (Elmt(T,i)!=X) && (Number(T,i)!=N); i++){
			if ((Elmt(T,i)==X) && (Number(T,i)==N)){
				return i;		
			}
		}
	}
}

void DelElmtP(Pesanan * T, ElType X, int N){
	IdxType i;

	if (SearchIdxP(*T,X,N) != IdxUndef)
		for (i=SearchIdxP(*T,X,N); i<NbElmt(*T); i++)
			Elmt(*T,i) = Elmt(*T,i+1);
	Neff(*T)--;
}

int NbElmtP (Pesanan T){
	return Neff(T);
}

void delPesanan(Pesanan *DaftarPesanan,ElType pesanan,int N){
	//Menghapus pesanan dari daftar pesanan, pesanan pasti ada di daftar pesanan
	DelElmtP(DaftarPesanan,pesanan,N);
}
		

void addPesanan(Pesanan *DaftarPesanan, ElType pesanan, int N ){
	//Menambah pesanan ke daftar pesanan
	AddElmtP(DaftarPesanan,pesanan,N);
}

//boolean cekPesananMeja(Pesanan DaftarPesanan, int P,int N){
//	return (Elmt(DaftarPesanan,Number(DaftarPesanan))==P)&&(Number(DaftarPesanan)==N);
//}
