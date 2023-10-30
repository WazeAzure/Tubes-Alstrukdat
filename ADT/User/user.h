#ifndef _USER_h
#define _USER_h

#include "../Wordmachine/wordmachine.h"
#include "../boolean.h"

// ADT Symbol
typedef struct {
    char color; // [R,G,B]
    char ASCII;
} SYMBOL;

// ADT FOTO (FOTO)
typedef int IdxType; /* Index baris, kolom */
typedef SYMBOL ElType;
typedef struct {
   ElType mem[5][5];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} FOTO;

// ADT Profile
typedef struct {
    Word bio;
    int hp;
    Word weton;
    boolean privacy;
    // adt matriks
} PROFILE;

// ADT User
typedef struct {
    int id;
    Word nama;
    Word kata_sandi;
    PROFILE profile;
    int jumlah_teman;
    // daftar permintaan pertemanan
    // daftar draft kicauan

} USER;

// SELEKTOR
// SYMBOl
#define COLOR(s) (s).color
#define ASCII(s) (s).ASCII

// FOTO
#define ROW_EFF(F) (F).rowEff
#define COL_EFF(F) (F).colEff
#define ELMT(F, i, j) (F).mem[(i)][(j)]

// PROFILE
#define ID(u) (u).id
#define NAMA(u) (u).nama
#define SANDI(u) (u).sandi
#define JUMLAH_TEMAN(u) (u).jumlah_teman
#define PROFILE(u) (u).profile
// #define daftarteman
// #define draft kicauan

// USER
#define BIO(u) (u).profile.bio
#define HP(u) (u).profile.hp
#define WETON(u) (u).profile.weton
#define PRIVACY(u) (u).profile.privacy

// PRIMITIF ADT FOTO
void createFoto(int nRows, int nCols, FOTO *m);
/* Membentuk sebuah FOTO "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia FOTO" *** */
boolean isFotoIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(FOTO m);
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(FOTO m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(FOTO m, IdxType i, IdxType j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

/* ********** Assignment  FOTO ********** */
void copyFoto(FOTO mIn, FOTO *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readFoto(FOTO *m);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateFOTO(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */

void displayFoto(FOTO m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */


/* (BAKAL DI PINDAH KE FOLDER SECTION)
// Fungsi dan Prosedur
// PENGGUNA
void daftar();
//  Membaca nama pengguna baru dengan mesin kata.

void masuk();
// Membaca nama untuk login

void keluar();
// Logout jika sedang login

boolean isNamaValid(Word nama);
// Fungsi yang mengecek apakah nama yang dimasukkan belum terdaftar (valid);

boolean isSandiValid(Word nama, Word sandi);
// Fungsi yang mengecek apakah sandi sesuai untuk nama yang dimasukkan.

int userId(Word nama);
// Fungsi return ID dari user dengan nama (nama);

// PROFILE
void ganti_profile();
// Mengganti profile

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
#endif