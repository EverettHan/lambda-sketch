#ifndef CATModelIdPath_H
#define CATModelIdPath_H

#include "CATBaseUnknown.h"
#include "SceneGraphManager.h"
#include "CATVizPtrList.h"

class CATPathElement;

class ExportedBySceneGraphManager CATModelIdPath : public CATBaseUnknown
{
public:
  CATModelIdPath();
  virtual ~CATModelIdPath();

  /**
  * Returns the number of element in the path
  */
  unsigned int GetLength();

  /**
  * Returns the persistent id (#ele, cgm id) of the ith element in the path
  */

  unsigned int GetId(unsigned int index);

  /**
  * Returns the naming context of the ith element in the path
  *  return value :
  *  1 : the element is a feature, its id is a #ele
  *  2 : the element is a cgm object, its id is a cgm id
  */

  unsigned int GetNamingContext(unsigned int index);

  /**
  * Returns the number of sub-elements (geometrical cells) in the path
  */

  unsigned int GetNumberOfSubElements();

  /**
  * Returns the cgm id of the ith sub-element
  */

  unsigned int GetSubElementId(unsigned int index);

  /**
  * Build a CATModelIdPath from a Visu Mode PathElement.
  * The return value must be released by the caller.
  */

  static CATModelIdPath *GenerateModeIdPathFromPathElement(CATPathElement *elt);

  /**
  Adds the id of an element, with its naming context
  */
  void AddId(unsigned int id, unsigned int namingContext);

  /**
  Adds the ID of a subelement
  */
  void AddSubElementId(unsigned int id);

  /**
  Clears the CATModelIdPath (remove every element and subelement ids)
  */
  void Clear();

  

private:

  
  CATVizPtrList<unsigned int> _ids;
  CATVizPtrList<unsigned int> _namingContexts;
  CATVizPtrList<unsigned int> _subElementsIds;
};

#endif
