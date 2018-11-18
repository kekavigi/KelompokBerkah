#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

typedef char ElType; /* type indeks */
typedef int IdxType;  /* type elemen tabel */

typedef struct { 
	ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Number; /* >=0, banyaknya elemen efektif */
	int Neff;
} Pesanan; 

#define Neff(T)   (T).Neff
#define Number(T)   (T).Number
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]
int NbElmtP (Pesanan T);

IdxType SearchIdxP (Pesanan T, ElType X);

void delPesanan(Pesanan *DaftarPesanan,ElType pesanan);

void DelElmtP(Pesanan * T, ElType X);

void AddElmtP(Pesanan * T, ElType X);

void addPesanan(ElType pesanan,Pesanan *DaftarPesanan);
