#include "peta.h"
#include <string.h>
#include <stdio.h>

int main(){
	PETA Ruang1, Ruang2, Ruang3, Ruang4;

	MakePETA(&Ruang1, "ruang1", MakePOINT(2,2));
	TulisPETA(Ruang1);
}
