#include <stdint.h>
#include <stdlib.h>
typedef uint8_t byte;	// 8-bit unsigned
typedef int8_t sbyte;	// 8-bit signed
typedef uint16_t word;	// 16-bit unsigned
typedef enum { false, true } bool; // boolean

//https://basicfantasy.org/downloads/BFRPG-Charts-and-Tables-by-Simone-Felli-r3.pdf
//Page 1 - Character Creation
typedef enum 
{
  STR, //Strength
  //•Melee attack rolls.
  //•Damage rolls when using a melee weapon or a thrown weapon (including slings)
  DEX, //Dexterity
  //•Ranged attack rolls (bows, crossbows, throwing axes)
  //•Armor Class (AC)
  //•Initiative die roll
  CON, //Constitution
  //•Hit Die
  //•Some saving throws vs. poison
  INT, //Intelligence
  //•Number of languages the character knows
  //•Some saving throws vs. illusion
  WIS, //Wisdom
  //•Some saving throws vs. magical attacks
  CHA //Charisma
    //•Reaction rolls
    //•Number of retainers a character may hire
  }ability; //This can be used for passing an ability type in a function
struct
{char Value[4];}AbilityName[6] = {{"STR"}, {"DEX"}, {"CON"}, {"INT"}, {"WIS"}, {"CHA"}};

struct 
{
  sbyte Modifier[19];
}AbilityBonus = 
{
  -3, // 0 - Not possble, use these for "Lord British" stats?
  -3, // 1
  -3, // 2
  -3, // 3 - Lowest possible
  -2, // 4
  -2, // 5
  -1, // 6
  -1, // 7
  -1, // 8
  0, // 9
  0, // 10
  0, // 11
  0, // 12
  1, // 13
  1, // 14
  1, // 15
  2, // 16
  2, // 17
  3, // 18
}; //Index = Level

/*Optional Skill Rolls
Level
Target
NM or 1 	17
2-3		16
4-5		15
6-7		14
8-9		13
10-11		12
12-13		11
14-15		10
16-17		9
18-19		8
20		7
Roll 1D20 + Ability Bonus/Penalty + Situational Bonus/Penalty >= Target number */

//Page 2 - Race Notes
struct{
  char Name[8];
  //Classes
  bool Cleric, MagicUser, Fighter, Thief, FighterMagicUser;
  //Min Ability Restriction
  ability MinAbilityRestriction;
  byte MinAbilityMinimum;
  //Max Ability Restriction
  ability MaxAbilityRestriction;
  byte MaxAbilityMinimum;
  //Hit Dice
  byte HitDiceMax;
  //Weapon Restrictions
  bool WeaponsMediumTwoHands, WeaponsLarge, WeaponsTwoHandedSwords, WeaponsPolearms, WeaponsLongbows;
  //Special Abilities
  bool Darkvision, DetectArchitecture, DetectDoors, ImmuneGhoulParalysis;
  byte ExpBonus, RangedAttackBonus, ACBonusMeleeVSLarge, InitiativeBonus, ChanceDetectedOutdoors, ChanceDetectedIndoors, SurpriseCheckRangeReduction;
  //Saving Throws Bonus
  byte SavingThrowDeathRayPoison, SavingThrowMagicWands, SavingTrowParalysisPetrify, SavingThrowDragonBreath, SavingThrowSpells;
}RaceDescription[4] =
{
  {
    "Dwarf",
    //Classes Allowed
    true,		 	//Cleric
    false,			//Magic-User
    true,			//Fighter
    true,			//Thief
    false,			//Fighter Magic-User

    //Min Ability Restriction
    CON, 9,
    //Max Ability Restriction
    CHA, 17,

    //Hit Dice
    20,

    //Weapon Restrictions
    false,			//WeaponsMediumTwoHands
    true,			//WeaponsLarge
    false,			//WeaponsTwoHandedSwords
    false,			//WeaponsPolearms
    false,			//WeaponsLongbows

    //Special Abilities
    true,			//Darkvision
    true, 			//DetectArchitecture
    false,			//DetectDoors
    false,			//ImmuneGhoulParalysis;
    0,				//ExpBonus
    0, 				//RangedAttackBonus
    0, 				//ACBonusMeleeVSLarge
    0,				//InitiativeBonus
    0,				//ChanceDetectedOutdoors
    0,				//ChanceDetectedIndoors
    0,				//SurpriseCheckRangeReduction
    //Saving Throws Bonus
    4,				//SavingThrowDeathRayPoison
    4,				//SavingThrowMagicWands
    4,				//SavingTrowParalysisPetrify
    3,				//SavingThrowDragonBreath
    4				//SavingThrowSpells
    },
  {
    "Human",
    //Classes Allowed
    true,		 	//Cleric
    true,			//Magic-User
    true,			//Fighter
    true,			//Thief
    false,			//Fighter Magic-User

    //Min Ability Restriction
    STR, 0,
    //Max Ability Restriction
    STR, 20,

    //Hit Dice
    20,

    //Weapon Restrictions
    false,			//WeaponsMediumTwoHands
    true,			//WeaponsLarge
    true,			//WeaponsTwoHandedSwords
    true,			//WeaponsPolearms
    true,			//WeaponsLongbows

    //Special Abilities
    false,			//Darkvision
    false, 			//DetectArchitecture
    false,			//DetectDoors
    false,			//ImmuneGhoulParalysis;
    10,				//ExpBonus in %
    0, 				//RangedAttackBonus
    0, 				//ACBonusMeleeVSLarge
    0,				//InitiativeBonus
    0,				//ChanceDetectedOutdoors
    0,				//ChanceDetectedIndoors
    0,				//SurpriseCheckRangeReduction
    //Saving Throws Bonus
    0,				//SavingThrowDeathRayPoison
    0,				//SavingThrowMagicWands
    0,				//SavingTrowParalysisPetrify
    0,				//SavingThrowDragonBreath
    0				//SavingThrowSpells
    },
  {
    "Halfling",
    //Classes Allowed
    true,		 	//Cleric
    false,			//Magic-User
    true,			//Fighter
    true,			//Thief
    false,			//Fighter Magic-User

    //Min Ability Restriction
    DEX, 9,
    //Max Ability Restriction
    STR, 17,

    //Hit Dice
    6,

    //Weapon Restrictions
    true,			//WeaponsMediumTwoHands
    false,			//WeaponsLarge
    true,			//WeaponsTwoHandedSwords
    true,			//WeaponsPolearms
    true,			//WeaponsLongbows

    //Special Abilities
    false,			//Darkvision
    false, 			//DetectArchitecture
    false,			//DetectDoors
    false,			//ImmuneGhoulParalysis;
    0,				//ExpBonus in %
    1, 				//RangedAttackBonus
    2, 				//ACBonusMeleeVSLarge
    1,				//InitiativeBonus
    10,				//ChanceDetectedOutdoors
    30,				//ChanceDetectedIndoors
    0,				//SurpriseCheckRangeReduction
    //Saving Throws Bonus
    4,				//SavingThrowDeathRayPoison
    4,				//SavingThrowMagicWands
    4,				//SavingTrowParalysisPetrify
    3,				//SavingThrowDragonBreath
    4				//SavingThrowSpells
    },
  {
    "Elf",
    //Classes Allowed
    true,		 	//Cleric
    true,			//Magic-User
    true,			//Fighter
    true,			//Thief
    true,			//Fighter Magic-User

    //Min Ability Restriction
    INT, 9,
    //Max Ability Restriction
    CON, 17,

    //Hit Dice
    6,

    //Weapon Restrictions
    false,			//WeaponsMediumTwoHands
    true,			//WeaponsLarge
    true,			//WeaponsTwoHandedSwords
    true,			//WeaponsPolearms
    true,			//WeaponsLongbows

    //Special Abilities
    true,			//Darkvision
    false, 			//DetectArchitecture
    true,			//DetectDoors
    true,			//ImmuneGhoulParalysis;
    0,				//ExpBonus in %
    0, 				//RangedAttackBonus
    0, 				//ACBonusMeleeVSLarge
    0,				//InitiativeBonus
    0,				//ChanceDetectedOutdoors
    0,				//ChanceDetectedIndoors
    0,				//SurpriseCheckRangeReduction
    //Saving Throws Bonus
    0,				//SavingThrowDeathRayPoison
    2,				//SavingThrowMagicWands
    1,				//SavingTrowParalysisPetrify
    0,				//SavingThrowDragonBreath
    2				//SavingThrowSpells
    }
}; 

