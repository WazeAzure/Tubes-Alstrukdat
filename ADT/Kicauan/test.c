#include <stdio.h>
#include <stdlib.h>

#include "kicauan.h"
#include "kicauan.c"

#include "../Wordmachine/wordmachine.h"
#include "../../util.c"

#include "../../globalVar.h"

int main(){
    CreateListKicauan(&ListKicauan, 100);

    char name[] = "justin hehe";
    Word Author;
    int len = strLen(name);

    for(int i=0; i<len; i++){
        Author.TabWord[i] = name[i];
    }
    Author.Length = len;

    for(int i=0; i<3; i++){
        kicau(Author);

        printf("--------------------\ndaftar kicauan\n");
        showAllListKicauan();
    }
    

    return 0;
}