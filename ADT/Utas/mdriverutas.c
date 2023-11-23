#include "utas.h"
#include "utas.c"
#include "stdio.h"

int main(){
    Word idUtas;
    Word index;
    Word teks;
    int IdUtas = WordToInt(idUtas);
    int Index = WordToInt(index); 
    LISTIDUTAS l;
    KICAUAN kicauan;
    kicauan.id = 2;
    CreateListIdUtas(&l, 10);
    AddressUtas daftarUtas;
    if(l.buffer == NULL){
        printf("LIST KOSONG\n");
    }
    printf("Neff %d\n", l.nEFF);
    printf("cap %d\n", l.CAPACITY);
    CreateListElementUtas(&daftarUtas);
    if(isEmptyDaftarUtas(daftarUtas) && isEmptyListIdUtas(l)){
        printf("tidak ada kicauan yang diutas\n");
    }
    printf('Banyak elemen list utas pada kicau %d adalah %d\n',kicauan.id,lengthDaftarUtas(daftarUtas));
    printf('%d\n',lengthDaftarIdUtas(l));
    utas(2);
    sambung_utas(idUtas,index);
    insertAtDaftarUtas(&daftarUtas,teks,Index);
    cetak_utas(IdUtas);
    printf(" Adress index ke %d : %p\n", Index, cariAddress(&daftarUtas,Index));
    sambung_utas(idUtas,index);
    sambung_utas(idUtas,index);
    hapus_utas(index,idUtas);
    int len = lengthDaftarIdUtas(l);
    cetak_utas(IdUtas);
    if(isUtas(2)){
        printf("ini adalah utas\n");
    }
    int lastidxidutas = getLastIdx(l);
    printf("idUtas terakhir adalah %d\n",lastidxidutas);
    insertLastDaftarUtas(&daftarUtas,teks,2);
    cetak_utas(IdUtas);
    deleteFirstDaftarUtas(&daftarUtas);
    cetak_utas(IdUtas);
    return 0;
}