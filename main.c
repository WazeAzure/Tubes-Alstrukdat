#include "util.c"

// global vars


int main(){

    // print welcome message
    printWelcomeBanner();

    printf("Selamat datang di BurBir.\nAplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

    // load semua file config
    loadConfigFile();

    Word input[3];
    readCommandMain(input);

    // char command[2][100] = {"TUTUP_APLIKASI", "DAFTAR"};
    printf("asdasdasdas\n");
    // while(input[0].TabWord != command[0]){
    //     if(input[0].TabWord == command[1]){

    //     }
    //     readCommandMain(input);
    //     break;
    // }



    return 0;
}