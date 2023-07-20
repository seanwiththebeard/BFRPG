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

typedef enum{Cleric, MagicUser, Fighter, Thief}CharacterClass;

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

struct{char* Value;}SpecialAbilityName[] = {"No Ability", "Turn Undead", "Cast Divine", "Read Magic", "Cast Arcane", "Open Lock", "Remove Trap", "Pick Pocket", "Move Silently", "Climb Wall", "Hide", "Listen", "Sneak Attack"};
SpecialAbility ClassAbilities[][8] = 
{
  {Ability_TurnUndead, Ability_CastDivine},
  {Ability_ReadMagic, Ability_CastArcane},
  {Ability_Null},
  {Ability_OpenLock, Ability_RemoveTrap, Ability_PickPocket, Ability_MoveSilently, Ability_ClimbWall, Ability_Hide, Ability_Listen, Ability_SneakAttack}
};

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
typedef enum
{
  Undead_Skeleton, 
  Undead_Zombie, 
  Undead_Ghoul, 
  Undead_Wight, 
  Undead_Wraith, 
  Undead_Mummy, 
  Undead_Spectre, 
  Undead_Vampire, 
  Undead_Ghost,
}UndeadType;

#define No 21
#define T 0
#define D -1
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
#undef No
#undef T
#undef D

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
  byte Level;
  bool Reversible;
}
MagicUserSpells;

char *MagicUserSpellsName[][] = 
{
  {"Charm Person", "Detect Magic", "Floating Disc", "Hold Portal", "Light", "Magic Missile", "Magic Mouth", "Protection from Evil", "Read Languages", "Shield", "Sleep", "Ventriloquism"},
  {"Continual Light", "Detect Evil", "Detect Invisible", "ESP", "Invisibility", "Knock", "Levitate", "Locate Object", "Mirror Image", "Phantasmal Force", "Web", "Wizard Lock"},
  {"Clairvoyance", "Darkvision", "Dispel Magic", "Fireball", "Fly", "Haste", "Hold Person", "Invisibility 10' radius", "Lightning Bolt", "Protection from Evil 10' radius", "Protection from Normal Missiles", "Water Breathing"},
  {"Charm Monster", "Confusion", "Dimension Door", "Growth of Plants*", "Hallucinatory Terrain", "Ice Storm", "Massmorph", "Polymorph Other", "Polymorph Self", "Remove Curse", "Wall of Fire", "Wizard Eye"},
  {"Animate Dead", "Cloudkill", "Conjure Elemental", "Feeblemind", "Hold Monster", "Magic Jar", "Passwall", "Telekinesis", "Teleport", "Wall of Stone"},
  {"Anti-Magic Shell", "Death Spell", "Disintegrate", "Flesh to Stone", "Geas", "Invisible Stalker", "Lower Water", "Projected Image", "Reincarnate", "Wall of Iron"}
};

char *ClericSpellsName[][] = 
{
  {"Cure Light Wounds", "Detect Evil", "Detect Magic", "Light", "Protection from Evil", "Purify Food and Water", "Remove Fear", "Resist Cold"},
  {"Bless", "Charm Animal", "Find Traps", "Hold Person", "Resist Fire", "Silence 15' radius", "Speak with Animals", "Spiritual Hammer"},
  {"Continual Light", "Cure Blindness", "Cure Disease", "Growth of Animals", "Locate Object", "Remove Curse", "Speak with Dead", "Striking"},
  {"Animate Dead", "Create Water", "Cure Serious Wounds", "Dispel Magic", "Neutralize Poison", "Protection from Evil 10' radius", "Speak with Plants", "Sticks to Snakes"},
  {"Commune", "Create Food", "Dispel Evil", "Insect Plague", "Quest", "Raise Dead", "True Seeing", "Wall of Fire"},
  {"Animate Objects", "Blade Barrier", "Find the Path", "Heal", "Regenerate", "Restoration", "Speak with Monsters", "Word of Recall"}
};

//Some spells are reversible; such spells are shown with an asterisk after the name

//Page 7
//Equipment, Weapons, and Movement
//General Equipment
struct 
{
  char *Name;
  byte Cost;
  byte Weight;
}Equipment[31] = 
{
  {"Backpack", 4, 0,},
  {"Candles, 12", 1, 0},
  {"Chalk, small bag of pieces", 2, 0},
  {"Clothing, common outfit", 4, 1},
  {"Glass bottle or vial", 1, 0}, 
  {"Grappling Hook", 2, 4},
  {"Holy Symbol", 25, 0}, 
  {"Holy Water, per vial", 10, 0},
  {"Iron Spikes, 12", 1, 1 },
  {"Ladder, 10 ft", 1, 20},
  {"Lantern, Hooded", 8, 2},
  {"Map or scroll case", 1, 0.5}, 
  {"Mirror, small metal", 7, 0},
  {"Oil (per flask)", 1, 1},
  {"Paper (per sheet)", 1, 0}, 
  {"Pole, 10ft wooden", 1, 10},
  {"Quiver or Bolt case", 1, 1},
  {"Rations, Dry, one week", 10, 14}, 
  {"Rope, Hemp (per 50 ft.)", 1, 5},
  {"Rope, Silk (per 50 ft.)", 10, 2},
  {"Sack, Large", 1, 0},
  {"Sack, Small", 5, 0},
  {"Tent, Large (ten men)", 25, 20},
  {"Tent, Small (one man)", 5, 10},
  {"Thieves' picks and tools", 25, 1},
  {"Tinderbox, flint and steel", 3, 1},
  {"Torches, 6", 1, 1},
  {"Whetstone", 1, 1},
  {"Wineskin/Waterskin", 1, 2},
  {"Winter blanket", 1, 3},
  {"Writing ink (per vial)", 8, 0}
};

struct
{
  char *Name;
  byte Range[3];
}MissileWeaponRanges[] =
{
  //Short +1 Medium 0 Long -2
  {"Longbow", 70, 140, 210},
  {"Shortbow", 50, 100, 150}, 
  {"Heavy Crossbow", 80, 160, 240}, 
  {"Light Crossbow", 60, 120, 180},
  {"Dagger", 10, 20, 30},
  {"Hammer", 10, 20, 30},
  {"Hand Axe", 10, 20, 30},
  {"Oil or Holy Water", 10, 30, 50},
  {"Sling", 30, 60, 90},
  {"Spear", 10, 20, 30},
  //* Missile weapon ranges are given in feet. 
  //In the wilderness, substitute yards for feet 
};

typedef enum {S, M, L} weaponSize;

