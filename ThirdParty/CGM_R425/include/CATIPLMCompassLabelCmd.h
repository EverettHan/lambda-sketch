
#ifndef CATIPLMCompassLabelCmd_H
#define CATIPLMCompassLabelCmd_H

// COPYRIGHT Dassault Systemes 2007

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
class CATPathElement;
class CATString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassLabelCmd;
#else
extern "C" const IID IID_CATIPLMCompassLabelCmd ;
#endif

/**
* Interface to launch command in view label.
*/
class ExportedByCATAfrItf CATIPLMCompassLabelCmd: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Gets command status.
     *   @param ispNode
     *     Object
     *   @param iPropertyID
     *     Attribute identficator
     */
    virtual int GetCommand( CATBaseUnknown_var ispNode, const CATString &iPropertyID ) = 0;

    /**
     * Launch command.
     *   @param ispItem
     *     Object
     *   @param iPropertyID
     *     Attribute identficator
     *   @param ipViewItem
     *     Label view item
     */
    virtual HRESULT LaunchCommand( const CATString& iPropertyID, 
                                   const CATPathElement& iPath, const float ilx, const float ily ) = 0;
};
#endif
