#ifndef _KICAUAN_h
#define _KICAUAN_h

#include "../boolean.h"

#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"

#include "../Balasan/balasan.h"
#include "../Utas/utas.h"

typedef struct {
    int id;
    BALASAN *list_balasan;
} PairBalasan;

typedef struct nodeKicauan* AddressKicauan;

typedef struct nodeKicauan{
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

    AddressKicauan next;
} KICAUAN;

#define FIRST(l) (l)

void CreateDaftarBalasan(KICAUAN* kicauan);

void CreateKicauan(KICAUAN* kicauan, int idAuthor, Word Author, Word teks);

void showKicauanContent(KICAUAN kicauan);

#endif