
#include "Game.h"
#include <iostream>
#include <random>
#include <cmath>

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




  // fonts
  if(!main_font.loadFromFile("Data/Fonts/Inversionz Unboxed.ttf"))
  {
    std::cout << "inversionz didn't load \n";
  }

  //setting the "special" font
  if(!secondary_font.loadFromFile("Data/Fonts/Curved Square.ttf"))
  {
    std::cout << "curved square font no load \n";
  }

  //background texture
  if(!background_texture.loadFromFile("Data/Images/SpaceShooterRedux/Backgrounds/background-good.png"))
  {
    std::cout << "background texture didn't load \n";
  }
  background.setTexture(background_texture);


  // player ship
  player_ship = new GameObject();
  player_ship->initialiseSprite(player_ship->player_ship_texture, "Data/Images/SpaceShooterRedux/PNG/playerShip3_red.png");
  player_ship->getSprite()->setPosition(window.getSize().x/2-49,600);

  //laser
  for (int x = 0; x < 4; x++)
  {
    laser[x] = new GameObject();
    laser[x]->initialiseSprite(laser[x]->laser_texture, "Data/Images/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
    laser[x]->visibility = false;

  }


  //enemy ships


  // rendering
  for (int x = 0; x < 9; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      enemy_ship[x][y] = new GameObject();

      switch (y)
      {
        case 0:
          enemy_ship[x][y]->initialiseSprite(enemy_ship[x][y]->enemy_ship_texture, "Data/Images/AlienUFOpack/PNG/shipBeige_manned.png");
          break;
        case 1:
          enemy_ship[x][y]->initialiseSprite(enemy_ship[x][y]->enemy_ship_texture, "Data/Images/AlienUFOpack/PNG/shipGreen_manned.png");
          break;
        case 2:
          enemy_ship[x][y]->initialiseSprite(enemy_ship[x][y]->enemy_ship_texture, "Data/Images/AlienUFOpack/PNG/shipBlue_manned.png");
          break;
        default:
          break;
      }
      enemy_ship[x][y]->getSprite()->setPosition( 150 + x * 85, y * 60);
      enemy_ship[x][y]->getSprite()->setScale(0.45,0.45);
      enemy_ship[x][y]->visibility = true;
    }
  }

  // text stuff

  //score stuff
  score_display.setFont(main_font);
  score_display.setCharacterSize(75);
  score_display.setFillColor(sf::Color(45,226,230));
  score_display.setOutlineColor(sf::Color(2,55,136));
  score_display.setOutlineThickness(3);
  score_display.setPosition(0, 200);

  // menu texts
  title_text.setString("alien invaders");
  title_text.setFont(secondary_font);
  title_text.setCharacterSize(100);
  title_text.setFillColor(sf::Color(2,55,136));
  title_text.setOutlineColor(sf::Color(45,226,230));
  title_text.setOutlineThickness(5);
  title_text.setPosition(125, 35);

  play_option.setFont(main_font);
  play_option.setString(">Play<");
  play_option.setCharacterSize(70);
  play_option.setFillColor(sf::Color(45,226,230));
  play_option.setOutlineColor(sf::Color(2,55,136));
  play_option.setOutlineThickness(3);
  play_option.setPosition(400,280);

  quit_option.setFont(main_font);
  quit_option.setString("Quit");
  quit_option.setCharacterSize(70);
  quit_option.setFillColor(sf::Color(45,226,230));
  quit_option.setOutlineColor(sf::Color(2,55,136));
  quit_option.setOutlineThickness(3);
  quit_option.setPosition(444, 370);

  credit.setFont(main_font);
  credit.setString("Credits: \n"
                   "Sprite Art: uhhh  \n"
                   "Code: Joey  \n"
                   "Background Art: Khanecz on Imgur");
  credit.setCharacterSize(25);
  credit.setFillColor(sf::Color(45,226,230));
  credit.setOutlineColor(sf::Color(2,55,136));
  credit.setOutlineThickness(3);
  credit.setPosition(0,625);
  credit.setPosition(0,625);

  // game over text
  game_over_title.setFont(secondary_font);
  game_over_title.setString("game over\n"
                               "return to menu?");
  game_over_title.setCharacterSize(100);
  game_over_title.setFillColor(sf::Color(2,55,136));
  game_over_title.setOutlineColor(sf::Color(45,226,230));
  game_over_title.setOutlineThickness(5);
  game_over_title.setPosition(125, 35);

  return_option.setFont(main_font);
  return_option.setString(">Menu<");
  return_option.setCharacterSize(70);
  return_option.setFillColor(sf::Color(45,226,230));
  return_option.setOutlineColor(sf::Color(2,55,136));
  return_option.setOutlineThickness(3);
  return_option.setPosition(400,280);

  exit_option.setFont(main_font);
  exit_option.setString("Exit");
  exit_option.setCharacterSize(70);
  exit_option.setFillColor(sf::Color(45,226,230));
  exit_option.setOutlineColor(sf::Color(2,55,136));
  exit_option.setOutlineThickness(3);
  exit_option.setPosition(444, 370);


  //victory text

  victory_title.setFont(secondary_font);
  victory_title.setString("you win\n"
                            "return to menu?");
  victory_title.setCharacterSize(100);
  victory_title.setFillColor(sf::Color(2,55,136));
  victory_title.setOutlineColor(sf::Color(45,226,230));
  victory_title.setOutlineThickness(5);
  victory_title.setPosition(125, 35);

  victory_return.setFont(main_font);
  victory_return.setString(">Menu<");
  victory_return.setCharacterSize(70);
  victory_return.setFillColor(sf::Color(45,226,230));
  victory_return.setOutlineColor(sf::Color(2,55,136));
  victory_return.setOutlineThickness(3);
  victory_return.setPosition(400,280);

  victory_exit.setFont(main_font);
  victory_exit.setString("Exit");
  victory_exit.setCharacterSize(70);
  victory_exit.setFillColor(sf::Color(45,226,230));
  victory_exit.setOutlineColor(sf::Color(2,55,136));
  victory_exit.setOutlineThickness(3);
  victory_exit.setPosition(444, 370);

  // game option stuff
  option_title.setString("      choose a    \n"
                             "enemy movement style");
  option_title.setFont(secondary_font);
  option_title.setCharacterSize(100);
  option_title.setFillColor(sf::Color(2,55,136));
  option_title.setOutlineColor(sf::Color(45,226,230));
  option_title.setOutlineThickness(5);
  option_title.setPosition(125, 35);

  normal_option.setFont(main_font);
  normal_option.setString(">Normal<");
  normal_option.setCharacterSize(70);
  normal_option.setFillColor(sf::Color(45,226,230));
  normal_option.setOutlineColor(sf::Color(2,55,136));
  normal_option.setOutlineThickness(3);
  normal_option.setPosition(window.getSize().x/2-168,280);

  gravity_option.setFont(main_font);
  gravity_option.setString("Gravity");
  gravity_option.setCharacterSize(70);
  gravity_option.setFillColor(sf::Color(45,226,230));
  gravity_option.setOutlineColor(sf::Color(2,55,136));
  gravity_option.setOutlineThickness(3);
  gravity_option.setPosition(window.getSize().x/2-145, 370);

  quadratic_option.setFont(main_font);
  quadratic_option.setString("Quadratic");
  quadratic_option.setCharacterSize(70);
  quadratic_option.setFillColor(sf::Color(45,226,230));
  quadratic_option.setOutlineColor(sf::Color(2,55,136));
  quadratic_option.setOutlineThickness(3);
  quadratic_option.setPosition(window.getSize().x/2-189.5f, 460);

  sine_option.setFont(main_font);
  sine_option.setString("Sine");
  sine_option.setCharacterSize(70);
  sine_option.setFillColor(sf::Color(45,226,230));
  sine_option.setOutlineColor(sf::Color(2,55,136));
  sine_option.setOutlineThickness(3);
  sine_option.setPosition(window.getSize().x/2-79.5f, 550);

  return true;
}

