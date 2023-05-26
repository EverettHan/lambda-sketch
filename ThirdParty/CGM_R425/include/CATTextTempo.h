// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATTextTempo_H
#define CATTextTempo_H
////////////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// 23/05/97
//
// Purpose: CATTextTempo
//          To Allow a Text Interface onto a tempo object
//
////////////////////////////////////////////////////////////////////////////////////////

#include<CATIText.h>
#include<LifeCycleObject.h>
#include<CATUnicodeString.h>

/**
 * @level Protected
 * @usage U1
 */

#include <CATImplementationAdapter.h>

#include<CP0CLIP.h>

class ExportedByCP0CLIP CATTextTempo: public CATImplementationAdapter
{
  CATDeclareKindOf;

 public:
  CATTextTempo();
  virtual ~CATTextTempo();
 
  void SetText(CATUnicodeString& str);

  //from CATIText
  virtual CATUnicodeString Text() const;

  //From LifeCycleObject
  virtual void             remove();

  virtual void             remove(int context);

 private: 
  CATUnicodeString _str;

};

#endif

