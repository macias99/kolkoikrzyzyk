#include <stdio.h>
#include <stdlib.h>
 
#define GRACZ_O 'O'
#define GRACZ_X 'X'
#define GRACZ_NIEZNANY '\0'
#define GRACZ_REMIS (char)-1
 
void planszaInicjalizuj(char plansza[3][3]);
void planszaRysuj(char plansza[3][3]);
char planszaWynik(char plansza[3][3]);
int planszaCzyWygral(char plansza[3][3], char gracz);
int planszaCzyJestWolnePole(char plansza[3][3]);
void planszaPobierzRuch(char plansza[3][3], char gracz);
int planszaCzyPoleJestPrawidlowe(char plansza[3][3], int pole, int *ii, int *jj);
int pobierzLiczbe();
 
int main()
{
    char plansza[3][3];
    char gracz, wynik;
    int ruchy;
    planszaInicjalizuj(plansza);
    gracz = GRACZ_O;
    ruchy=0;
    while ((wynik = planszaWynik(plansza)) == GRACZ_NIEZNANY)
    {
        planszaRysuj(plansza);
        planszaPobierzRuch(plansza, gracz);
 
        if (gracz == GRACZ_O)
        {
            gracz = GRACZ_X;
        }
        else
        {
            gracz = GRACZ_O;
        }
    ruchy ++;
    }
    planszaRysuj(plansza);
    if (wynik == GRACZ_O || wynik == GRACZ_X)
    {
        printf("Wygrał gracz %c(gra zakończyła sie w %d ruchach)\n", wynik,ruchy);
    }
    else
    {
        printf("REMIS\n");
    }
 
    return 0;
}
 
void planszaInicjalizuj(char plansza[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            plansza[i][j] = GRACZ_NIEZNANY;
        }
    }
}
 
/*
-------------
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------
*/
 
void planszaRysuj(char plansza[3][3])
{
    int n;
 
    n = 1;
 
    for (int i = 0; i < 3; i++)
    {
        printf("-------------\n");
        printf("|");
 
        for (int j = 0; j < 3; j++)
        {
            if (plansza[i][j] == GRACZ_NIEZNANY)
            {
                printf(" %d |", n);
            }
            else
            {
                printf(" %c |", plansza[i][j]);
            }
            n++;
        }
 
        printf("\n");
    }
    printf("-------------\n");
}
 
char planszaWynik(char plansza[3][3])
{
    if (planszaCzyWygral(plansza, GRACZ_O))
    {
        return GRACZ_O;
    }
   
    if (planszaCzyWygral(plansza, GRACZ_X))
    {
        return GRACZ_X;
    }
 
    if (planszaCzyJestWolnePole(plansza))
    {
        return GRACZ_NIEZNANY;
    }
 
    return GRACZ_REMIS;
}
 
int planszaCzyWygral(char plansza[3][3], char gracz)
{
    if (plansza[0][0] == gracz && plansza[0][1] == gracz && plansza[0][2] == gracz) return 1;
    if (plansza[1][0] == gracz && plansza[1][1] == gracz && plansza[1][2] == gracz) return 1;
    if (plansza[2][0] == gracz && plansza[2][1] == gracz && plansza[2][2] == gracz) return 1;
   
    if (plansza[0][0] == gracz && plansza[1][0] == gracz && plansza[2][0] == gracz) return 1;
    if (plansza[0][1] == gracz && plansza[1][1] == gracz && plansza[2][1] == gracz) return 1;
    if (plansza[0][2] == gracz && plansza[1][2] == gracz && plansza[2][2] == gracz) return 1;
   
    if (plansza[0][0] == gracz && plansza[1][1] == gracz && plansza[2][2] == gracz) return 1;
    if (plansza[2][0] == gracz && plansza[1][1] == gracz && plansza[0][2] == gracz) return 1;
 
    return 0;
}
 
int planszaCzyJestWolnePole(char plansza[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (plansza[i][j] == GRACZ_NIEZNANY)
            {
                return 1;
            }
        }
    }
 
    return 0;
}
 
void planszaPobierzRuch(char plansza[3][3], char gracz)
{
    int pole, i, j;
 
    printf("GRACZ %c: ", gracz);
 
    while (1)
    {
        pole = pobierzLiczbe();
 
        if (planszaCzyPoleJestPrawidlowe(plansza, pole, &i, &j))
        {
            plansza[i][j] = gracz;
            break;
        }
        else
        {
            printf("Podaj prawidłowe pole: ");
        }
    }
}
 
int planszaCzyPoleJestPrawidlowe(char plansza[3][3], int pole, int *ii, int *jj)
{
    int n;
 
    n = 1;
 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (plansza[i][j] == GRACZ_NIEZNANY && n == pole)
            {
                *ii = i;
                *jj = j;
 
                return 1;
            }
 
            n++;
        }
    }
 
    return 0;
}
 
int pobierzLiczbe()
{
    int liczba;
 
    while (1)
    {
        if (scanf("%d", &liczba) == 1)
        {
            return liczba;
        }
 
        fseek(stdin, SEEK_END, 0);
        printf("Podaj prawidłową liczbę: ");
    }
}
