/* Definisi type boolean */

#ifndef _BOOLEAN_h
#define _BOOLEAN_h

#if defined(_WIN32)
    typedef unsigned char boolean;
#else
    #define boolean unsigned char
#endif

#define true 1
#define false 0

#endif