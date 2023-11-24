#include "util.h"
#if defined(_WIN32)
    #include <conio.h>
    #include <windows.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int strLen(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void strSplit(char str[], char delim, char *x, char *y){
    int i = 0, j = 0;
    boolean s = false;
    while(str[i]){
        if(str[i] == delim){
            s = true;
            x[i] = '\0';
        } else {
            if(s){
                y[j] = str[i];
                j++;
            } else {
                x[i] = str[i];
            }
        }
        i++;
    }
    y[j] = '\0';
}

boolean strCompare(char str1[], char str2[]){
    // printf("%s\n", str1);
    // printf("%s\n", str2);
    
    int i=0;
    int len1 = strLen(str1);
    int len2 = strLen(str2);

    // printf("arr s1 s2 - %d %d\n", len1, len2);

    if(len1 != len2) return false;

    while(i < len1){
        if(str1[i] != str2[i]) return false;
        i++;
    }

    return true;
}

boolean isFolderExist(Word foldername){
    struct stat st;

    // Use stat to check the folder's existence
    if (stat(foldername.TabWord, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            printf("Folder '%s' exists.\n", foldername.TabWord);
            return true;
        } else {
            printf("%s'%s' is not a folder.%s\n", RED, foldername.TabWord, NORMAL);
            return false;
        }
    } else {
        printf("%sFolder '%s' does not exist.%s\n", RED, foldername.TabWord, NORMAL);
        return false;
    }
}

void strip(char *str, char symbol){
    int i=0;
    while(str[i]){
        if(str[i] == symbol){
            // printf("found %d\n", i);
            str[i] = '\0';
        }
        i++;
    }
}

void readHpFile(FILE* f, NoHp *input){
    char* buffer = (char*)malloc(sizeof(char)*100);
    int cap = 100;
    int neff = 0;

    // printf("hihi\n");
    while(currentChar != '\r' && currentChar != '\n'){
        // printf("%c\n", currentChar);
        if(neff > cap){
            cap += 100;
            buffer = (char*)realloc(buffer, sizeof(char)*cap);
        }
        fscanf(f, "%c", &currentChar);
        buffer[neff] = currentChar;

        neff++;
    }
    

    (*input).length = neff-1;

    buffer[neff-1] = '\0';

    (*input).TabWord = buffer;

    #if defined(_WIN32)
    // if(currentChar == '\r') printf("currentChar \\r \n");
    // fscanf(f, "%c", &currentChar);
    // if(currentChar == '\n') printf("currentChar \\n \n");
    currentChar = '\0';
    // fscanf(f, "%c", &currentChar);
    #else
    // if(currentChar == '\r') printf("currentChar \\r \n");
    fscanf(f, "%c", &currentChar);
    // if(currentChar == '\n') printf("currentChar \\n \n");
    // fscanf(f, "%c", &currentChar);
    // printf("%c\n", currentChar);
    // fgetc(f);
    currentChar = '\0';
    #endif
    // printf("awiaiajwiaj\n");
}

