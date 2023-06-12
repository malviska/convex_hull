#include"convex_hull.hpp"
#include<iostream>

#ifndef GRAHAM_H
#define GRAHAM_H


ConvexHull * graham(Line* (*sortAlg)(Line*, int), Line * values, int size);


#endif