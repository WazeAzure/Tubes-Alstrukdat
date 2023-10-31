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

    KICAUAN kicau;
    CreateKicauan(&kicau, 1, Author);

    printf("%d\n", kicau.id);
    showKicauanContent(kicau);
    return 0;
}