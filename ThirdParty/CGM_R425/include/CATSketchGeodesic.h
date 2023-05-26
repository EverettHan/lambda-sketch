#ifndef CATSketchGeodesic_H
#define CATSketchGeodesic_H
//
// COPYRIGHT DASSAULT SYSTEMES  2004

/**
* @level Protected
* @usage U1
*/ 
//#include "AdvTopoSketch.h"
#include "AdvTopoSketchLight.h"

#include "CATMathDef.h"
#include "CATSketchOperators.h"
//#include "CreateSketchGeodesic.h"
//
class CATFace;
class CATWire; 
class CATGeometry;
class CATMathVector;
class CATSurParam;
class CATCGMJournalList;
/**
  * Class defining the topological operator that creates a geodesic
  * curve from a point and a direction.
  *<ul>
  * <li>A CATSketchGeodesic operator is created with the <tt>CATCreateGeodesicPointDir</tt> global method;
  * it must be directly <tt>delete</tt>d after use. It is is not streamable. 
  * You ask for the computation by using the <tt>Run</tt> method. 
  * <li>The resulting body is retrieved with the <tt>GetResult</tt> method.
  *</ul>
  */
class ExportedByAdvTopoSketchLight CATSketchGeodesic : public CATSketchOperators
{
  CATCGMVirtualDeclareClass(CATSketchGeodesic);
  public :
  /**
  * @nodoc
  * Cannot be called. Use the <tt>CATCreateGeodesicPointDir</tt> global function
  * to create a CATSketchGeodesic operator.
  */
      CATSketchGeodesic(CATGeoFactory * iFacto,CATTopData * iData);
  /**
  * @nodoc
  * Cannot be called. Use the <tt>CATCreateGeodesicPointDir</tt> global function
  * to create a CATSketchGeodesic operator.
  */
      CATSketchGeodesic(CATGeoFactory * iFacto,CATCGMJournalList * iReport);
  /**
  * Destructor. 
  */
  virtual              ~CATSketchGeodesic()                       ;
  /**
  * Runs the operator.
  */
  virtual int          Run()                                    =0;
  /**
  * Replaces the support specified in the <tt>CATCreateGeodesicPointDir</tt> global function.
  * @param iSupport
  * The new support.
  */ 
  virtual void         ChangeSupport(CATGeometry * iSupport)    =0;
  /**
  * Replaces the point specified in the <tt>CATCreateGeodesicPointDir</tt> global function.
  * @param iPoint
  * The new point.
  */ 
  virtual void         ChangePoint  (CATGeometry * iPoint)      =0;

  /**
  * Replaces the point and support specified in the <tt>CATCreateGeodesicPointDir</tt> global function.
  * @param iSupportPoint
  * The new support.
  * @param iParam
  * The new point.
  */ 
  virtual void         ChangePoint  (CATGeometry * iSupportPoint, 
				     CATSurParam * iParam)      =0;
  /**
  * Replaces the tangent specified in the <tt>CATCreateGeodesicPointDir</tt> global function.
  * @param iTangent
  * The new tangent value.
  */ 
  virtual void         ChangeTangent(CATMathVector * iTangent)  =0;

  /**
  * Replaces the length specified in the <tt>CATCreateGeodesicPointDir</tt> global function.
  * @param iLength
  * The new length value.
  */ 
  virtual void         ChangeLength (CATPositiveLength iLength) =0;

 /**
  * @nodoc
  */ 
  virtual void         RemoveWire   ()                          =0;
};
#endif