struct
{
  char *Name;
  byte Cost;
  weaponSize Size;
  byte Weight;
  byte DmgDiceSize;
}Weapons[] = 
{
  //Axes
  {"Hand Axe", 4, S, 5, 6},
  {"Battle Axe", 7, M, 7, 8}, 
  {"Great Axe", 14, L, 15, 10},

  //Bows
  {"Shortbow", 25, M, 2, 6},
  //Shortbow Arrow 1sp 0.1 1d6 
  //Silver*Shortbow Arrow 2gp 0.1 1d6 
  {"Longbow", 60, L, 3, 8},
  //Longbow Arrow 2sp 0.1 1d8 
  //Silver*Longbow Arrow 4gp 0.1 1d8
  {"Light Crossbow", 30, M, 7, 6},
  //Light Quarrel 2sp 0.1 1d6 
  //Silver*Light Quarre l 5gp 0.1 1d6 
  {"Heavy Crossbow", 50, L, 14, 8},
  //Heavy Quarrel 4sp 0.1 1d8 
  //Silver*Heavy Quarrel 10gp 0.1 1d8 

  //Daggers 
  {"Dagger", 2, S, 1,4},
  {"Silver* Dagger", 25, S, 1, 4},

  //Swords 
  {"Shortsword", 6, S, 3, 6},
  {"Longsword/Scimitar", 10, M, 4, 8},
  {"Two-Handed Sword", 18, L, 10, 10},

  //Hammers and Maces 
  {"Warhammer", 4, S, 6, 6},
  {"Mace", 6, M, 10, 8},
  {"Maul", 10, L, 16, 10},

  //Other Weapons 
  {"Club/Cudgel/Walking Staff", 2, M, 1, 4},
  {"Quarterstaff", 2, L, 4, 6},
  {"Pole Arm", 9, L, 15, 10},
  {"Sling", 1, S, 0.1 },
  {"Bullet", 1, S, 0.1, 4 },
  {"Stone", 0, S, 0.1, 3 },
  {"Spear Thrown (one handed)", 5, M, 5, 6 },
  {"Spear Melee (one handed)", 5, M, 5, 6 },
  {"Spear Melee (two handed)", 5, M, 5, 8 },

  //* Silver tip or blade, for use against lycanthropes. 
};

struct
{
  char* Name;
  byte Cost, Weight, AC;
}Armor[] = 
{
  {"No Armor", 0, 0, 11},
  {"Leather Armor", 20, 15, 13}, 
  {"Chain Mail", 60, 40, 15},
  {"Plate Mail", 300, 50, 17},
  {"Shield", 7, 5, 1}
};


//Page 8
struct
{
  char* Name;
  byte VehicleLength, VehicleWidth, MovementA, MovementB, Hardness, HP, Cost;
  int Weight, CargoCapacity; //Pounds
}LandTransportation[] =
{
  {"Chariot", 15, 6, 60, 10, 10, 10, 400, 300, 750},
  {"Coach", 30, 8, 40, 15, 6, 12, 1500, 1000, 2000},
  {"Wagon", 35, 8, 20, 20, 6, 16, 500, 2000, 4000}
  //*Includes hitched horses or mules.
};

struct
{
  char* Name;
  //Cargo in tons
  byte Length, Width, Crew, MovementA, MovementB, MilesPerDayA, MilesPerDayB, Hardness, HP;
  int Cost, Cargo;
}WaterTransportation[] = 
{
  {"Canoe", 15, 4, 1, 40, 5, 30, 30, 4, 4,
   50, 0.5},
  {"Caravel", 55, 15, 10, 20, 20, 42, 42, 8, 75,
   10000, 75},
  {"Carrack", 60, 20, 20, 30, 30, 48, 48, 10, 120,
   20000, 135},
  {"Galley, Small", 100, 15, 90, 20, 20, 36, 24, 8, 75,
   15000, 210},
  {"Galley, Large", 120, 20, 160, 30, 25, 42, 24, 10, 120,
   30000, 375},
  {"Longship", 110, 15, 70, 30, 25, 42, 24, 9, 110,
   25000, 10},
  {"Raft/Barge", 10, 10, 1, 2, 40, 10, 18, 18, 6, 12,
   100, },
  {"Riverboat", 50, 20, 50, 10, 20, 20, 30, 30, 8, 30,
   3500, },
  {"Rowboat", 15, 6, 1, 30, 10, 24, 24, 6, 8,
   600, 1},
  {"Sailboat", 40, 8, 5, 40, 15, 36, 7, 20,
   2000, 1}
};

struct
{
  char* Name;
    int Cost;
  //Rate of Fire = 1/RateOfFire
  //Attack Penalty = negative
    byte RateOfFire, AttackPenalty, DamageDiceQuantity, DamageDiceSize, ShortRange, MediumRange, LongRange;   
}SiegeEngines[] = 
{
  {"Ballista", 100, 4, 3, 2, 8, 50, 100, 150}, 
  {"Battering Ram", 200, 3,0, 2,8, 0, 0, 0}, 
  {"Onager", 300, 6, 6, 2, 12, 100, 200, 300},
  {"Trebuchet", 400, 10, 8, 3, 10, 300, 400} 
};

struct
{
char* Name;
  byte Cost, Weight, Movement; 
}BeastsOfBurden[] =
{
  {"Horse, Draft", 120, 60, 10},
  {"Horse, War", 200, 60, 10},
  {"Horse, Riding", 75, 80, 10},
  {"Pony*", 40, 40, 10},
  {"Pony, War*", 80, 40, 10}, 
  {"Bit and bridle", 1.5, 0, 0},
  {"Horseshoes & shoeing", 1, 10},
  {"Saddle, Pack", 5, 15, 0},
  {"Saddle, Riding", 10, 35, 0},
  {"Saddlebags, pair", 4, 7, 0}
  //* Due to their small stature, Dwarves and Halflings must ride ponies rather than horses. 
};

/*
Monetary values 
1 platinum piece (pp)=5 gold pieces (gp) 
1 gold piece (gp)=10 silver pieces (sp) 
1 electrum piece (ep)=5 silver pieces (sp) 
1 silver piece (sp)=10 copper pieces (cp) 

Time 
Normal Game Turns - 10 minutes long
Combat Rounds - 10 seconds long* 
*60 combat rounds per game turn

Scale
Dungeon - Feet
Outdoors Yards*
*Area of effect measurements (for spells, for instance) normally remain in feet
*/

struct
{
  byte LightlyLoaded, HeavilyLoaded;
}MovementEncumberance[] =
{
  {40, 30},	//No Armor or Magic Leather
  {30, 20},	//Leather Armor or Magic Metal
  {20, 10}	//Metal Armor
};

struct
{
  byte NormalLight, NormalHeavy, HalflingLight, HalflingHeavy;
}Load[] =
{
  //Index = level - 3
  {25, 60, 20, 40}, 	//3
  {35, 90, 30, 60},	//4
  {35, 90, 30, 60},	//5
  {50, 120, 40, 80},	//6
  {50, 120, 40, 80},	//7
  {50, 120, 40, 80},	//8
  {60, 150, 50, 100},	//9
  {60, 150, 50, 100},	//10
  {60, 150, 50, 100},	//11
  {60, 150, 50, 100},	//12
  {65, 165, 55, 110},	//13
  {65, 165, 55, 110},	//14
  {65, 165, 55, 110},	//15
  {70, 180, 70, 120}, 	//16
  {70, 180, 70, 120}, 	//17
  {80, 195, 65, 130}	//18
};

//Page 9
struct{byte FeetPerRound, MilesPerDay;}WildernessMovementRates[] = 
{
  {10, 6},
  {20, 12},
  {30, 18},
  {40, 24},
  {50, 30},
  {60, 36},
  {70, 42},
  {80, 48},
  {90, 54},
  {100, 60},
  {110, 66},
  {120, 72}
  
  //•Based on 8 hour day of travel through open, clear terrain 
  //•Forced march: 12 hours per day, add 50% to the distance traveled (1d6 damage, save vs. Death Ray)
  //•Waterborne Travel: 12 hour day of travel (ships may travel 24 hours per day) 
  //•Traveling by air: overland movement rates are doubled, and all terrain effects are ignored 
};

byte OverlandTravelAdjustment[] = 
{ //Multuply by value and divide by 100
  33, //Jungle, Mountains, Swamp
  33, //Desert, Forest, Hills
  66, //Clear, Plains, Trail
  100 //Road (Paved)
};