void bacaPengguna(FILE* f){
    // printf("baca pengguna called\n");
    
    char nUser[10];
    fgets(nUser, sizeof(nUser), f);
    strip(nUser, '\r');
    strip(nUser, '\n');
    int n_user = WordToInt(CharToWord(nUser));

    LingkaranPertemanan.Neff = n_user;

    printf("n_user %d\n", n_user);
    // char line[100];
    int i;
    for(i=0; i<n_user; i++){
        char name[100];
        char password[100];
        char bio[100];
        NoHp hp;
        char weton[100];
        char privacy[10];
        char prof_pict[5][30];

        fgets(name, sizeof(name), f);
        strip(name, '\r');
        strip(name, '\n');
        fgets(password, sizeof(password), f);
        strip(password, '\r');
        strip(password, '\n');
        fgets(bio, sizeof(bio), f);
        strip(bio, '\r');
        strip(bio, '\n');
        readHpFile(f, &hp);
        // fgets(hp, sizeof(hp), f);
        // strip(hp, '\r');
        fgets(weton, sizeof(weton), f);
        strip(weton, '\r');
        strip(weton, '\n');
        fgets(privacy, sizeof(privacy), f);
        strip(privacy, '\r');
        strip(privacy, '\n');
        for(int i=0; i<5; i++){
            // printf("i - %d\n", i);
            fgets(prof_pict[i], sizeof(prof_pict[i]), f);
            strip(prof_pict[i], '\r');

            strip(prof_pict[i], '\n');
        }
        // fscanf(f, "%c", &currentChar);

        printf("name: %s\n", name);
        printf("%s\n", password);
        printf("%s\n", bio);
        printf("%s\n", hp.TabWord);
        printf("%s\n", weton);
        printf("%s\n", privacy);
        printf("%s\n", prof_pict[0]);
        printf("%s\n", prof_pict[1]);
        printf("%s\n", prof_pict[2]);
        printf("%s\n", prof_pict[3]);
        printf("%s\n", prof_pict[4]);

        Word wName = CharToWord(name);
        Word wPassword = CharToWord(password);
        Word wbio = CharToWord(bio);
        // NoHp whp = CharToNoHp(hp);
        Word wweton = CharToWord(weton);
        Word wprivacy = CharToWord(privacy);

        boolean priv = false;
        if(strCompare(wprivacy.TabWord, "Privat")){
            priv = true;
        }

        FOTO fotoProfile;
        createFoto(5, 5, &fotoProfile);
        setFotoProfil(&fotoProfile, prof_pict);

        displayFoto(fotoProfile);

        addUser(&user, wName, wPassword);
        setProfil(&user, i, wbio, hp, wweton, priv, fotoProfile);
    }

    // matrix pertemanan

    char pertemananLine[100];
    int j;
    int n_teman = 0;
    for(i=0; i<n_user; i++){
        fgets(pertemananLine, sizeof(pertemananLine), f);
        n_teman = 0;
        for(j=0; j<n_user; j++){
            DaftarPertemanan.Tabword[i][j] = pertemananLine[j*2] - '0';
            if(DaftarPertemanan.Tabword[i][j] == 1 && i != j){
                n_teman++;
                ds_union(&LingkaranPertemanan, i, j);
            }
        }
        JUMLAH_TEMAN(USER(user, i)) = n_teman;

    }

    PrintDaftarPertemanan(DaftarPertemanan);
    
    // permintaan pertemanan
    int banyakPermintaan;
    char nPermintaan[10];

    fgets(nPermintaan, sizeof(nPermintaan), f);
    strip(nPermintaan, '\r');
    strip(nPermintaan, '\n');
    banyakPermintaan = WordToInt(CharToWord(nPermintaan));
    printf("banyak permintaan %d\n", banyakPermintaan);

    char lineNum[100];
    int arr[3];

    for(i=0; i<banyakPermintaan; i++){
        fgets(lineNum, sizeof(lineNum), f);
        strip(lineNum, '\r');
        
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        int count = 0;
        // pass
        int x=0;
        while(lineNum[x]){
            if(lineNum[x] != ' '){
                arr[count] = arr[count]*10 + lineNum[x] - '0';
            } else {
                count++;
            }
            x++;
        }
        // arr[count] = arr[count]*10 + lineNum[x]-'0';

        infotype request;
        request.id = arr[0];
        request.jumlahTeman = arr[2];
        request.nama = USER(user, arr[0]).nama;
        EnqueuePermintaanPertemanan(&PERMINTAANPERTEMANAN(USER(user, arr[1])), request);
    }
}

void bacaKicauan(FILE* f){
    char nKicauan[10];
    fgets(nKicauan, sizeof(nKicauan), f);
    // printf("%s\n", nKicauan);
    strip(nKicauan, '\r');
    strip(nKicauan, '\n');
    int n_kicauan = WordToInt(CharToWord(nKicauan));

    printf("jumlah kicauan: %d\n", n_kicauan);
    int i;
    for(i=0; i<n_kicauan; i++){
        char idKicau[10];
        char text[281];
        char like[10];
        char author[300];
        char datetime[20];

        fgets(idKicau, sizeof(idKicau), f);
        strip(idKicau, '\r');
        strip(idKicau, '\n');
        fgets(text, sizeof(text), f);
        strip(text, '\r');
        strip(text, '\n');
        fgets(like, sizeof(like), f);
        strip(like, '\r');
        strip(like, '\n');
        fgets(author, sizeof(author), f);
        strip(author, '\r');
        strip(author, '\n');
        fgets(datetime, sizeof(datetime), f);
        strip(datetime, '\r');
        strip(datetime, '\n');

        // printf("idKicau str - %s\n", idKicau);
        int id_kicau = WordToInt(CharToWord(idKicau)) - 1;
        Word wtext = CharToWord(text);
        int nlike = WordToInt(CharToWord(like));
        Word wauthor = CharToWord(author);
        DATETIME d = CharToDATETIME(datetime);
        Word wtagar = CharToWord("\0");

        printf("%d\n", id_kicau);
        printf("%s\n", wtext.TabWord);
        printf("%d\n", nlike);
        printf("%s\n", wauthor.TabWord);
        TulisDATETIME(d);
        // endl;
        printf("%s\n", wtagar.TabWord);

        // printf("work\n");
        // add kicauan;
        KICAUAN* new = newKicau(wtext, wauthor, wtagar);
        new->idAuthor = userId(wauthor);
        new->id = id_kicau;
        new->like = nlike;
        new->timeCreated = d;

        // printf("middlen\n");

        ListKicauan.buffer[ListKicauan.NEFF] = *new;
        ListKicauan.NEFF++;
        // printf("end of work\n");

        #if defined(_WIN32)
            fgetc(f);
        #else
            fgetc(f);
            fgetc(f);
        #endif
    }
}

