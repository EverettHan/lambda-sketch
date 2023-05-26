#ifndef CATParmValuatorAdapter_H
#define CATParmValuatorAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
* @CAA2Level L1
* @CAA2Usage U2 
*/


/*  CAA2Reviewed by FRH */

// Export Module 
#include "KnowledgeItf.h"

// inherit from
#include "CATBaseUnknown.h"

//Forwards
#include "CATICkeRelationForwards.h"


#include "CATIParmValuator.h"


/**   
* CAA2 Adapter to CATIParmValuator Interface.
* <b>Role</b>: This class must be derived to implement features extension to CATIParmValuator.<br>
* CATIParmValuator is the interface used by Knowledgeware to understand which object valuates a parameter.<br>
* It is used in CATICkeParm::SetRelation (..) and CATICkeParm::Relation () methods.<br>
* @see CATIParmValuator, CATICkeParm
*/
class ExportedByKnowledgeItf CATParmValuatorAdapter : public CATIParmValuator
{
public:
	
	/** 
	* Constructs the extension.
    */ 
    CATParmValuatorAdapter();
	
	/** 
    * Deletes the extension.
    */ 
    virtual ~CATParmValuatorAdapter();
	
	
	//-------------------------------------------
	// Interface CATIParmValuator implementation
	//-------------------------------------------
	
	
	/**
	* Returns the NLS view of this object. 
	* This method is used to show the user who is Valuator a parameter.<br>
	* It is used in F(x).<br>
	* whatever it is (it can be the body of formula......for example).<br>
	*/
	virtual CATUnicodeString  Show    () const ; 
	
	/**
	* Indicates if a link with a parameter is removable.
	* Default implementation returns E_FAIL.
	* @param parm the parameter with the link.
	* @return S_OK if link with parameter is removable E_FAIL else
	*/
	virtual HRESULT AllowLinkRemoval(const CATICkeParm_var &parm);
	
	/**
	* Indicates if the removal of a link has succeeded.
	* Default implementation returns E_FAIL.
	* @param parm the parameter with the link.
	* @return S_OK if link removal succeeded, E_FAIL else
	*/
	virtual HRESULT RemoveLink(const CATICkeParm_var &parm);
	
	
	
private:
	
	/**
	*/
	CATParmValuatorAdapter(const CATParmValuatorAdapter&);
};


#endif