void Game::update(float dt)
{
  //player movement
  player_ship->getSprite()->move(
    player_ship->direction.x * player_ship->speed * dt, player_ship->direction.y * dt);
  //player-wall collision
  if (
    player_ship->getSprite()->getPosition().x >=
    (window.getSize().x - player_ship->getSprite()->getGlobalBounds().width) or
      player_ship->getSprite()->getPosition().x <= 0)
  {
    // reverse ship
    player_ship->direction.x *= -1.0f;
  }

}


void Game::enemyMovement(float dt)
{
  // this could probably be in update, resets the game
  if(in_menu or game_over or victory or option_menu)
  {
    for (int x = 0; x < 9; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        // everything gets reset to pre-run state
        enemy_ship[x][y]->getSprite()->move(0,0);
        enemy_ship[x][y]->getSprite()->setPosition( 150 + x * 85, y * 60);
        first_run = false;
        score = 0;
        temp_move = 0.f;
        enemy_ship[x][y]->visibility = true;
      }
    }
  }
  else
  {
    //random first movement
    enemy_direction = rand() % 1 + 2;

    // first run variable just randomly sends enemy ships one of two directions
    // on startup.
    if (!first_run)
    {
      for (int x = 0; x < 9; x++)
      {
        for (int y = 0; y < 3; y++)
        {
          switch (enemy_direction)
          {
              // randomly send the enemy ships one of two ways
            case 1:
              enemy_ship[x][y]->speed = 15;
              enemy_ship[x][y]->direction.x = 1;
              break;
            case 2:
              enemy_ship[x][y]->speed = 15;
              enemy_ship[x][y]->direction.x = -1;
              break;
            default:
              break;
          }
          // sets it to true so it can't run again
          first_run = true;
        }
      }

    }

    // normal collision loop
    for (int x = 0; x < 9; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        // im not entirely sure how this works but it does
        float temp_dir = enemy_ship[x][y]->direction.x;

        if (
          enemy_ship[x][y]->getSprite()->getPosition().x >=
          (window.getSize().x -
           enemy_ship[x][y]->getSprite()->getGlobalBounds().width) or
          enemy_ship[x][y]->getSprite()->getPosition().x <= 0)
        {
          for (int x = 0; x < 9; x++)
          {
            for (int y = 0; y < 3; y++)
            {
              // reverse ship
              enemy_ship[x][y]->direction.x *= -1.0f;

              // based on the mode, do different collision codes
              switch(mode_chosen)
              {
                  // normal collision - just rebounds and moves down slighty
                case 0:
                  enemy_ship[x][y]->getSprite()->setPosition(
                    enemy_ship[x][y]->getSprite()->getPosition().x,
                    enemy_ship[x][y]->getSprite()->getPosition().y + 10);
                  enemy_ship[x][y]->direction.x *= 1;
                  if (temp_dir != enemy_ship[x][y]->direction.x)
                  {
                    temp_move += 1;
                  }
                  break;
                  // gravity, gradually goes down
                case 1:
                  enemy_ship[x][y]->getSprite()->setPosition(
                    enemy_ship[x][y]->getSprite()->getPosition().x,
                    enemy_ship[x][y]->getSprite()->getPosition().y);
                  enemy_ship[x][y]->direction.x *= 1;
                  if (temp_dir != enemy_ship[x][y]->direction.x)
                  {
                    temp_move += 1;
                  }
                  break;
                  // quadratic curve
                case 2:
                  enemy_ship[x][y]->getSprite()->setPosition(
                    enemy_ship[x][y]->getSprite()->getPosition().x,
                    enemy_ship[x][y]->getSprite()->getPosition().y + 10);
                  enemy_ship[x][y]->direction.x *= 1;
                  if (temp_dir != enemy_ship[x][y]->direction.x)
                  {
                    temp_move += 1;
                  }
                  break;
                  // sine curve
                case 3:
                  enemy_ship[x][y]->getSprite()->setPosition(
                    enemy_ship[x][y]->getSprite()->getPosition().x,
                    enemy_ship[x][y]->getSprite()->getPosition().y + 10);
                  enemy_ship[x][y]->direction.x *= 1;
                  if (temp_dir != enemy_ship[x][y]->direction.x)
                  {
                    temp_move += 1;
                  }
                  break;

              }
            }
          }
        }


        // the actual collision/curve maths
        switch (mode_chosen)
        {
            // do nothing because the normal collision is already coded
          case 0:
            break;
            // gradually go down by adding 0.5 each time the program runs
          case 1:
            enemy_ship[x][y]->getSprite()->move(0, gravity);
            break;
            // quadratic curve
            // pray to eldritch deities in order for their blessing for this
            // maths to work
            // - i have no idea how it works, i had to get help to do this and
            // i still dont understand the maths. I'm doomed if we have to do a maths exam
          case 2:
            enemy_ship[x][y]->getSprite()->setPosition(enemy_ship[x][y]->getSprite()->getPosition().x,
            -((- temp_move +(y * 60 - 140)+((enemy_ship[x][y]->getSprite()->getPosition().x/55)-10)*((enemy_ship[x][y]->getSprite()->getPosition().x/55)-10))));
            break;
            // dont have to pray to as many eldritch deities to get this to work
            // sine wave
          case 3:
            enemy_ship[x][y]->getSprite()->setPosition(enemy_ship[x][y]->getSprite()->getPosition().x,
                                                       (y * 60) + 10 * sin(enemy_ship[x][y]->getSprite()->getPosition().x / 10) + temp_move);
            break;
      }

    }

      for (int x = 0; x < 9; x++)
      {
        for (int y = 0; y < 3; y++)
        {
          // make ships move
          enemy_ship[x][y]->getSprite()->move(enemy_ship[x][y]->direction.x * enemy_ship[x][y]->speed * dt, enemy_ship[x][y]->direction.y *  dt);
        }
      }
    }
    // gravity increase
    gravity += 0.0025;
  }
}




