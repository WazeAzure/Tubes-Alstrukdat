#include "utas.h"
#include "../../globalVar.h"
#include "../../util.h"

AddressUtas newUtas(Word teks){

    AddressUtas new = (AddressUtas)malloc(sizeof(ListElemenUtas));

    if(new != NULL) {
        new->next = NULL;
        new->teks = teks;
        long long int current_time = getCurrentTime();
        new->timeCreated = (DetikToDATETIME(current_time));
    }
    return new;
}


void CreateListElementUtas(ListElemenUtas *daftarUtas){
    FIRSTDAFTARUTAS(*daftarUtas) = NULL;
}

void CreateListIdUtas(LISTIDUTAS* li, int CAPACITY){
// inisialisasi UTAS, membentuk listdin dari utas 
    li->buffer = (int*)malloc(sizeof(int) * CAPACITY);
    li->CAPACITY = CAPACITY;
    li->nEFF = 0;
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

boolean isUtas(Word idKicau){
// Mengecek apakah ada idkicau di LISTIDUTAS, pake indexof listdin, mengembalikan true jika ada
    // IdxType i, index;
    // index = IDX_UNDEF;
    // i =0;
    // boolean check = false;

    // while(i<=getLastIdx(li) && check == false){
    //     if(ELMT(li,i) == idKicau){
    //         check = true;
    //     }
    //     i++;
    // }
    // return check;
   
    int idkicau = WordToInt(idKicau);
    int i;
    for(i=0; i<ListIdUtas.nEFF; i++){
        if(UTAS_ELMT(ListIdUtas, i) == idkicau){
            return true;
        }
    }
    return false;
}
void insertLastIdUtas(LISTIDUTAS *ListIdUtas, int val){

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
    if(isEmptyDaftarUtas(*daftarUtas)){
        NEXTDAFTARUTAS(p)=NULL;
    }else{
        NEXTDAFTARUTAS(p)= FIRSTDAFTARUTAS(*daftarUtas); 
    }    
    FIRSTDAFTARUTAS(*daftarUtas) = p;
}

void insertLastDaftarUtas(ListElemenUtas *daftarUtas,Word teks, int idkicau){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // KAMUS
    AddressUtas p,last;
    // AddressUtas* new = newUtas(teks);
    // ALGORTMA
    p = newUtas(teks);
    last = FIRSTDAFTARUTAS(*daftarUtas);
    if(p == NULL) return ;

    if ( p != NULL){
        if(isEmptyDaftarUtas(*daftarUtas)){
            FIRSTDAFTARUTAS(*daftarUtas) = p;
        }else{
            while(NEXTDAFTARUTAS(last)!=NULL){
                last = NEXTDAFTARUTAS(last);
            }
            NEXTDAFTARUTAS(last) = p;
        }
    }
    ListIdUtas.buffer[ListIdUtas.nEFF]=idkicau;
    ListIdUtas.nEFF++;
}

void deleteFirstDaftarUtas(ListElemenUtas *daftarutas,Word *teks,Word index){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-free */
    // KAMUS
    AddressUtas p;
    int Index;
    // ALGORITMA
    Index = WordToInt(index);
    if(Index == 1){
        p = FIRSTDAFTARUTAS(*daftarutas);
        *teks = TEKSUTAS(p);
        long long int current_time = getCurrentTime();
        p->timeCreated = (DetikToDATETIME(current_time));
        FIRSTDAFTARUTAS(*daftarutas) = NEXTDAFTARUTAS(p); 
        free(p);
    }
}

void utas(int idKicau){
    boolean access = false;
    if(idKicau>0 && idKicau<ListKicauan.NEFF){
        if(ListKicauan.buffer[idKicau].idAuthor == CurrentUserId){
            access = true;
        }else {
            printf("Utas bukan milik Anda\n\n");
        }
    }else{
        printf("Kicauan tidak ditemukan.\n\n");
    }

    if (access){
        // KICAUAN* k;
        //  WordToInt(idKicau)
        // *k = KICAUAN_ELMT(ListKicauan ,KICAUAN_ELMT(ListIdUtas, idKicau));
        // insertLastIdUtas(k->daftar_utas, idKicau);

        printf("Utas berhasil dibuat!\n");
        Word teks;
        printf("Masukkan kicauan\n");
        do{
            readWord(&teks,';');
        }while(teks.Length == 0);
        printf("\n\n");

        AddressUtas daftarUtas = newUtas(teks); // inisialisasi utas
        insertLastDaftarUtas(&daftarUtas,teks, idKicau);

        printf("Apakah Anda ingin melanjutkan utas ini?(YA/TIDAK)");
        Word val;
        readWord(&val, ';');
        boolean stop;
        if(strCompare(val.TabWord, "YA")){
            stop = true;
        }else{
            stop = false;
        }
        do{
            Word teks;
            printf("Masukkan kicauan\n");
            while(teks.Length == 0){
                printf("Masukkan tidak boleh kosong!\n");
                readWord(&teks,';');
                // daftarUtas = newUtas(teks, getCurrentTime());
                
                // ???
            }while(teks.Length == 0);
            printf("Apakah Anda ingin melanjutkan utas ini?");
        }while((!stop));
    } 
    printf("\n\n");
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

void sambung_utas(Word index, ListElemenUtas *daftarUtas, Word idUtas){
/* Pakai insertAt yang ada di listlinier  */
    int Index, IdUtas;
    Index = WordToInt(index);
    IdUtas = WordToInt(idUtas);
    if(nEFF(ListIdUtas)>IdUtas){
        printf("Utas tidak ditemukan.\n\n");
        return;
    }
    //
    //userId((KICAUAN_ELMT(ListIdUtas,idUtas)).Author
    else if(userId((cariAddress(daftarUtas,Index))->author) != CurrentUserId){
        printf("Anda tidak bisa menyambung utas ini.\n\n");
        return;
    }else if(lengthDaftarUtas(*daftarUtas)<Index){
        printf("Index terlalu tinggi.\n\n");
        return;
    }else{
        Word teks;
        printf("Masukkan kicauan.\n");
        do{
            readWord(&teks,';');
            int ctr;
            AddressUtas p,loc;
            if(Index == 1){
                insertFirstDaftarUtas(daftarUtas,teks);
                return;
            }else{
                p  = newUtas(teks);
                if(p != NULL){
                    ctr =0;
                    loc = FIRSTDAFTARUTAS(*daftarUtas);
                    while(ctr<Index-1){
                        ctr+=1;
                        loc = NEXTDAFTARUTAS(loc);
                    }
                    NEXTDAFTARUTAS(p)=NEXTDAFTARUTAS(loc);
                    NEXTDAFTARUTAS(loc)=p;
                }
            }
        }while(teks.Length == 0);
        printf("\n\n");
    }
}


void hapus_utas(Word Index,LISTIDUTAS li, Word idutas, ListElemenUtas *daftarUtas, Word *teks){
// hapus utas idutas index
    int index = WordToInt(Index);
    int idUtas = WordToInt(idutas);
    if(userId((cariAddress(daftarUtas,index))->author) != CurrentUserId){
        printf("Anda tidak bisa menghapus kicauan dalam utas ini.\n\n");
        return;
    }else if(index ==0){
        printf("Anda tidak bisa menghapus kicauan utama\n\n");
        return;
    }else if(idUtas>lengthDaftarIdUtas(li)){
        printf("Utas tidak ditemukan.\n\n");
        return;
    }else if(index>lengthDaftarUtas(*daftarUtas)){
        printf("Kicauan Sambungan dengan index %d tidak ditemukan.\n\n",index);
        return;
    }else{
        int ctr;
        AddressUtas p, loc;
        // ALGORITMA
        if(index == 1){
            deleteFirstDaftarUtas(daftarUtas,teks,Index);
        }else{
            ctr = 0;
            loc = FIRSTDAFTARUTAS(*daftarUtas);
            while(ctr<index-1){
                ctr+=1;
                loc = NEXTDAFTARUTAS(loc);
            }
            p = NEXTDAFTARUTAS(loc);
            *teks = TEKSUTAS(p);
            long long int current_time = getCurrentTime();
            p->timeCreated = (DetikToDATETIME(current_time));
            NEXTDAFTARUTAS(loc) = NEXTDAFTARUTAS(p);
            free(p);
        }
        printf("Kicauan sambungan berhasil dihapus.\n\n");
    }
}


// CETAK UTAS DI KICAUAN AJA YA
// void cetak_utas(){

//     // Mencetak keseluruhan utas 
//     UTAS *utasan;
//     int idutas;
//     if(PRIVACY(USER(user,CurrentUserId))){
//         printf("Akun yang membuat utas ini adalah akun privat.");
//     }else if(!isIdUtasExist(utasan, idutas)){
//         printf("Utas tidak ditemukan.");
//     }else{
//         int idutas,index,*idkicau;
//         UTAS *utasan;
//         Address p;
//         p = FIRST(utasan);
//         // Mencetak utas utama
//         // printf("id\t\t\t\t: %d\n", kicauan->id);
//         // printf("idAuthor\t\t: %d\n", kicauan->idAuthor);
//         // printf("isi teks\t\t: %s\n", kicauan->teks.TabWord);
//         printf("datetime\t\t: ");
//         long long int current_time = getCurrentTime();
//         // printf("Author\t\t\t: %s\n", kicauan->Author.TabWord);
//         TulisDATETIME(DetikToDATETIME(current_time));
//         printf("\n");
//         p = NEXT(p);
//         int index = 1;
//         // mencetak item utas dengan index utas index.
//         while(p!=NULL){
//             printf("\t\t\t\tid\t\t\t\t: %d\n", index);
//             // printf("\t\t\t\tidAuthor\t\t: %d\n", kicauan->idAuthor);
//             // printf("\t\t\t\tisi teks\t\t: %s\n", kicauan->teks.TabWord);
//             printf("\t\t\t\tdatetime\t\t: ");
//             long long int current_time = getCurrentTime();
//             // printf("\t\t\t\tAuthor\t\t\t: %s\n", kicauan->Author.TabWord);
//             TulisDATETIME(DetikToDATETIME(current_time));
//             printf("\n");
//             index++;
//         }

//     }
// }