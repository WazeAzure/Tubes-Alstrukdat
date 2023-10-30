#include <stdio.h>
#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"
#include "../Linkedlist/listlinier.h"

#ifndef _UTAS_H
#define _UTAS_H

typedef struct {
    int index; // index dari 1,...
    Word utasan;
    DATETIME time;
    MAINUTAS parent;
} UTAS;

typedef struct {
    int idkicau;
    int idutas; 
    Node child; 
} MAINUTAS;

// SELEKTOR //
// UTAS
#define INDEX(u) (u).index
#define INPUT(u) (u).utasan
#define TIME(u) (u).time

// MAINUTAS
#define ID_KICAUAN(m) (m).idkicau
#define ID_UTAS(m) (m).idutas

void CreateMainUtas(MAINUTAS *parent, int idkicau, int idutas, Node child);

void CetakMainUtas(MAINUTAS parent);

void CreateUtas(UTAS *utas, int index, Word utasan, DATETIME time, MAINUTAS parent);

void ReadUtas(UTAS *utas);

void CetakUtas(UTAS utas);

void SambungUtas(int idutas,int index, UTAS *utas);

void HapusUtas(int idutas,int index, UTAS *utas); 


#endif