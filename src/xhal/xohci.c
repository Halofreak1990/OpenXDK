// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xohci.h
// *
// * note : XBox USB Open Host Controller Interface
// *
// ******************************************************************
#include "openxdk.h"
#include <stdio.h>

// ******************************************************************
// * xohci_init
// ******************************************************************
void xohci_init()
{
    xohci_pci_init();

    return;
}