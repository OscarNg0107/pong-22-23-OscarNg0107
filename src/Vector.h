//
// Created by OscarNg on 2022/11/30.
//

#ifndef PONGSFML_VECTOR_H
#define PONGSFML_VECTOR_H

class Vector
{
 public:
    float x ;
    float y ;

    Vector();
    Vector(float val_x, float val_y);

    ~Vector();


    void normalise();
    void mult_scaler();
};

#endif // PONGSFML_VECTOR_H
