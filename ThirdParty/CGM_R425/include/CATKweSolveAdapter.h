#ifndef CATKweSolveAdapter_H
#define CATKweSolveAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 2002


// Export Module 
#include "CATLifSpecs.h"

// inherit from
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATICkeSolve.h"
#include "CATKWEErrorSeverity.h"


/**   
 * Adapter to CATICkeSolve Interface.
 * <b>Role</b>: This class must be derived to implement CATICkeSolve.<br>
 * CATICkeSolve is the interface used by Knowledgeware to "update" an object.<br>
 * @see CATICkeSolve
 */
class ExportedByCATLifSpecs CATKweSolveAdapter : public CATICkeSolve
{
public:

   /** 
    * Constructs the object.
    */ 
    CATKweSolveAdapter();

   /** 
    * Deletes the object.
    */ 
    virtual ~CATKweSolveAdapter();

    /**
     * Solves the object. <br>
	 * Default implementation calls SolveItInternal. Please do not override this method.
	 *
   	 * @return
	 *    E_FAIL if an error occured <br>	
	 *    E_ACCESSDENIED if the solve has failed due to licensing considerations<br>
	 *    S_OK if the solve is completed
     */
	 HRESULT SolveIt () ;

 	/**
	*  Description: Raises an error. Use this method inside the SolveIt method
	*  when you want to bring to the user more explanation about why the new operation has failed.<br>
	*  Note that you don't need to raise message (& use this method) in the standard error cases.
	*  Simply return the right HRESULT (E_INVALID_ARG, E_ACCESSDENIED) and a standard error message is raised (SolvenReadOnly, SolveFailer).<br>  
    *  @param iMessage: the NLS message that will be brought to the end-user.
    *  @param iSeverity: severity of the error.
	*/
	HRESULT SendError  (const CATUnicodeString				&iMessage, 
						const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error) const ;

	virtual CATBoolean IsSolved();

private:
 
    /**
     * Solves the object. <br>
	 * If an error occured, you must raise an evaluation error.<br>
	 * You must implement this interface of course.<br>
	 *
   	 * @return
	 *    E_FAIL if an error occured <br>
	 *    S_OK if the solve is completed
     */
	virtual HRESULT SolveItInternal () =0;

  /**
   */
   CATKweSolveAdapter(const CATKweSolveAdapter&);
};


#endif