void bacaUtas(FILE*f){
    char nUtas[10];
    fgets(nUtas, sizeof(nUtas), f);
    strip(nUtas, '\r');
    strip(nUtas, '\n');
    int n_utas = WordToInt(CharToWord(nUtas));

    int i, j;
    for(i=0; i<n_utas; i++){
        char id[100];
        char jumlah[100];

        fgets(id, sizeof(id), f);
        strip(id, '\r');
        strip(id, '\n');

        fgets(jumlah, sizeof(jumlah), f);
        strip(jumlah, '\r');
        strip(jumlah, '\n');

        int utasan = WordToInt(CharToWord(id));
        int Jumlah = WordToInt(CharToWord(jumlah));
        for (j=0; j<Jumlah; j++){
            AddressUtas new = (AddressUtas)malloc(sizeof(NodeElemenUtas));
            if (new != NULL) {
                char teks[100];
                char author[100];
                char datetime[100];
                
                fgets(teks, sizeof(teks), f);
                strip(teks, '\r');
                strip(teks, '\n');
                fgets(author, sizeof(author), f);
                strip(author, '\r');
                strip(author, '\n');
                fgets(datetime, sizeof(datetime), f);
                strip(datetime, '\r');
                strip(datetime, '\n');

                Word text = CharToWord(teks);
                Word Author = CharToWord(author);
                DATETIME Datetime = CharToDATETIME(datetime);

                new->next = NULL;
                new->teks = text;
                new->author = Author;
                new->timeCreated = Datetime;

                AddressUtas p = ListKicauan.buffer[utasan-1].daftar_utas;
                if (p == NULL) {
                    ListKicauan.buffer[utasan-1].daftar_utas = new;
                } else {
                    while (NEXTDAFTARUTAS(p) != NULL) {
                        p = NEXTDAFTARUTAS(p);
                    }
                    NEXTDAFTARUTAS(p) = new;
                }
                
            }
        }
        insertLastIdUtas(&ListIdUtas, utasan-1);
    }
}

void bacaBalasan(FILE *f){
    char nKicauan[4];
    fgets(nKicauan, sizeof(nKicauan), f);
    strip(nKicauan, '\r');
    strip(nKicauan, '\n');
    int n_kicau = WordToInt(CharToWord(nKicauan));

    int i;
    for(i=0; i<n_kicau; i++){
        char idKicau[10];
        fgets(idKicau, sizeof(idKicau), f);
        strip(idKicau, '\r');
        strip(idKicau, '\n');
        int id_kicau = WordToInt(CharToWord(idKicau)) - 1;

        char nBalasan[10];
        fgets(nBalasan, sizeof(nBalasan), f);
        strip(nBalasan, '\r');
        strip(nBalasan, '\n');

        int n_balas = WordToInt(CharToWord(nBalasan));
        printf("n_balas: %d\n", n_balas);
        int j;
        for(j=0; j<n_balas; j++){
            char idid[100];
            char teks[100];
            char author[100];
            char datetime[100];
            
            fgets(idid, sizeof(idid), f);
            strip(idid, '\r');
            strip(idid, '\n');
            fgets(teks, sizeof(teks), f);
            strip(teks, '\r');
            strip(teks, '\n');
            fgets(author, sizeof(author), f);
            strip(author, '\r');
            strip(author, '\n');
            fgets(datetime, sizeof(datetime), f);
            strip(datetime, '\r');
            strip(datetime, '\n');
            char parentId[10], balasId[10];
            strSplit(idid, ' ', parentId, balasId);
            
            int parent_id = WordToInt(CharToWord(parentId));
            if(parent_id != -1){
                parent_id --;
            }
            int balas_id = WordToInt(CharToWord(balasId)) -1;

            Word text = CharToWord(teks);
            Word Author = CharToWord(author);
            DATETIME Datetime = CharToDATETIME(datetime);

            BALASAN* balas = (BALASAN *)malloc(sizeof(BALASAN));
            balas->author = Author;
            balas->date = Datetime;
            balas->isi = text;
            balas->id = balas_id;
            balas->idAuthor = userId(Author);

            AddressTree t = (AddressTree)malloc(sizeof(TreeNode));
            t->info = *balas;
            t->sibling = NULL;
            t->child = NULL;

            printf("RUNNING -----------------------------\n");

            insertBalasan(id_kicau, parent_id, t, balas_id);
        }
    }
}

