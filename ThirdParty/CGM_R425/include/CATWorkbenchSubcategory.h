#ifndef CATWorkbenchSubcategory_h
#define CATWorkbenchSubcategory_h

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATListOfCATString.h"

#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2005

/*
 Start Menu Subcategories management
*/

class ExportedByCATAfrFoundation CATWorkbenchSubcategory
{
  
public:

  CATWorkbenchSubcategory(const CATString &);
  virtual ~CATWorkbenchSubcategory();

  static CATWorkbenchSubcategory * GetFirstSubcategory();
  static CATWorkbenchSubcategory * GetSubcategory(const CATString &);
  static CATString SubcategoryMarker;

  const CATString        & GetIconName();
  const CATString        & GetName();
  const CATUnicodeString & GetTitle();
  const CATString        & GetPosition();

  void SetNext(CATWorkbenchSubcategory *);
  CATWorkbenchSubcategory *GetNext();


private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATWorkbenchSubcategory ();
  CATWorkbenchSubcategory (const CATWorkbenchSubcategory &);
  CATWorkbenchSubcategory & operator= (const CATWorkbenchSubcategory &);

  static CATWorkbenchSubcategory *_staticFirstSubcategory;
  
  void LoadResources();

  CATWorkbenchSubcategory *_next;

  CATBoolean       _resourcesOK;
  CATString        _iconName;
  CATString        _name;
  CATUnicodeString _title;
  CATString        _category;
  CATString        _position;
};

#endif
