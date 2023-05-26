
#ifndef CATPolyConvexHull_H
#define CATPolyConvexHull_H

#include "CATPolyConvexHullExport.h"
#include "CATErrorDef.h" // HRESULT definition on UNIX systems.
#include "CATIAV5Level.h"
// Polyhedral
class CATPolyBody;
class CATIPolyMesh;

// Other
class CATMathTransformation;

#ifdef CATIAR418
class CATPolyConvexHullObserver;
#endif //CATIAR418



class ExportedByCATPolyConvexHull CATPolyConvexHull
{
public:

    /** 
    * 1) File Based mode
    * 2) In Memory mode
    */
    enum CATPolyVCHRunMode{
        FILE_BASED,
        IN_MEMORY
    };

  virtual ~CATPolyConvexHull();

public:
  // Adds a polybody for processing
  virtual HRESULT AddPolyBody (CATPolyBody &iPolyBody, const CATMathTransformation *iTransfo = 0) = 0;

  // Finds Convex Hull for all the added polyBodies
  // Caller will need to delete the output CATIPolyMesh after use
  virtual HRESULT Run(CATIPolyMesh*& oConvexHull) = 0;

public:
  static CATPolyConvexHull * New();

#ifdef CATIAR418
  // For Internal use
protected:
  CATPolyConvexHull();
public:
  inline void SetObserver (CATPolyConvexHullObserver* iObserver);
  inline CATPolyConvexHullObserver* GetObserver () const;

protected:
  CATPolyConvexHullObserver* _Observer;
#endif //CATIAR418

};

#ifdef CATIAR418
inline void CATPolyConvexHull::SetObserver (CATPolyConvexHullObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyConvexHullObserver* CATPolyConvexHull::GetObserver () const
{
  return _Observer;
}
#endif //CATIAR418

#endif /* CATPolyConvexHull_H */
