#include <vector>
#include "Recipe.h"
#include "Ingredient.h"

// The recipe manager is a tree indicating a hierarchial structure of categories of food.
// Each recipe can have one parent recipe and unlimited children recipes.

class RecipeManager {
private:
  Recipe items;

public:
  std::shared_ptr<Recipe> addItem(const std::string& itemName);

  std::shared_ptr<Recipe> addItem(const std::string& itemName, const std::shared_ptr<Recipe> &parent);

  Ingredient newItem(const std::shared_ptr<Recipe> &recipe, const std::vector<Ingredient>& params);
};
