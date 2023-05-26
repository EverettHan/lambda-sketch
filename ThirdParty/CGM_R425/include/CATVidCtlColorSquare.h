//===================================================================
// COPYRIGHT COPYRIGHT DASSAULT SYSTEMES 2011/09/22
//===================================================================
// CATVidCtlColorSquare.cpp
// Header definition of class CATVidCtlColorSquare
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/09/22 Creation: RZH
//===================================================================

#ifndef CATVidCtlColorSquare_H
#define CATVidCtlColorSquare_H

#include <VisuDialog.h>
#include <CATVidCtlColorAbstractShape.h>

/**
 * This widget provides a gradient color square with a slider on the side to choose a color.
 * <b>Role</b>:
 * This widget is used to choose a color in HSL color space.
 */
//-----------------------------------------------------------------------
class ExportedByVisuDialog CATVidCtlColorSquare : public CATVidCtlColorAbstractShape
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidCtlColorSquare ();
  virtual ~CATVidCtlColorSquare ();

  /**
   * Create a standard ColorSquare.
   */
  static CATVidCtlColorSquare* CreateColorSquare(CATCommand* i_pParent, const CATString& i_pIdentifier);

  /**
   * Create a ColorSquare that can be used within a 3D scene through V3D.
   */
  static CATVidCtlColorSquare* CreateImmersiveColorSquare(CATCommand* i_pParent, const CATString& i_pIdentifier);

  /**
  * Square Mode - The main color component 
  */
  enum SquareMode {
    /** Hue Mode for the slider*/
    Hue=0,
    /** Value Mode for the slider*/
    Value,
    /** Saturation Mode for the slider*/
    Saturation
  };

  /**
  * Sets the Main color mode of the square. This is the color component controlled
  * by the slider on the side of this color picker.
  * @see #Square Color Mode for available options.
  */
  void SetSquareColorMode ( CATVidCtlColorSquare::SquareMode i_Mode );
  /** @return the color mode*/
  CATVidCtlColorSquare::SquareMode GetSquareColorMode() const;

  /**
  * @copydoc l_CATVidCtl#TemplateDataUpdated
  */
  virtual void TemplateDataUpdated();

  virtual void Update();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlColorSquare(CATVidCtlColorSquare &);
  CATVidCtlColorSquare& operator=(CATVidCtlColorSquare&);

};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlColorSquare__SquareMode);

//-----------------------------------------------------------------------
#endif
