# Kelompok Berkah
memudahkan ngegabung mungkin bisa tulis ulang file .h disini secara ringkas, gini:

### define
apa aja yang didefine

### adt
* adt
	* komponennya

### sisanya
* void aaa
* int bbb
* dst

------------
# Peta

### define
* UBIN '_'
* KKOSONG 'C'
* KPENUH 'X'
* MEJA 'M'

### adt
*PETA
	* char_map

### sisanya
* void MakePETA(PETA *peta, char *namafile, POINT spawn);
* POINT FindMeja(MATRIKS M, POINT P);
* int CountObjek(MATRIKS M, POINT P, char objek);
* void IsiKursiKosong(MATRIKS *M, POINT P, int minta);
* void JadikanKursiKosong(MATRIKS *M, POINT P);
* void UpdatePosisiPlayer(MATRIKS*M, POINT P);
* void TulisPETA(PETA peta);
* void GantiPeta(MATRIKS *M, int move);

------------
# POINT

### define
* Absis(P) (P).X
* Ordinat(P) (P).Y

### adt
* POINT
	* int X; /* absis   */
	* int Y; /* ordinat */


### sisanya
* POINT MakePOINT (int X, int Y);
* void BacaPOINT (POINT * P); 
* void TulisPOINT (POINT P);
* boolean EQ (POINT P1, POINT P2);
* boolean IsOrigin (POINT P);
* boolean IsOnSbX (POINT P);
* boolean IsOnSbY (POINT P);
* boolean IsDinding (POINT P);
* boolean IsVal(POINT P);
* POINT UP (POINT P);
* POINT DOWN (POINT P);
* POINT LEFT (POINT P);
* POINT RIGHT (POINT P);
