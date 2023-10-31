#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include "ADT/pcolor/pcolor.h"
#include "ADT/Wordmachine/wordmachine.h"

#define endl printf("\n")


boolean isFolderExist(Word foldername){
    struct stat st;

    // Use stat to check the folder's existence
    if (stat(foldername.TabWord, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            printf("Folder '%s' exists.\n", foldername.TabWord);
            return true;
        } else {
            printf("'%s' is not a folder.\n", foldername.TabWord);
            return false;
        }
    } else {
        printf("Folder '%s' does not exist.\n", foldername.TabWord);
        return false;
    }
}

boolean readFile(Word FileName){
    char filename[FileName.Length];
    WordToChar(FileName, filename);

    FILE* f_pengguna = fopen(filename, "r");   // buka file pengguna

    if(f_pengguna != NULL){
        printf("file opened \'%s\'\n", filename);
    } else {
        printf("file \'%s\' not exist\n", filename);
        return false;
    }

    fclose(f_pengguna); // tutup file pengguna
    return true;
}

void loadConfigFile(){
    Word foldername;
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    readWord(&foldername, '\n');

    // <-- berikan pengecekkan folder
    while(!isFolderExist(foldername)){
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        readWord(&foldername, '\n');
    }

    char char_pengguna[] = "/pengguna.config";
    char char_kicauan[] = "/kicauan.config";
    char char_balasan[] = "/balasan.config";
    char char_utas[] = "/utas.config";

    Word pengguna = CharToWord(char_pengguna);
    Word kicauan = CharToWord(char_kicauan);
    Word balasan = CharToWord(char_balasan);
    Word utas = CharToWord(char_utas);

    pengguna = ConcatWord(foldername, pengguna);
    kicauan = ConcatWord(foldername, kicauan);
    balasan = ConcatWord(foldername, balasan);
    utas = ConcatWord(foldername, utas);

    boolean stat1 = readFile(pengguna);
    boolean stat2 = readFile(kicauan);
    boolean stat3 = readFile(balasan);
    boolean stat4 = readFile(utas);

    if(!(stat1 && stat2 && stat3 && stat4)){
        printf("Mohon pastikan semua file ada.\n");
        exit(1);
    }
}

void readCommandMain(Word* input){
    printf("> ");
    Word sentence;
    // printf("current char %c\n", currentChar);
    readWord(&sentence, ';');
    // printf("%s\n", sentence.TabWord);
    // printf("%s\n", sentence.TabWord);

    int idx = 0;
    int i=0, j =0;
    boolean loop = true;
    while(loop){
        if(sentence.TabWord[i] == '\0') loop = false;
        if(sentence.TabWord[i] == ' '){
            input[idx].Length = j;
            input[idx].TabWord[j] = '\0';
            j = 0;
            idx++;
            i++;
        }
        
        if(idx == 0){
            input[0].TabWord[j] = sentence.TabWord[i];
        } else if(idx == 1){
            input[1].TabWord[j] = sentence.TabWord[i];
        } else {
            input[2].TabWord[j] = sentence.TabWord[i]; 
        }

        j++;
        i++;
    }

    input[idx].Length = j;
    input[idx].TabWord[j] = '\0';

    // printf("%d\n", idx);

    // printWord(input[0]);
    // endl;
    // printWord(input[1]);
    // endl;
    // printWord(input[2]);
    // endl;
}

int strLen(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

boolean strCompare(char str1[], char str2[]){
    // printf("%s\n", str1);
    // printf("%s\n", str2);
    
    int i=0;
    int len1 = strLen(str1);
    int len2 = strLen(str2);

    // printf("arr s1 s2 - %d %d\n", len1, len2);

    if(len1 != len2) return false;

    while(i < len1){
        if(str1[i] != str2[i]) return false;
        i++;
    }

    return true;
}

/* SECTION PRINT PRINT-AN AJA */

void printWelcomeBanner(){
    // clear screen
    system("clear");

    // welcome message
    printf(
"        \n"
" _______                       _______   __           \t\t ⠀⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣶⣶⡿⢋\n"
"|       \\                     |       \\ |  \\          \t\t ⠀⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋\n"
"| $$$$$$$\\ __    __   ______  | $$$$$$$\\ \\$$  ______  \t\t ⠀⠹⣿⣿⣿⣿⣶⣤⣤⣤⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀\n"
"| $$__/ $$|  \\  |  \\ /      \\ | $$__/ $$|  \\ /      \\ \t\t ⠀⣄⣈⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀\n"
"| $$    $$| $$  | $$|  $$$$$$\\| $$    $$| $$|  $$$$$$\\ \t\t ⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀\n"
"| $$$$$$$\\| $$  | $$| $$   \\$$| $$$$$$$\\| $$| $$   \\$$ \t\t ⠀⠀⣀⣉⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀\n"
"| $$__/ $$| $$__/ $$| $$      | $$__/ $$| $$| $$      \t\t ⠀⠀⠘⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀\n"
"| $$    $$ \\$$    $$| $$      | $$    $$| $$| $$      \t\t ⠀⠀⠀⠀⠀⢉⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀\n"
" \\$$$$$$$   \\$$$$$$  \\$$       \\$$$$$$$  \\$$ \\$$      \t\t ⠒⠶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀\n"
"                                                      \t\t ⠀⠀⠀⠉⠙⠛⠛⠛⠛⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"                                                      \t\t\n"
"                                                      \t\t\n"
    );
}

void printExitBanner(){
    printf(
" __________________\n"
"< Come Back Later! >\n"
" ------------------\n"
"        \\   ^__^\n"
"         \\  (oo)\\_______\n"
"            (__)\\       )\\/\\ \n"
"                ||----w |\n"
"                ||     ||\n"
    );
}

void printErrMessage(Word w){
    if(strCompare(w.TabWord, "DAFTAR")){
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    } else if(strCompare(w.TabWord, "MASUK")){
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    } else if(strCompare(w.TabWord, "MUAT")){
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    }
}