#ifndef CATDlgSYPRectDimensions_H
#define CATDlgSYPRectDimensions_H

#include "DialogAPILevel.h"

#ifdef DialogAPI_DECLARATIVE_DIALOG_SUPPORT

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "DI0PANV2.h"
#include "CATDlgUtility.h"
#include <CATSYPFactoryResult.h>
#include <CATBasicTypeFactory.h>

extern "C" ExportedByDI0PANV2
  CATSYPFactoryResult CATSYPCATDlgSYPRectDimensionsFactory(const CATUnicodeString& i_string);
extern "C" ExportedByDI0PANV2
  HRESULT CATSYPCATDlgSYPRectDimensionsSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

/**
 * This class defines instrospectable rect dimensions for Dialog objets in declarative files.
 * Factory and serializer functions are also defined in this file, next to the CATDlgSYPRectDimensions implementation.
 * The following attributes can be used for this type inside a serialized string : X, Y, Dx Dy.
  * Required attributes : All
 *    Example : 
 *    <CATDlgPushButton RectDimensions="X=1 Y=1 Dx=1 Dy=1"/>
*/


class ExportedByDI0PANV2 CATDlgSYPRectDimensions : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATDlgSYPRectDimensions ();
  virtual ~CATDlgSYPRectDimensions ();

  /** 
  * Simple conversion methods
  **/
  void Import(const DRECT & i_rect);
  const DRECT Export();

  void SetRect(int i_x, int i_y, int i_dx, int i_dy);

private: 

  DRECT _pRect;
  int _pX;
  int _pY;
  int _pDx;
  int _pDy;

};

#endif

#endif
