#include "graph.h"

void MakeGRAPH(GRAPH *graf, int room_inisial){
// membentuk sebuah graf ketetanggaan dari namafile, dengan room yang aktif adalah room_inisial
  MakeMATRIKS(&MatGraf(*graf), 4, 4);
  BacaFileMATRIKS(&MatGraf(*graf), "tetangga.txt");
  RumAktif(*graf) = room_inisial;
}

void Teleport(GRAPH *graf, int X){
// I.S : Player sudah ada dipintu, mengecek apakah gerakan X dapat mengubah room_inisial
// F.S : jika bisa mengubah room, room yang aktif berubah, jika tidak tidak ada yang terjadi
  int tujuan;
  for (tujuan=1; tujuan<=4; tujuan++){
      if (ValGraf(*graf, RumAktif(*graf), tujuan) == X){
          RumAktif(*graf) = tujuan;
          break;
      };
  };
}
