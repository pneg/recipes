#ifndef RECIPE_H
#define RECIPE_H

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

// Forward declaration to avoid circular dependency
class Ingredient;

// Recipes, or recipe classes, are functions that take ingredients as parameters
// and return ingredients As an analogy to object-oriented programming, think
// recipes are classes and ingredients are instances.

// Recipes are represented by a format string where substrings of the format
// "${[<recipe>/<ingredient>]}," with <recipe> or <ingredient> being an optional
// restriction on the recipe class or ingredient name of the ingredient
// parameter. Ex: The recipe format "${} and ${Cheese}" with the parameters
// "Macaroni" and "Cheese" would create the item "Macaroni and Cheese." The
// second parameter must either be of the recipe class "Cheese" or one of its
// descendants

// Recipes with no parameters create base ingredients
// Ex: Recipes with the format "Cheese" and "Macaroni"

class Recipe {
private:
  std::string format;
  std::unordered_set<std::shared_ptr<Recipe>> children;
  std::shared_ptr<Recipe> parent;

public:
  Recipe(const std::string &form, std::shared_ptr<Recipe> p);

  std::string getFormat();

  std::shared_ptr<Recipe> addChild(std::string form);

  Recipe findChild(std::string form);

  bool validateArgs(const std::vector<Ingredient> &args) const;
};

#endif // RECIPE_H