//Page 3 - Class Advancement Tables
//Page 4 - Class Notes, Saving Throws
//Index = Level

byte ExpMultiplier[20] = {1, 1, 2, 4, 8, 16, 28, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60};
byte HitDiceQuantity[20] = { 1, 2,3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
byte SpellsLevel[2][6][20] = 
{
  //Cleric Spells
  0, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6,	//Level 1
  0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5,	//Level 2
  0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5,	//Level 3
  0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4,	//Level 4
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3,	//Level 5
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3,	//Level 6

  //Magic-User Spells
  1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6,	//Level 1
  0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5,	//Level 2
  0, 0,	0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4,	5, 5,	//Level 3
  0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4,	//Level 4
  0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4,	//Level 5
  0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3	//Level 6
  };

struct
{
  char Name[12];
  int ExpBase;
  byte HitDiceSize;
  byte HitDiceBonus[20];
}ClassDescription[4] = 
{
  {"Cleric",
    //Exp Base
    1500,
    //Hit Dice Size
    6,
    //Hit Dice Bonus
   0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    },
  {
    "Magic-User",
    //Exp Base
    2500,
    //Hit Dice Size
    4,
    //Hit Dice Bonus
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    },
  {"Fighter",//Fighter
   //Exp Base
   2000,
   //Hit Dice Size
   8,
   //Hit Dice Bonus
   0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6,		//Level 12
   8,		//Level 13
   10,		//Level 14
   12,		//Level 15
   14,		//Level 16
   16,		//Level 17
   18,		//Level 18
   20,		//Level 19
   22		//Level 20
   },
  {"Thief",//Thief
   //Exp Base
   1250,
   //Hit Dice Size
   4,
   //Hit Dice Bonus
   0,		//Level 1
   0,		//Level 2
   0,		//Level 3
   0,		//Level 4
   0,		//Level 5
   0,		//Level 6
   0,		//Level 7
   0,		//Level 8
   0,		//Level 9
   2,		//Level 10
   4,		//Level 11
   6,		//Level 12
   8,		//Level 13
   10,		//Level 14
   12,		//Level 15
   14,		//Level 16
   16,		//Level 17
   18,		//Level 18
   20,		//Level 19
   22		//Level 20
   }
};