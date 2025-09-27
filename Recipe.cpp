#include "Recipe.h"

Recipe::Recipe(const std::string &form, std::shared_ptr<Recipe> p) {
  format = form;
  parent = p;
}

std::string Recipe::getFormat() { return format; }

Recipe Recipe::addChild(std::string form) {
  std::shared_ptr<Recipe> recipe(
      new Recipe(form, std::shared_ptr<Recipe>(this)));
  children.insert(recipe);
  return *recipe;
}