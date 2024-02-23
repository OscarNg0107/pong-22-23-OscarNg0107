//
// Created by OscarNg on 2022/12/15.
//

#ifndef PONGSFML_BALL_H
#define PONGSFML_BALL_H
#include "Vector.h"
#include <SFML/Graphics.hpp>
class Ball
{
 public:
  Vector ball_direction ;
  int ball_speed = 6;
  float speed = 30 ;

  sf::Sprite sprite;

  void init(sf::Texture & texture);

  void move(float dt);

};

#endif // PONGSFML_BALL_H
