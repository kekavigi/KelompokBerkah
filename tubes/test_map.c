#include "peta.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	MATRIKS M, N;
	
	MakeMATRIKS(1,&M);

	Elmt(M,MakePOINT(1,1)) = '_';
	Elmt(M,MakePOINT(1,2)) = '_';
	Elmt(M,MakePOINT(1,3)) = '_';
	Elmt(M,MakePOINT(1,4)) = '_';
	Elmt(M,MakePOINT(1,5)) = '_';
	Elmt(M,MakePOINT(1,6)) = '_';
	Elmt(M,MakePOINT(1,7)) = '_';
	Elmt(M,MakePOINT(1,8)) = '_';

	Elmt(M,MakePOINT(2,1)) = '_';
	Elmt(M,MakePOINT(2,2)) = '_';
	Elmt(M,MakePOINT(2,3)) = '_';
	Elmt(M,MakePOINT(2,4)) = '_';
	Elmt(M,MakePOINT(2,5)) = '_';
	Elmt(M,MakePOINT(2,6)) = '_';
	Elmt(M,MakePOINT(2,7)) = '_';
	Elmt(M,MakePOINT(2,8)) = '_';

	Elmt(M,MakePOINT(3,1)) = '_';
	Elmt(M,MakePOINT(3,2)) = '_';
	Elmt(M,MakePOINT(3,3)) = '_';
	Elmt(M,MakePOINT(3,4)) = '_';
	Elmt(M,MakePOINT(3,5)) = '_';
	Elmt(M,MakePOINT(3,6)) = '_';
	Elmt(M,MakePOINT(3,7)) = '_';
	Elmt(M,MakePOINT(3,8)) = '_';

	Elmt(M,MakePOINT(4,1)) = '_';
	Elmt(M,MakePOINT(4,2)) = '_';
	Elmt(M,MakePOINT(4,3)) = '_';
	Elmt(M,MakePOINT(4,4)) = '_';
	Elmt(M,MakePOINT(4,5)) = '_';
	Elmt(M,MakePOINT(4,6)) = '_';
	Elmt(M,MakePOINT(4,7)) = '_';
	Elmt(M,MakePOINT(4,8)) = '_';
	
	Elmt(M,MakePOINT(5,1)) = '_';
	Elmt(M,MakePOINT(5,2)) = '_';
	Elmt(M,MakePOINT(5,3)) = '_';
	Elmt(M,MakePOINT(5,4)) = '_';
	Elmt(M,MakePOINT(5,5)) = '_';
	Elmt(M,MakePOINT(5,6)) = '_';
	Elmt(M,MakePOINT(5,7)) = '_';
	Elmt(M,MakePOINT(5,8)) = '_';
	
	Elmt(M,MakePOINT(6,1)) = '_';
	Elmt(M,MakePOINT(6,2)) = '_';
	Elmt(M,MakePOINT(6,3)) = '_';
	Elmt(M,MakePOINT(6,4)) = '_';
	Elmt(M,MakePOINT(6,5)) = '_';
	Elmt(M,MakePOINT(6,6)) = '_';
	Elmt(M,MakePOINT(6,7)) = '_';
	Elmt(M,MakePOINT(6,8)) = '_';
	
	Elmt(M,MakePOINT(7,1)) = '_';
	Elmt(M,MakePOINT(7,2)) = '_';
	Elmt(M,MakePOINT(7,3)) = '_';
	Elmt(M,MakePOINT(7,4)) = '_';
	Elmt(M,MakePOINT(7,5)) = '_';
	Elmt(M,MakePOINT(7,6)) = '_';
	Elmt(M,MakePOINT(7,7)) = '_';
	Elmt(M,MakePOINT(7,8)) = '_';
	
	Elmt(M,MakePOINT(8,1)) = '_';
	Elmt(M,MakePOINT(8,2)) = '_';
	Elmt(M,MakePOINT(8,3)) = '_';
	Elmt(M,MakePOINT(8,4)) = '_';
	Elmt(M,MakePOINT(8,5)) = '_';
	Elmt(M,MakePOINT(8,6)) = '_';
	Elmt(M,MakePOINT(8,7)) = '_';
	Elmt(M,MakePOINT(8,8)) = '_';
	
	
	TulisMATRIKS(M);
	
	return 0;
}