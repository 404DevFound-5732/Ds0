#include <stdlib.h>
#include <stdio.h>
#define PI 3.1415926135
typedef struct
{
    double r;
    double x;
    double y;
} Circle;
//构造圆
void Circlecreat(Circle *C, float r1, float x1, float y1)
{
    C->r = r1;
    C->y = y1;
    C->x = x1;
}
//面积
double Area(Circle C)
{
    return PI * C.r * C.r;
}