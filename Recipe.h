#pragma once
#include <memory>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>

class RecipeManager;
class Ingredient;

// Recipes, or recipe classes, are functions that take ingredients as parameters
// and return ingredients As an analogy to object-oriented programming, think
// recipes are classes and ingredients are instances.

// Recipes are represented by a format string where substrings of the format
// "$r{<recipe>}" or "$i{<ingredient name>}" with <recipe> or <ingredient name>
// being an optional restriction on the recipe class or ingredient name of the
// ingredient parameter. Ex: The recipe format "$r{Macaroni} and $r{Cheese}"
// with the parameters "Macaroni" and "Cheese" would create the item "Macaroni
// and Cheese." The second parameter must either be of the recipe class "Cheese"
// or one of its descendants

// Recipes with no parameters create base ingredients
// Ex: Recipes with the format "Cheese" and "Macaroni"

class Recipe {
private:
  std::string format;
  std::unordered_set<std::shared_ptr<Recipe>> children;
  std::shared_ptr<Recipe> parent;
  std::vector<std::variant<std::string, std::shared_ptr<Recipe>>> params;
  std::vector<std::string> surroundings; // everything that isn't a parameter

  void createInverseSubstringVector(std::vector<std::pair<int, int>>,
                                    std::vector<std::string> out);

public:
  Recipe(const std::string &form, std::shared_ptr<Recipe> p);
  // should only be run by RecipeManager
  void initializeParams(const RecipeManager &filledRecipeManager);

  std::string getFormat() const;

  std::shared_ptr<Recipe> addChild(std::string form);

  std::shared_ptr<Recipe> findDescendant(std::string form) const;

  bool validateArgs(const std::vector<Ingredient> &args) const;

  std::string substituteArgs(const std::vector<Ingredient> &args) const;
};