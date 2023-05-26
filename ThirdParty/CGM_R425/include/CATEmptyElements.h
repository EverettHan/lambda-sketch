#ifndef CATEmptyElements_H
#define CATEmptyElements_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SceneGraphManager.h"
#include "CATCsoNotification.h"
#include "list.h"
//
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   
//              define the addition of references of elements in a 
//              Current Set Of Object.
//              
//------------------------------------------------------------------------------
// Class :      CATEmptyElements
//                 CATCsoNotification
//------------------------------------------------------------------------------


/**
* Event that defined an remove of elements in a Set of Objects.
* Diectly use the variable member <b>_ListElt</b> to add/remove elements
* or to give the whole list of them.
*
* @see CATHSO, CATPSO
*/
class ExportedBySceneGraphManager CATEmptyElements : public CATCsoNotification
{
  CATDeclareClass;

public:
    
  /**
  * The default constructor.
  */
  CATEmptyElements();
  
  virtual ~CATEmptyElements();


  /**
  *  The list of all elements added in the SO.
  *
  */
  list<CATBaseUnknown> _ListElt;
};

#endif
