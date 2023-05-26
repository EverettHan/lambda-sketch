#ifndef CATDlgSYPColor_H
#define CATDlgSYPColor_H

#include "DialogAPILevel.h"

#ifdef DialogAPI_DECLARATIVE_DIALOG_SUPPORT

#include "DI0PANV2.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include <CATSYPFactoryResult.h>
#include <CATBasicTypeFactory.h>

extern "C" ExportedByDI0PANV2
  CATSYPFactoryResult CATSYPCATDlgSYPColorFactory(const CATUnicodeString& i_string);
extern "C" ExportedByDI0PANV2
  HRESULT CATSYPCATDlgSYPColorSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

/**
 * This class defines instrospectable color for Dialog objets in declarative files.
 * Factory and serializer functions are also defined in this file, next to the CATDlgSYPColor implementation.
 * The following attributes can be used for this type inside a serialized string : Red, Green, Blue
 * Required attributes : All
 *    Example : 
 *    <CATDlgPushButton SYPColor="Red=255 Green=255 Blue=255"/>
*/

class ExportedByDI0PANV2 CATDlgSYPColor : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATDlgSYPColor ();
  virtual ~CATDlgSYPColor ();

  unsigned char* Export();

  void SetR(unsigned char i_r);
  void SetG(unsigned char i_g);
  void SetB(unsigned char i_b);

  unsigned char GetR();
  unsigned char GetG();
  unsigned char GetB();


private:


  unsigned char _pR;
  unsigned char _pG;
  unsigned char _pB;

  unsigned char* _pColor;

};

#endif

#endif
