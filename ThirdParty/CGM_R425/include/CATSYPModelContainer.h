#ifndef CATSYPModelContainer_H
#define CATSYPModelContainer_H

#include <CATStyleProcessor.h>
#include <CATSYPArray.h>
#include <CATUnicodeString.h>

class CATSYPModelTag;

class ExportedByCATStyleProcessor CATSYPModelContainer
{
public:
  /**
  * Constructor.
  * @param i_name name of the container, corresponding to the
  * instrospectable property that allow access to the container 
  * collection or presenter). Can be an empty string when it
  * is the default container of the object.
  */
  CATSYPModelContainer(const CATUnicodeString& i_name);
  ~CATSYPModelContainer();
  /**
  *@return the list of the children.
  */
  const CATSYPDynArray<CATSYPModelTag*>& GetChildren() const;
  /**
  * Adds a child to the container.
  * AddRef() WON'T be called on i_pChild.
  */
  void AddChild(CATSYPModelTag* i_pChild);

  /**
  * Insert a child to the container on i_index.
  * AddRef() WON'T be called on i_pChild.
  */
  void InsertChild(CATSYPModelTag* i_pChild,int i_index);
  /**
  * Removes a child from the container
  * Release() WON'T be called on i_pChild.
  */
  void RemoveChild(CATSYPModelTag* i_pChild);
  /**
  * Removes a child from the container
  * Release() WILL be called on i_pChild.
  */
  void DeleteChild(CATSYPModelTag* i_pChild);
  /**
  * Replace i_pChildToReplace by i_pChildReplacement in the container
  * Release() WON'T be called on i_pChildToReplace.
  * AddRef() WON'T be called on i_pChildReplacement.
  */
  void ReplaceChild(CATSYPModelTag* i_pChildToReplace,CATSYPModelTag* i_pChildReplacement);
  /**
  *@return 1 if i_pChildTag is a child of "this" container
  *else 0
  */
  int IsChild(CATSYPModelTag* i_pChild);
  /**
  * @retrun the name of the Container
  */
  const CATUnicodeString& GetName() const;
  /**
  * calls CATSYPModelTag::CleanAllProperties on every children
  */
  void CleanAllProperties();
private:
  /** Copy Constructor */
  CATSYPModelContainer(const CATSYPModelContainer &i_toCopy);
  /** Operator = */
  CATSYPModelContainer& operator = (const CATSYPModelContainer &i_toCopy);
private:
  CATUnicodeString _name;
  CATSYPDynArray<CATSYPModelTag*> _children;
};

#endif
