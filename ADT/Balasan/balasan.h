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

#endif