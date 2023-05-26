// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBooleanOptions.h
//
//===================================================================
// February 2015 Creation: ndo
//===================================================================
#ifndef CATPolyBodyBooleanOptions_H
#define CATPolyBodyBooleanOptions_H

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyBodyOverlayOptions.h"
#include "CATPolyBoolean.h"


/**
 Options for the CATPolyBodyBoolean operator.
*/
class CATPolyBodyBooleanOptions : public CATPolyBodyOverlayOptions
{

public:

  inline CATPolyBodyBooleanOptions ();
  inline CATPolyBodyBooleanOptions(const CATPolyBodyOverlayOptions & iOptions);

  CATPolyBodyBooleanOptions (const CATPolyBodyBooleanOptions& iRHS) : 
    CATPolyBodyOverlayOptions (iRHS) {}

  ~CATPolyBodyBooleanOptions () {}

  inline CATPolyBodyBooleanOptions& operator = (const CATPolyBodyBooleanOptions& iRHS);

public:

  /**
   * Query for switching to the mesh boolean operator (CATIPolyMesh operator).
   */
  inline bool DoMeshBoolean () const;

  /**
   * Option for switching to the mesh boolean operator.
   * By default, the mesh boolean is not activated.
   */
  inline void SetDoMeshBoolean (bool iDo);

  /**
   * Query for forcing the use of the overlay operator.
   */
  inline bool ForceOverlay () const;
};

inline CATPolyBodyBooleanOptions& CATPolyBodyBooleanOptions::operator = (const CATPolyBodyBooleanOptions& iRHS)
{
  return (CATPolyBodyBooleanOptions&) CATPolyBodyOverlayOptions::operator = (iRHS);
}

inline bool CATPolyBodyBooleanOptions::DoMeshBoolean () const
{
  return _UseMeshBoolean;
}

inline bool CATPolyBodyBooleanOptions::ForceOverlay () const
{
  return _ForceOverlay;
}

inline void CATPolyBodyBooleanOptions::SetDoMeshBoolean (bool iDo)
{
  if (iDo)
  {
    _UseMeshBoolean = 1;
    _ForceOverlay = 0;
  }
  else
  {
    _UseMeshBoolean = 0;
    _ForceOverlay = 1;
  }
}

inline CATPolyBodyBooleanOptions::CATPolyBodyBooleanOptions() : CATPolyBodyOverlayOptions()
{
}

inline CATPolyBodyBooleanOptions::CATPolyBodyBooleanOptions(const CATPolyBodyOverlayOptions & iOptions) : CATPolyBodyOverlayOptions(iOptions)
{
}

#endif
