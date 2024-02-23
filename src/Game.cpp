
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{


  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font loading error";
  }

  menu_text.setString("Pong");
  menu_text.setFont(font);
  menu_text.setCharacterSize(150);
  menu_text.setFillColor(sf::Color(255, 255, 255, 255));
  menu_text.setPosition(350, 100);

  start_text.setString("Start");
  start_text.setFont(font);
  start_text.setCharacterSize(30);
  start_text.setFillColor(sf::Color(200, 0, 0, 255));
  start_text.setPosition(480, 400);

  option_text.setString("Option");
  option_text.setFont(font);
  option_text.setCharacterSize(30);
  option_text.setFillColor(sf::Color(255, 255, 255, 255));
  option_text.setPosition(480, 440);

  quit.setString("Quit");
  quit.setFont(font);
  quit.setCharacterSize(30);
  quit.setFillColor(sf::Color(255, 255, 255, 255));
  quit.setPosition(480, 480);


  option_title.setString("OPTION");
  option_title.setFont(font);
  option_title.setCharacterSize(60);
  option_title.setFillColor(sf::Color(255,255,255,255));
  option_title.setPosition(window.getSize().x/2 - option_title.getGlobalBounds().width /2 ,50);

  ball_speed_option_text.setString("Speed of Ball");
  ball_speed_option_text.setFont(font);
  ball_speed_option_text.setCharacterSize(30);
  ball_speed_option_text.setFillColor(sf::Color(255,255,255,255));
  ball_speed_option_text.setPosition(160,160);

  ball_speed_value.setString("<  6  >");
  ball_speed_value.setFont(font);
  ball_speed_value.setCharacterSize(30);
  ball_speed_value.setFillColor(sf::Color(255,255,255,125));
  ball_speed_value.setPosition(800,160);

  paddle_speed_option_text.setString("Speed of Paddle");
  paddle_speed_option_text.setFont(font);
  paddle_speed_option_text.setCharacterSize(30);
  paddle_speed_option_text.setFillColor(sf::Color(255,255,255,255));
  paddle_speed_option_text.setPosition(160,320);

  paddle_speed_value.setString("<  3  >");
  paddle_speed_value.setFont(font);
  paddle_speed_value.setCharacterSize(30);
  paddle_speed_value.setFillColor(sf::Color(255,255,255,125));
  paddle_speed_value.setPosition(800,320);

  string_ball_speed << ball1.ball_speed;
  string_paddle_speed << bat1.paddle_speed;

  return_main_menu.setString(">Press Esc to return menu<");
  return_main_menu.setFont(font);
  return_main_menu.setCharacterSize(30);
  return_main_menu.setFillColor(sf::Color(255,255,255,150));
  return_main_menu.setPosition(window.getSize().x /2 - return_main_menu.getGlobalBounds().width/2,
                               window.getSize().y - 100);


  string_player1_score << player1_score;
  string_player1_score << player2_score;

  start_game_text.setString("< Press Space to start >");
  start_game_text.setFont(font);
  start_game_text.setCharacterSize(40);
  start_game_text.setFillColor(sf::Color(255,255,255,200));
  start_game_text.setPosition(window.getSize().x/2 -start_game_text.getGlobalBounds().width/2 ,
                         window.getSize().y/2 + 200);

  scoreboard1.setString("0");
  scoreboard1.setFont(font);
  scoreboard1.setCharacterSize(75);
  scoreboard1.setFillColor(sf::Color(255,255,255,200));
  scoreboard1.setPosition(200-scoreboard1.getGlobalBounds().width/2 ,20);

  scoreboard2.setString("0");
  scoreboard2.setFont(font);
  scoreboard2.setCharacterSize(75);
  scoreboard2.setFillColor(sf::Color(255,255,255,200));
  scoreboard2.setPosition(880 - scoreboard2.getGlobalBounds().width/2,20);



  if (!ball_texture.loadFromFile("Data/Images/ballGrey.png"))
  {
    std::cout << "Ball texture loading error";
  }
  ball1.init(ball_texture);
  ball1.sprite.setPosition(window.getSize().x / 2 - ball1.sprite.getGlobalBounds().width / 2,
                           window.getSize().y / 2 - ball1.sprite.getGlobalBounds().height / 2);

  if (!bat_texture.loadFromFile("Data/Images/paddleBlue.png"))
  {
    std::cout << "bat texture loading error";
  }
  bat1.init(bat_texture);
  bat1.sprite.setPosition(
    150, window.getSize().y / 2 - bat1.sprite.getGlobalBounds().height / 2);

  if (!bat2_texture.loadFromFile("Data/Images/paddleRed.png"))
  {
    std::cout << "bat texture loading error";
  }
  bat2.init(bat2_texture);
  bat2.sprite.setPosition(
    930, window.getSize().y / 2 - bat2.sprite.getGlobalBounds().height / 2);

  game_over.setString("GAME OVER");
  game_over.setFont(font);
  game_over.setCharacterSize(75);
  game_over.setFillColor(sf::Color(255,255,255,255));
  game_over.setPosition(window.getSize().x/2 - game_over.getGlobalBounds().width/2, 20);

  player1_final_result.setFont(font);
  player1_final_result.setCharacterSize(50);
  player1_final_result.setFillColor(sf::Color(255,255,255,255));

  player2_final_result.setFont(font);
  player2_final_result.setCharacterSize(50);
  player2_final_result.setFillColor(sf::Color(255,255,255,255));

  return true;
}

