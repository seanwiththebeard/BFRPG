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

/*Sneak Attack
	•+4 attack bonus and does double damage if it is successful. 
        The opponent  should not be aware where the Thief is
        (may require a Move Silently or Hide roll).
        •Can't be performed on the same opponent twice in any given combat
        •Can also be performed bare-handed and with the "flat of the blade" 
        (+0 attack bonus and does normal damage). In both cases subduing
        damage is done.*/

//Clerics vs. Undead (ClericVsUndead[Type - 1][Level]
#define No 21
#define T 0
#define D -1
#define Skeleton 1
#define Zombie 2
#define Ghoul 3
#define Wight 4
#define Wraith 5
#define Mummy 6
#define Spectre 7
#define Vampire 8
#define Ghost 9
sbyte ClericVsUndead[9][20] = 
{
  {13, 11, 9, 7, 5, 4, 3, T, T, T, D, D, D, D, D, D, D, D, D, D}, //Skeleton
  {17, 15, 13, 11, 9, 7, 5, 3, 2, T, T, T, D, D, D, D, D, D, D, D}, //Zombie
  {19, 18, 17, 16, 15, 11, 9, 7, 5, 3, 2, T, T, T, D, D, D, D, D, D}, //Ghoul
  {No, 20, 19, 18, 17, 15, 13, 11, 9, 7, 5, 3, 2, T, T, T, D, D, D, D}, //Wight
  {No, No, No, 20, 19, 18, 17, 15, 13, 11, 9, 7, 5, 3, 2, T, T, T, D, D}, //Wraith
  {No, No, No, No, No, 20, 19, 18, 17, 15, 13, 11, 9, 7, 5, 3, 2, T, T, T}, //Mummy
  {No, No, No, No, No, No, No, 20, 19, 18, 17, 15, 13, 11, 9, 7, 5, 3, 2, T}, //Spectre
  {No, No, No, No, No, No, No, No, No, 20, 19, 18, 17, 15, 13, 11, 9, 7, 5, 3}, //Vampire
  {No, No, No, No, No, No, No, No, No, No, No, 20, 19, 18, 17, 15, 13, 11, 9, 7}  //Ghost
};

/*Turn Undead 
	•Roll 1d20 >= Target number.
        If the roll is a success 2d6 hit dice of undead monsters are affected;
        surplus hit dice are lost
        •T = undead is automatically affected (no roll needed)
        •D =  undead will be damaged.
        1d8 damage per level of the Cleric (roll once and apply
        the same damage to all undead monsters affected)
*/

//Page 6

struct
{
  int NameIndex;
  byte NameLength;
  byte Level;
  bool Reversible;
}
MagicUserSpells;

char *MagicUserSpellsName[][] = 
{
  {"Charm Person", "Detect Magic", "Floating Disc", "Hold Portal", "Light", "Magic Missile", "Magic Mouth", "Protection from Evil", "Read Languages", "Shield", "Sleep", "Ventriloquism"},
  {"Continual LightDetect EvilDetect InvisibleESPInvisibilityKnockLevitateLocate ObjectMirror ImagePhantasmal ForceWebWizard Lock"},
  {"ClairvoyanceDarkvisionDispel MagicFireballFlyHaste*Hold PersonInvisibility 10‘ radiusLightning BoltProtection from Evil 10’ radius*Protection from Normal MissilesWater Breathing"},
  {"Charm MonsterConfusionDimension DoorGrowth of Plants*Hallucinatory TerrainIce StormMassmorphPolymorph OtherPolymorph SelfRemove CurseWall of FireWizard Eye"},
  {"Animate DeadCloudkillConjure ElementalFeeblemindHold MonsterMagic JarPasswallTelekinesisTeleportWall of Stone"},
  {"Anti-Magic ShellDeath SpellDisintegrateFlesh to StoneGeasInvisible StalkerLower WaterProjected ImageReincarnateWall of Iron"}
};
/* Magic-User Spells

First Level
1 Charm Person
2 Detect Magic
3 Floating Disc
4 Hold Portal
5 Light*
6 Magic Missile
7 Magic Mouth
8 Protection from Evil*
9 Read Languages
10 Shield
11 Sleep
12 Ventriloquism

Second Level
1 Continual Light*
2 Detect Evil*
3 Detect Invisible
4 ESP
5 Invisibility
6 Knock
7 Levitate
8 Locate Object
9 Mirror Image
10 Phantasmal Force
11 Web
12 Wizard Lock

Third Level
1 Clairvoyance
2 Darkvision
3 Dispel Magic
4 Fireball
5 Fly
6 Haste*
7 Hold Person
8 Invisibility 10‘ radius
9 Lightning Bolt
10 Protection from Evil 10’ radius*
11 Protection from Normal Missiles
12 Water Breathing

Fourth Level
1 Charm Monster
2 Confusion
3 Dimension Door
4 Growth of Plants*
5 Hallucinatory Terrain
6 Ice Storm 7Massmorph
8 Polymorph Other
9 Polymorph Self
10 Remove Curse*
11 Wall of Fire
12 Wizard Eye

Fifth Level
1 Animate Dead 
2 Cloudkill 
3 Conjure Elemental 
4 Feeblemind 
5 Hold Monster 
6 Magic Jar 
7 Passwall 
8 Telekinesis 
9 Teleport 
10 Wall of Stone

Sixth Level
1 Anti-Magic Shell
2 Death Spell
3 Disintegrate
4 Flesh to Stone*
5 Geas*
6 Invisible Stalker
7 Lower Water
8 Projected Image
9 Reincarnate
10 Wall of Iron

Clerical Spells

First Level
1 Cure Light Wounds*
2 Detect Evil*
3 Detect Magic
4 Light*
5 Protection from Evil*
6 Purify Food and Water
7 Remove Fear*
8 Resist Cold

Second Level
1 Bless*
2 Charm Animal
3 Find Traps
4 Hold Person
5 Resist Fire
6 Silence 15' radius
7 Speak with Animals
8 Spiritual Hammer

Third Level
1 Continual Light*
2 Cure Blindness
3 Cure Disease*
4 Growth of Animals
5 Locate Object
6 Remove Curse*
7 Speak with Dead
8 Striking

Fourth Level
1 Animate Dead
2 Create Water
3 Cure Serious Wounds*
4 Dispel Magic
5 Neutralize Poison*
6 Protection from Evil 10' radius*
7 Speak with Plants
8 Sticks to Snakes

Fifth Level
1 Commune
2 Create Food
3 Dispel Evil
4 Insect Plague
5 Quest*
6 Raise Dead*
7 True Seeing
8 Wall of Fire

Sixth Level
1 Animate Objects
2 Blade Barrier
3 Find the Path
4 Heal*
5 Regenerate
6 Restoration
7 Speak with Monsters
8 Word of Recall

* Some spells are reversible; such spells are shown with an asterisk after the name
*/

