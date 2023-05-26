/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES   95
//=============================================================================
//
// class CATLinkExtension :
//
//
//=============================================================================
// Usage Notes:
//
// Extension des interfaces CATINavigElement, CATINavigLinkCtrl
//=============================================================================
// Dec. 95   Creation                                  
//=============================================================================
#ifndef CATLinkExtension_H_
#define CATLinkExtension_H_

// NB : les forward suivants seraient plus judicieux   
//      s'ils distingaient les macros des vraies classes :
// ====================================================

#include <CATOmnExt.h>

#include "CATBaseUnknown.h"

class CATINavigContainer;
class CATNavigController;
class CATNavigInstance;
class CATUnicodeString;


class ExportedByCATOmnExt CATLinkExtension : public CATBaseUnknown
{
public:
//  MacExt(CATLinkExtension,CATExtensionAdapter, CATObject);
  CATDeclareClass;
  
  CATLinkExtension();
  virtual ~CATLinkExtension();

  // Interface CATINavigElement
  virtual void Update();
  virtual void Remove(int index);
  virtual CATINavigContainer* GetFatherContainer();
  virtual const CATNavigController* GetController();
  virtual void ProcessAfterSelect();
  virtual void ProcessAfterExtSelect();
  virtual void ProcessAfterAction();
  virtual void ProcessAfterExpand();
  virtual void ProcessAfterMethod();
  virtual CATNavigInstance* GetAssociatedInstance();
  virtual void SetMarked(int mark=1);
  virtual int  GetMarked();

  virtual HRESULT ModifyShortHelp(CATUnicodeString& text) ;

  // Interface CATINavigModify
  virtual void UpdateElem (CATNavigInstance* inst);

  // Gestion de la selection
  virtual void Select(int mode);
  virtual int IsSelected();

private:
  CATLinkExtension(const CATLinkExtension &iObject); // Prohibited
  CATLinkExtension &operator=(const CATLinkExtension &iObject); // Prohibited
};

#endif
