#include <stdint.h>
typedef uint8_t byte;	// 8-bit unsigned
typedef int8_t sbyte;	// 8-bit signed
typedef uint16_t word;	// 16-bit unsigned
typedef enum { false, true } bool; // boolean

//"BFRPG-Charts-and-Tables-by-Simone-Felli-R3.pdf
// Page 1 - Character Creation
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
    "Elf@",
    //Classes Allowed
    true,		 	//Cleric
    true,			//Magic-User
    true,			//Fighter
    true,			//Thief
    true,			//Fighter Magic-User
    
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
  }
}; 