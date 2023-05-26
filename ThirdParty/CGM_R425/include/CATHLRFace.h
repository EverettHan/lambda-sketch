/**
 * @fullReview  TPG 02:03:20
 * @quickReview TPG 01:07:24
 */
/* -*-C++-*-*/
#ifndef CATHLRFace_H
#define CATHLRFace_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRFace 
//
// DESCRIPTION :
/**
 * Face for the HLR. A face is composed of a list of loops
 */
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
// Jan. 98 HKL Creation            
// Jun. 99 HKL Added Get2DBox method
// Apr. 01 TPG Added the GetNormalSenseWithEntityTransfo method
// Jul. 01 TPG Added the IsHelix method
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"     // ExportedBy

#include "CATHLRTopology.h"  // derivation
#include "CATErrorDef.h"     // HRESULT

#include "CATListValCATCrvParam.h"

class CATFace;
class CATHLRChainLoop;
class CATHLREntity;
class CATHLRLoop;
class CATHLRLoopIterator;
class CATHLREdge;
class CATHLRSurface; 
class CATHLRTemporaryFactory;
class CATHLRContainerObject;
class CATHLRPtOnFaceSectorIter;
class CATHLRProjection;

class CATSurLimits;
class CATSurParam;
class CATMathPoint;
class CATMathDirection;

class ExportedByHLRTopology CATHLRFace : public CATHLRTopology
{
public:

//=============================================================================
// ENUMERATIONS
//=============================================================================
/** Different curvatures computed.
 */
  enum CATHLRFaceIdType { FaceUnknownId, FaceV5TAG, FaceV4JELE, FaceGPPTR, PolyFaceID, SubHLRFace };

//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

/**
  * Constructor from a FacePTR
  */
  CATHLRFace(void * iFacePTR=0, CATHLRContainerObject * iContainer=0);

/** Constructor with a surface and a sense of normal, according to the surface,
 * and the sense of the face in the volume.
 * <BR> To have the normal external to the volume, one should multiply the normal to
 * the surface by these two values..
 */
  CATHLRFace(CATHLRSurface * iSupport,
	           short           iSenseOfNormal,
             short           iSenseInVolume);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the model face associated to the face.
 */
  virtual CATFace * GetModelFace() const = 0;


/** Get attribute/identifier (CATINPTR) lying on CATHLRFace, 
  * CATHLRFaceIdType depends on context (JELE, TAG, FaceGP* ...)
  * Null value means no attribute/identifier
  */
  virtual CATINTPTR GetClientId(CATHLRFaceIdType &oType);

/** Gets the surface on which the face lies.
 */
  virtual CATHLRSurface * GetSurface() const;

/** Gets the loops. The iterator is initialized to sweep the loops of the face.
  */
  void GetLoops(CATHLRLoopIterator & oIterator) const;

/** Gets the number of loops.
 */
  CATLONG32 GetCountLoops() const;

/** Gets the sense of the normal.
 */
  virtual CATLONG32 GetNormalSense() const;

/** Gets the sense of the normal taking into account the Entity transformation.
 */
  virtual CATLONG32 GetNormalSenseWithEntityTransfo() const;

/** For DCubed interface, the face orientation must be changed 
 *  on revolution faces where (du,dv,axis) is not direct
 */
  virtual void SetDirectNormalSense(short iSense);
  virtual CATLONG32 GetDirectNormalSense() const;

/** Gets the sense of the face in the volume that contains it.
 * <BR> This method returns 0 if the face is isolated, 1 or -1
 * in other cases, according to the send of the external normal
 *to the volume. 
 */
  virtual CATLONG32 GetSenseInVolume() const;

/** Test if the face is a fillet face.
 */
  virtual CATLONG32 IsFillet() const;

/** if the face is a fillet test if the profile is in V.
 */
  virtual CATLONG32 IsFilletProfileInV() const;

/** Test if the face is a sweep face.
 */
  virtual CATLONG32 IsSweep() const;

/** Test if the face is a helix face.
 *  Returns 0 if unknown, 1 if Helix, -1 if not Helix
 */
  virtual CATLONG32 IsHelix() const;

/** Set the helix property.
 *  input 1 if Helix, -1 if not Helix
 */
  virtual void SetHelix(CATLONG32 iHelix);

/** Gets the temporary factory to create some reflect lines
 */
  CATHLRTemporaryFactory * GetTemporaryFactory() const;

/** Retrieves the face's dimension (ie. 2)
  */
  int GetDimension();

/** Retrieves the face's UV box.
  */
  virtual void Get2DBox(CATSurLimits & oLimits) const;

/** Returns 1 if the point is inside the face, -1 if it is on the face
  * boundary, 0 if it is outside the face
  */
  virtual CATLONG32 IsInside(const CATSurParam& iParam) const;


