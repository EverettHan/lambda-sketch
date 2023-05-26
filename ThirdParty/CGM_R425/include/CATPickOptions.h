#ifndef CATPickOptions_H
#define CATPickOptions_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "SGInfra.h"

/** @nodoc */
#define CATViz_Pick_SubElementsLevel                        (0x0)
/** @nodoc */
#define CATViz_Pick_SubSubElementsLevelFor3DPoints          (0x1)
/** @nodoc */
#define CATViz_Pick_SubSubElementsLevelFor3DLines           (0x2)
/** @nodoc */
#define CATViz_Pick_SubSubElementsLevelFor3DTriangles       (0x4)

/**
* Class representing the pick options within a visualized viewer.
* <br><b>Role</b> : it describes the pick options associated to a viewer.
* 
*/
class ExportedBySGInfra CATPickOptions
{
public :

  /**
   * Default constructor.
   */
  CATPickOptions ();

  virtual ~CATPickOptions ();
  
  /**
   * Sets the window size for simple pick in pixels.
   * <br><b>Role</b> : sets the picking window width and height for simple pick.
   *
   * @param iPixelSize
   *        The pixel size.
   */
  void SetSimplePickWindowSize (int iPixelSize);

  /**
   * Gets the window size for simple pick in pixels.
   * <br><b>Role</b> : gets the picking window width and height for simple pick.
   *
   * @param oPixelSize
   *        The pixel size.
   */
  void GetSimplePickWindowSize (int& oPixelSize) const;

  /**
   * Sets the sub sub elements mode for simple pick
   * <br><b>Role</b> : sets if simple pick uses sub elements level or a sub sub element level
   * <br>for specific sub sub element
   *
   * @param iSubSubElementsMode
   * The sub sub elements mode.
   */
  void SetSubSubElementsModeForSimplePick (const int iSubSubElementsMode);

  /**
   * Gets the sub sub elements mode for simple pick
   * @param oSubSubElementsMode
   * The sub sub elements mode.
   */
  void GetSubSubElementsModeForSimplePick (int& oSubSubElementsMode) const;

protected :
  
  //  sub sub element picking mode
  //  ----------------------------
  int _subSubElementsMode;   

private :

  /**
   * Copy constructor.
   *
   * @param iPickOptions
   *        The pick options to copy.
   */
  CATPickOptions (const CATPickOptions& iPickOptions);

  /**
   * Operator of assignment.
   *
   * @param iPickOptions
   *        The pick options use to create a new one identical.
   *
   * @return
   *        The new pick options created by assignment.
   */
  CATPickOptions & operator = (const CATPickOptions& iPickOptions);

};

#endif
