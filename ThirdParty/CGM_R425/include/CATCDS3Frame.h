#ifndef CATCDS3Frame_H
#define CATCDS3Frame_H

// COPYRIGHT DASSAULT SYSTEMES 2020

#include "CDSMathematics.h"
#include "CATCDSInline.h"
#include "CATCDSCPlusPlusVersions.h"
#include "CATCDS3Point.h"
#include "CATCDS3Vector.h"

/**
 * Class representing a frame in dimension 3 (1 origin + 3 vectors).
 */
class ExportedByCDSMathematics CATCDS3Frame
{
public:
  //=============================================================================
  //- Constructors
  //============================================================================
  /**
   * Constructs a canonical frame.
   * Origin = (0,0,0), vectors = (1,0,0), (0,1,0), (0,0,1).
   */
  CATCDS3Frame();

  /**
   * Constructs a frame from a CATCDS3Point and three CATCDS3Vector.
   */
  CATCDS3Frame(
    const CATCDS3Point & iOrigin,
    const CATCDS3Vector & iI,
    const CATCDS3Vector & iJ,
    const CATCDS3Vector & iK);

  //============================================================================
  //- Get/Set
  //============================================================================

  /**
   * Set the origin and vectors of <tt>this</tt> CATCDS3Frame.
   */
  void Set(
    const CATCDS3Point & iOrigin,
    const CATCDS3Vector & iI,
    const CATCDS3Vector & iJ,
    const CATCDS3Vector & iK);

  /**
   * Set/Get the origin of <tt>this</tt> CATCDS3Frame.
   */
  void SetOrigin(const CATCDS3Point & iOrigin);
  void GetOrigin(CATCDS3Point & ioOrigin) const;

  /**
   * Set/Get the vectors of <tt>this</tt> CATCDS3Frame.
   */
  void SetVectors(const CATCDS3Vector & iI, const CATCDS3Vector & iJ, const CATCDS3Vector & iK);
  void GetVectors(CATCDS3Vector & ioI, CATCDS3Vector & ioJ, CATCDS3Vector & ioK) const;

  /**
   * Get the coordinates of <tt>this</tt> CATCDS3Frame in an array of 12 doubles :
   * 3 coordinates of the origin
   * 3 coordinates of the firt vector
   * 3 coordinates of the second vector
   * 3 coordinates of the third vector
   */
  void GetCoord(double oaCoord[12]);

protected:
  CATCDS3Point _Origin;
  CATCDS3Vector _aVectors[3];
};
#endif
