
#ifndef CATIAfrLabelItem_H
#define CATIAfrLabelItem_H

// COPYRIGHT DASSAULT SYSTEMES 2011/03/22

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

class CATPathElement;

extern ExportedByCATAfrItf  IID IID_CATIAfrLabelItem ;
//-----------------------------------------------------------------------------
/**
* Interface managing Label item.
*
*/
class ExportedByCATAfrItf CATIAfrLabelItem: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
    * Get associated path
    **/
    virtual HRESULT GetPath( CATPathElement** opPath ) = 0;

    /**
    * Get unicode values
    **/
    virtual HRESULT GetValues( CATListOfCATUnicodeString& oListLabel, 
                               CATListOfCATUnicodeString& oListAtt ) = 0;

    /**
    * Get values
    **/
    virtual HRESULT Get( float& oLx, float& oLy, float& oTx, float& oTy, 
                         float& oLbx, float& oLby, float& oLbw, float& oLbh, float& oLid) = 0;

    /**
    * Set values
    **/
    virtual HRESULT Set( const float& iLx, const float& iLy, const float& iTx, const float& iTy, 
                         const float& iLbx, const float& iLby, const float& iLbw, const float& iLbh, 
                         const float& iLid ) = 0;
};
#endif
