#include "boolean.h"

#define Nil 0
#define MaxEl 10

typedef char infotype;
typedef int address; 

 typedef struct { 
	infotype T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} Hand;

#define Top(H) (H).TOP
#define InfoTop(H) (H).T[(H).TOP]

boolean IsEmptyHand(Hand H);
boolean IsFullHand (Hand H);
void CreateEmptyHand (Hand *H);
void PopHand (Hand * H, infotype* X);
void PushHand (Hand * H, infotype X);
void CH(Hand *Tangan);
void TAKE(Hand *Tangan,infotype bahan);
