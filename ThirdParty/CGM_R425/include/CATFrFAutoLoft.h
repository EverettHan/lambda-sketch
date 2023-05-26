/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2001
//==========================================================================
//
// CATFrFAutoLoft:
// Interface class of the CATFrFAutoLoft Operator.
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// Jan. 01     Creation                       NDN
//========================================================================== 
//
#ifndef CATFrFAutoLoft_H
#define CATFrFAutoLoft_H
//
#include "PowerTopologicalOpe.h"
#include "CATTopOperator.h"
#include "ListPOfCATFace.h"
//
class CATGeoFactory;
class CATBody;
class CATShell;
class CATTopFillingInput;
class CATTopData;
class CATTopFillingReport;
//
//-----------------------------------------------------------------------------
class ExportedByPowerTopologicalOpe CATFrFAutoLoft : public CATTopOperator
{
public :
  
  virtual ~CATFrFAutoLoft() {};

  //return is diferent from 0 in case of error.
  virtual int Run() =0;

  //get pointer on report which is owned by the operator.
  virtual const CATTopFillingReport * GetReport () =0;
  
protected :
  
  /** @nodoc */
  CATFrFAutoLoft(CATGeoFactory* iFactory, CATTopData* iTopData)
    :CATTopOperator(iFactory,iTopData)
  {};
  
};

//-----------------------------------------------------------------------------
ExportedByPowerTopologicalOpe  
CATFrFAutoLoft * CATCreateFrFAutoLoft(CATGeoFactory * Factory,
                                      CATTopData * iTopData,
                                      CATBody * iCreationBody,
                                      CATShell * iCreationShell,
                                      CATTopFillingInput * iInput);

#endif
