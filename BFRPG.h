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

struct {sbyte Modifier[19];}AbilityBonus = {{
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
}}; //Index = Level

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
    "Dwarf@",
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
    "Human@",
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
    "Halfling@",
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
    "Elf@",
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
struct
{
  char Name[11];
  uint16_t ExpRequired[20];
  byte HitDiceQuantity[20], HitDiceSize, HitDiceBonus[20],
  SpellsLevel1[20], SpellsLevel2[20], SpellsLevel3[20], SpellsLevel4[20], SpellsLevel5[20], SpellsLevel6[20];
}ClassDescription[4] = 
{
  {
    "Cleric@",
    
    //Exp Points
    0,			//Level 1
    1500,		//Level 2
    1500,		//Level 3
    3000,		//Level 4
    6000,		//Level 5
    12000,		//Level 6
    24000,		//Level 7
    (90000 / 2 - 3000),	//Level 8 (why does this throw an error if it's just 42000?)
    90000,		//Level 9
    90000,		//Level 10
    90000,		//Level 11
    90000,		//Level 12
    90000,		//Level 13
    90000,		//Level 14
    90000,		//Level 15
    90000,		//Level 16
    90000,		//Level 17
    90000,		//Level 18
    90000,		//Level 19
    90000,		//Level 20
    
    //Hit Dice Quantity
    1,			//Level 1
    2,		//Level 2
    3,		//Level 3
    4,		//Level 4
    5,		//Level 5
    6,		//Level 6
    7,		//Level 7
    8,		//Level 8
    9,		//Level 9
    9,		//Level 10
    9,		//Level 11
    9,		//Level 12
    9,		//Level 13
    9,		//Level 14
    9,		//Level 15
    9,		//Level 16
    9,		//Level 17
    9,		//Level 18
    9,		//Level 19
    9,		//Level 20
    //Hit Dice Size
    6,
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
    1,		//Level 10
    2,		//Level 11
    3,		//Level 12
    4,		//Level 13
    5,		//Level 14
    6,		//Level 15
    7,		//Level 16
    8,		//Level 17
    9,		//Level 18
    10,		//Level 19
    11,		//Level 20
    
    //Spells
    //Level 1
    0,		//Level 1
    1,		//Level 2
    2,		//Level 3
    2,		//Level 4
    2,		//Level 5
    2,		//Level 6
    3,		//Level 7
    3,		//Level 8
    3,		//Level 9
    3,		//Level 10
    4,		//Level 11
    4,		//Level 12
    4,		//Level 13
    4,		//Level 14
    4,		//Level 15
    5,		//Level 16
    5,		//Level 17
    5,		//Level 18
    6,		//Level 19
    6,		//Level 20
    //Level 2
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    1,		//Level 4
    2,		//Level 5
    2,		//Level 6
    2,		//Level 7
    2,		//Level 8
    3,		//Level 9
    3,		//Level 10
    3,		//Level 11
    4,		//Level 12
    4,		//Level 13
    4,		//Level 14
    4,		//Level 15
    4,		//Level 16
    5,		//Level 17
    5,		//Level 18
    5,		//Level 19
    5,		//Level 20
    //Level 3
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    1,		//Level 6
    2,		//Level 7
    2,		//Level 8
    2,		//Level 9
    2,		//Level 10
    3,		//Level 11
    3,		//Level 12
    3,		//Level 13
    4,		//Level 14
    4,		//Level 15
    4,		//Level 16
    4,		//Level 17
    4,		//Level 18
    4,		//Level 19
    5,		//Level 20
    //Level 4
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    0,		//Level 6
    0,		//Level 7
    1,		//Level 8
    2,		//Level 9
    2,		//Level 10
    2,		//Level 11
    2,		//Level 12
    3,		//Level 13
    3,		//Level 14
    3,		//Level 15
    3,		//Level 16
    3,		//Level 17
    4,		//Level 18
    4,		//Level 19
    4,		//Level 20
    //Level 5
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    0,		//Level 6
    0,		//Level 7
    0,		//Level 8
    0,		//Level 9
    1,		//Level 10
    2,		//Level 11
    2,		//Level 12
    2,		//Level 13
    2,		//Level 14
    3,		//Level 15
    3,		//Level 16
    3,		//Level 17
    3,		//Level 18
    3,		//Level 19
    3,		//Level 20
    //Level 6
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    0,		//Level 6
    0,		//Level 7
    0,		//Level 8
    0,		//Level 9
    0,		//Level 10
    1,		//Level 11
    2,		//Level 12
    2,		//Level 13
    2,		//Level 14
    2,		//Level 15
    2,		//Level 16
    2,		//Level 17
    3,		//Level 18
    3,		//Level 19
    3,		//Level 20
  },
  {
    "Magic User@",
    
    //Exp Points
    0,			//Level 1
    2500,		//Level 2
    5000,		//Level 3
    10000,		//Level 4
    20000,		//Level 5
    (80000 / 2),	//Level 6
    70000,		//Level 7
    150000,		//Level 8
    150000,		//Level 9
    150000,		//Level 10
    150000,		//Level 11
    150000,		//Level 12
    150000,		//Level 13
    150000,		//Level 14
    150000,		//Level 15
    150000,		//Level 16
    150000,		//Level 17
    150000,		//Level 18
    150000,		//Level 19
    150000,		//Level 20
    
    //Hit Dice Quantity
    1,			//Level 1
    2,		//Level 2
    3,		//Level 3
    4,		//Level 4
    5,		//Level 5
    6,		//Level 6
    7,		//Level 7
    8,		//Level 8
    9,		//Level 9
    9,		//Level 10
    9,		//Level 11
    9,		//Level 12
    9,		//Level 13
    9,		//Level 14
    9,		//Level 15
    9,		//Level 16
    9,		//Level 17
    9,		//Level 18
    9,		//Level 19
    9,		//Level 20
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
    1,		//Level 10
    2,		//Level 11
    3,		//Level 12
    4,		//Level 13
    5,		//Level 14
    6,		//Level 15
    7,		//Level 16
    8,		//Level 17
    9,		//Level 18
    10,		//Level 19
    11,		//Level 20
    
    //Spells
    //Level 1
    1,		//Level 1
    2,		//Level 2
    2,		//Level 3
    2,		//Level 4
    2,		//Level 5
    3,		//Level 6
    3,		//Level 7
    3,		//Level 8
    3,		//Level 9
    4,		//Level 10
    4,		//Level 11
    4,		//Level 12
    4,		//Level 13
    4,		//Level 14
    5,		//Level 15
    5,		//Level 16
    5,		//Level 17
    6,		//Level 18
    6,		//Level 19
    6,		//Level 20
    //Level 2
    0,		//Level 1
    0,		//Level 2
    1,		//Level 3
    2,		//Level 4
    2,		//Level 5
    2,		//Level 6
    2,		//Level 7
    3,		//Level 8
    3,		//Level 9
    3,		//Level 10
    4,		//Level 11
    4,		//Level 12
    4,		//Level 13
    4,		//Level 14
    4,		//Level 15
    5,		//Level 16
    5,		//Level 17
    5,		//Level 18
    5,		//Level 19
    5,		//Level 20
    //Level 3
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    1,		//Level 5
    2,		//Level 6
    2,		//Level 7
    2,		//Level 8
    2,		//Level 9
    3,		//Level 10
    3,		//Level 11
    3,		//Level 12
    4,		//Level 13
    4,		//Level 14
    4,		//Level 15
    4,		//Level 16
    4,		//Level 17
    4,		//Level 18
    5,		//Level 19
    5,		//Level 20
    //Level 4
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    0,		//Level 6
    1,		//Level 7
    2,		//Level 8
    2,		//Level 9
    2,		//Level 10
    2,		//Level 11
    3,		//Level 12
    3,		//Level 13
    3,		//Level 14
    3,		//Level 15
    3,		//Level 16
    4,		//Level 17
    4,		//Level 18
    4,		//Level 19
    4,		//Level 20
    //Level 5
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    0,		//Level 6
    0,		//Level 7
    0,		//Level 8
    1,		//Level 9
    2,		//Level 10
    2,		//Level 11
    2,		//Level 12
    2,		//Level 13
    3,		//Level 14
    3,		//Level 15
    3,		//Level 16
    3,		//Level 17
    3,		//Level 18
    3,		//Level 19
    4,		//Level 20
    //Level 6
    0,		//Level 1
    0,		//Level 2
    0,		//Level 3
    0,		//Level 4
    0,		//Level 5
    0,		//Level 6
    0,		//Level 7
    0,		//Level 8
    0,		//Level 9
    0,		//Level 10
    1,		//Level 11
    2,		//Level 12
    2,		//Level 13
    2,		//Level 14
    2,		//Level 15
    2,		//Level 16
    3,		//Level 17
    3,		//Level 18
    3,		//Level 19
    3,		//Level 20
  },
  {},
  {}
};