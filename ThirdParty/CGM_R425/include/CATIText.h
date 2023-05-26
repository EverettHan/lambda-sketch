// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIText_H
#define CATIText_H
////////////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// 23/05/97
//
// Purpose: CATIText
//          Enable to get a Text Information from an object
//
////////////////////////////////////////////////////////////////////////////////////////
#include<CATBaseUnknown.h>
#include<CATUnicodeString.h>

/**
 * @level Protected 
 * @usage U3
 */

#include <CP0CLIP.h>

extern ExportedByCP0CLIP IID IID_CATIText ;


class ExportedByCP0CLIP CATIText: public CATBaseUnknown
{
  CATDeclareInterface;
 public:

  virtual CATUnicodeString Text() const=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIText, CATBaseUnknown ) ;


#endif