char* WindDirection[] = 
{
  "Northerly",
  "Northeasterly",
  "Easterly",
  "Southeasterly",
  "Southerly",
  "Southwesterly",
  "Westerly",
  "Northwesterly",
  "Prevailing",
  "Prevailing",
  "Prevailing",
  "Prevailing",
};

/*
Wind Conditions Adjustment 
d% Wind Conditions Sailing
01-05 Becalmed x0
06-13 Very Light Breeze x1/3
14-25 Light Breeze x1/2
26-40 Moderate Breeze x2/3
41-70 Average Winds x1
71-85 Strong Winds x1 1/3
86-96 Very Strong Winds x1 1/2
97-00 Gale x2*/
typedef enum
{
  RefusalPenalty, 
  Refusal,
  TryAgain, 
  Acceptance,
  AcceptLoyaltyBonus
}RetainerResult;

RetainerResult retainerResult[] = 
{ //Index = Roll 2d6 + character CHA bonus - 1
  RefusalPenalty,	//1
  RefusalPenalty,	//2
  Refusal,		//3
  Refusal,		//4
  Refusal,		//5
  TryAgain,		//6
  TryAgain,  		//7
  TryAgain,  		//8
  Acceptance,		//9
  Acceptance,		//10
  Acceptance,		//11
  AcceptLoyaltyBonus  	//12
};

struct 
{
  int XPValue;
  byte SpeciaAbilityBonus;
}MonsterXPTable[] = 
{ //Index = Monster Hit Dice
  {10, 3},
  {25, 12},
  {75, 145},
  {240, 40},
  {360, 45},
  {500, 55},
  {670, 65},
  {875, 70},
  {1075, 75},
  {1300, 90},
  {1575, 95},
  {1875, 100},
  {2175, 110},
  {2500, 115},
  {2850, 125},
  {3250, 135},
  {3600, 135},
  {4000, 160},
  {4500, 175},
};

byte OpeningDoors[] =  //1 / (1+STRBonus) on 1dX
{
  6,	//Stuck door
  10,	//Locked door
  20	//Metal bars doors
};

/*
Detection - Dwarves, Elves, Others //This isn't really a data table, probably better to implement in code
Traps* 			1-2 on 1d6, 1 on 1d6, 1 on 1d6
*It takes at least a turn per 10' square area for searching

Shifting walls		1-2 on 1d6, -, -

New construction	1-2 on 1d6, -, -

Slanting passages	1-2 on 1d6, -, -

Secret doors* 		•1 on 1d6 •1-2 on 1d6 if INT>=15, •1-2 on 1d6 •1 on 1d6 with a look, •1 on 1d6 •1-2 on 1d6 if INT>=15 
*/

//Page 10 - Encounter
/*
 Encounter Sequence
 Surprise check*
 	•Normal: 1-2 on 1d6 
        •Ambush: 1-4 on 1d6 
        •Deafened: 1-3 on 1d6 
        •Blinded: 1-4 on 1d6 
  
 Initiave rolls 
 	Roll 1d6 + Dex mod. 
        High numbers act first 
        (-1 penalty if deafened, -2 if blinded)
 
 Monster reaction
 Roll 2d6 + Cha mod of the leader
 
 * For Elves reduce the range by 1
*/

/*
 Reaction Roll Table (Adjusted Die Roll, Result)
 2 or less	Immediate Attack
 3-7 		Unfavorable
 8-11 		Favorable
 12 or more 	Very Favorable
*/

/*
Morale Checks
How	Roll 2d6 <= Monster morale score
When 	•During first encounter 
	•When the monster party is reduced to half strength 
        (by numbers if more than one monster, or by 
        hit points for one monster) 
*/

/*
Typical Actions
Standard attack 	Move (encounter movement distance) + melee or ranged attack 
Run			Move (2 X encounter movement distance) 
Charge			*Move (2 X encounter movement distance) + attack (+2 bonus) 
Parting shot		Free attack (+2 bonus) vs. opponents turning from the fight 
Fighting withdrawal 	Move back (half normal walking movement) + melee attack 

* -2 penalty to Armor Class for the round 
*/

/*
Attack bonus / penalty 
Attacking From Behind 		+2 (do not combine with the Sneak Attack ability) 
Flat of the blade attack	-4 ( do half subduing damage) 
Punch				+0 (1d3 points of subduing damage) 
Kick				-2 (1d4 points of subduing damage) 
Attacker/Defender is invisible	+4 / -4 
Attacker/Defender is blinded	-4 / +4 
Defender is pinned		+4 
*/

/*
Missile fire - Target distance, Attack bonus / penalty
<= 5', 					-5 * 
> 5' AND <= Short range			+1 
> Short range AND <= Medium range	0 
> Medium range AND <= Long range	-2 
> Long range				Cannot be attacked 

* If the attacker is behind the target creature and undetected, 
or that creature is distracted apply +1 bonus 
(+3 total bonus if attacking from behind)
*/

/*
Cover and Concealment Penalty
Target is,	 Covered,	 Concealed 
25%		-2		-1 
50%		-4		-2 
75%		-6		-3 
90%		-8		-4 
*/

/*
Grenade-Like Missiles Miss Table
(behind)
  0 
7 8 9
5 T 6
2 3 4
  1 
(in front)

•Roll 1d10 and consult the diagram to determine where 
the missile hit. Treat each number as representing a 
10' square area 

•Missiles that Miss: GM roll attacks against each targets 
(no more than three). These attack rolls are made with the 
shooter's normal attack bonus, just as if he or she intended 
to attack the target. 
*/

/*
Oil Grenade-Like Missiles

•Direct hit: 1d8 points of fire damage, plus in the next round 
an additional 1d8 points of damage, unless the character spends 
the round extinguishing the flames 

•Splash Hit: 1d6 points of fire damage within 5 feet of the point
of impact. A save vs. Death Ray is allowed to avoid this damage 

•Effective for 10 rounds. Those attempting to cross the burning oil 
will receive 1d6 points of fire damage each round they are in it. 
*/

/*
Holy Water 
•Direct hit: 1d8 points damage. 

•Splash Hit: 1d6 points of fire damage within 5 feet 
of the point of impact. 

•Effective for 1 round
*/

//Page 11
//Attack Bonus Tables
//*On a hit roll a natural "1" is always a failure. A natural "20" is always a hit, if the opponent can be hit at all
byte AttackBonusTable[][] = 
{//Index = Level + 1
  {//Fighter
    1, 2, 2, 3, 4, 4, 5, 6, 6, 6, 7, 7, 8, 8, 8, 9, 9, 10, 10, 10},
  {//Cleric
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8},
  {//Thief
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8},
  {//Magic-User
    1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7},
};

//0-32 and 32+
byte MonsterAttackBonusTable[] = 
{//Index = Monster Hit Dice
    0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16};

/*
Monsters and mapping
Monsters description notation
Name		If an asterisk appears after the monster's name, it indicates that the monster 
        	is only able to be hit by special weapons (such as silver or magical weapons, 
        	or creatures affected only by fire, etc.) 

Armor Class	•If the monster  wears armor, the first listed AC value is with that armor, and 
		the second, in parentheses, is unarmored 
                •Some monsters are only able to be hit by silver(†) or magical weapons(‡)

Hit Dice 	•Monsters always roll eight sided dice (d8) for hit points, unless noted otherwise 
		•* or ** : Special Ability Bonus to experience points (each asterisk adds the special
                ability bonus once) 
                •If the monster's Attack Bonus is different than its number of Hit Dice the Attack Bonus 
                will be listed in parentheses after the Hit Dice figure MovementA distance may appear in 
                parentheses after a movement figure; this is the creature's turning distance.  If a turning 
                distance is not listed, assume 5'.
*/

