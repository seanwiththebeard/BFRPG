#include <stdint.h>
#include <stdlib.h>
#if defined (__C64__)
#include <cbm_petscii_charmap.h>
#endif
typedef uint8_t byte;	// 8-bit unsigned
typedef int8_t sbyte;	// 8-bit signed
typedef uint16_t word;	// 16-bit unsigned
typedef enum { false, true } bool; // boolean

//https://basicfantasy.org/downloads/BFRPG-Charts-and-Tables-by-Simone-Felli-r3.pdf
//Page 1 - Character Creation
typedef enum 
{
  STR, //Strength
  #define STR 0
  //•Melee attack rolls.
  //•Damage rolls when using a melee weapon or a thrown weapon (including slings)
  DEX, //Dexterity
  #define DEX 1
  //•Ranged attack rolls (bows, crossbows, throwing axes)
  //•Armor Class (AC)
  //•Initiative die roll
  CON, //Constitution
  #define CON 2
  //•Hit Die
  //•Some saving throws vs. poison
  INT, //Intelligence
  #define INT 3
  //•Number of languages the character knows
  //•Some saving throws vs. illusion
  WIS, //Wisdom
  #define WIS 4
  //•Some saving throws vs. magical attacks
  CHA //Charisma
    #define CHA 5
    //•Reaction rolls
    //•Number of retainers a character may hire
  }Ability; //This can be used for passing an ability type in a function
struct {char Value[4];}AbilityName[6] = {{"STR"}, {"DEX"}, {"CON"}, {"INT"}, {"WIS"}, {"CHA"}};
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
  Ability MinAbilityRestriction;
  byte MinAbilityMinimum;
  //Max Ability Restriction
  Ability MaxAbilityRestriction;
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

byte ExpMultiplier[19] = {1, 1, 2, 4, 8, 16, 28, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60};
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

//typedef enum { ARMOR_NO, ARMOR_LEATHER, ARMOR_ANY } ArmorType;
//typedef enum { SHIELD_NO, SHIELD_PENALTY, SHIELD_ANY } ShieldType;
#define ARMOR_NO 0
#define ARMOR_LEATHER 1
#define ARMOR_ANY 2
#define SHIELD_NO 0
#define SHIELD_PENALTY 1
#define SHIELD_ANY 2

struct {char Value[9];}ArmorTypeName[3] = {"None", "Leather", "Any"};
struct {char Value[9];}ShieldTypeName[3] = {"None", "Penalty", "Any"};

struct
{
  char Name[12];
  int ExpBase;
  byte HitDiceSize;
  byte FirstSpecialAbility;
  byte CountSpecialAbilities;
  byte PrimeReq;
  byte Armor;
  byte Shield;
  byte HitDiceBonus[20];
}ClassDescription[4] = 
{
  {"Cleric",
   //Exp Base
   1500,
   //Hit Dice Size
   6,
   //SpecialAbilities
   1, 2,
   //Prime Req
   WIS,
   //ArmorType
   ARMOR_ANY, SHIELD_ANY,
   //Hit Dice Bonus
   0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
   },
  {"Magic-User",
   //Exp Base
   2500,
   //Hit Dice Size
   4,
   //SpecialAbilities
   3, 2,
   //Prime Req
   INT,
   //ArmorType
   ARMOR_NO, SHIELD_NO,
   //Hit Dice Bonus
   0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
   },
  {"Fighter",
   //Exp Base
   2000,
   //Hit Dice Size
   8,
   //SpecialAbilities
   0, 1,
   //Prime Req
   STR,
   //ArmorType
   ARMOR_ANY, SHIELD_ANY,
   //Hit Dice Bonus
   0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22
   },
  {"Thief",
   //Exp Base
   1250,
   //Hit Dice Size
   4,
   //SpecialAbilities
   5, 8,
   //Prime Req
   DEX,
   //ArmorType
   ARMOR_LEATHER, SHIELD_PENALTY, //Metal armor and shields interfere with stealthy activities
   //Hit Dice Bonus
   0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22
   }
};

typedef enum 
{
  Ability_Null,
  Ability_TurnUndead,
  Ability_CastDivine,
  Ability_ReadMagic,
  Ability_CastArcane,
  Ability_OpenLock,
  Ability_RemoveTrap,
  Ability_PickPocket,
  Ability_MoveSilently,
  Ability_ClimbWall,
  Ability_Hide,
  Ability_Listen,
  Ability_SneakAttack,
  }SpecialAbility;

struct{char Value[14];}SpecialAbilityName[13] = {"Null", "Turn Undead", "Cast Divine", "Read Magic", "Cast Arcane", "Open Lock", "Remove Trap", "Pick Pocket", "Move Silently", "Climb Wall", "Hide", "Listen", "Sneak Attack"};

