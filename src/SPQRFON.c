#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include <libload.h>
#include <graphx.h>
#include <keypadc.h>
#include <compression.h>
#include <stdio.h>
#include <fontlibc.h>
#include <SPQRFON.h>
static const uint8_t SPQRFONDATA[] = {
    #include "SPQRFONT.inc"
};

const fontlib_font_t *SPQRFontPtr = (fontlib_font_t *)SPQRFONDATA;