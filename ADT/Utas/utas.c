#include <stdio.h>
#include <stdlib.h>


#include "utas.h"
#include "../../globalVar.h"
#include "../../util.c"

AddressUtas newUtas(){
    AddressUtas new = (AddressUtas)malloc(sizeof(UTAS));

    if(new == NULL) return NULL;

    new->next = NULL;

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

boolean isEmpty(LISTIDUTAS li){
    return (nEFF(li)==0);
}

// IdxType getLastIdx(LISTIDUTAS li){
//     return (IdxType)(length(li)-1);
// }

// int length(LISTIDUTAS li){
//     return NEFF_LISTIDUTAS(li);
// }

// boolean isUtas(LISTIDUTAS li, int idKicau){
// // Mengecek apakah ada idkicau di LISTIDUTAS, pake indexof listdin, mengembalikan true jika ada
//     IdxType i, index;
//     index = IDX_UNDEF;
//     i =0;
//     boolean check = false;
//     if(isEmpty(li)){
//         check = false;
//     }else{
//         while(i<=getLastIdx(li) && check == false){
//             if(ELMT(li,i) == idKicau){
//                 check = true;
//             }
//         }
//     }
//     return check;
// }


// void utas(int idKicau){
//     AddressUtas daftarUtas = newUtas();
//     int idutas, *idkicau;
//     LISTIDUTAS li;
//     if(!isUtas(li,idKicau)){
//         printf("Kicauan tidak ditemukan.");
//         return;
//     }else if(ListKicauan.buffer[idKicau].idAuthor == CurrentUserId){
//         printf("Utas bukan milik Anda.");
//         return;
//     }else{
//         printf("Utas berhasil dibuat!");
//         Word teks;
//         printf("Masukkan kicauan");
//         do{
//             readWord(&teks,';');
//         }while(teks.Length == 0);
//         printf("\n\n");
        
//         daftarUtas->teks = teks;

//         Word val;
//         readWord(&val,';');
//         boolean stop ;
//         if(strCompare(val.TabWord, "YA")){
//             stop = true;
//         }else{
//             stop = false;
//         }
//         do{
//             Word teks;
//             printf("Masukkan kicauan");
//             do{
//                 readWord(&teks,';');
//             }while(teks.Length == 0);
//             printf("Apakah Anda ingin melanjutkan utas ini?");
//         }while((!stop));
//         printf("\n\n");
//         printf("Utas selesai!");
//     }
// }

// void sambung_utas(){
// /* Pakai insertat yang ada di listlinier  */
//     int idutas,index;
//     // LISTIDUTAS *utasan;
//     // if(getIdAuthor()!= CurrentUserId){
//     //     printf("Utas bukan milih Anda.");
//     // }else if(!isUtas){
//     //     printf("Index terlalu tinggi");
//     // }else{
//     //     if(!isIndexValid){
//     // for loop palinkedlist
//     //         printf("Index terlalu tinggi.");
//     //     }else{
//     //         ReadUtas(utasan);
//     //     }
//     // }
// }

// void hapus_utas(){
//     int idutas, idx;
//     UTAS *utasan;
//     ITEMUTAS val;
//     if(getIdAuthor()!=CurrentUserId){
//         printf("Anda tidak bisa menghapus kicauan dalam utas ini.");
//     }else if(idx ==0){
//         printf("Anda tidak bisa menghapus kicauan utama");
//     }else if(!isIdUtasExist(utasan, idutas)){
//         printf("Utas tidak ditemukan");
//     }else if(!isIndexValid(utasan,idx)){
//         printf("Kicauan Sambungan dengan index X tidak");
//     }else{
//         deleteAtUtas(utasan, val,idx);
//         printf("Kicauan sambungan berhasil dihapus.");
//     }
// }


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
