
/**
 * @level Protected
 * @usage U4 
 */

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/07/05
//===================================================================
// Header definition of class CATIOmeAbendPanel
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/07/05 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIOmeAbendPanel_H
#define CATIOmeAbendPanel_H

#include "CATOme.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"


extern ExportedByCATOme  IID IID_CATIOmeAbendPanel ;

class ExportedByCATOme CATIOmeAbendPanel : public CATBaseUnknown
{
CATDeclareInterface;
public:
   virtual void DisplayPanel(const CATUnicodeString& iTitle,const CATUnicodeString& iMessage)=0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIOmeAbendPanel, CATBaseUnknown );


#endif