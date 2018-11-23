#include "peta.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	MATRIKS r1, r2, r3, r4;

	MakeMATRIKS(1,&r1);
	MakeMATRIKS(2,&r2);
	MakeMATRIKS(3,&r3);
	MakeMATRIKS(4,&r4);

	BacaMATRIKS(&r1);
	BacaMATRIKS(&r2);
	BacaMATRIKS(&r3);
	BacaMATRIKS(&r4);


	TulisMATRIKS(r1);


	return 0;
}
