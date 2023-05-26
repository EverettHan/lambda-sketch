//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010
//==============================================================================================================
// CATCldInterval:
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 13-Jul-2010 - DNR - Creation.
//==============================================================================================================

#ifndef CATCldInterval_H
#define CATCldInterval_H

#include "ExportedByCATCloudExactPredicates.h"
#include "CATBooleanDef.h"
#include "CATCldRounding.h"
#include <float.h>
#include <stdio.h>
//#define RoundingDEBUG

class ExportedByCATCloudExactPredicates CATCldInterval
{

//==============================================================================================================
// Public Part.
//==============================================================================================================

public :

  /**
   * Constructors / Destructor<br>
   */
  inline CATCldInterval () ;
  inline CATCldInterval (const double iValue) ;
  inline CATCldInterval (const double iValMin, const double iValMax) ;
  inline CATCldInterval (const CATCldInterval & iInterval) ;
  inline virtual ~CATCldInterval () ;

  /**
   * Returns -> 1 if the interval is strictly Positive ie its minimum Value is strictlypositive.<br>
   *              else Returns 0.<br>
   */
  inline int isPositive() const;
  /**
   * Returns -> 1 if the interval is strictly Negative ie its maximum Value is strictlynegative.<br>
   *              else Returns 0.<br>
   */
  inline int isNegative() const;
  /*
  * return -1,0,1 if the interval is respectively negative, zero (i.e. contain 0)  or positive
  **/
  inline int sign() const;
  /**
   * Returns the interval updated after addition.<br>
   */
  inline CATCldInterval operator + (const CATCldInterval &iInterval) const;
  inline void operator += (const CATCldInterval &iInterval);

  /**
   * Returns the interval updated after subtraction.<br>
   */
  inline CATCldInterval operator - (const CATCldInterval &iInterval) const;
  inline void operator -= (const CATCldInterval &iInterval);
  inline CATCldInterval operator - ()  const;


  /**
   * Returns the interval updated after multiplication.<br>
   */
  CATCldInterval operator * (const CATCldInterval &iInterval) const;

  /**
   * Returns the interval updated after division.<br>
   */
  CATCldInterval operator / (const CATCldInterval &iInterval) const;
  /**
   * comparizon operators <br>
   */
  inline boolean operator < (const CATCldInterval & iInterval) const;
  inline boolean operator > (const CATCldInterval & iInterval) const;
  inline boolean operator != (const CATCldInterval & iInterval) const;

  // convert to double
  //inline operator double() const;

  inline void SetMinMax (const double iMinValue, const double iMaxValue);
  inline void GetMinMax (double& oMinValue, double& oMaxValue) const ;

  inline double sup() const;
  inline double inf() const;
  inline boolean do_overlap (const CATCldInterval & iInterval) const;

  void error() const {
    fprintf(stdout,"Min > Max\n");
  }


//==============================================================================================================
// Private Part.
//==============================================================================================================

private :

  ExportedByCATCloudExactPredicates friend int compare(const CATCldInterval &iI1, const CATCldInterval &I2);
  ExportedByCATCloudExactPredicates friend double to_double(const CATCldInterval & iInterval);

  double _MinValue ;  // Lower bound
  double _MinusMaxValue ; // min Upper Bound


} ;


//-----------------------------------------------------------------------------
// CATCldInterval : constructor
//-----------------------------------------------------------------------------
CATCldInterval::CATCldInterval() :
_MinValue  (0.),
_MinusMaxValue  (0.)
{
}

//-----------------------------------------------------------------------------
// CATCldInterval : constructor
//-----------------------------------------------------------------------------
CATCldInterval::CATCldInterval(const double iValue) :
_MinValue  (iValue),
_MinusMaxValue  (-iValue)
{
}

//-----------------------------------------------------------------------------
// CATCldInterval : constructor
//-----------------------------------------------------------------------------
CATCldInterval::CATCldInterval(const double iValMin, const double iValMax) :
_MinValue  (iValMin),
_MinusMaxValue  (-iValMax)
{
}


