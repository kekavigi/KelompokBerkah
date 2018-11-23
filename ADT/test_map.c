#include "peta.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	PETA Ruang1;

	MakePETA(&Ruang1, "ruang1", MakePOINT(4,4));
	TulisMATRIKS(CharMap(Ruang1));

	printf("%c", Elmt(CharMap(Ruang1), MakePOINT(1,1)));
	return 0;
}
