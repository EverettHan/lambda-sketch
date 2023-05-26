/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CAT_OBJECT_META_TYPE_H_
#define CAT_OBJECT_META_TYPE_H_

/**
 * @level Private
 * @usage U1
 */

#include "CATMetaObject.h"
#include "CATObject.h"
#include "CATOMY.h"
#include "CATDataType.h"

#define VCS_declare_inheritance_tree
#define VCS_activate_inheritance_tree

class CATSysSimpleHashTable;


class ExportedByCATOMY CATObjectMetaType: public CATMetaClass
{
public:
  static CATObjectMetaType* find (CATClassId type);
  static CATObjectMetaType* create (CATClassId type, CATObjectMetaType* superType=0);

  CATMetaClass * __stdcall GetMetaObject() const;
  CATClassId     IsA() const ;
  int            IsAKindOf(CATClassId) const;		
  
  CATObjectMetaType*		superType() const ;
  static void RemoveAllMeta();

private:
  CATObjectMetaType();
  CATObjectMetaType(const CATObjectMetaType& from);
  CATObjectMetaType& operator= (const CATObjectMetaType& from);
  ~CATObjectMetaType();
};


#endif
