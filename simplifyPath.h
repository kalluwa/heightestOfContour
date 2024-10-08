//
//  simplifyPath.h
//  RDP
//
//  Created by Yongjiao Yu on 14-6-13.
//  Copyright (c) 2014年 ___RCPD___. All rights reserved.
//


#ifndef __simplifyPath__H__
#define __simplifyPath__H__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>

//"Point" struct stand for each GPS coordinates(x,y). Methods related are used only for simplification of calculation in implementation.

struct Point{
    double x;
    double y;
    
    double operator*(Point rhs)const{
        return (this->x * rhs.y - rhs.x * this->y);
    }
    
    Point operator-(Point rhs)const{
        Point p;
        p.x=this->x-rhs.x;
        p.y=this->y-rhs.y;
        return p;
    }
    
    double Norm()const{
        return sqrt(this->x * this->x + this->y * this->y);
    }

    Point()
    {

    }

    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const glm::vec2& pt)
    {
        x = pt.x;
        y = pt.y;
    }

    void operator =(const glm::vec2& pt)
    {
        x = pt.x;
        y = pt.y;
    }
    
};

class simplifyPath{
//"findMaximumDistance" used as part of implementation for RDP algorithm.
private:
    const std::pair<int, double> findMaximumDistance(const std::vector<Point>& Points)const;
    
//"simplifyWithRDP" returns the simplified path with a Point vector. The function takes in the paths to be simplified and a customerized thresholds for the simplication.
public:
    std::vector<Point> simplifyWithRDP(std::vector<Point>& Points, double epsilon)const;
};

#endif 


