//===================================================================
// COPYRIGHT Dassault Systemes 2013/04/30
//===================================================================
// CATAfrAdapter3DExpAppsManagement.cpp
// Header definition of class CATAfrAdapter3DExpAppsManagement
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/04/30 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAfrAdapter3DExpAppsManagement_H
#define CATAfrAdapter3DExpAppsManagement_H

#include "CATIAfr3DExpAppsManagement.h"

#include "CATAfrItf.h"

//-----------------------------------------------------------------------

class ExportedByCATAfrItf CATAfrAdapter3DExpAppsManagement: public CATIAfr3DExpAppsManagement
{
public:
// Standard constructors and destructors
// -------------------------------------
CATAfrAdapter3DExpAppsManagement ();
virtual ~CATAfrAdapter3DExpAppsManagement ();


// CATIAfr3DExpAppsManagement methods
   public:
      virtual HRESULT GetMyAppsInfo(CATPathElement * i_plastSelectedObject,
                                    CATUnicodeString & o_physicalId,
                                    CATUnicodeString & o_tenant,
                                    CATUnicodeString & o_securityContext);


virtual HRESULT GetMyAppsWidgetInfo(CATPathElement * i_plastSelectedObject, 
                              CATUnicodeString & o_envId, 
                              CATUnicodeString & o_serviceId, 
                              CATUnicodeString & o_objectId,
                              CATUnicodeString & o_displayName,
                              CATUnicodeString & o_displayType,
                              CATUnicodeString & o_objectType) ;

private:
// Copy constructor and equal operator
// -----------------------------------
CATAfrAdapter3DExpAppsManagement (CATAfrAdapter3DExpAppsManagement &);
CATAfrAdapter3DExpAppsManagement& operator=(CATAfrAdapter3DExpAppsManagement&);

//-----------------------------------------------------------------------

};
#endif