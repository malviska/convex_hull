#ifndef GRAHAM_H
#define GRAHAM_H
#include"convex_hull.hpp"
#include<iostream>


ConvexHull * graham(Line* (*sortAlg)(Line*, int first, int last), Line * values, int first, int last);



#endif