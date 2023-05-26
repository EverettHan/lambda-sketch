// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlTabPage.h
// Header definition of CATVidCtlTabPage
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlTabPage_H
#define CATVidCtlTabPage_H

#include <VisuDialog.h>
#include <CATVidCtlHeaderedContent.h>
#include <CATBoolean.h>
#include <CAT4x4Matrix.h>
#include <CATMathPointf.h>
#include <CATVidCursor.h>
#include <CATVidColor.h>
#include <CATISYPPresenter.h>

class CATVidMinMax;
class CATVidCtlMenuItem;
class CATVidCtlContextMenu;
class CATVidGP;
class CATVidTooltip;
class CATISYPPresenter_var;
/**
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlTabPage: public CATVidCtlHeaderedContent
{
  CATDeclareClass;
  friend class CATVidCtlTabPageSYPIntro;

public:
  static CATVidCtlTabPage* CreateTabPage(CATCommand *i_pParent, const CATString & i_pIdentifier);
  CATVidCtlTabPage();

protected:
  virtual ~CATVidCtlTabPage ();
private:
  CATVidCtlTabPage(CATCommand *i_pParent, const CATString & i_pIdentifier);
};
//-----------------------------------------------------------------------
#endif
