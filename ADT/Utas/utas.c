#include "utas.h"
#include "../../globalVar.h"
#include "../../util.h"


void CreateListIdUtas(LISTIDUTAS* ListIdUtas, int CAPACITY){
    LISTIDUTAS_CAPACITY(*ListIdUtas) = CAPACITY;
    nEFF(*ListIdUtas) = 0;
    LISTIDUTAS_BUFFER(*ListIdUtas) = (int*) malloc(sizeof(int) * CAPACITY);
}

void dealocateListIdUtas(LISTIDUTAS *ListIdUtas){
    nEFF(*ListIdUtas) = 0;
    LISTIDUTAS_CAPACITY(*ListIdUtas) = 0;
    free(LISTIDUTAS_BUFFER(*ListIdUtas));
}


void ExpandListIdUtas(LISTIDUTAS* ListIdUtas){
    int add = 10 + ListIdUtas->CAPACITY;

    LISTIDUTAS l2;
    CreateListIdUtas(&l2, add);
    l2.nEFF = ListIdUtas->nEFF;

    for(int i=0; i<l2.nEFF; i++){
        l2.buffer[i] = ListIdUtas->buffer[i];
    }
    dealocateListIdUtas(ListIdUtas);
    *ListIdUtas = l2;
}


AddressUtas newUtas(Word teks){

    AddressUtas new = (AddressUtas)malloc(sizeof(NodeElemenUtas));

    if(new != NULL) {
        new->next = NULL;
        new->teks = teks;
        long long int current_time = getCurrentTime();
        new->author = user.user[CurrentUserId].nama;
        new->timeCreated = (DetikToDATETIME(current_time));
    } else {
        printf("Alokasi Gagal!\n");
    }
    return new;
}


void CreateListElementUtas(ListElemenUtas *daftarUtas){
    FIRSTDAFTARUTAS(*daftarUtas) = NULL;
}

boolean isEmptyDaftarUtas(ListElemenUtas daftarUtas){
    return(FIRSTDAFTARUTAS(daftarUtas)==NULL);
}

boolean isEmptyListIdUtas(LISTIDUTAS li){
    return (nEFF(li)==0);
}

int lengthDaftarUtas(ListElemenUtas daftarUtas){
// Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong
    int length=0;
    AddressUtas p;
    p = FIRSTDAFTARUTAS(daftarUtas);
    while(p!=NULL){
        length +=1;
        p = NEXTDAFTARUTAS(p);
    }
    return(length);
}

int lengthDaftarIdUtas(LISTIDUTAS li){
// Mengembalikan banyak elemen dalam DaftarIdUtas global
    return nEFF(li);
}

IdxType getLastIdx(LISTIDUTAS li){
    return (IdxType)(lengthDaftarIdUtas(li)-1);
}

boolean isUtas(int idkicau){
// Mengecek apakah ada idkicau di LISTIDUTAS, pake indexof listdin, mengembalikan true jika ada
    int i;
    for(i=0; i<ListIdUtas.nEFF; i++){
        if(UTAS_ELMT(ListIdUtas, i) == idkicau){
            return true;
        }
    }
    return false;
}

void insertLastIdUtas(LISTIDUTAS *ListIdUtas, int val){
    if ((*ListIdUtas).nEFF == (*ListIdUtas).CAPACITY) {
        ExpandListIdUtas(ListIdUtas);
    }
    UTAS_ELMT(*ListIdUtas,nEFF(*ListIdUtas)) = val;
    nEFF(*ListIdUtas)++;
}



void insertFirstDaftarUtas(ListElemenUtas *daftarUtas, Word teks){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    // KAMUS
    AddressUtas p;
    // ALGORITMA
    p = newUtas(teks);
    if (p != NULL) {
        if(isEmptyDaftarUtas(*daftarUtas)){
            NEXTDAFTARUTAS(p)=NULL;
        }else{
            NEXTDAFTARUTAS(p)= FIRSTDAFTARUTAS(*daftarUtas); 
        }    
        FIRSTDAFTARUTAS(*daftarUtas) = p;
    }
}

void insertLastDaftarUtas(ListElemenUtas *daftarUtas,Word teks, int idkicau){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // KAMUS
    AddressUtas p,last;
    // ALGORTMA
    p = newUtas(teks);
    if (p != NULL){
        if(isEmptyDaftarUtas(*daftarUtas)){
            insertFirstDaftarUtas(daftarUtas, teks);
        } else{
            // printf("MASUK\n");
            last = FIRSTDAFTARUTAS(*daftarUtas);
            if (p!=NULL){
                while(NEXTDAFTARUTAS(last)!=NULL){
                    // printf("jalan2");
                    last = NEXTDAFTARUTAS(last);
                }
                NEXTDAFTARUTAS(last) = p;
                // printf("BERES\n");
            }
        }
    }
}