//Page 7
/*
Equipment, Weapons, and Movement
General Equipment (Item, Cost, Weight)
Backpack 4gp * 
Candles, 12 1gp *
Chalk, small bag of pieces 2gp * 
Clothing, common outfit 4gp 1 
Glass bottle or vial 1gp * 
Grappling Hook 2gp 4 
Holy Symbol 25gp * 
Holy Water, per vial 10gp * 
Iron Spikes, 12 1gp 1 
Ladder, 10 ft. 1gp 20 
Lantern, Hooded 8 gp2 
Map or scroll case 1gp ½ 
Mirror, small metal 7gp * 
Oil (per flask) 1 gp1 
Paper (per sheet) 1gp ** 
Pole, 10' wooden 1gp 10 
Quiver or Bolt case 1gp 1 
Rations, Dry, one week 10gp 14 
Rope, Hemp (per 50 ft.) 1gp 5 
Rope, Silk (per 50 ft.) 10gp 2 
Sack, Large 1gp *
Sack, Small 5sp * 
Tent, Large (ten men) 25gp 20 
Tent, Small (one man) 5gp 10 
Thieves' picks and tools 25gp 1 
Tinderbox, flint and steel 3gp 1 
Torches, 6 1gp 1 
Whetstone 1gp 1 
Wineskin/Waterskin 1gp 2 
Winter blanket 1gp 3 
Writing ink (per vial) 8gp * 

* These items weigh little individually. Ten of these items weigh one pound. 
** These items have no appreciable weight and should not be considered for 
encumbrance unless hundreds are carried. 

Missile Weapon Ranges (Weapon, Short (+1), Medium (0), Long (-2))
Longbow 70 140 210
Shortbow 50 100 150 
Heavy Crossbow 80 160 240 
Light Crossbow 60 120 180 
Dagger 10 20 30 
Hammer 10 20 30 
Hand Axe 10 20 30 
Oil or Holy Water 10 30 50 
Sling 30 60 90 
Spear 10 20 30 

* Missile weapon ranges are given in feet. 
In the wilderness, substitute yards for feet 

Weapons (Weapon, Cost, Size, Weight, Dmg.)
//Axes
Hand Axe 4gp S 5 1d6 
Battle Axe7 gpM71d8 
Great Axe14 gpL151d10

//Bows
Shortbow 25gp M 2 
	Shortbow Arrow 1sp 0.1 1d6 
	Silver*Shortbow Arrow 2gp 0.1 1d6 
Longbow 60gp L 3 
	Longbow Arrow 2sp 0.1 1d8 
	Silver*Longbow Arrow 4gp 0.1 1d8
Light Crossbow 30gp M 7 
	Light Quarrel 2sp 0.1 1d6 
	Silver*Light Quarre l 5gp 0.1 1d6 
Heavy Crossbow 50gp L 14 
	Heavy Quarrel 4sp 0.1 1d8 
	Silver*Heavy Quarrel 10gp 0.1 1d8 

//Daggers 
Dagger2 gpS11d4 
Silver* Dagger25 gpS11d4 

//Swords 
Shortsword 6gp S 3 1d6 
Longsword/Scimitar 10gp M 4 1d8 
Two-Handed Sword 18 gp L 10 1d10 

//Hammers and Maces 
Warhammer 4gp S 6 1d6 
Mace 6gp M 10 1d8 
Maul 10gp L 16 1d10 

//Other Weapons 
Club/Cudgel/Walking Staff 2sp M1 1d4 
Quarterstaff 2gp L 4 1d6 
Pole Arm 9gp L 15 1d10 
Sling 1gp S 0.1 
Bullet 1sp 0.1 1d4 
Stone n/a 0.1 1d3 
Spear 5gp M 5 
Thrown (one handed) 1d6 
Melee (one handed) 1d6 
Melee (two handed) 1d8 

* Silver tip or blade, for use against lycanthropes. 

Armor and Shields (Armor Type, Cost, Weight, AC)
No Armor 0 gp 0 11 
Leather Armor 20gp 15 13 
Chain Mail 60gp 40 15 
Plate Mail 300gp 50 17 
Shield 7gp 5 +1
*/

