#include "BFRPG.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <string.h>
#if defined (__C64__)
#include <c64.h>
#include <cbm_petscii_charmap.h>
#endif
void PrintAbilityModifiers();
void PrintRaceDescriptions();
void PrintClassDescriptions();
void PrintSpells();
void PrintSpecialAbilities();
void PrintSavingThrows();
void PrintSpellNames();
byte x, y, z;
void main(void) 
{
  //PrintAbilityModifiers();
  //PrintRaceDescriptions();
  //PrintClassDescriptions();
  //PrintSpells();
  //PrintSpecialAbilities();
  //PrintSavingThrows();
  PrintSpellNames();
}
void PrintSpellNames()
{
  clrscr();
  printf("Magic-User Spells:\n");
  for (y = 0; y < 6; ++y)
  {
    printf("\nLevel %d\n", y + 1);
    for (x = 0; x < 12; ++x)
    {
      printf("%s\n", MagicUserSpellsName[y][x]);
    }
  }
  getchar();
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
    printf("\n%s EXP to reach\n", ClassDescription[x].Name);
    printf("EXP Base: %d\n", ClassDescription[x].ExpBase);
    printf("Hit Dice: %d\n", ClassDescription[x].HitDiceSize);
    printf("Special Abilities: %d\n", ClassDescription[x].CountSpecialAbilities);
    printf("Prime Req: %s\n", AbilityName[ClassDescription[x].PrimeReq].Value);
    printf("Armor Type: %s\n", ArmorTypeName[ClassDescription[x].Armor].Value);
    printf("Shield Type: %s\n", ShieldTypeName[ClassDescription[x].Shield].Value);
    for (y = 0; y < 19; ++y)
    {
      //printf("Level %d ", y + 2);
      //printf("Hit Dice Bonus: %d\n", ClassDescription[x].HitDiceBonus[y]);
      //printf("EXP %d x %d\n", ExpMultiplier[y], ClassDescription[x].ExpBase);
    }
    printf("\nSpecial Abilities: \n");
    for (y = 0; y < ClassDescription[x].CountSpecialAbilities; ++y)
    {
      printf("%s\n", SpecialAbilityName[ClassDescription[x].FirstSpecialAbility + y].Value);
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

void PrintSpecialAbilities()
{
  clrscr();
  printf("Special Abilities\n");
  for (y = 0; y < 4; ++y)
  {
    printf("%s\n", ClassDescription[y].Name);
    for (x = 0; x < ClassDescription[y].CountSpecialAbilities; ++x)
    {
      printf("%s\n", SpecialAbilityName[x]);
    }
  }
  getchar();
}

void PrintSavingThrows()
{
  clrscr();
  printf("Special Abilities\n");
  for (y = 0; y < 4; ++y)
  {
    printf("\n%s\n", ClassDescription[y].Name);
    for (x = 0; x < 20; ++x)
    {
      for (z = 0; z < 5; ++z)
      {
        if(SavingThrow[y][z][x] < 10)
          printf(" ");
        printf("%d ", SavingThrow[y][z][x]);
      }
      printf("\n");
    }
  }
  getchar();
}