void bacaDraf(FILE*f){
    int i, j, k, len;
    char jumlah[100];

    fgets(jumlah, sizeof(jumlah), f);
    strip(jumlah, '\r');
    strip(jumlah, '\n');
    int Jumlah = WordToInt(CharToWord(jumlah));

    for (i = 0; i < Jumlah; i++){
        char jumlahDraf[100];
        char NamaNDraf[100];
        char author[100];

        fgets(NamaNDraf, sizeof(NamaNDraf), f);
        strip(NamaNDraf, '\r');
        strip(NamaNDraf, '\n');

        len = strLen(NamaNDraf);
        j = len-1;
        while (NamaNDraf[j] != ' ' && j >= 0){
            j--;
        }

        for (k = 0; k < len-j-1; k++) {
            jumlahDraf[k] = NamaNDraf[k + j + 1];
        }
        jumlahDraf[len-j-1] = '\0';
        int jumlahdraf = WordToInt(CharToWord(jumlahDraf));

        for (k = 0; k < j; k++){
            author[k] = NamaNDraf[k];
        } 
        author[j] = '\0';
        Word Author = CharToWord(author);

        int authorID = userId(Author);

        Stack S;
        DraftKicauanCreateEmpty(&S);

        for (j = 0; j < jumlahdraf; j++){
            DraftKicau temp;
            char teks[100];
            char datetime[100];

            fgets(teks, sizeof(teks), f);
            strip(teks, '\r');
            strip(teks, '\n');

            fgets(datetime, sizeof(datetime), f);
            strip(datetime, '\r');
            strip(datetime, '\n');

            Word text = CharToWord(teks);
            DATETIME Datetime = CharToDATETIME(datetime);

            temp.isiDraftKicauan = text;
            temp.timeCreated = Datetime;

            PushDraftKicau(&S, temp);
        }
        DraftKicau temps;
        PopDraftKicau(&S, &temps);
        PushDraftKicau(&(USER(user, authorID).draftKicauan), temps);
    }
}

boolean readFile(Word FileName, Word foldername){
    
    Word fname = ConcatWord(foldername, FileName);

    char filename[FileName.Length + foldername.Length + 1];
    WordToChar(fname, filename);

    // printWord(fname);
    FILE* f = fopen(filename, "r");   // buka file X

    if(f != NULL){
        printf("file opened \'%s\'\n", filename);
        if(strCompare(FileName.TabWord, "/pengguna.config")){
            bacaPengguna(f);
        } else if(strCompare(FileName.TabWord, "/balasan.config")){
            bacaBalasan(f);
        } else if(strCompare(FileName.TabWord, "/kicauan.config")){
            bacaKicauan(f);
        } else if(strCompare(FileName.TabWord, "/utas.config")){
            bacaUtas(f);
        } else if(strCompare(FileName.TabWord, "/draf.config")) {
            bacaDraf(f);
        }
    } else {
        printf("%sfile \'%s\' not exist%s\n", RED, filename, NORMAL);
        return false;
    }

    fclose(f); // tutup file pengguna
    return true;
}

