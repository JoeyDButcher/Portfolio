#include <iostream>
#include "GameObject.h"

GameObject::GameObject()
{
  // constructor go brrrrr
}

GameObject::~GameObject()
{
  // destructor go brrrrr
}

// make sprite be textured
bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if(!texture.loadFromFile(filename))
  {
    std::cout << "TEXTURE NOT LOAD \n";
  }

  sprite = new sf::Sprite();
  sprite->setTexture(texture);
  return true;
}

// sprite thing
sf::Sprite* GameObject::getSprite()
{
  return sprite;
}
