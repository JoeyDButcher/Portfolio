
#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"
#include <cmath>

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
  void enemyMovement(float dt);
  void laserStuff(sf::Event event);
  void laserMovement(float dt);
  void winOrLoss();
  void scoreUpdate();

 private:
  sf::RenderWindow& window;

  //fonts
  sf::Font main_font;
  sf::Font secondary_font;

  //text
  // menu stuff
  sf::Text credit;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text quit_option;
  //game over stuff
  sf::Text game_over_title;
  sf::Text return_option;
  sf::Text exit_option;
  // victory screen stuff
  sf::Text victory_title;
  sf::Text victory_return;
  sf::Text victory_exit;
  // options menu stuff
  sf::Text option_title;
  sf::Text normal_option;
  sf::Text gravity_option;
  sf::Text quadratic_option;
  sf::Text sine_option;

  // score
  int score = 0;
  sf::Text score_display;

  //background sprite
  sf::Sprite background;
  sf::Texture background_texture;

  // other sprites
  GameObject* player_ship;
  GameObject* enemy_ship[9][3];
  GameObject* laser[4];


  //bools
  bool in_menu = true;
  bool game_over = false;
  bool victory = false;
  bool play_selected = true;
  bool go_return_selected = true;
  bool v_return_selected = true;
  bool first_run = false;
  bool option_menu = false;
  bool normal_selected = true;
  bool gravity_selected = false;
  bool quadratic_selected = false;
  bool sine_selected = false;


  // number variables
  int enemy_direction;
  int current_shot = 0;
  int option_choice = 1;
  int enemy_count = sizeof(enemy_ship)/4;
  float gravity = 1;
  float quad_x = 0.0001*pow(1080, 2);
  //float sine_x = 100*sin(0.01*1080);
  int temp_move = 0.f;
  int mode_chosen;

};

#endif // SPACEINVADERS_GAME_H
