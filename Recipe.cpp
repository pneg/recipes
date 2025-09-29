#include "Recipe.h"

Recipe::Recipe(const std::string &form, std::shared_ptr<Recipe> p) {
  format = form;
  parent = p;
}
void Recipe::initializeParams(const RecipeManager &filledRecipeManager) {
  int paramNum = 0;
  std::vector<std::string> paramStrings;
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
}

std::string Recipe::getFormat() { return format; }

std::shared_ptr<Recipe> Recipe::addChild(std::string form) {
  std::shared_ptr<Recipe> recipe(
      new Recipe(form, std::shared_ptr<Recipe>(this)));
  children.insert(recipe);
  return recipe;
}

std::shared_ptr<Recipe> Recipe::findDescendant(std::string form) {
  for (std::shared_ptr<Recipe> child : children) {
    std::string childForm = child->getFormat();
    if (childForm == form)
      return child;
  }
  for (std::shared_ptr<Recipe> child : children) {
    std::shared_ptr<Recipe> descendant = child->findDescendant(form);
    if (descendant != null)
      return descendant;
  }
  return null;
}

bool Recipe::validateArgs(const std::vector<Ingredient> &args) const {
  return false;
}