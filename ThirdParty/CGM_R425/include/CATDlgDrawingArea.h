#ifndef CATDlgDrawingArea_H
#define CATDlgDrawingArea_H

#include "CATDlgBox.h"

class CATViewer;
class CATString;
class l_CATDlgDrawingArea;

/** 
 * This class lets handle the drawing area of a viewer.
 * Its usage must be restricted to CID Frame internal management
 */
class ExportedByDI0PANV2 CATDlgDrawingArea : public CATDlgBox
{
  CATDeclareClass;

public:
  /**
   * Get the CATDlgDrawingArea object attached to the drawing area of a viewer
   * @param iViewer the viewer
   * @param iCreateWhenNeeded set to TRUE to create the object when needed
   * @return the CATDlgDrawingArea object
   */
  static CATDlgDrawingArea * GetDrawingArea(CATViewer * iViewer, CATBoolean iCreateWhenNeeded = TRUE);

private:
  /**
   * Constructor
   * @param iParent the parent Dialog object
   * @param iName the name of the object
   * @param iStyle the style of the object
   */
  CATDlgDrawingArea(CATDialog * iParent, const CATString& iName, CATDlgStyle iStyle = NULL);

public:
  /**
   * Destructor
   */
  virtual ~CATDlgDrawingArea();

  /**
   * @nodoc
   * Returns the internal object.
   */
  virtual l_CATDialog * GetLetterObject();

  /**
   * @nodoc 
   * Resets the internal object.
   */
  virtual void ResetLetterObject();

private:
  // Forbidden constructors
  CATDlgDrawingArea(CATDlgDrawingArea&);
  CATDlgDrawingArea& operator = (CATDlgDrawingArea&);

  l_CATDlgDrawingArea * _plDrawingArea;
};

#endif