typedef enum
{
  NormalDoor, DoubleDoor, LockedDoor, DoubleLockedDoor,
  Grate, Fireplace, Ladder, Curtain, Bars, Statue,
  SecretDoor, Pit, Fountain, Chest, Well, Trapdoor,
  Stairs, Spiralstair, Bed, FalseDoor, Altar, Throne,
  Ctrapdoor, Pillar
  }CommonDungeonSymbol;

//Page 12
/*
Treasure To generate a random treasure, find the indicated treasure type assigned to monsters and read across; 
where a percentage chance is given, roll percentile dice to see if that sort of treasure is found.  
If so, roll the indicated dice to determine how much. 

Lair Treasures
	100xCopper	100xSilver	100xElectrum	100xGold	100xPlatinum	Gems		Jewelry		Magic Items 
A 	50% 5d6		60% 5d6		40% 5d4		70% 10d6	50% 1d10	50% 6d6 	50% 6d6		30% any 3 
B	75% 5d10	50% 5d6		50% 5d4		50% 3d6		None		25% 1d6 	25% 1d6 	10% 1 weapon or armor 
C	60% 6d6		60% 5d4		30% 2d6		None		None		25% 1d4 	25% 1d4		15% any 1d2 
D	30% 4d6		45% 6d6		None		90% 5d8		None		30% 1d8 	30% 1d8 	20% any 1d2 + 1 potion 
E	30% 2d8		60% 6d10	50% 3d8		50% 4d10	None		10% 1d10 	10% 1d10 	30% any 1d4 + 1 scroll 
F	None		40% 3d8		50% 4d8		85% 6d10	70% 2d8		20% 2d12 	10% 1d12 	35% any 1d4 except weapons + 1 potion + 1 scroll 
G	None		None		None		90% 4d6x10	75% 5d8		25% 3d6 	25% 1d10 	50% any 1d4 + 1 scroll 
H	75% 8d10	75% 6d10x10	75% 3d10x10	75% 5d8x10	75% 9d8		50% 1d100 	50% 10d4 	20% any 1d4 + 1 potion + 1 scroll 
I	None		None		None		None		80% 3d10	50% 2d6 	50% 2d6		15% any 1 
J	45% 3d8		45% 1d8		None		None		None		None 		None		None 
K	None		90% 2d10	35% 1d8		None		None		None 		None		None 
L	None		None		None		None		None		50% 1d4 	None		None 
M	None		None		None		90% 4d10	90% 2d8x10	55% 5d4 	45% 2d6		None 
N	None		None		None		None		None		None 		None		40% 2d4 potions 
O	None		None		None		None		None		None 		None		50% 1d4 scrolls 

Individual Treasures
	Copper		Silver		Electrum	Gold		Platinum	Gems	Jewelry		Magic Items
P	3d8		None		None		None		None		None 	None		None 
Q	None		3d6		None		None		None		None	None		None 
R	None		None		2d6		None		None		None 	None		None 
S	None		None		None		2d4		None		None 	None		None 
T	None		None		None		None		1d6		None 	None		None 
U	50% 1d20	50% 1d20	None		25% 1d20	None		5% 1d4 	5% 1d4		2% Any 1 
V	None		25% 1d20	25% 1d20	50% 1d20	25% 1d20	10% 1d4 10% 1d4		5% Any 1
*/

//Page 13
/*
Unguarded Treasures
Dungeon Level	100xCopper	100xSilver	100xElectrum	100xGold	100xPlatinum	Gems		Jewelry		Magic Items 
1 		75%1d8		50%1d6		25%1d4		7%1d4		1%1d4		7%1d4 		3%1d4		2% Any 1
2		50%1d10		50%1d8		25%1d6		20%1d6		2%1d4		10%1d6 		7%1d4		5% Any 1 
3		30%2d6		50%1d10		25%1d8		50%1d6		4%1d4		15%1d6 		7%1d6		8%Any 1 
4-5		20%3d6		50%2d6		25%1d10		50%2d6		8%1d4		20%1d8 		10%1d6		12%Any 1 
6-7		15%4d6		50%3d6		25%1d12		70%2d8		15%1d4		30%1d8 		15%1d6		16%Any 1 
8+		10%5d6		50%5d6		25%2d8		75%4d6		30%1d4		40%1d8 		30%1d8		20%Any 1 

Gems and Jewelry
Use the tables below to determine the base value and number found when gems are indicated in a treasure hoard.  
If the number generated in the main table above is small, roll for each gem; but if the number is large 
(10 or more, at the GM's option), after each roll for Type and Base Value, roll the indicated die to see how 
many such gems are in the hoard. 

d%, Type, Base Value in Gold Pieces, Number Found,
01-20, Ornamental, 10, 1d10
21-45, Semiprecious, 50, 1d8
46-75, Fancy, 100, 1d6
76-95, Precious, 500, 1d4
96-00, Gem, 1000, 1d2
       Jewel, 5000, 1
       
The values of gems vary from the above for reasons of quality, size, etc. 
The GM may use the table below to adjust the values of the gems in the hoard, at his or her option.  
This is why there is no die result given in the table above for Jewel; on a roll of 12 on
the table below, a Gem can become a Jewel. 
2d6, Value Adjustment
2, Next Lower Value Row
3, 1/2 
4, 3/4 
5-9, Normal Value 
10, 1.5 Times 
11, 2 Times 
12, Next Higher Value Row 

Standard items of jewelry are valued at 2d8x100 gp value.  
The table below can be used to generate descriptions of 
the items themselves. 
d%, Type
01-06 Anklet
07-12 Belt 
13-14 Bowl 
15-21 Bracelet 
22-27 Brooch 
28-32 Buckle 
33-37 Chain 
38-40 Choker 
41-42 Circlet 
43-47 Clasp 
48-51 Comb 
52 Crown 
53-55 Cup 
56-62 Earring 
63-65 Flagon 
66-68 Goblet 
69-73 Knife 
74-77 Letter Opener 
78-80 Locket 
81-82 Medal 
83-89 Necklace 
90 Plate 
91-95 Pin 
96 Sceptre 
97-99 Statuette 
00 Tiara
*/

