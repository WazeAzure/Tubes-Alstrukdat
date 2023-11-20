#include "utas.h"
#include "utas.c"

int main(){
    LISTIDUTAS l;
    CreateListUtas(&l, 10);

    if(l.buffer == NULL){
        printf("LIST KOSONG\n");
    }
    printf("Neff %d\n", l.nEFF);
    printf("cap %d\n", l.CAPACITY);

    return 0;
}