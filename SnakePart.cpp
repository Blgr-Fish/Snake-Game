#include "SnakePart.h"

SnakePart::SnakePart(int x, int y) {
    this->p_x = x ;
    this->p_y = y;
    this->p_isHead = true ;
}

int SnakePart::getX() { return this->p_x ;}
int SnakePart::getY() { return this->p_y ;}

bool SnakePart::isHead() { return this->p_isHead ;}

void SnakePart::setHead(bool b) { this->p_isHead = b ;}
