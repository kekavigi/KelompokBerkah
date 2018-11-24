#include "pesanan.h"

void AddElmtP(Pesanan * T, ElType X){
	Elmt(*T, Neff(*T)++) = X;
}

IdxType SearchIdxP (Pesanan T, ElType X){
	IdxType i;
	if (IsEmpty(T))
		return IdxUndef;
	else {
		for (i=1; (i<=NbElmt(T)) && (Elmt(T,i)!=X); i++);
		if (Elmt(T,i)==X) return i;
	};
}

void DelElmtP(Pesanan * T, ElType X){
	IdxType i;

	if (SearchIdxP(*T,X) != IdxUndef)
		for (i=SearchIdxP(*T,X); i<NbElmt(*T); i++)
			Elmt(T,i) = Elmt(T,i+1);
	Neff(*T)--;
}

int NbElmtP (Pesanan T){
	return Neff(T);
}

void delPesanan(Pesanan *DaftarPesanan,ElType pesanan){
	//Menghapus pesanan dari daftar pesanan, pesanan pasti ada di daftar pesanan
		DelElmtP(DaftarPesanan,&pesanan);
	}
		
}

void addPesanan(ElType pesanan,Pesanan *DaftarPesanan){
	//Menambah pesanan ke daftar pesanan
	AddElmtP(DaftarPesanan,pesanan);
}
