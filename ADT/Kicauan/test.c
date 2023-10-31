#include <stdio.h>
#include <stdlib.h>

#include "kicauan.h"
#include "kicauan.c"

#include "../Wordmachine/wordmachine.h"
#include "../../util.c"

int main(){
    char name[] = "justin hehe";
    Word Author;
    int len = strLen(name);

    for(int i=0; i<len; i++){
        Author.TabWord[i] = name[i];
    }
    Author.Length = len;

    kicau(Author);

    printf("daftar kicauan\n");
    showAllListKicauan();

    return 0;
}