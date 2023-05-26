#ifndef CATDlgSYPInterval_H
#define CATDlgSYPInterval_H

#include "DialogAPILevel.h"

#ifdef DialogAPI_DECLARATIVE_DIALOG_SUPPORT

#include "DI0PANV2.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDlgUtility.h"
#include <CATSYPFactoryResult.h>
#include <CATBasicTypeFactory.h>

extern "C" ExportedByDI0PANV2
  CATSYPFactoryResult CATSYPCATDlgSYPIntervalFactory(const CATUnicodeString& i_string);
extern "C" ExportedByDI0PANV2
  HRESULT CATSYPCATDlgSYPIntervalSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

/**
 * This class defines instrospectable interval for Dialog objets in declarative files.
 * Factory and serializer functions are also defined in this file, next to the CATDlgSYPInterval implementation.
 * The following attributes can be used for this type inside a serialized string : Begin, End, Increment (Fraction can also be used)
 * Required attributes : Begin, End
 *    Example : 
 *    <CATDlgSpinner SYPMinMaxStep="Begin=1 End=8 Increment=1"/>
*/


class ExportedByDI0PANV2 CATDlgSYPInterval : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATDlgSYPInterval ();
  virtual ~CATDlgSYPInterval ();

  /** 
  * Simple conversion methods
  **/
  void ImportInteger(const DPOS & i_interval);
  const DPOS ExportInteger();

  double GetBegin();
  double GetEnd();
  double GetIncrement();
  void SetBegin(double i_x);
  void SetEnd(double i_y);
  void SetIncrement(double i_increment);

private: 

  DPOS _pIntegerInterval;
  double _pBegin;
  double _pEnd;
  double _pIncrement;

};

#endif

#endif
