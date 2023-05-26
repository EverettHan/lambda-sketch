#ifndef CATVidTabPopOverEventArgs_H
#define CATVidTabPopOverEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"
#include "CATBaseUnknown_WR.h"
#include "CATMathPoint2Df.h"
class CATPixelImage;
class CATVidCtlTabButton;


class ExportedByVisuDialog CATVidTabPopOverEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the event dispatched.
   * @param i_pButton the tab button currently hovered.
   */
  CATVidTabPopOverEventArgs(CATSYPEvent * i_pEvent, CATVidCtlTabButton * i_pButton);
  /** Destroy this class */
  virtual ~CATVidTabPopOverEventArgs();
  /**
   * @param i_pixelImage the image to display on pop over. Will be @c AddRef-ed.
   */
  void SetImage(CATPixelImage * i_pixelImage);
  /**
   * @return the image to display on pop over.
   */
  CATPixelImage * GetImage() const;
  /**
   * @param i_dimension the Dimension of the pop over popup. 
   */
  void SetDimension(const CATMathPoint2Df & i_dimension);
  /**
   * @return the Dimension to display on pop over.
   */
  CATMathPoint2Df GetDimension() const;
  /**
   * @return the tab button currently hovered.
   */
  CATVidCtlTabButton * GetTabButton();

private:
  CATVidTabPopOverEventArgs(const CATVidTabPopOverEventArgs &);
  CATVidTabPopOverEventArgs &operator=(const CATVidTabPopOverEventArgs &);
private:
  /** @see #SetImage */
  CATPixelImage * _pImage;
  /** Weak reference on the tab button currently hovered.  */
  CATBaseUnknown_WR _wrTabButton;
  /** @see #GetDimension */
  CATMathPoint2Df _dimension;
};

#endif // CATVidTabPopOverEventArgs_H