//Page 8
/*
Land Transportation (Vehicle Length x width*WeightCargoMovementHardness / HPCost (gp))
Chariot 15' x 6'300 750 lbs60' (10') 10 / 10400 
Coach30' x 8'1,0002,000 lbs40' (15')6 / 121,500 Wagon35' x 8'2,0004,000 lbs20' (20')6 / 16500 *Includes hitched horses or mules. Water Transportation VehicleLength x WidthCargoCrewMovementMiles/DayHardness / HPCost (gp) Canoe15' x 4'1/2  ton140'(5')304 / 450 Caravel55' x 15'75 tons1020'(20')428 / 7510,000 Carrack60' x 20'135 tons2030'(30')4810 / 12020,000 Galley, Small100' x 15'210 tons9020'(20')36 / 248 / 7515,000 Galley, Large120' x 20'375 tons16030'(25')42 / 2410 / 12030,000 Longship110' x 15'10 tons7030'(25')42 / 249 / 11025,000 Raft/Bargeper 10' x 10'1 ton240'(10')186 / 12100 Riverboat50' x 20'50 tons1020'(20')308 / 303,500 Rowboat15' x 6'1 ton130'(10')246 / 8600 Sailboat40' x 8'5 tons140'(15')367 / 202,000 Siege Engines WeaponCost Rate of Fire Attack PenaltyDamage Short Range (+1) Medium Range (+0) Long Range (-2) Ballista100 gp1/4-32d850'100'150' Battering Ram200 gp1/3+02d8N/AN/AN/A Onager300 gp1/6-62d12100'200'300' Trebuchet400 gp1/10-83d10N/A300'400' Beasts of Burden ItemCostWeightMovement Horse, Draft120 gp-60' (10') Horse, War200 gp-60' (10') Horse, Riding75 gp-80' (10') Pony*40 gp-40' (10') Pony, War*80 gp-40' (10') Bit and bridle15 sp3Horseshoes & shoeing1 gp10Saddle, Pack5 gp15Saddle, Riding10 gp35Saddlebags, pair4 gp7* Due to their small stature, Dwarves and Halflings must ride ponies rather than horses. Monetary values 1 platinum piece (pp)=5 gold pieces (gp) 1 gold piece (gp)=10 silver pieces (sp) 1 electrum piece (ep)=5 silver pieces (sp) 1 silver piece (sp)=10 copper pieces (cp) Time Normal Game TurnsCombat Rounds 10 minutes long10 seconds long * *  60 combat rounds per game turn Scale DungeonOutdoors FeetYards * * Area of effect measurements (for spells, for instance) normally remain in feet Movement and Encumbrance Armor TypeLightly Loaded Heavily Loaded No Armor or Magic Leather40'30' Leather Armor or Magic Metal30'20' Metal Armor20'10' Load Dwarf, Elf, HumanHalfling StrengthLight Load Heavy Load Light Load Heavy Load 325602040 4-535903060 6-8501204080 9-126015050100 13-156516555110 16-177018060120 188019565130
*/

//Page 9
/*
Wilderness Movement Rates Encounter Movement (Feet per Round) Wilderness Movement (Miles per Day) 10'6 20'12 30'18 40'24 50'30 60'36 70'42 80'48 90'54 100'60 110'66 120'72 •Based on 8 hour day of travel through open, clear terrain •Forced march: 12 hours per day, add 50% to the distance traveled (1d6 damage, save vs. Death Ray) •Waterborne Travel: 12 hour day of travel (ships may travel 24 hours per day) •Traveling by air: overland movement rates are doubled, and all terrain effects are ignored Overland Travel Terrain Adjustment Jungle, Mountains, Swampx1/3 Desert, Forest, Hillsx1/2 Clear, Plains, Trailx2/3 Road (Paved)x1 Wind Direction d12Wind Direction 1Northerly 2Northeasterly 3Easterly 4Southeasterly 5Southerly 6Southwesterly 7Westerly 8Northwesterly 9-12Prevailing wind direction for this locale Wind Conditions Adjustment d%Wind ConditionsSailing 01-05Becalmedx0 06-13Very Light Breezex1/3 14-25Light Breezex1/2 26-40Moderate Breezex2/3 41-70Average Windsx1 71-85Strong Windsx1 1/3 86-96Very Strong Windsx1 1/2 97-00Galex2 Retainers* Adjusted Die RollResult 2 or lessRefusal, -1 on further rolls 3-5Refusal 6-8Try again 9-11Acceptance 12 or moreAcceptance, +1 to Loyalty * Roll 2d6 and adds the player character's Charisma bonus and any adjustments Monster XP Table Monster Hit DiceXP ValueSpecial Ability Bonus less than 1103 12512 27525 314530 424040 536045 650055 767065 887570 91,07575 101,30090 111,57595 121,875100 132,175110 142,500115 152,850125 163,250135 173,600145 184,000160 194,500175 Opening Doors Door TypeRoll Range / Dice Stuck door1 ÷ (1+Strength bonus) on 1d6 Locked doors1 ÷ (1+Strength bonus) on 1d10 Metal bars doors1 ÷ (1+Strength bonus) on 1d20 Detection Item TypeDwarvesElvesOthers Traps*1-2 on 1d61 on 1d61 on 1d6 Shifting walls1-2 on 1d6-- New construction1-2 on 1d6-- Slanting passages1-2 on 1d6-- Secret doors* •1 on 1d6 •1-2 on 1d6 if INT>=15 •1-2 on 1d6 •1 on 1d6  with a look •1 on 1d6 •1-2 on 1d6 if INT>=15 * It takes at least a turn per 10' square area for searching
*/

