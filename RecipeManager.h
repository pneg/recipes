#pragma once
#include "Ingredient.h"
#include "Recipe.h"
#include <vector>

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
  std::shared_ptr<Recipe> findRecipe(const std::string &recipeForm);
  Ingredient newIngredient(const std::shared_ptr<Recipe> &recipe,
                           const std::vector<Ingredient> &params);
};
