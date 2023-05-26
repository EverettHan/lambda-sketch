//===================================================================
// COPYRIGHT Microsoft 2012/04/19
//===================================================================
// CATAsyncTaskCompletionCallBack.cpp
// Header definition of class CATAsyncTaskCompletionCallBack
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/04/19 Creation: Code generated by the 3DS wizard
//===================================================================

#ifdef KOALA_MIGRATION
#include "CATAsyncTaskCompletionCallBack_NG.h"
#else

#include "CATAsyncTasksPlatform.h"

#ifdef AsyncCompileError
#error "CATAsyncTaskCompletionCallBack should not be included. Migrate on new platform : cf. KOALA_MIGRATION. Contact JBX."
#else
#pragma message ("CATAsyncTaskCompletionCallBack should not be included. Migrate on new platform : cf. KOALA_MIGRATION. Contact JBX.")
#endif 

#ifndef CATAsyncTaskCompletionCallBack_H
#define CATAsyncTaskCompletionCallBack_H

#include "CATIAsyncTaskCompletionCallBack.h"

//-----------------------------------------------------------------------

class ExportedByCATAsyncTasksPlatform_OLD CATAsyncTaskCompletionCallBack: public CATIAsyncTaskCompletionCallBack
{
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATAsyncTaskCompletionCallBack ();
  virtual ~CATAsyncTaskCompletionCallBack ();

  virtual HRESULT OnTaskCompleted(CATAsyncTaskContext & iAsyncTaskContext) { return E_NOTIMPL; }

  virtual HRESULT OnTaskProgressed(CATAsyncTaskContext & iAsyncTaskContext) { return E_NOTIMPL; }

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATAsyncTaskCompletionCallBack (CATAsyncTaskCompletionCallBack &);
  CATAsyncTaskCompletionCallBack& operator=(CATAsyncTaskCompletionCallBack&);

};

#endif

//-----------------------------------------------------------------------

#endif