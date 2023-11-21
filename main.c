#include "globalVar.h"

// daftar fungsi header
#include "ADT/User/user.h"
#include "ADT/Kicauan/kicauan.h"
#include "ADT/Utas/utas.h"
#include "ADT/HashTable/HashTable.h"
#include "ADT/Balasan/pohontree.h"

// daftar fungsi C
#include "util.c"
#include "ADT/User/user.c"
#include "ADT/Kicauan/kicauan.c"
#include "ADT/DaftarPertemanan/daftarpertemanan.h"
#include "ADT/Utas/utas.c"
#include "ADT/HashTable/HashTable.c"
#include "ADT/Balasan/pohontree.c"

void initiateGlobalVariables(){
    // set matriks pertemanan
    CreateEmptyDaftarPertemanan(&DaftarPertemanan);

    // set daftar kicauan
    CreateListKicauan(&ListKicauan, 100);

    // set daftar id utas
    CreateListIdUtas(&ListIdUtas, 100);

    // Inisialisasi ListUser (Daftar Pengguna)
    createListUser(&user);

    // Inisialisasi Hash Table Tagar
    ht_new(&HashTable);

    // Inisialisasi list id utas
    CreateListIdUtas(&ListIdUtas, 10);
}

int main(){
    // define initial value of global variables
    initiateGlobalVariables();

    // print welcome message
    printWelcomeBanner();

    printf("Selamat datang di BurBir.\nAplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

    // load semua file config
    loadConfigFile();

    Word input[3];
    input[0].Length = 0;
    input[1].Length = 0;
    input[2].Length = 0;
    
    char command[30][30] = {"DAFTAR", "MASUK", "KELUAR", "TUTUP_PROGRAM",
                            "GANTI_PROFIL", "LIHAT_PROFIL", "ATUR_JENIS_AKUN", "UBAH_FOTO_PROFIL",
                            "DAFTAR_TEMAN", "HAPUS_TEMAN",
                            "TAMBAH_TEMAN", "BATAL_TAMBAH_TEMAN", "DAFTAR_PERMINTAAN_PERTEMANAN", "SETUJUI_PERTEMANAN",
                            "KICAU", "KICAUAN", "SUKA_KICAUAN", "UBAH_KICAUAN",
                            "BALAS", "BALASAN", "HAPUS_BALASAN",
                            "BUAT_DRAF", "LIHAT_DRAF",
                            "UTAS", "SAMBUNG_UTAS", "HAPUS_UTAS", "CETAK_UTAS",
                            "SIMPAN", "MUAT",
                            "CARI_KICAUAN"};
    /* 
    not login hanya bisa : DAFTAR, MASUK, MUAT, SIMPAN, TUTUP_PROGRAM
    yes login hanya bisa : selain not login, SIMPAN, TUTUP_PROGRAM
    */

    // printf("succeed to pass readCommand \n");
    boolean loop = true;
    while(loop){
        readCommandMain(input);
        if(CurrentUserId == -1){
            if(strCompare(input[0].TabWord, command[0])){
                // DAFTAR
                printf("called %s\n", command[0]);
                daftar();
            }
            else if(strCompare(input[0].TabWord, command[1])){
                // MASUK
                printf("called %s\n", command[1]);
                masuk();
            }
            else if(strCompare(input[0].TabWord, command[27])){
                // SIMPAN
                printf("called %s\n", command[27]);
            }
            else if(strCompare(input[0].TabWord, command[28])){
                // MUAT
                printf("called %s\n", command[28]);
            }
            else if(strCompare(input[0].TabWord, command[3])){
                // TUTUP_PROGRAM
                loop = false;
                printf("called %s\n", command[3]);
                printExitBanner();
            }
            else {
                printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else {
            if(strCompare(input[0].TabWord, command[2])){
                // KELUAR
                printf("called %s\n", command[2]);
                keluar();
            }
            else if(strCompare(input[0].TabWord, command[3])){
                // TUTUP_PROGRAM
                loop = false;
                printf("called %s\n", command[3]);
                printExitBanner();
            }
            else if(strCompare(input[0].TabWord, command[4])){
                // GANTI_PROFIL
                printf("called %s\n", command[4]);
                ganti_profile();
            }
            else if(strCompare(input[0].TabWord, command[5])){
                // LIHAT_PROFIL
                printf("called %s\n", command[5]);
                lihat_profil(input[1]);
            }
            else if(strCompare(input[0].TabWord, command[6])){
                // ATUR_JENIS_AKUN
                printf("called %s\n", command[6]);
                atur_jenis_akun();
            }
            else if(strCompare(input[0].TabWord, command[7])){
                // UBAH_FOTO_PROFIL
                printf("called %s\n", command[7]);
                ubah_foto_profil();
            }
            else if(strCompare(input[0].TabWord, command[8])){
                // DAFTAR_TEMAN
                printf("called %s\n", command[8]);
                showDaftarTeman(CurrentUserId);
            }
            else if(strCompare(input[0].TabWord, command[9])){
                // HAPUS_TEMAN
                printf("called %s\n", command[9]);
                hapusTeman(CurrentUserId);
            }
            else if(strCompare(input[0].TabWord, command[10])){
                // TAMBAH_TEMAN
                printf("called %s\n", command[10]);
                tambahTeman(CurrentUserId);
            }
            else if(strCompare(input[0].TabWord, command[11])){
                // BATAL_TAMBAH_TEMAN
                printf("called %s\n", command[11]);
            }
            else if(strCompare(input[0].TabWord, command[12])){
                // DAFTAR_PERMINTAAN_PERTEMANAN
                printf("called %s\n", command[12]);
                showDaftarPermintaanPertemanan(CurrentUserId);
            }
            else if(strCompare(input[0].TabWord, command[13])){
                // SETUJUI PERTEMANAN
                printf("called %s\n", command[13]);
                setujuiPermintaanPertemanan(CurrentUserId);
            }
            else if(strCompare(input[0].TabWord, command[14])){
                // KICAU
                printf("called %s\n", command[14]);
                kicau(USER(user, CurrentUserId).nama);
                ht_insert(&HashTable, ListKicauan.buffer[ListKicauan.NEFF-1].tagar.TabWord, &ListKicauan.buffer[ListKicauan.NEFF-1]);
            }
            else if(strCompare(input[0].TabWord, command[15])){
                // KICAUAN
                printf("called %s\n", command[15]);
                kicauan();
            }
            else if(strCompare(input[0].TabWord, command[16])){
                // SUKA_KICAUAN
                printf("called %s\n", command[16]);
                sukaKicauan(input[1]);
            }
            else if(strCompare(input[0].TabWord, command[17])){
                // UBAH_KICAUAN
                printf("called %s\n", command[17]);
                ubahKicauan(input[1]);
            }
            else if(strCompare(input[0].TabWord, command[18])){
                // BALAS
                printf("called %s\n", command[18]);
                int idKicau = WordToInt(input[1]);
                // int idBalasan = WordToInt(input[2]);
                balas(idKicau, input[2]);
            }
            else if(strCompare(input[0].TabWord, command[19])){
                // BALASAN
                printf("called %s\n", command[19]);
            }
            else if(strCompare(input[0].TabWord, command[20])){
                // HAPUS_BALASAN
                printf("called %s\n", command[20]);
            }
            else if(strCompare(input[0].TabWord, command[21])){
                // BUAT_DRAF
                printf("called %s\n", command[21]);
                buatDraft();
            }
            else if(strCompare(input[0].TabWord, command[22])){
                // LIHAT_DRAF
                printf("called %s\n", command[22]);
                lihatDraft(DRAFT(USER(user, CurrentUserId)));
            }
            else if(strCompare(input[0].TabWord, command[23])){
                // UTAS
                printf("called %s\n", command[23]);
                // utas(WordToInt(input[1]));
                int idKicau = WordToInt(input[1]);
                utas(idKicau);
            }
            else if(strCompare(input[0].TabWord, command[24])){
                // SAMBUNG_UTAS
                printf("called %s\n", command[24]);
                KICAUAN k;
                k = KICAUAN_ELMT(ListKicauan ,KICAUAN_ELMT(ListIdUtas,WordToInt(input[1])));
                sambung_utas((input[2]),&k.daftar_utas,(input[1]));
            }
            else if(strCompare(input[0].TabWord, command[25])){
                // HAPUS_UTAS
                printf("called %s\n", command[25]);
                KICAUAN k;
                k = KICAUAN_ELMT(ListKicauan ,KICAUAN_ELMT(ListIdUtas,WordToInt(input[1])));
                hapus_utas((input[2]),ListIdUtas,(input[1]),&k.daftar_utas,&TEKSUTAS(k.daftar_utas));
            }
            else if(strCompare(input[0].TabWord, command[26])){
                // CETAK UTAS
                printf("called %s\n", command[26]);
                // KICAUAN k;
                // k = KICAUAN_ELMT(ListKicauan ,KICAUAN_ELMT(ListIdUtas,WordToInt(input[1])));
                cetak_utas(WordToInt(input[1]));
            }
            else if(strCompare(input[0].TabWord, command[27])){
                // SIMPAN
                printf("called %s\n", command[27]);
            }
            else if(strCompare(input[0].TabWord, "showAllKicauan")){
                showAllListKicauan();
            }
            else if(strCompare(input[0].TabWord, command[29])){
                // CARI_KICAUAN
                printf("called %s\n", command[29]);
                cari_kicauan(input[1]);
            }
            else {
                printErrMessage(input[0]);
            }
        }
        resetCommand(input);
    }
    return 0;
}

//  gcc -o test  ADT/DaftarPertemanan/daftarpertemanan.c ADT/Datetime/datetime.c ADT/Draftkicauan/draftkicauan.c ADT/Foo/foo.c ADT/Kicauan/kicauan.c ADT/Matrix/matrix.c ADT/pcolor/pcolor.c ADT/Prioqueue/prioqueue.c ADT/User/user.c ADT/Wordmachine/Wordmachine.c globalVar.c main.c utilc