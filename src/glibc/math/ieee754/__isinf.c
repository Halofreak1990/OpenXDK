/* Copyright (C) 1991, 1992 Free Software Foundation, Inc.
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
#include <math.h>
#include "ieee754.h"

/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
__CONSTVALUE int
DEFUN(__isinf, (value), double value)
{
  union ieee754_double u;

  u.d = value;
  /* An IEEE 754 infinity has an exponent with the
     maximum possible value and a zero mantissa.  */
  if ((u.ieee.exponent & 0x7ff) == 0x7ff &&
      u.ieee.mantissa0 == 0 && u.ieee.mantissa1 == 0)
    return u.ieee.negative ? -1 : 1;

  return 0;
}
