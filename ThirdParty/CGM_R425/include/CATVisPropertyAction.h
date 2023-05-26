/* -*-c++-*- */
#ifndef CATVisPropertyAction_H
#define CATVisPropertyAction_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

//
// COPYRIGHT DASSAULT SYSTEMES 2000
//


/**
* @nodoc 
* Characterises the type of action for graphic properties.
* <b>Role</b>: This enum is used in 
* the @href CATIVisPropertiesAbstract#GetPropertyOwner .
* method.
* @param CATVPGet
* @param CATVPSet
* @param  CATVPReset 
* @see CATIVisProperties
*/

enum CATVisPropertyAction {
  CATVPGet,
  CATVPSet,
  CATVPReset
};


#endif
