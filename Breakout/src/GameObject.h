
#ifndef BREAKOUT_GAMEOBJECT_H
#define BREAKOUT_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Vector2.h"


class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();


  bool visibility = true;
  float speed = 300.f;
  Vector2 direction {0,0};


  sf::Texture ball_texture;
  sf::Texture paddle_texture;
  sf::Texture block_texture;
  sf::Texture gem_texture;

 private:
  sf::Sprite* sprite = nullptr;
};


#endif // BREAKOUT_GAMEOBJECT_H