void loadConfigFile(){
    Word foldername;
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    readWord(&foldername, ';');

    // <-- berikan pengecekkan folder
    while(!isFolderExist(foldername)){
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        readWord(&foldername, ';');
    }

    char char_pengguna[] = "/pengguna.config";
    char char_kicauan[] = "/kicauan.config";
    char char_balasan[] = "/balasan.config";
    char char_utas[] = "/utas.config";
    char char_draf[] = "/draf.config";

    Word pengguna = CharToWord(char_pengguna);
    Word kicauan = CharToWord(char_kicauan);
    Word balasan = CharToWord(char_balasan);
    Word utas = CharToWord(char_utas);
    Word draf = CharToWord(char_draf);

    boolean stat1 = readFile(pengguna, foldername);
    boolean stat2 = readFile(kicauan, foldername);
    boolean stat3 = readFile(balasan, foldername);
    boolean stat4 = readFile(utas, foldername);
    boolean stat5 = readFile(draf, foldername);

    if(!(stat1 && stat2 && stat3 && stat4 && stat5)){
        printf("Mohon pastikan semua file ada.\n");
        exit(1);
    }

    // parsing daftar pengguna
}

void readCommandMain(Word* input){
    printf("> ");
    Word sentence;
    // printf("current char %c\n", currentChar);
    readWord(&sentence, ';');
    // printf("%s\n", sentence.TabWord);
    // printf("%s\n", sentence.TabWord);

    int idx = 0;
    int i=0, j =0;
    boolean loop = true;
    while(loop){
        if(sentence.TabWord[i] == '\0') loop = false;
        if(sentence.TabWord[i] == ' '){
            input[idx].Length = j;
            input[idx].TabWord[j] = '\0';
            j = 0;
            idx++;
            i++;
        }
        
        if(idx == 0){
            input[0].TabWord[j] = sentence.TabWord[i];
        } else if(idx == 1){
            input[1].TabWord[j] = sentence.TabWord[i];
        } else {
            input[2].TabWord[j] = sentence.TabWord[i]; 
        }

        j++;
        i++;
    }

    input[idx].Length = j;
    input[idx].TabWord[j] = '\0';

    // printf("%d\n", idx);

    if(idx == 1){
        strip(input[1].TabWord, '\n');
        input[1].Length--;
    }
    if(idx == 2){
        strip(input[2].TabWord, '\n');
        input[2].Length--;
    }

    // printWord(input[0]);
    // endl;
    // printf("inpu1 length - %d\n", input[1].Length);
    // if(input[1].Length != 0){
    //     printWord(input[1]);
    //     endl;
    //     printf("w length - %d\n", input[1].Length);
    // }
    // if(input[2].Length != 0){
    //     printWord(input[2]);
    //     printf("input2 int - %d\n", WordToInt(input[2]));
    // }
    
    // endl;
}

void resetCommand(Word *input){
    input[0].TabWord[0] = '\0';
    input[0].Length = 0;

    input[1].TabWord[0] = '\0';
    input[1].Length = 0;

    input[2].TabWord[0] = '\0';
    input[2].Length = 0;
}



/* SECTION PRINT PRINT-AN AJA */

void printWelcomeBanner(){
    // clear screen
    #if defined(_WIN32)
    system("cls");
    system("chcp 65001");
    #else
    system("clear");
    #endif
    // welcome message
    printf("        \n");
    printf(" _______                       _______   __           \t\t%s ⠀⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣶⣶⡿⢋%s\n", BLUE, NORMAL);
    printf("|       \\                     |       \\ |  \\          \t\t%s ⠀⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋%s\n", BLUE, NORMAL);
    printf("| $$$$$$$\\ __    __   ______  | $$$$$$$\\ \\$$  ______  \t\t%s ⠀⠹⣿⣿⣿⣿⣶⣤⣤⣤⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀%s\n", BLUE, NORMAL);
    printf("| $$__/ $$|  \\  |  \\ /      \\ | $$__/ $$|  \\ /      \\ \t\t%s ⠀⣄⣈⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀%s\n", BLUE, NORMAL);
    printf("| $$    $$| $$  | $$|  $$$$$$\\| $$    $$| $$|  $$$$$$\\ \t\t%s ⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀%s\n", BLUE, NORMAL);
    printf("| $$$$$$$\\| $$  | $$| $$   \\$$| $$$$$$$\\| $$| $$   \\$$ \t\t%s ⠀⠀⣀⣉⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀%s\n", BLUE, NORMAL);
    printf("| $$__/ $$| $$__/ $$| $$      | $$__/ $$| $$| $$      \t\t%s ⠀⠀⠘⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀%s\n", BLUE, NORMAL);
    printf("| $$    $$ \\$$    $$| $$      | $$    $$| $$| $$      \t\t%s ⠀⠀⠀⠀⠀⢉⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀%s\n", BLUE, NORMAL);
    printf(" \\$$$$$$$   \\$$$$$$  \\$$       \\$$$$$$$  \\$$ \\$$      \t\t%s ⠒⠶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀%s\n", BLUE, NORMAL);
    printf("                                                      \t\t%s ⠀⠀⠀⠉⠙⠛⠛⠛⠛⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀%s\n", BLUE, NORMAL);
    printf("                                                      \t\t\n");
    printf("                                                      \t\t\n");
}

