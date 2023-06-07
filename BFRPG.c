#include "BFRPG.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <string.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>

byte x, y, z;
void main(void) {
  //clrscr();
  //for (x = 0; x < 19; ++x)
  //{
  //printf("Ability Modifier Score %d:  %d\n", x, AbilityBonus.Modifier[x]);
  //}
  
  //for (x = 0; x < 4; ++x)
  //{
    //printf("%s\n", RaceDescription[x].Name);    
  //}
  
  /*for (x = 0; x < 4; ++x)
  {
    printf("%s\n", ClassDescription[x].Name);
    for (y = 0; y < 20; ++y)
    {
      //printf("%d\n", ClassDescription[x].HitDiceBonus[y]);
      printf("%d %d %d\n", ExpMultiplier[y], ClassDescription[x].ExpBase, ExpMultiplier[y] * ClassDescription[x].ExpBase);
    } 
  }*/
  
  for (z = 0; z < 2; ++z)
  {
    for(x = 0; x < 20; ++x)
    {
      for(y = 0; y < 6; ++y)
      {
        printf("%d ", SpellsLevel[z][y][x]);
      }
      printf("\n");
    }
   printf("\n"); 
  }
  //getchar();
}
