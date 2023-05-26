// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATAfrLegacyFacetNotification.h
// Header definition of CATAfrLegacyFacetNotification
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: Code generated by the CAA wizard  OLC
//===================================================================
#ifndef CATAfrLegacyFacetNotification_H
#define CATAfrLegacyFacetNotification_H

#include "UIModelInterfaces.h"
#include "CATNotification.h"

//-----------------------------------------------------------------------

/**
* Class representing the notification for an event 
*
* <br><b>Role</b>: 
* 
*
* @example
*  SendNotification (GetFather(),new CATAfrLegacyFacetNotification());
*
*/
class ExportedByUIModelInterfaces CATAfrLegacyFacetNotification: public CATNotification
{
  CATDeclareClass;

  public:

    // constructors and destructors
    // -------------------------------------
    // deprecated use the one with 2 args
    CATAfrLegacyFacetNotification (int iUpdateType);

    // second arg corresponds to the CATFrmWindow
    CATAfrLegacyFacetNotification (int iUpdateType, CATBaseUnknown *ipBUAsData);
    virtual ~CATAfrLegacyFacetNotification ();

     int              GetRefreshType();

     /**
      * @return CATBaseUnknown#Release
      */
     CATBaseUnknown * GetBUAsData();

  private:

    // Copy constructor and equal operator
    // -----------------------------------
    CATAfrLegacyFacetNotification (CATAfrLegacyFacetNotification &);
    CATAfrLegacyFacetNotification& operator=(CATAfrLegacyFacetNotification&);

    int             _UpdateType;
    CATBaseUnknown *_pBUAsData;
};
//-----------------------------------------------------------------------
#endif