void Game::update(float dt)
{
  if (selected_text_count == 0)
  {
    selected_text_count = 3;
  }
  selected_text = selected_text_count % 3;

  if (selected_text == 0)
  {
    start_text.setString("> Start");
    start_text.setFillColor(sf::Color(200, 0, 0, 255));
    option_text.setString("Option");
    option_text.setFillColor(sf::Color(255, 255, 255, 255));
    quit.setString("Quit");
    quit.setFillColor(sf::Color(255, 255, 255, 255));
  }
  else if (selected_text == 1 || selected_text == -1)
  {
    start_text.setString("Start");
    start_text.setFillColor(sf::Color(255, 255, 255, 255));
    option_text.setString("> Option");
    option_text.setFillColor(sf::Color(200, 0, 0, 255));
    quit.setString("Quit");
    quit.setFillColor(sf::Color(255, 255, 255, 255));
  }
  else if (selected_text == 2 || selected_text == -2)
  {
    start_text.setString("Start");
    start_text.setFillColor(sf::Color(255, 255, 255, 255));
    option_text.setString("Option");
    option_text.setFillColor(sf::Color(255, 255, 255, 255));
    quit.setString("> Quit");
    quit.setFillColor(sf::Color(200, 0, 0, 255));
  }

  if (menu_option == 1)
  {
    if(start == true)
    {
      ball1.move(dt);
      if (
        ball1.sprite.getPosition().y >
          (window.getSize().y - ball1.sprite.getGlobalBounds().height) ||
        (ball1.sprite.getPosition().y < 0))
      {
        ball1.ball_direction.y *= -1;
      }

      if ((collisionCheck(ball1.sprite, bat1.sprite)) || (collisionCheck2(ball1.sprite, bat2.sprite)))
      {
        ball1.ball_direction.x *= -1;
        ball1.ball_direction.mult_scaler();
      }
      if ((bat1.bat_moving_up) && (bat1.sprite.getPosition().y > 0))
      {
        bat1.paddleMoveUp(dt);
      }
      if (
        (bat1.bat_moving_down) &&
        (bat1.sprite.getPosition().y <
         (window.getSize().y - bat1.sprite.getGlobalBounds().height)))
      {
        bat1.paddleMoveDown(dt);
      }
      if ((bat2.bat_moving_up) && (bat2.sprite.getPosition().y > 0))
      {
        bat2.paddleMoveUp(dt);
      }
      if (
        (bat2.bat_moving_down) &&
        (bat2.sprite.getPosition().y <
         (window.getSize().y - bat2.sprite.getGlobalBounds().height)))
      {
        bat2.paddleMoveDown(dt);
      }
    }
    if (ReachTheGoal(ball1.sprite))
    {
      string_player1_score.str("");
      string_player2_score.str("");
      string_player1_score << player1_score;
      string_player2_score << player2_score;
      scoreboard1.setString(string_player1_score.str());
      scoreboard2.setString(string_player2_score.str());
      ball1.sprite.setPosition(
        window.getSize().x / 2 - ball1.sprite.getGlobalBounds().width / 2,
        window.getSize().y / 2 - ball1.sprite.getGlobalBounds().height / 2);
      ball1.ball_direction.x = 2;
      ball1.ball_direction.y = 3;
      bat2.sprite.setPosition(
        930, window.getSize().y / 2 - bat2.sprite.getGlobalBounds().height / 2);
      bat1.sprite.setPosition(
        150, window.getSize().y / 2 - bat1.sprite.getGlobalBounds().height / 2);
      start = false;
    }
    if (player1_score == 5 or player2_score == 5)
    {
      menu_option = 3;

      if (player1_score > player2_score)
      {
        player1_final_result.setString("You win");
        player1_final_result.setPosition(120, 150);
        player2_final_result.setString("You lose");
        player2_final_result.setPosition(
          930 - player2_final_result.getGlobalBounds().width, 150);
      }
      else
      {
        player1_final_result.setString("You lose");
        player1_final_result.setPosition(120, 150);
        player2_final_result.setString("You win");
        player2_final_result.setPosition(
          930 - player2_final_result.getGlobalBounds().width, 150);
      }
    }
  }
}
void Game::render()
{
  if (menu_option == 0)
  {
    window.draw(menu_text);
    window.draw(start_text);
    window.draw(option_text);
    window.draw(quit);
  }

  else if (menu_option == 1)
  {
    if(start == false)
    {
      window.draw(start_game_text);
    }
    window.draw(scoreboard1);
    window.draw(scoreboard2);
    window.draw(ball1.sprite);
    window.draw(bat1.sprite);
    window.draw(bat2.sprite);
  }
  else if(menu_option == 2)
  {
    window.draw(option_title);
    window.draw(ball_speed_option_text);
    window.draw(ball_speed_value);
    window.draw(paddle_speed_option_text);
    window.draw(paddle_speed_value);
    window.draw(return_main_menu);
  }

  else if(menu_option == 3)
  {
    window.draw(game_over);
    window.draw(ball1.sprite);
    window.draw(bat1.sprite);
    window.draw(bat2.sprite);
    window.draw(scoreboard1);
    window.draw(scoreboard2);
    window.draw(player1_final_result);
    window.draw(player2_final_result);
  }
}

