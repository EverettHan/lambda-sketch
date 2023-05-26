#ifndef  CATICkeCheck_H
#define  CATICkeCheck_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */


/*  CAA2Reviewed by FRH */

// module declaration
#include "KnowledgeItf.h"

//Inherited from
#include "CATBaseUnknown.h"

// forwards
class CATICkeParm_var;
#include "CATICkeRelationForwards.h"

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeCheck;
#else
extern "C" const IID IID_CATICkeCheck;
#endif

 

/**   
 * Interface representing the result parameter of a Knowledge check.
 * <b>Role</b>: This interface is implemented on Knowledge Advisor checks.
 * This interface is mono implemented on Knowledge Advisor checks.
 */
class ExportedByKnowledgeItf CATICkeCheck : public CATBaseUnknown
{

  CATDeclareInterface;

public:

/**
 * Returns the check result parameter.
 * @return a CATICkeParm of boolean type.
 *     <br><b>Legal values</b>:
 *     <tt>True</tt>  if the check is verified. 
 *     <tt>False</tt> if the check is KO.
 */
	virtual CATICkeParm_var  GetResultParameter() const = 0;

/**
 * Returns the check warning message.
 * @return a CATUnicodeString: the warning message associated to the check when it fails.
 * This warning message is displayed if the check has a severity = 2.
 */
	virtual CATUnicodeString  GetWarningMessage () const = 0;
	
/**
 * Returns the check warning message parameter.
 * @return a CATICkeParm: the string parameter which value is the warning message.
 */
	virtual CATICkeParm_var  GetWarningMessageParameter () const = 0;

/**
 * Sets the warning message.
 * @param iMessage the string valuating the warning message of the check.
 * This warning message is displayed if the check has a severity = 2.
 * @return classic HRESULT
 */
	virtual HRESULT  SetWarningMessage (const CATUnicodeString &iMessage)  = 0;
	
/**
 * Sets the warning message with NLS name deduced from catalog.<br>
 * Note that check should be read only !.
 * @param iCatalogName the catalog where to find the NLS message.
 * @param iMsgKey the key in the catalog.
 * @return classic HRESULT
 */
	virtual HRESULT  SetWarningMessage (const char *iCatalogName,const char *iMsgKey)  = 0;

/**
 * Returns the severity parameter.
 * @return
 *		a CATICkeParm valuated with an integer value.
 *     <br><b>Legal values</b>:
 *     <tt>0</tt> if the check is silent: no message is displayed. 
 *     <tt>1</tt> if the check displays an information message.
 *     <tt>2</tt> if the check displays a warning message.
 */
	virtual CATICkeParm_var  GetSeverityParameter() const = 0;

/**
 * Sets the severity.
 * @param iSeverity
 *		The severity is defined with an integer value:
 *     <br><b>Legal values</b>:
 *     <tt>0</tt> if the check is silent: no message are displayed. 
 *     <tt>1</tt> if the check displays an information message.
 *     <tt>2</tt> if the check displays a warning message.
 * @return classic HRESULT
 */
	virtual HRESULT  SetSeverity (const int &iSeverity)  = 0;
};

CATDeclareHandler(CATICkeCheck,CATBaseUnknown);


#endif
