#include "util.c"

// global vars


int main(){

    // print welcome message
    printWelcomeBanner();

    printf("Selamat datang di BurBir.\nAplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

    // load semua file config
    loadConfigFile();



    return 0;
}