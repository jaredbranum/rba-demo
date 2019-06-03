#include <stdio.h>
#include "button_defs.h"
#include "item_defs.h"
typedef char Item;
typedef char Button;
typedef char ItemAmount;

/* 
  0 - Item equipped to B
  1 - Item equipped to C-Left
  2 - Item equipped to C-Down
  3 - Item equipped to C-Right
  4 - Inventory offset for Item equipped to C-Left (used for bottles)
  5 - Inventory offset for Item equipped to C-Down (used for bottles)
  6 - Inventory offset for Item equipped to C-Right (used for bottles)
 */
Button buttons[7];

/* Used for bottles */
Button last_used_button;

typedef struct
{
  Item items[24];
  ItemAmount ammo[16];
} Inventory;
Inventory inv;

void catch_with_bottle(Item item_caught) {
  buttons[last_used_button] = item_caught; /* Update button */
  *(inv.items + buttons[last_used_button + 3]) = item_caught; /* Update inventory */
}

void dump_out_bottle() {
  Item updated_bottle;
  /* Check for milk */
  if (*(inv.items + buttons[last_used_button + 3]) == LON_LON_MILK){
    updated_bottle = LON_LON_MILK_HALF;
  } else {
    updated_bottle = EMPTY_BOTTLE;
  }

  buttons[last_used_button] = updated_bottle; /* Update button */
  *(inv.items + buttons[last_used_button + 3]) = updated_bottle; /* Update inventory */
}

int main() {

  buttons[C_RIGHT_BUTTON] = BOTTLED_FAIRY;
  inv.ammo[DEKU_STICK] = 10;

  printf("You have %d Deku Sticks.\n", inv.ammo[DEKU_STICK]);
  printf("Catching Fish on B...\n");
  last_used_button = B_BUTTON;
  catch_with_bottle(FISH);
  printf("You have %d Deku Sticks.\n", inv.ammo[DEKU_STICK]);
  printf("Dumping out B...\n");
  last_used_button = B_BUTTON;
  dump_out_bottle();
  printf("You have %d Deku Sticks.\n", inv.ammo[DEKU_STICK]);
  return 0;
}