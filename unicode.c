#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#endif

int main(){
  printf(" %s\n", SPADE);
  printf(" %s\n", CLUB);
  printf(" %s\n", HEART);
  printf(" %s\n", DIAMOND);
  return 0;
}
