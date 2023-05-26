#ifndef CATAddElement_h
#define CATAddElement_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 1999

/** @nodoc */
#include "SceneGraphManager.h"
#include "CATCsoNotification.h"
//
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   
//              define the addition of a reference of an element in a 
//              Current Set Of Object.
//              
//------------------------------------------------------------------------------
// Class :      CATAddElement
//                 CATCsoNotification
//------------------------------------------------------------------------------


/**
* Event that defined an add of elements in a Set of Objects.
*
*/
class ExportedBySceneGraphManager CATAddElement : public CATCsoNotification
{
  CATDeclareClass;

  public:

   /**
    * The default constructor take the element that was add in the set.
    *
    * @param iElement
    *        A pointer on the added element.
    */
    CATAddElement( CATBaseUnknown *);

    virtual ~CATAddElement();
};

#endif