//Page 10
/*
Encounter Encounter Sequence Surprise check* •Normal: 1-2 on 1d6 •Ambush: 1-4 on 1d6 •Deafened: 1-3 on 1d6 •Blinded: 1-4 on 1d6 Initiave rolls Roll 1d6 + Dex mod. High numbers act first (-1 penalty if deafened, -2 if blinded) Monster reactionRoll 2d6 + Cha mod of the leader * For Elves reduce the range by 1 Reaction Roll Table Adjusted Die RollResult 2 or lessImmediate Attack 3-7Unfavorable 8-11Favorable 12 or moreVery Favorable Morale Checks HowRoll 2d6 <= Monster morale score When •During first encounter •When the monster party is reduced to half strength (by numbers if more than one monster, or by hit points for one monster) Typical Actions Standard attack Move (encounter movement distance) + melee or ranged attack RunMove (2 X encounter movement distance) Charge*Move (2 X encounter movement distance) + attack (+2 bonus) Parting shotFree attack (+2 bonus) vs. opponents turning from the fight Fighting withdrawal Move back (half normal walking movement) + melee attack * -2 penalty to Armor Class for the round Attack bonus / penalty Attacking From Behind +2 (do not combine with the Sneak Attack ability) Flat of the blade attack-4 ( do half subduing damage) Punch+0 (1d3 points of subduing damage) Kick-2 (1d4 points of subduing damage) Attacker/Defender is invisible+4 / -4 Attacker/Defender is blinded-4 / +4 Defender is pinned+4 Missile fire Target distanceAttack bonus / penalty <= 5'-5 * > 5' AND <= Short range+1 > Short range AND <= Medium range0 > Medium range AND <= Long range-2 > Long rangeCannot be attacked * If the attacker is behind the target creature and undetected, or that creature is distracted apply +1 bonus (+3 total bonus if attacking from behind) Cover and Concealment Penalty Target isCoveredConcealed 25%-2-1 50%-4-2 75%-6-3 90%-8-4 Grenade-Like Missiles Miss Table (behind) •Roll 1d10 and consult the diagram to determine where the missile hit. Treat each number as representing a 10' square area •Missiles that Miss: GM roll attacks against each targets (no more than three). These attack rolls are made with the shooter's normal attack bonus, just as if he or she intended to attack the target. 0 789 5Target6 234 1 (in front) Oil Grenade-Like Missiles •Direct hit: 1d8 points of fire damage, plus in the next round an additional 1d8 points of damage, unless the character spends the round extinguishing the flames •Splash Hit: 1d6 points of fire damage within 5 feet of the point of impact. A save vs. Death Ray is allowed to avoid this damage •Effective for 10 rounds. Those attempting to cross the burning oil will receive 1d6 points of fire damage each round they are in it. Holy Water •Direct hit: 1d8 points damage. •Splash Hit: 1d6 points of fire damage within 5 feet of the point of impact. •Effective for 1 round
*/

//Page 11
/*
Attack Bonus Table Fighter LevelCleric  or Thief LevelMagic-User LevelMonster Hit DiceAttack Bonus NMless than 1+0 11-21-31+1 2-33-44-52+2 45-66-83+3 5-67-89-124+4 79-1113-155+5 8-1012-1416-186+6 11-1215-1719-207+7 13-1518-208-9+8 16-1710-11+9 18-2012-13+10 14-15+11 16-19+12 20-23+13 24-27+14 28-31+15 32 or more+16 *  On a hit roll a natural "1" is always a failure. A natural "20" is always a hit, if the opponent can be hit at all Monsters and mapping Monsters description notation NameIf an asterisk appears after the monster's name, it indicates that the monster is only able to be hit by special weapons (such as silver or magical weapons, or creatures affected only by fire, etc.) Armor Class •If the monster  wears armor, the first listed AC value is with that armor, and the second, in parentheses, is unarmored •Some monsters are only able to be hit by silver(†) or magical weapons(‡) Hit Dice •Monsters always roll eight sided dice (d8) for hit points, unless noted otherwise •* or ** : Special Ability Bonus to experience points (each asterisk adds the special ability bonus once) •If the monster's Attack Bonus is different than its number of Hit Dice the Attack Bonus will be listed in parentheses after the Hit Dice figure MovementA distance may appear in parentheses after a movement figure; this is the creature's turning distance.  If a turning distance is not listed, assume 5'.
*/

