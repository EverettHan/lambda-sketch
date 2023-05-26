// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCurveListIterator.h
// Header definition of CATPolyCurveListIterator
//
//===================================================================
//
// Usage notes: Basic implementation of CATIPolyCurveIterator, just put curves in it
//
//===================================================================
//
// November 2013 Creation JXO
//===================================================================
#ifndef CATPolyCurveListIterator_H
#define CATPolyCurveListIterator_H

// Derive from
#include "CATIPolyCurveIterator.h"

// Poly
#include "CATIPolyCurve.h"

// System
#include "CATListPV.h"


/** Basic implementation of CATIPolyCurveIterator
 *  Just put curves in it */
class CATPolyCurveListIterator : public CATIPolyCurveIterator
{
public:
  CATPolyCurveListIterator():
    m_cur(1)
  {
  }
  ~CATPolyCurveListIterator()
  {
    Empty();
  }

  CATIPolyCurveIterator& Begin ()
  {
    m_cur = 1;
    return *this;
  }
  CATBoolean End () const
  {
    return (m_cur > m_ListOfCurves.Size());
  }
  CATIPolyCurveIterator& operator++ ()
  {
    ++m_cur;
    return *this;
  }
  // Don't believe what the comment says. Always do a Release
  CATIPolyCurve* GetAndRelease ()
  {
    if(m_cur > m_ListOfCurves.Size())
      return 0;
    CATIPolyCurve * pCurve = (CATIPolyCurve*)m_ListOfCurves[m_cur];
    if(pCurve)
      pCurve->AddRef();
    return pCurve;
  }
  // Don't believe what the comment says. Always do a Release
  CATIPolyCurve * DummyGet ()
  {
    if(m_cur > m_ListOfCurves.Size())
      return 0;
    CATIPolyCurve * pCurve = (CATIPolyCurve*)m_ListOfCurves[m_cur];
    if(pCurve)
      pCurve->AddRef();
    return pCurve;
  }
  /** Takes ownership of the curve, don't release it */
  void AppendCurve(CATIPolyCurve * pCurve)
  {
    m_ListOfCurves.Append(pCurve);
  }
  /** Empties itself then clones the passed iterator */
  void Clone(CATIPolyCurveIterator * pIter)
  {
    Empty();
    if(!pIter)
      return;
    CATIPolyCurve * pCurve = 0;
    for(pIter->Begin(); !pIter->End(); ++(*pIter))
      if(pCurve = pIter->GetAndRelease())
      {
        m_ListOfCurves.Append(pCurve);
      }
  }

private:
  void Empty()
  {
    int i;
    CATIPolyCurve * pCurve = 0;
    for(i = 1; i <= m_ListOfCurves.Size(); ++i)
      if(pCurve = (CATIPolyCurve*)m_ListOfCurves[i])
        pCurve->Release();
    m_ListOfCurves.RemoveAll();
    m_cur = 1;
  }
private:
  int m_cur;
  CATListPV m_ListOfCurves;
};

#endif


