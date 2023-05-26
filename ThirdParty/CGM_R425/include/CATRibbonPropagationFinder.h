// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : JQS
//
// DESCRIPTION  : Operator to obtain ribbon propagation from selected face
//
//=============================================================================
#ifndef CATRibbonPropagationFinder_H
#define CATRibbonPropagationFinder_H

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
class CATRibbonPropagationFinder;
class CATRibbonPropagationFinderImpl;

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
ExportedByAdvOpeInfra CATRibbonPropagationFinder* CATCreateRibbonPropagationFinder(CATGeoFactory &iFactory, CATSoftwareConfiguration &iConfig, CATBody &iBody);

class ExportedByAdvOpeInfra CATRibbonPropagationFinder : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATRibbonPropagationFinder);

public:

  virtual ~CATRibbonPropagationFinder();

  /**
  * Set selected faces from which the propagation should be started
  */
  void SetSelectionFaces(ListPOfCATFace iSelectionFaces);

  /**
  * Returns S_OK if the corresponding porpagation faces were found
  * oPropagationFaces: list of faces found by propagation for selected faces
  */
  HRESULT GetListOfPropagationFaces(ListPOfCATFace &oPropagationFaces);

  //----------------------------------------------------------------------------
  // Private section
  //----------------------------------------------------------------------------
  /** @nodoc @nocgmitf */
  CATRibbonPropagationFinder(CATRibbonPropagationFinderImpl *iImpl, CATGeoFactory &iFactory);
  /** @nodoc @nocgmitf */
  CATCGMNewClassArrayDeclare; // Pool allocation

private:
  int RunOperator(); // for CGMReplay

};

//----------------------------------------------------------------------------

#endif
