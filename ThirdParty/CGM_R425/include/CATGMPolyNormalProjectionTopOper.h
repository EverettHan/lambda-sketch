/* -*-C++-*-*/
#ifndef CATGMPolyNormalProjectionTopOper_H
#define CATGMPolyNormalProjectionTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2017
//
// CATGMPolyNormalProjectionTopOper
//
// DESCRIPTION :
// Project a polyhedral wire or point on a polyhedral body at minimum distance.
// Ideally along the normal on the body at the resulting location.
//
// History
//
// May. 2017 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyProject.h"        // ExportedBy

#include "CATDataType.h"          // HRESULT
#include "CATTopDefine.h"         // CATSide
#include "CATMathInline.h"        // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"

#include "ListPOfCATDomain.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyNormalProjectionTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyProject CATGMPolyNormalProjectionTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyNormalProjectionTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyNormalProjectionTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyNormalProjectionTopOper() method to create an instance
  static CATGMPolyNormalProjectionTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyNormalProjectionTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  // Enable/Disable the "LyingOn" links of the projected cells on the target body
  // Default mode is FALSE (disabled)
  void SetLyingOnMode(CATBoolean iLyingOnMode);

  // Enable the generation of GeoPolyCurveOnPlane instead of simple 3D GeoPolyCurve, 
  // associating UV parameters to the 3D points of the curves if the target body is an infinite planar body
  // Default mode is FALSE (disabled)
  void EnablePlanarModeling();

  // Enable/Disable the "Distance Computation" 
  // Default mode is FALSE
  void SetDistComputation(CATBoolean iDistComputation);

  // Enable MaxDistance mode
  void SetMaxDistanceValue(double iMaxDistance);

  //=============================================================================
  // Get Outputs
  //=============================================================================

  void GetResultDomainsAndDistances(CATLISTP(CATDomain) & oDomains, CATListOfDouble & oDistances);


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();


protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyNormalProjectionTopOper() method to create an instance
  CATGMPolyNormalProjectionTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyNormalProjectionTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyNormalProjectionTopOper();
  CATGMPolyNormalProjectionTopOper(const CATGMPolyNormalProjectionTopOper& iOneOf); 
  CATGMPolyNormalProjectionTopOper& operator =(const CATGMPolyNormalProjectionTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyNormalProjectionTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToProject
 * The pointer to the body (wire of point) to project
 * @param iTargetBody
 * The pointer to the body on which the projection has to be computed
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolyNormalProjectionTopOper * CATCreatePolyNormalProjectionTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToProject, CATBody * iTargetBody); 

#endif
