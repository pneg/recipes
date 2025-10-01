#include "RecipeManager.h"

using RecipePointer = std::shared_ptr<Recipe>;

void initializeRecipeManager(const RecipeManager &recipeManager);

int main() {
  Recipe root("Food", nullptr);
  RecipeManager recipeManager(root);

  // initialization
  RecipePointer cheese = recipeManager.addRecipe("Cheese");
  RecipePointer cheddar = recipeManager.addRecipe("Cheddar Cheese", cheese);
  RecipePointer swiss = recipeManager.addRecipe("Swiss Cheese", cheese);
  RecipePointer pasta = recipeManager.addRecipe("Pasta");
  RecipePointer spaghetti = recipeManager.addRecipe("Spaghetti");
  RecipePointer macaroni = recipeManager.addRecipe("Macaroni");
  RecipePointer macAndCheese = recipeManager.addRecipe("$r{Macaroni} & $r{Cheese}");
}