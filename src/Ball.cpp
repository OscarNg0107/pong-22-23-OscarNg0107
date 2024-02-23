//
// Created by OscarNg on 2022/12/15.
//

#include "Ball.h"

void Ball::init(sf::Texture & texture)
{
  Vector ball_direction;
  ball_direction.x = 2;
  ball_direction.y = 3;
  ball_direction.normalise();
  sprite.setTexture(texture);
  sprite.setScale(1.5f,1.5f);
}