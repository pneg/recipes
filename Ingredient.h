#pragma once
#include <vector>
#include <memory>
#include <string>

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

class Recipe;

// An ingredient is an instance of a recipe realized with specific inputs (other
// ingredients)

class Ingredient {
private:
  std::shared_ptr<Recipe> recipe;
  ECookingMethod cookingMethod;
  EAttribute attributes;
  std::vector<Ingredient> inputs;
  std::string name;

public:
  Ingredient(std::shared_ptr<Recipe> r); // no parameter constructor
  Ingredient(std::shared_ptr<Recipe> r, const std::vector<Ingredient> &args);

  std::string getName() const;
  std::shared_ptr<Recipe> getRecipe() const;
  ECookingMethod getCookingMethod() const;
  EAttribute getAttributes() const;
};
