//====================================================================
// Copyright Dassault Systemes 2013, all rights reserved
//====================================================================
//

#ifndef CAT2DBoxComputation_H
#define CAT2DBoxComputation_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "AnalysisTools.h"
#include "CATIACGMLevel.h"
 
#include "CATBoolean.h"
#include "CATCGMVirtual.h"
#include "CATTopOperator.h"

class CATGeoFactory;
class CATTopData;
class CATFace;
class CATEdge;
class CATSurLimits;

 /**
 * Class defining a topological operator that computes a uv bounding box for a <tt>CATFace</tt> or a <tt>CATEdge</tt> on a support face:
 * <ul>
 *     <li> A <tt>CAT2DBoxComputation</tt> operator is created with the <tt>CATCreate2DBoxComputationOper</tt> global functions
 *     <li> It is the user's responsibility to release the operator after it has been used.
 *     <li> In both cases, the result is returned by the <tt>Get2DBox</tt> method.
 * </ul>
 */
class ExportedByAnalysisTools CAT2DBoxComputation : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CAT2DBoxComputation);
public :

  virtual ~CAT2DBoxComputation ();
 
  /**
  * Returns the computed uv bounding box.
  * @return
  * oBoundingBox : The uv bounding box.
  */
  virtual void Get2DBox(CATSurLimits &oBoundingBox) = 0;
   
  
protected:
  CAT2DBoxComputation(CATGeoFactory *ipFactory, CATTopData *ipTopData);
};

/**
 * Creates the operator that computes a uv bounding box for a <tt>CATFace</tt>.
 * @param ipFactory
 * The pointer to the factory of the geometry.
 * @param ipTopData
 * The pointer to the <tt>CATTopData</tt> object used to create the operator.
 * @param ipInputFace
 * The pointer to the input face.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 */
ExportedByAnalysisTools
CAT2DBoxComputation * CATCreate2DBoxComputation (
	CATGeoFactory				*ipFactory,
	CATTopData					*ipTopData,
	CATFace						*ipInputFace);

/**
 * Creates the operator that computes a uv bounding box for a CATEdge on a support face.
 * @param ipFactory
 * The pointer to the factory of the geometry.
 * @param ipTopData
 * The pointer to the <tt>CATTopData</tt> object used to create the operator.
 * @param ipInputEdge
 * The pointer to the input edge.
 * @param ipSupportFace
 * The pointer to the support face of the input edge.
 * @return
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByAnalysisTools
CAT2DBoxComputation * CATCreate2DBoxComputation (
	CATGeoFactory				*ipFactory,
	CATTopData					*ipTopData,
	CATEdge						*ipInputEdge,
	CATFace						*ipSupportFace);

#endif
