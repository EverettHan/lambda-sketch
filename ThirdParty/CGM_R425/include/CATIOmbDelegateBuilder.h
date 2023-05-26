// COPYRIGHT Dassault Systemes 2006
/**
* @level Protected 
* @usage U3
*/ 
//===================================================================
//
// CATIOmbDelegateBuilder.h
// Define the CATIOmbDelegateBuilder interface
//
//===================================================================
//
// Interface enabling to create delegate objects
//
//===================================================================
#ifndef CATIOmbDelegateBuilder_H
#define CATIOmbDelegateBuilder_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATIOmbUpdateContract_var;
class CATIOmbDelegateObject_var;
class CATLISTP( CATIOmbUpdateContract );
class CATLISTP( CATIOmbDelegateObject );

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIOmbDelegateBuilder;
#else
extern "C" const IID IID_CATIOmbDelegateBuilder ;
#endif

//------------------------------------------------------------------

/**
 *  Interface enabling to create delegate objects. These objects are used 
 *   by product structure linkable objects to reference either geometrical features, or
 *   selection objects.
 */
class ExportedByAC0XXLNK CATIOmbDelegateBuilder: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Creation of a delegate object 
  * <b>Role</b>:<br>
  * Creation of a delegate object CATIOmbDelegateObject.
  * @param LinkableObject
  *   The pointed linkableObject (a CATIMmiGeometryAccess pointing towards a mechanical feature or a selection object).
  * @return
  *   E_FAIL if no delegate has been created
  */
  virtual HRESULT CreateDelegate(CATIOmbUpdateContract_var & iContract, CATIOmbDelegateObject_var & oDelegate)=0;

  /**
   * Access to the delegate objets
   * <b>Role</b>:<br>
   * Access to the delegate objets CATIOmbDelegateObject
   * @param iListOfContact
   *	The list of contracts
   * @param oListDelegates
   *	The list of delegates
   * @return
   *	E_FAIL if error
   */
  virtual HRESULT GetDelegates( const CATLISTP( CATIOmbUpdateContract ) &iListOfContact, CATLISTP( CATIOmbDelegateObject ) &oListDelegates ) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(CATIOmbDelegateBuilder,CATBaseUnknown);

#endif
