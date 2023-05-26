#ifndef CATModifyLayerFilter_h
#define CATModifyLayerFilter_h

#include "CATModify.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify a global layer modification
//              
//              
//------------------------------------------------------------------------------
// Usage :      
//              
//------------------------------------------------------------------------------
// Main methods :
//              IsAKindOf(const char *) : 
//
//------------------------------------------------------------------------------
// Class :      CATModifyLayerFilter
//                 CATModify
//------------------------------------------------------------------------------


class ExportedByCATVisItf CATModifyLayerFilter : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyLayerFilter(CATBaseUnknown *object, const IID &interfaceName=CATBaseUnknown::ClassId() );
    virtual ~CATModifyLayerFilter();

    // clone the notification
    virtual CATModelNotification* Clone ();

};

#endif
