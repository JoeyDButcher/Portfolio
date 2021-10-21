
#include "Game.h"
#include <iostream>
#include <chrono>
#include <random>

// i might need to learn how to make code not so agonisingly long
// ill practice more classes outside of assignments, i am too committed to this
// mess of functions to re-code at this point

// on a side note, some of the comments in here demonstrate my rapidly dwindling sanity
// i apologise in advance


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
  // destructor be like
}

bool Game::init()
{
  //texture things i guess
  if(!background_texture.loadFromFile("Data/Images/breakout-background-good.png"))
  {
    std::cout << "background texture didn't load \n";
  }
  background.setTexture(background_texture);

  //don't worry about this texture
  if(!secret_texture.loadFromFile("Data/Images/dont-worry.png"))
  {
    std::cout << "the secret didn't work \n"
                 "shh don't tell anyone though \n";
  }
  secret.setTexture(secret_texture);


  // gem texture

  // random x generator
  rand_gem_x = std::rand() % 1038 + 48;


  gem = new GameObject();

  gem->initialiseSprite(gem->gem_texture, "Data/Images/gem.png");
  gem->getSprite()->setPosition(rand_gem_x, -48);


  //paddle
  paddle = new GameObject();
  paddle->initialiseSprite(paddle->paddle_texture,"Data/Images/paddle-1.png");
  paddle->getSprite()->setPosition(window.getSize().x/2-52,680);

  //ball
  ball = new GameObject();
  ball->initialiseSprite(ball->ball_texture, "Data/Images/small ball.png");
  ball->getSprite()->setPosition(window.getSize().x/2-11,600);

  //block
  for (int x = 0; x < 17; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      blocks[x][y] = new GameObject();

      // render loads of blocks easily
      switch (y)
      {
        case 0:
          blocks[x][y]->initialiseSprite(blocks[x][y]->block_texture, "Data/Images/brick.png");
          break;
        case 1:
          blocks[x][y]->initialiseSprite(blocks[x][y]->block_texture, "Data/Images/brick2.png");
          break;
        case 2:
          blocks[x][y]->initialiseSprite(blocks[x][y]->block_texture, "Data/Images/brick3.png");
          break;
        case 3:
          blocks[x][y]->initialiseSprite(blocks[x][y]->block_texture, "Data/Images/brick4.png");
          break;
        default:
          break;
      }
      // set positions for the sprites
      blocks[x][y]->getSprite()->setPosition( x * 63.5, 40 + y * 38);

      // previous attempt
      /*if (y == 2)
      {
        blocks[x][y]->initialiseSprite(blocks[x][y]->block_texture, "Data/Images/brick2.png");
      }
      else
      {
        blocks[x][y]->initialiseSprite(blocks[x][y]->block_texture, "Data/Images/brick.png");
      }
      blocks[x][y]->getSprite()->setPosition(x * 60, 40 + y * 38);*/
    }
  }


  //things for the title

  //setting main font
  if(!main_font.loadFromFile("Data/Fonts/Inversionz Unboxed.ttf"))
  {
    std::cout << "the main font didn't load \n";
  }

  //setting the "special" font
  if(!special_font.loadFromFile("Data/Fonts/Curved Square.ttf"))
  {
    std::cout << "3d font didn't load \n";
  }

  if(!secret_font.loadFromFile("Data/Fonts/Qdbettercomicsans-jEEeG.ttf"))
  {
           std::cout << "shh secret font didn't work \n";
  }

  //first half of title
  top_title_text.setString("spaceout");
  top_title_text.setFont(special_font);
  top_title_text.setCharacterSize(100);
  top_title_text.setFillColor(sf::Color(2,55,136));
  top_title_text.setOutlineColor(sf::Color(45,226,230));
  top_title_text.setOutlineThickness(5);

  // the play button
  play_option.setFont(main_font);
  play_option.setString(">Play<");
  play_option.setCharacterSize(70);
  play_option.setFillColor(sf::Color(45,226,230));
  play_option.setOutlineColor(sf::Color(2,55,136));
  play_option.setOutlineThickness(3);

  //the quit option
  quit_option.setFont(main_font);
  quit_option.setString("Quit");
  quit_option.setCharacterSize(70);
  quit_option.setFillColor(sf::Color(45,226,230));
  quit_option.setOutlineColor(sf::Color(2,55,136));
  quit_option.setOutlineThickness(3);

  // L I V E S
  lives_display.setFont(main_font);
  lives_display.setCharacterSize(75);
  lives_display.setFillColor(sf::Color(45,226,230));
  lives_display.setOutlineColor(sf::Color(2,55,136));
  lives_display.setOutlineThickness(3);
  lives_display.setPosition(0, 160);

  // tell the player how good they are
  score_display.setFont(main_font);
  score_display.setCharacterSize(75);
  score_display.setFillColor(sf::Color(45,226,230));
  score_display.setOutlineColor(sf::Color(2,55,136));
  score_display.setOutlineThickness(3);
  score_display.setPosition(0, 200);

  // credits
  credit.setFont(main_font);
  credit.setString("Credits: \n"
                   "Sprite Art: Joey  \n"
                   "Code: Joey  \n"
                   "Background Art: Khanecz on Imgur");
  credit.setCharacterSize(25);
  credit.setFillColor(sf::Color(45,226,230));
  credit.setOutlineColor(sf::Color(2,55,136));
  credit.setOutlineThickness(3);
  credit.setPosition(0,625);

  // menu stuff
  in_menu = true;
  top_title_text.setPosition(290, 35);
  play_option.setPosition(400,280);
  quit_option.setPosition(444, 370);


  // stuff for the game over screen
  game_over_text.setFont(special_font);
  game_over_text.setString("   GAME OVER   \n"
                                 "RETURN TO MENU?");
  game_over_text.setCharacterSize(75);
  game_over_text.setFillColor(sf::Color(2,55,136));
  game_over_text.setOutlineColor(sf::Color(45,226,230));
  game_over_text.setOutlineThickness(5);
  game_over_text.setPosition(200, 35);

  // go back to menu button
  return_option.setFont(main_font);
  return_option.setString(">Menu<");
  return_option.setCharacterSize(70);
  return_option.setFillColor(sf::Color(45,226,230));
  return_option.setOutlineColor(sf::Color(2,55,136));
  return_option.setOutlineThickness(3);
  return_option.setPosition(400,280);

  // exit game button
  exit_option.setFont(main_font);
  exit_option.setString("Exit");
  exit_option.setCharacterSize(70);
  exit_option.setFillColor(sf::Color(45,226,230));
  exit_option.setOutlineColor(sf::Color(2,55,136));
  exit_option.setOutlineThickness(3);
  exit_option.setPosition(444, 370);

  // stuff for victory screen


  // victory text
  victory_text.setFont(special_font);
  victory_text.setString("    victory    \n"
                               "return to menu?");
  victory_text.setCharacterSize(75);
  victory_text.setFillColor(sf::Color(2,55,136));
  victory_text.setOutlineColor(sf::Color(45,226,230));
  victory_text.setOutlineThickness(5);
  victory_text.setPosition(180, 25);

  // dont worry about this
  // it does nothing
  curious = false;
  whats_this.setFont(secret_font);
  whats_this.setString("oi oi wot's all dis then? \n"
                       "you shouldn't be 'ere! \n"
                       "go back to the menu! \n"
                       "(just press enter again) \n");
  whats_this.setCharacterSize(70);
  whats_this.setFillColor(sf::Color(0,0,0));
  whats_this.setOutlineColor(sf::Color(255,255,255));
  whats_this.setOutlineThickness(3);
  whats_this.setPosition(225, 370);


  return true;
}

