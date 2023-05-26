#ifndef CATModifyLayer_h
#define CATModifyLayer_h

#include "CATModify.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify an layer modification of an element
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
// Class :      CATModifyLayer
//                 CATModify
//------------------------------------------------------------------------------


class ExportedByCATVisItf CATModifyLayer : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyLayer(CATBaseUnknown *object, const IID &interfaceName=CATBaseUnknown::ClassId(),
                   const unsigned int & iLayer = 0 );
    virtual ~CATModifyLayer();

    unsigned int GetLayer () const;

    // clone the notification
    virtual CATModelNotification* Clone ();


  protected:
    unsigned int _Layer;
};



#endif