//-----------------------------------------------------------------------------
// CATCldInterval : constructor
//-----------------------------------------------------------------------------
CATCldInterval::CATCldInterval(const CATCldInterval & iInterval) :
_MinValue  (iInterval._MinValue),
_MinusMaxValue  (iInterval._MinusMaxValue)
{
}

//-----------------------------------------------------------------------------
// CATCldInterval : destructor
//-----------------------------------------------------------------------------
CATCldInterval::~CATCldInterval()
{
}


//-----------------------------------------------------------------------------
// CATCldInterval : isPositive
//-----------------------------------------------------------------------------
int CATCldInterval::isPositive() const
{
  return (_MinValue > 0.) ? 1 : 0;
}

//-----------------------------------------------------------------------------
// CATCldInterval : isNegative
//-----------------------------------------------------------------------------
int CATCldInterval::isNegative() const
{
  return (_MinusMaxValue > 0.) ? 1 : 0;
}

//-----------------------------------------------------------------------------
// CATCldInterval : sign
//-----------------------------------------------------------------------------
int CATCldInterval::sign() const
{
   return (_MinusMaxValue > 0.) ? -1 : (_MinValue > 0.) ? 1 : 0;
}

//-----------------------------------------------------------------------------
// CATCldInterval : Addition
//-----------------------------------------------------------------------------
inline CATCldInterval CATCldInterval::operator + (const CATCldInterval & iInterval) const
{
  CATCldRounding::SetMinusInfinityMode();
#ifdef CheckRounding
  CATCldRounding::CheckRoundingForInterval();
#endif
  CATCldInterval Res;
  if (_MinusMaxValue == DBL_MAX || iInterval._MinusMaxValue == DBL_MAX ) {
    // si l'un des operandes n'est pas valide le resultat ne l'est pas non plus. 
    Res._MinValue = -DBL_MAX;
    Res._MinusMaxValue = DBL_MAX;
  } else {
    Res._MinValue = _MinValue + iInterval._MinValue;
    Res._MinusMaxValue = _MinusMaxValue + iInterval._MinusMaxValue;
  }
  if (Res._MinValue > -Res._MinusMaxValue) {
    error();
  }
  return Res;
}

//-----------------------------------------------------------------------------
// CATCldInterval : Addition
//-----------------------------------------------------------------------------
void CATCldInterval::operator += (const CATCldInterval & iInterval)
{
  CATCldRounding::SetMinusInfinityMode();
#ifdef CheckRounding
  CATCldRounding::CheckRoundingForInterval();
#endif
  if (_MinusMaxValue == DBL_MAX || iInterval._MinusMaxValue == DBL_MAX ) {
    // si l'un des operandes n'est pas valide le resultat ne l'est pas non plus. 
    _MinValue = -DBL_MAX;
    _MinusMaxValue = DBL_MAX;
  } else {
    _MinValue = _MinValue + iInterval._MinValue;
    _MinusMaxValue = _MinusMaxValue + iInterval._MinusMaxValue;
  }
  if (_MinValue > -_MinusMaxValue) {
        error();

  }
}
//-----------------------------------------------------------------------------
// CATCldInterval : Soustraction
//-----------------------------------------------------------------------------
  CATCldInterval CATCldInterval::operator - (const CATCldInterval & iInterval) const
{
  CATCldRounding::SetMinusInfinityMode();
#ifdef CheckRounding
  CATCldRounding::CheckRoundingForInterval();
#endif
  CATCldInterval Res;
  if (_MinusMaxValue == DBL_MAX || iInterval._MinusMaxValue == DBL_MAX ) {
    // si l'un des operandes n'est pas valide le resultat ne l'est pas non plus. 
    Res._MinValue = -DBL_MAX;
    Res._MinusMaxValue = DBL_MAX;
  } else {
    Res._MinValue = _MinValue + iInterval._MinusMaxValue;
    Res._MinusMaxValue = _MinusMaxValue + iInterval._MinValue;
  }
  if (Res._MinValue > -Res._MinusMaxValue) {
    
        error();

  }
  return Res;
}


