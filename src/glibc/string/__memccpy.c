/* Copyright (C) 1991 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

#include <ansidecl.h>
#include <stddef.h>	/* For size_t and NULL.	*/


/*
 * Copy no more than N bytes of SRC to DEST, stopping when C is found.
 * Return the position in DEST one byte past where C was copied,
 * or NULL if C was not found in the first N bytes of SRC.
 */
PTR
DEFUN(__memccpy, (dest, src, c, n),
      PTR dest AND CONST PTR src AND int c AND size_t n)
{
  register CONST char *s = src;
  register char *d = dest;
  register CONST int x = (unsigned char) c;
  register size_t i = n;

  while (i-- > 0)
    if ((*d++ = *s++) == x)
      return d;

  return NULL;
}