void printExitBanner(){
    printf(
" __________________\n"
"< Come Back Later! >\n"
" ------------------\n"
"        \\   ^__^\n"
"         \\  (oo)\\_______\n"
"            (__)\\       )\\/\\ \n"
"                ||----w |\n"
"                ||     ||\n"
    );
}

void printErrMessage(Word w){
    if(strCompare(w.TabWord, "DAFTAR")){
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    } else if(strCompare(w.TabWord, "MASUK")){
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    } else if(strCompare(w.TabWord, "MUAT")){
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    }
}

// ----------------------- SIMPAN & LOAD  ----------------
static void redrawPrompt(void)
{
    int i;
    int totalDots = 3;

    printf("Mohon tunggu ");

    for (i = 0; i < totalDots; ++i) {
        printf(".");
        fflush(stdout); // Flush the output buffer to make sure dots are printed immediately

        // You can replace the sleep function with actual loading operations
        // For demonstration purposes, sleep is used to simulate loading time
        // Sleep for 0.5 second
        #if defined(_WIN32)
            // printf("called in windows\n");
            Sleep(500);
        #else
            // sleep(1);
            // printf("called in linux\n");
        #endif
    }
    endl;
}

static void redrawPromptFiles(void)
{
    int i;
    int totalDots = 3;
    char arr[5][20] = {"pengguna.config", "draf.config", "kicauan.config", "utas.config", "balasan.config"};

    for(int f=0; f<5; f++){
        printf("%d. Creating %s ", f+1, arr[f]);
        for (i = 0; i < totalDots; ++i) {
            printf(".");
            fflush(stdout); // Flush the output buffer to make sure dots are printed immediately

            // You can replace the sleep function with actual loading operations
            // For demonstration purposes, sleep is used to simulate loading time
            // Sleep for 0.5 second
            #if defined(_WIN32)
                // printf("called in windows\n");
                Sleep(500);
            #else
                // sleep(1);
                // printf("called in linux\n");
            #endif
             
        }
        endl;
    }
}

void createFolder(Word folder){
    int check;

    #if defined(_WIN32)
        // printf("called in windows\n");
        check = mkdir(folder.TabWord);
    #else
        check = mkdir(folder.TabWord, 0777);
        // printf("called in linux\n");
    #endif

    if (!check)
        printf("Directory created\n");
    else {
        printf("%sUnable to create directory\n%s", RED, NORMAL);
        exit(1);
    }
}

void createEmptyFile(Word filename){
    char temp[filename.Length];
    WordToChar(filename, temp);

    FILE *f = fopen(temp, "w");
    fclose(f);
}

void createFiles(Word folder){
    char char_pengguna[] = "/pengguna.config";
    char char_kicauan[] = "/kicauan.config";
    char char_balasan[] = "/balasan.config";
    char char_utas[] = "/utas.config";
    char char_draf[] = "/draf.config";

    Word pengguna = CharToWord(char_pengguna);
    Word kicauan = CharToWord(char_kicauan);
    Word balasan = CharToWord(char_balasan);
    Word utas = CharToWord(char_utas);
    Word draf = CharToWord(char_draf);

    pengguna = ConcatWord(folder, pengguna);
    kicauan = ConcatWord(folder, kicauan);
    balasan = ConcatWord(folder, balasan);
    utas = ConcatWord(folder, utas);
    draf = ConcatWord(folder, draf);
    
    createEmptyFile(pengguna);
    createEmptyFile(kicauan);
    createEmptyFile(balasan);
    createEmptyFile(utas);
    createEmptyFile(draf);
}

