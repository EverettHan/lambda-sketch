#ifndef CATRemoveElement_h
#define CATRemoveElement_h
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
//              define the removal of a reference of an element in a 
//              Current Set Of Object.
//              
//------------------------------------------------------------------------------
// Class :      CATRemoveElement
//                 CATCsoNotification
//------------------------------------------------------------------------------



/**
* Event that defined an remove of elements from a Set of Objects.
*
*/
class ExportedBySceneGraphManager CATRemoveElement : public CATCsoNotification
{
  CATDeclareClass;

  public:

   /**
    * The default constructor take the element that was remove from the set.
    *
    * @param iElement
    *        A pointer on the removed element.
    */
    CATRemoveElement( CATBaseUnknown *);


    virtual ~CATRemoveElement();
    
};

#endif
