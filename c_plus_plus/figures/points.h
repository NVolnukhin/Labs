#pragma once
#define ARG_COUNT 2
#include <iostream>

class Point {
public:
    Point() : x_{0}, y_{0} {};
    Point(double x, double y) : x_(x), y_(y) {};

    Point& operator+=(const Point& other) {
        this->x_ += other.x_;
        this->y_ += other.y_;
        return *this;
    }

    Point& operator-=(const Point& other) {
        this->x_ -= other.x_;
        this->y_ -= other.y_;
        return *this;
    }

    long double DotProduct(const Point& other) {
        return x_ * other.x_ + y_ * other.y_;
    }

    long double CrossProduct(const Point& other) {
        return x_ * other.y_ - y_ * other.x_;
    }

    Point operator+(const Point& other) {
        Point res;
        res.x_ = this->x_ + other.x_;
        res.y_ = this->y_ + other.y_;
        return res;
    }

    Point operator-(const Point& other) {
        Point res;
        res.x_ = this->x_ - other.x_;
        res.y_ = this->y_ - other.y_;
        return res;
    }

    long double operator*(const Point& other) {
        return this->DotProduct(other);
    }

    long double operator^(const Point& other) {
        return this->CrossProduct(other);
    }

    bool operator==(const Point& other) const {
        return std::tie(y_, x_) == std::tie(other.y_, other.x_);
    }

    bool operator<(const Point& other) const {
        return std::tie(y_, x_) < std::tie(other.y_, other.x_);
    }

    void getPoint();
    void printPoint();
    static double getPolarAngle(Point& point);
    static double getLineLength(Point& point1, Point& point2);
public:
    double x_, y_;
};