void tulisPengguna(Word folder){
    char pengguna[] = "/pengguna.config";
    Word filename = ConcatWord(folder, CharToWord(pengguna));

    char temp[filename.Length];
    WordToChar(filename, temp);

    FILE *f = fopen(temp, "a");

    // jumlah pengguna
    fprintf(f, "%d\n", user.CounterUser);

    int n;
    for(n=0; n<user.CounterUser; n++){
        fprintf(f, "%s\n", USER_NAMA(USER(user, n)).TabWord);
        fprintf(f, "%s\n", SANDI(USER(user, n)).TabWord);
        fprintf(f, "%s\n", BIO(USER(user, n)).TabWord);
        fprintf(f, "%s\n", HP(USER(user, n)).TabWord);
        fprintf(f, "%s\n", WETON(USER(user, n)).TabWord);
        if(PRIVACY(USER(user, n))){
            fprintf(f, "%s\n", "Privat");
        } else {
            fprintf(f, "%s\n", "Public");
        }
        for(int temp=0; temp < FOTO_ROW_EFF(FOTO(USER(user, n))); temp++){
            for(int temp2=0; temp2 < FOTO_COL_EFF(FOTO(USER(user, n)))-1; temp2++){
                fprintf(f, "%c %c ", COLOR(FOTO_ELMT(FOTO(USER(user, n)), temp, temp2)), ASCII(FOTO_ELMT(FOTO(USER(user, n)), temp, temp2)));
            }
            fprintf(f, "%c %c\n", COLOR(FOTO_ELMT(FOTO(USER(user, n)), temp, 4)), ASCII(FOTO_ELMT(FOTO(USER(user, n)), temp, 4)));
        }
    }
    // matriks pertemanan
    for(n = 0; n < user.CounterUser; n++){
        int j = 0;
        for(j = 0; j < user.CounterUser-1; j++){
            fprintf(f, "%d ", ElmtDaftarPertemanan(DaftarPertemanan, n, j));
        }
        fprintf(f, "%d\n", ElmtDaftarPertemanan(DaftarPertemanan, n, j));
    }

    // cek daftar pertemanan

    int i;
    int jumlah_request = 0;
    for(i=0; i<user.CounterUser; i++){
        jumlah_request += PERMINTAANPERTEMANAN(USER(user, i)).jumlah_permintaan;
    }

    fprintf(f, "%d\n", jumlah_request);
    // int jumlah = 0;
    // int j=0;
    for(i=0; i<user.CounterUser; i++){
        // jumlah = PERMINTAANPERTEMANAN(USER(user, i)).jumlah_permintaan;
        Address first = PERMINTAANPERTEMANAN(USER(user, i)).first;
        while(first != NULL){
            int asal = first->value.id;
            int tujuan = i;
            int jumlah_teman = first->value.jumlahTeman;
            fprintf(f, "%d %d %d\n", asal, tujuan, jumlah_teman);
            first = first->next;
        }
    }

    fclose(f);
}

void tulisKicauan(Word folder){
    char kicauan[] = "/kicauan.config";
    Word filename = ConcatWord(folder, CharToWord(kicauan));

    char tempF[filename.Length];
    WordToChar(filename, tempF);

    FILE *f = fopen(tempF, "a");

    // jumlah kicauan
    fprintf(f, "%d\n", ListKicauan.NEFF);

    int n=0;
    KICAUAN temp = KICAUAN_ELMT(ListKicauan, n);
    for(n=0; n<ListKicauan.NEFF-1; n++){
        fprintf(f, "%d\n", KICAU_ID(temp)+1);
        fprintf(f, "%s\n", KICAU_TEKS(temp).TabWord);
        fprintf(f, "%d\n", LIKE(temp));
        fprintf(f, "%s\n", KICAU_NAMAAUTHOR(temp).TabWord);
        DATETIME temp2 = KICAU_TIMECREATED(temp);
        fprintf(f, "%02d/%02d/%d %02d:%02d:%02d\r\n", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));
        temp = KICAUAN_ELMT(ListKicauan, n+1);
    }

    fprintf(f, "%d\n", KICAU_ID(temp)+1);
    fprintf(f, "%s\n", KICAU_TEKS(temp).TabWord);
    fprintf(f, "%d\n", LIKE(temp));
    fprintf(f, "%s\n", KICAU_NAMAAUTHOR(temp).TabWord);
    DATETIME temp2 = KICAU_TIMECREATED(temp);
    fprintf(f, "%02d/%02d/%d %02d:%02d:%02d", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));

    fclose(f);
}

