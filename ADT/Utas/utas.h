#include <stdio.h>
#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"
#include "../Linkedlist/listlinier.h"
#include "../Listdin/listdin.h"


#ifndef _UTAS_H
#define _UTAS_H

typedef struct {
    int index; // index dari 1,... //
    Word utasan;
    DATETIME time;
    int idkicau;
} UTAS;



// SELEKTOR //
// UTAS
#define INDEX(u) (u).index
#define INPUT(u) (u).utasan
#define TIME(u) (u).time

// MAINUTAS
#define ID_KICAUAN(m) (m).idkicau
#define ID_UTAS(m) (m).idutas

// void CreateMainUtas(MAINUTAS *parent, int idkicau, int idutas, ListDin child , int *CounterKicauan);
// F.S Utas berhasil dibuat

// void CetakMainUtas(MAINUTAS parent, int idkicau,int *CounterKicauan, int idutas);
// I.S idutas, idkicau, parent valid
//  Mendisplay mainutas beserta isi utasnya

void CreateUtas(UTAS *utas, int index, Word utasan, DATETIME time, int idutas);

void ReadUtas(UTAS *utas);

void CetakUtas(UTAS utas);
// search apakah ada 
void SambungUtas(int idutas,int index, UTAS *utas);

void HapusUtas(int idutas,int index, UTAS *utas); 

// createmainutas du
#endif