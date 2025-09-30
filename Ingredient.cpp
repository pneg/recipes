#include "Ingredient.h"
#include "Recipe.h"
#include <stdexcept>

Ingredient::Ingredient(std::shared_ptr<Recipe> r) {
  recipe = r;
  cookingMethod = Uncooked;
  attributes = None;
  name = r->getFormat();
}

Ingredient::Ingredient(std::shared_ptr<Recipe> r,
                       const std::vector<Ingredient> &args) {
  recipe = r;
  cookingMethod = Uncooked;
  attributes = None;
  if (!r->validateArgs(args))
    throw std::invalid_argument("recipe args are invalid");
  name = r->substituteArgs(args);
  inputs = args;
}

std::string Ingredient::getName() const { return name; }
std::shared_ptr<Recipe> Ingredient::getRecipe() const { return recipe; }
ECookingMethod Ingredient::getCookingMethod() const { return cookingMethod; }
EAttribute Ingredient::getAttributes() const { return attributes; }