//Page 12
/*
Treasure To generate a random treasure, find the indicated treasure type assigned to monsters and read across; where a percentage chance is given, roll percentile dice to see if that sort of treasure is found.  If so, roll the indicated dice to determine how much. Lair Treasures Type100's of Copper 100's of Silver 100's of Electrum 100's of Gold 100's of Platinum Gems and JewelryMagic Items A50% 5d660% 5d640% 5d470% 10d650% 1d1050% 6d6 50% 6d630%any 3 B75% 5d1050% 5d650% 5d450% 3d6None25% 1d6 25% 1d6 10%1 weapon or armor C60% 6d660% 5d430% 2d6NoneNone25% 1d4 25% 1d415%any 1d2 D30% 4d645% 6d6None90% 5d8None30% 1d8 30% 1d8 20%any 1d2 + 1 potion E30% 2d860% 6d1050% 3d850% 4d10None10% 1d10 10% 1d10 30%any 1d4 + 1 scroll FNone40% 3d850% 4d885% 6d1070% 2d820% 2d12 10% 1d12 35%any 1d4 except weapons + 1 potion + 1 scroll GNoneNoneNone90% 4d6x1075% 5d825% 3d6 25% 1d10 50%any 1d4 + 1 scroll H75% 8d1075% 6d10x1075% 3d10x1075% 5d8x1075% 9d850% 1d100 50% 10d4 20%any 1d4 + 1 potion + 1 scroll INoneNoneNoneNone80% 3d1050% 2d6 50% 2d615%any 1 J45% 3d845% 1d8NoneNoneNoneNone NoneNone KNone90% 2d1035% 1d8NoneNoneNone NoneNone LNoneNoneNoneNoneNone50% 1d4 NoneNone MNoneNoneNone90% 4d1090% 2d8x1055% 5d4 45% 2d6None NNoneNoneNoneNoneNoneNone None40%2d4 potions ONoneNoneNoneNoneNoneNone None50%1d4 scrolls Individual Treasures TypePieces of Copper Pieces of Silver Pieces of Electrum Pieces of Gold Pieces of Platinum Gems and JewelryMagic Items P3d8NoneNoneNoneNoneNone NoneNone QNone3d6NoneNoneNoneNone NoneNone RNoneNone2d6NoneNoneNone NoneNone SNoneNoneNone2d4NoneNone NoneNone TNoneNoneNoneNone1d6None NoneNone U50% 1d2050% 1d20None25% 1d20None5% 1d4 5% 1d42%Any 1 VNone25% 1d2025% 1d2050% 1d2025% 1d2010% 1d4 10% 1d45%Any 1
*/

//Page 13
/*
Unguarded Treasures Level*100's of Copper 100's of Silver 100's of Electrum 100's of Gold 100's of Platinum Gems and JewelryMagic Items 175%1d850%1d625%1d47%1d41%1d47%1d4 3%1d42%Any 1 250%1d1050%1d825%1d620%1d62%1d410%1d6 7%1d45%Any 1 330%2d650%1d1025%1d850%1d64%1d415%1d6 7%1d68%Any 1 4-520%3d650%2d625%1d1050%2d68%1d420%1d8 10%1d612%Any 1 6-715%4d650%3d625%1d1270%2d815%1d430%1d8 15%1d616%Any 1 8+10%5d650%5d625%2d875%4d630%1d440%1d8 30%1d820%Any 1 * Dungeon levels Gems and Jewelry Use the tables below to determine the base value and number found when gems are indicated in a treasure hoard.  If the number generated in the main table above is small, roll for each gem; but if the number is large (10 or more, at the GM's option), after each roll for Type and Base Value, roll the indicated die to see how many such gems are in the hoard. d%Type Base Value in Gold Pieces Number Found 01-20Ornamental101d10 21-45Semiprecious501d8 46-75Fancy1001d6 76-95Precious5001d4 96-00Gem10001d2 Jewel50001 The values of gems vary from the above for reasons of quality, size, etc.  The GM may use the table below to adjust the values of the gems in the hoard, at his or her option.  This is why there is no die result given in the table above for Jewel; on a roll of 12 on the table below, a Gem can become a Jewel. 2d6Value Adjustment 2Next Lower Value Row 31/2 43/4 5-9Normal Value 101.5 Times 112 Times 12Next Higher Value Row Standard items of jewelry are valued at 2d8x100 gp value.  The table below can be used to generate descriptions of the items themselves. d%Type 01-06Anklet 07-12Belt 13-14Bowl 15-21Bracelet 22-27Brooch 28-32Buckle 33-37Chain 38-40Choker 41-42Circlet 43-47Clasp 48-51Comb 52Crown 53-55Cup 56-62Earring 63-65Flagon 66-68Goblet 69-73Knife 74-77Letter Opener 78-80Locket 81-82Medal 83-89Necklace 90Plate 91-95Pin 96Sceptre 97-99Statuette 00Tiara
*/

//Page 14
/*
Magic Item Generation Determine the sort of item found by rolling on the following table: AnyWeapon or Armor Any Exc. WeaponsType of Item 01-2501-70Weapon 26-3571-0001-12Armor 36-5513-40Potion 56-8541-79Scroll 86-9080-86Ring 91-9587-93Wand, Staff, or Rod 96-0094-00Miscellaneous Magic Magic Weapons First, roll d% on the following table to determine the weapon type: d%Weapon Typed%Weapon Type 01-02Great Axe60-65Shortsword 03-09Battle Axe66-79Longsword 10-11Hand Axe80-81Scimitar 12-19Shortbow82-83Two-Handed Sword 20-27Shortbow Arrow84-86Warhammer 28-31Longbow87-94Mace 32-35Longbow Arrow95Maul 36-43Light Quarrel96Pole Arm 44-47Heavy Quarrel97Sling Bullet 48-59Dagger98-00Spear Next, roll on the Weapon Bonus tables.  Follow the directions given if a roll on the Special Enemy or Special Ability tables are indicated; generally multiple rolls on the Special Ability table should be ignored when rolled. d% RollWeapon Bonus MeleeMissileBonus 01-4001-46+1 41-5047-58+2 51-5559-64+3 56-57+4 58+5 59-7565-82+1, +2 vs. Special Enemy 76-8583-94+1, +3 vs. Special Enemy 86-95Roll Again + Special Ability 96-9895-98Cursed, -1* 99-0099-00Cursed, -2* * If cursed weapons are rolled along with special abilities, ignore the special ability roll. 1d6Special Enemy1d20Special Ability 1Dragons01-09Casts Light on Command 2Enchanted10-11Charm Person 3Lycanthropes12Drains Energy 4Regenerators13-16Flames on Command 5Spell Users17-19Locate Objects 6Undead20Wishes Wands, Staves and Rods d%Type 01-08Rod of Cancellation 09-13Snake Staff 14-17Staff of Commanding 18-28Staff of Healing 29-30Staff of Power 31-34Staff of Striking 35Staff of Wizardry 36-40Wand of Cold 41-45Wand of Enemy Detection 46-50Wand of Fear 51-55Wand of Fireballs 56-60Wand of Illusion 61-65Wand of Lightning Bolts 66-73Wand of Magic Detection 74-79Wand of Paralyzation 80-84Wand of Polymorph 85-92Wand of Secret Door Detection 93-00Wand of Trap Detection Rings d%Typed%Type 01-06Control Animal71Protection +3 07-12Control Human72-73Regeneration 13-19Control Plant74-75Spell Storing 20-30Delusion76-81Spell Turning 31-33Djinni Summoning82-83Telekinesis 34-44Fire Resistance84-90Water Walking 45-57Invisibility91-97Weakness 58-66Protection +198Wishes 67-70Protection +299-00X-Ray Vision Magic Armor Generate the type and bonus of each item of magic armor on the tables below. d%Armor Typed%Armor Bonus 01-09Leather Armor01-50+1 10-28Chain Mail51-80+2 29-43Plate Mail81-90+3 44-00Shield91-95Cursed * 96-00Cursed, AC 11 ** * If Cursed armor is rolled, roll again and reverse the bonus (e.g., -1 instead of +1). ** This armor has AC 11 but appears to be +1 when tested.
*/

