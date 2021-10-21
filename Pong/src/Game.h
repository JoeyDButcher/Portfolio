
#ifndef PONG_GAME_H
#define PONG_GAME_H
#include <SFML/Graphics.hpp>

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
  void player1Movement(sf::Event event, float dt);
  void player2Movement(sf::Event event, float dt);
  void scoreUpdate(float dt);
  void pauseKeyPressed(sf::Event event);


 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite pinkPaddle;
  sf::Texture pinkPaddle_texture;
  sf::Sprite bluePaddle;
  sf::Texture bluePaddle_texture;
  sf::Font main_font;
  sf::Font special_font;
  sf::Sprite right_goal;
  sf::Texture right_goal_texture;
  sf::Sprite left_goal;
  sf::Texture left_goal_texture;

  sf::Text credit;
  sf::Text player_1_score;
  sf::Text player_2_score;

  bool in_menu;
  sf::Text top_title_text;
  sf::Text bottom_title_text;
  sf::Text play_option;
  sf::Text quit_option;
  bool play_selected = true;
  bool in_pause = false;
  sf::Text pause_menu_text;
  sf::Text menu_return;
  sf::Text yes_option;
  sf::Text no_option;
  bool yes_selected = true;


  bool reverse_x = false;
  bool reverse_y = false;
  float speed = 200;
  int p1_score_value = 0;
  int p2_score_value = 0;

};

#endif // PONG_GAME_H
