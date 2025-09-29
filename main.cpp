#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

enum ECookingMethod : char {
  Uncooked,
  Burnt,
  Seared,
  Baked,
  Roasted,
  Boiled,
  Grilled,
  Smoked,
  Fried,
  Pickled
};

enum EAttribute : char { None = 0, Cut = 1, Dried = 2, Shredded = 4 };

int main() {
  ItemType item1 = ItemType("Swiss Cheese");
  ItemType item2 = ItemType("Macaroni");
  ItemType.merge(recipe1, item1, item2);
}