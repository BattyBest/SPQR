/* HOW TO WRITE IN THIS FILE
 *
 * This is to keep this file readable and the codebase easily editable.
 *
 * 1. Be verbose.
 * A smaller source file size is not worth sacrificing readability. It compiles to the same thing, write it out.
 * 2. Name things accordingly
 * While an int variable may be an int variable, dont name it 'int1', it's not helpful, instead name it something more appropriate, like 'MoneyInTreasury'
 * 3. No bracing rules.
 * As long as its correct, syntax does not matter. Just keep it readable
 * 4. Explanatory comments
 * Your comments should not be:
 * // Declares an int named x with the value 3
 * int x = 3;
 * They should be like:
 * // Declares x with 3 to be used as a counter later
 * int x = 3;
 * Similarly,
 * Dont:
 * //declares a function
 * int myOinkyFunction(int[] numList) {
 * Do:
 * // *Purpose of function in relation to the rest of the program*
 * int myOinkyFunction(int[] numList) {
 * 5. Use snakeCase (first letter lowercase, words uppercase, eg. thisIsASentenceInSnakeCase)
 * 6. Explain acronyms in comments, eg.
 * // tiacv stands for 'This is a counter variable'
 * int tiacv = 0;
 *
 * Thanks for reading this, and remember to follow it!
 *
 */
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

// Senatorplate stands for Senator Baseplate

struct Senatorplate {
    char Name[30];
    int PoliticalAlignment;
    int Age;
    int Faction;
    int Popularity;
    int BirthMonth;
};
struct Senatorplate Senators[75] = {{"Very Generic Senator", 5, 21, 0, 50, 6}};

/* Function to 'Declare' senators
 * Takes in all of the senator values and puts them into the 'Senators' array
 */

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

// Checks for each keypad press, and return an int value
// 1-9 is keypad
// 10 is enter

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
// Game initialization
// Sets the starter senators, new game will generate more senators by replacing the items in the Senators array
// Loading existing game will completely replace them anyway

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
//Clears the screen completely, and moves the cursor the the top-left
void ClearScreen(void) {fontlib_ClearWindow();fontlib_HomeUp();}


// Main game loop
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

// Closes the game

void SPQR_Shutdown(void)
{
    gfx_End();
}

// Calls the functions, also main

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
