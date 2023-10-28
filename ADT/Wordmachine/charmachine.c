/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char MARK)
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       // if(currentChar != '\0'){
       //        printf("called\n");
       //        fgetc(pita);
       //        fgetc(pita);
       //        currentChar = '\0';
       // }
       
       // printf("Start called\n");
       // if(currentChar == '\0') printf("asdas %c\n", currentChar);
       pita = stdin;
       ADV(MARK);
}

void ADV(char MARK)
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOP = (currentChar == MARK);
       // printf("EOP %d\n", EOP);
       // if(currentChar == '\n') printf("newline detected\n");
       // if(currentChar == '\0') printf("end of \\0 detected\n");
       // printf("cc --> %c\n", currentChar);
       if (EOP && currentChar != '\n')
       {
              fgetc(pita);
              // fclose(pita);
              // printf("closed\n");
              
       }
}