void Game::update(float dt)
{
  // paddle move
  paddle->getSprite()->move(
    paddle->direction.x * paddle->speed * dt, paddle->direction.y * dt);

  // ball-paddle collision
  if (paddle->getSprite()->getGlobalBounds().intersects(
        ball->getSprite()->getGlobalBounds()))
  {
    // reverses the y, randomly assigns the x
    ball->direction.y *= -1.0f;
    ball->direction.x *= 1.0f;
  }

  // paddle/wall collision
  if (
    paddle->getSprite()->getPosition().x >=
      (window.getSize().x - paddle->getSprite()->getGlobalBounds().width) or
    paddle->getSprite()->getPosition().x <= 0)
  {
    paddle->direction.x *= -1.0f;
  }

  // other collisions

  // if it hits the top
  if (ball->getSprite()->getPosition().y <= 0)
  {
    // reverses y, tells x to maintain direction
    ball->direction.y *= -1.0f;
    ball->direction.x *= 1.0f;
  }
  else if (
    ball->getSprite()->getPosition().y >=
    (window.getSize().y - ball->getSprite()->getGlobalBounds().height))
  {
    lives -= 1;
    ball->getSprite()->setPosition(window.getSize().x / 2 - 11, 600);
    ball->direction.y *= -1.0f;
  }

  // if it hits one of the sides
  if (
    ball->getSprite()->getPosition().x >=
    (window.getSize().x - ball->getSprite()->getGlobalBounds().width))
  {
    ball->direction.x *= -1.0f;
  }
  // the other side
  else if (ball->getSprite()->getPosition().x <= 0)
  {
    ball->direction.x *= -1.0f;
  }

  // block collision
  for (int x = 0; x < 17; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      // the no longer ungodly block of if statements
      if (
        ball->getSprite()->getGlobalBounds().intersects(
          blocks[x][y]->getSprite()->getGlobalBounds()) &&
        blocks[x][y]->visibility)
      {
        // block go byebye, ball reverses
        ball->direction.y        = 1.0f;
        blocks[x][y]->visibility = false;
        brick_count -= 1;
        score += 1;
        std::cout << "bricks left: " << brick_count << std::endl;
      }
    }
  }

  // death
  if (lives == 0)
  {
    // send the player to hell
    game_over = true;
  }

  // not death
  if (brick_count == 0)
  {
    // send the player to heaven
    victory = true;
  }

  // STUFF FOR THE GEMS BELOW
  if(!in_menu and !game_over and !victory and !curious)
  {
    gem_cd -= 1 * dt;

    if (gem_cd == 0)
    {
      gem->getSprite()->move(0, 100.0f * dt);

      if (gem->getSprite()->getPosition().y > 720)
      {
        gem->getSprite()->move(0, 0);

        rand_gem_x = std::rand() % 1038 + 48;
        gem->getSprite()->setPosition(rand_gem_x, -48);

        gem_cd = 2000;
      }
    }
  }

  if (paddle->getSprite()->getGlobalBounds().intersects(gem->getSprite()->getGlobalBounds()))
  {
    score += score * 0.5;

    gem->getSprite()->move(0, 0);

    rand_gem_x = std::rand() % 1038 + 48;
    gem->getSprite()->setPosition(rand_gem_x, -48);

    gem_cd = 2000;
  }

}

