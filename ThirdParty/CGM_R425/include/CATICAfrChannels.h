
#ifndef CATICAfrChannels_H
#define CATICAfrChannels_H

// COPYRIGHT DASSAULT SYSTEMES 2012/03/27

#include "CATAfrItf.h"
#include "CATICAfrComponent.h"
#include "CATUnicodeString.h"

extern ExportedByCATAfrItf  IID IID_CATICAfrChannels ;

//-----------------------------------------------------------------------------
/**
* Interface representing The Channel Component.
*/
class ExportedByCATAfrItf CATICAfrChannels: public CATICAfrComponent
{
  CATDeclareInterface;

  public:



    /**
    * Sets a flag that expands or collapses the contained widget.
    * @param i_expandedFlag
    * The flag that expands or collapses the contained widget.
    */

    virtual void SetExpandedFlag( const CATBoolean& i_expandedFlag) = 0;

    /**
    * Returns a flag that indicate if the contained widget is collapsed or expanded
    */
    virtual CATBoolean GetExpandedFlag() const = 0;

    /**
    * Sets a flag that allow to unexpand the expander under the same father..
    * @param i_exclusiveFlag
    */
    virtual void SetExclusiveFlag( const CATBoolean& i_exclusiveFlag) = 0;

    /**
    * Returns a flag that indicate if the contained widget is exclusive
    */
    virtual CATBoolean GetExclusiveFlag() const = 0;

};
CATDeclareHandler( CATICAfrChannels, CATICAfrComponent );
#endif