// generic rendering stuff
void Game::render()
{
  if(in_menu)
  {
    window.draw(background);
    window.draw(title_text);
    window.draw(play_option);
    window.draw(quit_option);
    window.draw(credit);
  }
  else if(game_over)
  {
    window.draw(background);
    window.draw(game_over_title);
    window.draw(return_option);
    window.draw(exit_option);
  }
  else if (victory)
  {
    window.draw(background);
    window.draw(victory_title);
    window.draw(victory_return);
    window.draw(victory_exit);
  }
  else if (option_menu)
  {
    window.draw(background);
    window.draw(option_title);
    window.draw(normal_option);
    window.draw(gravity_option);
    window.draw(quadratic_option);
    window.draw(sine_option);
  }
  else
  {
    window.draw(background);
    window.draw(*player_ship->getSprite());
    window.draw(score_display);

    for (int x = 0; x < 9; x++)
    {
      for(int y = 0; y < 3; y++)
      {
        if (enemy_ship[x][y]->visibility)
        {
          window.draw(*enemy_ship[x][y]->getSprite());
        }
      }
    }

    for (int x = 0; x < 4; x ++)
    {
      if (laser[x]->visibility)
      {
        window.draw(*laser[x]->getSprite());
      }
    }
  }
}

//void Game::mouseClicked(sf::Event event)
//{
  //get the click position
  //sf::Vector2i click = sf::Mouse::getPosition(window);


