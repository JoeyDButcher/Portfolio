
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{

  // Setting background texture
  if(!background_texture.loadFromFile("Data/Images/pong_outrun_background.png"))
  {
    std::cout << "background texture didn't load \n";
  }
  background.setTexture(background_texture);

  // Setting ball texture
  if(!ball_texture.loadFromFile("Data/Images/ball.png"))
  {
    std::cout << "ball texture didn't load \n";
  }
  ball.setTexture(ball_texture);

  ball.setPosition(520,300);
  ball.setScale(0.3,0.3);

  // Setting Player 1 paddle texture
  if(!pinkPaddle_texture.loadFromFile("Data/Images/PinkBat.png"))
  {
    std::cout << "pink bat texture didn't load \n";
  }
  pinkPaddle.setTexture(pinkPaddle_texture);

  pinkPaddle.setPosition(990, 270);
  pinkPaddle.setScale(0.3,0.3);

  // setting player 2 paddle texture
  if(!bluePaddle_texture.loadFromFile("Data/Images/BlueBat.png"))
  {
    std::cout << "blue bat texture didn't load \n";
  }
  bluePaddle.setTexture(bluePaddle_texture);

  bluePaddle.setPosition(30, 270);
  bluePaddle.setScale(0.3,0.3);

  if(!left_goal_texture.loadFromFile("Data/Images/left_goal.png"))
  {
    std::cout << "the left goal's texture didn't work \n";
  }
  left_goal.setTexture(left_goal_texture);

  left_goal.setPosition(-50,0);

  if(!right_goal_texture.loadFromFile("Data/Images/right_goal.png"))
  {
    std::cout << "the right goal's texture didn't work \n";
  }
  right_goal.setTexture(right_goal_texture);

  right_goal.setPosition(1050,0);

  //setting main font
  if(!main_font.loadFromFile("Data/Fonts/thunderstrike.ttf"))
  {
    std::cout << "the main font didn't load \n";
  }

  //setting the "special" font
  if(!special_font.loadFromFile("Data/Fonts/thunderstrike3d.ttf"))
  {
    std::cout << "3d font didn't load \n";
  }


  //things for the title

  //first half of title
  top_title_text.setString("Pong:");
  top_title_text.setFont(main_font);
  top_title_text.setCharacterSize(80);
  top_title_text.setFillColor(sf::Color(45, 226, 230));
  top_title_text.setOutlineColor(sf::Color(2, 55, 136));
  top_title_text.setOutlineThickness(5);

  //second half of title
  bottom_title_text.setString("Outrun");
  bottom_title_text.setFont(special_font);
  bottom_title_text.setCharacterSize(90);
  bottom_title_text.setFillColor(sf::Color(246, 1, 157));
  bottom_title_text.setOutlineColor(sf::Color(246, 1, 157));
  bottom_title_text.setOutlineThickness(2);

  // the play button
  play_option.setFont(main_font);
  play_option.setString("> Play");
  play_option.setCharacterSize(50);
  play_option.setFillColor(sf::Color(249,200,14));
  play_option.setOutlineColor(sf::Color(255, 108, 17));
  play_option.setOutlineThickness(3);

  //the quit option
  quit_option.setFont(main_font);
  quit_option.setString("Quit");
  quit_option.setCharacterSize(50);
  quit_option.setFillColor(sf::Color(249,200,14));
  quit_option.setOutlineColor(sf::Color(255, 108, 17));
  quit_option.setOutlineThickness(3);

  // STUFF FOR INGAME PAUSE MENU
  // menu title text
  pause_menu_text.setFont(main_font);
  pause_menu_text.setString("PAUSED");
  pause_menu_text.setCharacterSize(90);
  pause_menu_text.setFillColor(sf::Color(45, 226, 230));
  pause_menu_text.setOutlineColor(sf::Color(2, 55, 136));
  pause_menu_text.setOutlineThickness(3);

  //text asking if user wants to return to menu
  menu_return.setFont(special_font);
  menu_return.setString("Return to Menu?");
  menu_return.setCharacterSize(70);
  menu_return.setFillColor(sf::Color(255, 67, 101));
  menu_return.setOutlineColor(sf::Color(255, 67, 101));
  menu_return.setOutlineThickness(3);

  // text for the yes option
  yes_option.setFont(main_font);
  yes_option.setString("> Yes");
  yes_option.setCharacterSize(50);
  yes_option.setFillColor(sf::Color(249,200,14));
  yes_option.setOutlineColor(sf::Color(255, 108, 17));
  yes_option.setOutlineThickness(3);

  //text for no option
  no_option.setFont(main_font);
  no_option.setString("No");
  no_option.setCharacterSize(50);
  no_option.setFillColor(sf::Color(249,200,14));
  no_option.setOutlineColor(sf::Color(255, 108, 17));
  no_option.setOutlineThickness(3);


  // crediting myself
  credit.setFont(main_font);
  credit.setString("Credits: \n"
                   "Art: Joey Butcher \n"
                   "Code: Joey Butcher \n");
  credit.setCharacterSize(15);
  credit.setFillColor(sf::Color(101,13,137));
  credit.setOutlineColor(sf::Color(38,20,71));
  credit.setOutlineThickness(3);

  // scores
  // both for player 1 and player 2
  player_1_score.setFont(special_font);
  player_2_score.setFont(special_font);
  player_1_score.setCharacterSize(200);
  player_2_score.setCharacterSize(200);
  player_1_score.setFillColor(sf::Color(2, 55, 136));
  player_1_score.setOutlineColor(sf::Color(2, 55, 136));
  player_1_score.setOutlineThickness(3);
  player_2_score.setFillColor(sf::Color(246, 1, 157));
  player_2_score.setOutlineColor(sf::Color(246, 1, 157));
  player_2_score.setOutlineThickness(3);

  // menu stuff
  in_menu = true;
  top_title_text.setPosition(320, 35);
  bottom_title_text.setPosition(330, 105);
  play_option.setPosition(400,280);
  quit_option.setPosition(400, 370);
  credit.setPosition(880, 620);

  // in game text
  player_1_score.setPosition(200, 200);
  player_2_score.setPosition(650, 200);

  //pause menu text
  pause_menu_text.setPosition(270, 35);
  menu_return.setPosition(160, 180);
  yes_option.setPosition(400,280);
  no_option.setPosition(400, 370);

  return true;
}

