//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010
//==============================================================================================================
// CATCldFloatRingExtension:
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 26-Jan-2011 - DNR - Suppression du champ prive _MyExactPredicates.
// 15-Jul-2010 - ALA - Creation.
//==============================================================================================================

#ifndef CATCldFloatRingExtension_H
#define CATCldFloatRingExtension_H


#include "ExportedByCATCloudExactPredicates.h"
#include "CATBooleanDef.h"

class CATR3DAllocatorForFloatRingExtension;

//
//
//#include "CATM2DExactsPredicates.h"

class ExportedByCATCloudExactPredicates CATCldFloatRingExtension
{
public :

  /**
   * Constructors / Destructor<br>
   */
  CATCldFloatRingExtension () ;
  CATCldFloatRingExtension (const double iValue) ;
  CATCldFloatRingExtension (const CATCldFloatRingExtension & iOther) ;
  virtual ~CATCldFloatRingExtension () ;

  /**
   * Returns -> 1 if strictly Positive .<br>
   *              else Returns 0.<br>
   */
  boolean isPositive() const;
  /**
   * Returns -> 1 if  strictly Negative .<br>
   *              else Returns 0.<br>
   */
  boolean isNegative() const;
  /*
  * return -1,0,1 if  respectively negative, zero  or positive
  **/
  int sign() const;

  CATCldFloatRingExtension operator + (const CATCldFloatRingExtension &iOther) const ;

  CATCldFloatRingExtension operator - (const CATCldFloatRingExtension &iOther)  const ;

  CATCldFloatRingExtension operator - ()  const ;

  CATCldFloatRingExtension operator * (const CATCldFloatRingExtension &iOther) const ;
  //
  // affectation operator 
  CATCldFloatRingExtension operator = (const CATCldFloatRingExtension &iOther);


  /**
   * comparizon operators <br>
   */
  boolean operator == (const CATCldFloatRingExtension &iOther) const ;
  boolean operator != (const CATCldFloatRingExtension &iOther) const ;
  boolean operator <  (const CATCldFloatRingExtension &iOther) const ;
  boolean operator >  (const CATCldFloatRingExtension &iOther) const ;

  // convert to double
  operator double() const;

  void Approximate(); // does not change the sign

  int IsZero() const;


// get approximate Log in base 2
  double GetLog2() const;
  //
// the following method is not thread safe; If to be used in a multithread environnmenet, must be modified (1 allocator by thread).
static void SetMemoryAllocator(CATR3DAllocatorForFloatRingExtension *iAllocator)
{
	_Allocator = iAllocator;
}

//==============================================================================================================
// Private Part.
//==============================================================================================================

private :


// private  constructor

	CATCldFloatRingExtension (const int iSize, const double iValue);
	//
	void Release();


	// fields :

  double *_Extension ;
  int _ExtLength ;
  int _RefCount;
  //
	// static fields
  static CATR3DAllocatorForFloatRingExtension *_Allocator;
};


#endif



