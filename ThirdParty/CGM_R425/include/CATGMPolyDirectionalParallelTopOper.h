/* -*-C++-*-*/
#ifndef CATGMPolyDirectionalParallelTopOper_H
#define CATGMPolyDirectionalParallelTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyDirectionalParallelTopOper
//
// DESCRIPTION :
// Offset a polyhedral wire lying on a surface, according to a given direction
// Please note that the distance between input and output wires is not euclidian here
// The offset value is only respected as distance between the projected wires in any plane whose the normal is the given direction.
//
//
// History
//
// March. 2016 DPS Creation
// Oct.   2020 DPS Modification : Add Create with implicit direction normal to infinite planar body
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyOffset.h"         // ExportedBy

#include "CATDataType.h"           // HRESULT
#include "CATTopDefine.h"          // CATSide
#include "CATMathInline.h"         // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyDirectionalParallelTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyOffset CATGMPolyDirectionalParallelTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyDirectionalParallelTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyDirectionalParallelTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyDirectionalParallelTopOper() method to create an instance
  static CATGMPolyDirectionalParallelTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyDirectionalParallelTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  /** 
   * Sets the value of the offset to apply on the boundary of the planar polygon 2D
   * A null offset value (as initialized by the operator itself) leads to return the projected planar wire, without applying any offset
   */
  void SetOffsetValue(double iOffsetValue);

  /** 
  * Sets the side to apply the offset from the boundary of the planar polygon 2D
  * This side depends on both the orientation of the initial wires and the planar normal
  * The point of view is always defined by an observer in front of the plane
  * A Full side is not authorized here
  * Default value (initialized by the operator itself) is CATSideRight
  */
  void SetParallelSide(CATSide iSide);

  /** 
  * Sets the mode to drive the parallel behaviour
  * This mode impacts only the concave (resp. convexe) sharp vertices in case of positive (resp. negative) Offset value value
  *   TRUE leads to create a circular arc (according to the Minkowsky offset specification),
  *   FALSE leads to create a sharp vertex computed by extrapolation (in this case, the Offset value value is not respected).
  *   Default mode is TRUE (Rounded)
  */
  void SetRoundedMode(CATBoolean iRoundedMode);

  /** 
  * Sets the mode to drive the generation of "LyingOn" links of the offset cells on the support body
  *   TRUE leads to enable the generation of LyingOn links
  *   FALSE leads to disable the generation of LyingOn links
  *   Default mode is FALSE (disabled)
  */
  void SetLyingOnMode(CATBoolean iLyingOnMode);

  /** 
  * Enable the generation of GeoPolyCurveOnPlane instead of simple 3D GeoPolyCurve, 
  * associating UV parameters to the 3D points of the curves if the target body is an infinite planar body
  * Default mode is FALSE (disabled)
  */
  void EnablePlanarModeling();


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
  // Please, call CATCreatePolyDirectionalParallelTopOper() method to create an instance
  CATGMPolyDirectionalParallelTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyDirectionalParallelTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyDirectionalParallelTopOper();
  CATGMPolyDirectionalParallelTopOper(const CATGMPolyDirectionalParallelTopOper& iOneOf); 
  CATGMPolyDirectionalParallelTopOper& operator =(const CATGMPolyDirectionalParallelTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyDirectionalParallelTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iWireBody
 * The pointer to the body (wire) to offset
 * @param iSupportBody
 * The pointer to the body on which the Parallel has to be computed
 * @param iDirection
 * The mathematical direction to apply the Parallel
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyOffset CATGMPolyDirectionalParallelTopOper * CATCreatePolyDirectionalParallelTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iWireBody, CATBody * iSupportBody, CATMathDirection &iDirection); 


/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyDirectionalParallelTopOper operator on a an infinite planar body.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iWireBody
 * The pointer to the body (wire) to offset
 * @param iInfinitePlanarBody
 * The pointer to the infinite planar body on which the Parallel Curve has to be computed
 * The wire side will be considered comparing to the topological orientation of this body
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyOffset CATGMPolyDirectionalParallelTopOper * CATCreatePolyDirectionalParallelTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iWireBody, CATBody * iInfinitePlanarBody); 

#endif
