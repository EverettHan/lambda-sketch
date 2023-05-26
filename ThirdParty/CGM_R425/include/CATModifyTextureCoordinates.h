#ifndef CATModifyTextureCoordinates_h
#define CATModifyTextureCoordinates_h

#include "CATModify.h"

//
// CATIA Version 6 Release 213x Framework Visualization
// Copyright Dassault Systemes 2012
//------------------------------------------------------------------------------
// Abstract :   used to notify texture coordinates of an element
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
// Class :      CATModifyTextureCoordinates
//                 CATModify
//------------------------------------------------------------------------------


class ExportedByCATVisItf CATModifyTextureCoordinates : public CATModify
{
  CATDeclareClass;

  public:
    CATModifyTextureCoordinates(CATBaseUnknown *object, CATBaseUnknown *feature, const IID &interfaceName=CATBaseUnknown::ClassId());
    virtual ~CATModifyTextureCoordinates();

    // clone the notification
    virtual CATModelNotification* Clone ();

    // Returns a pointer to the enclosed object. 
    CATBaseUnknown * GetFeature() const;

 private:
	CATBaseUnknown *_pFeature;

};



#endif
