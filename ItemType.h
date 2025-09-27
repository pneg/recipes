

class ItemType {
private:
  Recipe *recipe;
  ECookingMethod cookingMethod;
  EAttribute attributes;

public:
  ItemType(Recipe *r) {
    recipe = r;
    cookingMethod = Uncooked;
    attributes = None;
  }

  std::string getName() const { return recipe->getFormat(); }
  ECookingMethod getCookingMethod() const { return cookingMethod; }
  EAttribute getAttributes() const { return attributes; }
};
