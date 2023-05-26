
#ifndef _CATMathMarshMetric_HeaderFile
#define _CATMathMarshMetric_HeaderFile
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U6
*/


#include "MathMarsh.h"


#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATMathBox.h"

class ExportedByMathMarsh CATMathMarshMetric

{
public :

  class Accelerator 
  {
  public :
    virtual ~Accelerator() {};
  protected :
    Accelerator() {};

  };


  void AddRef() const;

	/**
	* Decrements the reference count for the given interface. 
	* @return The reference count value.
	* <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
	*/
	void Release () const;

	/**
	* Determines whether the given object's class derives from a given class.
	* @param iName
	*   The class name from which the given object's class is supposed to derive.
	* @return 0 if the given object's class doesn't derive from <tt>iName</tt>
	* and a non null value otherwise.
	* @return
	* <br><b>Legal values</b>:
	*   <dl>
	*     <dt>0 </dt>
	*        <dd>Current onject does not derive from iName.</dd>
	*     <dt>1 </dt>
	*        <dd>Otherwise.</dd>
	*   </dl>
	*/
  //CATBoolean  IsAKindOf(const char *iName) const;

  virtual int EvalMetric(const CATMathVector& iP1, const CATMathVector& iP2, CATMathVector& oDiffMetric, const Accelerator* iAccelerator = NULL, const int iNum = -1, bool inUserSpace = false) const = 0;

  //Wrapper on CATMathPoint
  int EvalMetric(const CATMathPoint& iP1, const CATMathPoint& iP2, CATMathVector& oDiffMetric, const Accelerator* iAccelerator = NULL, const int iNum = -1, bool inUserSpace = false) const;
 

  virtual int AddPSourcePoint(const CATMathPoint& iPnt);

  virtual void SetNormalization(const CATMathVector& iCenterNormalization, const double iRatioNormalization);

  virtual void SetBox(const CATMathBox& iBox) {};


  virtual Accelerator* NewAccelerator(const CATMathVector& iPnt, const int iNum = -1) { return NULL; }
  //virtual Accelerator* GetAccelerator(const CATMathVector& iPnt) { return NULL; }

  
  int CheckMetric(const CATMathBox& iBox, const int iNbCheck);
  
#ifdef MarshMetricAvailable
/**
* CreateConstMetric
* <br><b>Role</b>: 
* @param iMatrix
* 
* @return [out, IUnknown#Release]
* 
*/
static CATMathMarshMetric* CreateConstMetric(CATMath3x3Matrix& iMatrix);
#endif

protected :

  CATMathMarshMetric();
  virtual ~CATMathMarshMetric();

private:
  mutable int _Count;


};



#endif
