#include "Recipe.h"
#include "Ingredient.h"
#include "RecipeManager.h"
#include <utility>

Recipe::Recipe(const std::string &form, std::shared_ptr<Recipe> p) {
  format = form;
  parent = p;
}
void Recipe::initializeParams(const RecipeManager &filledRecipeManager) {
  int paramNum = 0;
  std::vector<std::string> paramStrings;
  std::vector<std::pair<int, int>> paramStringIndices;
  for (int i = 2; i < format.size(); i++) {
    if (format[i - 2] == '$' && format[i] == '{' &&
        (format[i - 1] == 'r' || format[i - 1] == 'i')) {
      int bracketCount = 1;
      int j;
      for (j = i + 1; j < format.size() && bracketCount > 0; j++) {
        if (format[j] == '{')
          bracketCount++;
        if (format[j] == '}')
          bracketCount--;
      }
      if (bracketCount == 0)
        paramStrings[paramNum++] = format.substr(i, j - i);
      i = j;
    }
  }
  for (int i = 0; i < paramStrings.size(); i++) {
    std::string content = paramStrings[i].substr(3);
    if (paramStrings[i][1] == 'r')
      params[i] = filledRecipeManager.findRecipe(content);
    else if (paramStrings[i][1] == 'i')
      params[i] = content;
  }
  createInverseSubstringVector(paramStringIndices, surroundings);
}

void Recipe::createInverseSubstringVector(
    std::vector<std::pair<int, int>> paramStringIndices,
    std::vector<std::string> out) {
  int i = 0;
  for (std::pair<int, int> pair : paramStringIndices) {
    auto [a, b] = pair;
    out.push_back(format.substr(i, i - a));
    i = b;
  }
  out.push_back(format.substr(i));
}

std::string Recipe::getFormat() const { return format; }

std::shared_ptr<Recipe> Recipe::addChild(std::string form) {
  std::shared_ptr<Recipe> recipe(
      new Recipe(form, std::shared_ptr<Recipe>(this)));
  children.insert(recipe);
  return recipe;
}

std::shared_ptr<Recipe> Recipe::findDescendant(std::string form) const {
  for (std::shared_ptr<Recipe> child : children) {
    std::string childForm = child->getFormat();
    if (childForm == form)
      return child;
  }
  for (std::shared_ptr<Recipe> child : children) {
    std::shared_ptr<Recipe> descendant = child->findDescendant(form);
    if (descendant != nullptr)
      return descendant;
  }
  return nullptr;
}

bool Recipe::validateArgs(const std::vector<Ingredient> &args) const {
  if (params.size() != args.size())
    return false;
  int i = 0;
  for (auto param : params) {
    if (std::holds_alternative<std::string>(param)) {
      if (std::get<std::string>(param) != args[i].getName())
        return false;
    } else if (std::holds_alternative<std::shared_ptr<Recipe>>(param)) {
      if (std::get<std::shared_ptr<Recipe>>(param) != args[i].getRecipe())
        return false;
    }
    i++;
  }
  return true;
}

std::string Recipe::substituteArgs(const std::vector<Ingredient> &args) const {
  std::string name = "";
  for (int i = 0; i < surroundings.size() - 1; i++) {
    name+=surroundings[i];
    name+=args[i].getName();
  }
  name+=surroundings.back();
}