//
// Created by OscarNg on 2022/12/15.
//

#ifndef PONGSFML_PADDLE_H
#define PONGSFML_PADDLE_H
#include <SFML/Graphics.hpp>
class Paddle
{
 public:
  int paddle_speed = 3;
  float bat_speed = 100;
  bool bat_moving_up = false;
  bool bat_moving_down = false;

  sf::Sprite sprite;

  void init(sf::Texture & texture);
  void paddleMoveUp(float dt);
  void paddleMoveDown(float dt);

};

#endif // PONGSFML_PADDLE_H