void Game::mouseClicked(sf::Event event)
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::keyPressed(sf::Event event)
{
  if (menu_option == 0)
  {
    if (event.key.code == sf::Keyboard::Down)
    {
      selected_text_count += 1;
    }

    else if (event.key.code == sf::Keyboard::Up)
    {
      selected_text_count -= 1;
    }

    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (selected_text == 0)
      {
        menu_option = 1;
      }
      else if (selected_text == 1)
      {
        menu_option = 2;
      }
      else if (selected_text == 2)
      {
        window.close();
      }
    }
  }
  else if (menu_option == 1)
  {
    if (event.key.code == sf::Keyboard::Space)
    {
      start = true;
    }
    else if (event.key.code == sf::Keyboard::W)
    {
      bat1.bat_moving_up = true;
    }

    else if (event.key.code == sf::Keyboard::S)
    {
      bat1.bat_moving_down = true;
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
      bat2.bat_moving_up = true;
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
      bat2.bat_moving_down= true;
    }
    else if(event.key.code == sf::Keyboard::Escape)
    {
      menu_option = 0;
      Reset();
    }
  }

  else if(menu_option == 2)
  {
    if((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::Down))
    {
      selected_option =! selected_option;

      if(selected_option)
      {
        ball_speed_value.setFillColor(sf::Color(255,255,255,255));
        paddle_speed_value.setFillColor(sf::Color(255,255,255,125));
        ball_speed_selected = true;
      }
      else
      {
        paddle_speed_value.setFillColor(sf::Color(255,255,255,255));
        ball_speed_value.setFillColor(sf::Color(255,255,255,125));
        ball_speed_selected = false;
      }
    }
    else if(event.key.code == sf::Keyboard::Escape)
    {
      menu_option = 0;
    }
    else if(event.key.code == sf::Keyboard::Left)
    {
      if(ball_speed_selected)
      {
        if (ball1.ball_speed >1)
        {
          ball1.ball_speed -=1;
          string_ball_speed.str("");
          string_ball_speed << ball1.ball_speed;
          ball_speed_value.setString("<  "+ string_ball_speed.str() + "  >");
        }
      }
      else
      {
        if (bat1.paddle_speed >1)
        {
          bat1.paddle_speed -=1;
          bat2.paddle_speed -=1;
          string_paddle_speed.str("");
          string_paddle_speed << bat1.paddle_speed;
          paddle_speed_value.setString("<  "+ string_paddle_speed.str() + "  >");
        }
      }
    }
    else if(event.key.code == sf::Keyboard::Right)
    {
      if (ball_speed_selected)
      {
        if (ball1.ball_speed < 10)
        {
          ball1.ball_speed += 1;
          string_ball_speed.str("");
          string_ball_speed << ball1.ball_speed;
          ball_speed_value.setString("<  " + string_ball_speed.str() + "  >");
        }
      }
      else
      {
        if(bat1.paddle_speed <10)
        {
          bat1.paddle_speed += 1;
          bat2.paddle_speed += 1;
          string_paddle_speed.str("");
          string_paddle_speed << bat1.paddle_speed;
          paddle_speed_value.setString("<  " + string_paddle_speed.str() + "  >");
        }
      }
    }
  }

  else if(menu_option == 3)
  {
    menu_option = 0;
    Reset();
  }
}

