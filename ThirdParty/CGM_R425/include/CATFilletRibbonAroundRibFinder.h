// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : JQS
//
// DESCRIPTION  : Operator to obtain ribbon propagation from selected face
//
//=============================================================================
#ifndef CATFilletRibbonAroundRibFinder_H
#define CATFilletRibbonAroundRibFinder_H

#include "AdvOpeInfra.h"
#include "CATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATCGMNewArray.h"
#include "CATCGMOperator.h"
#include "CATDeclarativeApplication.h"
#include "CATDeclarativeContext.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFilletRibbonAroundRibFinder;
class CATFilletRibbonAroundRibFinderImpl;

//----------------------------------------------------------------------------
// Public section
//----------------------------------------------------------------------------
/** 
* Creates a CATRibbonPropagationFinder operator.
* @param iFactory
* Factory in which objects may be created.
* @param iConfig
* CATSoftwareConfiguration to manage upward compatibility of changes in the implementation.
* @param iBody
* Body to be analyzed. 
* @return [out, delete]
*/
ExportedByAdvOpeInfra CATFilletRibbonAroundRibFinder* CATCreateFilletRibbonAroundRibFinder(CATGeoFactory &iFactory, CATSoftwareConfiguration &iConfig, CATBody &iBody);

class ExportedByAdvOpeInfra CATFilletRibbonAroundRibFinder : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATFilletRibbonAroundRibFinder);

public:

  virtual ~CATFilletRibbonAroundRibFinder();

  /**
  * Set selected faces from which the propagation should be started
  */
  //void SetSelectionFaces(ListPOfCATFace iSelectionFaces);

  /**
   * Returns S_OK if the corresponding faces were found
   * oTriTangentFaces: list of TriTangent faces found in given body
   */
  HRESULT GetListOfTriTangentFaces(ListPOfCATFace &oTriTangentFaces);

  /**
  * Returns S_OK if the corresponding faces were found
  * oBiTangentFaces: list of BiTangent faces found in given body
  */
  HRESULT GetListOfBiTangentFaces(ListPOfCATFace& oBiTangentFaces);

  /**
  * Returns S_OK if the corresponding faces were found
  * oFlatTopFaces: list of flat top faces found in given body
  */
  HRESULT GetListOfFlatTopFaces(ListPOfCATFace& oFlatTopFaces);


  /**
  * Returns S_OK if the corresponding direction was found for given face
  * oDirectionOfFace: direction of rolling ball for given fillet face
  */
  HRESULT GetDirectionOfFilletFace(CATFace* iFace, CATMathVector& oDirectionOfFace);
  //----------------------------------------------------------------------------
  // Private section
  //----------------------------------------------------------------------------
  /** @nodoc @nocgmitf */
  CATFilletRibbonAroundRibFinder(CATFilletRibbonAroundRibFinderImpl *iImpl, CATGeoFactory &iFactory);
  /** @nodoc @nocgmitf */
  CATCGMNewClassArrayDeclare; // Pool allocation

private:
  int RunOperator(); // for CGMReplay

};

//----------------------------------------------------------------------------

#endif
