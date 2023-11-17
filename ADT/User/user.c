#include <stdio.h>

#include "user.h"
#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"
#include "../DaftarPertemanan/daftarpertemanan.h"
#include "../PermintaanPertemanan/permintaanpertemanan.h"

#include "../Datetime/time.c"
#include "../Datetime/datetime.c"

#include "../Draftkicauan/draftkicauan.c"
#include "../DaftarPertemanan/daftarpertemanan.c"
#include "../PermintaanPertemanan/permintaanpertemanan.c"

#include "../pcolor/pcolor.h"

#include "../../globalVar.h"

void createFoto(int nRows, int nCols, FOTO *m){
/* Membentuk sebuah FOTO "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk dan Set Default Foto */
    FOTO_ROW_EFF(*m) = nRows;
	FOTO_COL_EFF(*m) = nCols;

    // Set Default Foto
	IdxType i, j;
	for(i=0;i<nRows;i++){
		for(j=0;j<nCols;j++){
			COLOR(FOTO_ELMT(*m, i, j)) = 'R';
            ASCII(FOTO_ELMT(*m, i, j)) = '*';
		}
	}
}

/* *** Selektor "FOTO" *** */
boolean isFotoIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0 && i < 5 && j >=0 && j < 5);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(FOTO m){
/* Mengirimkan Index baris terbesar m */
    return FOTO_ROW_EFF(m) - 1;
}
IdxType getLastIdxCol(FOTO m){
/* Mengirimkan Index kolom terbesar m */
    return FOTO_COL_EFF(m) -1;
}
boolean isIdxEff(FOTO m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m));
}

