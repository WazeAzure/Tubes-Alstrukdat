#include "utas.h"
#include "../../globalVar.h"
#include "../../util.h"

AddressUtas newUtas(Word teks,long long int time){

    AddressUtas new = (AddressUtas)malloc(sizeof(ListElemenUtas));

    if(new != NULL) {
        new->next = NULL;
        new->teks = teks;
        new->time = time;
    }
    return new;
}

void CreateListElementUtas(ListElemenUtas *daftarUtas){
    FIRST(*daftarUtas) = NULL;
}

void CreateListIdUtas(LISTIDUTAS* li, int CAPACITY){
// inisialisasi UTAS, membentuk listdin dari utas 
    li->buffer = (int*)malloc(sizeof(int) *li->CAPACITY);
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

boolean isUtas(LISTIDUTAS li, int idKicau){
// Mengecek apakah ada idkicau di LISTIDUTAS, pake indexof listdin, mengembalikan true jika ada
    IdxType i, index;
    index = IDX_UNDEF;
    i =0;
    boolean check = false;

    while(i<=getLastIdx(li) && check == false){
        if(ELMT(li,i) == idKicau){
            check = true;
        }
        i++;
    }
    return check;
}

void insertFirstDaftarUtas(ListElemenUtas *daftarUtas, Word teks,long long int time){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    // KAMUS
    AddressUtas p;
    // ALGORITMA
    p = newUtas( teks, time);
    if(isEmptyDaftarUtas(*daftarUtas)){
        NEXTDAFTARUTAS(p)=NULL;
    }else{
        NEXTDAFTARUTAS(p)= FIRSTDAFTARUTAS(*daftarUtas); 
    }    
    FIRSTDAFTARUTAS(*daftarUtas) = p;
}

void deleteFirstDaftarUtas(ListElemenUtas *daftarutas,Word *teks,long long int *time,int index){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-free */
    // KAMUS
    AddressUtas p;
    // ALGORITMA
    p = FIRSTDAFTARUTAS(*daftarutas);
    *teks = TEKSUTAS(p);
    *time = TIMEUTAS(p);
    FIRSTDAFTARUTAS(*daftarutas) = NEXTDAFTARUTAS(p); 
    free(p);
}

void utas(int idKicau){

    LISTIDUTAS li;
    if(!isUtas(li,idKicau)){
        printf("Kicauan tidak ditemukan.\n\n");
        return;
    }else if(ListKicauan.buffer[idKicau].idAuthor == CurrentUserId){
        printf("Utas bukan milik Anda.\n\n");
        return;
    }else{
        printf("Utas berhasil dibuat!\n");
        Word teks;
        printf("Masukkan kicauan\n");
        do{
            readWord(&teks,';');
        }while(teks.Length == 0);
        printf("\n\n");
        
        AddressUtas daftarUtas = newUtas(teks,getCurrentTime());

        Word val;
        readWord(&val,';');
        boolean stop ;
        if(strCompare(val.TabWord, "YA")){
            stop = true;
        }else{
            stop = false;
        }
        do{
            Word teks;
            printf("Masukkan kicauan\n");
            do{
                readWord(&teks,';');
                AddressUtas daftarUtas = newUtas(teks,getCurrentTime());
            }while(teks.Length == 0);
            printf("Apakah Anda ingin melanjutkan utas ini?");
        }while((!stop));
        printf("\n\n");
        printf("Utas selesai!\n\n");
    }
}

void sambung_utas(int index, ListElemenUtas *daftarUtas, LISTIDUTAS li, int idKicau, Word teks){
/* Pakai insertAt yang ada di listlinier  */
    if(!isUtas(li, idKicau)){
        printf("Utas tidak ditemukan.\n\n");
        return;
    }
    // else if(userId(nama)!= CurrentUserId){
    //     printf("Anda tidak bisa menyambung utas ini.\n\n");
    //     return;
    else if(lengthDaftarUtas(*daftarUtas)<index){
        printf("Index terlalu tinggi.\n\n");
        return;
    }else{
        Word teks;
        printf("Masukkan kicauan.\n");
        do{
            readWord(&teks,';');
            int ctr;
            AddressUtas p,loc;
            if(index == 1){
                insertFirstDaftarUtas(daftarUtas,teks,getCurrentTime());
                return;
            }else{
                p  = newUtas(teks,getCurrentTime());
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
        }while(teks.Length == 0);
        printf("\n\n");
    }
}


void hapus_utas(int index,LISTIDUTAS li, int idUtas, ListElemenUtas *daftarUtas, Word *teks,long long int *time){

    // if(userId(nama)!=CurrentUserId){
    //     printf("Anda tidak bisa menghapus kicauan dalam utas ini.\n\n");
    //     return;
    // }else 
    if(index ==0){
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
            deleteFirstDaftarUtas(daftarUtas,teks,time,index);
        }else{
            ctr = 0;
            loc = FIRSTDAFTARUTAS(*daftarUtas);
            while(ctr<index-1){
                ctr+=1;
                loc = NEXTDAFTARUTAS(loc);
            }
            p = NEXTDAFTARUTAS(loc);
            *teks = TEKSUTAS(p);
            *time = TIMEUTAS(p);
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

