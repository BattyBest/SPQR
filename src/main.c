#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include <libload.h>
#include <graphx.h>
#include <keypadc.h>
#include <compression.h>
#include <stdio.h>
#include <fontlibc.h>
#include <string.h>
#include <SPQRFON.h>
#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define NUM_ROWS(a) ARRAYSIZE(a)
#define NUM_COLS(a) ARRAYSIZE(a[0])

// Incredibly boring initialization, *yawn*

struct Senatorplate {
    char Name[30];
    int PoliticalAlignment;
    int Age;
    int Faction;
    int Popularity;
    int BirthMonth;
};
struct Senatorplate Senators[75] = {{"Very Generic Senator", 5, 21, 0, 50, 6}};

int DeclareSenator(int n, char N[], int P, int A, int F, int P2, int B);
int DeclareSenator(int n, char Name[], int PoliticalAlignment, int Age, int Faction, int Popularity, int BirthMonth) 
{
    strcpy(Senators[n].Name, Name);
    Senators[n].PoliticalAlignment = PoliticalAlignment;
    Senators[n].Age = Age;
    Senators[n].Faction = Faction;
    Senators[n].Popularity = Popularity;
    Senators[n].BirthMonth = BirthMonth;
    return 0;
}

// Back to boring definitions

char output[] = "";
bool Keypress = false;

int SPQR_CheckKeypadPress(void)
{
    kb_Scan();
    if (kb_Data[3] & kb_1) {
        Keypress = true;
        if (Keypress == false)
            return 1;
    }
    if (kb_Data[3] & kb_4) {
        Keypress = true;
        if (Keypress == false)    
            return 4;
    }
    if (kb_Data[3] & kb_7) {
        Keypress = true;
        if (Keypress == false)
            return 7;
    }
    if (kb_Data[4] & kb_2) {
        Keypress = true;
        if (Keypress == false)
        return 2;
    }
    if (kb_Data[4] & kb_5) {
        Keypress = true;
        if (Keypress == false)
            return 5;
    }
    if (kb_Data[4] & kb_8) {
        Keypress = true;
        if (Keypress == false)
            return 8;
    }
    if (kb_Data[5] & kb_3) {
        Keypress = true;
        if (Keypress == false)
            return 3;
    }
    if (kb_Data[5] & kb_6) {
        Keypress = true;
        if (Keypress == false)
            return 6;
    }
    if (kb_Data[5] & kb_9) {
        Keypress = true;
        if (Keypress == false)
            return 9;
    }
    if (kb_Data[6] & kb_Enter) {
        Keypress = true;
        if (Keypress == false)
            return 10;
    }
    Keypress = false;
    return 0;
}
void SPQR_Gameinit(void) {
    gfx_Begin();
    fontlib_SetFont(SPQRFontPtr, 0);
    // *GASP* *SHOCK* *INTENSE SCREECHING* OMG LOOK ITS CAESAR :00000000000000000000
    // Defines various historical and important senators
    DeclareSenator(1, "Gaius Julius Ceasar", 10, 39, 1, 90, 7);
    DeclareSenator(2, "Marcus Antonius", 8, 22, 1, 85, 1);
    DeclareSenator(3, "Marcus Tullius Cicero", 4, 46, 3, 60, 1);
    DeclareSenator(4, "Marcus Porcius Cato", 0, 35, 2, 63, 6);
}
void ClearScreen(void) {fontlib_ClearWindow();fontlib_HomeUp();}
void SPQR_GameStart() 
{
    int QuitCon = 0;
    while (QuitCon == 0) {
        int pressKey = SPQR_CheckKeypadPress();
        if (pressKey == 10) {
            QuitCon = 1;
        }
        if (pressKey == 2) {
            ClearScreen();
            fontlib_DrawString(Senators[1].Name);
        }
    }
}

void SPQR_Shutdown(void)
{
    gfx_End();
}

int main(void)
{
    os_ClrHome();

    if ((libload_IsLibLoaded(GRAPHX) == false) || (libload_IsLibLoaded(KEYPADC) == false)) 
    {
        os_PutStrFull("A library is missing, check your clibs.");
        return 10;
    } else {
        os_PutStrFull("Good jub, everything loaded :)");
    }
    SPQR_Gameinit();
    SPQR_GameStart();
    SPQR_Shutdown();

    return 0;
}