#ifndef CATIconMask_H
#define CATIconMask_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATInteractiveInterfaces.h"

class CATUnicodeString;

/**
 * Mask to add on an icon.
 * <b>Role</b>: A mask can be added on an icon in order to provide more information to the user.<br>
 * Notice that <tt>CATDeskItem</tt> is not an object modeler interface.
 */
class ExportedByCATInteractiveInterfaces CATIconMask
{
public:
  CATIconMask();
  virtual ~CATIconMask();

  /**
   * Adds a mask on an icon.
   * @param iMaskFile
   *   Path of the mask to add.<br>
   *   If <tt>iMaskFile</tt> contains a separator of directory ("\" or "/"), <tt>iMaskFile</tt> must be a path that points an existing icon file.<br>
   *   Otherwise <tt>iMaskFile</tt> must be the name of the icon file.
   * @param iXVal
   *   Coordonate of mask (usually 0).
   * @param iYVal
   *   Coordonate of mask (usually 0).
   * @param iTransVal
   *   Translatory  value (usually 0).
   */
  virtual void AddMask(const CATUnicodeString &iMaskFile, int iXVal, int iYVal, int iTransVal = 0) = 0;
};

#endif
