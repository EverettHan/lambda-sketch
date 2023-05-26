// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : AJT1
//
// DESCRIPTION  : Operator to find closed fillet ribbons
//
//=============================================================================
#ifndef CATClosedFilletRibbonFinder_H
#define CATClosedFilletRibbonFinder_H

#include "AdvOpeInfra.h"
#include "CATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATCGMNewArray.h"
#include "CATCGMOperator.h"
#include "CATDeclarativeApplication.h"
#include "CATDeclarativeContext.h"
#include "CATLISTV_CATMathPoint.h"
#include "ListPOfCATVertex.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATClosedFilletRibbonFinder;
class CATClosedFilletRibbonFinderImpl;

//----------------------------------------------------------------------------
// Public section
//----------------------------------------------------------------------------
/** 
* Creates a CATClosedFilletRibbonFinder operator.
* @param iFactory
* Factory in which objects may be created.
* @param iConfig
* CATSoftwareConfiguration to manage upward compatibility of changes in the implementation.
* @param iBody
* Body to be analyzed. 
* @return [out, delete]
*/
ExportedByAdvOpeInfra CATClosedFilletRibbonFinder* CATCreateClosedFilletRibbonFinder(CATGeoFactory &iFactory, CATSoftwareConfiguration &iConfig, CATBody &iBody);

class ExportedByAdvOpeInfra CATClosedFilletRibbonFinder : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATClosedFilletRibbonFinder);

public:

  virtual ~CATClosedFilletRibbonFinder();

  /**
  * Set DeclarativeApplication
  */
  void SetDeclarativeApplication(CATDeclarativeApplication iDeclarativeApplication);

  /**
  * Set industry for DeclarativeContext
  * if not specified, industry is selected using DRepIndustryAssistant (running time nearly x2)
  */
  void SetDeclarativeContextIndustry(CATDeclarativeContextIndustry iIndustry);
  
  
  /**
  * Activate the extremity points calculation
  */
  void ActivateExtremitiesCalculation(CATBoolean iExtrem);
  
  
  /**
  * Activate the curvature change finder
  */
  void ActivateCurvatureChange(CATBoolean iCurvat);

  /**
  * Returns the number of closed fillet ribbons detected
  */
  int GetNumberOfClosedFilletRibbons();

  /**
  * Returns S_OK if the corresponding closed ribbon was found
  * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon to retrieve
  * <br> oClosedRibbonFaces : Faces of the closed fillet ribbon to retrieve
  */
  HRESULT GetClosedFilletRibbonFaces(int iRibbon, ListPOfCATFace &oClosedRibbonFaces);

  /**
  * Returns the number of external fillets crossed by a closed ribbon
  * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon
  */
  int GetNumberOfCrossedFillets(int iRibbon);

  /**
  * Returns S_OK if the corresponding closed ribbon and crossed fillet was found
  * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon
  * <br> iCrossedFillet : Index (from 1 to NumberOfCrossedFillets(iRibbon)) of the crossed fillet
  * <br> oCrossedFilletContactEdges : Contact edges between the closed ribbon and the crossed fillet
  */
  HRESULT GetCrossedFilletContactEdges(int iRibbon, int iCrossedFillet, ListPOfCATEdge &oCrossedFilletContactEdges);

  //Added for extremity points

  /**
  * Returns the number of extremity points
  * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon
  */
  int GetNumberOfExtremityPoints(int iRibbon);

  /**
 * Returns S_OK if the corresponding closed ribbon and extremity points were found
 * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon
 * <br> oExtremityPoints : list of extremity points
 */
  HRESULT GetExtremityPoints(int iRibbon, CATListValCATMathPoint& oExtremityPoints);

  //Added for curvature change vertices

  /**
  * Returns the number of curvature vertices
  * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon
  */
  int GetNumberOfCurvatureVertices(int iRibbon);

  /**
 * Returns S_OK if the corresponding closed ribbon and Curvature Vertices were found
 * <br> iRibbon : Index (from 1 to NumberOfClosedFilletRibbons) of the closed fillet ribbon
 * <br> oCurvatureVertices : list of Curvature Vertices
 */
  HRESULT GetCurvatureVertices(int iRibbon, ListPOfCATVertex& oCurvatureVertices);

  //----------------------------------------------------------------------------
  // Private section
  //----------------------------------------------------------------------------
  /** @nodoc @nocgmitf */
  CATClosedFilletRibbonFinder(CATClosedFilletRibbonFinderImpl *iImpl, CATGeoFactory &iFactory);
  /** @nodoc @nocgmitf */
  CATCGMNewClassArrayDeclare; // Pool allocation

private:
  int RunOperator(); // for CGMReplay

  // prevent usage of copy constructor and equal operator
  CATClosedFilletRibbonFinder(const CATClosedFilletRibbonFinder& iToCopy);
  CATClosedFilletRibbonFinder & operator=(const CATClosedFilletRibbonFinder& iToCopy);
};

//----------------------------------------------------------------------------

#endif