void deleteFirstDaftarUtas(ListElemenUtas *daftarutas){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-free */
    // KAMUS
    AddressUtas p;
    // ALGORITMA
    p = FIRSTDAFTARUTAS(*daftarutas);
    FIRSTDAFTARUTAS(*daftarutas) = NEXTDAFTARUTAS(p); 
    free(p);
}

void utas(int idKicau){
    boolean access = false;
    
    if(idKicau>0 && idKicau<=ListKicauan.NEFF){
        idKicau = idKicau-1;
        if(ListKicauan.buffer[idKicau].idAuthor == CurrentUserId){
            access = true;
        }else {
            printf("Utas ini bukan milik Anda\n\n");
            return;
        }
    }else{
        printf("Kicauan tidak ditemukan.\n\n");
        return;
    }
    if (isUtas(idKicau)){
        printf("Kicauan sudah pernah diutas!\n\n");
        return;
    }

    if (access){
        printf("Utas berhasil dibuat!\n");
        Word teks;
        printf("Masukkan kicauan: \n");
        do{
            readWord(&teks,';');
        }while(teks.Length == 0);
        printf("\n");

        
        insertLastIdUtas(&ListIdUtas, idKicau);
        insertLastDaftarUtas(&KICAU_DAFTAR_UTAS(KICAUAN_ELMT(ListKicauan, idKicau)),teks, idKicau);

        boolean stop;
        printf("Apakah Anda ingin melanjutkan utas ini?(YA/TIDAK) ");
            Word pilihan;
            readWord(&pilihan, ';');
            toLowerCase(&pilihan);
            printf("\n");
            while (!strCompare(pilihan.TabWord, "ya") && !strCompare(pilihan.TabWord, "tidak")) {
                printf("Masukkan salah!(YA/TIDAK) ");
                readWord(&pilihan, ';');
                toLowerCase(&pilihan);
                printf("\n");
            }
            if (strCompare(pilihan.TabWord, "ya")) {
                stop = false;
            } else {
                stop = true;
            }
        while (!stop){
            printf("Masukkan kicauan: \n");
            do{
                readWord(&teks,';');
            } while (teks.Length == 0);
            printf("\n");
            insertLastDaftarUtas(&KICAU_DAFTAR_UTAS(KICAUAN_ELMT(ListKicauan, idKicau)),teks, idKicau);
            printf("Apakah Anda ingin melanjutkan utas ini?(YA/TIDAK) ");
            readWord(&pilihan, ';');
            toLowerCase(&pilihan);
            printf("\n");
            while (!strCompare(pilihan.TabWord, "ya") && !strCompare(pilihan.TabWord, "tidak")) {
                printf("Apakah Anda ingin melanjutkan utas ini?(YA/TIDAK) ");
                readWord(&pilihan, ';');
                toLowerCase(&pilihan);
                printf("\n");
            }
            if (strCompare(pilihan.TabWord, "ya")) {
                stop = false;
            } else {
                stop = true;
            }
        }
    } 
    printf("Utas selesai!\n\n");
}

AddressUtas cariAddress(ListElemenUtas *addressUtas,int  index){
    int i = 0; // 0 / 1
    AddressUtas P = FIRSTDAFTARUTAS(*addressUtas);
    while(i < index){
        P = NEXTDAFTARUTAS(P);
        i++;
    }
    return P;
}

void insertAtDaftarUtas(ListElemenUtas *daftarUtas, Word teks, int index){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    int ctr;
    AddressUtas p,loc;
    if(index == 0){
        insertFirstDaftarUtas(daftarUtas, teks);
    }else{
        p  = newUtas(teks);
        if(p != NULL){
            ctr =0;
            loc = FIRSTDAFTARUTAS(*daftarUtas);
            while(ctr<index-1){
                ctr+=1;
                loc = NEXTDAFTARUTAS(loc);
            }
            NEXTDAFTARUTAS(p)=NEXTDAFTARUTAS(loc);
            NEXTDAFTARUTAS(loc)=p;
        }
    }
}

