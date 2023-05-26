// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Author  : Andre LIEUTIER, Thu Oct 19 1995
// Modified: Patrick BOSINCO, Tue May 18 1999
//           CATIA version


#ifndef _CATMathPlateD1_HeaderFile
#define _CATMathPlateD1_HeaderFile

#include "MathPlate.h"
#include "CATMathVector.h"

class ExportedByMathPlate CATMathPlateD1  {

public:

 // Methods PUBLIC
 // 
CATMathPlateD1(const CATMathVector& du,const CATMathVector& dv);
CATMathPlateD1(const CATMathPlateD1& ref);
inline  const CATMathVector& DU() const;
inline  const CATMathVector& DV() const;

protected:

 // Methods PROTECTED
 // 


 // Fields PROTECTED
 //


private: 

 // Methods PRIVATE
 // 


 // Fields PRIVATE
 //
CATMathVector Du;
CATMathVector Dv;


};

inline const CATMathVector& CATMathPlateD1::DU() const
{
  return Du;
}

 
inline const CATMathVector& CATMathPlateD1::DV() const
{
  return Dv;
}



#endif
