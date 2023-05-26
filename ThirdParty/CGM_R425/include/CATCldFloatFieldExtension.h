//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010
//==============================================================================================================
// CATCldFloatFieldExtension:
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 15-Jul-2010 - ALA - Creation.

#ifndef CATCldFloatFieldExtension_H
#define CATCldFloatFieldExtension_H


#include "ExportedByCATCloudExactPredicates.h"
#include "CATBooleanDef.h"
#include "CATCldFloatRingExtension.h"


//
//
//#include "CATM2DExactsPredicates.h"

enum  Sign
{
    NEGATIVE = -1, ZERO = 0, POSITIVE = 1,
    SMALLER = -1, EQUAL = 0, LARGER = 1
};




class ExportedByCATCloudExactPredicates CATCldFloatFieldExtension
{
public :

  /**
   * Constructors / Destructor<br>
   */
  CATCldFloatFieldExtension () ;
  CATCldFloatFieldExtension (const double iValue) ;
  CATCldFloatFieldExtension (const CATCldFloatFieldExtension & iOther) ;
  virtual ~CATCldFloatFieldExtension () ;

  boolean isPositive() const;
  boolean isNegative() const;
  /*
  * return -1,0,1 if  respectively negative, zero   or positive
  **/
  Sign sign() const;

  CATCldFloatFieldExtension operator + (const CATCldFloatFieldExtension &iOther) const ;

  CATCldFloatFieldExtension operator - (const CATCldFloatFieldExtension &iOther)  const ;

  void operator += (const CATCldFloatFieldExtension &iOther);

  void operator -= (const CATCldFloatFieldExtension &iOther);

  CATCldFloatFieldExtension operator - ()  const ;

  CATCldFloatFieldExtension operator * (const CATCldFloatFieldExtension &iOther) const ;

  CATCldFloatFieldExtension operator / (const CATCldFloatFieldExtension &iOther) const ;

// affectation operator 
  CATCldFloatFieldExtension operator = (const CATCldFloatFieldExtension &iOther);


  /**
   * comparizon operators <br>
   */
  boolean operator == (const CATCldFloatFieldExtension &iOther) const ;
  boolean operator != (const CATCldFloatFieldExtension &iOther) const ;
  boolean operator <  (const CATCldFloatFieldExtension &iOther) const ;
  boolean operator >  (const CATCldFloatFieldExtension &iOther) const ;

  // convert to double
  // operator double() const;
  // for advanced use

 void ShiftExponents(int iShift);

 int GetMaxExponent() const;

 void Normalize();

 void Approximate(); // does not change the sign



//==============================================================================================================
// Private Part.
//==============================================================================================================

private :

	ExportedByCATCloudExactPredicates friend Sign compare(const CATCldFloatFieldExtension &iV1, const CATCldFloatFieldExtension &iV2);
	ExportedByCATCloudExactPredicates friend double to_double(const CATCldFloatFieldExtension &iV1);


	// fields :

  CATCldFloatRingExtension _Numerator;
  CATCldFloatRingExtension _Denominator;
};

ExportedByCATCloudExactPredicates Sign compare(const CATCldFloatFieldExtension &iV1, const CATCldFloatFieldExtension &iV2);
ExportedByCATCloudExactPredicates double to_double(const CATCldFloatFieldExtension &iV1);

#endif