//Page 14
/*
Magic Item Generation
Determine the sort of item found by rolling on the following table: 
Any, 	Weapon or Armor, 	Any Exc. Weapons, 	Type of Item 
01-25 	01-70 						Weapon
26-35 	71-00			01-12			Armor
36-55				13-40			Potion
56-85				41-79			Scroll 
86-90				80-86			Ring 
91-95				87-93			Wand, Staff, or Rod 
96-00				94-00			Miscellaneous Magic 

Magic Weapons 
First, roll d% on the following table to determine the weapon type: 
d% 	Weapon Type
01-02 	Great Axe
60-65	Shortsword
03-09 	Battle Axe
66-79	Longsword
10-11 	Hand Axe
80-81 	Scimitar
12-19	Shortbow
82-83 	Two-Handed Sword 
20-27	Shortbow Arrow
84-86 	Warhammer 
28-31 	Longbow
87-94	Mace 
32-35	Longbow Arrow
95 	Maul 
36-43 	Light Quarrel
96 	Pole Arm 
44-47	Heavy Quarrel
97	Sling Bullet 
48-59	Dagger
98-00	Spear 

Next, roll on the Weapon Bonus tables.  Follow the directions given if a roll 
on the Special Enemy or Special Ability tables are indicated; generally 
multiple rolls on the Special Ability table should be ignored when rolled. 
Melee d% Roll	Missile d% Roll	Bonus
01-40 		01-46		+1 
41-50		47-58		+2 
51-55		59-64		+3 
56-57				+4 
58				+5 
59-75		65-82		+1, +2 vs. Special Enemy 
76-85		83-94		+1, +3 vs. Special Enemy 
86-95				Roll Again + Special Ability 
96-98		95-98		Cursed, -1* 
99-00		99-00		Cursed, -2* 
*If cursed weapons are rolled along with special abilities, ignore the special ability roll. 
1d6 Special Enemy 
1 Dragons
2 Enchanted
3 Lycanthropes
4 Regenerators
5 Spell Users
6 Undead

1d20 Special Ability 
01-09 Casts Light on Command 
10-11 Charm Person 
12 Drains Energy 
13-16 Flames on Command 
17-19 Locate Objects
20 Wishes

Wands, Staves and Rods
d%, Type
01-08 Rod of Cancellation 
09-13 Snake Staff
14-17 Staff of Commanding
18-28 Staff of Healing
29-30 Staff of Power
31-34 Staff of Striking
35 Staff of Wizardry
36-40 Wand of Cold 
41-45 Wand of Enemy Detection
46-50 Wand of Fear
51-55 Wand of Fireballs
56-60 Wand of Illusion
61-65 Wand of Lightning Bolts
66-73 Wand of Magic Detection
74-79 Wand of Paralyzation
80-84 Wand of Polymorph
85-92 Wand of Secret Door Detection
93-00 Wand of Trap Detection 

Rings 
d%, Type
01-06 Control Animal
07-12 Control Human
13-19 Control Plant
20-30 Delusion
31-33 Djinni Summoning
34-44 Fire Resistance
45-57 Invisibility
58-66 Protection +1
67-70 Protection +2
71 Protection +3
72-73 Regeneration 
74-75 Spell Storing
76-81 Spell Turning
82-83 Telekinesis 
84-90 Water Walking 
91-97 Weakness 
98 Wishes
99-00 X-Ray Vision

Magic Armor 
Generate the type and bonus of each item of magic armor on the tables below. 
d%, Armor Type
01-09 Leather Armor
10-28 Chain Mail
29-43 Plate Mail
44-00 Shield

d%Armor Bonus
01-50 +1 
51-80 +2 
81-90 +3 
91-95 Cursed *
96-00 Cursed, AC 11 ** 

* If Cursed armor is rolled, roll again and reverse the bonus 
(e.g., -1 instead of +1). 

** This armor has AC 11 but appears to be +1 when tested.
*/

//Page 15
/*
Miscellaneous Magic Items 
d%, Type 
01-04 Amulet of Proof against Detection and Location 
05-06 Bag of Devouring 
07-12 Bag of Holding 
13-17 Boots of Levitation 
18-22 Boots of Speed 
23-27 Boots of Traveling and Leaping 
28 Bowl Commanding Water Elementals 
29 Brazier Commanding Fire Elementals 
30-35 Broom of Flying 
36 Censer Commanding Air Elementals 
37-39 Cloak of Displacement 
40-43 Crystal Ball 
44-45 Crystal Ball with Clairaudience 
46 Drums of Panic 
47 Efreeti Bottle 
48-54 Elven Boots 
55-61 Elven Cloak 
62-63 Flying Carpet 
64-70 Gauntlets of Ogre Power 
71-72 Girdle of Giant Strength 
73-78 Helm of Reading Languages and Magic 
79 Helm of Telepathy 
80 Helm of Teleportation 
81 Horn of Blasting 
82-90 Medallion of ESP 
91 Mirror of Life Trapping 
92-96 Rope of Climbing 
97-99 Scarab of Protection 
00 Stone Commanding Earth Elementals 

Wands, Staves and Rods 
d%, Type 
01-08 Rod of Cancellation
09-13 Snake Staff
14-17 Staff of Commanding
18-28 Staff of Healing
29-30 Staff of Power
31-34 Staff of Striking
35 Staff of Wizardry
36-40 Wand of Cold
41-45 Wand of Enemy Detection
46-50 Wand of Fear
51-55 Wand of Fireballs
56-60 Wand of Illusion
61-65 Wand of Lightning Bolts
66-73 Wand of Magic Detection
74-79 Wand of Paralyzation
80-84 Wand of Polymorph
85-92 Wand of Secret Door Detection
93-00 Wand of Trap Detection

Potions
d%, Type
01-03 Clairaudience
04-07 Clairvoyance
08-10 Control Animal
11-13 Control Dragon
14-16 Control Giant
17-19 Control Human
20-22 Control Plant
23-25 Control Undead
26-32 Delusion
33-35 Diminution
36-39 ESP
40-43 Fire Resistance
44-47 Flying
48-51 Gaseous Form
52-55 Giant Strength
56-59 Growth
60-63 Healing
64-68 Heroism
69-72 Invisibility
73-76 Invulnerability 
77-80 Levitation
81-84 Longevity
85-86 Poison
87-89 Polymorph Self
90-97 Speed
98-00 Treasure Finding

Scrolls
d%, General Type
01-03 Cleric Spell Scroll (1 Spell)
04-06 Cleric Spell Scroll (2 Spells)
07-08 Cleric Spell Scroll (3 Spells)
09 Cleric Spell Scroll (4 Spells)
10-15 Magic-User Spell Scroll (1 Spell)
16-20 Magic-User Spell Scroll (2 Spells)
21-25 Magic-User Spell Scroll (3 Spells)
26-29 Magic-User Spell Scroll (4 Spells)
30-32 Magic-User Spell Scroll (5 Spells)
33-34 Magic-User Spell Scroll (6 Spells)
35 Magic-User Spell Scroll (7 Spells)
36-40 Cursed Scroll
41-46 Protection from Elementals
47-56 Protection from Lycanthropes
57-61 Protection from Magic
62-75 Protection from Undead
76-85 Map to Treasure Type A
86-89 Map to Treasure Type E
90-92 Map to Treasure Type G
93-00 Map to 1d4 Magic Items
*/

