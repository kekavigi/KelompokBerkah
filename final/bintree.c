#include "bintree.h"
#include "mesinkar.h"
#include "stackt.h"
#include "dataresep.h"
#include "stackt.h"

void Allocate (paddress *P)
{
	*P =(paddress) malloc(sizeof(node));
}

BinTree Tree (int A, BinTree L, BinTree R)
{
	paddress P;
	Allocate (&P);
	if (P!=NilTree) {
		Akar(P) = A;
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}
void MakeTree (int Akar, BinTree L, BinTree R, BinTree *P)
{
	Allocate(P);
	if (*P!=NilTree) {
		Akar(*P)=Akar;
		Left(*P) = L;
		Right(*P) = R;
	} 
}

void LoadTree(BinTree *P)
{
	START("resep.txt");
	BuildTree(P);
}

void BuildTree (BinTree *P)
{

	char tanda[256];
	int i;

	ADV();
	if (CC==')')
		(*P)=NilTree;
	else {
		Allocate(P);
		for (i=0; i<256; i++)
			tanda[i] = 0;
		i = 0;
		while ((CC !='(')&&(CC != ')')) {
			tanda[i] = CC;
			ADV();
			i++;
		}
		Akar(*P) = atoi(tanda);
		BuildTree(&Left(*P));
		BuildTree(&Right(*P));
	}
	ADV();
}

boolean IsTreeEmpty (BinTree P)
{
	return (P==NilTree);
}

boolean IsOneElmt (BinTree P)
{
	return ((!IsTreeEmpty(P))&&(IsTreeEmpty(Left(P)))&&(IsTreeEmpty(Right(P))));
}

boolean IsUnerLeft (BinTree P)
{
	return ((Right(P) == NilTree) && (Left(P) != NilTree));
}

boolean IsUnerRight (BinTree P)
{
	return ((Right(P) != NilTree) && (Left(P) == NilTree));
}

boolean IsBiner (BinTree P)
{
	return ((Right(P) != NilTree) && (Left(P) != NilTree));
}

void PrintPreorder (BinTree P)
{
	if (P!=NilTree)  {
		printf("%d\n", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
}
void PrintInorder (BinTree P)
{
	if (P!=NilTree)  {
		PrintInorder(Left(P));
		printf("%d\n", Akar(P));
		PrintInorder(Right(P));
	}
}
void PrintPostorder (BinTree P)
{
	puts(bahan[Akar(P)]);
	if (P!=NilTree)  {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d\n", Akar(P));
	}
}

void ShowBranch (BinTree P)
{

	int Slash[100]; 
	int i;

	for( i = 0;i < 100; i++){
		Slash[i] = 0;
	}
		
	PrintTree (P, 5, 4,Slash);
}

void PrintBranch(int h)
{	int i;
	for ( i = 1; i < h; i++){
		printf(" ");
	}
}

void PrintTree (BinTree P, int inden1, int inden2, int * ArrSlash)
{
	int i,j,k;
	int subakar = inden2 + inden1/2;

	if (!IsTreeEmpty(P)) {
		if (Akar(P) == 1){
			printf("***RESEP MAKANAN*** \n");
		}
		
		puts(bahan[Akar(P)]);
		if (!IsTreeEmpty(Left(P))) {
			PrintBranch(subakar);
			i = 0;
			while ((ArrSlash[i] != 0) && (ArrSlash[i] != subakar)){
				i += 1;
			}
			if(ArrSlash[i] == 0){
				ArrSlash[i] = subakar;
			}
			printf("|");
			for ( j = 1; j < 2; j++){
				printf("-");
			} 
			printf(">");
			j = 1;
			PrintTree(Left(P), inden1, inden2+inden1, ArrSlash);
		}
		if (!IsTreeEmpty(Right(P))) {
			PrintBranch(subakar);
			i = 0;
			while ((ArrSlash[i] != 0) && (ArrSlash[i] != subakar)){
				i += 1;
			}
			if(ArrSlash[i] == 0){
				ArrSlash[i] = subakar;
			}
			printf("|");
			for (j = 1; j < 2; j++){
				printf("-");
			} 
			printf(">");
			j = 0;
			while (ArrSlash[j] != 0){
				if (ArrSlash[j] == subakar){
					ArrSlash[j] = -999;
				}
				j += 1;
			}	
			PrintTree(Right(P), inden1, inden2+inden1, ArrSlash);
		}
	}
}

boolean SearchPB (BinTree P, int X)
{
	if (IsTreeEmpty(P)) {
		return false;
	}
		if (X==Akar(P)) {
			return true;
		}
		else {
			return (SearchPB(Left(P), X) || SearchPB(Right(P), X));
		}
}


int NbElmtPB (BinTree P)
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return 1+NbElmtPB(Left(P))+NbElmtPB(Right(P));
	}
}

int NbDaun (BinTree P)
{
	if ((Left(P)==NilTree)&&(Right(P)==NilTree)) {
		return 1;
	}
	else {
		if ((Left(P)!=NilTree)&&(Right(P)==NilTree)) {
			return NbDaun(Left(P));
		}
		else if ((Left(P)==NilTree)&&(Right(P)!=NilTree)) {
			return NbDaun(Right(P));
		}
		else if ((Left(P)!=NilTree)&&(Right(P)!=NilTree)) {
			return NbDaun(Left(P))+NbDaun(Right(P));
		}
	}
}

boolean IsSkewLeft (BinTree P)
{
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerLeft(P)) {
				return IsSkewLeft(Left(P));
			}
			else {
				return false;
			}
		}
}

