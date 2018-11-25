#include "bintree.h"
#include "mesinkar.h"
#include "stackt.h"
#include "dataresep.h"
int main(){
	BinTree T;
	int i,N;
	printf("Membuat pohon bintree\n");
	printf("Masukkan jumlah simpul yg akan dibentuk = ");
	scanf("%d",&N);
	printf("Masukkan kode bahan yg akan dijadikan tree\n");
	T=BuildBalanceTree(N);
	ShowBranch(T);
}
