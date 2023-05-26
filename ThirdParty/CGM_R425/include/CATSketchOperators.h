#ifndef CATSketchOperators_H
#define CATSketchOperators_H
//
// COPYRIGHT DASSAULT SYSTEMES  2004

/**
* @level Protected
* @usage U1
*/ 
//#include "AdvTopoSketch.h"
#include "AdvTopoSketchLight.h"
#include "CATMathDef.h"
#include "CATTopOperator.h"

//
class CATBody;
class CATWire;
class CATCGMJournalList;
/**
  * Parent class of CATSketchGeodesic.
  * @see CATSketchGeodesic.
  */
class ExportedByAdvTopoSketchLight CATSketchOperators : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSketchOperators);
  public :
/**
  * @nodoc
  */
                      CATSketchOperators(CATGeoFactory * iFacto,CATTopData * iData);
  /**
  * @nodoc
  */
                      CATSketchOperators(CATGeoFactory * iFacto,CATCGMJournalList * iReport);
  virtual              ~CATSketchOperators()                     ;
 /**
  * Retrieve the geodesic curve.
  * @param oBody
  * The geodesic curve.
  */
  virtual void         GetResult(CATBody *& oBody)             =0;
/**
  * @nodoc
  */
  virtual CATLONG32         GetNumberOfResults()              const =0;
  /**
  * @nodoc
  */
  virtual void         BeginningResult()                       =0;
  /**
  * @nodoc
  */
  virtual CATBoolean   NextResult()                            =0;
  /**
  * Retrieves the created wire.
  * @param iWire
  * The geodesic wire.
  */
  virtual void         GetWire(CATWire *& iWire)         const =0;
};
#endif