boolean IsSkewRight (BinTree P)
{
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerRight(P)) {
				return IsSkewRight(Right(P));
			}
			else {
				return false;
			}
		}
}

int Level (BinTree P, int X)
{
	if (X==Akar(P)){
		return 1;
	}
	else 
		if (SearchPB(Left(P), X)) {
			return 1+Level(Left(P), X);
		}
		else {
			return 1+Level(Right(P), X);
		}
}
void AddDaunTerkiri (BinTree *P, int X)
{
	paddress Pk;
	if (IsTreeEmpty(*P)) {
		printf("kosong\n");
		Allocate(P);
		if(P == NilTree) printf("kosong\n");
		Akar (*P) = X;
	}
	else {
		if (IsTreeEmpty(Left(*P))) {
			Allocate(&Pk);
			Left(*P) = Pk;
			Akar (Pk) = X;
		}
		else {
			AddDaunTerkiri(&Left(*P), X);
		}
	}
}

void AddDaun (BinTree *P, int X, int Y, boolean Kiri)
{
	paddress Pk;
	if (X==Akar(*P)) {
		Allocate(&Pk);
		Akar(Pk) = Y;
		if (Kiri) {
			Left(*P) = Pk;
		}
		else {
			Right(*P) = Pk;
		}
	}
	else {
		if (SearchPB(Left(*P), X)) {
			AddDaun(&Left(*P), X, Y, Kiri);
		}
		else {
			AddDaun(&Right(*P),X,Y,Kiri);
		}
	}
}

void DelDaunTerkiri (BinTree *P, int *X)
{
	if (Left(*P)==NilTree) {
		if (Right(*P)==NilTree) {
			(*X) = Akar(*P);
			(*P) = NilTree;
			free(*P);
		}
		else {
			DelDaunTerkiri(&Right(*P), X);
		}
	}
	else {
		DelDaunTerkiri(&Left(*P), X);
	}
}

void DelDaun (BinTree *P, int X)
{
	if ((X==Akar(*P))&&(IsOneElmt(*P))) {
		free(*P);
	}
	else {
		if (SearchPB(Left(*P), X)) {
			DelDaun(&Left(*P), X);
		}
		if (SearchPB(Right(*P), X)) {
			DelDaun(&Right(*P), X);
		}
	}
}

BinTree BuildBalanceTree (int n)
{
	paddress P;
	int nL, nR;
	int X;
	BinTree R, L;
	if (n==0) {
		return NilTree;
	}
	else {
		scanf("%d", &X);
		Allocate(&P);
		if (P!=NilTree) {
			Akar(P) = X;
			nL = n/2; nR = n-nL-1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L; 
			Right(P) = R;
		}
		return P;
	}
}

BinTree InsSearch (BinTree P, int X)
{

	BinTree Pout;

	if (IsTreeEmpty(P)) {
		MakeTree(X, NilTree, NilTree, &Pout);
	}
	else {
		if (X>Akar(P)) {
			Pout = InsSearch(Right(P), X);
		}
		else if (X<Akar(P)) {
			Pout = InsSearch(Left(P),X);
		}
	}
	return Pout;
}

void DelBtree (BinTree *P, int X)

{
	paddress q;

	if (X<Akar(*P)) {
		DelBtree(&Left(*P), X);
	}
	else if (X>Akar(*P)) {
		DelBtree(&Right(*P),X);
	}
	else if (X==Akar(*P)) {
		q = Tree(Akar(*P), Left(*P), Right(*P));
		if (Right(q) == NilTree) {
			(*P) = Left(q);
		}
		else if (Left(q)==NilTree) {
			(*P) = Right(q);
		}
		else {
			DelNode(&Left(q));
			free(q);
		}
	}
}


void DelNode (BinTree *P) {
	paddress q;
	if (Right(*P)!=NilTree) {
		DelNode(&Right(*P));
	}
	else {
		q = *P;
		*P = Left(*P);
	}
}

void SearchBranch(BinTree *P, Stack * StackIn, Stack * StackOut)
{
  infotypeStackt X;
  boolean match = true;
  while ((match) && (!IsOneElmt(*P))){
    if (!IsEmptyStackt(*StackIn)){
      Pop(StackIn,&X);
      Push(StackOut,X);
    }
    if (IsUnerRight(*P)){
      if (InfoTop(*StackIn) != Akar(Right(*P))){
        match = false;
      }
      *P = Right(*P); 
    }
    else if (IsUnerLeft(*P)){
      if (InfoTop(*StackIn) != Akar(Left(*P))){
        match = false;
      }
      *P = Left(*P); 
    }
    else{
      if (InfoTop(*StackIn) == Akar(Right(*P))){
        *P = Right(*P);
      }
      else if (InfoTop(*StackIn) == Akar(Left(*P))){
        *P = Left(*P);
      }
      else{
        match = false;
      }
    }
  } 
}

void  LoadRecipe (BinTree *P)
{
  LoadTree(P);
}
