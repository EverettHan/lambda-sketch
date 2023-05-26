/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1997  
//-----------------------------------------------------------------------------
// class CATUndoDocument (extension) :
// 
// This extension implements the undo/redo operation for feature documents
//
//-----------------------------------------------------------------------------
// Creation by User pjo
//-----------------------------------------------------------------------------
#ifndef CATUndoDocument_H_
#define CATUndoDocument_H_

/**
 * @level Private 
 * @usage U1
 */
#include "CATExtensionAdapter.h"
#include "CATCallbackManager.h"
#include "CATListPV.h"
#include "CATContainersInSession.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATUndoDocument
{
public:
  
  CATUndoDocument();
  virtual ~CATUndoDocument();
  
protected:
  CATUndoDocument( const CATUndoDocument &);
  CATUndoDocument& operator = (const CATUndoDocument &);

  
 
};

#endif
