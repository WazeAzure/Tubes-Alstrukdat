
// #include "../../util.c"

#include "draftkicauan.h"

#include "../../globalVar.h"

#define endl printf("\n")

/* ************ Prototype ************ */
AddressDraftKicau newNodeDraftKicau(DraftKicau val){
    AddressDraftKicau p = (AddressDraftKicau) malloc(sizeof(Node));
    if(p!=NULL){
        INFO_S(p)= val;
        NEXT_S(p)= NULL;
    }
    return p;
}
/* *** Konstruktor/Kreator *** */
void DraftKicauanCreateEmpty(Stack *S)
{
    ADDR_TOP(*S) = NULL;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean DraftKicauanIsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (ADDR_TOP(S) == NULL);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushDraftKicau(Stack * S, DraftKicau X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    AddressDraftKicau p = newNodeDraftKicau(X);
    if (p != NULL)
    {
        NEXT_S(p) = ADDR_TOP(*S);
        ADDR_TOP(*S) = p;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopDraftKicau(Stack * S, DraftKicau* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = TOP(*S);
    AddressDraftKicau p = ADDR_TOP(*S);
    ADDR_TOP(*S) = NEXT_S(ADDR_TOP(*S));
    NEXT_S(p) = NULL;
    free(p);
}

void buatDraft()
{
    Stack *S = &DRAFT(USER(user, CurrentUserId));
    // membaca draft menggunakan mesin kata
    Word isi;
    printf("Masukkan draf:\n");
    readWord(&isi,';');

    // masukkan draft ke Stack
    DraftKicau x;
    isiDraft(x) = isi;

    // pilihan hapus, unggah, singgah
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    // membaca pilihan
    Word command;
    
    do
    {
        readWord(&command, ';');
    } while (strCompare(command.TabWord, "HAPUS") && strCompare(command.TabWord, "SIMPAN") && strCompare(command.TabWord, "TERBIT"));
    
    if (strCompare(command.TabWord, "HAPUS"))
    {
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(command.TabWord, "SIMPAN"))
    {
        long long int time_second = getCurrentTime();
        DATETIME timeDraftK = DetikToDATETIME(time_second);
        timeDraft(x) = timeDraftK;

        PushDraftKicau(S, x);
        printf("Draf telah berhasil disimpan\n");
    } else if (strCompare(command.TabWord, "TERBIT"))
    {
        terbitDraft(S);
    }
}

void lihatDraft(Stack S)
{
    if (DraftKicauanIsEmpty(S))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
        // return ;
    } else
    {
        DraftKicau draf = TOP(S);
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        TulisDATETIME(draf.timeCreated);
        printf("\n");
        printf("| ");
        printWord(draf.isiDraftKicauan);
        printf("\n");
    }

    Word command;
    
    do
    {
        printf("Apakah anda ingin mengubah, menyimpan, atau menerbitkan draf ini?\n");
        readWord(&command,';');
    } while (strCompare(command.TabWord, "HAPUS") != 0 && strCompare(command.TabWord, "UBAH") != 0 && strCompare(command.TabWord, "TERBIT") != 0 && strCompare(command.TabWord, "KEMBALI"));

    if (strCompare(command.TabWord, "HAPUS"))
    {
        DraftKicau val;
        PopDraftKicau(&S,&val);
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(command.TabWord, "UBAH"))
    {
        ubahDraft();
    } else if (strCompare(command.TabWord, "TERBIT"))
    {
        terbitDraft(&S);
    } else if (strCompare(command.TabWord, "KEMBALI"))
    {
        printf("Kembali ke menu.\n");
    }

}

void terbitDraft (Stack *S)
{
    DraftKicau x;
    PopDraftKicau(S,&x);
    Word tagar;
    readWord(&tagar, ';');
    KICAUAN* kicauBaru = newKicau(x.isiDraftKicauan, USER_NAMA(USER(user, CurrentUserId)), tagar);

    ListKicauan.buffer[ListKicauan.NEFF] = *kicauBaru;
    ListKicauan.NEFF++;

    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:");
    showKicauanContent(*kicauBaru);
}

void ubahDraft ()
{
    Stack* S = &DRAFT(USER(user, CurrentUserId));

    // meminta input baru
    printf("Masukkan draf yang baru:\n");

    //menerima masukkan
    Word newIsi;
    readWord(&newIsi,';');

    //mengganti draft awal dengan draft baru
    DraftKicau val, new;

    PopDraftKicau(S, &val);

    isiDraft(val) = newIsi;


    // pilihan hapus, unggah, singgah
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    // membaca pilihan
    Word command;
    
    do
    {
        readWord(&command,';');
    } while (strCompare(command.TabWord, "HAPUS") || strCompare(command.TabWord,"SIMPAN") || strCompare(command.TabWord, "TERBIT"));
    
    if (strCompare(command.TabWord, "HAPUS"))
    {
        // gak ngelakuin apa apa karena diawal belum di push
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(command.TabWord,"SIMPAN"))
    {

        int time_second = getCurrentTime();
        DATETIME timeDraftK = DetikToDATETIME(time_second);
        timeDraft(new) = timeDraftK;

        PushDraftKicau(S,new);
        printf("Draf telah berhasil disimpan\n");
    } else if (strCompare(command.TabWord, "TERBIT"))
    {
        terbitDraft(S);
    }

}