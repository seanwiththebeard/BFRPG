#include <stdint.h>
typedef uint8_t byte;	// 8-bit unsigned

//"BFRPG-Charts-and-Tables-by-Simone-Felli-R3.pdf
// Page 1
enum ability
{
  STR, 
  //•Melee attack rolls.
  //•Damage rolls when using a melee weapon or a thrown weapon (including slings)
  DEX,
  //•Ranged attack rolls (bows, crossbows, throwing axes)
  //•Armor Class (AC)
  //•Initiative die roll
  CON,
  //•Hit Die
  //•Some saving throws vs. poison
  INT,
  //•Number of languages the character knows
  //•Some saving throws vs. illusion
  WIS,
  //•Some saving throws vs. magical attacks
  CHA
  //•Reaction rolls
  //•Number of retainers a character may hire
  };
