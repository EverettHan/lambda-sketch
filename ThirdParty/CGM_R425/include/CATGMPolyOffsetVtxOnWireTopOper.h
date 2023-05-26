/* -*-c++-*- */
#ifndef CATGMPolyOffsetVtxOnWireTopOper_h
#define CATGMPolyOffsetVtxOnWireTopOper_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyOffsetVtxOnWireTopOper
// idem CATBodyFromLengthOnWire but dedicated to polyhedral implementation of CATBody
//
// DESCRIPTION :
// Create a Vertex on a Wire at a given distance from another one
//
//
// History
//
// April. 2016 DPS Creation
//
//=============================================================================

#include "GMPolyOffset.h" // ExportedBy


#include "CATGMPolyTopOperator.h" // derivation
#include "CATLengthType.h"
#include "CATTopDef.h"

#include "CATListOfDouble.h"
#include "ListPOfCATVertex.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"

class CATGMPolyOffsetVtxOnWireTopExt;
class CATWire;
class CATVertex;
class CATBody;
class CATPoint;
class CATGeoFactory;
class CATTopData;

/**
* @nodoc @nocgmitf (do not create any specific interface)
* Class defining an operator to create a vertex on a Wire at a given distance from another one.
* <br>
* <br>
* The <tt>CATGMPolyOffsetVtxOnWireTopOper</tt> operator follows the global frame of the topological
* operators and satisfies the smart mechanism: 
* the input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
*<li>If the vertex is not on the wire, then a point is computed
* from the input Vertex that is closest to the wire.
*<li>The length can be positive or negative. The sign of the length
* indicates the direction to traverse on the wire.
*<li>Options must be precised with the appropriate methods, before
* asking for the computation with the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
*/

class ExportedByGMPolyOffset CATGMPolyOffsetVtxOnWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyOffsetVtxOnWireTopOper);
  
public:

  /**
  * Destructor
  */
  virtual ~CATGMPolyOffsetVtxOnWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreate...TopOper functions to create an instance
  static CATGMPolyOffsetVtxOnWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOffsetVtxOnWireTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  /**
  * Activates or deactivates the lay-down operation.  If activated, the operator
  * projects the resulting point body upon the specified wire body 
  * if the distance between them is lower than the factory resolution.
  * @param iEnableLayDown
  * FALSE to turn off lay-down, TRUE to turn it on.
  * @param iWireBody
  * The wire body that is the target of the lay-down operation.
  */
  void SetLayDown(CATBoolean iEnableLayDown, CATBody * iWireBody); 


  void SetExtrapolationMode(CATBoolean iAuthorizeExtrapolation);


  // the new point is on the wire or not.
  // if the point is not on the wire it returns the extrapoled distance
  // Returns the status of the farest point in case of multi distance values
  /** @nodoc */
  CATBoolean IsOffsetVtxOnWire(double &oExtrapolDistance) const;



  /**
  * Returns the resulting vertices, locations & tangents information
  * The operator must be run prior to the use of this method
  * @return
  * The <tt>oVertices</tt> list of the sampled vertices.
  * The <tt>oLocations</tt> list of 3D locations of the vertices.
  * The <tt>oTangents</tt> list of tangents associated to the vertices.
  */
  void GetOffsetVtxInformation(CATLISTP(CATVertex) * oVertices=NULL, CATLISTV(CATMathPoint) * oLocations=NULL, CATLISTV(CATMathVector) * oTangents=NULL) const;


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
	

protected:

  // Constructor
  // Please, call CATCreatePolyOffsetVtxOnWireTopOper() method to create an instance
  CATGMPolyOffsetVtxOnWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOffsetVtxOnWireTopExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyOffsetVtxOnWireTopOper();
  CATGMPolyOffsetVtxOnWireTopOper(const CATGMPolyOffsetVtxOnWireTopOper& iOneOf); 
  CATGMPolyOffsetVtxOnWireTopOper& operator =(const CATGMPolyOffsetVtxOnWireTopOper& iOneOf);


};

//- ----------------------------------------
// Constructor:  if type is RELATIVE, the ABSOLUTE value will be calculated.
//- ----------------------------------------
/**
* @nodoc @nocgmitf (do not create a specific interface)
* Creates a CATGMPolyOffsetVtxOnWireTopOper operator.
* @param iFactory
*    The factory of the geometry. 
* @param iTopData
*    The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iWire
*    The wire domain to be sampled.
* @param iRefVertex
*    The reference vertex where the sampling will start.
* @param iDistance
*    The offset distance to apply from the input vertex as reference
* @param iType
*    The type defining if the length is absolute or relative
* CATLengthType_ABSOLUTE_L = The distance is an absolute value, but the sign indicates the direction on the wire for finding the vertex.
* CATLengthType_RELATIVE_L = The distance is a fraction of the total length of the wire. Since it's a fraction,  its value must be equal to or between -1 and 1. 
* @return [out]
*    The pointer to the created operator.  To be deleted after use.
*/
ExportedByGMPolyOffset CATGMPolyOffsetVtxOnWireTopOper * CATCreatePolyOffsetVtxOnWireTopOper(CATGeoFactory * iFactory,
                                                                                             CATTopData    * iTopData,
                                                                                             CATWire       * iWire,
                                                                                             CATVertex     * iRefVertex,
                                                                                             double          iDistance,
                                                                                             CATLengthType   iType = CATLengthType_ABSOLUTE_L);

/**
* @nodoc @nocgmitf (do not create a specific interface)
* Creates a CATGMPolyOffsetVtxOnWireTopOper operator.
* @param iFactory
*    The factory of the geometry. 
* @param iTopData
*    The pointer to the data defining the software configuration and the journal.
*    If the journal inside <tt>iData</tt> is <tt>NULL</tt>, it is not filled.
* @param iSamplingArcLengths
*    Variable arc lengths between the sample points on the wire. The wire will be sampled at
*    consecutive increments defined in iSamplingArcLengths array starting from the 
*    ReferenceVertex in the direction of wire orientation.
* @param iRepeatLastOnly
*    If TRUE, only last value in the list will be used.
*    Wire will be sampled from iRefVertex to :
*    - First wire extremity encountered if wire is open
*    - iRefVertex itself if wire is closed
*    If FALSE, default mode, samples are defined by the given list.
* @param iWire
*    The wire domain to be sampled.
* @param iRefVertex
*    The reference vertex where the sampling will start.
* @param iReverseSamplingDirection
*    Reverse the sampling direction (with respect to the wire orientation)
* @param iTolFactor
*    Specifies the relative tolerance (a multiplicative factor of the factory resolution) 
*    used internally in the integration scheme to determine sample point positions on the
wire. Lower tolerance values may result in a higher precision of the computation at 
*	  the expense of a slower performance. The legal values are between 10^-4 and 1.
* @return [out]
*	  The pointer to the created operator.  To be deleted after use.
*/
ExportedByGMPolyOffset CATGMPolyOffsetVtxOnWireTopOper * CATCreatePolyOffsetVtxOnWireTopOper(CATGeoFactory         * iFactory,
                                                                                             CATTopData            * iTopData,
                                                                                             CATWire               * iWire,
                                                                                             CATVertex             * iRefVertex,
                                                                                             const CATListOfDouble & iSamplingArcLengths,
                                                                                             CATBoolean              iRepeatLastOnly = FALSE,
                                                                                             CATBoolean              iReverseSamplingDirection = FALSE,
                                                                                             double                  iTolFactor = 0.1 );

#endif