//Page 16-17 - Encounters
typedef enum
{
  //Dungeon Encounters
  /*Level 1*/	Bee, Goblin, GreenSlime, Kobold, NPCPartyAdventurer, NPCPartyBandit, Orc, Skeleton, CobraSnake, GiantCrabSpider, Stirge, Wolf,
  /*Level 2*/	GiantBombardierBeetle, GiantFly, Ghoul, Gnoll, GrayOoze, Hobgoblin, LizardMan, /*NPCPartyAdventurer,*/ PitViperSnake, GiantBlackWidowSpider, Troglodyte, Zombie,
  /*Level 3*/	GiantAnt, CarnivorousApe, GiantTigerBeetle, Bugbear, Doppleganger, Gargoyle, GelatinousCube, WereratLycanthrope, Ogre, Shadow, TentacleWorm, Wight,
  /*Level 4-5*/	CaveBear, GiantCaecilia, Cockatrice, /*Doppleganger,*/ /*GrayOoze,*/ Hellhound, WerewolfLycanthrope, Minotaur, OchreJelly, Owlbear, RustMonster, Wraith,
  /*Level 6-7*/	Basilisk, BlackPudding, Caecilia, Displacer, Hydra, WeretigerLycanthrope, Mummy, /*Owlbear,*/ /*RustMonster,*/ GiantScorpion, Spectre, Troll,
  /*Level 8+*/	/*BlackPudding,*/ Chimera, HillGiant, StoneGiant, /*Hydra,*/ WereboarLycanthrope, PurpleWorm, FlameSalamander, FrostSalamander, Vampire,

  //City, Town or Village Encounters (2d6)
  /*Day Encounter*/ 	/*Doppleganger,*/ Noble, NPCThief, Bully, CityWatch, Merchant, Beggar, Priest, Mercenary, Wizard, /*WereratLycanthrope,*/
  /*Night Encounter*/	/*Doppleganger,*/ /*Shadow,*/ PressGang, /*Beggar,*/ /*Thief,*/ /*Bully,*/ /*Merchant,*/ GiantRat, /*CityWatch,*/ /*Wizard,*/ /*WereratLycanthrope,*/
  
  //Wilderness Encounters
  /*Desert or Barren*/		BlueDragon, /*Hellhound,*/ FireGiant, /*PurpleWorm,*/ /*GiantFly,*/ /*GiantScorpion,*/ Camel, GiantTarantellaSpider, NPCPartyMerchant, /*NPCPartyMerchant,*/ Hawk, /*NPCPartyBandit,*/ /*Ogre,*/ Griffon, /*Gnoll,*/ RedDragon,
  /*Grassland*/			GreenDragon, /*Troll, GiantFly, GiantScorpion, NPCPartyBandit,*/ Lion, WildBoar, NPCPartyPilgrim, /*Wolf,*/ GiantBee, /*Gnoll, Goblin,*/ BlinkDog, DireWolf, /*HillGiant,*/
  /*Inhabited Territories*/ 	GoldDragon, /*Ghoul, Bugbear, Goblin,*/ Centaur, /*NPCPartyBandit, NPCPartyMerchant,*/ NPCPartyNoble, Dog, /*Gargoyle, Gnoll, Ogre, Minotaur, Vampire*/
  /*Jungle*/			/*GreenDragon, NPCPartyBandit, Goblin, Hobgoblin,*/ GiantCentipede, GiantPythonSnake, Elephant, Antelope, Jaguar, /*Stirge, GiantTigerBeetle, GiantCaecilia, Shadow, NPCPartyMerchant, WeretigerLycanthrope,*/
  /*Mountains or Hills*/	WhiteDragon, Roc/* (1d6: 1-3 Large, 4-5 Huge, 6 Giant)*/, /*Displacer,*/ /*WerewolfLycanthrope,*/ MountainLion, /*Wolf, GiantCrabSpider, Hawk, Orc,*/ GiantBat, GiantHawk, /*HillGiant, Chimera, DireWolf, RedDragon,*/
  /*Ocean*/			SeaDragon, /*Hydra,*/ SpermWhale, GiantCrocodile, GiantCrab, KillerWhale, GiantOctopus, MakoShark, /*NPCPartyMerchant,*/ NPCPartyBuccaneer, BullShark, /*Roc (1d8: 1-5 Huge, 6-8 Giant),*/ GreatWhiteShark, Mermaid, SeaSerpent,
  /*River or Riverside*/	BlackDragon, GiantPiranhaFish, /*Stirge,*/ GiantBassFish, /*NPCPartyMerchant,*/ Lizardman, Crocodile, GiantFrog, GiantCatfish, /*NPCPartyBuccaneer, Troll, Jaguar,*/ Nixie, GiantWaterTermite, /*GreenDragon,*/
  /*Swamp*/			/*BlackDragon, Shadow, Troll,*/ GiantDracoLizard, /*GiantCentipede,*/ GiantLeech, /*Lizardman, Crocodile, Stirge, Orc,*/ GiantToad/* (see Frog, Giant)*/, /*Troglodyte,*/ BloodRose, HangmanTree, /*Basilisk,*/
  /*Woods or Forest */		/*GreenDragon,*/ Alicorn/* (see Unicorn)*/, Treant, /*Orc, WildBoar,*/ BlackBear, /*GiantHawk, Antelope, Wolf, Ogre,*/ BrownBear, /*DireWolf, HillGiant, Owlbear,*/ Unicorn
}EncounterMonster;

EncounterMonster DungeonEncounters[][] = 
{
  //The Game Master should check once every 3 turns 
  //* Roll 1d6; on a roll of 1, an encounter occurs.  
  //* Roll 1d12 on the appropriate table.
  {/*Level 1*/		Bee, Goblin, GreenSlime, Kobold, NPCPartyAdventurer, NPCPartyBandit, Orc, Skeleton, CobraSnake, GiantCrabSpider, Stirge, Wolf},
  {/*Level 2*/		GiantBombardierBeetle, GiantFly, Ghoul, Gnoll, GrayOoze, Hobgoblin, LizardMan, NPCPartyAdventurer, PitViperSnake, GiantBlackWidowSpider, Troglodyte, Zombie},
  {/*Level 3*/		GiantAnt, CarnivorousApe, GiantTigerBeetle, Bugbear, Doppleganger, Gargoyle, GelatinousCube, WereratLycanthrope, Ogre, Shadow, TentacleWorm, Wight},
  {/*Level 4-5*/	CaveBear, GiantCaecilia, Cockatrice, Doppleganger, GrayOoze, Hellhound, WerewolfLycanthrope, Minotaur, OchreJelly, Owlbear, RustMonster, Wraith},
  {/*Level 6-7*/	Basilisk, BlackPudding, Caecilia, Displacer, Hydra, WeretigerLycanthrope, Mummy, Owlbear, RustMonster, GiantScorpion, Spectre, Troll},
  {/*Level 8+*/		BlackPudding, Chimera, HillGiant, StoneGiant, Hydra, WereboarLycanthrope, PurpleWorm, FlameSalamander, FrostSalamander, Vampire},
};

EncounterMonster CityEncounters[][] = 
{
  //Roll 2d6
  /*Day Encounter*/ 	{Doppleganger, Noble, NPCThief, Bully, CityWatch, Merchant, Beggar, Priest, Mercenary, Wizard, WereratLycanthrope,},
  /*Night Encounter*/	{Doppleganger, Shadow, PressGang, Beggar, Thief, Bully, Merchant, GiantRat, CityWatch, Wizard, WereratLycanthrope,},

};

