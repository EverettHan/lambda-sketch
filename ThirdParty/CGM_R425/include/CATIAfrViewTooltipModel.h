//===================================================================
// COPYRIGHT Microsoft 2011/06/10
//===================================================================
// CATIAfrViewTooltipModel.cpp
// Header definition of class CATIAfrViewTooltipModel
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/06/10 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIAfrViewTooltipModel_H
#define CATIAfrViewTooltipModel_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
//---------------------------------------------------------------------- System
#include "CATString.h"
#include "CATUnicodeString.h"

class CATVizViewer;
class CATCommand;
class CATNotification;

extern ExportedByCATAfrItf  IID IID_CATIAfrViewTooltipModel ;


class ExportedByCATAfrItf CATIAfrViewTooltipModel: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual CATVizViewer *GetViewer(void) = 0;
  /**
  * Get tooltip
  **/
  virtual CATUnicodeString GetTooltip( void )= 0;
  // DBE August 2007 +
  virtual CATString GetTooltipIconName( void )= 0;
  virtual CATUnicodeString GetTooltipLink( CATCommand* widget )= 0;
  virtual CATCommand* GetCurrentWidget(CATNotification*& oToolTipLinkNotification)= 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIAfrViewTooltipModel, CATBaseUnknown );

#endif
