/**
 * @fullReview TPG 02:03:20
 */
/* -*-C++-*-*/
#ifndef CATHLREdgeExact_H
#define CATHLREdgeExact_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2002
//
// CATHLREdgeExact 
//
// DESCRIPTION :
// Edge for the exact HLR. An edge is necessary linked to 2 vertices.
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Mar. 2002 TPG creation 
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"

// For inheritance
#include "CATHLREdge.h"

// Other includes
#include "CATHLRConstant.h"
#include "CATCrvParam.h"
#include "CATCGMOutput.h"

#include "CATHLRBodyId.h"

#include "CATIAV5Level.h"

class CATEdge;
class CATHLRCoedge;
class CATHLRChainFace; 
class CATHLRContainer;
class CATHLRCurve;
class CATHLRFace;
class CATHLRVertex;
class CATHLRTransformation;
class CATMathVector;
class CATHLRHedge;
class CATHLRClashEdge;
class CATSurParam;
class CATHLRMemoryManager;

class ExportedByHLRTopology CATHLREdgeExact : public CATHLREdge
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a CATEdge
 */ 
  CATHLREdgeExact(void            * iEdge, 
	                CATHLRBodyId      iIdentity,
                  CATHLRContainer * iContainer,
                  CATHLRVertex    * iStartVertex,
                  CATHLRVertex    * iEndVertex,
                  CATHLRCurve     * iSupportCurve,
                  const CATHLRTransformation * iTransformation);

/** Constructor with no model geometry, but all the datas. The last datas is
 * put to declare if the edge is a reflect line.
 */
  CATHLREdgeExact(int                 iIdentifier,
	                CATHLRBodyId        iIdentity,
                  CATHLRContainer   * iContainer,
                  CATHLRVertex      * iStartVertex,
                  CATHLRVertex      * iEndVertex,
                  CATHLRCurve       * iSupportCurve);

//=============================================================================
// METHODS
//=============================================================================

/** Return the original orientation of the curve in the edge, multiplied by the
 *  orientation of the edge in its unique domain. Return 0 if the edge is
 *  shared by several domains.
 */
  virtual int GetCurveUniqueOrientation() const;
  virtual void UpdateCurveUniqueOrientation(int iOrientation);

/** Checks if the edge is vivid.
 */
  CATLONG32 IsVivid() const;
  CATLONG32 IsSmooth() const;

/** Gets a pointer on a CATEdge. This returns NULL if it is a reflect line.
 */
  virtual CATEdge * GetEdge() const = 0;

/** Gets an identifier for the edge.
 */
  virtual CATINTPTR GetIdentificationTAG() const {return 0;};
  // while waiting for the ACIS migration
  virtual CATLONG32 GetIdentificationTag() const {return 0;};

/** Specific method for the drafting.
 * <BR> Evaluates the difference of curvature between the two faces that share
 * the edge.
 * The result is between 0. and 1..
 * 0 means there is no jump of curvature, 1. there is a big step.
 */
  double GetCurvatureStep(double iReferenceCurvature);


//=============================================================================
// METHODS TO SET THE DATAS
//=============================================================================

/** Sets the vivicity.
 */
  inline void SetVivicity(CATHLRConstant::Vivicity iVivicity);

#ifdef CATIAR214
/** Update Clash information on edge
 */
  virtual void AppendClashPoint(CATHLRMemoryManager * iMemoryManager, CATCrvParam &iClashParam, CATHLRFace * iClashingFace);
#endif

/** Evaluates the inverse of the curvature of the face in the direction
 * that is orthogonal to the tangent at the given parameter..
 */
  virtual CATHLREdgeExact::CurvatureStatus EvaluateInternalCurvature(const CATCrvParam & iParam,
                                                                     CATHLRFace        * iFace,
                                                                     double            & iCurvature,
                                                                     CATMathVector     * oDirection = 0L) const;

/** Evaluates the face's surface parameter at edge's curve parameter
 */
  virtual void EvaluateOnFace(double iParam, CATHLRFace * iFace, CATSurParam & oParam) const = 0;

//------------------------------------------------------------
// For the HLR's management
//------------------------------------------------------------
  virtual void SetHLRHedge(CATHLRHedge * iHeadEdge);
  virtual CATHLRHedge * GetHLRHedge();
  virtual CATHLRClashEdge * GetHLRClashEdge();
  
  inline void Dump(CATCGMOutput& os);


//=============================================================================
// INTERNAL METHODS
//=============================================================================
public:
/** Compute the vivicity.
 */
  virtual void ComputeVivicity();

//=============================================================================
// INTERNAL DATAS
  //=============================================================================
protected:

  void SetHLRClashEdge(CATHLRClashEdge * iHLRClashEdge);

  float               _CurvatureStep;

  
  // Pointer on the HLREdge data information
  union CATHLRHedgeInfo {
    CATHLRHedge       * _HEdge;
    CATHLRClashEdge   * _ClashHLREdge;
  } _HLREdgeInfo;


  // BitField
  struct BitField {

    //  Stored curvature step
    unsigned int      _CurvatureStepIsComputed : 1;

    // Vivicity of the edge
    unsigned int      _Vivicity : 2;

    // Curve's unique orientation
    // (internaly: -1 negative, 1 positive orientations
    // 0 not initialized yet, -2 orientation not unique)
    signed int        _CurveUniqueOrientation : 2;

    unsigned int      _ClashType : 1;

    // Free area to complete the current byte
    unsigned int      _FreeArea : 2;
  } _BitField;

};


//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline void CATHLREdgeExact::SetVivicity(CATHLRConstant::Vivicity Vivicity) {
  _BitField._Vivicity = (unsigned int) Vivicity; }


//-----------------------------------------------------------------------------

void CATHLREdgeExact::Dump(CATCGMOutput& os)
{
	CATHLREdge::Dump(os);
}
#endif
