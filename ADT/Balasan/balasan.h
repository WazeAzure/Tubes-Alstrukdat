#ifndef _BALASAN_h
#define _BALASAN_h

#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"

typedef struct 
{
    int id;
    Word isi;
    Word author;
    int idAuthor;
    DATETIME date;

} BALASAN;

/*--------- SELEKTOR--------*/
#define idBalasan(x) (x).id
#define isiBalasan(x) (x).isi
#define authorBalasan(x) (x).author
#define idAuthorBalasan(x) (x).idAuthor
#define dateBalasan(x) (x).date

#endif