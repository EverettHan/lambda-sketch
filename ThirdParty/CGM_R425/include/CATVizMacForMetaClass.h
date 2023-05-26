#ifndef CATVizMacForMetaClass_H
#define CATVizMacForMetaClass_H

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME*/
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATVizMetaClass.h"

#define CATVizIsAKindOf(Object, Meta) (Object && Object->MetaClass().IsAKindOf(Meta))


#define CATVizDeclareMeta(MetaName)                                     \
extern CATVIZMETAEXPORT const CATVizMetaClass MetaName                  \

#define CATVizImplementBaseMeta(MetaName)                               \
const CATVizMetaClass MetaName(#MetaName, NULL)                         \

#define CATVizImplementMeta(MetaName,BaseMeta)                          \
const CATVizMetaClass MetaName(#MetaName, &BaseMeta)                    \

#define CATVizDeclareClass                                              \
public:                                                                 \
  virtual int IsAKindOf(const CATVizMetaClass & iMeta) const;           \
  virtual int IsAKindOf(const CATVizMetaClassList & iList) const;       \
  virtual const CATVizMetaClass & MetaClass() const;                    \
  virtual const char * VizIsA() const                                   \


#define CATVizImplementClass(ClassName, MetaName)                       \
int ClassName::IsAKindOf(const CATVizMetaClass & iMeta) const           \
{                                                                       \
   return MetaName.IsAKindOf(iMeta);                                    \
}                                                                       \
int ClassName::IsAKindOf(const CATVizMetaClassList & iList) const       \
{                                                                       \
   return MetaName.IsAKindOf(iList);                                    \
}                                                                       \
const CATVizMetaClass & ClassName::MetaClass() const                    \
{                                                                       \
   return MetaName;                                                     \
}                                                                       \
const char * ClassName::VizIsA() const                                  \
{                                                                       \
   return #ClassName;                                                   \
}                                                                       \

#endif
