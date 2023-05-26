//===================================================================
// COPYRIGHT Microsoft 2011/10/13
//===================================================================
// CATIAfrModelViewFactory.cpp
// Header definition of class CATIAfrModelViewFactory
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/10/13 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIAfrModelViewFactory_H
#define CATIAfrModelViewFactory_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
//---------------------------------------------------------------------- System
#include "CATString.h"
#include "CATUnicodeString.h"

class CATAfrModelView;

extern ExportedByCATAfrItf  IID IID_CATIAfrModelViewFactory ;

/**
* Interface representing a factory for @href CATAfrModelView object.
* Each implementation has to derive from a late type :
* <code>CATImplementClass(**className**, DataExtension,CATBaseUnknown,**LateType**)</code>
*
* <br><b>Role</b>: Create "your" CATAfrModelView instances 
*
* <br><b>Note :</b>
* Using a subclass of @href CATEAfrModelViewFactory is mandatory when 
* implementing the <tt>CATIAfrModelViewFactory</tt> interface.
* <p><b>BOA information</b>: this interface CANNOT be implemented
* using the BOA (Basic Object Adapter).
*
*/
class ExportedByCATAfrItf CATIAfrModelViewFactory: public CATBaseUnknown
{
CATDeclareInterface;

public:

    /**
    *
    * <br><b>Role</b>: Creates the model View instance.
    * @param ipDataBlock : the data block thats wraps all necessary properties of the model.
    * @return an instance of CATAfrModelView
    * 
    */
     virtual CATAfrModelView * CreateInstanceModelView(CATBaseUnknown * ipDataBlock, const CATString & iRepresentationType) = 0; 

    /**
    *
    * <br><b>Role</b>: Creates  the model View instance by declarative way.
    * @param ipDataBlock : the data block thats wraps all necessary properties of the model.
    * @param iLocationTemplate : the file where located the template.
    * @return an instance of CATAfrModelView
    * 
    */
     virtual CATAfrModelView * CreateInstanceDeclModelView(CATBaseUnknown * ipDataBlock, const CATString & iRepresentationType, const CATUnicodeString & iLocationTemplate) = 0; 
     



};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIAfrModelViewFactory, CATBaseUnknown );

#endif