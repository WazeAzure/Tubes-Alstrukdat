#ifndef _USER_h
#define _USER_h

#include "../Wordmachine/wordmachine.h"

typedef struct {
    Word bio;
    int hp;
    Word weton;
    boolean privacy;
    // adt matriks
} PROFILE;

typedef struct {
    int id;
    Word nama;
    Word kata_sandi;
    PROFILE profile;
    int jumlah_teman;
    // daftar permintaan pertemanan
    // daftar draft kicauan

} USER;

#endif