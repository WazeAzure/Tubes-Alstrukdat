#include "user.h"
#include <stdio.h>

int main() {
    FOTO foto;
    createFoto(5, 5, &foto);
    readFoto(&foto);
    displayFoto(foto);
    // Word tes, tes1;
    // readWord(&tes, '\n');
    // printWord(tes);

    // readWord(&tes1, '\n');
    // printWord(tes1);
    return 0;
}