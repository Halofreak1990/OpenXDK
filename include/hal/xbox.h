#ifndef HAL_XBOX_H
#define HAL_XBOX_H

void XReboot();
int XGetTickCount();
void XSleep(int milliseconds);

void XLaunchXBE(char *xbePath);

#endif
