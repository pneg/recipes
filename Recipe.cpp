#include "Recipe.h"
#include "Ingredient.h"
#include <memory>
#include <string>
#include <vector>

Recipe::Recipe(const std::string &form, std::shared_ptr<Recipe> p) {
  format = form;
  parent = p;
}

std::string Recipe::getFormat() { return format; }

std::shared_ptr<Recipe> Recipe::addChild(std::string form) {
  std::shared_ptr<Recipe> recipe(
      new Recipe(form, std::shared_ptr<Recipe>(this)));
  children.insert(recipe);
  return recipe;
}

bool Recipe::validateArgs(const std::vector<Ingredient> &args) const {
  // TODO: Implement parameter validation logic
  return true;
}