SpecialAbility SpecialAbilities_Cleric[2] = {Ability_TurnUndead, Ability_CastDivine};
SpecialAbility SpecialAbilities_MagicUser[2] = {Ability_ReadMagic, Ability_CastArcane};
SpecialAbility SpecialAbilities_Fighter[1] = {Ability_Null};
SpecialAbility SpecialAbilities_Thief[8] = {Ability_OpenLock, Ability_RemoveTrap, Ability_PickPocket, Ability_MoveSilently, Ability_ClimbWall, Ability_Hide, Ability_Listen, Ability_SneakAttack};

//Saving Throws (SavingThrow[Class][Type][Level])
//* Poison saving throws are always adjusted by the Constitution bonus of the character.
//* Saving throws against illusions (such as phantasmal force) are always adjusted by the character's Intelligence.
byte SavingThrow[4][5][20]=
{
  {//Cleric
    {11, 10, 10, 9, 9, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 6, 6, 6, 6, 5}, 				//Death Ray or Poison
    {12, 11, 11, 10, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 6}, 			//Magic Wands
    {14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9}, 		//Paralysis or Petrify
    {16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12 ,12, 12, 11, 11, 11}, 		//Dragon Breath
    {15, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10}, 		//Spells
  },
  {//Magic-User
    {13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 9, 8}, 		//Death Ray or Poison
    {14, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 10, 10, 9, 9, 8, 8, 7, 7, 6},			//Magic Wands
    {13, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 9, 9, 8, 8, 7, 7, 6, 6, 5}, 			//Paralysis or Petrify
    {16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11},		//Dragon Breath
    {15, 14, 14, 13, 13, 13, 13, 12, 12, 11, 11, 11, 11, 10, 10, 9, 9, 9, 9, 8}, 			//Spells
  },
  {//Fighter
    {13, 12, 12, 11, 11, 11, 11, 10, 10, 9, 9, 9, 9, 8, 8, 7, 7, 7, 7, 6}, 			//Death Ray or Poison
    {14, 13, 13, 12, 12, 11, 11, 11, 11, 10, 9, 9, 9, 9, 8, 8, 7, 7, 7, 7}, 			//Magic Wands
    {15, 14, 14, 14, 14, 13, 13, 12, 12, 12, 12, 11, 11, 10, 10, 10, 10, 9, 9, 8}, 		//Paralysis or Petrify
    {16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 12, 12, 12, 12, 11, 11, 10, 10, 10}, 		//Dragon Breath
    {18, 17, 17, 16, 16, 15, 15, 15, 15, 14, 14, 13, 13, 13, 13, 12, 12, 11, 11, 11},			//Spells
  },
  {//Thief
    {13, 12, 12, 11, 11, 11, 11, 10, 10, 9, 9, 9, 9, 8, 8, 7, 7, 7, 7, 6}, 			//Death Ray or Poison
    {14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 10, 10, 10, 10, 9, 9, 9, 9, 8}, 		//Magic Wands
    {13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8}, 			//Paralysis or Petrify
    {16, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8, 7, 7, 6}, 			//Dragon Breath
    {15, 14, 14, 13, 13, 13, 13, 12, 12, 11, 11, 11, 11, 10, 10, 9, 9, 9, 9, 8} 		//Spells
  }
};

//Page 5
//Thief Special Abilities (ThiefSpecialAbilities[AbilityIndex][Level]
byte ThiefSpecialAbilities[7][20] = 
{
  {25, 30, 35, 40, 45, 50, 55, 60, 65, 68, 71, 74, 77, 80, 83, 84, 85, 86, 87, 88}, //Open Locks
  {20, 25, 30, 35, 40, 45, 50, 55, 60, 63, 66, 69, 72, 75, 78, 79, 80, 81, 82, 83}, //Remove Traps
  {30, 35, 40, 45, 50, 55, 60, 65, 70, 74, 78, 82, 86, 90, 94, 95, 96, 97, 98, 99}, //Pick Pocket
  {25, 30, 35, 40, 45, 50, 55, 60, 65, 68, 71, 74, 77, 80, 83, 85, 87, 89, 91, 93}, //Move Silently
  {80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99}, //Climb Walls
  {10, 15, 20, 25, 30, 35, 40, 45, 50, 53, 56, 59, 62, 65, 68, 69, 70, 71, 72, 73}, //Hide
  {30, 34, 38, 42, 46, 50, 54, 58, 62, 65, 68, 71, 74, 77, 80, 83, 86, 89, 92, 95} //Listen
};