void Game::keyReleased(sf::Event event)
{
  if (menu_option == 1)
  {
    if (event.key.code == sf::Keyboard::W)
    {
      bat1.bat_moving_up = false;
    }

    else if (event.key.code == sf::Keyboard::S)
    {
      bat1.bat_moving_down = false;
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
      bat2.bat_moving_up = false;
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
      bat2.bat_moving_down = false;
    }
  }
}

float Game::left_hitbox(sf::Sprite sprite)
{
  sprite_left_hitbox =sprite.getPosition().x ;

  return sprite_left_hitbox;
}

float Game::right_hitbox(sf::Sprite sprite)
{
  sprite_right_hitbox =
    sprite.getPosition().x + sprite.getGlobalBounds().width ;

  return sprite_right_hitbox;
}

bool Game ::collisionCheck(sf::Sprite sprite1, sf::Sprite sprite2)
{
  if (sprite2.getPosition().x +sprite2.getGlobalBounds().width >= (left_hitbox(sprite1)) &&
      (sprite2.getPosition().x +sprite2.getGlobalBounds().width/4 <= (left_hitbox(sprite1)) &&
    (sprite2.getPosition().y+sprite2.getGlobalBounds().height  >=sprite1.getPosition().y) &&
     (sprite1.getPosition().y+ sprite1.getGlobalBounds().height >= sprite2.getPosition().y )))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool Game ::collisionCheck2(sf::Sprite sprite1, sf::Sprite sprite2)
{
  if (((right_hitbox(sprite1)) >= sprite2.getPosition().x) &&
      ((right_hitbox(sprite1)) <= sprite2.getPosition().x+ sprite2.getGlobalBounds().width /4)&&
      (sprite2.getPosition().y+sprite2.getGlobalBounds().height  >=sprite1.getPosition().y) &&
      (sprite1.getPosition().y+ sprite1.getGlobalBounds().height >= sprite2.getPosition().y ))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Game::ReachTheGoal(sf::Sprite sprite)
{
  if(sprite.getPosition().x > window.getSize().x)
  {
    player1_score += 1;
    return true;
  }
  else if (sprite.getPosition().x < 0)
  {
    player2_score += 1;
    return true;
  }
  else
  {
    return false;
  }
}

void Game::Reset()
  {
    ball1.sprite.setPosition(
      window.getSize().x / 2 - ball1.sprite.getGlobalBounds().width / 2,
      window.getSize().y / 2 - ball1.sprite.getGlobalBounds().height / 2);
    ball1.ball_direction.x = 2;
    ball1.ball_direction.y = 3;
    bat1.sprite.setPosition(
      150, window.getSize().y / 2 - bat1.sprite.getGlobalBounds().height / 2);
    bat2.sprite.setPosition(
      930, window.getSize().y / 2 - bat2.sprite.getGlobalBounds().height / 2);
    player1_score = 0;
    player2_score = 0;
    string_player1_score.str("");
    string_player2_score.str("");
    string_player1_score << player1_score;
    string_player2_score << player2_score;
    scoreboard1.setString(string_player1_score.str());
    scoreboard2.setString(string_player2_score.str());
    start = false;
  }

  void Ball::move(float dt)
  {
    sprite.move(
      ball_direction.x * (speed * ball_speed * dt) ,
      ball_direction.y * (speed * ball_speed *dt));
  }

  void Paddle::paddleMoveUp(float dt)
  {
    sprite.move(0.0, -2.0f * (bat_speed * paddle_speed) * dt);
  }

  void Paddle::paddleMoveDown(float dt)
  {
    sprite.move(0.0, 2.0f * (bat_speed * paddle_speed) * dt);
  }