#include "BFRPG.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <string.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>

byte x, y;
void main(void) {
  //clrscr();
  for (x = 0; x < 19; ++x)
  {
  printf("Ability Modifier Score %d:  %d\n", x, AbilityBonus.Modifier[x]);
  }
  
  for (x = 0; x < 4; ++x)
  {
    printf("%s\n", RaceDescription[x].Name);    
  }
  
  for (x = 0; x < 4; ++x)
  {
    printf("%s\n", ClassName[x].Value);
  }
  //getchar();
}
