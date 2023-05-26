// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFillAllHolesOper.h
// Header definition of CATPolyFillAllHolesOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2006 Creation: NDO
//===================================================================
#ifndef CATPolyFillAllHolesOper_h
#define CATPolyFillAllHolesOper_h

#include "CATPolyFillHolesOperators.h"
#include "CATPolyModOper.h"
#include "CATErrorDef.h"  // For definition of HRESULT.
#include "CATBoolean.h"
#include "CATIAV5Level.h"

#ifdef CATIAR418
class CATPolyFillAllHolesOperObserver;
class CATechExt;
#endif //CATIAR418
/*
Operator that fills all the holes of a mesh or holes up to a specific size.
*/
class ExportedByCATPolyFillHolesOperators CATPolyFillAllHolesOper : public CATPolyModOper
{

public:

  CATPolyFillAllHolesOper ();

  virtual ~CATPolyFillAllHolesOper ();

  /*
   * Option to fill all the holes including the largest one.
   * By default, this option is set to TRUE; largest hole is filled.
   */
  void SetFillLargestHole (const CATBoolean iFillLargestHole);

  /*
   * Fill all the holes up to the specific hole size in number of vertices.
   * If this parameter is set to 0 (default), holes of any size are filled.
   */
  void SetMaximumHoleSize (const int iHoleSize);

  /*
   * Run the operator and fills all the holes that satisfy the above options.
   * If any of these holes cannot be filled, the method return E_FAIL.
   */
  HRESULT Run ();

  /* 
   * Returns the number of holes left in the mesh.
   */
  int GetNbHoles () const;

private:

  CATBoolean _FillLargestHole; // An option to specify whether to fill the largest hole or not. 
  int _MaximumHoleSize;        // The maximum number of vertices of a hole to be filled.

#ifdef CATIAR418
public:
  void SetObserver (CATPolyFillAllHolesOperObserver* iObserver);
  CATPolyFillAllHolesOperObserver* GetObserver () const;

protected:
  CATPolyFillAllHolesOperObserver* _Observer;
  CATechExt * _PhoenixExtension;
#endif //CATIAR418

};


#ifdef CATIAR418
inline void CATPolyFillAllHolesOper::SetObserver (CATPolyFillAllHolesOperObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyFillAllHolesOperObserver* CATPolyFillAllHolesOper::GetObserver () const
{
  return _Observer;
}
#endif //CATIAR418


#endif
