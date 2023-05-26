// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlBorder.h
// Header definition of CATVidCtlBorder
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlBorder_H
#define CATVidCtlBorder_H

#include <VisuDialog.h>
#include <CATVidCtl.h>
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

//-----------------------------------------------------------------------
/**
* This widget is used to display component inside a frame.
* <b>Role</b>:
* This widget is used to display a component inside a frame. 
* It inherits the generic component CATVidCtlHeaderedContent.
* <br>
* Create this CATVidCtlBorder by using factory static method CreateCATVidCtlBorder.
* @ingroup VIDControls
*/
class ExportedByVisuDialog CATVidCtlBorder: public CATVidCtl
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATVidCtlBorder();
  static CATVidCtlBorder* CreateCATVidCtlBorder(CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetForegroundColor( const CATVidColor &i_foregroundColor );
  const CATVidColor &GetForegroundColor( void ) const;

  void SetBackgroundColor( const CATVidColor &i_backgroundColor );
  const CATVidColor &GetBackgroundColor( void ) const;
  
  virtual void SetChild(CATBaseUnknown_var i_spToConnect);

  virtual CATISYPPresenter_var GetItem();

  void SetContent(CATVidWidget* i_pContent);
  CATVidWidget* GetContent() const;

  void SetBorderItem(const CATISYPPresenter_var& i_spBorderItem);
  CATISYPPresenter_var GetBorderItem();
  CATBoolean GetUseIconFlag() const;
  CATBoolean  GetUseLabelFlag() const;

  /**
   * Specifies whether the border is visible or not.
   */
  void SetBorderVisibleFlag(CATBoolean i_visibleFlag);

  /**
   * Returns TRUE if the border is visible, FALSE otherwise.
   */
  CATBoolean GetBorderVisibleFlag() const;

protected:
	virtual ~CATVidCtlBorder ();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlBorder(CATVidCtlBorder &iToCopy);
  CATVidCtlBorder& operator=(CATVidCtlBorder& original);

private:
  CATVidColor                     _foregroundColor;
  CATVidColor                     _backgroundColor;

  CATVidWidget* _pContent;
  CATISYPPresenter_var _spBorderItem;
  CATBoolean _borderVisibleFlag;
};

//-----------------------------------------------------------------------
#endif
