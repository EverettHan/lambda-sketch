// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidColorAction.h
// Header definition of CATVidColorAction
//
//=============================================================================
//  June 2012  Creation: LD5
//=============================================================================
#ifndef CATVidColorAction_H
#define CATVidColorAction_H

#include <VisuDialog.h>
#include <CATVidAction.h>
#include <CATVidColor.h>

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 *
 * Basic class for actions that uses a color.
 */
class ExportedByVisuDialog CATVidColorAction : public CATVidAction
{
  CATDeclareClass;

public:
  /**
   * Default constructor. Sets the color to opaque black: <tt>(0 0 0 255)</tt>.
   */
  CATVidColorAction();
  /**
   * Constructor with a color.
   *
   * @param i_color the color used for this action.
   */
  CATVidColorAction(CATVidColor i_color);
  /**
   * @return the color used for this action.
   */
  CATVidColor GetColor() const;
  /**
   * Sets the color used for this action. Used internally in addition to
   * default constructor for introspection. When creating this action in C++,
   * you can directly call the color-parametered constructor.
   *
   * @param i_color the color that must be considered when this action is ran.
   */
  void SetColor(CATVidColor i_color);

protected:
  /** Destructor. */
  virtual ~CATVidColorAction();

private:
  /** Copy constructor. */
  CATVidColorAction(CATVidColorAction &);
  /** Copy operator. */
  CATVidColorAction& operator=(CATVidColorAction& original);

private:
  /** The color used for this action. */
  CATVidColor _color;
};

//-----------------------------------------------------------------------------
#endif
