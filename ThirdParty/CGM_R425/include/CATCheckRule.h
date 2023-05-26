/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATCheckRule_h
#define CATCheckRule_h

/** 
 *  @level Protected 
 *  @usage U1
 */

#include "ExportedByCATClnBase.h"

#include "CATUnicodeString.h"
#include "CATBooleanDef.h"
#include "CATBaseUnknown.h"


/**
 * CATCheckRule repesents the Abstract Rule Class.
 * <br><b>Role:</b> All rules must derive from an abstract class (CATCheckRule).
 */
class ExportedByCATClnBase CATCheckRule 
{
  public:

/**
 * Constructs an empty Rule Object.
 */
     CATCheckRule();
/**
 * Destructs an Rule Object and releases the resources.
 */
	 virtual ~CATCheckRule();

/**
 * Sets ErrorMessage for Rule.
 * @param iErrorMessage
 *			The error message to set.
 */
     void SetErrorMessage(CATUnicodeString iErrorMessage);

/**
 * Returns ErrorMessage for Rule.
 * @return
 *			The error message.
 */
	 CATUnicodeString GetErrorMessage();

/**
 * Returns Short ErrorMessage for Rule.
 * @return
 *			The short error message.
 */
	 CATUnicodeString GetShortMessage();

/**
 * Verifies the Fixability of Rule Object.
 * @return 
 *		Flag indicating the status.
 */
     boolean IsFixable();
/**
 * Returns the Severity of Rule Object.
 * @return 
 *		The Severity of Rule Object.
 */
     short GetSeverity();
/**
 * Returns the CodeLevel of Rule Object.
 * @return 
 *		The CodeLevel of Rule Object.
 */
     int GetCodeLevel();
/**
 * Returns the Code of Rule Object.
 * @return 
 *		The Code of Rule Object.
 */
     CATUnicodeString GetRuleCode();

/**
 * Launchs Check on object eventually with a linked object.
 * @param iPtr
 *			Pointer to Object.
 * @param iLink
 *			Pointer to Linked object.
 */
     virtual HRESULT CheckObject(CATBaseUnknown* iPtr, CATBaseUnknown* iLink=NULL) {return S_OK;} 
		 
/**
 * Returns the Domain of Rule Object.
 * @return 
 *		The Domain of Rule Object.
 * <br><b>Legal values:</b><br>
 * <tt>1</tt> Spec rule (default)<br>
 * <tt>2</tt> Result rule<br>
 * <tt>4</tt> Geometry rule<br>
 */
	 virtual int GetRuleDomain() {return 1;}

  protected:
/**
 * Represents a template : TYP_X.
 * <br><b>Role:</b>Every rule has this code where :<br>
 *		TYP : Three letters to sum-up the type of corruption.<br>
 *		X   : A number (0,n).<br>
 */
    CATUnicodeString _RuleCode;
/**
 * A long message which details the corruption.
 */
    CATUnicodeString _ErrorMessage;
/**
 * (Not used for the moment) Represents the code level on which the rule has been delivered.
 */
	int _CodeLevel;
/**
 * Flag indicating rule is fixable or not.
 */
    boolean _Fixable;
/**
 * Severity level rule belongs to.
 * <br><b>Legal values:</b><br>
 * <tt>0</tt> Not detected in Cutomer Environment.<br>
 * <tt>1</tt> Prevent application to work.<br>
 * <tt>2</tt> Prevent application to work.<br>
 * <tt>3</tt> The customer can work with the data without any problem.<br>
 */
    short _Severity;
/**
 * A short message which defines quickly the rule.
 */
    CATUnicodeString _ShortMessage;
};
   

#endif
