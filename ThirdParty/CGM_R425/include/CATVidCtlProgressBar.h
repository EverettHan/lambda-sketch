// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlProgressBar.h
// Header definition of CATVidCtlProgressBar
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlProgressBar_H
#define CATVidCtlProgressBar_H

#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATBoolean.h>
#include <CATVidColor.h>
#include <CATUnicodeString.h>

class CATVidMinMax;
class CATVidCtlMenuItem;
class CATVidCtlContextMenu;
class CATVidGP;
class CATVidTooltip;
class CATISYPPresenter_var;

//-----------------------------------------------------------------------
/**
 * @ingroup VIDControls
 * 
 * This widget is a basic progress bar, either with minimum and maximal value, or infinite.
 */
class ExportedByVisuDialog CATVidCtlProgressBar: public CATVidCtl
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATVidCtlProgressBar();
  static CATVidCtlProgressBar* CreateProgressBar(CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetForegroundColor( const CATVidColor &i_foregroundColor );
  const CATVidColor &GetForegroundColor( void ) const;

  void SetBackgroundColor( const CATVidColor &i_backgroundColor );
  const CATVidColor &GetBackgroundColor( void ) const;
  
  void SetMinimumValue(int i_minimumValue);
  int GetMinimumValue() const;

  void SetMaximumValue(int i_maximumValue);
  int GetMaximumValue() const;

  void SetValue(int i_value);
  int GetValue() const;

  float GetPercentage() const;

  const CATBoolean GetInfiniteFlag( ) const;
  void SetInfiniteFlag( const CATBoolean& i_InfiniteFlag );

protected:
	virtual ~CATVidCtlProgressBar ();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlProgressBar(CATVidCtlProgressBar &iToCopy);
  CATVidCtlProgressBar& operator=(CATVidCtlProgressBar& original);


private:
  CATVidColor                     _foregroundColor;
  CATVidColor                     _backgroundColor;
  int _minimumValue;
  int _maximumValue;
  int _value;
  float _percentage;
  CATBoolean _InfiniteFlag;
};

//-----------------------------------------------------------------------
#endif