//}

// same key pressed stuff as previously
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
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (play_selected)
      {
        in_menu = false;
        option_menu = true;
      }
      else
      {
        window.close();
      }
    }
  }
  // this was annoying to figure out but works, easily enough
  else if (option_menu)
  {
    if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
    {
        if (event.key.code == sf::Keyboard::Up )
        {
          if (option_choice <= 1)
          {
            option_choice = 4;
          }
          else
          {
            option_choice -= 1;
          }
        }

        if (event.key.code == sf::Keyboard::Down)
        {
          if (option_choice >= 4)
          {
            option_choice = 1;
          }
          else
          {
            option_choice += 1;
          }
        }

        switch (option_choice)
        {
          case 1:
            normal_selected = true;
            gravity_selected = false;
            quadratic_selected = false;
            sine_selected = false;

            normal_option.setString(">Normal<");
            normal_option.setPosition(window.getSize().x/2-168, 280);
            gravity_option.setString("Gravity");
            gravity_option.setPosition(window.getSize().x/2-145, 370);
            quadratic_option.setString("Quadratic");
            quadratic_option.setPosition(window.getSize().x/2-189.5f, 460);
            sine_option.setString("Sine");
            sine_option.setPosition(window.getSize().x/2-79, 550);
            break;
          case 2:
            normal_selected = false;
            gravity_selected = true;
            quadratic_selected = false;
            sine_selected = false;

            normal_option.setString("Normal");
            normal_option.setPosition(window.getSize().x/2-124, 280);
            gravity_option.setString(">Gravity<");
            gravity_option.setPosition(window.getSize().x/2-189, 370);
            quadratic_option.setString("Quadratic");
            quadratic_option.setPosition(window.getSize().x/2-189.5f, 460);
            sine_option.setString("Sine");
            sine_option.setPosition(window.getSize().x/2-79, 550);
            break;
          case 3:
            normal_selected = false;
            gravity_selected = false;
            quadratic_selected = true;
            sine_selected = false;

            normal_option.setString("Normal");
            normal_option.setPosition(window.getSize().x/2-124, 280);
            gravity_option.setString("Gravity");
            gravity_option.setPosition(window.getSize().x/2-145, 370);
            quadratic_option.setString(">Quadratic<");
            quadratic_option.setPosition(window.getSize().x/2-233.5f, 460);
            sine_option.setString("Sine");
            sine_option.setPosition(window.getSize().x/2-79, 550);
            break;
          case 4:
            normal_selected = false;
            gravity_selected = false;
            quadratic_selected = false;
            sine_selected = true;

            normal_option.setString("Normal");
            normal_option.setPosition(window.getSize().x/2-124, 280);
            gravity_option.setString("Gravity");
            gravity_option.setPosition(window.getSize().x/2-145, 370);
            quadratic_option.setString("Quadratic");
            quadratic_option.setPosition(window.getSize().x/2-189.5f, 460);
            sine_option.setString(">Sine<");
            sine_option.setPosition(window.getSize().x/2-123, 550);
            break;
          default:
            break;
        }
      }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (normal_selected)
      {
        mode_chosen = 0;
        option_menu   = false;
      }
      else if (gravity_selected)
      {
        mode_chosen = 1;
        option_menu    = false;
      }
      else if (quadratic_selected)
      {
        mode_chosen = 2;
        option_menu      = false;
      }
      else if (sine_selected)
      {
        mode_chosen = 3;
        option_menu = false;
      }
    }
  }
  else if (game_over)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      go_return_selected = !go_return_selected;
      if (go_return_selected)
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
      if (go_return_selected)
      {
        in_menu = true;
        game_over = false;
      }
      else
      {
        window.close();
      }
    }
  }
  else if (victory)
  {
    if (
      (event.key.code == sf::Keyboard::Down) ||
      (event.key.code == sf::Keyboard::Up))
    {
      v_return_selected = !v_return_selected;
      if (v_return_selected)
      {
        victory_return.setString(">Menu<");
        victory_return.setPosition(400, 280);
        victory_exit.setString("Exit");
        victory_exit.setPosition(444, 370);
      }
      else
      {
        victory_return.setString("Menu");
        victory_return.setPosition(444, 280);
        victory_exit.setString(">Exit<");
        victory_exit.setPosition(400, 370);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (v_return_selected)
      {
        in_menu = true;
        victory = false;
      }
      else
      {
        window.close();
      }
    }
  }

  if (event.key.code == sf::Keyboard::Tab)
  {
    game_over = true;
  }
  if (event.key.code == sf::Keyboard::LShift)
  {
    victory = true;
  }

  if (event.key.code == sf::Keyboard::A)
  {
    player_ship->direction.x = -1.f;
  }
  else if (event.key.code == sf::Keyboard::D)
  {
    player_ship->direction.x = 1.f;
  }

}

