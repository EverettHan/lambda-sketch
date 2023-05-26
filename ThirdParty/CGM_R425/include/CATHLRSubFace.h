/* -*-C++-*-*/
#ifndef CATHLRSubFace_H
#define CATHLRSubFace_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATHLRSubFace 
//
// DESCRIPTION :
//
// SubFace for the HLR after subdivision of a face by the silhouettes
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
// Nov. 12 DPS Creation            
//
//=============================================================================

#include "HLRTopology.h"

#include "CATHLRFace.h"

class CATFace;
class CATHLREntity;
class CATHLRLoop;
class CATHLRLoopIterator;
class CATHLRSurface; 

class CATSurLimits;
class CATSurParam;
class CATMathPoint;
class CATMathDirection;
class CATHLRPtOnFaceSectorIter;

class ExportedByHLRTopology CATHLRSubFace : public CATHLRFace
{
public:


//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

/**
* Constructor from a CATHLRFace
*/
  CATHLRSubFace(const CATHLRFace & iMasterFace, CATHLRSubFace * iPreviousSubFace, int iViewOrientation);

  virtual void Clean()=0;


//=============================================================================
// METHODS
//=============================================================================


  //=============================================================================
  // specifical methods to the CATHLRSubFace class
  //=============================================================================
  static CATHLRSubFace * SafeCastToHLRSubFace(CATHLRFace * iHLRFaceToCast);
  const CATHLRFace & GetMasterHLRFace() const;
  CATHLRSubFace * GetNextSubFaceInMasterFace() const;
  CATHLRSubFace * GetNextInEntityChain() const;

  inline int GetViewOrientation() const;

  virtual CATHLRPtOnFaceSectorIter * CreatePtOnFaceSectorIter();


  //=============================================================================
  // virtual methods inheritate from CATHLRFace class
  //=============================================================================

  /** Retrieves the face's UV box.
  */
  virtual void Get2DBox(CATSurLimits & oLimits) const=0;

  /** Gets the model face associated to the face.
  */
  virtual CATFace * GetModelFace() const;


/** Get attribute/identifier (CATINPTR) lying on CATHLRFace, 
  * CATHLRFaceIdType depends on context (JELE, TAG, FaceGP* ...)
  * Null value means no attribute/identifier
  */
  virtual CATINTPTR GetClientId(CATHLRFaceIdType &oType);

/** Gets the surface on which the face lies.
 */
  virtual CATHLRSurface * GetSurface() const;

/** Gets the sense of the normal.
 */
  virtual CATLONG32 GetNormalSense() const;

/** Gets the sense of the normal taking into account the Entity transformation.
 */
  virtual CATLONG32 GetNormalSenseWithEntityTransfo() const;

/** For DCubed interface, the face orientation must be changed 
 *  on revolution faces where (du,dv,axis) is not direct
 */
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

  virtual CATHLREntity * GetEntity();


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  signed char         _ViewOrientation;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//-----------------------------------------------------------------------------
inline int CATHLRSubFace::GetViewOrientation() const {
  return _ViewOrientation; }


#endif

