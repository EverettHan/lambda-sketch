// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFillHoleOper.h
// Header definition of CATPolyFillHoleOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2006 Creation: NDO
//===================================================================
#ifndef CATPolyFillHoleOper_h
#define CATPolyFillHoleOper_h

#include "CATPolyFillHolesOperators.h"
#include "CATPolyModOper.h"
#include "CATListOfInt.h"
#include "CATErrorDef.h"  // For definition of HRESULT.
#include "CATIAV5Level.h"

class CATIPolyMesh;

#ifdef CATIAR418
class CATPolyFillHoleOperObserver;
class CATechExt;
#endif //CATIAR418

/*
Simple hole filling operator.
*/
class ExportedByCATPolyFillHolesOperators CATPolyFillHoleOper : public CATPolyModOper
{

public:

  CATPolyFillHoleOper ();

  virtual ~CATPolyFillHoleOper ();

  HRESULT Run (const CATListOfInt& iHole);

private:

  HRESULT FillHoleWithOneTriangle (const CATListOfInt& iHole);
  HRESULT FillHole (const CATListOfInt& iHole);

  int GetOrientation (const int iBarVertex0, const int iBarVertex1) const;

#ifdef CATIAR418
public:
  void SetObserver (CATPolyFillHoleOperObserver* iObserver);
  CATPolyFillHoleOperObserver* GetObserver () const;

protected:
  CATPolyFillHoleOperObserver* _Observer;
  CATechExt * _PhoenixExtension;
#endif //CATIAR418
};

#ifdef CATIAR418
inline void CATPolyFillHoleOper::SetObserver (CATPolyFillHoleOperObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyFillHoleOperObserver* CATPolyFillHoleOper::GetObserver () const
{
  return _Observer;
}
#endif //CATIAR418


#endif
