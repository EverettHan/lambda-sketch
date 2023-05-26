// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtlColorPalette.h
// Header definition of CATVidCtlColorPalette
//
//===================================================================
//  Oct 2005  Creation: qjp
//===================================================================
#ifndef CATVidCtlColorPalette_H
#define CATVidCtlColorPalette_H

#include <VisuDialog.h>
#include <CATVidCtlColorPicker.h>

class ExportedByVisuDialog CATVidCtlColorPalette: public CATVidCtlColorPicker
{
  CATDeclareClass;
public:

  enum LayoutMode {
    Grid=0,
    List
  };

  CATVidCtlColorPalette ();

  /**
  * @return the dimension of the swatches icon
  */
  const CATMathPoint2Df & GetSwatchDimension() const;

  int GetItemsCount() const;
  int GetHasItemsFlag() const;

  /**
  * Sets the layout mode of the widget
  * @see # CATVidCtlColorPalette::LayoutMode for available options.
  */
  void SetLayoutMode ( CATVidCtlColorPalette::LayoutMode i_Mode );

  /** @return the layout mode*/
  CATVidCtlColorPalette::LayoutMode GetLayoutMode() const;  

  int GetPaletteSelectedColor(CATVidRGBA & o_SelectedColor);

  void ClearColorSelection();

  /**
  * If TRUE, alpha channel is used when adding colors. Otherwise, only RGB and alpha is set to 255.
  */
  void SetStoreTransparencyFlag(const CATBoolean& i_storeTransparencyFlag);
  /**
  * @see SetStoreTransparencyFlag
  */
  CATBoolean GetStoreTransparencyFlag() const;

protected:
  virtual ~CATVidCtlColorPalette ();
  CATVidCtlColorPalette(CreateLetterFunc i_pCreateLetterFunc);
  
  /**
   * @copydoc l_CATVidCtl#TemplateDataUpdated
   * Here are the mandatory "syp:named" objects :
   * @li WheelContainer [CATVidLayLayer]
   */
  virtual void TemplateDataUpdated();

private:
  CATVidCtlColorPalette (CATVidCtlColorPalette &);
  CATVidCtlColorPalette& operator=(CATVidCtlColorPalette&);

  friend class l_CATVidCtlColorPalette;


//Deprecated : please do not use!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
public : 

  //Deprecated : please do not use!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
  /**
  * Sets the dimension of the swatches icon
  * @param i_dimension
  * The 2D point representing the dimension of the icon.
  */
  void SetSwatchDimension( const CATMathPoint2Df &i_dimension);

};
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlColorPalette__LayoutMode);

//-----------------------------------------------------------------------

#endif
