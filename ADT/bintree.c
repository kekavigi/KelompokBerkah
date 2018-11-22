#include "bintree.h"
#include "listrek.c"
#include <stdlib.h>
#include <stdio.h>


BinTree Tree(infotype Akar, BinTree L, BinTree R){
	addrNode P;
	P= AlokNode(Akar);
  if(P!=Nil){
    Akar(P) = Akar;
    Left(P) = L;
    Right(P) = R;
  }
  return P;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
	*P = Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
BinTree BuildBalanceTree(int n){
	BinTree P;
	BinTree L,R;
	infotype X;
	int nl,nr;
	if(n==0){
		return Nil;
	}else{
		scanf("%d",&X);
		P=AlokNode(X);
		if(P!=Nil){
			if(nl%2==0){
				nl=nl/2;
			}else{
				nl=nl-1;
				nl=nl/2;
			}
			nr=n-nl-1;
			L=BuildBalanceTree(nl);
			R=BuildBalanceTree(nr);
			Left(P)=L;
			Right(P)=R;
		}
	}
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
  addrNode P;
  P=(addrNode) malloc(sizeof(infotype));
  if(P!=Nil){
    Akar(P)=X;
    Left(P)=Nil;
    Right(P)=Nil;
  }
  return P;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
	return P == Nil;
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
	return P!=Nil && Left(P)==Nil && Right(P)==Nil;
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
	return P!=Nil && Left(P)!=Nil && Right(P)==Nil; 
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
	return P!=Nil && Left(P)==Nil && Right(P)!=Nil; 
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
	return P!=Nil && Left(P)!=Nil && Right(P)!=Nil; 
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)){
    printf("%d",Akar(P));
    PrintPreorder(Left(P));
    PrintPreorder(Right(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)){
    PrintInorder(Left(P));
    printf("%d",Akar(P));
    PrintInorder(Right(P));
  }
  printf(")");
}

/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
  printf("(");
  if (!IsTreeEmpty(P)){
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%d",Akar(P));
  }
  printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTreeRecc(BinTree P, int l, int h) {
  if (!IsTreeEmpty(P)) {
    int i;
    for (i = 0; i < l*h; i++){
      printf(" ");
    }
    printf("%d\n", Akar(P));
    PrintTreeRecc(Left(P), l+1, h);
    PrintTreeRecc(Right(P), l+1, h);
  }
}
void PrintTree(BinTree P, int h){
	PrintTreeRecc(P, 0, h);
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
  if(IsTreeEmpty(P)){
    return false;
  }
  if(Akar(P)==X){
    return true;
  } else {
    return SearchTree(Left(P),X) || SearchTree(Right(P),X);
  }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
  if(IsTreeEmpty(P)){
    return 0;
  } else {
    return 1+NbElmt(Left(P))+NbElmt(Right(P));
  }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
  if(IsTreeEmpty(P)){
    return 0;
  } else if (IsTreeOneElmt(P)){
    return 1;
  } else {
    return NbDaun(Left(P))+NbDaun(Right(P));
  }
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
  if (IsTreeEmpty(P)) {
    return true;
  } else {
    return Right(P)==Nil && IsSkewLeft(Left(P));
  }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
	if (IsTreeEmpty(P)) {
		return true;
	} else {
    	return Left(P)==Nil && IsSkewRight(Right(P));
    }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X){
  if(Akar(P)==X){
    return 1;
  } else if(SearchTree(Left(P),X)){
  
  	return 1+Level(Left(P),X);
  } else {
  	return Level(Right(P),X)+1;
  }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
  if (IsTreeEmpty(P)){
    return 0;
  } else {
    return 1+(Tinggi(Left(P))>Tinggi(Right(P))?Tinggi(Left(P)):Tinggi(Right(P)));
  }
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){
  if(IsTreeEmpty(*P)){
    *P=Tree(X,Nil,Nil);
  } else {
    AddDaunTerkiri(&Left(*P),X);
  }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
  if(Akar(*P)==X && IsTreeOneElmt(*P)){
    if(Kiri){
      Left(*P)=Tree(Y,Nil,Nil);
    } else {
      Right(*P)=Tree(Y,Nil,Nil);
    }
  } else {
    if(SearchTree(Left(*P),X)){
      AddDaun(&Left(*P),X,Y,Kiri);
    } else {
      AddDaun(&Right(*P),X,Y,Kiri);
    }
  }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X){
  if(IsTreeOneElmt(*P)){
    *X=Akar(*P);
    DealokNode(*P);
    *P=Nil;
  } else {
    if(Left(*P)!=Nil){
      DelDaunTerkiri(&Left(*P),X);
    } else {
      DelDaunTerkiri(&Right(*P),X);
    }
  }
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X){
  if(Akar(*P)==X && IsTreeOneElmt(*P)){
    DealokNode(*P);
    *P=Nil;
  }
  if (!IsTreeEmpty(*P)){
    if(SearchTree(Left(*P),X)){
      DelDaun(&Left(*P),X);
    }
    if(SearchTree(Right(*P),X)){
      DelDaun(&Right(*P),X);
    }
  }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
List MakeListDaun(BinTree P){
  if(IsTreeEmpty(P)){
    return Nil;
  } else if(IsTreeOneElmt(P)){
    return Alokasi(Akar(P));
  } else {
    return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
  }	
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P){
  if(IsTreeEmpty(P)){
    return Nil;
  } else {
    Konso(Akar(P),Concat(MakeListPreorder(Left(P)),MakeListPreorder(Right(P))));
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListLevel(BinTree P, int N){
  if(IsTreeEmpty(P)){
    return Nil;
  } else {
    if(N==1){
      return Konso(Akar(P),MakeListLevel(Left(P),N-1));
      return Konso(Akar(P),MakeListLevel(Right(P),N-1));
    } else {
      return Concat(MakeListLevel(Left(P),N-1),MakeListLevel(Right(P),N-1));
    }
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X){
	if(Akar(P)==X){
		return true;
	}else if( Akar(P)>X){
		return BSearch(Right(P),X);
	}else {
		return BSearch(Left(P),X);
	}
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X)

{
	if(IsTreeEmpty(*P)){
		MakeTree(X,Nil,Nil,P);
	}else if(Akar(*P)<Akar(Right(*P))){
		InsSearch(&Left(*P),X);
	}else {
		InsSearch(&Right(*P),X);
	}
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

void DelBtree(BinTree *P, infotype X){
	if(Akar(*P)==X){
		DealokNode(*P);
    	*P=Nil;
	}else if(Akar(*P)<Akar(Right(*P))){
		DelBtree(&Left(*P),X);
	}else {
		DelBtree(&Right(*P),X);
	}
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
