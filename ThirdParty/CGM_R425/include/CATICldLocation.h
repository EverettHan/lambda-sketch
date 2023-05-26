#ifndef CATICldLocation_h
#define CATICldLocation_h

#include <string.h>

#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathPoint;
class CATMathPoint2D;


class CATICldLocation : public CATBaseUnknown
{
public :

   virtual int Set2D( int iIndex, double  iU, double iV) =0;
   virtual int  Get2D( int iIndex, double & oU, double & oV, CATBoolean & oIsDefined ) const =0;
   
   virtual int SetPoint( int Index, double iX, double iY, double iZ) =0;
   virtual int GetPoint( int Index, double& oX, double& oY, double& oZ, CATBoolean & oIsDefined ) const =0;

   virtual int ResetUV() = 0;


   //virtual short Set2D( int iNumberOfUV, const double * iUV ) = 0;
   ////virtual short SetUV( int Index, double iU, double iV ) = 0;
   
   //virtual short SetPoints( int iNumberOfUV, const double * iXYZ) = 0;
   ////virtual short SetPunctual(double iX, double iY, double iZ) = 0;      
      
   ///virtual const double * Get2D() const = 0;
   //virtual short GetUV( int iIndex, double & oU, double & oV ) const = 0;
   //virtual const double * GetPoints() const  = 0;
   //virtual short GetPoint( int Index, double& oX, double& oY, double& oZ) const = 0;


   virtual CATBoolean IsAKindOf(const char * iType){
      if(NULL==iType) return 0;
      else return !(strcmp(iType, "CATICldLocation")); 
   }

};
#endif
