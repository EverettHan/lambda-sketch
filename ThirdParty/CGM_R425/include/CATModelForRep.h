#ifndef CATModelForRep_H
#define CATModelForRep_H

//
//  copyright dassault systemes 2001
//  --------------------------------
//
/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 *  Base class for dialog help objects.
 *  <b>Role:</b> 
 *  This class is a the main class (implementation) of a component that 
 *  implements a visualization interface.
 *  It is dedicated to hold a graphic representation of an object that is 
 *  not part of the document, but is used to ease the dialog. This
 *  representation is to be built outside and set to the component.
 *  <br><br>
 *  For example, it can hold the representation of a local 3D-axis system to 
 *  enable the end user to indicate an axis.
 *  Such a component it can be put into the <i>CATISO</i> to be displayed, and thus 
 *  selectable. Converted as a @href CATPathElement, it can be put into the 
 *  @href CATHSO, 
 *  and @href CATPSO objects to be highlighted, and prehighlighted respectively.
 *  <br><br>
 *  Since this class is a base class, do not use it directly. Use its 
 *  derived classes instead:
 *  <ul>
 *  <li>@href CATModelForRep2D that implements CATI2DGeoVisu</li>  
 *  <li>@href CATModelForRep3D that implements CATI3DGeoVisu</li>
 *  </ul>
 */


#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "list.h"

class CATRep;

class ExportedBySGInfra CATModelForRep : public CATBaseUnknown 
{
  CATDeclareClass;

public:
 
  virtual ~CATModelForRep();

  /**
   * @nodoc 
   * Associates the CATModelForRep with the given representation iRep.
   *
   * @param iRep
   *   the given representation which you want CATModelForRep to be associated with.
   *   Once the representation iRep has been associated to a CATModelForRep its lifecycle is
   *   managed by the CATVisManager.
   */
  virtual void SetRep (CATRep * iRep);

  /**
   * Returns a pointer to the graphic representation.
   */
  virtual CATRep *GiveRep();

  /**
   * @nodoc
   * Sets the representation associated to this object to NULL.
   */
  void UnreferenceRep(void);

  /** @nodoc */
  void SetSubElementList(const list<int> &subElement);
  /** @nodoc */
  const list<int> & GetSubElementList() const;


protected:
  /** @nodoc*/
  CATModelForRep();

private:
  CATRep *_EnclosedRep;
  list<int>  _subElementList;
};


#endif
