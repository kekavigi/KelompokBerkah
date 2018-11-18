 #include "hand.h" 
boolean IsEmptyHand(Hand H){
	return (Top(H)==Nil);
}
boolean IsFullHand (Hand H){
	return (Top(H)==MaxEl);
}
void CreateEmptyHand (Hand *H){
	Top(*H) = Nil;
}
void PopHand (Hand * H, infotype* X){
 	*X = InfoTop(*H);
	 Top(*H)--;	
}

void PushHand (Hand * H, infotype X){
	Top(*H)++;
 	InfoTop(*H) = X;
}

void CH(Hand *Tangan){
	//Membuang semua makanan di hand
	infotype bahan;
	while(! IsEmptyHand(*Tangan)){
		PopHand(Tangan,&bahan);
	}
}

void TAKE(Hand *Tangan,infotype bahan){
	//Mengambil objek bahan makanan
	PushHand(Tangan,bahan);
}


