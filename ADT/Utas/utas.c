#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

#include "../Datetime/datetime.h"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"
#include "../Kicauan/kicauan.h"
#include "../User/user.h"
#include "../User/user.c"
// #include "../Linkedlist/listlinier.h"

#include "utas.h"
#include "../../globalVar.h"
#include "../../util.c"


void CreateListIdUtas(LISTIDUTAS *l, int CAPACITY){
// inisialisasi UTAS, membentuk linkedlist of itemutas dan melakukan increment setiap pembuatan UTAS di global variabel pada CounterUtas
    l->buffer = (int*)malloc(sizeof(int) * CAPACITY);
    l->CAPACITY = CAPACITY;
    l->NEFF = 0;
}

// int getIdAuthor(){

// }
// void ReadUtas(UTAS *utas){
// /*Membuat UTAS dengan memasukkkan teks saja.*/
//     printf("Masukkan kicauan:\n");
//     Word input;
//     readWord(&input,';');
// }

// boolean isIndexValid(UTAS *utasan,int index){

// }

// boolean isUtasExist(UTAS utas, int idUtas){

// }

// void deleteAtItemUtas(UTAS *utasan, ITEMUTAS *itemutas, int idx){
// /* I.S. index valid, idx bukan 0*/
// /* F.S val diset dengan elemen utasan pada index ke idx*/
//     int ctr;
//     AddressUtas p,loc;
//     ctr = 0;
//     loc = FIRST_UTAS(*utasan);
//     while(ctr<idx-1){
//         ctr++;
//         loc = NEXT_UTAS(loc);
//     }
//     p = NEXT_UTAS(loc);
//     // *itemutas = INFO_UTAS(p);                                ERROR
//     NEXT_UTAS(loc)=NEXT_UTAS(p);
//     free(p);
// }

// void utas(){
// /*Membuat isi dari sebuah utasan*/
//     UTAS *daftarutas;
//     int idutas, *idkicau;

//     if(!isUtasExist(daftarutas,idutas)){
//         printf("Kicauan tidak ditemukan.");
//     }else if(getIdAuthor(daftarutas,idkicau)){
//         printf("Utas bukan milih Anda.");
//     }else{
//         printf("Utas berhasil dibuat!");
//     }

//     Word val;
//     readWord(&val,';');
//     boolean stop ;
//     if(vstrCompare(val.TabWord, "YA")){
//         stop = true;
//     }else{
//         stop = false;
//     }
//     do{
//         ReadUtas(daftarutas);
//         printf("Apakah Anda ingin melanjutkan utas ini?");
//     }while((!stop));
//     printf("Utas selesai!");
// }
 
// void sambung_utas(){
// /*  */
//     int idutas,index;
//     UTAS *utasan;
//     if(getIdAuthor()!= CurrentUserId){
//         printf("Utas bukan milih Anda.");
//     }else if(!isIdUtasExist){
//         printf("Index terlalu tinggi");
//     }else{
//         if(!isIndexValid){
//             printf("Index terlalu tinggi.");
//         }else{
//             ReadUtas(utasan);
//         }
//     }
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
