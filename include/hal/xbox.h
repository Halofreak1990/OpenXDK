#ifndef HAL_XBOX_H
#define HAL_XBOX_H

#define XBOX_VIDEO_ADDRESS    (0xF0000000 + *(unsigned int*)0xFD600800)

void XReboot();
int  XGetTickCount();
void XSleep(int milliseconds);

void XLaunchXBE(char *xbePath);

// the thread callback function
typedef void (*XThreadCallback)(void *args1, void *args2);
int XCreateThread(XThreadCallback callback, void *args1, void *args2);

#endif
