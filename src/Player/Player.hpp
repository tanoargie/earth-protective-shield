#ifndef Player_hpp
#define Player_hpp

#include "../Entity/Entity.hpp"
#include <vector>

class Player : public Entity {
public:
  Player();
  void setHealth(int h) { health = h; }
  void setMaxHealth(int h) { maxHealth = h; }
  int getHealth() const { return health; }
  int getMaxHealth() const { return maxHealth; }

private:
  int health, maxHealth;
};
#endif
