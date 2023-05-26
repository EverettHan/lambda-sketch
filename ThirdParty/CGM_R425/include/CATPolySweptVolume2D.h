// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySweptVolume2D.h
// Header definition of CATPolySweptVolume2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2014 Creation: XXC
//===================================================================
#ifndef CATPolySweptVolume2D_H
#define CATPolySweptVolume2D_H

#include "PolygonalOperators.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATPolyPolygon2D.h"
#include "CATPolyExactArithmetic.h"

class CATMathPoint2D;
class CATMathBox2D;
class CATMathTransformation2D;
class CATMapOfPtrToPtr;
class CATPolyBooleanNOper2D;
class CATProgressCallback;

/**
 This operator swept a (close or open) polygon along a path and return
 the polygon resulting from the sweep. The path is given by a list of
 positions of the given polygon to sweep, which is interpolated
 linearly between two positions.
*/
class ExportedByPolygonalOperators CATPolySweptVolume2D
{

public :

  CATPolySweptVolume2D ();

  CATPolySweptVolume2D (CATPolyExactArithmetic & iExactArithmetic);

  ~CATPolySweptVolume2D ();

  /** Run the swept volumt on the givent polygon along the given
   *  positions. Calling this method creates a polygon which must be
   *  retrieved and deleted by the user to prevent memory leaks.
   *@param iPolygon: the polygon that have to be swept.
   *@param iPositions: an array of positions (CATMathTransformation2D)
   *that the polygon has to be placed at during the sweeping.
   *@param iNbPositions: the size of the array of positions.
   */
  HRESULT Run (const CATPolyPolygon2D * iPolygon, const CATMathTransformation2D * iPositions, const int iNbPositions);

  /** Option to indicate if the resulting polygon must be triangulated
   *  at the end of the run command. By default, the result is
   *  triangulated. Must be called before the Run method to be taken
   *  into account.
   */
  INLINE void TriangulateResult(CATBoolean iTriangulate) { _Triangulate = iTriangulate; }

  /** Returns the polygon representing the swept volume of the
   *  original polygon given in the Run command.
   *  WARNING: The polygon instance must be deleted by the user.
   */
  CATPolyPolygon2D * GetSweptPolygon() const;
  
  /** To get the progress and/or interrupt */
  void SetProgressCallback(CATProgressCallback * iProgress);

  /** Debug only, don't use */
  void SetIndex(int i){m_i = i;}

private:

  HRESULT CopyPolygon(const CATPolyPolygon2D & iInput, CATPolyPolygon2D & oOutput, const CATMathTransformation2D * iPosition);


  HRESULT Extrude(const CATMathTransformation2D & iPos1, const CATMathTransformation2D & iPos2, CATPolyBooleanNOper2D & iPartoche, int & ioScanId, CATBoolean doWire);

  HRESULT Initialize(const CATMathTransformation2D & iInitPos);

 private:
  
  HRESULT TestBars(const CATMathTransformation2D & iPos1, const CATMathTransformation2D & iPos2);

  /* HRESULT TestVertices(const CATMathTransformation2D & iPos1, const CATMathTransformation2D & iPos2); */

  int TestBar(const CATMathPoint2D & iOldPos1, const CATMathPoint2D & iOldPos2,
              const CATMathPoint2D & iNewPos1, const CATMathPoint2D & iNewPos2);

  int TestVertex(const CATMathPoint2D * iOldPos, const CATMathPoint2D * iNewPos, int iNbPos);
  
  HRESULT GetFullPolyline(CATPolyBar2D * iBar, const CATPolyLoop2D * iLoop1, const CATPolyLoop2D * iLoop2, CATListPV & oListOfBars, CATPolyVertex2D *& oFirst);

  HRESULT ExtendBarsAndVertices(const CATMathTransformation2D & iPos1, const CATMathTransformation2D & iPos2, CATPolyBooleanNOper2D & iBooleanOper, int & ioScanId, CATBoolean doWire);

  static double ComputeMaxCoordinate(const CATPolyPolygon2D & iPolygon, const CATMathTransformation2D * iPositions, const int iNbPositions,
                                     CATMathBox2D & oBox);

 protected:
  CATBoolean _OwnArithmetic;
  CATPolyExactArithmetic * _ExactArithmetic;

  CATBoolean _Triangulate;
  
  CATPolyPolygon2D * _Origin;
  CATPolyPolygon2D * _SweptPolygon;

  int * _BarExtension;
  int * _VertexExtension;

  CATPolyFace2D * _MainFace;
  CATProgressCallback * m_progress;
  int m_i;
};

#endif
