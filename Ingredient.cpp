#include "Ingredient.h"
#include "Recipe.h"

Ingredient::Ingredient(std::shared_ptr<Recipe> r) {
  recipe = r;
  cookingMethod = Uncooked;
  attributes = None;
}

Ingredient::Ingredient(std::shared_ptr<Recipe> r,
                       const std::vector<Ingredient> &args) {
  recipe = r;
  cookingMethod = Uncooked;
  attributes = None;
  r->validateArgs(args);
  inputs = args;
}

std::string Ingredient::getName() const { return recipe->getFormat(); }
ECookingMethod Ingredient::getCookingMethod() const { return cookingMethod; }
EAttribute Ingredient::getAttributes() const { return attributes; }