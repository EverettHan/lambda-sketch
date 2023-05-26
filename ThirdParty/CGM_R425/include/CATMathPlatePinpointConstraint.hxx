// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Author  : Andre LIEUTIER, Thu Oct 19 1995
// Modified: Patrick BOSINCO, Tue May 18 1999
//           CATIA version


#ifndef _CATMathPlatePinpointConstraint_HeaderFile
#define _CATMathPlatePinpointConstraint_HeaderFile

#include "MathPlate.h"

#include "CATMathVector.h"
#include "CATMathPoint2D.h"


class ExportedByMathPlate CATMathPlatePinpointConstraint  {

public:

 // Methods PUBLIC
 // 
 CATMathPlatePinpointConstraint();
 CATMathPlatePinpointConstraint(const CATMathPoint2D& point2d,const CATMathVector& ImposedValue,const int iu = 0,const int iv = 0);
 inline   CATMathPoint2D& ChangePnt2d() ;
 inline   CATMathVector& ChangeValue() ;
 inline  const CATMathPoint2D& Pnt2d() const;
 inline  int Idu() const;
 inline  int Idv() const;
 inline  int& ChangeIdu();
 inline  int& ChangeIdv();
 inline  const CATMathVector& Value() const;


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
CATMathVector value;
CATMathPoint2D pnt2d;
int idu;
int idv;
};


inline  CATMathPoint2D& CATMathPlatePinpointConstraint::ChangePnt2d()
{
  return pnt2d;
}

inline  const CATMathPoint2D& CATMathPlatePinpointConstraint::Pnt2d() const
{
  return pnt2d;
}

 
inline  int CATMathPlatePinpointConstraint::Idu() const
{
  return idu;
}

 
inline  int CATMathPlatePinpointConstraint::Idv() const
{
  return idv;
}

inline  int& CATMathPlatePinpointConstraint::ChangeIdu()
{
  return idu;
}

 
inline  int& CATMathPlatePinpointConstraint::ChangeIdv()
{
  return idv;
}

 
inline  CATMathVector& CATMathPlatePinpointConstraint::ChangeValue()
{
  return value;
}
 
inline  const CATMathVector& CATMathPlatePinpointConstraint::Value() const
{
  return value;
}

#endif