void tulisUtas(Word folder){
    char utas[] = "/utas.config";
    Word filename = ConcatWord(folder, CharToWord(utas));

    char tempF[filename.Length];
    WordToChar(filename, tempF);

    FILE *f = fopen(tempF, "a");

    // jumlah utas
    fprintf(f, "%d\n", ListIdUtas.nEFF);

    int n=0;
    int i=0;
    int len;
    AddressUtas temp = KICAUAN_ELMT(ListKicauan, (ListIdUtas.buffer[n])).daftar_utas;
    for(n=0; n<ListIdUtas.nEFF-1; n++){
        fprintf(f, "%d\n", ListIdUtas.buffer[n]+1);
        len = lengthDaftarUtas(temp);
        fprintf(f, "%d\n", len);
        for (i = 0; i < len; i++){
            fprintf(f, "%s\n", temp->teks.TabWord);
            fprintf(f, "%s\n", temp->author.TabWord);
            DATETIME temp2 = temp->timeCreated;
            fprintf(f, "%02d/%02d/%d %02d:%02d:%02d\r\n", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));
            temp = NEXTDAFTARUTAS(temp);
        }
        temp = KICAUAN_ELMT(ListKicauan, (ListIdUtas.buffer[n+1])).daftar_utas;
    }

    fprintf(f, "%d\n", ListIdUtas.buffer[n]+1);
    len = lengthDaftarUtas(temp);
    fprintf(f, "%d\n", len);
    for (i = 0; i < len-1; i++){
        fprintf(f, "%s\n", temp->teks.TabWord);
        fprintf(f, "%s\n", temp->author.TabWord);
        DATETIME temp2 = temp->timeCreated;
        fprintf(f, "%02d/%02d/%d %02d:%02d:%02d\r\n", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));
        temp = NEXTDAFTARUTAS(temp);
    }
    fprintf(f, "%s\n", temp->teks.TabWord);
    fprintf(f, "%s\n", temp->author.TabWord);
    DATETIME temp2 = temp->timeCreated;
    fprintf(f, "%02d/%02d/%d %02d:%02d:%02d", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));
    fclose(f);
}

void tulisDraf(Word folder){
    char draf[] = "/draf.config";
    Word filename = ConcatWord(folder, CharToWord(kicauan));

    char tempF[filename.Length];
    WordToChar(filename, tempF);

    FILE *f = fopen(tempF, "a");

    // jumlah kicauan
    fprintf(f, "%d\n", ListKicauan.NEFF);

    int n=0;
    KICAUAN temp = KICAUAN_ELMT(ListKicauan, n);
    for(n=0; n<ListKicauan.NEFF-1; n++){
        fprintf(f, "%d\n", KICAU_ID(temp)+1);
        fprintf(f, "%s\n", KICAU_TEKS(temp).TabWord);
        fprintf(f, "%d\n", LIKE(temp));
        fprintf(f, "%s\n", KICAU_NAMAAUTHOR(temp).TabWord);
        DATETIME temp2 = KICAU_TIMECREATED(temp);
        fprintf(f, "%02d/%02d/%d %02d:%02d:%02d\r\n", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));
        temp = KICAUAN_ELMT(ListKicauan, n+1);
    }

    fprintf(f, "%d\n", KICAU_ID(temp)+1);
    fprintf(f, "%s\n", KICAU_TEKS(temp).TabWord);
    fprintf(f, "%d\n", LIKE(temp));
    fprintf(f, "%s\n", KICAU_NAMAAUTHOR(temp).TabWord);
    DATETIME temp2 = KICAU_TIMECREATED(temp);
    fprintf(f, "%02d/%02d/%d %02d:%02d:%02d", Day(temp2), Month(temp2), Year(temp2), Hour(Time(temp2)), Minute(Time(temp2)), Second(Time(temp2)));

    fclose(f);
}

void simpan(){
    Word folder;
    printf("Masukkan nama folder penyimpanan: ");
    readWord(&folder, ';');

    if(!isFolderExist(folder)){
        printf("Belum terdapat \"%s\". Akan dilakukan pembuatan \"%s\" terlebih dahulu.\n", folder.TabWord, folder.TabWord);
        createFolder(folder);
        redrawPrompt();
    }
    // create empty file
    createFiles(folder);


    // isi file
    tulisPengguna(folder);
    tulisKicauan(folder);
    tulisUtas(folder);
    tulisDraf(folder);

    redrawPromptFiles();
}