void Game::render()
{
  // generic rendering stuff
  if(in_menu)
  {
    window.draw(background);
    window.draw(top_title_text);
    window.draw(play_option);
    window.draw(quit_option);
    window.draw(credit);
  }
  else if(game_over)
  {
    window.draw(background);
    window.draw(game_over_text);
    window.draw(return_option);
    window.draw(exit_option);
  }
  else if(curious)
  {
    window.draw(secret);
    window.draw(whats_this);
  }
  else if(victory)
  {
    window.draw(background);
    window.draw(victory_text);
    window.draw(return_option);
    window.draw(exit_option);
  }
  else
  {
    window.draw(background);
    window.draw(lives_display);
    window.draw(score_display);
    window.draw(*gem->getSprite());
    window.draw(*paddle->getSprite());
    window.draw(*ball->getSprite());

    // get the blocks to render
    for (int x = 0; x < 17; x++)
    {
      for(int y = 0; y < 4; y++)
      {
        if (blocks[x][y]->visibility)
        {
          window.draw(*blocks[x][y]->getSprite());
        }
      }
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
  // menu code
  // exactly the same as pong/whack a mole
  if (in_menu)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      play_selected = !play_selected;
      if (play_selected)
      {
        play_option.setString(">Play<");
        play_option.setPosition(400, 280);
        quit_option.setString("Quit");
        quit_option.setPosition(444, 370);
      }
      else
      {
        play_option.setString("Play");
        play_option.setPosition(444, 280);
        quit_option.setString(">Quit<");
        quit_option.setPosition(400, 370);
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
    else if(event.key.code == sf::Keyboard::LShift)
    {
      in_menu = false;
      curious = true;
    }
  }
  else if (game_over)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      return_selected = !return_selected;
      if (return_selected)
      {
        return_option.setString(">Menu<");
        return_option.setPosition(400, 280);
        exit_option.setString("Exit");
        exit_option.setPosition(444, 370);
      }
      else
      {
        return_option.setString("Menu");
        return_option.setPosition(444, 280);
        exit_option.setString(">Exit<");
        exit_option.setPosition(400, 370);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (return_selected)
      {
        game_over = false;
        in_menu = true;
      }
      else
      {
        window.close();
      }
    }
  }
  else if(victory)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      return_selected = !return_selected;
      if (return_selected)
      {
        return_option.setString(">Menu<");
        return_option.setPosition(400, 280);
        exit_option.setString("Exit");
        exit_option.setPosition(444, 370);
      }
      else
      {
        return_option.setString("Menu");
        return_option.setPosition(444, 280);
        exit_option.setString(">Exit<");
        exit_option.setPosition(400, 370);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (return_selected)
      {
        game_over = false;
        in_menu = true;
      }
      else
      {
        window.close();
      }
    }
  }
  else if(curious)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      curious = false;
      in_menu = true;
    }
  }

  //paddle movement
  //key pressed events
  if (event.key.code == sf::Keyboard::A)
  {
    paddle->direction.x = -1.f;
  }
  else if (event.key.code == sf::Keyboard::D)
  {
    paddle->direction.x = 1.f;
  }

}

