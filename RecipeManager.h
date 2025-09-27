class RecipeManager {
private:
  Recipe items;

  Recipe& findRecipe(std::string recipeName, Recipe &r) {
    r = r->children.find(recipeName);
  }

  void addItem(std::string itemName, Recipe &parent, Recipe &r) {
    if (r.getFormat() == parent) {
      r.addChild(itemName);
      return;
    }
    addItem(itemName, parent, r->children)
  }

public:
  void addItem(std::string itemName) { items.addChild(itemName); }
  void addItem(std::string itemName, Recipe &parent) {
    parent.addChild(itemName);
  }
  ItemType newItem();
};