// track when player releases keys
void Game::keyReleased(sf::Event event)
{
  // code just checks if A or D is released, and stops the paddles
  if (event.key.code == sf::Keyboard::A)
  {
    player_ship->direction.x = 0.f;
  }
  else if (event.key.code == sf::Keyboard::D)
  {
    player_ship->direction.x = 0.f;
  }
}

// laser movement stuff
void Game::laserStuff(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Space)
  {
    // constantly calculate the middle of the player ship
     float player_middle = player_ship->getSprite()->getPosition().x +
                          player_ship->getSprite()->getGlobalBounds().width / 2 -
                          laser[0]->getSprite()->getGlobalBounds().width /2;

     for (int x = 0; x < 4; x++)
     {
       if (!laser[x]->visibility)
       {
         // assign a number of shots to the lasers
         current_shot = x;
         break;
       }
     }

      // if the number of shots on screen is less than four, fire another if prompted
     // also increase the number of shots on screen
     if (current_shot < 4)
     {
       laser[current_shot]->visibility = true;
       laser[current_shot]->getSprite()->setPosition(player_middle, player_ship->getSprite()->getPosition().y -  60);
       current_shot++;
     }
  }
}

// function handling movement for the laser
void Game::laserMovement(float dt)
{
  // for loop for array
  for (int x = 0; x < 4; x++)
  {
    // check if the laser is visible
    if (laser[x]->visibility)
    {
      // set speed, direction, and make it move
      laser[x]->speed = 400;
      laser[x]->direction.y = -1.f;
      laser[x]->getSprite()->move(0, laser[x]->direction.y * laser[x]->speed * dt);

      // collision check with enemy ships
      for (int i = 0; i < 9; i ++)
      {
        for (int y = 0; y < 3; y++)
        {
          // if laser hit enemy ship
          if (laser[x]->getSprite()->getGlobalBounds().intersects(enemy_ship[i][y]->getSprite()->getGlobalBounds()))
          {
            // if that enemy ship is visible
            if (enemy_ship[i][y]->visibility)
            {
              // laser + enemy ship go invisible, increase score.
              laser[x]->visibility = false;
              enemy_ship[i][y]->visibility = false;
              score += 10;
              enemy_count -= 1;
            }
          }
          else if (laser[x]->getSprite()->getPosition().y <= 0)
          {
            laser[x]->visibility = false;
          }
        }
      }
    }
  }
}


// function handling detecting win/loss conditions
void Game::winOrLoss()
{
  // for loops needed for the enemy ship bit
  for (int x = 0; x < 9; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      // if no enemies player wins
      if (enemy_count == 0)
      {
        victory = true;
      }
      // if any of the enemy ships collide with the player, player loses
      if (enemy_ship[x][y]->getSprite()->getGlobalBounds().intersects(player_ship->getSprite()->getGlobalBounds()) and enemy_ship[x][y]->visibility)
      {
        game_over = true;
      }
    }
  }
}

// score stuff
// same as previous worksheets
void Game::scoreUpdate()
{
  // make score number a string then print it
  std::string score_string = std::to_string(score);
  score_display.setString("Score: " + score_string + "pts.");
}