void Game::update(float dt)
{
  if(in_menu or in_pause)
  {
    ball.move(0,0);
  }
  else
  {
    if (
      (ball.getPosition().x >=
       (window.getSize().x - ball.getGlobalBounds().width)) ||
      (ball.getPosition().x <= 0))
    {
      reverse_x = !reverse_x;
    }
    else if (
      ball.getPosition().y >=
        (window.getSize().y - ball.getGlobalBounds().height) ||
      (ball.getPosition().y <= 0))
    {
      reverse_y = !reverse_y;
    }

    if (reverse_x)
    {
      ball.move(1.0f * speed * dt, 0);
    }
    else if (!reverse_x)
    {
      ball.move(-1.0f * speed * dt, 0);
    }

    if (reverse_y)
    {
      ball.move(0, 1.0f * speed * dt);
    }
    else if (!reverse_y)
    {
      ball.move(0, -1.0f * speed * dt);
    }

    // set bounding boxes for the paddles
    sf::FloatRect pinkPaddleBox = pinkPaddle.getGlobalBounds();
    sf::FloatRect bluePaddleBox = bluePaddle.getGlobalBounds();

    // collision detection for the paddles
    if (
      ball.getGlobalBounds().intersects(pinkPaddleBox) or
      ball.getGlobalBounds().intersects(bluePaddleBox))
    {
      reverse_x = !reverse_x;
    }

    if (
      ball.getGlobalBounds().intersects(pinkPaddleBox) or
      ball.getGlobalBounds().intersects(bluePaddleBox))
    {
      reverse_y = !reverse_y;
    }

    // stop the paddles going offscreen
    if (
      pinkPaddle.getPosition().y >=
      (window.getSize().y - pinkPaddle.getGlobalBounds().height))
    {
      pinkPaddle.move(0, -1.0f * speed * dt);
    }
    else if (pinkPaddle.getPosition().y <= 0)
    {
      pinkPaddle.move(0, 1.0f * speed * dt);
    }

    // stop the blue paddle going offscreen
    if (
      bluePaddle.getPosition().y >=
      (window.getSize().y - bluePaddle.getGlobalBounds().height))
    {
      bluePaddle.move(0, -1.0f * speed * dt);
    }
    else if (bluePaddle.getPosition().y <= 0)
    {
      bluePaddle.move(0, 1.0f * speed * dt);
    }
  }
}

