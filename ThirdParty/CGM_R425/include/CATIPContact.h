#ifndef CATIPContact_h
#define CATIPContact_h

#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathPoint ;
class CATMathVector ;


 class CATIPContact : public CATBaseUnknown
 {
 public :

   // This methode give if a contact of order <iorder> is defined
   virtual  CATLONG32  HasContact(const short iorder, 
	                            CATBoolean * oHasContact) const =0;

   // This methode give the contact type of order <iorder> 
   virtual  CATLONG32  IsGeometricalContact(const short iorder, 
	                                      CATBoolean * oIsGeometricalContact) const =0;

	 // This methode give the priority level of the contact
	 virtual CATLONG32   GetLevelPriority() const =0;

   //These methodes returns the values contact 
   virtual  CATLONG32 D0(CATMathPoint * oP) = 0;
   virtual  CATLONG32 D1(CATMathPoint * oP,
                       CATMathVector * oD1u, CATMathVector * oD1v) = 0;
   virtual  CATLONG32 D2(CATMathPoint * oP,
                       CATMathVector * oD1u, CATMathVector * oD1v,
                       CATMathVector * oD2u, CATMathVector * oD2v, 
					   CATMathVector * oD2uv) const =0;

   // These methodes gives tolerances associated with the contact 
   virtual  CATLONG32 ToleranceG0(double * oTolG0) const =0;
   virtual  CATLONG32 ToleranceG1(double * oTolG1) const =0;
   virtual  CATLONG32 ToleranceG2(double * oTolG2) const =0;
 };
#endif
