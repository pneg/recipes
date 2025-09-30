#pragma once
#include "Recipe.h"
#include <vector>
#include <memory>
#include <string>

class Ingredient;

// The recipe manager is a tree indicating a hierarchial structure of categories
// of food. Each recipe can have one parent recipe and unlimited children
// recipes.

class RecipeManager {
private:
  Recipe items;

public:
  std::shared_ptr<Recipe> addRecipe(const std::string &recipeForm);

  std::shared_ptr<Recipe> addRecipe(const std::string &recipeForm,
                                    const std::shared_ptr<Recipe> &parent);
  std::shared_ptr<Recipe> findRecipe(const std::string &recipeForm) const;
  Ingredient newIngredient(const std::shared_ptr<Recipe> &recipe,
                           const std::vector<Ingredient> &params) const;
};
