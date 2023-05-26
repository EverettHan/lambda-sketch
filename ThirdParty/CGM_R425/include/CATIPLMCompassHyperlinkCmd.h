
#ifndef CATIPLMCompassHyperlinkCmd_H
#define CATIPLMCompassHyperlinkCmd_H

// COPYRIGHT Dassault Systemes 2007

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
class CATPathElement;
class CATString;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassHyperlinkCmd;
#else
extern "C" const IID IID_CATIPLMCompassHyperlinkCmd ;
#endif

/**
* Interface to launch command in view label.
*/
class ExportedByCATAfrItf CATIPLMCompassHyperlinkCmd: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Gets command status.
     *   @param ispNode
     *     Object
     *   @param iPropertyID
     *     Attribute identficator
     *   @param iHyperLink
     *     Hyperlink text
     */
    virtual int GetCommand( CATBaseUnknown_var ispNode, const CATString &iPropertyID, CATUnicodeString &oHyperLink ) = 0;

    /**
     * Launch command.
     *   @param ispItem
     *     Object
     *   @param iPropertyID
     *     Attribute identficator
     *   @param ipViewItem
     *     Label view item
     *   @param iHyperLink
     *     Hyperlink text
     */
    virtual HRESULT LaunchCommand( const CATString& iPropertyID, 
                                   const CATPathElement& iPath, const float ilx, const float ily,
                                   const CATUnicodeString &iHyperLink ) = 0;
};
#endif
