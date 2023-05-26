/* -*-C++-*-*/
#ifndef CATTessInFaceSurfacePoly_h
#define CATTessInFaceSurfacePoly_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 20001
//
// CATTessInFaceSurfacePoly
//
// DESCRIPTION :
// 
// Maillage d'un element type "Body"
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
// Fev. 2001 TPD Mise en place nouvel interface MAILLAGE
//
//=============================================================================

// For Windows NT
#include "TessTopology.h"

#include "CATTessInCell.h"

// Pour CATLISTP(xxx)
#include "CATCollec.h"
#include "CATCGMNewArray.h"

#include "CATSurLimits.h"

class CATLISTP(CATTessInCell);
typedef CATLISTP(CATTessInCell) CATListTessInCells ;

class CATSurface;
class CATGeoFactory;

class ExportedByTessTopology CATTessInFaceSurfacePoly : public CATTessInCell
{
public:

  //=============================================================================
  // Constructors  and desctructor
  //=============================================================================
  /**
   * CONSTRUCTOR
   */
  CATTessInFaceSurfacePoly( CATSurface   *  iSurface,
			    CATSurLimits *  iLimits);
  
  /**
   *  Destructor
   */
  ~CATTessInFaceSurfacePoly();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  //=============================================================================
  // METHODS
  //=============================================================================

  /** Get du nombre de domaines
   */
  virtual CATLONG32 GetNbDomains( CATLONG32 & oNbPtsMax );

  /** Get des donnees du Polygon iiPoly
   */
  virtual void GetPolygon(CATLONG32       iPoly,
			  CATLONG32     & NbPts,
			  double     Xyz[][3],
			  double     Nor[][3],
			  double     Uv[][2]);

  /** Get de la Surface
   */
  inline CATSurface * GetSurface() const;

  /** Get de la Surface
   */
  inline CATSurLimits * GetSurLimits() const;

  /** Get de la factory de la surface
    */
  virtual CATGeoFactory * GetFactory() const;

protected:
  // Surface plane representant le polygone
  CATSurface   * _Surface;
  // Limites de discretisation de la surface
  CATSurLimits * _SurfaceLimits;
  
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATSurface * CATTessInFaceSurfacePoly::GetSurface() const
{
  return _Surface;
}

inline CATSurLimits * CATTessInFaceSurfacePoly::GetSurLimits() const
{
  return _SurfaceLimits;
}

#endif
