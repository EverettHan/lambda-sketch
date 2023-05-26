#ifndef CATVizMetaClass_H
#define CATVizMetaClass_H

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME*/
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATVizMetaClassList.h"
#include "SGInfra.h"
#include "list.h"
#include "CATAssert.h"

class ExportedBySGInfra CATVizMetaClass
{
public:
   // Standard constructor / destructor
   CATVizMetaClass(const char * iName, const CATVizMetaClass * iFather);
   ~CATVizMetaClass();

   inline const int IsA      (const CATVizMetaClass     & iMeta) const;
   inline const int IsAKindOf(const CATVizMetaClass     & iMeta) const;
   inline const int IsAKindOf(const CATVizMetaClassList & iList) const;
   
   inline const char            * GetMetaName()              const;
   inline const CATVizMetaClass * GetMetaObjectOfBaseClass() const;
   
   inline CATVizMetaClass &   operator =  (const CATVizMetaClass & iToCopy);
   inline const int           operator == (const CATVizMetaClass & iToCompare) const;
   inline const int           operator != (const CATVizMetaClass & iToCompare) const;
   inline CATVizMetaClassList operator |  (const CATVizMetaClass & iToAdd) const;
   inline                     operator CATVizMetaClassList () const;

protected:

   const CATVizMetaClass  * _father;
   char                   * _name;
};

// INLINED METHODS

inline const int CATVizMetaClass::IsA(const CATVizMetaClass & iMeta) const
{
   return ((*this) == iMeta);
}

inline const int CATVizMetaClass::IsAKindOf(const CATVizMetaClass & iMeta) const
{
   const CATVizMetaClass * meta = this;
   while(meta)
   {
      if((*meta) == iMeta)
         return 1;
      else
         meta = meta->_father;
   }
    
   return 0;
}

inline const int CATVizMetaClass::IsAKindOf(const CATVizMetaClassList & iList) const
{
   const CATVizMetaClass * meta = NULL;
   unsigned int i=0;
   while(meta = iList[i++])
   {
      if(IsAKindOf(*meta))
         return 1;
   }
   return 0;
}

inline const char * CATVizMetaClass::GetMetaName() const
{
   return _name;
}

inline const CATVizMetaClass * CATVizMetaClass::GetMetaObjectOfBaseClass() const
{
   return _father;
}

inline CATVizMetaClass & CATVizMetaClass::operator = (const CATVizMetaClass & iToCopy)
{
   _father = iToCopy._father;
   return (*this);
}

inline const int CATVizMetaClass::operator == (const CATVizMetaClass & iToCompare) const
{
   if(&iToCompare == this)
      return 1;
   
   return 0;
}

inline const int CATVizMetaClass::operator != (const CATVizMetaClass & iToCompare) const
{
   return !((*this) == iToCompare);
}

inline CATVizMetaClassList CATVizMetaClass::operator | (const CATVizMetaClass & iToAdd) const
{
   CATVizMetaClassList list;
   list.AddMetaClass(*this);
   list.AddMetaClass(iToAdd);
   return list;
}

inline CATVizMetaClass::operator CATVizMetaClassList () const
{
   CATVizMetaClassList list;
   list.AddMetaClass(*this);
   return list;
}

#endif
