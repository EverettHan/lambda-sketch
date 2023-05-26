// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTriangulateOper2D.h
//
//===================================================================
// August 2004 Creation: ndo
// 25/09/19 NLD Ajout _ForceWithLoops et SetForceWithLoops() pour inhibition tactique versionning
//===================================================================
#ifndef CATPolyTriangulateOper2D_H
#define CATPolyTriangulateOper2D_H

#include "PolygonalOperators.h"
#include "CATListPV.h"
#include "CATErrorDef.h"     // HRESULT definition
#include "CATBoolean.h"
#include "CATPolyDeprecatedM.h"

class CATPolyPolygon2D;
class CATPolyLoop2D;
class CATPolyFace2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;
class CATPolyExactArithmetic;
class CATPolyRegularizeOper2D;
class CATPolyFaceIntLayer2D;
class CATSoftwareConfiguration;



/**
 Operator that computes the triangulation of a CATPolyPolygon2D object.
 The triangulation of the CATPolyPolygon2D object is Delaunay with the regularization operator.
*/
class ExportedByPolygonalOperators CATPolyTriangulateOper2D
{

public:

  /**
   * Observer interface for update of polygon attributes during triangulation.
   */
  class ExportedByPolygonalOperators Observer
  {
  public:

    virtual ~Observer () {}

  public:

    /**
     * Call made before the split of a face into multiple faces during triangulation.
     * @param face
     *   The face that is being split.
     */
    virtual void PrepareToSplitFace (CATPolyFace2D& face) = 0;

    /**
     * Call made during the split of a face into multiple faces.
     * It is called as many times as the number of resulting faces in the split.
     * @param splitFace
     *   A resulting face.
     */
    virtual void ReactToSplitFace (CATPolyFace2D& face) = 0;

  };

  /**
   * Constructs a default observer that copies the face attributes.
   * During triangulation of a face, it copies its attribute to all the
   * new resulting faces.
   * The returned observer must be deleted.
   */
  static Observer* NewDefaultObserver ();

public:

  /**
   * Constructs a triangulator given an instance of exact arithmetic.
   * @param iSoftConfig
   *   An optional software configuration for versioning.  
   *   To benefit of the latest and more efficient code, you must use a software configuration.
   */
  CATPolyTriangulateOper2D (const CATPolyExactArithmetic& iExactArithmetic, const CATSoftwareConfiguration* iSoftConfig = 0);

  ~CATPolyTriangulateOper2D ();

  /**
   * Sets an operator to regularize the polygon after triangulation (Delaunay triangulation.)
   */
  void SetRegularizeOperator (CATPolyRegularizeOper2D* iOper);

  /**
   * Sets an option to ignore the free vertices from the polygon during triangulation.
   * Free vertices are polygon vertices are vertices that are not referred by any bar
   * of faces of the polygon.
   * By default, free vertices within a solid face are used by the triangulation. 
   */
  void IgnoreFreeVertices (const CATBoolean iIgnoreFreeVertices);

  /**
   * Always authorize loops in Delaunay triangulation. (inhibits versionning activation through software configuration)
   */
  void SetForceWithLoops ();

  /**
   * Triangulates the input CATPolyPolygon2D object.  
   * The triangulation is done in place.
   * @param ioPolyPolygon
   *   The polygon whose faces are triangulated.
   * @param iListFaces
   *   An optional list of faces to triangulate.  If this argument is null,
   *   then the method triangulates all solid faces of the polygon.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolyPolygon, CATListPV* iListFaces = 0);

  /**
   * Triangulates a polygon with an optional observer for update of polygon attributes.
   * The method triangulates all solid faces of the polygon.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolygon, Observer* obs, CATListPV* iListFaces=0);

  /**
   * Triangulates a polygon with update of the face attributes when the face is split.
   * The method triangulates all solid faces of the polygon.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolygon, CATPolyFaceIntLayer2D& ioFaceLayer);

  /** 
   * Returns the error code different from 0 when the operator fails.
   * See CATPolyError2D.h for a definition of the various errors.
   */
  int GetError () const;

private:

  const CATPolyExactArithmetic  & _ExactArithmetic;
  const CATSoftwareConfiguration* _SoftwareConfiguration;
        CATPolyRegularizeOper2D * _RegularizeOper;

        CATBoolean                _IgnoreFreeVertices;

        int                       _Orientation;
        int                       _ErrorCode;

        int                       _ForceWithLoops; // inhibition du versionning CGM_Versionning_Triangulator2D_WithoutLoops
        unsigned int              _BarDataSize;
        void                    * _BarData;
        Observer                * _Observer;

  // No implementation of copy constructor and operator =.
  CATPolyTriangulateOper2D (CATPolyTriangulateOper2D& iOther) ;
  CATPolyTriangulateOper2D& operator= (CATPolyTriangulateOper2D& iOther) ;

private:

  HRESULT Triangulate                  (      CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace, CATPolyCoBar2D** eventVertices,
                                        const CATListPV* iFreeVertices, const bool withoutLoops);

  HRESULT ConstructMonotonePolygons    (      CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                              CATPolyCoBar2D** cobars, const int nbCoBars, const bool withoutLoops);

  HRESULT ConstructMonotonePolygonsNeg (      CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                              CATPolyCoBar2D** cobars, const int nbCoBars, const bool withoutLoops);

  HRESULT ConstructMonotonePolygonsPos (      CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                              CATPolyCoBar2D** cobars, const int nbCoBars, const bool withoutLoops);

  HRESULT ExtractMonotonePolygon       (      CATPolyCoBar2D* cb,
                                              int* ranks, int iMaxIndex, int inbCoBars,
                                              CATPolyCoBar2D** cobars, int& nbCoBars);

  HRESULT ExtractMonotonePolygon       (      CATPolyLoop2D* iLoop,
                                              int* ranks, int iMaxIndex ,int inbCoBars,
                                              CATPolyCoBar2D** cobars, int& nbCoBars);

  HRESULT TriangulateMonotonePolygon   (      CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                              CATPolyCoBar2D** cobars, const int nbCoBars, const bool withoutLoops);

  int     GetOrientation               (const CATPolyPolygon2D& iPolygon, 
                                              CATPolyCoBar2D** cobars, const int nbCoBars) const;

  int GetOrientation (CATPolyVertex2D* vertex0, CATPolyVertex2D* vertex1, CATPolyVertex2D* vertex2) const;

public:

  /**
   * @deprecated 
   * Do not use.
   */  
  POLY_DEPRECATED ("Replace by a call to other constructor.", 
    CATPolyTriangulateOper2D (const CATPolyExactArithmetic* iExactArithmetic););

};

#endif
