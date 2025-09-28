#pragma once 

class SnakePart {
    public:

        SnakePart(int x, int y);
        int getX();
        int getY();
        bool isHead();
        void setHead(bool b);

    private:
        int p_x ;
        int p_y;
        bool p_isHead;
};