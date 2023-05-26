/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2001

#ifndef CATFileDocLocAdapter_H
#define CATFileDocLocAdapter_H

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
class CATIDocId;
class CATIDocDescriptor;
class CATUnicodeString;


class ExportedByAC0XXLNK CATFileDocLocAdapter : public CATBaseUnknown
{
  public:
  
  CATDeclareClass;
  
  //--------------
  // 'tors
  //--------------
  CATFileDocLocAdapter () ;
  virtual ~CATFileDocLocAdapter() ;
 
  //------------------------------
  // CATIDocLocator bindings
  //------------------------------
  virtual HRESULT GetName(CATUnicodeString& oName);
  virtual HRESULT RetrieveDocDescriptor(CATIDocId *iDocId, CATIDocDescriptor **oDocDescriptor, CATIDocId *iPointingDocId = NULL);
  
  //------------------------------
  // virtual method
  //------------------------------
  virtual HRESULT GetNewPath(const CATUnicodeString& iDocPath, const CATUnicodeString& iDocType, CATUnicodeString& oNewDocPath);

};

#endif
