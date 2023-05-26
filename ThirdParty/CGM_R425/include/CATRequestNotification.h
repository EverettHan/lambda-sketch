#ifndef _CATRequestNotification
#define _CATRequestNotification

#include "CATVisController.h"
#include "CATVueNotification.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//
// Abstract :   basic class for making request to a vue component
// ---------    contains a pathElement and an interface iid
//
//
//------------------------------------------------------------------------------
//
// Usage :      is used by copilot to ask decode of visible element of
// -------      a model path ( sketch element in the model ) 
//              
//              
//------------------------------------------------------------------------------
//
// Main methods :
// --------------
//                      
//
//------------------------------------------------------------------------------
//
// Class :      CATRequestNotification
// -------         CATVueNotification
//
//------------------------------------------------------------------------------

class CATPathElement;

class ExportedByCATVisController CATRequestNotification : public CATVueNotification
{
  CATDeclareClass;

  public:
    CATRequestNotification(CATNotification *notif, CATPathElement *path);
    virtual ~CATRequestNotification();
    
    CATPathElement *GetPathElement() const;

 protected:
    CATPathElement *_pathElement;

};

#endif