  virtual CATHLRPtOnFaceSectorIter * CreatePtOnFaceSectorIter();


  // IsHidingAPoint service
  // ----------------------
  //
  // Intput
  // iPointToCheck and iObserver are defined in the 3D space
  // iPointToCheck is seen from the Observer through the current face
  // iBoundaryTol : tolerance along X/Y axis in the screen defined by iPointToCheck and the view direction
  // iContactTol  : tolerance along Z axis (the view direction)
  //
  // Output :
  // oNbOcclusionsByBoundary : number of border edges in front of the point to check, in regards with iBoundaryTol
  // oNbHiddenByFace         : number of face areas in front of the point to check, far from the boundary
  // => oNbOcclusionsByBoundary and oNbHiddenByFace are complementary
  // oContactStatus : 0 if there is 'No Contact' in regards with iContactTol, 
  //                  1 if the contact is on the boundary, in regards with iBoundaryTol,
  //                  2 if the contact is inside the face, far from the boundary
  //
  // returns E_FAIL if this service is not implemented (default)
  //
  virtual HRESULT IsHidingAPoint(const CATMathPoint &iPointToCheck, CATHLRProjection &iHLRProjection, double iBoundaryTol, double iContactTol,
                                 int &oNbOcclusionsByBoundary, CATListPV &oBoundaryEdgesOccluding, CATLISTV(CATCrvParam) &oCrvParamOnOccludingEdges,
                                 int &oNbHiddenByFace, int &oContactStatus, CATHLREdge * &oBoundaryEdgeInContact, CATCrvParam &oCrvParamOnBEdgeInContact);

  /** Evaluates the box according to the projection plane axis
  */
  virtual HRESULT EvalProjectionViewBox(CATHLRProjection &iHLRProjection, CATMathBox & oBox);

  //=============================================================================
// METHODS TO SET THE DATAS
//=============================================================================
/** Adds a loop in the face. The object used to chain the loops is also provided.
 */
  //void AddLoop(CATHLRLoop * iLoop, CATHLRChainLoop * iChainLoop) ;
  void AddLoop(CATHLRLoop * iLoop) ;

/** Sets the surface. The sense of normal is -1 or 1, according to the orientation
 * between the surface and the loops
 */
  virtual void SetSurface(CATHLRSurface      * iSurface,
		                      CATLONG32            iSenseOfNormal,
                          CATLONG32            iSenseInVolume);

/** Sets the sense in a manifold.
 */
  virtual void SetSenseInVolume(CATLONG32 iSenseInVolume);

/** Sets the entity.
 */
  virtual void SetEntity(CATHLREntity * iEntity);

/** For the debug of the models.
 */
// HKL  inline void SetComputationId(CATLONG32 iNumber);
// HKL  CATLONG32 GetComputationId() const;

  inline CATHLRFace * GetNext() const;
  inline void SetNext(CATHLRFace * iFace);

  virtual CATHLREntity * GetEntity();



//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  CATHLRFace      * _Next;

  // Pointer on a chain of loops
  CATHLRLoop      * _FirstChainLoop;

  // Number of loops
  CATLONG32         _CountLoops;

  // Pointer on the entity
  CATHLREntity    * _Entity;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//-----------------------------------------------------------------------------

inline CATHLRFace * CATHLRFace::GetNext() const
{
  return _Next;
}

//-----------------------------------------------------------------------------

inline void CATHLRFace::SetNext(CATHLRFace * iFace)
{
  if (iFace) iFace->_Next = _Next;
  _Next = iFace;
}


#endif
