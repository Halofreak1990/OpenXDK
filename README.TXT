OpenXDK

This is an open development environment to create applications on the XBOX.  
In summary, it has the following features (and limitations):

- Working libc layer (fopen, malloc, times, etc).  alloca is not supported.
- Multimedia support via SDL.  Video resolution is currently limited to 640x480. 
  If you specify a smaller resolution, OpenXDK will centre it on your monitor.
  If you specify a larger resolution, it will probably fall over.
- Gamepad support. Currently supports only one joystick, but the support for
  multiple gamepads will be coming soon.
- Audio support for 16 bit stereo 44.1kHz samples
  
For more documentation, see the doc directory.