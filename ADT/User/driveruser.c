#include <stdio.h>
#include "user.c"
#include "../Wordmachine/charmachine.c"
#include "../Wordmachine/wordmachine.c"
#include "../DaftarPertemanan/daftarpertemanan.c"
#include "../PermintaanPertemanan/permintaanpertemanan.c"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"
#include "../Draftkicauan/draftkicauan.c"
#include "../pcolor/pcolor.c"
#include "../../globalVar.c"

int main(){
    // set matriks pertemanan
    CreateEmptyDaftarPertemanan(&DaftarPertemanan);

    // set daftar kicauan
    CreateListKicauan(&ListKicauan, 100);

    // set daftar id utas
    CreateListIdUtas(&ListIdUtas, 100);

    // Inisialisasi ListUser (Daftar Pengguna)
    createListUser(&user);
    Word nama;
    Word sandi;
    KICAUAN k;
    printf("Masukkan nama: \n");
    readWord(&nama, ';');
    printf("\n");

    // Handle kasus nama sudah terdaftar, loop sampai nama valid.
    while (!isNamaValid(nama) || nama.Length == 0){
        if (nama.Length == 0) {
            printf("Nama tidak boleh kosong, isi kembali!\n\n");
        } else {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
        }
        printf("Masukkan nama: \n");
        readWord(&nama, ';');
        printf("\n");
    }
    printf("\n");

    // Membaca kata sandi dengan mesin kata
    printf("Masukkan kata sandi: \n");
    readWord(&sandi, ';');
    printf("\n\n");

    // Add user
    user.CounterUser = 0;
    CurrentUserId = 0;
    addUser(&user,nama,sandi);
}