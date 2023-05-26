#ifndef CATICkeLaw_h
#define CATICkeLaw_h

// COPYRIGHT DASSAULT SYSTEMES 2000

  /** 
 * @CAA2Level L1
 * @CAA2Usage U4 CATCkeLawAdapter
 */

// module declaration
#include "KnowledgeItf.h"

// Inherited from
#include "CATBaseUnknown.h"

// Forwords for CkeAdapter
#include "CATICkeForwards.h"
#include "CATICkeFunction.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeLaw;
#else
extern "C" const IID IID_CATICkeLaw;
#endif

class CATCompositeLaw;
/**   
 * Interface dedicated to law management.
 * <b>Role</b>: <br>
 * <br>
 * Implementations of that interface should derive from CATCkeLawAdapter.
 *
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
* 
 * @see CATICkeFunction
 */
class ExportedByKnowledgeItf CATICkeLaw : public CATBaseUnknown
{

public :
 
/**  Returns the Knowledge function attributed to the Law.
	  *@return The function.
	  */
virtual CATICkeFunction_var GetFunction () const =0;

/** Returns the domain of validity of the law.
*@param oMin Minimum limit of the domain
*@param oMax Maximum limit of the domain
*/
virtual void GetDomain (double &oMin, double &oMax) const =0; 

/** Computes a CATCompositeLaw. 
*@return The CATCompositeLaw.
*/
virtual CATCompositeLaw* ComputesCompositeLaw () const =0;

/** Returns the list of the formal parameters. 
* @return The list of parameters of the law.
*/
virtual CATCkeListOfParm GetFormalParameters () const =0;

/**
*  Adds a formal parameter to the law.
* @param iParm The parameter to be added to the law.
*/
virtual	void AddFormalParameter (const CATICkeParm_var &iParm) const = 0;

/** 
* Removes a formal parameter to the law.
* @param iParm Removes the specified formal parameter.
*/
virtual	void RemoveFormalParameter (const CATICkeParm_var &iParm) const = 0;

private:

  // to define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATICkeLaw,CATBaseUnknown);

#endif


