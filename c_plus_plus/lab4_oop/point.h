#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point();
    Point(float x, float y, float z);
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);

private:
    double _x;
    double _y;
    double _z;
};

#endif // POINT_H
