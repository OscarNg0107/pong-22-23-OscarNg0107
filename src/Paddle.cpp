//
// Created by OscarNg on 2022/12/15.
//

#include "Paddle.h"

void Paddle::init(sf::Texture& texture)
{
  sprite.setTexture(texture);
  sprite.setScale(1.0f, 1.0f);
}