//-----------------------------------------------------------------------------
// CATCldInterval : Soustraction
//-----------------------------------------------------------------------------
void CATCldInterval::operator -= (const CATCldInterval & iInterval)
{
  CATCldRounding::SetMinusInfinityMode();
#ifdef CheckRounding
  CATCldRounding::CheckRoundingForInterval();
#endif
  if (_MinusMaxValue == DBL_MAX || iInterval._MinusMaxValue == DBL_MAX ) {
    // si l'un des operandes n'est pas valide le resultat ne l'est pas non plus. 
    _MinValue = -DBL_MAX;
    _MinusMaxValue = DBL_MAX;
  } else {
    _MinValue = _MinValue + iInterval._MinusMaxValue;
    _MinusMaxValue = _MinusMaxValue + iInterval._MinValue;
  }
  if (_MinValue > -_MinusMaxValue) {
    error();
  }
}



//-----------------------------------------------------------------------------
// CATCldInterval : operator <
//-----------------------------------------------------------------------------
boolean CATCldInterval::operator < (const CATCldInterval & iInterval) const
{
   return (-_MinusMaxValue < iInterval._MinValue) ? TRUE : FALSE;
}

//-----------------------------------------------------------------------------
// CATCldInterval : operator >
//-----------------------------------------------------------------------------
boolean CATCldInterval::operator > (const CATCldInterval & iInterval) const
{
   return (_MinValue > -iInterval._MinusMaxValue) ? TRUE : FALSE;
}

//-----------------------------------------------------------------------------
// CATCldInterval : division
//-----------------------------------------------------------------------------
boolean CATCldInterval::operator != (const CATCldInterval & iInterval) const
{
  return (-_MinusMaxValue < iInterval._MinValue) ? TRUE : 
         (_MinValue > -iInterval._MinusMaxValue) ? TRUE : FALSE;

}


//-----------------------------------------------------------------------------
// CATCldInterval : division
//-----------------------------------------------------------------------------
//CATCldInterval::operator double() const
//{
//  return ((_MinValue - _MinusMaxValue)*.5);
//}

//-----------------------------------------------------------------------------
// CATCldInterval : division
//-----------------------------------------------------------------------------
void CATCldInterval::SetMinMax (const double iMinValue, const double iMaxValue)
{
  _MinValue = iMinValue;
  _MinusMaxValue = -iMaxValue;
}


//-----------------------------------------------------------------------------
// CATCldInterval : division
//-----------------------------------------------------------------------------
void CATCldInterval::GetMinMax (double& oMinValue, double& oMaxValue) const
{
  oMinValue = _MinValue;
  oMaxValue = -_MinusMaxValue;
}


//-----------------------------------------------------------------------------
// CATCldInterval : sup
//-----------------------------------------------------------------------------
double CATCldInterval::sup () const
{
  return -_MinusMaxValue;
}

//-----------------------------------------------------------------------------
// CATCldInterval : division
//-----------------------------------------------------------------------------
double CATCldInterval::inf () const
{
  return _MinValue;
}

//-----------------------------------------------------------------------------
// CATCldInterval : division
//-----------------------------------------------------------------------------
boolean CATCldInterval::do_overlap (const CATCldInterval & iInterval) const
{
  if (_MinValue > -_MinusMaxValue) {
    error();
  }
  return (-_MinusMaxValue < iInterval._MinValue) ? FALSE : 
         (_MinValue > -iInterval._MinusMaxValue) ? FALSE : TRUE;
}


//-----------------------------------------------------------------------------
// CATCldInterval : unary minus
//-----------------------------------------------------------------------------

CATCldInterval CATCldInterval::operator - ()  const
{
  CATCldInterval Res;
    Res._MinValue = _MinusMaxValue;
    Res._MinusMaxValue = _MinValue;
  return Res;
}
//////////////////////////////

ExportedByCATCloudExactPredicates int compare(const CATCldInterval &iV1, const CATCldInterval &iV2);
ExportedByCATCloudExactPredicates double to_double(const CATCldInterval & iInterval);


#endif
