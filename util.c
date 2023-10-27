#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include "ADT/pcolor/pcolor.h"
#include "ADT/Wordmachine/wordmachine.h"

#define endl printf("\n")
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

void readFile(Word FileName){
    char filename[FileName.Length];
    WordToChar(FileName, filename);

    FILE* f_pengguna = fopen(filename, "r");   // buka file pengguna

    if(f_pengguna != NULL){
        printf("file opened \'%s\'\n", filename);
    } else {
        printf("file \'%s\' not exist\n", filename);
        return;
    }

    fclose(f_pengguna); // tutup file pengguna
}

void loadConfigFile(){
    Word foldername;
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    readWord(&foldername, '\n');

    // <-- berikan pengecekkan folder
    if(!isFolderExist(foldername)){
        // end of function
        return;
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

    readFile(pengguna);
    readFile(kicauan);
    readFile(balasan);
    readFile(utas);
    
}