void Game::render()
{
  if(in_menu)
  {
    window.draw(background);
    window.draw(top_title_text);
    window.draw(bottom_title_text);
    window.draw(play_option);
    window.draw(quit_option);
    window.draw(credit);
  }
  else
  {
    window.draw(background);
    window.draw(pinkPaddle);
    window.draw(bluePaddle);
    window.draw(player_1_score);
    window.draw(player_2_score);
    window.draw(ball);
    window.draw(left_goal);
    window.draw(right_goal);
  }

  if(in_pause)
  {
    window.draw(background);
    window.draw(pause_menu_text);
    window.draw(menu_return);
    window.draw(yes_option);
    window.draw(no_option);
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
  if (in_menu)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      play_selected = !play_selected;
      if (play_selected)
      {
        play_option.setString("> Play");
        quit_option.setString("Quit");
      }
      else
      {
        play_option.setString("Play");
        quit_option.setString("> Quit");
      }
    }
    else if(event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        in_menu = false;
      }
      else
      {
        window.close();
      }
    }
  }
}

//pause menu stuff
void Game::pauseKeyPressed(sf::Event event)
{
  if(!in_menu and event.key.code == sf::Keyboard::Escape)
  {
    in_pause = true;
  }

  if(in_pause)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      yes_selected = !yes_selected;
      if (yes_selected)
      {
        yes_option.setString("> Yes");
        no_option.setString("No");
      }
      else
      {
        yes_option.setString("Yes");
        no_option.setString("> No");
      }
    }
    else if(event.key.code == sf::Keyboard::Enter)
    {
      if(yes_selected)
      {
        in_menu = true;
        in_pause = false;
      }
      else
      {
        in_pause = false;
      }
    }
  }
}

// movement code for the pink paddle
void Game::player1Movement(sf::Event event, float dt)
{
  // check if the up or down arrow key is pressed
  if (event.type == sf::Event::KeyPressed)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
      pinkPaddle.move(0, -10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
      pinkPaddle.move(0, 10);
    }

  }
  // check if they're released
  else if (event.type == sf::Event::KeyReleased)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      pinkPaddle.move(0, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      pinkPaddle.move(0, 0);
    }

  }
}

// moving the blue paddle
void Game::player2Movement(sf::Event event, float dt)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      bluePaddle.move(0, -10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      bluePaddle.move(0,10);
    }
  }
  else if (event.type == sf::Event::KeyReleased)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      bluePaddle.move(0, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      bluePaddle.move(0,0);
    }
  }
}

void Game::scoreUpdate(float dt)
{
  sf::FloatRect left_bounding_box = left_goal.getGlobalBounds();
  sf::FloatRect right_bounding_box = right_goal.getGlobalBounds();

  if(ball.getGlobalBounds().intersects(left_bounding_box))
  {
    ball.setPosition(540,270);
    p2_score_value += 1;
  }
  if(ball.getGlobalBounds().intersects(right_bounding_box))
  {
    ball.setPosition(540, 270);
    p1_score_value += 1;
  }

  std::string p1_score_output = std::to_string(p1_score_value);
  std::string p2_score_output = std::to_string(p2_score_value);
  player_1_score.setString(p1_score_output);
  player_2_score.setString(p2_score_output);
}