//Page 15
/*
Miscellaneous Magic Items d%Type 01-04Amulet of Proof against Detection and Location 05-06Bag of Devouring 07-12Bag of Holding 13-17Boots of Levitation 18-22Boots of Speed 23-27Boots of Traveling and Leaping 28Bowl Commanding Water Elementals 29Brazier Commanding Fire Elementals 30-35Broom of Flying 36Censer Commanding Air Elementals 37-39Cloak of Displacement 40-43Crystal Ball 44-45Crystal Ball with Clairaudience 46Drums of Panic 47Efreeti Bottle 48-54Elven Boots 55-61Elven Cloak 62-63Flying Carpet 64-70Gauntlets of Ogre Power 71-72Girdle of Giant Strength 73-78Helm of Reading Languages and Magic 79Helm of Telepathy 80Helm of Teleportation 81Horn of Blasting 82-90Medallion of ESP 91Mirror of Life Trapping 92-96Rope of Climbing 97-99Scarab of Protection 00Stone Commanding Earth Elementals Wands, Staves and Rods d%Type 01-08Rod of Cancellation 09-13Snake Staff 14-17Staff of Commanding 18-28Staff of Healing 29-30Staff of Power 31-34Staff of Striking 35Staff of Wizardry 36-40Wand of Cold 41-45Wand of Enemy Detection 46-50Wand of Fear 51-55Wand of Fireballs 56-60Wand of Illusion 61-65Wand of Lightning Bolts 66-73Wand of Magic Detection 74-79Wand of Paralyzation 80-84Wand of Polymorph 85-92Wand of Secret Door Detection 93-00Wand of Trap Detection Potions d%Typed%Type 01-03Clairaudience48-51Gaseous Form 04-07Clairvoyance52-55Giant Strength 08-10Control Animal56-59Growth 11-13Control Dragon60-63Healing 14-16Control Giant64-68Heroism 17-19Control Human69-72Invisibility 20-22Control Plant73-76Invulnerability 23-25Control Undead77-80Levitation 26-32Delusion81-84Longevity 33-35Diminution85-86Poison 36-39ESP87-89Polymorph Self 40-43Fire Resistance90-97Speed 44-47Flying98-00Treasure Finding Scrolls d%General Typed%General Type 01-03Cleric Spell Scroll (1 Spell)35Magic-User Spell Scroll (7 Spells) 04-06Cleric Spell Scroll (2 Spells)36-40Cursed Scroll 07-08Cleric Spell Scroll (3 Spells)41-46Protection from Elementals 09Cleric Spell Scroll (4 Spells)47-56Protection from Lycanthropes 10-15Magic-User Spell Scroll (1 Spell)57-61Protection from Magic 16-20Magic-User Spell Scroll (2 Spells)62-75Protection from Undead 21-25Magic-User Spell Scroll (3 Spells)76-85Map to Treasure Type A 26-29Magic-User Spell Scroll (4 Spells)86-89Map to Treasure Type E 30-32Magic-User Spell Scroll (5 Spells)90-92Map to Treasure Type G 33-34Magic-User Spell Scroll (6 Spells)93-00Map to 1d4 Magic Items
*/

