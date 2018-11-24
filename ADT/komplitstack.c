#include "stackt.h"
#include "array.h"
#include "bintree.h"

Stack Hand;
Stack Nampan;
TabInt Pesanan;
void CH(Stack *Hand){
	//Membuang semua makanan di hand
	infotypeStackt bahan;
	while(! IsEmptyStackt(*Hand)){
		Pop(Hand,&bahan);
	}
}
void CT(Stack *Nampan){
	//Membuang semua makanan di tray
	infotypeStackt makanan;
	while(! IsEmptyStackt(*Nampan)){
		Pop(Nampan,&makanan);	
	}
}

void TAKE(Stack *Hand,infotypeStackt bahan){
	//Mengambil objek bahan makanan
	Push(Hand,bahan);
}

void ShowRecipe (BinTree P)
/* Mencetak Resep */
{
  //Algoritma
  ShowBranch(P);
}


void PUT (BinTree  P, Stack *Bahan,Stack *Food)
{
  //Kamus
  Stack SLoop, SIn, SOut, SExtra,FoodExtra;
  infotypeStackt X;
  BinTree Px;
  //Algoritma
  CreateEmptyStackt(&SLoop);
  CreateEmptyStackt(&FoodExtra);
  CreateEmptyStackt(&SIn);
  while(!IsEmptyStackt(*Bahan)){
    while ((InfoTop(*Bahan) != 1) && (!IsEmptyStackt(*Bahan))){ //Cari piring di Stack
      Pop(Bahan,&X);
      Push(&SIn,X);
    }
    if (InfoTop(*Bahan) == 1){ //Kalo udah ketemu piring di Top Bahan
      CreateEmptyStackt(&SOut);
      //taro piring di SIn
      Pop(Bahan,&X);
      Push(&SIn,X);
      Px = P; 
      SearchBranch(&Px, &SIn, &SOut); 
      if (IsOneElmt(Px)) { //Kalo sesuai resep
        Push(&FoodExtra, Akar(Px)); //biar dibalik dulu stacknya
        //Jika ada makanan yang sisa di SIn, balikin ke SLoop dulu
        while (!IsEmptyStackt(SIn)){
          Pop(&SIn,&X);
          Push(&SLoop,X);
        }
      }
      else { //gak sesuai resep, balikin ke SLoop dulu
        CreateEmptyStackt(&SExtra);
        while(!(IsEmptyStackt(SOut))){
          Pop(&SOut,&X);
          Push(&SIn,X);
        }
        while(!(IsEmptyStackt(SIn))){
          Pop(&SIn,&X);
          Push(&SExtra,X);
        }
        while(!(IsEmptyStackt(SExtra))){
          Pop(&SExtra,&X);
          Push(&SLoop,X);
        }
      }
    }
    else { //Gak ada piring di stack Bahan 
      //Balikin SIn ke SLoop dulu
      while (!IsEmptyStackt(SIn)){
        Pop(&SIn,&X);
        Push(&SLoop,X);
      }
    }
  }
  //kalo SLoop gak kosong, balikin semuanya ke Bahan
  //CreateEmptyStackt(&SIn);
  while(!IsEmptyStackt(SLoop)){
    Pop(&SLoop,&X);
    Push(Bahan,X);
  }
  while(!IsEmptyStackt(FoodExtra)){
    Pop(&FoodExtra,&X);
    Push(Food,X);
  } 
}
//int CekRacikan(Stack *Hand);