// #ifndef _BALASAN_h
// #define _BALASAN_h

// #include "../Wordmachine/wordmachine.h"
// #include "../Datetime/datetime.h"

// typedef struct 
// {
//     int id;
//     Word isi;
//     Word author;
//     int idAuthor;
//     DATETIME date;

// } BALASAN;

// /*--------- SELEKTOR--------*/
// #define idBalasan(x) (x).id
// #define isiBalasan(x) (x).isi
// #define authorBalasan(x) (x).author
// #define authorBalasan2(x) (x).idAuthor
// #define dateBalasan(x) (x).date

// #endif

#ifndef _BALASAN_h
#define _BALASAN_h

#include "../boolean.h"

#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"

#include "../Balasan/balasan.h"
#include "../Utas/utas.h"

typedef struct {
    int id;
    BALASAN *list_balasan;
} PairBalasan;

typedef struct {
    int idParent;
    int id;
    int like;
    int idAuthor;
    int inc_balasan;
    Word teks;
    Word Author;
    DATETIME timeCreated;

    // list of daftar balasan
    PairBalasan *daftar_balasan;

    // list of daftar utas
    UTAS *daftar_utas;
} BALASAN;

typedef struct {
    BALASAN* buffer;
    int NEFF;
    int CAPACITY;
} LISTBALASAN;

#define FIRST(l) (l)

void CreateListBalasan(LISTBALASAN* l, int CAPACITY);

// void CreateDaftarBalasan(BALASAN* BALASAN);

void CreateBalasan(BALASAN* balasan, int idParent, int idAuthor, Word Author, Word teks);

void balasan(Word Author);

void showBalasanContent(BALASAN balasan);

#endif