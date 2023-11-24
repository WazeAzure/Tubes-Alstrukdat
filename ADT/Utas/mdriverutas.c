#include "utas.c"
#include "stdio.h"

#include "../../globalVar.c"
#include "../Wordmachine/charmachine.c"
#include "../Wordmachine/wordmachine.c"
#include "../DisjoinSetUnion/circle.c"
#include "../../util.c"
#include "../pcolor/pcolor.c"
#include "../User/user.c"
#include "../Kicauan/kicauan.c"

int main(){
    CreateListKicauan(&ListKicauan, 100);

    char name[] = "justin hehe";
    Word Author;
    int len = strLen(name);

    for(int i=0; i<len; i++){
        Author.TabWord[i] = name[i];
    }
    Author.Length = len;
    kicau(Author);
    printf("ini kicauan\n");
    kicauan();
    Word input;
    input.TabWord[0] = 0;
    KICAUAN kicauan;
    kicauan.id = 2;

    printf("tes\n");
    Word idUtas;
    Word index;
    Word teks;
    scanf("masukkan idUtas %s\n", idUtas);
    idUtas.TabWord[0] = 1;
    int sum = 0;
    int Index = WordToInt(index); 
    printf("s\n");
    int cap;
    scanf("%d", cap);
    CreateListIdUtas(&ListIdUtas, cap);
    AddressUtas daftarUtas;
    if(ListIdUtas.buffer == NULL){
        printf("LIST KOSONG\n");
    }
    CreateListElementUtas(&daftarUtas);
    if(isEmptyDaftarUtas(daftarUtas) && isEmptyListIdUtas(ListIdUtas)){
        printf("tidak ada kicauan yang diutas\n");
    }
    printf("Banyak elemen list utas pada kicau %d adalah %d\n",kicauan.id,lengthDaftarUtas(daftarUtas));
    printf("%d\n",lengthDaftarIdUtas(ListIdUtas));
    utas(2);
    sambung_utas(idUtas,index);
    insertAtDaftarUtas(&daftarUtas,teks,Index);
    cetak_utas(sum);
    printf(" Adress index ke %d : %p\n", Index, cariAddress(&daftarUtas,Index));
    hapus_utas(index,idUtas);
    int lent = lengthDaftarIdUtas(ListIdUtas);
    cetak_utas(sum);
    if(isUtas(2)){
        printf("ini adalah utas\n");
    }
    int lastidxidutas = getLastIdx(ListIdUtas);
    printf("idUtas terakhir adalah %d\n",lastidxidutas);
    insertLastDaftarUtas(&daftarUtas,teks,2);
    cetak_utas(sum);
    deleteFirstDaftarUtas(&daftarUtas);
    cetak_utas(sum);
    return 0;
}