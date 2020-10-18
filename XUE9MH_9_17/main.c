#include <stdio.h>
#include <stdlib.h>

#define N 7

typedef enum szin {KEK, PIROS, ZOLD, FEKETE, FEHER , END} Szin;
char * szinek[5] = {"KEK", "PIROS", "ZOLD", "FEKETE", "FEHER" };

typedef struct{
    char rendszam[7];
    char tipus[255];
    Szin szin;
    int ar;
} Auto;

typedef struct{
    char Name[50];
    char Surname[50];
    int ID;
} person;

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

void readAuto( FILE *f , int index , Auto* a){
    fseek(f , sizeof(Auto) * index , SEEK_SET );
    fread( a , sizeof(Auto) , 1 , f );
    return;
}

void autoAdatai( Auto *a ){
    printf("%s\n%s\n%d\n%s\n\n",a->rendszam, a->tipus , a->ar, szinek[a->szin] );
    return;
}
/*
void readPersonFromUser( person *p){
    printf("Adj meg egy nevet");
    gets(p->nev);
    printf("Hany eves %s:",p->nev);
    sscanf("%d", &p->azonosito );
}*/

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa uj = (BiFa) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}
//Elso feladat - nem tudom mit ért Tanár úr B-fa alatt én bináris fát gondolom így azt csinálom meg.
void f1()
{
    int minta[] = {6, 12, 9, 2, 5, 4, 15, 20, 1, 3, 10, 14, 17, 16, 21, 25, 24};
    BiFa *gyoker = NULL;
    int i;
    for (i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    return;
}

void upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}

void f2()
{
    FILE *fp;
    char ch;
    char fnev[50];
    printf("Filenev: ");
    scanf("%s",fnev);
    fp=fopen(fnev,"w");
    printf("Uzenet: ");
    while((ch=getchar()) !='#')
    {
        putc(ch,fp);
    }
    fclose(fp);

    fp=fopen(fnev,"r");
    while((ch=getc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    fp=fopen(fnev,"r");
    upper_string(fp);
    while((ch=getc(fp)) != EOF)
    {
        putc(ch,fp);
    }
    fclose(fp);
    return ;
}

void f3( char * fn1, char * fn2 ){
    FILE* f1 = fopen( fn1 , "r" );
    FILE* f2 = fopen( fn2 , "w" );
    if( f1 == NULL ){
        printf("Hiba %s", fn1);
    }
    if( f2 == NULL ){
        printf("Hiba %s", fn2);
    }
    char c;
    while( (c = fgetc(f1))!= EOF )
        fputc(c, f2);

    fflush(f2);
    fclose(f1);
    fclose(f2);
    return;
}

void f4(){
    FILE* f = fopen( "auto.bin", "wb" );
    if( f == NULL ){
        printf("Hiba\n");
    }
    Auto autok[N];
    int i;
    for( i = 0; i < N; i++ ){
        sprintf(autok[i].rendszam, "%c%c%c%d%d%d", 'A' + (rand() % 26), 'A' + (rand() % 26), 'A' + (rand() % 26) ,1 + rand()%9,1 + rand()%9,1 + rand()%9);
        autok[i].ar = 500000+rand()%2000000;
        autok[i].szin = rand() % END;
        sprintf(autok[i].tipus, "Fiat" );
        autoAdatai( &autok[i] );
    }
    fwrite( autok , sizeof(Auto) , N , f);
    fflush(f);
    fclose(f);

    f = fopen( "auto.bin", "rb" );
    if( f == NULL ){
        printf("Hiba\n");
    }
    fseek(f, 0, SEEK_END );
    int n = ftell(f) / sizeof(Auto);

    printf("Hanyadikat olvassuk(1..%d): ",n);
    scanf("%d", &i);

    Auto a;
    if( i > 0 && i <= n ){
    readAuto( f , i-1 , &a );
    autoAdatai( &a );
    } else
        printf("Invalid index" );
    fclose(f);
    return;
}

void AddEntry (person people[]) {
    counter++;
    printf("\nKeresztnev: ");
    scanf("%s", people[counter-1].Name);
    printf("Vezeteknev: ");
    scanf("%s", people[counter-1].Surname);
    printf("A szemely azonositoja: ");
    scanf("%d", &people[counter-1].ID);
    printf("\n%s hozza lett adva\n", people[counter-1].Name);
}

void DeleteEntry (person people[]){
    int x = 0;
    char deleteName[50];
    char deleteSurname[50];
    char nullStr[50] = {"\0"};
    int ID = 0;
    printf("\nAdd meg a keresztnevet: ");
    scanf("%s", deleteName);
    printf("Add meg a vezeteknevet: ");
    scanf("%s", deleteSurname);
    for (x = 0; x < counter; x++)
    {
        if (strcmp(deleteName, people[x].Name) == 0)
        {
            for (x = 0; x < counter; x++)
            {
                if (strcmp(deleteSurname, people[x].Surname) == 0)
                {
                    strcpy(people[x].Name, nullStr);
                    strcpy(people[x].Surname, nullStr);
                    people[x].ID = 0;
                    printf("Ki lett torolve a szemely.\n");
                    counter--;
                    break;
                }
            }
        }
        else printf("Nincs ilyen szemely.\n");
    }
}

void PrintEntry (person people[]) {
    int x = 0;
    printf("\nSzemelyek:\n");
    for ( x = 0; x < counter; x++) {
        printf("\n(%d)\n", x+1);
        printf("Nev: %s %s\n", people[x].Name, people[x].Surname);
        printf("ID: %d\n", people[x].ID);
    }
}

void f5(){
    FILE *fbe, *fki;
    fbe = fopen("szemelyek.dat", "rb");
    fki = fopen("szemelyek.dat", "wb");

    person people[50];
    char userChoice;
    while (userChoice != 'Q') {
        printf ("***************\n");
        printf("'A': Hozza add egy szemelyt\n");
        printf("'D': Torol egy szemelyt\n");
        printf("'P': Kiirja a szemelyeket\n");
        printf("'Q': Kilep\n");
        printf ("***************\n");
        scanf("%s", &userChoice);
        if (userChoice == 'A')
            AddEntry(people);
        if (userChoice == 'D')
            DeleteEntry (people);
        if (userChoice == 'P')
            PrintEntry(people);
        if (userChoice == 'Q') {
            printf("Quit.");
            return 0;
        }
    }
}

void f6(){
    FILE* f = fopen( "auto.txt", "rb" );
    if( f == NULL ){
        printf("Hiba\n");
    }
    fseek(f, 0, SEEK_END );
    int n = ftell(f) / sizeof(Auto);

    Auto *autok;
    autok = calloc(n , sizeof(Auto) );
    if( autok == NULL ){
        printf("Hiba\n");
    }

    int i, pirosak =0, imax=0;
    double atlag = 0;
    for( i = 0; i < n; i++ ){
        readAuto( f , i , autok+i);
        autoAdatai( autok + i );
        atlag += autok[i].ar;
        if(autok[i].szin==PIROS)
            pirosak++;
        if( autok[i].ar >autok[imax].ar )
            imax = i;
    }
    atlag /= n;
    printf("Az autok atlagara: %.2lfft\n%d piros auto van\nLegdragebb auto: \n", atlag, pirosak);
    Auto *legdargabbA;
    legdargabbA = (autok + imax);

    autoAdatai(legdargabbA);
    close(f);
    return;
}


int main(void) {
    f1();
    f2();
    //f3( argv[1] , argv[2] );
    f4();
    //f5();
    f6();

    return 0;
}
