#ifndef CATICkeNaming_h
#define CATICkeNaming_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// module 
#include "CATLifSpecs.h"

// Its an interface1
#include "CATBaseUnknown.h"

// Forwards 
#include "CATICkeForwards.h"
class CATICkeParm_var;

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeNaming;
#else
extern "C" const IID IID_CATICkeNaming;
#endif

/**   
 *  Interface dedicated to Knowledge relations naming. 
 *  <b>Role</b>: Parameters can be valuated by such an object.<br>
 *  It is implemented on relations.<br>
 *  The name is used to be shown to a user (it can be changed by user)<br>
 *  The comment gives an explanation of it (it can be changed by user)<br>
 *  The type of the object can not be changed<br>
 */
class ExportedByCATLifSpecs CATICkeNaming : public CATBaseUnknown
{

public :

  /**
   * Rights defined on a naming object.
   * Used to define how this object can be used through Knowledgeware.<br>
   * <br><b>Legal values</b>:
   * <tt>NotSeen</tt> this relation is not seen by the user.
   * <tt>ReadOnly</tt> Default value : the relation will be seen but wont be modified
   * <tt>ReadWrite</tt>   the relation object can be modified, deactivated
   * <tt>User</tt> the relation can be modified or destroyed by end user
   * <tt>LockType</tt> the Type of Feature accepted in the list can not be modified or destroyed by end user
   */
	// LockType utilise par les Listes.
  enum UserAccessMode  
  {
    NotSeen	    = 0,   
    ReadOnly    = 1,  
    ReadWrite	= 2,   
    User        = 3
  };

    
/**
 * @nodoc Use ObjectModelerBase CATIAlias::GetAlias method.  
 * Returns the NLS name of this object.
 */
virtual CATUnicodeString  Name    () const =0;

/**
 * @nodoc Use ObjectModelerBase CATIAlias::SetAlias method.  
 * Renames the relation.
 * @param iNewName:
 *    new name for the object
 */
virtual void            Rename    (const CATUnicodeString &iNewName) =0;

/**
 * @nodoc Use KnowledgeInterfaces CATIParmValuator::Show method.  
 * Returns the NLS view of an object.
 * This method is used to show the user who is valuating a parameter.<br>
 * whatever it is (it can be the body of formula......for example)<br>
 */
virtual CATUnicodeString  Show    () const =0; 

/**
 * Returns the type of this object. 
 */
virtual CATICkeType_var Type    () const =0;


/**
 * Returns the rights on this naming object.  
 * <br><b>Legal values</b>:
 * <tt>NotSeen</tt> this relation is not seen by the user.
 * <tt>ReadOnly</tt> Default value : the relation will be seen but wont be modified
 * <tt>ReadWrite</tt>   the relation object can be modified, deactivated
 * <tt>User</tt> the relation can be modified or destroyed by end user
 */
virtual CATICkeNaming::UserAccessMode UserAccess () const = 0;

/**
 * Sets the rights on this naming object.
 * @param iRights: the rights
 * <br><b>Legal values</b>:
 * <tt>NotSeen</tt> this relation is not seen by the user.
 * <tt>ReadOnly</tt> Default value : the relation will be seen but wont be modified
 * <tt>ReadWrite</tt>   the relation object can be modified, deactivated
 * <tt>User</tt> the relation can be modified or destroyed by end user
 */
virtual void    SetUserAccess (const CATICkeNaming::UserAccessMode iRights) = 0; 

//----------------------------------------------
  // rights
  //----------------------------------------------
/**
 * Indicates if this object is const or not.
 * Default value is always not Const 
 * @return <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is constant
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsConst () const = 0;

/**
 * Sets Const facet.
 * Default value is always not Const 
 * @param iConstant
 * <b>Legal values</b>:
 * <tt>CATCke::True</tt> if it is constant
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual void    SetConst (const CATCke::Boolean iConstant) = 0; 

/**
 * Is this object hidden or shown.
 * Default value is always Shown<br> 
 * @return
 * <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is hidden
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsHidden () const = 0;

/**
 * Sets HideShow facet.
 * Default value is always Shown
 * @param iHidden <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is hidden
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual void    SetHidden (const CATCke::Boolean iHidden) = 0; 

private:

  // to define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATICkeNaming,CATBaseUnknown);

#endif



