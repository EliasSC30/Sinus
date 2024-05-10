//
// Created by Oezcan, Elias on 09.05.24.
//
#include <array>
#include <numeric>

#ifndef SINUS_SINUS_H
#define SINUS_SINUS_H

struct Point{
    double x,y;
};

constexpr std::array firstQuadrant {
    Point{0.0, 0.0},
    Point{1.0,0.84147098480789650665250232163029899962256306079837},
    Point{M_PI_2, 1.0}};

constexpr std::array secondQuadrant {
        Point{M_PI_2, 1.0},
        Point{0.75 * M_PI, 0.70710678118654746172},
        Point{M_PI, 0.0}};

constexpr std::array thirdQuadrant {
        Point{M_PI, 0.0},
        Point{M_PI * (5.0/4.0), -0.7071067811865475},
        Point{1.5 * M_PI, -1.0}};
constexpr std::array fourthQuadrant {
        Point{1.5 * M_PI, -1.0},
        Point{M_PI * (7.0/4.0), -0.7071067811865475},
        Point{2.0*M_PI, 0.0}};


class Sinus {
private:
    static constexpr auto& getPtsForInterpolation(double x)
    {
        if(x < M_PI)
            return (x < M_PI_2) ? firstQuadrant : secondQuadrant;
        else
            return (x < (M_PI + M_PI_2)) ? thirdQuadrant : fourthQuadrant;

    }
public:
    constexpr double operator()(double x)
    {
        auto pts = getPtsForInterpolation(x);

        double ret{0.0};
        for(size_t j{0u}; j < pts.size(); ++j)
            ret += pts[j].y * Lj(x, j);

        return ret;
    }

private:
    static constexpr double Lj(double x, size_t j)
    {
        auto pts = getPtsForInterpolation(x);

        double ret{1.0};
        for(size_t i{0u}; i < pts.size(); ++i)
        {
            if( i == j)
                continue;
            ret *= (x-pts[i].x) / (pts[j].x - pts[i].x);
        }

        return ret;
    }
};


#endif //SINUS_SINUS_H
