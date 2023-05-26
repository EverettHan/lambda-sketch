//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2005                                          *
//*===========================================================================*
//*                                                                           *
//*  Specific Services for the Save Persistency                               *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Sep 2008  Creation                                               ycm     *
//*===========================================================================*

#ifndef CATOMBCATBackSpecificServices_H
#define CATOMBCATBackSpecificServices_H

/**
* @level Private
* @usage U1
*/

#pragma message( "!!" )
#pragma message( "!! Stop including " __FILE__  ", this include is empty." )
#pragma message( "!!" )

#include "CATDocument.h"

class CATOMBCATBackSpecificServices
{
public:
  static inline void Set(CATLISTP(CATDocument)* iDocs) {}
};


#endif
