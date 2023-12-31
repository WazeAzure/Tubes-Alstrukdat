#ifndef _KICAUAN_h
#define _KICAUAN_h

#include "../boolean.h"

#include "../Wordmachine/wordmachine.h"
// #include "../Datetime/datetime.h"

// #include "../Balasan/balasan.h"
#include "../Utas/utas.h"
#include "../Balasan/pohontree.h"

typedef struct {
    int id;
    BALASAN *list_balasan;
} PairBalasan;

typedef struct {
    int id;
    int like;
    int idAuthor;
    int inc_balasan;
    Word teks;
    Word Author;
    DATETIME timeCreated;

    Word tagar;

    // list of daftar balasan
    Tree daftar_balasan;

    // list of daftar utas
    ListElemenUtas daftar_utas;
    
} KICAUAN;

typedef struct {
    KICAUAN* buffer;
    int NEFF;
    int CAPACITY;
} LISTKICAUAN;

/* SELEKTOR KICAUAN */
#define KICAU_ID(kicau) (kicau).id
#define LIKE(kicau) (kicau).like
#define KICAU_IDAUTHOR(kicau) (kicau).idAuthor
#define KICAU_INC_IDBALASAN(kicau) (kicau).inc_balasan
#define KICAU_TEKS(kicau) (kicau).teks
#define KICAU_NAMAAUTHOR(kicau) (kicau).Author
#define KICAU_TIMECREATED(kicau) (kicau).timeCreated
#define KICAU_DAFTAR_BALASAN(kicau) (kicau).daftar_balasan
#define KICAU_DAFTAR_UTAS(kicau) (kicau).daftar_utas

/* SELEKTOR LISTKICAUAN */
#define KICAUAN_NEFF(l) (l).NEFF
#define KICAUAN_CAPACITY(l) (l).CAPACITY
#define KICAUAN_BUFFER(l) (l).buffer
#define KICAUAN_ELMT(l, i) (l).buffer[(i)]

void CreateListKicauan(LISTKICAUAN* l, int CAPACITY);

void CreateDaftarBalasan(KICAUAN* kicauan);

KICAUAN* newKicau(Word teks, Word Author, Word tagar);

void CreateKicauan(KICAUAN* kicauan, int idAuthor, Word Author, Word teks, Word tagar);

boolean kicau(Word Author);

void showKicauanContent(KICAUAN kicauan);

void showAllListKicauan();

#endif