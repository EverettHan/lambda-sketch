/* -*-c++-*- */
#ifndef CATTopCrvToNurbsCrvOperatorProtected_h
#define CATTopCrvToNurbsCrvOperatorProtected_h
/**
 * @quickReview JSX 30:09:2021
 */
//COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================
// Author : Jean SALOUX Date : 25/11/2020
// Class CATTopCrvToNurbsCrvOperatorProtected : 
//    add some method to the caa public interface CATTopCrvToNurbsCrvOperator
//
// 30/09/2021 SME31 : ICEM:IR-875164 Interface to query Deviations and IsExactTransformation for multiple edge
//===================================================================

#include "CATTopCrvToNurbsCrvOperator.h"


class ExportedByBasicTopology CATTopCrvToNurbsCrvOperatorProtected : public CATTopCrvToNurbsCrvOperator
{
  CATCGMVirtualDeclareClass(CATTopCrvToNurbsCrvOperatorProtected);
//-------------------------------------------------------------------
public :
//-------------------------------------------------------------------

  // contructor
  CATTopCrvToNurbsCrvOperatorProtected(CATGeoFactory * iFactory,
                                       CATTopData    * iTopData);

  // destructor
  virtual ~CATTopCrvToNurbsCrvOperatorProtected();



  //
  // ADVANCED mode settings
  //-----------------------
  //
  // The following setting methods follow the creation of a CATTopCrvToNurbsCrvOperator,
  // (see CATCreateTopCrvToNurbsCrvOperator global function)
  //
  
  /**
  * Defines the parametrization option.
  * @param iOtionOfParametrization
  * The option value. By default, set to the 0 .
  *   = 0 The Parametrization is not changed
  *   = 1 The resulting parametization is curvilinear (Only for modified curves)
  *   = 2 The resulting parametrization can be changed by the operator ( depending of degre or other parmeter)
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 SetParametrizationOption(CATLONG32 iOtionOfParametrization)=0;
  

// ICEM:IR-875164 Interface to query Deviations and IsExactTransformation for multiple edges
  /**
  * Retrieves whether the created curve has been approximated for a list of curves.
  * <br>To be called after the <tt>Run</tt> method.
  * @param ioIsExactList
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 IsExactTransformationForEdgeList(CATListOfInt& ioIsExactList) = 0;

  /**
  * Retrieves max deviation for edges for a list of edges.
  * <br>To be called after the <tt>Run</tt> method.
  * @param ioDeviations
  * @return
  * Not null in case of error.
  */
  virtual CATLONG32 GetDeviationsForEdgeList(CATListOfDouble& ioDeviations) = 0;
};


//
//ExportedByBasicTopology CATTopCrvToNurbsCrvOperatorProtected*
//CATCreateTopCrvToNurbsCrvOperatorProtected(CATGeoFactory* iFactory,
//    CATTopData* iTopData,
//    CATBody* iWireBody,
//    CATCell* iEdgeCell);
//
//ExportedByBasicTopology CATTopCrvToNurbsCrvOperatorProtected*
//CATCreateTopCrvToNurbsCrvOperatorProtected(CATGeoFactory* iFactory,
//    CATTopData* iTopData,
//    CATBody* iWireBody,
//    CATLISTP(CATEdge)* iEdgeList);

#endif
