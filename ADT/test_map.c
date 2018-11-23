#include "peta.h"
#include <string.h>
#include <stdio.h>

PETA Ruang1, Ruang2, Ruang3, Ruang4;

int main(){

	MakePETA(&Ruang1, "ruang1", MakePOINT(2,2));
	TulisPETA(Ruang1);
}
