// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Author  : Andre LIEUTIER, Thu Oct 19 1995
// Modified: Patrick BOSINCO, Tue May 18 1999
//           CATIA version


#ifndef _CATMathPlateD3_HeaderFile
#define _CATMathPlateD3_HeaderFile

#include "MathPlate.h"
#include "CATMathVector.h"


class ExportedByMathPlate CATMathPlateD3  {

public:

 // Methods PUBLIC
 // 
CATMathPlateD3(const CATMathVector& duuu,const CATMathVector& duuv,const CATMathVector& duvv,const CATMathVector& dvvv);
CATMathPlateD3(const CATMathPlateD3& ref);
inline  const CATMathVector& DUUU() const;
inline  const CATMathVector& DUUV() const;
inline  const CATMathVector& DUVV() const;
inline  const CATMathVector& DVVV() const;




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
CATMathVector Duuu;
CATMathVector Duuv;
CATMathVector Duvv;
CATMathVector Dvvv;
};


inline  const CATMathVector& CATMathPlateD3::DUUU() const
{
	return Duuu;
}
inline  const CATMathVector& CATMathPlateD3::DUUV() const
{
	return Duuv;
}
inline  const CATMathVector& CATMathPlateD3::DUVV() const
{
	return Duvv;
}
inline  const CATMathVector& CATMathPlateD3::DVVV() const
{
	return Dvvv;
}

#endif