EncounterMonster WildernessEncounters[][] = 
{
  //Check about every four hours of game time (this translates nicely to three night checks and three daytime checks)
  //* Roll 1d6; on a roll of 1, an encounter occurs.
  //* Roll 2d8 on the appropriate table.
  /*Desert or Barren*/		{BlueDragon, Hellhound, FireGiant, PurpleWorm, GiantFly, GiantScorpion, Camel, GiantTarantellaSpider, NPCPartyMerchant, NPCPartyMerchant, Hawk, NPCPartyBandit, Ogre, Griffon, Gnoll, RedDragon},
  /*Grassland*/ 		{GreenDragon, Troll, GiantFly, GiantScorpion, NPCPartyBandit, Lion, WildBoar, NPCPartyPilgrim, Wolf, GiantBee, Gnoll, Goblin, BlinkDog, DireWolf, HillGiant},
  /*Inhabited Territories*/ 	{GoldDragon, Ghoul, Bugbear, Goblin, Centaur, NPCPartyBandit, NPCPartyMerchant, NPCPartyNoble, Dog, Gargoyle, Gnoll, Ogre, Minotaur, Vampire},
  /*Jungle*/			{GreenDragon, NPCPartyBandit, Goblin, Hobgoblin, GiantCentipede, GiantPythonSnake, Elephant, Antelope, Jaguar, Stirge, GiantTigerBeetle, GiantCaecilia, Shadow, NPCPartyMerchant, WeretigerLycanthrope},
  /*Mountains or Hills*/	{WhiteDragon, Roc/* (1d6: 1-3 Large, 4-5 Huge, 6 Giant)*/, Displacer, WerewolfLycanthrope, MountainLion, Wolf, GiantCrabSpider, Hawk, Orc, GiantBat, GiantHawk, HillGiant, Chimera, DireWolf, RedDragon},
  /*Ocean*/			{SeaDragon, Hydra, SpermWhale, GiantCrocodile, GiantCrab, KillerWhale, GiantOctopus, MakoShark, NPCPartyMerchant, NPCPartyBuccaneer, BullShark, Roc /*(1d8: 1-5 Huge, 6-8 Giant)*/, GreatWhiteShark, Mermaid, SeaSerpent},
  /*River or Riverside*/	{BlackDragon, GiantPiranhaFish, Stirge, GiantBassFish, NPCPartyMerchant, Lizardman, Crocodile, GiantFrog, GiantCatfish, NPCPartyBuccaneer, Troll, Jaguar, Nixie, GiantWaterTermite, GreenDragon},
  /*Swamp*/			{BlackDragon, Shadow, Troll, GiantDracoLizard, GiantCentipede, GiantLeech, Lizardman, Crocodile, Stirge, Orc, GiantToad/* (see Frog, Giant)*/, Troglodyte, BloodRose, HangmanTree, Basilisk},
  /*Woods or Forest */		{GreenDragon, Alicorn/* (see Unicorn)*/, Treant, Orc, WildBoar,BlackBear, GiantHawk, Antelope, Wolf, Ogre, BrownBear, DireWolf, HillGiant, Owlbear, Unicorn},
};

enum{NullAttack, Sting, }AttackNames;
enum{NullMovement, Fly,}MovementNames;
enum{NullTreasure, Special}TreasureTypeNames;

struct
{
  char* Name;
  byte ArmorClass, HitDice, 
  AttackNameA, AttackCountA, AttackDamageDiceSizeA, AttackDamageDiceCountA, 
  AttackNameB, AttackCountB, AttackDamageDiceSizeB, AttackDamageDiceCountB, 
  AttackNameC, AttackCountC, AttackDamageDiceSizeC, AttackDamageDiceCountC,
  MovementA, MovementType, MovementB,
  AppearDiceCountWild, AppearDiceSizeWild,
  AppearDiceCountLair, AppearDiceSizeLair;
  CharacterClass SaveAsClass;
  byte SaveAsLevel, Morale, TreasureType;
  int XP;
}MonsterData[] = 
{
  {
    "Bee", 13, 0.25, 1, 
    Sting, 1, 4,
    NullAttack, 0, 0,
    NullAttack, 0, 0,
    10, Fly, 50,
    1, 6, 5, 6,
    Fighter, 1,
    9, //12 if queen is threatened
    Special,
    13},

    /*
    Bee, Giant
    Armor Class: 13
    Hit Dice: ½* (1d4 hit points)
    No. of Attacks: 1 sting
    Damage: 1d4 + poison sting
    Movement: 10' Fly 50'
    No. Appearing: 1d6, Wild 1d6, Lair 5d6
    Save As: Fighter: 1
    Morale: 9 (12 if queen is threatened)
    Treasure Type: Special
    XP: 13
    */
  {"Goblin"},
  {"GreenSlime"}, 
  {"Kobold"},
  {"NPCPartyAdventurer"},
  {"NPCPartyBandit"}, 
  {"Orc"},
  {"Skeleton"}, 
  {"CobraSnake"}, 
  {"GiantCrabSpider"}, 
  {"Stirge"}, 
  {"Wolf"}, 
  {"GiantBombardierBeetle"}, 
  {"GiantFly"}, 
  {"Ghoul"}, 
  {"Gnoll"}, 
  {"GrayOoze"}, 
  {"Hobgoblin"}, 
  {"LizardMan"},
  {"NPCPartyAdventurer"},
  {"PitViperSnake"},
  {"GiantBlackWidowSpider"},
  {"Troglodyte"}, 
  {"Zombie"},
  {"GiantAnt"},
  {"CarnivorousApe"},
  {"GiantTigerBeetle"},
  {"Bugbear"}, 
  {"Doppleganger"}, 
  {"Gargoyle"}, 
  {"GelatinousCube"}, 
  {"WereratLycanthrope"},
  {"Ogre"}, 
  {"Shadow"}, 
  {"TentacleWorm"},
  {"Wight"},
  {"CaveBear"},
  {"GiantCaecilia"},
  {"Cockatrice"}, 
  {"Hellhound"},
  {"WerewolfLycanthrope"},
  {"Minotaur"},
  {"OchreJelly"},
  {"Owlbear"},
  {"RustMonster"},
  {"Wraith"},
  {"Basilisk"},
  {"BlackPudding"},
  {"Caecilia"},
  {"Displacer"},
  {"Hydra"},
  {"WeretigerLycanthrope"},
  {"Mummy"},
  {"GiantScorpion"},
  {"Spectre"},
  {"Troll"},
  {"Chimera"},
  {"HillGiant"},
  {"StoneGiant"},
  {"WereboarLycanthrope"},
  {"PurpleWorm"},
  {"FlameSalamander"},
  {"FrostSalamander"},
  {"Vampire"},
  {"Noble"},
  {"NPCThief"},
  {"Bully"},
  {"CityWatch"}, 
  {"Merchant"},
  {"Beggar"},
  {"Priest"},
  {"Mercenary"}, 
  {"Wizard"},
  {"PressGang"},
  {"GiantRat"},
  {"BlueDragon"},
  {"FireGiant"},
  {"Camel"},
  {"GiantTarantellaSpider"},
  {"NPCPartyMerchant"},
  {"Hawk"},
  {"RedDragon"},
  {"GreenDragon"},
  {"Lion"},
  {"WildBoar"},
  {"NPCPartyPilgrim"},
  {"GiantBee"},
  {"BlinkDog"},
  {"DireWolf"},
  {"GoldDragon"},
  {"Centaur"},
  {"NPCPartyNoble"},
  {"Dog"},
  {"GiantCentipede"},
  {"GiantPythonSnake"},
  {"Elephant"},
  {"Antelope"},
  {"Jaguar"},
  {"WhiteDragon"},
  {"Roc"}, /* (1d6: 1-3 Large, 4-5 Huge, 6 Giant)*/
  {"MountainLion"},
  {"GiantBat"},
  {"GiantHawk"},
  {"SeaDragon"},
  {"SpermWhale"},
  {"GiantCrocodile"},
  {"GiantCrab"},
  {"KillerWhale"},
  {"GiantOctopus"},
  {"MakoShark"},
  {"NPCPartyBuccaneer"},
  {"BullShark"},
  {"GreatWhiteShark"},
  {"Mermaid"},
  {"SeaSerpent"},
  {"BlackDragon"},
  {"GiantPiranhaFish"},
  {"GiantBassFish"},
  {"Lizardman"},
  {"Crocodile"},
  {"GiantFrog"},
  {"GiantCatfish"},
  {"Nixie"},
  {"GiantWaterTermite"},
  {"GiantDracoLizard"},
  {"GiantLeech"},
  {"GiantToad"}, /* (see Frog, Giant)*/
  {"BloodRose"},
  {"HangmanTree"},
  {"Alicorn"},/* (see Unicorn)*/
  {"Treant"},
  {"BlackBear"},
  {"BrownBear"},
  {"Unicorn"},
};

