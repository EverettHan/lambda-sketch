/* -*-c++-*- */
#ifndef CATIIcon_H
#define CATIIcon_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
  * @CAA2Level L1
  * @CAA2Usage U5
  */ 


#include "CATBaseUnknown.h"
#include "UIModelInterfaces.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIcon;
#else
extern "C" const IID IID_CATIIcon;
#endif

/**
  * Associate an icon.
  * <b>Role</b>: Implement this interface to associate an icon to an element.
  */

class ExportedByUIModelInterfaces CATIIcon: public CATBaseUnknown
{
   CATDeclareInterface;
public:

  /**
    * Read the icon name.
    *   @param oName 
    *      The icon name of the element.
    *   @return 
    *      S_OK if OK, E_FAIL if fail
    */	
   virtual HRESULT GetIconName (CATUnicodeString& oName)=0;

  /**
    * Set the icon name. 
    *   @param iName 
    *      The icon name of the element.
    *   @return 
    *      S_OK if OK, E_FAIL if failed.
    */	
   virtual HRESULT SetIconName (const CATUnicodeString& iName)=0;
};

CATDeclareHandler (CATIIcon, CATBaseUnknown);

#endif

