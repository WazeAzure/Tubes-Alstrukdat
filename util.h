#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include "ADT/pcolor/pcolor.h"
#include "ADT/Wordmachine/wordmachine.h"
#include "globalVar.h"
#include "ADT/DisjoinSetUnion/circle.h"

#include "ADT/Balasan/pohontree.h"

#define endl printf("\n")

int strLen(char str[]);

boolean strCompare(char str1[], char str2[]);

boolean isFolderExist(Word foldername);

void strip(char *str, char symbol);

void bacaPengguna(FILE* f);

boolean readFile(Word FileName, Word foldername);

void loadConfigFile();

void readCommandMain(Word* input);

/* SECTION PRINT PRINT-AN AJA */
void printWelcomeBanner();

void printExitBanner();

void printErrMessage(Word w);