/* ********** Assignment  FOTO ********** */
void copyFoto(FOTO mIn, FOTO *mOut){
/* Melakukan assignment mOut <- mIn */
    createFoto(FOTO_ROW_EFF(mIn), FOTO_COL_EFF(mIn), mOut);

	IdxType i=0, j=0;
	for(i=0; i<FOTO_ROW_EFF(mIn); i++){
		for(j=0; j<FOTO_COL_EFF(mIn); j++){
			FOTO_ELMT(*mOut, i, j) = FOTO_ELMT(mIn, i, j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
boolean isLineValid(Word line) {
// Mengecek apakah baris masukan foto valid atau tidak.
    if (line.Length != 19) {
        return false;
    } else {
        int i;
        for (i = 0; i < 10; i += 4) {
            if (line.TabWord[i] != 'R' && line.TabWord[i] != 'G' && line.TabWord[i] != 'B') {
                return false;
            }
        }
        return true;
    }
}

void setFotoProfil(FOTO* foto, char str[5][30]){
    /* Asumsi input sudah valid */
    int i;
    for(i=0; i<5; i++){
        int j;
        for(j=0; j<5; j++){
            COLOR(FOTO_ELMT(*foto, i, j)) = str[i][4*j];
            ASCII(FOTO_ELMT(*foto, i, j)) = str[i][4*j + 2];
        }
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
            if (i != 4){
                readWord(&line, '\n');
            } else {
                readWord(&line, ';');
            }

            // Cek apakah input baris valid
            if (!isLineValid(line)) {
                printf("Masukkan Tidak valid, coba lagi!\n\n");
                break;
            } else {
                for (j = 0; j < 5; j++) {
                    COLOR(FOTO_ELMT(temp, i, j)) = line.TabWord[4*j];
                    ASCII(FOTO_ELMT(temp, i, j)) = line.TabWord[4*j+2];
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
	for(i=0;i<FOTO_ROW_EFF(m);i++){
		for(j=0;j<FOTO_COL_EFF(m)-1;j++){
			if (COLOR(FOTO_ELMT(m, i, j)) == 'R') {
                print_red(ASCII(FOTO_ELMT(m, i, j)));
                printf(" ");
            } else if (COLOR(FOTO_ELMT(m, i, j)) == 'G') {
                print_green(ASCII(FOTO_ELMT(m, i, j)));
                printf(" ");
            } else if (COLOR(FOTO_ELMT(m, i, j)) == 'B') {
                print_blue(ASCII(FOTO_ELMT(m, i, j)));
                printf(" ");
            }
		}
        if (COLOR(FOTO_ELMT(m, i, FOTO_COL_EFF(m)-1)) == 'R') {
            print_red(ASCII(FOTO_ELMT(m, i, FOTO_COL_EFF(m)-1)));
            printf("\n");
        } else if (COLOR(FOTO_ELMT(m, i, FOTO_COL_EFF(m)-1)) == 'G') {
            print_green(ASCII(FOTO_ELMT(m, i, FOTO_COL_EFF(m)-1)));
            printf("\n");
        } else if (COLOR(FOTO_ELMT(m, i, FOTO_COL_EFF(m)-1)) == 'B') {
            print_blue(ASCII(FOTO_ELMT(m, i, FOTO_COL_EFF(m)-1)));
            printf("\n");
        }
	}
}


// Fungsi dan Prosedur

void toLowerCase(Word* input) {
// Mengubah input menjadi lowercase.
    int i;
    for (i = 0; i < input->Length; i++) {
        if (input->TabWord[i] >= 65 && input->TabWord[i] <= 95) {
            input->TabWord[i] += 32;
        }
    }
}

void showUser(int id){
// I.S. Sudah login.
// F.S. Menampilkan informasi-informasi akun CurrentUserId.
    printf(" | Nama\t\t: %s\n", USER_NAMA(USER(user, id)).TabWord);
    printf(" | Bio Akun\t: %s\n", BIO(USER(user, id)).TabWord);
    printf(" | No HP\t: %s\n", HP(USER(user, id)).TabWord);
    printf(" | Weton\t: %s\n", WETON(USER(user, id)).TabWord);
}

int userId(Word nama) {
// Fungsi yang return ID dari user dengan nama (nama) atau -1 jika tidak ada/nama berupa string kosong.
    int i;
    if (nama.Length != 0) {
        for (i = 0 ; i < COUNTER_USER(user); i++) {
            if (strCompare(USER(user, i).nama.TabWord, nama.TabWord)) {
                return i;
            }
        }
    }
    return -1;
}

boolean isNamaValid(Word nama){
// Fungsi yang mengecek apakah nama yang dimasukkan belum terdaftar (valid);
    int i;
    if (nama.Length == 0) return false;
    for (i = 0; i < COUNTER_USER(user); i++) {
        if (strCompare(nama.TabWord, USER(user, i).nama.TabWord)){
            return false;
        }
    }
    return true;
}

boolean isSandiValid(Word nama, Word sandi){
// Fungsi yang mengecek apakah sandi sesuai untuk nama yang dimasukkan.
    int id = userId(nama);
    return strCompare(USER(user, id).kata_sandi.TabWord, sandi.TabWord);
}

boolean isBioValid(Word bio){
// fungsi yang mengecek apakah masukan bio valid.
// return boolean.
    return bio.Length <= 135;
}

boolean isHpValid(NoHp hp){
// fungsi yang mengecek apakah masukan nomor HP valid yaitu integer dengan panjang berapapun.
// return boolean.
    if(hp.length == 0) return true;
    
    int i=0;
    while(hp.TabWord[i]){
        if(hp.TabWord[i] - '0' > 9 || hp.TabWord[i] - '0' < 0) return false;
        i++;
    }
    return true;
}

boolean isWetonValid(Word weton){
// fungsi yang mengecek apakah masukan weton valid.
// return boolean.
    if (weton.Length == 0) {
        return true;
    } else {
        char listWeton[5][7] = {"pahing", "kliwon", "wage", "pon", "legi"};
        int i;
        for (i = 0; i < 5; i++) {
            if (strCompare(weton.TabWord, listWeton[i])) {
                return true;
            }
        }
        return false;
    }
}

void createListUser(ListUser * u) {
// Inisialisasi ListUser, membentuk List user dengan tiap id user = index dan jumlah teman = 0.
    int i;
    PERMINTAANPERTEMANAN Q;
    CreateEmptyPermintaanPertemanan(&Q);
    for (i = 0; i < 20; i++) {
        USER_ID(USER(*u, i)) = i;
        JUMLAH_TEMAN(USER(*u, i)) = 0;
        DraftKicauanCreateEmpty(&USER(*u, i).draftKicauan);
        createFoto(5, 5, &FOTO(USER(*u, i)));
    }
}

void addUser(ListUser * u, Word nama, Word sandi){
// menambahkan user ke list u.
    USER_NAMA(USER(*u, COUNTER_USER(*u))) = nama;
    SANDI(USER(*u, COUNTER_USER(*u))) = sandi;
    COUNTER_USER(*u)++;
}

void setProfil(ListUser * u, int index, Word bio, NoHp hp, Word weton, boolean privacy, FOTO foto){
// Set profil User dengan id index berdasarkan input bio, hp, weton, privacy, dan foto.
    BIO(USER(*u, index)) = bio;
    HP(USER(*u, index)) = hp;
    WETON(USER(*u, index)) = weton;
    PRIVACY(USER(*u, index)) = privacy;
    FOTO(USER(*u, index)) = foto;
}

// Fungsi dan Prosedur
// PENGGUNA
void daftar(){
//  Membaca nama pengguna baru dengan mesin kata.
    if (COUNTER_USER(user) < 20){ // Cek apakah jumlah pengguna maximum.
        Word nama, sandi;
        
        // membaca nama pengguna baru
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
        addUser(&user, nama, sandi);

        // Sukses daftar
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");

    } else { // Daftar gagal.
        printf("Jumlah pengguna sudah melebihi batas");
    }
}

void masuk(){
// Membaca nama untuk login

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
    
}

void keluar(){
// Logout jika sedang login
    CurrentUserId = -1;
    printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
}


// PROFILE
void ganti_profile(){
// Mengganti profile
    Word bio, weton;
    NoHp inputHP;

    showUser(CurrentUserId);
    printf("\n\n");

    // Update Bio.
    printf("Masukkan Bio Akun: \n");
    readWord(&bio, ';');
    while(!isBioValid(bio)) {
        printf("Bio tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan Bio Akun: \n");
        readWord(&bio, ';');
        printf("\n\n");
    }
    if (bio.Length != 0) {
        BIO(USER(user, CurrentUserId)) = bio;
    }

    // Update No HP
    printf("Masukkan No HP: \n");
    readHP(&inputHP, ';');

    while(!isHpValid(inputHP)) {
        printf("HP tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan HP Akun: \n");
        readHP(&inputHP, ';');
        printf("\n\n");
    }
    if (inputHP.length > 0) { // Update jika tidak Word Kosong.
        HP(USER(user, CurrentUserId)) = inputHP;
    }

    // Update Weton
    printf("Masukkan Weton: \n");
    readWord(&weton, ';');
    toLowerCase(&weton);
    while(!isWetonValid(weton)) {
        printf("Weton anda tidak valid.\n\n");
        printf("Masukkan Weton: \n");
        readWord(&weton, ';');
        toLowerCase(&weton);
        printf("\n\n");
    }
    if (weton.Length != 0) {
        WETON(USER(user, CurrentUserId)) = weton;
    }
    
    // Pesan Berhasil
    printf("Profil Anda sudah berhasil diperbarui!\n\n");
}

void lihat_profil(Word nama){
    // Melihat profile akun dengan nama (nama) jika akun publik.

    // Cek apakah nama terdaftar.
    if (isNamaValid(nama) || nama.Length == 0) {
        printf("Nama tidak terdaftar! Cek kembali nama.\n\n");
        return;
    } else { // Nama terdaftar
        int id = userId(nama);
        if (PRIVACY(USER(user, id)) && !isTeman(CurrentUserId, id)) {
            printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n\n", nama.TabWord, nama.TabWord);
        } else {
            showUser(id);
            printf("\n\n");
            printf("Foto profil: \n");
            showFotoProfil(id);
            printf("\n\n");
        }
    }

}

void atur_jenis_akun(){
// Mengubah jenis akun.
    if (PRIVACY(USER(user, CurrentUserId))) {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik?\n");
    } else {
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat?\n");
    }
    char YATIDAK[2][6] = {"ya", "tidak"};
    printf("(YA/TIDAK) ");
    Word pilihan;
    readWord(&pilihan, ';');
    toLowerCase(&pilihan);
    printf("\n\n");
    while (!strCompare(pilihan.TabWord, YATIDAK[0]) && !strCompare(pilihan.TabWord, YATIDAK[1])) {
        printf("Masukkan Salah! (YA/TIDAK) ");
        readWord(&pilihan, ';');
        toLowerCase(&pilihan);
        printf("\n\n");
    }

    // Jika Ya, Ganti.
    if (strCompare(pilihan.TabWord, YATIDAK[0])) {
        PRIVACY(USER(user, CurrentUserId)) = !PRIVACY(USER(user, CurrentUserId));
        if (PRIVACY(USER(user, CurrentUserId))) { // Akun menjadi privat
            printf("Akun anda sudah diubah menjadi akun Privat.\n\n");
        } else { // Akun menjadi publik
            printf("Akun anda sudah diubah menjadi akun Publik.\n\n");
        }
    } else { // Pilihan Tidak.
        printf("Proses dibatalkan, pengaturan privasi tidak diubah.\n\n");
    }
}

void ubah_foto_profil(){
// Mengubah foto profil.
    printf("Foto profil Anda saat ini adalah\n");
    showFotoProfil(CurrentUserId);
    printf("\n\n");
    printf("Masukkan foto profil yang baru\n");
    readFoto(&FOTO(USER(user,CurrentUserId)));
    printf("\n\n");
    printf("Foto profil anda sudah berhasil diganti!\n\n");
}

boolean isPrivat(int id){
// Mengecek apakah akun dengan id (id) privat.
    return PRIVACY(USER(user, id));
}

void showFotoProfil(int id){
// Menampilkan foto profil akun dengan id (id).
    displayFoto(FOTO(USER(user, id)));
}

// Bagian Teman dan Daftar Pertemanan
void cariTeman(Word* Input,int id){
    int i = 0;
    for(int j = 0; j < 20; j++){
        if(ElmtDaftarPertemanan(DaftarPertemanan,j,id) == true && j != id){
            *(Input + i) =  USER_NAMA(USER(user,j));
            i++;
        }
    }
}

void showDaftarTeman(int id){
    if(JUMLAH_TEMAN(USER(user,id)) == 0){
        printf("%s belum mempunyai teman\n\n",USER_NAMA(USER(user,id)).TabWord);
    } else{
        printf("%s memiliki %d teman\n",USER_NAMA(USER(user,id)).TabWord,JUMLAH_TEMAN(USER(user,id)));
        printf("Daftar teman %s\n",USER_NAMA(USER(user,id)).TabWord);
        Word ListTeman[20];
        cariTeman(ListTeman,id);
        for(int i = 0; i < JUMLAH_TEMAN(USER(user,id)); i++){
            printf("| %s\n",ListTeman[i].TabWord);
        }
    }
}


boolean isTeman(int idUser, int idTeman){
    if(idTeman == -1){ // Nama teman tidak ada di semua item list user
        return false;
    }
    if(ElmtDaftarPertemanan(DaftarPertemanan, idUser, idTeman) == 1){
        return true;
    } else{
        return false;
    }
}   

void hapusTeman(int idUser){
    Word namaTeman, konfirmasi;
    printf("Masukkan nama pengguna:\n");
    readWord(&namaTeman, ';');
    int idTeman = userId(namaTeman);
    if(isTeman(idUser, idTeman)){
        printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda?(YA/TIDAK)\n\n", namaTeman.TabWord);
        readWord(&konfirmasi, ';');
        if(strCompare(konfirmasi.TabWord, "YA")){
            setSymmetricElmt(&DaftarPertemanan, idUser, idTeman, false);
            JUMLAH_TEMAN(USER(user,idUser))--;
            JUMLAH_TEMAN(USER(user,idTeman))--;
        }else{
            printf("Penghapusan teman dibatalkan.\n\n");
        }
    } else{
        printf("%s bukan teman Anda.\n\n",namaTeman.TabWord);
    }
}


void tambahTeman(int idUser){
    Word namaTeman;
    printf("Masukkan nama pengguna:\n");
    readWord(&namaTeman, ';');
    int idTeman = userId(namaTeman);
    if(idTeman == -1){
        printf("Pengguna bernama %s tidak ditemukan.\n\n",namaTeman.TabWord);
    } else if(isTeman(idUser,idTeman)){
        printf("Anda sudah berteman dengan %s.\n\n",USER_NAMA(USER(user,idTeman)).TabWord);
    } else{
        infotype X;
        X.id = USER_ID(USER(user,idUser));
        X.nama = USER_NAMA(USER(user,idUser));
        X.jumlahTeman = JUMLAH_TEMAN(USER(user,idUser));
        // prinf("%d %s %d",X.id, X.nama.TabWord, X.jumlahTeman);
        EnqueuePermintaanPertemanan(&PERMINTAANPERTEMANAN(USER(user,idTeman)), X); ;
        printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n\n",USER_NAMA(USER(user,idTeman)).TabWord);

    }
}

void showDaftarPermintaanPertemanan(int idUser){
    if(!IsEmptyPermintaanPertemanan(PERMINTAANPERTEMANAN(USER(user,idUser)))){
        int jumlah_permintaan_pertemanan = JumlahPermintaanPertemanan(PERMINTAANPERTEMANAN(USER(user,idUser)));
        if(jumlah_permintaan_pertemanan != 0){
            printf("Terdapat %d permintaan pertemanan untuk Anda.\n", jumlah_permintaan_pertemanan);
        }
            PrintPermintaanPertemanan(PERMINTAANPERTEMANAN(USER(user,idUser)));
    } else{
        printf("Tidak ada permintaan pertemanan :(\n\n");
    }
}

void setujuiPermintaanPertemanan(int idUser){
    if(!IsEmptyPermintaanPertemanan(PERMINTAANPERTEMANAN(USER(user,idUser)))){
        PrintPermintaanPertemananPertama(PERMINTAANPERTEMANAN(USER(user,idUser)));
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) \n");
        Word konfirmasi;
        readWord(&konfirmasi, ';');
        infotype X;
        if(strCompare(konfirmasi.TabWord, "YA")){
            DequeuePermintaanPertemanan(&PERMINTAANPERTEMANAN(USER(user,idUser)),&X);
            setSymmetricElmt(&DaftarPertemanan,idUser,X.id,true);
            JUMLAH_TEMAN(USER(user,idUser))++;
            JUMLAH_TEMAN(USER(user,X.id))++;
            printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n\n",X.nama.TabWord,X.nama.TabWord);
        } else{
            DequeuePermintaanPertemanan(&PERMINTAANPERTEMANAN(USER(user,idUser)),&X);
            printf("Permintaan pertemanan dari %s telah ditolak.\n\n",X.nama.TabWord);
        }
    } else{
        printf("Tidak ada permintaan pertemanan :(\n\n");
    }
}