//Page 16
/*
Encounters Dungeon Encounters The Game Master should check once every 3 turns * Roll 1d6; on a roll of 1, an encounter occurs.  * Roll 1d12 on the appropriate table. Die RollLevel 1Level 2Level 3 1Bee, GiantBeetle, Giant BombardierAnt, Giant 2GoblinFly, GiantApe, Carnivorous 3Green Slime*GhoulBeetle, Giant Tiger 4KoboldGnollBugbear 5NPC Party: AdventurerGray OozeDoppleganger 6NPC Party: BanditHobgoblinGargoyle* 7OrcLizard ManGelatinous Cube 8SkeletonNPC Party: AdventurerLycanthrope, Wererat* 9Snake, CobraSnake, Pit ViperOgre 10Spider, Giant CrabSpider, Giant Black WidowShadow* 11StirgeTroglodyteTentacle Worm 12WolfZombieWight* Die RollLevel 4-5Level 6-7Level 8+ 1Bear, CaveBasiliskBlack Pudding 2Caecilia, GiantBlack PuddingChimera 3CockatriceCaeciliaGiant, Hill 4DopplegangerDisplacerGiant, Stone 5Gray OozeHydraHydra 6HellhoundLycanthrope, Weretiger*Lycanthrope, Wereboar* 7Lycanthrope, Werewolf*Mummy*Purple Worm 8MinotaurOwlbearSalamander, Flame* 9Ochre Jelly*Rust Monster*Salamander, Frost* 10OwlbearScorpion, GiantVampire* 11Rust Monster*Spectre* 12Wraith*Troll City, Town or Village Encounters (2d6) Die RollDay EncounterNight Encounter 2DopplegangerDoppleganger 3NobleShadow* 4ThiefPress Gang 5BullyBeggar 6City WatchThief 7MerchantBully 8BeggarMerchant 9PriestGiant Rat 10MercenaryCity Watch 11WizardWizard 12Lycanthrope, Wererat*Lycanthrope, Wererat*
*/

//Page 17
/*
Wilderness Encounters Check about every four hours of game time (this translates nicely to three night checks and three daytime checks) * Roll 1d6; on a roll of 1, an encounter occurs.  * Roll 2d8 on the appropriate table. Die RollDesert or BarrenGrasslandInhabited Territories 2Dragon, BlueDragon, GreenDragon, Gold 3HellhoundTrollGhoul 4Giant, FireFly, GiantBugbear 5Purple WormScorpion, GiantGoblin 6Fly, GiantNPC Party:  BanditCentaur 7Scorpion, GiantLionNPC Party:  Bandit 8CamelBoar, WildNPC Party:  Merchant 9Spider, Giant TarantellaNPC Party:  MerchantNPC Party:  Pilgrim 10NPC Party:  MerchantWolfNPC Party:  Noble 11HawkBee, GiantDog 12NPC Party:  BanditGnollGargoyle* 13OgreGoblinGnoll 14GriffonBlink DogOgre 15GnollWolf, DireMinotaur 16Dragon, RedGiant, HillVampire* Die RollJungleMountains or HillsOcean 2Dragon, GreenDragon, WhiteDragon, Sea 3NPC Party:  BanditRoc (1d6: 1-3 Large, 4-5 Huge, 6 Giant)Hydra 4GoblinDisplacerWhale, Sperm 5HobgoblinLycanthrope, Werewolf*Crocodile, Giant 6Centipede, GiantMountain LionCrab, Giant 7Snake, Giant PythonWolfWhale, Killer 8ElephantSpider, Giant CrabOctopus, Giant 9AntelopeHawkShark, Mako 10JaguarOrcNPC Party:  Merchant 11StirgeBat, GiantNPC Party:  Buccaneer (Pirate) 12Beetle, Giant TigerHawk, GiantShark, Bull 13Caecilia, GiantGiant, HillRoc (1d8: 1-5 Huge, 6-8 Giant) 14Shadow*ChimeraShark, Great White 15NPC Party:  MerchantWolf, DireMermaid 16Lycanthrope, Weretiger*Dragon, RedSea Serpent Die RollRiver or RiversideSwampWoods or Forest 2Dragon, BlackDragon, BlackDragon, Green 3Fish, Giant PiranhaShadow*Alicorn (see Unicorn) 4StirgeTrollTreant 5Fish, Giant BassLizard, Giant DracoOrc 6NPC Party:  MerchantCentipede, GiantBoar, Wild 7LizardmanLeech, GiantBear, Black 8CrocodileLizardmanHawk, Giant 9Frog, GiantCrocodileAntelope 10Fish, Giant CatfishStirgeWolf 11NPC Party:  BuccaneerOrcOgre 12TrollToad, Giant (see Frog, Giant)Bear, Brown 13JaguarTroglodyteWolf, Dire 14NixieBlood RoseGiant, Hill 15Water Termite, GiantHangman TreeOwlbear 16Dragon, GreenBasiliskUnicorn
*/

