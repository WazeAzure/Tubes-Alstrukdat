#include <stdio.h>
#include <stdlib.h>

#include "kicauan.h"
#include "kicauan.c"

#include "../Wordmachine/wordmachine.c"
#include "../Wordmachine/charmachine.c"
#include "../../util.c"
#include "../DisjoinSetUnion/circle.c"
#include "../pcolor/pcolor.c"
#include "../User/user.c"
#include "../Utas/utas.c"



#include "../../globalVar.c"

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
    sukaKicauan(input);
    return 0;
}
// gcc -o kicauan ADT/Draftkicauan/draftkicauan.c ADT/User/user.c ADT/Wordmachine/charmachine.c ADT/Wordmachine/wordmachine.c ADT/Kicauan/kicauan.c ADT/Draftkicauan/mdrivekicauan.c globalVar.c main.c ADT/pcolor/pcolor.c