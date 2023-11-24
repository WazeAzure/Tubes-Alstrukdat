#include "../boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

#include <stdio.h>


int main() {

    printf("Testing ADVWORD fungsi :\n");
    ADVWORD('\n');
    printf("EndWord: %s\n", EndWord ? "true" : "false");
    printf("Current Word: ");
    printWord(currentWord);
    printf("\n\n");

    printf("Mengetes fungsi STARTWORD:\n");
    STARTWORD('\n');
    printf("EndWord: %s\n", EndWord ? "true" : "false");
    printf("Current Word: ");
    printWord(currentWord);
    printf("\n\n");


    printf("Testing fungsi  ConcatWord :\n");
    Word w1 = CharToWord("Hello");
    Word w2 = CharToWord("World");
    Word w3 = ConcatWord(w1, w2);
    printf("Concatenated Word: ");
    printWord(w3);
    printf("\n\n");

    printf("Testing fungsi WordToInt:\n");
    Word w5 = CharToWord("123");
    int num = WordToInt(w5);
    printf("Converted Integer: %d\n\n", num);

    printf("Testing fungsi CharToWord:\n");
    char str[] = "TestingCharToWord";
    Word w4 = CharToWord(str);
    printf("Converted Word: ");
    printWord(w4);
    printf("\n\n");


    printf("Testing fungsi  readWord :\n");
    Word inputWord;
    readWord(&inputWord, '\n');
    printf("Read Word: ");
    printWord(inputWord);
    printf("\n\n");

    printf("Testing fungsi readHP :\n");
    NoHp inputHP;
    readHP(&inputHP, '\n');
    printf("No HP : %s\n", inputHP.TabWord);

    return 0;
}
