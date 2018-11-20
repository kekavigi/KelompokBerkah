#include "matriks.h"
#include <stdio.h>

int main(){
	MATRIKS M;
	
	MakeMATRIKS(5,5, &M);
	
	printf("ok\n");
	
	BacaMATRIKS(&M);
	TulisMATRIKS(M);
	
	return 0;
}
