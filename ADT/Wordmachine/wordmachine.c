#include <stdio.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

#define endl printf("\n")

void IgnoreBlanks(char MARK)
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV(MARK);
    }
}

void STARTWORD(char MARK)
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(MARK);
    IgnoreBlanks(MARK);
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord(MARK);
    }
}

void ADVWORD(char MARK)
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks(MARK);
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord(MARK);
        IgnoreBlanks(MARK);
    }
}

void CopyWord(char MARK)
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV(MARK);
        }
        else
            break;
    }
}

Word ConcatWord(Word w1, Word w2){
    Word w3;
    w3.Length = w1.Length + w2.Length;

    int i, j;
    for(i=0; i<w1.Length; i++){
        w3.TabWord[i] = w1.TabWord[i];
    }

    for(j = 0; j < w2.Length; j++){
        w3.TabWord[i] = w2.TabWord[j];
        i++;
    }
    w3.TabWord[i] = '\0';
    return w3;
}

Word CharToWord(char str[]){
    Word w;

    // get string length
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    w.Length = i;

    // int i;
    for(i=0; i<w.Length; i++){
        w.TabWord[i] = str[i];
    }

    w.TabWord[i] = '\0';
    return w;
}

void WordToChar(Word str, char* arr_str){
    int i;
    for(i=0; i<str.Length; i++){
        arr_str[i] = str.TabWord[i]; 
    }
    arr_str[i] = '\0';
}

void readWord(Word *input, char MARK) {
    int i;
    START(MARK);
    IgnoreBlanks(MARK);

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV(MARK);
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

void printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);

   }

}