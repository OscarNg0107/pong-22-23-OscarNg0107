
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector.h"
#include <sstream>
#include "Ball.h"
#include "Paddle.h"
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

 private:
  sf::RenderWindow& window;
  sf::Font font;

  Ball ball1;
  sf::Texture ball_texture;

  float sprite_left_hitbox;
  float sprite_right_hitbox;

  float left_hitbox(sf::Sprite sprite);
  float right_hitbox(sf::Sprite sprite);
  bool collisionCheck(sf::Sprite sprite1, sf::Sprite sprite2);
  bool collisionCheck2(sf::Sprite sprite1, sf::Sprite sprite2);
  bool ReachTheGoal(sf::Sprite sprite);

  bool start = false;
  sf::Text start_game_text;
  Paddle bat1;
  Paddle bat2;
  sf::Texture bat_texture;
  sf::Texture bat2_texture;

  int menu_option = 0;
  sf::Text menu_text;
  sf::Text start_text;
  sf::Text option_text;
  sf::Text quit;
  int selected_text_count = 0;
  int selected_text = selected_text_count %3;

  sf::Text option_title;
  sf::Text ball_speed_option_text;
  sf::Text ball_speed_value;
  sf::Text paddle_speed_option_text;
  sf::Text paddle_speed_value;
  sf::Text return_main_menu;
  bool selected_option = true;
  bool ball_speed_selected;
  std::ostringstream string_ball_speed;
  std::ostringstream string_paddle_speed;

  sf::Text scoreboard1;
  sf::Text scoreboard2;
  int player1_score = 0;
  int player2_score = 0;
  std::ostringstream string_player1_score;
  std::ostringstream string_player2_score;

  bool player1_win = false;
  sf::Text game_over;
  sf::Text player1_final_result;
  sf::Text player2_final_result;

  void Reset();
};

#endif // PONG_GAME_H
