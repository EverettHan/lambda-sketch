/**
 * @fullReview TPG 02:03:20
 */
/* -*-C++-*-*/
#ifndef CATHLRFaceExact_H
#define CATHLRFaceExact_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2002
//
// CATHLRFaceExact 
//
// DESCRIPTION :
/**
 * Face for the exact HLR. A face is composed of a list of loops
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
// Mar. 02 TPG creation
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"

#include "CATHLRFace.h"

class CATFace;
class CATHLRChainLoop;
class CATHLREntity;
class CATHLRLoop;
class CATHLRLoopIterator;
class CATHLRSurface; 
class CATHLRTemporaryFactory;

class CATSurLimits;
class CATSurParam;
class CATMathPoint;
class CATMathDirection;

class ExportedByHLRTopology CATHLRFaceExact : public CATHLRFace
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor.
 */
  CATHLRFaceExact(void * iFacePTR=0);

/** Constructor with a surface and a sense of normal, according to the surface,
 * and the sense of the face in the volume.
 * <BR> To have the normal external to the volume, one should multiply the normal to
 * the surface by these two values..
 */
  CATHLRFaceExact(CATHLRSurface * iSupport, short iSenseOfNormal, short iSenseInVolume);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the model face associated to the face.
 */
  virtual CATFace * GetModelFace() const = 0;

/** Gets an identifier for the face.
 */
  virtual CATINTPTR GetIdentificationTAG() const {return 0;};
  // while waiting for the ACIS migration
  virtual CATLONG32 GetIdentificationTag() const {return 0;};

/** Gets the surface on which the face lies.
 */
  CATHLRSurface * GetSurface() const;

/** Gets the sense of the normal.
 */
  CATLONG32 GetNormalSense() const;

/** Gets the sense of the normal taking into account the Entity transformation.
 */
  CATLONG32 GetNormalSenseWithEntityTransfo() const;

/** For DCubed interface, the face orientation must be changed 
 *  on revolution faces where (du,dv,axis) is not direct
 */
  void SetDirectNormalSense(short iSense);
  CATLONG32 GetDirectNormalSense() const;

/** Gets the sense of the face in the volume that contains it.
 * <BR> This method returns 0 if the face is isolated, 1 or -1
 * in other cases, according to the send of the external normal
 *to the volume. 
 */
  CATLONG32 GetSenseInVolume() const;

/** Test if the face is a fillet face.
 */
  inline CATLONG32 IsFillet() const;

/** if the face is a fillet test if the profile is in V.
 */
  inline CATLONG32 IsFilletProfileInV() const;

/** Test if the face is a sweep face.
 */
  inline CATLONG32 IsSweep() const;

/** Test if the face is a helix face.
 *  Returns 0 if unknown, 1 if Helix, -1 if not Helix
 */
  inline CATLONG32 IsHelix() const;

/** Set the helix property.
 *  input 1 if Helix, -1 if not Helix
 */
  virtual void SetHelix(CATLONG32 iHelix);

//=============================================================================
// METHODS TO SET THE DATAS
//=============================================================================
/** Sets the surface. The sense of normal is -1 or 1, according to the orientation
 * between the surface and the loops
 */
  void SetSurface(CATHLRSurface * iSurface,
		  CATLONG32            iSenseOfNormal,
                  CATLONG32            iSenseInVolume);

/** Sets the sense in a manifold.
 */
  void SetSenseInVolume(CATLONG32 iSenseInVolume);

/** Sets the entity.
 */
  virtual void SetEntity(CATHLREntity * iEntity);

/** For the debug of the models.
 */
// HKL  inline void SetComputationId(CATLONG32 iNumber);
// HKL  CATLONG32 GetComputationId() const;

  inline CATHLRFaceExact * GetNext() const;
  inline void SetNext(CATHLRFace * iFace);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointer on the surface
  CATHLRSurface   * _Surface;

// Sense of the normal to the surface
  struct BitField {
    signed int             _NormalSense : 3;          // = orientation of face versus surface, why 3 bits for all variables = mystery (chu)
    signed int             _DirectNormalSense : 3;    // =_NormalSense, probably unreliable, hopefully unused, intended meaning = mystery (chu)
    // Flag for whether the face is a fillet face 
    unsigned int           _IsFillet : 3;
    // Flag for whether the face is a sweep face 
    unsigned int           _IsSweep : 3;
    // Flag for whether the face is a helix face 
    signed int             _IsHelix : 3;
    // Sense of the face if it belongs to a volume
    // =opposite of CATSide of face vs volume upon creation (note: left=1, right=-1, and inward normals make "left" faces) (chu)
    signed int             _SenseInVolume : 3;
    // Flag for whether the face is a fillet face 
    unsigned int           _IsFilletProfileInV : 3;
  } _BitField;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline CATLONG32 CATHLRFaceExact::IsFillet() const
{
  return _BitField._IsFillet;
}

//-----------------------------------------------------------------------------

inline CATLONG32 CATHLRFaceExact::IsFilletProfileInV() const
{
  return _BitField._IsFilletProfileInV;
}

//-----------------------------------------------------------------------------

inline CATLONG32 CATHLRFaceExact::IsSweep() const
{
  return _BitField._IsSweep;
}

//-----------------------------------------------------------------------------

inline CATLONG32 CATHLRFaceExact::IsHelix() const
{
  return _BitField._IsHelix;
}

//-----------------------------------------------------------------------------

#endif

