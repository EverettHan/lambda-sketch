// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyBaseOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyBaseOper_h
#define CATPolyBaseOper_h

#include "CATPolyModOperators.h"
#include "CATPolyOperatorTypes.h"
#include "CATErrorDef.h"     // HRESULT definition (for subclasses compil under UNIX)
#include "CATIACGMLevel.h"

class CATCGMProgressBar;
class CATProgressCallback;


class ExportedByCATPolyModOperators CATPolyBaseOper
{

public :

  CATPolyBaseOper (void);

  virtual ~CATPolyBaseOper (void);

  /**
  * Sets the callback to track the progress in an operator and to interrupt.
  * @param callback
  *   The callback.
  */
  void SetCallback (CATCGMProgressBar* callback);
  void SetProgressCallback (CATProgressCallback* callback);

  /**
  * Returns the callback.
  * @return 
  *   The callback or NULL is no callback has been set.
  *   No AddRef () is done to the returned pointer.
  */
  CATCGMProgressBar* GetCallback () const;
  CATProgressCallback* GetProgressCallback () const;

protected :

  void SetOperatorType (const PolyOperatorTypes type);

  PolyOperatorTypes _type;

  CATCGMProgressBar * _Callback;
  mutable CATProgressCallback * m_ProgressCallback;

};

#endif
