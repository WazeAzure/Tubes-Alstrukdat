#include <stdio.h>
#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"
#include "../Linkedlist/listlinier.h"

#ifndef _UTAS_H
#define _UTAS_H

typedef struct {
    int index; // index dari 1,...
    Word utas;
    DATETIME time;
} UTAS;

typedef struct {
    int IDUtas; 
    Node child; 
} MAINUTAS;

void CreateUtas(UTAS *utas, int index, Word input, DATETIME time);

void ReadUtas(UTAS utas);

void CetakUtas(UTAS *utas);

void SambungUtas(int IDUtas,int index, UTAS *utas);

void HapusUtas(int IDUtas,int index, UTAS *utas); 

#endif