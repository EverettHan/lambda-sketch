#ifndef CATDlgSYPIconName_H
#define CATDlgSYPIconName_H

#include "DialogAPILevel.h"

#ifdef DialogAPI_DECLARATIVE_DIALOG_SUPPORT

#include "DI0PANV2.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include <CATSYPFactoryResult.h>
#include <CATBasicTypeFactory.h>

extern "C" ExportedByDI0PANV2
  CATSYPFactoryResult CATSYPCATDlgSYPIconNameFactory(const CATUnicodeString& i_string);
extern "C" ExportedByDI0PANV2
  HRESULT CATSYPCATDlgSYPIconNameSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);


/**
 * This class defines instrospectable icon names for Dialog objets in declarative files.
 * Factory and serializer functions are also defined in this file, next to the CATDlgSYPIconName implementation.
 * The following attributes can be used for this type inside a serialized string : Normal, Selected, Focused, Disabled, ForceSmall
 * Required attributes : Normal
 *    Example : 
 *    <CATDlgLabel SYPIconName="Normal=normalIcon Selected=selectedIcon Focused=chuckNorris Disabled=disabledIcon ForceSmall=forceSmallIcon"/>
*/

class ExportedByDI0PANV2 CATDlgSYPIconName : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATDlgSYPIconName ();
  virtual ~CATDlgSYPIconName ();

  CATString* Export();

  void SetNormal(CATString i_normal);
  void SetSelected(CATString i_selected);
  void SetFocused(CATString i_focused);
  void SetDisabled(CATString i_disabled);
  void SetForceSmall(CATString i_forceSmall);

  CATString GetNormal();
  CATString GetSelected();
  CATString GetFocused();
  CATString GetDisabled();
  CATString GetForceSmall();

private:


  CATString _pNormal;
  CATString _pSelected;
  CATString _pFocused;
  CATString _pDisabled;
  CATString _pForceSmall;

  CATString* _pExport;


};

#endif 

#endif
