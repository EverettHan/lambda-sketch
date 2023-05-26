#ifndef CATICldContact_h
#define CATICldContact_h


#include <string.h>
#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathPoint ;
class CATMathVector ;


 class CATICldContact : public CATBaseUnknown
 {
 public :

   // This methode give if a contact of order <iorder> is defined
   virtual  short  HasContact( const int iIndex, const short iorder, 
	                            CATBoolean * oHasContact) const =0;
   
    ///virtual short OrderMax()const = 0 ;

   // This methode give the contact type of order <iorder> 
   virtual  short  IsGeometricalContact(const short iorder, 
	                                    CATBoolean * oIsGeometricalContact) const =0;

   //These methodes returns the values contact 
   /*virtual  CATLONG32 D0(CATMathPoint * oP) = 0;
   virtual  CATLONG32 D1(CATMathPoint * oP,
                       CATMathVector * oD1u, CATMathVector * oD1v) = 0;
   virtual  CATLONG32 D2(CATMathPoint * oP,
                       CATMathVector * oD1u, CATMathVector * oD1v,
                       CATMathVector * oD2u, CATMathVector * oD2v, 
					   CATMathVector * oD2uv) const =0;*/



   // These methodes gives tolerances associated with the contact 
   virtual  short ToleranceG0(int iIndex, double & oTolG0) const =0;
   virtual  short ToleranceG1(int iIndex, double & oTolG1) const =0;
   virtual  short ToleranceG2(int iIndex, double & oTolG2) const =0;

   virtual  short D0(int iIndex, CATMathPoint * oP) const = 0;
   virtual  short D1(int iIndex, CATMathPoint * oP,
                       CATMathVector * oD1u, CATMathVector * oD1v)  const = 0;
   virtual  short D2(int iIndex, CATMathPoint * oP,
                       CATMathVector * oD1u, CATMathVector * oD1v,
                       CATMathVector * oD2u, CATMathVector * oD2v, 
					   CATMathVector * oD2uv) const = 0;

   virtual int GetNumberOfPoints( ) const = 0;
   virtual double ConstraintsRatioToSatisfied( ) const = 0;

   virtual CATBoolean IsAKindOf(const char * iType);

	virtual int  SetIsFilterable( int iIdx, const CATBoolean &iIsFilterable )= 0;
	virtual int  GetIsFilterable( int iIdx, CATBoolean & oIsFilterable  ) const = 0;
	//
	virtual int  SetIsFiltered( int iIdx, const CATBoolean & iIsFiltered ) = 0;
	virtual int  GetIsFiltered(  int iIdx, CATBoolean & oIsFiltered ) const = 0;
	//
	virtual CATBoolean IsFree(int iIdx)const=0;



 };
 
inline CATBoolean CATICldContact::IsAKindOf(const char * iType)
{
   if(NULL==iType) return 0;
   else return !(strcmp(iType, "CATICldContact"));
}

#endif
