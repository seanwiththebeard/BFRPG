#include "BFRPG.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <string.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>
void PrintAbilityModifiers();
void PrintRaceDescriptions();
void PrintClassDescriptions();
void PrintSpells();
byte x, y, z;
void main(void) 
{
  //PrintAbilityModifiers();
  //PrintRaceDescriptions();
  //PrintClassDescriptions();
  PrintSpells();
}

void PrintAbilityModifiers()
{
  clrscr();
  printf("Ability Modifiers:\n");
  for (x = 0; x < 19; ++x)
  {
    printf("Score %d:", x);
    if (x < 10)
      printf(" ");
    if (AbilityBonus.Modifier[x] >= 0)
      printf("+");
    printf("%d\n",AbilityBonus.Modifier[x]);
  }
  getchar();
}
void PrintRaceDescriptions()
{
  for (x = 0; x < 4; ++x)
    printf("%s\n", RaceDescription[x].Name);
  for (x = 0; x < 6; ++x)
  {
    printf("%s\n", AbilityName[x].Value);
    
  }
  
}

void PrintClassDescriptions()
{
  for (x = 0; x < 4; ++x)
  {
    printf("%s\n", ClassDescription[x].Name);
    for (y = 0; y < 20; ++y)
    {
      printf("%d\n", ClassDescription[x].HitDiceBonus[y]);
      printf("%d %d %d\n", ExpMultiplier[y], ClassDescription[x].ExpBase, ExpMultiplier[y] * ClassDescription[x].ExpBase);
    } 
  }
  getchar();
}

void PrintSpells()
{
  clrscr();
  for (z = 0; z < 2; ++z)
  {
    for(x = 0; x < 20; ++x)
    {
      printf("%s Spells Level %d: ", ClassDescription[z].Name, y);
      
      for(y = 0; y < 6; ++y)
      {
        //printf("%d ", ClassDescription[z].SpellsLevel[y][x]);
        printf("%d ", SpellsLevel[z][y][x]);
      }
      printf("\n");
    }
    printf("\n");
  }
  getchar();
}