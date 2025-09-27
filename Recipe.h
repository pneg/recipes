#include <string>
#include <unordered_set>
#include <memory>

class Recipe {
private:
  std::string format;
  std::unordered_set<std::shared_ptr<Recipe>> children;
  std::shared_ptr<Recipe> parent;

public:
  Recipe(const std::string &form, std::shared_ptr<Recipe> p);

  std::string getFormat();

  Recipe addChild(std::string form);

  Recipe findChild(std::string form);
};