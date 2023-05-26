// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTrignometricUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jun 2012 Creation: nhd
//===================================================================
#ifndef CATCGMUVTrignometricUtil_h
#define CATCGMUVTrignometricUtil_h

//#include "ExportedByTessellateCommon.h"
#include "CATIAV5Level.h"
#include "CATCGMUVCachedSineValues.h"
#include "CATMathDef.h"


// This file was created to speed-up the UV cache processing...
// Here we simply store the sin values in intervals of stepForTheta.The range of angle is from 
// 0 to 5*PiBy2( 2.5Pi instead of 2Pi) to cater to cos(angle)which we represent as sin(pi/2+angle)...
//
// For obtaining the sine for the angle of a particular value, we locate the angle nearest to the 
// angle given by the user forwhich we have an accurate sine value in the table. Also, we have the 
// next accurate value given by the next value in the sineValues array.
// Then we simply interpolate linearly to get the sin of the required angle...



static unsigned long NumOfSinesStored = 1280 ;// This number is 2^10 + 2^10/4 = 1024 + 1024/4 = 1024 + 256;

static double stepForTheta = (double)(5.0*CATPIBY2) / (double)NumOfSinesStored; // Angle incremented by this amount while 
                                                                                // storing sine values


class /*ExportedByTessellateCommon*/ CATCGMUVTrignometricUtil
{

public :

 // CAUTION : The algo ASSUMES that the values of iAngle will be between 0 to 2Pi !!!
 // We did not put a check because we did not want a branch which can hit performance.
 static double FastSine(const double &iAngle);
 static double FastCos(const double &iAngle);

};
 
inline double CATCGMUVTrignometricUtil::FastSine(const double &iAngle)
{  
  // The integer part of the calculation in the line below will give us the lower index of the sin array..
  
  int TableIndex = (int)(iAngle/stepForTheta) ;
  
  // The required sine value will lie between the sinValues[TableIndex] and the sinValues[TableIndex + 1]...

  double sinResidue = (iAngle/stepForTheta - TableIndex )*(sinValues[TableIndex+1] - sinValues[TableIndex]);

  return (sinValues[TableIndex]+sinResidue);
}

inline double CATCGMUVTrignometricUtil::FastCos(const double &iAngle)
{
  return FastSine(CATPIBY2 + iAngle); // Reuse the sine calculation as cos(t) = sin( pi/2 + t)...  
}








#endif
