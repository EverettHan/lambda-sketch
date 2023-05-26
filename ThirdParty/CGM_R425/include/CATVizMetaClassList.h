#ifndef CATVizMetaClassList_H
#define CATVizMetaClassList_H

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME*/
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "SGInfra.h"
#include "list.h"

class CATVizMetaClass;

class ExportedBySGInfra CATVizMetaClassList
{
public:

   CATVizMetaClassList();
   CATVizMetaClassList(const CATVizMetaClassList & iToCopy);
   inline int IsEmpty();
   inline void AddMetaClass(const CATVizMetaClass & iToAdd);
   inline int  ContainsMetaClass(const CATVizMetaClass & iCompare) const;

   inline CATVizMetaClassList &   operator =  (const CATVizMetaClassList & iToCopy);
   inline const CATVizMetaClass * operator [] (unsigned int iIndex) const;
   inline CATVizMetaClassList     operator |  (const CATVizMetaClass & iToAdd) const;
   inline CATVizMetaClassList &   operator |= (const CATVizMetaClass & iToAdd);

protected:

   ::list<const CATVizMetaClass> _metaList;
};


// INLINED METHODS
inline int CATVizMetaClassList::IsEmpty()
{
   return _metaList.length() ? 0 : 1;
}

inline void CATVizMetaClassList::AddMetaClass(const CATVizMetaClass & iToAdd)
{
   _metaList.fastadd(iToAdd);
}

inline int CATVizMetaClassList::ContainsMetaClass(const CATVizMetaClass & iCompare) const
{
   for(int i = _metaList.length() - 1; i >= 0; i--)
      if(_metaList[i] == &iCompare) return 1;
      return 0;
}

inline CATVizMetaClassList & CATVizMetaClassList::operator = (const CATVizMetaClassList & iToCopy)
{
   _metaList.empty();
   _metaList = iToCopy._metaList;
   return (*this);
}

inline const CATVizMetaClass * CATVizMetaClassList::operator [] (unsigned int iIndex) const
{
   return _metaList[iIndex];
}

inline CATVizMetaClassList CATVizMetaClassList::operator | (const CATVizMetaClass & iToAdd) const
{
   CATVizMetaClassList list(*this);
   list.AddMetaClass(iToAdd);
   return list;
}

inline CATVizMetaClassList & CATVizMetaClassList::operator |= (const CATVizMetaClass & iToAdd)
{
   AddMetaClass(iToAdd);
   return (*this);
}

#endif