void sambung_utas(Word idUtas,Word index){
/* Pakai insertAt yang ada di listlinier  */
    int Index, IdUtas;
    Index = WordToInt(index);
    IdUtas = WordToInt(idUtas);

    // Cek apakah IdUtas valid
    if(nEFF(ListIdUtas)<IdUtas  || IdUtas < 1){
        printf("Utas tidak ditemukan.\n\n");
        return;
    }
    KICAUAN *K;
    K = &KICAUAN_ELMT(ListKicauan, ListIdUtas.buffer[IdUtas-1]);

    ListElemenUtas *currentUtas;
    currentUtas = &KICAU_DAFTAR_UTAS(*K);
    
    if(userId(K->Author) != CurrentUserId){
        printf("Anda tidak bisa menyambung utas ini.\n\n");
        return;
    }else if (Index < 1){
        printf("Index tidak valid.\n\n");
        return;
    }else if(Index-1 > lengthDaftarUtas(*currentUtas)){
        printf("%d %d\n", Index, lengthDaftarUtas(*currentUtas));
        printf("Index terlalu tinggi.\n\n");
        return;
    }else{
        Word teks;
        printf("Masukkan kicauan:\n");
        do{
            readWord(&teks,';');
        }while(teks.Length == 0);
        if(Index == 1){
            insertFirstDaftarUtas(currentUtas,teks);
            KICAU_DAFTAR_UTAS(*K) = *currentUtas;
        }else{
            insertAtDaftarUtas(currentUtas, teks, Index-1);
        }
        printf("\n\n");
    }
}

void deleteAtUtas(ListElemenUtas *daftarUtas, int index){
    AddressUtas p, indexnext;
    p = FIRSTDAFTARUTAS(*daftarUtas);
    if (index==0){
        deleteFirstDaftarUtas(daftarUtas);
    }
    else{
        int count=0;
        indexnext= FIRSTDAFTARUTAS(*daftarUtas);
        while (count!=index-1){
            count++;
            indexnext = NEXTDAFTARUTAS(indexnext);
        }
        p = NEXTDAFTARUTAS(indexnext);
        NEXTDAFTARUTAS(indexnext) = NEXTDAFTARUTAS(p);
        free(p);
        
    }

}

void hapus_utas(Word Index, Word idutas){
// hapus utas idutas index
    int index = WordToInt(Index);
    int idUtas = WordToInt(idutas)-1;
    ListElemenUtas *daftarUtas;
    daftarUtas = &KICAU_DAFTAR_UTAS(KICAUAN_ELMT(ListKicauan, ListIdUtas.buffer[idUtas]));
    if(userId((*daftarUtas)->author) != CurrentUserId){
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n\n");
        return;
    }
    else if(index ==0){
        printf("Anda tidak bisa menghapus kicauan utama!\n\n");
        return;
    }
    else if(idUtas>=lengthDaftarIdUtas(ListIdUtas)){
        printf("Utas tidak ditemukan!\n\n");
        return;
    }else if(index>lengthDaftarUtas(*daftarUtas)){
        printf("Kicauan Sambungan dengan index %d tidak ditemukan pada utas!\n\n",index);
        return;
    }else{
        if(index == 1){
            deleteFirstDaftarUtas(daftarUtas);
        }else{
            deleteAtUtas(daftarUtas, index-1);
        }
        printf("Kicauan sambungan berhasil dihapus!\n\n");
    }
}


// CETAK UTAS DI KICAUAN AJA YA
void cetak_utas(int id_utas){
    // Mencetak keseluruhan utas 
    id_utas = id_utas-1;
   
    KICAUAN kicauan = ListKicauan.buffer[ListIdUtas.buffer[id_utas]];
    if(PRIVACY(USER(user, kicauan.idAuthor)) && !isTeman(CurrentUserId, kicauan.idAuthor)){
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n\n");
        return;
    }else if(id_utas < 0 || id_utas>=ListIdUtas.nEFF){
        printf("Utas tidak ditemukan.\n\n");
        return;
    }else{
        printf("| ID = %d\n", kicauan.id+1);
        printf("| %s\n", kicauan.Author.TabWord);
        printf("| ");
        TulisDATETIME(kicauan.timeCreated);
        printf("\n");
        printf("| %s\n", kicauan.teks.TabWord);
        printf("\n");
        AddressUtas p;
        p = kicauan.daftar_utas;
        
        int index = 1;
        // mencetak item utas dengan index utas index.
        while(p!=NULL){
            printf("\t| INDEX = %d\n", index);
            printf("\t| %s\n", kicauan.Author.TabWord);
            printf("\t| ");
            TulisDATETIME(p->timeCreated);
            printf("\n");
            printf("\t| %s\n", p->teks.TabWord);
            printf("\n");
            index++;
            p = NEXTDAFTARUTAS(p);
        }

    }
}