#include "stackt.h"
#include "array.h"
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>


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
    while ((InfoTop(*Bahan) != 1) && (!IsEmptyStackt(*Bahan))){ 
      Pop(Bahan,&X);
      Push(&SIn,X);
    }
    if (InfoTop(*Bahan) == 1){ 
      CreateEmptyStackt(&SOut);
      //taro piring di SIn
      Pop(Bahan,&X);
      Push(&SIn,X);
      Px = P; 
      SearchBranch(&Px, &SIn, &SOut); 
      if (IsOneElmt(Px)) { 
        Push(&FoodExtra, Akar(Px)); 
        while (!IsEmptyStackt(SIn)){
          Pop(&SIn,&X);
          Push(&SLoop,X);
        }
      }
      else { 
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
    else { 
 
      while (!IsEmptyStackt(SIn)){
        Pop(&SIn,&X);
        Push(&SLoop,X);
      }
    }
  }

  while(!IsEmptyStackt(SLoop)){
    Pop(&SLoop,&X);
    Push(Bahan,X);
  }
  while(!IsEmptyStackt(FoodExtra)){
    Pop(&FoodExtra,&X);
    Push(Food,X);
  } 
}
