
#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();

  sf::Texture player_ship_texture;
  sf::Texture enemy_ship_texture;
  sf::Texture laser_texture;

  bool visibility = true;
  float speed = 300.f;
  Vector2 direction {0,0};


 private:
  sf::Sprite* sprite = nullptr;
};


#endif // SPACEINVADERS_GAMEOBJECT_H
