/* -*-c++-*- */
#ifndef CATGMPolyOffsetVtxOnShellTopOper_h
#define CATGMPolyOffsetVtxOnShellTopOper_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyOffsetVtxOnShellTopOper
// idem CATBodyFromLengthOnShell but dedicated to polyhedral implementation of CATBody
//
// DESCRIPTION :
// Create a Vertex on a Shell at a given distance from another one in a specific direction
//
//
// History
//
// November. 2016 DPS Creation
//
//=============================================================================

#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyOffset.h"         // ExportedBy

#include "CATLengthType.h"
#include "CATTopDef.h"

#include "CATListOfDouble.h"
#include "ListPOfCATVertex.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"

class CATGMPolyOffsetVtxOnShellTopExt;
class CATShell;
class CATVertex;
class CATBody;
class CATPoint;
class CATGeoFactory;
class CATTopData;

/**
* @nodoc @nocgmitf (do not create any specific interface)
* Class defining an operator to create a vertex on a Shell at a given distance from another one.
* <br>
* <br>
* The <tt>CATGMPolyOffsetVtxOnShellTopOper</tt> operator follows the global frame of the topological
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

class ExportedByGMPolyOffset CATGMPolyOffsetVtxOnShellTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyOffsetVtxOnShellTopOper);
  
public:

  /**
  * Destructor
  */
  virtual ~CATGMPolyOffsetVtxOnShellTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreate...TopOper functions to create an instance
  static CATGMPolyOffsetVtxOnShellTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOffsetVtxOnShellTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  /**
  * Activates or deactivates the lay-down operation.  If activated, the operator
  * projects the resulting point body upon the specified wire body 
  * if the distance between them is lower than the factory resolution.
  * @param iEnableLayDown
  * FALSE to turn off lay-down, TRUE to turn it on.
  */
  void SetLayDown(CATBoolean iEnableLayDown); 



  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();


protected:

  // Constructor
  // Please, call CATCreatePolyOffsetVtxOnShellTopOper() method to create an instance
  CATGMPolyOffsetVtxOnShellTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOffsetVtxOnShellTopExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyOffsetVtxOnShellTopOper();
  CATGMPolyOffsetVtxOnShellTopOper(const CATGMPolyOffsetVtxOnShellTopOper& iOneOf); 
  CATGMPolyOffsetVtxOnShellTopOper& operator =(const CATGMPolyOffsetVtxOnShellTopOper& iOneOf);


};

//- ----------------------------------------
// Constructor:  if type is RELATIVE, the ABSOLUTE value will be calculated.
//- ----------------------------------------
/**
* @nodoc @nocgmitf (do not create a specific interface)
* Creates a CATGMPolyOffsetVtxOnShellTopOper operator.
* @param iFactory
*    The factory of the geometry. 
* @param iTopData
*    The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iVertexBody
*    The reference vertex where the sampling will start.
* @param iShellBody
*    The shell domain to be sampled.
* @param iDistance
*    The offset distance to apply from the input vertex as reference
* @param iOffsetDirection
*    direction to project on the shell support in order to define the geodesic direction
*/
ExportedByGMPolyOffset CATGMPolyOffsetVtxOnShellTopOper * CATCreatePolyOffsetVtxOnShellTopOper(CATGeoFactory   * iFactory,
                                                                                               CATTopData      * iTopData,
                                                                                               CATBody         * iVertexBody,
                                                                                               CATBody         * iShellBody,
                                                                                               double            iDistance,
                                                                                               CATMathDirection &iOffsetDirection);

#endif
