// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xvga.c
// *
// * note : XBox VGA
// *
// ******************************************************************
#include "xvga.h"
#include "xvga_def.h"

// ******************************************************************
// * static functions
// ******************************************************************
static void init_unchained(void);
static void write_vgareg(int port, int index, int value);

// ******************************************************************
// * init_unchained
// ******************************************************************
void init_unchained(void)
{
    uint08 x = 0;

    CRTC_WRITE(CRTC_REG_INDEX, 0x11);

    x = CRTC_READ(CRTC_REG_DATA) & 0x7F;

    CRTC_WRITE(CRTC_REG_INDEX, 0x11);

    CRTC_WRITE(CRTC_REG_DATA, x);
}

// ******************************************************************
// * write_vgareg
// ******************************************************************
void write_vgareg(int port, int index, int value)
{
    if(port == 0x03C0)
    {
        CRTC_WRITE(CRTC_REG_INDEX, index | 0x20);
        CRTC_WRITE(CRTC_REG_INDEX, value);
    }
    else if(port == 0x03C2)
    {
        MISC_WRITE(MISC_REG, value);
    }
    else if(port == 0x03C3)
    {
        *(char * const)0x000c03c3 = value;
    }
    else
    {
        char *real_port = 0;

        if(port == 0x03CE || port == 0x03CF || port == 0x03C4 || port == 0x03C5)
        {
            real_port = (char*)(port + 0xFD0C0000);
        }
        else
        {
            real_port = (char*)(port + 0xFD601000);
        }
	
        real_port[0] = index;
        real_port[1] = value;
    }
}

// ******************************************************************
// * xvga_setmode
// ******************************************************************
void xvga_setmode(xvga_mode mode)
{
    vga_reg *table = 0;
    uint32   tsize = 0;

    switch(mode)
    {
        case XVGA_MODE_256x240:
            table = xvga_mode_256x240;
            tsize = MODE256x240SIZE;
            break;
        case XVGA_MODE_320x240:
            table = xvga_mode_320x240;
            tsize = MODE320x240SIZE;
            break;
        case XVGA_MODE_320x200:
            table = xvga_mode_320x200;
            tsize = MODE320x200SIZE;
            break;
        default:
            return;
    }

    init_unchained();

    // ******************************************************************
    // * set mode registers
    // ******************************************************************
    {
        uint32 v = 0;

        for(v=0;v<tsize;v++)
            write_vgareg(table[v].port, table[v].index, table[v].value);
    }
}

// ******************************************************************
// * xvga_wait_vblank
// ******************************************************************
void xvga_wait_vblank()
{
    // wait until we are not vblank
    while(CRTC_READ(VERTICAL_BLANK) & 0x08);

    // wait until we are in vblank
    while(!(CRTC_READ(VERTICAL_BLANK) & 0x08));
}

// ******************************************************************
// * xvga_wait_vblank_end
// ******************************************************************
void xvga_wait_vblank_end()
{
    // wait until we are in vblank
    while(CRTC_READ(VERTICAL_BLANK) ^ 0x08);

    // wait until we are not vblank
    while(CRTC_READ(VERTICAL_BLANK) & 0x08);
}