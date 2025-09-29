#include "RecipeManager.h"

std::shared_ptr<Recipe>
RecipeManager::addItem(const std::string &ingredientName) {
  return items.addChild(ingredientName);
}

std::shared_ptr<Recipe>
RecipeManager::addItem(const std::string &ingredientName,
                       const std::shared_ptr<Recipe> &parent) {
  return parent->addChild(ingredientName);
}