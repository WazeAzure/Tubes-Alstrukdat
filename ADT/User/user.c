#include "user.h"
#include "../pcolor/pcolor.h"
#include <stdio.h>

void createFoto(int nRows, int nCols, FOTO *m){
/* Membentuk sebuah FOTO "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk dan Set Default Foto */
    ROW_EFF(*m) = nRows;
	COL_EFF(*m) = nCols;

    // Set Default Foto
	IdxType i, j;
	for(i=0;i<nRows;i++){
		for(j=0;j<nCols;j++){
			COLOR(ELMT(*m, i, j)) = 'R';
            ASCII(ELMT(*m, i, j)) = '*';
		}
	}
}

/* *** Selektor "Dunia FOTO" *** */
boolean isFotoIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0 && i < 5 && j >=0 && j < 5);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(FOTO m){
/* Mengirimkan Index baris terbesar m */
    return ROW_EFF(m) - 1;
}
IdxType getLastIdxCol(FOTO m){
/* Mengirimkan Index kolom terbesar m */
    return COL_EFF(m) -1;
}
boolean isIdxEff(FOTO m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m));
}

/* ********** Assignment  FOTO ********** */
void copyFoto(FOTO mIn, FOTO *mOut){
/* Melakukan assignment mOut <- mIn */
    createFoto(ROW_EFF(mIn), COL_EFF(mIn), mOut);

	IdxType i=0, j=0;
	for(i=0; i<ROW_EFF(mIn); i++){
		for(j=0; j<COL_EFF(mIn); j++){
			ELMT(*mOut, i, j) = ELMT(mIn, i, j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
boolean isLineValid(Word line) {
// Mengecek apakah baris masukan foto valid atau tidak.
    if (line.Length != 10) {
        return false;
    } else {
        int i;
        for (i = 0; i < 10; i += 2) {
            if (line.TabWord[i] != 'R' && line.TabWord[i] != 'G' && line.TabWord[i] != 'B') {
                return false;
            }
        }
        return true;
    }
}

void readFoto(FOTO *m){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateFoto(m, 5, 5) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
    int i, j;
    Word line;
    FOTO temp;
    createFoto(5, 5, &temp);

    // IMPLEMENTASI
    boolean finish = false;
    while (!finish) {
        for (i = 0; i < 5; i++) {
            printf("%d\n", i);
            // Baca baris
            // if (i != 4){
            //     readWord(&line, '\n');
            // } else {
            //     readWord(&line, ';');
            // }
            readWord(&line, ';');
            printf("%d\n", line.Length);

            // Cek apakah input baris valid
            if (!isLineValid(line)) {
                printf("Masukkan Tidak valid, coba lagi!\n\n");
                // for (j = 0; j <= line.Length; j++) {
                //     line.TabWord[i] = '';
                // }
                break;
            } else {
                for (j = 0; j < 5; j++) {
                    COLOR(ELMT(temp, i, j)) = line.TabWord[2*j];
                    ASCII(ELMT(temp, i, j)) = line.TabWord[2*j+1];
                }
                if (i == 4) {
                    finish = true;
                }
            }
        }
    }
    copyFoto(temp, m);
}


void displayFoto(FOTO m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    IdxType i=0, j=0;
	for(i=0;i<ROW_EFF(m);i++){
		for(j=0;j<COL_EFF(m)-1;j++){
			if (COLOR(ELMT(m, i, j)) == 'R') {
                print_red(ASCII(ELMT(m, i, j)));
                printf(" ");
            } else if (COLOR(ELMT(m, i, j)) == 'G') {
                print_green(ASCII(ELMT(m, i, j)));
                printf(" ");
            } else if (COLOR(ELMT(m, i, j)) == 'B') {
                print_blue(ASCII(ELMT(m, i, j)));
                printf(" ");
            }
		}
        if (COLOR(ELMT(m, i, COL_EFF(m)-1)) == 'R') {
            print_red(ASCII(ELMT(m, i, COL_EFF(m)-1)));
            printf("\n");
        } else if (COLOR(ELMT(m, i, COL_EFF(m)-1)) == 'G') {
            print_green(ASCII(ELMT(m, i, COL_EFF(m)-1)));
            printf("\n");
        } else if (COLOR(ELMT(m, i, COL_EFF(m)-1)) == 'B') {
            print_blue(ASCII(ELMT(m, i, COL_EFF(m)-1)));
            printf("\n");
        }
	}
}

/* (BAKAL DIPINDAH KE FOLDER SECTION)
// Fungsi dan Prosedur
void daftar(){
//  Membaca nama pengguna baru dengan mesin kata.
    if (CurrentUserId == -1) {
        if (CounterUser < 20){ // Cek apakah jumlah pengguna maximum.
            Word nama, sandi;
            
            // membaca nama pengguna baru
            printf("Masukkan nama: \n");
            readWord(&nama, ';');
            printf("\n");

            // Handle kasus nama sudah terdaftar, loop sampai nama valid.
            while (!isNamaValid(nama)){
                printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
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
            NAMA(user[CounterUser]).TabWord = nama.TabWord;
            SANDI(user[CounterUser]).TabWord = sandi.TabWord;
            CounterUser++;

            // Sukses daftar
            printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");

        } else { // Daftar gagal.
            printf("Jumlah pengguna sudah melebihi batas");
        }
    } else {// CurrentUserId != -1 (sudah login)
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
}

void masuk(){
// Membaca nama untuk login
    if (CurrentUserId != -1) {

        Word nama, sandi;
        printf("Masukkan nama: \n");
        readWord(&nama, ';');
        printf("\n\n");

        // mengecek apakah nama terdaftar
        while (isNamaValid(nama)) {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            printf("Masukkan nama: \n");
            readWord(&nama, ';');
            printf("\n\n");
        }

        // Membaca kata sandi
        printf("Masukkan kata sandi: \n");
        readWord(&sandi, ';');
        printf("\n\n");
        while(!isSandiValid(nama, sandi)){
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
            printf("Masukkan kata sandi: \n");
            readWord(&sandi, ';');
            printf("\n\n");
        }
        CurrentUserId = userId(nama);

        // Success message
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n", nama.TabWord);
    
    } else { // sudah login
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n\n");
    }
}

void keluar(){
// Logout jika sedang login
    if (CurrentUserId == -1) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    } else {
        CurrentUserId = -1;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
    }
}

boolean isNamaValid(Word nama){
// Fungsi yang mengecek apakah nama yang dimasukkan belum terdaftar (valid);
    int i;
    for (i = 0; i < CounterUser; i++) {
        if (nama.TabWord == user[i].nama.TabWord){
            return false;
        }
    }
    return true;
}

boolean isSandiValid(Word nama, Word sandi){
// Fungsi yang mengecek apakah sandi sesuai untuk nama yang dimasukkan.
    int id = userId(nama);
    return (user[id].kata_sandi.TabWord == sandi.TabWord);
}

 int userId(Word nama) {
// Fungsi yang return ID dari user dengan nama (nama) atau -1 jika tidak ada/nama berupa string kosong.
    int i;
    if (nama.Length != 0) {
        for (i = 0 ; i < CounterUser; i++) {
            if (user[i].nama.Tabword == nama.TabWord) {
                return i;
            }
        }
    }
    return -1;
}


// PROFILE
void ganti_profile(){
// Mengganti profile
    Word bio, weton, inputHP;
    long long HP;

    showCurrentUser();

    // Update Bio.
    printf("Masukkan Bio Akun: \n");
    readWord(&bio, ';');
    while(!isBioValid(bio)) {
        printf("Bio tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan Bio Akun: \n");
        readWord(&bio, ';');
        printf("\n\n");
    }
    if (BIO(user[CurrentUserId]).Length != 0) {
        BIO(user[CurrentUserId]) = bio;
    }

    // Update No HP
    printf("Masukkan No HP: \n");
    readWord(&inputHP, ';');
    
    // HP = wordToInt(inputHP)
    while(!isHpValid(bio)) {
        if(inputHP.Length == 0) {
            break;
        }
        printf("Bio tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan Bio Akun: \n");
        readWord(&bio, ';');
        printf("\n\n");
    }
    if (BIO(user[CurrentUserId]).Length != 0) {
        BIO(user[CurrentUserId]) = bio;
    }
    
}

void lihat_profil(Word nama);
// Melihat profile akun dengan nama (nama).

void atur_jenis_akun();
// Mengubah jenis akun.

void ubah_foto_profil();
// Mengubah foto profil.

void showCurrentUser();
// I.S. Sudah login.
// F.S. Menampilkan informasi-informasi akun CurrentUserId.

boolean isBioValid(Word bio);
// fungsi yang mengecek apakah masukan bio valid.
// return boolean.

boolean isHpValid();
// fungsi yang mengecek apakah masukan nomor HP valid yaitu integer dengan panjang berapapun.
// return boolean.

boolean isWetonValid(weton);
// fungsi yang mengecek apakah masukan weton valid.
// return boolean.

boolean isPrivat(int id);
// Mengecek apakah akun dengan id (id) privat.

void showFotoProfil(int id);
// Menampilkan foto profil akun dengan id (id).

void readFotoProfil();
// I.S. Login.
// F.S. membaca masukan ubah foto profil akun CurrentUserId.

*/