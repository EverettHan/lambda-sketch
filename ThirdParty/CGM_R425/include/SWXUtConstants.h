#ifndef SWXUtConstants_H
#define SWXUtConstants_H

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef M_PI
    const double PI = M_PI;
#else
    const double PI = 3.14159265358979323846;
#endif

const double SWXUtToRadianFactor = PI/180.0;
const double SWXUtToDegreeFactor = 180.0/PI;
	
inline double SWXToRadian(double iAngleInDegrees)
{
	return iAngleInDegrees * SWXUtToRadianFactor;
}


inline double SWXToDegree(double iAngleInRadian)
{
	return iAngleInRadian * SWXUtToDegreeFactor;
}

#endif
