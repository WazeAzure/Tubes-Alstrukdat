#include "utas.h"
#include "utas.c"
#include "stdio.h"

int main(){
    Word idUtas;
    Word index;
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
        printf("tidak ada kicauan yang diutas");
    }
    printf('Banyak elemen list utas pada kicau %d adalah %d\n',kicauan.id,lengthDaftarUtas(daftarUtas));
    printf('%d\n',lengthDaftarIdUtas(l));
    utas(2);
    sambung_utas(idUtas,index);
    deleteAtUtas(daftarUtas,1);
    cetak_utas(1);
    return 0;
}