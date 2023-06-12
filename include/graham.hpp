#include"convex_hull.hpp"
#include<iostream>

#ifndef GRAHAM_H
#define GRAHAM_H


ConvexHull * graham(Line* (*sortAlg)(Line*, int first, int last), Line * values, int first, int last);



#endif