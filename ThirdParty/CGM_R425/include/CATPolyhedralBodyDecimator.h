/* -*-C++-*-*/
#ifndef CATPolyhedralBodyDecimator_H
#define CATPolyhedralBodyDecimator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATPolyhedralBodyDecimator
//
// DESCRIPTION :
// Operator that decimates a polyhedral body.
//
//
// History
//
// July. 2016 CLO2/DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolySimplify.h"     // ExportedBy

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyOperTopExt;

/**
* Operator for decimating a polyhedral CATBody.
*
* <b>Role:</b> This operator produces a polyhedral CATBody with a reduced triangle count
* while maintaining a shape that is close to the shape of the input.  This operator
* currently only works for polyhedral CATBody inputs.
**/

class ExportedByGMPolySimplify CATPolyhedralBodyDecimator : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATPolyhedralBodyDecimator);

public:
  
  /**
  * Destructor
  */
  virtual ~CATPolyhedralBodyDecimator();
  

  //=============================================================================
  // Settings
  //=============================================================================
    
  /**
  * Sets the chordal deviation that is not to be exceeded between the input and decimated CATBody instances.
  * Recommended if the input body to decimate contains only wires.
  * In the other cases (surfaces or volumes), it's recommended to call the other method SetChordalDeviations 
  * with 2 arguments, one for faces, the second one for edges.
  * Decimation stops when further processing would exceed this chordal deviation. 
  * @param iChordalDeviation
  *   The input chordal deviation.
  */
  virtual void SetChordalDeviation (const double iChordalDeviation) = 0;

  /**
  * Sets the chordal deviation that is not to be exceeded between the input and decimated CATBody instances.
  * Decimation stops when further processing would exceed these chordal deviations. 
  * @param iFaceChordalDeviation
  *   The input chordal deviation to apply on Meshes
  * @param iEdgeChordalDeviation
  *   The input chordal deviation to apply on PolyCurves
  * It's strongly recommended to set iEdgeChordalDeviation to a lower value than iFaceChordalDeviation
  */
  virtual void SetChordalDeviations (const double iFaceChordalDeviation, const double iEdgeChordalDeviation=0.) = 0;

  /**
   * Sets a flag to prevent the collapse and change of any bar that is not adjacent to two triangles
   * (either on the same surface or across an edge.)
   * By default the boundary-bars are not frozen.
   * @param iDoFreeze
   *   The input flag.
   */
  virtual void DoFreezeBoundaryBars (CATBoolean iDoFreeze) = 0;
  

	
protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATPolyhedralBodyDecimator(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  /** @nodoc @nocgmitf */
  CATPolyhedralBodyDecimator();
  /** @nodoc @nocgmitf */
  CATPolyhedralBodyDecimator(const CATPolyhedralBodyDecimator& iOneOf); 
  /** @nodoc @nocgmitf */
  CATPolyhedralBodyDecimator& operator =(const CATPolyhedralBodyDecimator& iOneOf);

};

/**
 * Creates a CATPolyhedralBodyDecimator operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the body to decimate.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolySimplify CATPolyhedralBodyDecimator * CATCreatePolyhedralBodyDecimator(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody); 

#endif
