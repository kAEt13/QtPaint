#ifndef MY_POINT_H
#define MY_POINT_H


class my_point
{
public:
    my_point();

    my_point(int x, int y);

    void setX(int new_x);

    void setY(int new_y);

    void setXY(int new_x, int new_y);

    int getX(void);

    int getY(void);

    void getXY(int &n_x, int &n_y);

protected:
    int x;
    int y;
};

#endif // MY_POINT_H
