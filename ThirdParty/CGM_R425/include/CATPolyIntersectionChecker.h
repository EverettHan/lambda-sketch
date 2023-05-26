// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyIntersectionChecker.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Apr  2009 Creation: JXO
// May  2014      JXO: Contact triangles
// July 2014      JXO: clash/contact status as a return
// September 2018 JXO: Multithread
// April     2019 JXO: SetSetOfValidFaces
//===================================================================
#ifndef CATPolyIntersectionChecker_h
#define CATPolyIntersectionChecker_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATMapOfBVHNodesToAttributes.h"
#include "CATSysBoolean.h"
#include "CATSetOfInt.h"
#include "CATMapOfPtrToPtr.h"


class CATPolyBodySimpleClashFaceEdgeIterator;
class CATPolyBVHNodePairStack;
class CATIPolyCurveIterator;
class CATPolyCurveFromBarsIterator;
class CATMapOfPtrPtrToPtr;
class CATCellId;
class CATBVHNode;
class CATTolerance;
class CATIPolyMesh;
class CATPolyMeshImpl;
class CATPolyBodySelfClearanceObserver;
class CATProgressCallback;
class CATPolyBVHDescentSelf;
class CATSetOfPtr;

ExportedByCATPolyBoundingVolumeOperators CATCellId* GetCellIdFromNode(CATBVHNode* iNode);

/**
 *
 */

class ExportedByCATPolyBoundingVolumeOperators CATPolyIntersectionChecker
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyIntersectionChecker(CATPolyBVHNodePairStack & Stack, const CATTolerance & iTol);
  ~CATPolyIntersectionChecker();

  /**
   * Returns 
   *     1: if a geometric intersection was discovered
   *     2: if a contact was discovered
   *     3: for both
   *     0: if only topological intersections (or no intersection) were discovered
   */
  int Check(const CATSetOfInt * iFacesToCheck = NULL);

  /**
   * Intersecting free bars won't be reported
   */
  void DiscardFreeBars();
  /**
   * Intersecting triangles on edges won't be reported
   */
  void DiscardEdgeTriangles();

  /** @nodoc */
  void ComputeCurves();

  /** @nodoc */
#define CATPolyIntersectionCheckerOption_DEFAULT    0
#define CATPolyIntersectionCheckerOption_COUPLES    1
#define CATPolyIntersectionCheckerOption_CONTACTS   2
#define CATPolyIntersectionCheckerOption_SCARS      4
#define CATPolyIntersectionCheckerOption_TRIANGLES  8

  /** @nodoc */
  void SetCheckerOptions(unsigned char iOptions);

  /** @nodoc */
  // To be deleted by caller
  CATIPolyCurveIterator * GetCurves();

  /** @nodoc */
  // To be released by caller
  CATIPolyMesh * GetTriangles();

  /** @nodoc */
  // To be released after use
  CATPolyBodySimpleClashFaceEdgeIterator * GetCouples();

  /** @nodoc */
  inline void SetContactTolerance(double iTol);

  /** @nodoc */
  inline void SetClearance(double iClearance);

  /** @nodoc */
  void SetTimerCallbacks(void (*ifStart)(),double (*ifStop)());

  /** @nodoc */
  class CoupleData
  {
  public:
    // Constructor
    CoupleData() { status      = 0; nbintersect = 0; nbcontact   = 0; scar        = NULL; }
    // Methods
    inline void AddIntersect() { nbintersect++; CoupleData::nbintersectglobal++; }
    inline void AddContact()   { nbcontact++;   CoupleData::nbcontactglobal++;   }
    inline void UpdateStatus(int iStatus) { if (status < iStatus) status = iStatus; }
  public:
    // Couple specific data
    // status can be 0 : faces are not in clash, not in contact and not even topological neighbors
    //               1 : triangles are clashing on their edge, faces are most likely topological neighbors
    //               2 : triangles are clashing away from the edges OR are close enough to be in contact
    int status;
    int nbintersect;
    int nbcontact;
    CATPolyCurveFromBarsIterator* scar;
  public:
    // Global data
    ExportedByCATPolyBoundingVolumeOperators static int nbintersectglobal;
    ExportedByCATPolyBoundingVolumeOperators static int nbcontactglobal;
    ExportedByCATPolyBoundingVolumeOperators static double intersecttime;
    ExportedByCATPolyBoundingVolumeOperators static double contacttime;
  };

  /** @nodoc */
  inline CATMapOfPtrPtrToPtr* GetMapOfCouplesToData() { _delete_map_cellcell_data = 0; return _map_cellcell_data; }

  /** @nodoc */
  void RegisterObserver(CATPolyBodySelfClearanceObserver * iObs);
  /** @nodoc */
  void SetProgressCallback(CATProgressCallback * pBar);
  /**
  * @nodoc
  * Force number of threads (default is 1 : monothread)
  */
  inline void ForceNumberOfThreads(int iNbThreads, int iNbEstimatedCouples = 0);
  inline void CouplesComputerToCallBack(CATPolyBVHDescentSelf * couplescomputer);
  void SetSetOfValidFaces(const CATSetOfPtr * iSetOfValidFaces);

private:
  int DestroyMap(CATMapOfPtrToPtr & map);
  void Reinitialize();

private:
  CATPolyBVHNodePairStack & _Couples;
  const CATTolerance & m_Tol;

  CATMapOfPtrToPtr _MapOfBoxesAttributes;

  unsigned char _checkeroptions;

  CATIPolyCurveIterator * _curves;
  int _deletecurves;
  CATPolyMeshImpl * _mesh;

  CATPolyBodySimpleClashFaceEdgeIterator * _couples_faces;

  int _discardfreebars;

  double _ContactTolerance;
  double m_clearance; // clearance is like 2 times the contact tolerance

  void   (*_pfTimerStart)(void);
  double (*_pfTimerStop)(void);

  CATMapOfPtrPtrToPtr* _map_cellcell_data;
  int _delete_map_cellcell_data;

  CATPolyBodySelfClearanceObserver * m_obs;
  CATProgressCallback * m_progress;

  int m_nbthreads;
  int m_nbestimatedcouples;
  CATPolyBVHDescentSelf * m_couplescomputer;

  const CATSetOfPtr * m_SetOfValidFaces;
};

inline void CATPolyIntersectionChecker::SetContactTolerance(double iTol) {
  _ContactTolerance = iTol; }

inline void CATPolyIntersectionChecker::SetClearance(double iClearance) {
  m_clearance = iClearance; }

inline void CATPolyIntersectionChecker::ForceNumberOfThreads(int iNbThreads, int iNbEstimatedCouples)
{
  m_nbthreads = iNbThreads;
  m_nbestimatedcouples = iNbEstimatedCouples;
}

inline void CATPolyIntersectionChecker::CouplesComputerToCallBack(CATPolyBVHDescentSelf * couplescomputer)
{
  m_couplescomputer = couplescomputer;
}

#endif // CATPolyIntersectionChecker_H