//Open Game License
/*
OPEN GAME LICENSE INTRODUCTION Basic Fantasy RPG Charts and Tables (hereinafter “the Supplement”) is based on the System Reference Document v3.5 ("SRD"), which is Open Game Content.    The text of the Open Game License itself is not Open Game Content. Instructions on using the License are provided within the License itself. Designation of Open Game Content:  The entire text of the Supplement (except the Open Game License, as noted above) is Open Game Content, released under the Open Game License, Version 1.0a (reproduced below) as described in Section 1(d) of the License.  Artwork incorporated in this document is not Open Game Content, and remains the property of the copyright holder. Designation of Product Identity:  Product identity is not Open Game Content. The following is designated as product identity pursuant to OGL v1.0a(1)(e) and (7): (A) product and product line names, including Basic Fantasy Role-Playing Game, Basic Fantasy RPG, and BFRPG, as well as the phrase “make mine Basic”; (B) all artwork, logos, symbols, graphic designs, depictions, likenesses, formats, poses, concepts, themes and graphic, photographic and other visual representations, including the “eye” logo, which is the personal mark of Chris Gonnerman for his various products, and which is Copyright © 2002 Chris Gonnerman, and the “Scribbled Dragon,” which is Copyright © 2005 Erik Wilson; (C) logos and trademarks, including any trademark or registered trademark clearly identified as product identity by the owner of the product identity, and which specifically excludes the open game content. More information on the Open Game License can be found at: http://www.wizards.com/d20 OPEN GAME LICENSE VERSION 1.0A The following text is the property of Wizards of the Coast, Inc. and is Copyright 2000 Wizards of the Coast, Inc ("Wizards"). All Rights Reserved. 1. Definitions: (a)"Contributors" means the copyright and/or trademark owners who have contributed Open Game Content; (b)"Derivative Material" means copyrighted material including derivative works and translations (including into other computer languages), potation, modification, correction, addition, extension, upgrade, improvement, compilation, abridgment or other form in which an existing work may be recast, transformed or adapted; (c) "Distribute" means to reproduce, license, rent, lease, sell, broadcast, publicly display, transmit or otherwise distribute; (d)"Open Game Content" means the game mechanic and includes the methods, procedures, processes and routines to the extent such content does not embody the Product Identity and is an enhancement over the prior art and any additional content clearly identified as Open Game Content by the Contributor, and means any work covered by this License, including translations and derivative works under copyright law, but specifically excludes Product Identity. (e) "Product Identity" means product and product line names, logos and identifying marks including trade dress; artifacts; creatures characters; stories, storylines, plots, thematic elements, dialogue, incidents, language, artwork, symbols, designs, depictions, likenesses, formats, poses, concepts, themes and graphic, photographic and other visual or audio representations; names and descriptions of characters, spells, enchantments, personalities, teams, personas, likenesses and special abilities; places, locations, environments, creatures, equipment, magical or supernatural abilities or effects, logos, symbols, or graphic designs; and any other trademark or registered trademark clearly identified as Product identity by the owner of the Product Identity, and which specifically excludes the Open Game Content; (f) "Trademark" means the logos, names, mark, sign, motto, designs that are used by a Contributor to identify itself or its products or the associated products contributed to the Open Game License by the Contributor (g) "Use", "Used" or "Using" means to use, Distribute, copy, edit, format, modify, translate and otherwise create Derivative Material of Open Game Content. (h) "You" or "Your" means the licensee in terms of this agreement. 2. The License: This License applies to any Open Game Content that contains a notice indicating that the Open Game Content may only be Used under and in terms of this License. You must affix such a notice to any Open Game Content that you Use. No terms may be added to or subtracted from this License except as described by the License itself. No other terms or conditions may be applied to any Open Game Content distributed using this License. 3.Offer and Acceptance: By Using the Open Game Content You indicate Your acceptance of the terms of this License. 4. Grant and Consideration: In consideration for agreeing to use this License, the Contributors grant You a perpetual, worldwide, royalty-free, non-exclusive license with the exact terms of this License to Use, the Open Game Content. 5.Representation of Authority to Contribute: If You are contributing original material as Open Game Content, You represent that Your Contributions are Your original creation and/or You have sufficient rights to grant the rights conveyed by this License. 6.Notice of License Copyright: You must update the COPYRIGHT NOTICE portion of this License to include the exact text of the COPYRIGHT NOTICE of any Open Game Content You are copying, modifying or distributing, and You must add the title, the copyright date, and the copyright holder's name to the COPYRIGHT NOTICE of any original Open Game Content you Distribute. 7. Use of Product Identity: You agree not to Use any Product Identity, including as an indication as to compatibility, except as expressly licensed in another, independent Agreement with the owner of each element of that Product Identity. You agree not to indicate compatibility or coadaptability with any Trademark or Registered Trademark in conjunction with a work containing Open Game Content except as expressly licensed in another, independent Agreement with the owner of such Trademark or Registered Trademark. The use of any Product Identity in Open Game Content does not constitute a challenge to the ownership of that Product Identity. The owner of any Product Identity used in Open Game Content shall retain all rights, title and interest in and to that Product Identity. 8. Identification: If you distribute Open Game Content You must clearly indicate which portions of the work that you are distributing are Open Game Content. 9. Updating the License: Wizards or its designated Agents may publish updated versions of this License. You may use any authorized version of this License to copy, modify and distribute any Open Game Content originally distributed under any version of this License. 10. Copy of this License: You MUST include a copy of this License with every copy of the Open Game Content You Distribute. 11. Use of Contributor Credits: You may not market or advertise the Open Game Content using the name of any Contributor unless You have written permission from the Contributor to do so. 12. Inability to Comply: If it is impossible for You to comply with any of the terms of this License with respect to some or all of the Open Game Content due to statute, judicial order, or governmental regulation then You may not Use any Open Game Material so affected. 13. Termination: This License will terminate automatically if You fail to comply with all terms herein and fail to cure such breach within 30 days of becoming aware of the breach. All sublicenses shall survive the termination of this License. 14. Reformation: If any provision of this License is held to be unenforceable, such provision shall be reformed only to the extent necessary to make it enforceable. 15. COPYRIGHT NOTICE Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc. System Reference Document Copyright 2000-2003, Wizards of the Coast, Inc.; Authors Jonathan Tweet, Monte Cook, Skip Williams, Rich Baker, Andy Collins, David Noonan, Rich Redman, Bruce R. Cordell, John D. Rateliff, Thomas Reid, James Wyatt, based on original material by E. Gary Gygax and Dave Arneson. Castles & Crusades: Players Handbook, Copyright 2004, Troll Lord Games; Authors Davis Chenault and Mac Golden. Castles & Crusades: Monsters Product Support, Copyright 2005, Troll Lord Games. Basic Fantasy Role-Playing Game Copyright © 2006-2016 Chris Gonnerman. Basic Fantasy Role-Playing Game Charts and Tables Copyright © 2010, 2016, 2021 Simone Felli
*/
