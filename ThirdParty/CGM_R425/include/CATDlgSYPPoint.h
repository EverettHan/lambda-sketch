#ifndef CATDlgSYPPoint_H
#define CATDlgSYPPoint_H

#include "DialogAPILevel.h"

#ifdef DialogAPI_DECLARATIVE_DIALOG_SUPPORT

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "DI0PANV2.h"
#include "CATDlgUtility.h"
#include <CATSYPFactoryResult.h>
#include <CATBasicTypeFactory.h>

extern "C" ExportedByDI0PANV2
  CATSYPFactoryResult CATSYPCATDlgSYPPointFactory(const CATUnicodeString& i_string);
extern "C" ExportedByDI0PANV2
  HRESULT CATSYPCATDlgSYPPointSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

/**
 * This class defines instrospectable points for Dialog objets in declarative files.
 * Factory and serializer functions are also defined in this file, next to the CATDlgSYPPoint implementation.
 * The following attributes can be used for this type inside a serialized string : X, Y.
 * Required attributes : All
 *    Example : 
 *    <CATDlgPushButton RectPosition="X=1 Y=1"/>
*/


class ExportedByDI0PANV2 CATDlgSYPPoint : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATDlgSYPPoint ();
  virtual ~CATDlgSYPPoint ();

  CATDlgSYPPoint(const DPOS & i_pos);

  /** 
  * Simple conversion methods
  **/
  void Import(const DPOS & i_pos);
  const DPOS Export();

  void SetCoordinates(int i_x, int i_y);

  int GetX();
  int GetY();
  void SetX(int i_x);
  void SetY(int i_y);

private: 

  DPOS _pPos;
  int _pX;
  int _pY;


};

#endif

#endif
