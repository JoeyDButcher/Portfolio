
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void ballMovement(float dt);
  void livesUpdate();
  void gameReset();

 private:
  sf::RenderWindow& window;

  sf::Font main_font;
  sf::Font special_font;
  sf::Font secret_font;
  sf::Text credit;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite secret;
  sf::Texture secret_texture;
  sf::Text lives_display;
  sf::Text score_display;



  bool in_menu;
  sf::Text top_title_text;
  sf::Text play_option;
  sf::Text quit_option;
  bool play_selected = true;

  bool game_over = false;
  sf::Text game_over_text;
  sf::Text return_option;
  sf::Text exit_option;
  bool return_selected = true;

  bool victory = false;
  sf::Text victory_text;

  bool curious = false;
  sf::Text whats_this;

  int brick_count = sizeof(blocks)/4;
  int score = 0;
  int lives = 3;
  float rand_gem_x;
  int gem_cd = 2000;

  bool run_once = false;


  GameObject* paddle;
  GameObject* ball;
  GameObject* blocks[17][4];
  GameObject* gem;
};

#endif // BREAKOUT_GAME_H
