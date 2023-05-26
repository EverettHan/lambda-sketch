/* -*-C++-*-*/
#ifndef CATGMPolyDirectionalProjectionTopOper_H
#define CATGMPolyDirectionalProjectionTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyDirectionalProjectionTopOper
//
// DESCRIPTION :
// Project a polyhedral wire or point, along a direction, on a polyhedral surfacic body
//
//
// History
//
// March. 2016 DPS Creation
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
class CATSoftwareConfiguration;
class CATGMPolyDirectionalProjectionTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyProject CATGMPolyDirectionalProjectionTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyDirectionalProjectionTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyDirectionalProjectionTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyDirectionalProjectionTopOper() method to create an instance
  static CATGMPolyDirectionalProjectionTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyDirectionalProjectionTopExt & iExtension);

  /** @nodoc @nocgmitf */
  static CATBoolean CheckIfOperandsAreBothCompliant(CATBody & iBodyToProject, CATBody & iTargetBody, CATSoftwareConfiguration * iConfig);


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

  // Enable/Disable the "ExtrapolationMode" links of the projected cells on the target body
  // Default mode is FALSE (disabled)
  void SetExtrapolationMode(CATBoolean iExtrapolMode);

  // Enable/Disable the "Nearest Mode" 
  // Default mode is FALSE
  void SetNearestMode(CATBoolean iKeepNearestOnly=TRUE);

  // Enable/Disable the "Original Ori Mode" 
  // Default mode is FALSE
  void SetOriginalOriMode(CATBoolean iKeepOriginalOri=TRUE);

  // Enable/Disable the "Distance Computation" 
  // Default mode is FALSE
  void SetDistComputation(CATBoolean iDistComputation);

  // Enable MaxDistance mode
  void SetMaxDistanceValue(double iMaxDistance);

  // Outputs
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
  // Please, call CATCreatePolyDirectionalProjectionTopOper() method to create an instance
  CATGMPolyDirectionalProjectionTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyDirectionalProjectionTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyDirectionalProjectionTopOper();
  CATGMPolyDirectionalProjectionTopOper(const CATGMPolyDirectionalProjectionTopOper& iOneOf); 
  CATGMPolyDirectionalProjectionTopOper& operator =(const CATGMPolyDirectionalProjectionTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyDirectionalProjectionTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToProject
 * The pointer to the body (wire of point) to project
 * @param iTargetBody
 * The pointer to the body on which the projection has to be computed
 * @param iDirection
 * The mathematical direction to apply the projection
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolyDirectionalProjectionTopOper * CATCreatePolyDirectionalProjectionTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyToProject, CATBody * iTargetBody, CATMathDirection &iDirection); 

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyDirectionalProjectionTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iPlanarBodyToProject
 * The pointer to the body (wire of point contained in a plane) to project
 * @param iTargetBody
 * The pointer to the body on which the projection has to be computed
 * @param iInputBodyPlane
 * The mathematical definition of the plane containing the Body to project and defining the direction by its normal vector
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolyDirectionalProjectionTopOper * CATCreatePolyDirectionalProjectionTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iPlanarBodyToProject, CATBody * iTargetBody, CATMathPlane &iInputBodyPlane); 


#endif