// track when player releases keys
void Game::keyReleased(sf::Event event)
{
  // code just checks if A or D is released, and stops the paddles
  if (event.key.code == sf::Keyboard::A)
  {
    paddle->direction.x = -0.f;
  }
  else if (event.key.code == sf::Keyboard::D)
  {
    paddle->direction.x = 0.f;
  }
}



void Game::ballMovement(float dt)
{
  // get a random number, this just seems to work
  float ball_directions[2] = {1,-1};
  srand(time(nullptr));
  float ball_x = ball_directions[rand() % 2];

  // stop it moving if it's in the menu
  if (in_menu or victory or game_over or curious)
  {
    ball->getSprite()->move(0,0);
  }
  // otherwise collision time
  else
  {
    ball->speed = 200.f;

    // start off ball movement
    // send it into the paddle
    if (!run_once)
    {
      ball->direction.y = 1.0f;
      ball->direction.x = ball_x;
      run_once = true;
    }

    // constantly make the ball move
    ball->getSprite()->move(ball->direction.x * ball->speed * dt, ball->direction.y * ball->speed * dt);
  }
}


void Game::livesUpdate()
{
  std::string lives_string = std::to_string(lives);
  lives_display.setString("Lives: " + lives_string);

  std::string score_string = std::to_string(score);
  score_display.setString("Score: " + score_string + "pts.");
}


void Game::gameReset()
{
  // reset blocks after a game
  if(in_menu or victory or game_over)
  {
    for (int x = 0; x < 17; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        blocks[x][y]->visibility = true;
      }
    }

    // reset these two as well
    brick_count = sizeof(blocks)/4;
    lives = 3;
    score = 0;
  }
}