//Open Game License
/*
OPEN GAME LICENSE INTRODUCTION Basic Fantasy RPG Charts and Tables (hereinafter “the Supplement”)
is based on the System Reference Document v3.5 ("SRD"), which is Open Game Content.    
The text of the Open Game License itself is not Open Game Content. 
Instructions on using the License are provided within the License itself. Designation of Open Game Content: 
The entire text of the Supplement (except the Open Game License, as noted above) is Open Game Content,
released under the Open Game License, Version 1.0a (reproduced below) as described in Section 1(d) of the License. 
Artwork incorporated in this document is not Open Game Content, and remains the property of the copyright holder.
Designation of Product Identity:  Product identity is not Open Game Content. 
The following is designated as product identity pursuant to OGL v1.0a(1)(e) and 
(7): (A) product and product line names, including Basic Fantasy Role-Playing Game, Basic Fantasy RPG, 
and BFRPG, as well as the phrase “make mine Basic”; (B) all artwork, logos, symbols, graphic designs, depictions,
likenesses, formats, poses, concepts, themes and graphic, photographic and other visual representations,
including the “eye” logo, which is the personal mark of Chris Gonnerman for his various products, and which is
Copyright © 2002 Chris Gonnerman, and the “Scribbled Dragon,” which is Copyright © 2005 Erik Wilson; (C) logos 
and trademarks, including any trademark or registered trademark clearly identified as product identity by the owner
of the product identity, and which specifically excludes the open game content. More information on the Open 
Game License can be found at: http://www.wizards.com/d20 OPEN GAME LICENSE VERSION 1.0A The following text is 
the property of Wizards of the Coast, Inc. and is Copyright 2000 Wizards of the Coast, Inc ("Wizards"). All Rights 
Reserved. 1. Definitions: (a)"Contributors" means the copyright and/or trademark owners who have contributed
Open Game Content; (b)"Derivative Material" means copyrighted material including derivative works and translations
(including into other computer languages), potation, modification, correction, addition, extension, upgrade,
improvement, compilation, abridgment or other form in which an existing work may be recast, transformed or adapted; 
(c) "Distribute" means to reproduce, license, rent, lease, sell, broadcast, publicly display, transmit or otherwise 
distribute; (d)"Open Game Content" means the game mechanic and includes the methods, procedures, processes and
routines to the extent such content does not embody the Product Identity and is an enhancement over the prior 
art and any additional content clearly identified as Open Game Content by the Contributor, and means any work 
covered by this License, including translations and derivative works under copyright law, but specifically 
excludes Product Identity. (e) "Product Identity" means product and product line names, logos and identifying 
marks including trade dress; artifacts; creatures characters; stories, storylines, plots, thematic elements,
dialogue, incidents, language, artwork, symbols, designs, depictions, likenesses, formats, poses, concepts,
themes and graphic, photographic and other visual or audio representations; names and descriptions of characters,
spells, enchantments, personalities, teams, personas, likenesses and special abilities; places, locations,
environments, creatures, equipment, magical or supernatural abilities or effects, logos, symbols, or graphic
designs; and any other trademark or registered trademark clearly identified as Product identity by the owner of 
the Product Identity, and which specifically excludes the Open Game Content; (f) "Trademark" means the logos,
names, mark, sign, motto, designs that are used by a Contributor to identify itself or its products or the 
associated products contributed to the Open Game License by the Contributor (g) "Use", "Used" or "Using" means 
to use, Distribute, copy, edit, format, modify, translate and otherwise create Derivative Material of Open Game
Content. (h) "You" or "Your" means the licensee in terms of this agreement. 2. The License: This License applies
to any Open Game Content that contains a notice indicating that the Open Game Content may only be Used under and
in terms of this License. You must affix such a notice to any Open Game Content that you Use. No terms may be 
added to or subtracted from this License except as described by the License itself. No other terms or conditions
may be applied to any Open Game Content distributed using this License. 3.Offer and Acceptance: By Using the 
Open Game Content You indicate Your acceptance of the terms of this License. 4. Grant and Consideration: In
consideration for agreeing to use this License, the Contributors grant You a perpetual, worldwide, royalty-free,
non-exclusive license with the exact terms of this License to Use, the Open Game Content. 5.Representation of
Authority to Contribute: If You are contributing original material as Open Game Content, You represent that Your 
Contributions are Your original creation and/or You have sufficient rights to grant the rights conveyed by this 
License. 6.Notice of License Copyright: You must update the COPYRIGHT NOTICE portion of this License to 
include the exact text of the COPYRIGHT NOTICE of any Open Game Content You are copying, modifying or distributing,
and You must add the title, the copyright date, and the copyright holder's name to the COPYRIGHT NOTICE of any 
original Open Game Content you Distribute. 7. Use of Product Identity: You agree not to Use any Product Identity,
including as an indication as to compatibility, except as expressly licensed in another, independent Agreement 
with the owner of each element of that Product Identity. You agree not to indicate compatibility or
coadaptability with any Trademark or Registered Trademark in conjunction with a work containing Open Game Content
except as expressly licensed in another, independent Agreement with the owner of such Trademark or Registered 
Trademark. The use of any Product Identity in Open Game Content does not constitute a challenge to the ownership 
of that Product Identity. The owner of any Product Identity used in Open Game Content shall retain all rights,
title and interest in and to that Product Identity. 8. Identification: If you distribute Open Game Content
You must clearly indicate which portions of the work that you are distributing are Open Game Content. 9. Updating
the License: Wizards or its designated Agents may publish updated versions of this License. You may use any
authorized version of this License to copy, modify and distribute any Open Game Content originally distributed
under any version of this License. 10. Copy of this License: You MUST include a copy of this License with every 
copy of the Open Game Content You Distribute. 11. Use of Contributor Credits: You may not market or advertise the
Open Game Content using the name of any Contributor unless You have written permission from the Contributor to do 
so. 12. Inability to Comply: If it is impossible for You to comply with any of the terms of this License with 
respect to some or all of the Open Game Content due to statute, judicial order, or governmental regulation then 
You may not Use any Open Game Material so affected. 13. Termination: This License will terminate automatically if
You fail to comply with all terms herein and fail to cure such breach within 30 days of becoming aware of the
breach. All sublicenses shall survive the termination of this License. 14. Reformation: If any provision of this
License is held to be unenforceable, such provision shall be reformed only to the extent necessary to make it
enforceable. 15. COPYRIGHT NOTICE Open Game License v 1.0 Copyright 2000, Wizards of the Coast, Inc. System 
Reference Document Copyright 2000-2003, Wizards of the Coast, Inc.; Authors Jonathan Tweet, Monte Cook, Skip 
Williams, Rich Baker, Andy Collins, David Noonan, Rich Redman, Bruce R. Cordell, John D. Rateliff, Thomas Reid,
James Wyatt, based on original material by E. Gary Gygax and Dave Arneson. Castles & Crusades: Players Handbook,
Copyright 2004, Troll Lord Games; Authors Davis Chenault and Mac Golden. Castles & Crusades: Monsters Product 
Support, Copyright 2005, Troll Lord Games. Basic Fantasy Role-Playing Game Copyright © 2006-2016 Chris Gonnerman.
Basic Fantasy Role-Playing Game Charts and Tables Copyright © 2010, 2016, 2021 Simone Felli
*/
