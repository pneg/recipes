#include "RecipeManager.h"

std::shared_ptr<Recipe>
RecipeManager::addRecipe(const std::string &recipeForm) {
  return items.addChild(recipeForm);
}

std::shared_ptr<Recipe>
RecipeManager::addRecipe(const std::string &recipeForm,
                       const std::shared_ptr<Recipe> &parent) {
  return parent->addChild(recipeForm);
}

std::shared_ptr<Recipe> RecipeManager::findRecipe(const std::string &recipeForm) const {
  items.findDescendant(recipeForm);
}