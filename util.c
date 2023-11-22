#include "util.h"
#include <unistd.h>

int strLen(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
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
            printf("'%s' is not a folder.\n", foldername.TabWord);
            return false;
        }
    } else {
        printf("Folder '%s' does not exist.\n", foldername.TabWord);
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

    while(currentChar != '\r'){
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
    fscanf(f, "%c", &currentChar);
}

void bacaPengguna(FILE* f){
    printf("baca pengguna called\n");
    
    char nUser[10];
    fgets(nUser, sizeof(nUser), f);
    strip(nUser, '\r');
    strip(nUser, '\n');
    int n_user = WordToInt(CharToWord(nUser));
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
        readHpFile(f, &hp);
        // fgets(hp, sizeof(hp), f);
        // strip(hp, '\r');
        fgets(weton, sizeof(weton), f);
        strip(weton, '\r');
        fgets(privacy, sizeof(privacy), f);
        strip(privacy, '\r');
        for(int i=0; i<5; i++){
            fgets(prof_pict[i], sizeof(prof_pict[i]), f);
            strip(prof_pict[i], '\r');
        }
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
            if(DaftarPertemanan.Tabword[i][j] == 1){
                n_teman++;
            }
        }
        JUMLAH_TEMAN(USER(user, i)) = n_teman-1;
    }

    PrintDaftarPertemanan(DaftarPertemanan);
    
    // permintaan pertemanan
    int banyakPermintaan;
    char nPermintaan[10];

    fgets(nPermintaan, sizeof(nPermintaan), f);
    strip(nPermintaan, '\r');
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

        } else if(strCompare(FileName.TabWord, "/kicauan.config")){

        } else if(strCompare(FileName.TabWord, "/utas.config")){

        }
    } else {
        printf("file \'%s\' not exist\n", filename);
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

    Word pengguna = CharToWord(char_pengguna);
    Word kicauan = CharToWord(char_kicauan);
    Word balasan = CharToWord(char_balasan);
    Word utas = CharToWord(char_utas);

    boolean stat1 = readFile(pengguna, foldername);
    boolean stat2 = readFile(kicauan, foldername);
    boolean stat3 = readFile(balasan, foldername);
    boolean stat4 = readFile(utas, foldername);

    if(!(stat1 && stat2 && stat3 && stat4)){
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
    system("clear");

    // welcome message
    printf(
"        \n"
" _______                       _______   __           \t\t ⠀⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣶⣶⡿⢋\n"
"|       \\                     |       \\ |  \\          \t\t ⠀⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋\n"
"| $$$$$$$\\ __    __   ______  | $$$$$$$\\ \\$$  ______  \t\t ⠀⠹⣿⣿⣿⣿⣶⣤⣤⣤⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀\n"
"| $$__/ $$|  \\  |  \\ /      \\ | $$__/ $$|  \\ /      \\ \t\t ⠀⣄⣈⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀\n"
"| $$    $$| $$  | $$|  $$$$$$\\| $$    $$| $$|  $$$$$$\\ \t\t ⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀\n"
"| $$$$$$$\\| $$  | $$| $$   \\$$| $$$$$$$\\| $$| $$   \\$$ \t\t ⠀⠀⣀⣉⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀\n"
"| $$__/ $$| $$__/ $$| $$      | $$__/ $$| $$| $$      \t\t ⠀⠀⠘⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀\n"
"| $$    $$ \\$$    $$| $$      | $$    $$| $$| $$      \t\t ⠀⠀⠀⠀⠀⢉⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀\n"
" \\$$$$$$$   \\$$$$$$  \\$$       \\$$$$$$$  \\$$ \\$$      \t\t ⠒⠶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀\n"
"                                                      \t\t ⠀⠀⠀⠉⠙⠛⠛⠛⠛⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"                                                      \t\t\n"
"                                                      \t\t\n"
    );
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
// static void redrawPrompt(void)
// {
//     int i;
//     int totalDots = 3;

//     printf("Mohon tunggu ");

//     for (i = 0; i < totalDots; ++i) {
//         printf(".");
//         fflush(stdout); // Flush the output buffer to make sure dots are printed immediately

//         // You can replace the sleep function with actual loading operations
//         // For demonstration purposes, sleep is used to simulate loading time
//         sleep(1); // Sleep for 1 second
//     }
//     endl;
// }

// static void redrawPromptFiles(void)
// {
//     int i;
//     int totalDots = 3;
//     char arr[5][20] = {"pengguna.config", "draf.config", "kicauan.config", "utas.config", "balasan.config"};

//     for(int f=0; f<5; f++){
//         printf("%d. Creating %s ", f+1, arr[f]);
//         for (i = 0; i < totalDots; ++i) {
//             printf(".");
//             fflush(stdout); // Flush the output buffer to make sure dots are printed immediately

//             // You can replace the sleep function with actual loading operations
//             // For demonstration purposes, sleep is used to simulate loading time
//             sleep(1); // Sleep for 1 second
//         }
//         endl;
//     }
// }

void createFolder(Word folder){
    int check;
    check = mkdir(folder.TabWord, 0777);
    if (!check)
        printf("Directory created\n");
    else {
        printf("Unable to create directory\n");
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

    Word pengguna = CharToWord(char_pengguna);
    Word kicauan = CharToWord(char_kicauan);
    Word balasan = CharToWord(char_balasan);
    Word utas = CharToWord(char_utas);

    pengguna = ConcatWord(folder, pengguna);
    kicauan = ConcatWord(folder, kicauan);
    balasan = ConcatWord(folder, balasan);
    utas = ConcatWord(folder, utas);
    
    createEmptyFile(pengguna);
    createEmptyFile(kicauan);
    createEmptyFile(balasan);
    createEmptyFile(utas);
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

    fclose(f);
}

void simpan(){
    Word folder;
    printf("Masukkan nama folder penyimpanan: ");
    readWord(&folder, ';');

    if(!isFolderExist(folder)){
        printf("Belum terdapat \"%s\". Akan dilakukan pembuatan \"%s\" terlebih dahulu.\n", folder.TabWord, folder.TabWord);
        createFolder(folder);
        // redrawPrompt();
    }
    // create empty file
    createFiles(folder);


    // isi file
    tulisPengguna(folder);

    // redrawPromptFiles();
}