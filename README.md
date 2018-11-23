# Kelompok Berkah

#CumaBiarNggaGilaSendiri

---------------------------------------------------------------

* ADT POINT
	* int X
	* int Y

POINT 	MakePOINT (int X, int Y);
void 	BacaPOINT (POINT * P); 
void 	TulisPOINT (POINT P);
boolean EQ (POINT P1, POINT P2);
boolean IsOrigin (POINT P);
boolean IsOnSbX (POINT P);
boolean IsOnSbY (POINT P);
boolean IsDinding (POINT P);
boolean IsVal(POINT P);
POINT 	UP (POINT P);
POINT 	DOWN (POINT P);
POINT 	LEFT (POINT P);
POINT 	RIGHT (POINT P);
----------------------------------------------------------------

* ADT MATRIKS
	* int Mem[1+8][1+8]		<- matriksnya
	* int NXeff
	* int NYEff

void	MakeMATRIKS (MATRIKS * M, int X, int Y);
void	BacaFileMATRIKS (MATRIKS *M, char *namafile);
void	TulisMATRIKS (MATRIKS M);	

----------------------------------------------------------------

* ADT PETA
	* MATRIKS char_map		<- isinya karakter
	* MATRIKS value_map		<- isinya angka, dipakai kalau mau
	* POINT pos				<- posisi player

void 	MakePETA(PETA *peta, char *namafile)
POINT	FindMeja(MATRIKS M, POINT P)
int		CountObjek(MATRIKS M, POINT P, char objek)
void 	IsiKursiKosong(MATRIKS *M, POINT P, int minta)
void	JadikanKursiKosong(MATRIKS *M, POINT P)
void	UpdatePosisiPlayer(MATRIKS*M, POINT P)
void	TulisPETA(PETA peta)
void	GantiPeta(MATRIKS *M, int move)

