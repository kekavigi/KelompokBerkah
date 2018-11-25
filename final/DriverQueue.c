#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	Queue Q;
	int j,k,p;
	CreateEmptyQueue(&Q,100);
	printf("Masukkan jumlah orang = 0 jika ingin berhenti\n");
    do{
        printf("jumlah orang dalam grup = " );
        scanf("%d",&j);
        printf("kesabaran = " );
        scanf("%d",&k);
        if(j!=0){
        	AddQueue(&Q,j,k);	
		}
        
        printf("antrian saat ini :\n");
        PrintQueue(Q);
    }while(j!=0);

	printf("Banyak antrian saat ini = ");
	printf("%d\n",NBElmtQueue(Q));	
	printf("masukkan urutan pengunjung yang ingin dihapus : ");
	scanf("%d", &p);
	Q=DeleteP(Q,p);
    printf("antrian saat ini :\n");
    PrintQueue(Q);
}
