// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Author  : Andre LIEUTIER, Thu Oct 19 1995
// Modified: Patrick BOSINCO, Tue May 18 1999
//           CATIA version


#ifndef _CATMathPlateD2_HeaderFile
#define _CATMathPlateD2_HeaderFile

#include "MathPlate.h"
#include "CATMathVector.h"



class ExportedByMathPlate CATMathPlateD2  {

public:

 // Methods PUBLIC
 // 
 CATMathPlateD2(const CATMathVector& duu,const CATMathVector& duv,const CATMathVector& dvv);
 CATMathPlateD2(const CATMathPlateD2& ref);
	inline  const CATMathVector& DUU() const;
	inline  const CATMathVector& DVV() const;
	inline  const CATMathVector& DUV() const;



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
CATMathVector Duu;
CATMathVector Duv;
CATMathVector Dvv;
};

inline  const CATMathVector& CATMathPlateD2::DUU() const
{
	return Duu;
}
inline  const CATMathVector& CATMathPlateD2::DVV() const
{
	return Dvv;
}
inline  const CATMathVector& CATMathPlateD2::DUV() const
{
	return Duv;
}





#endif
