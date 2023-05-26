/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
#ifndef CATICleanObject_h
#define CATICleanObject_h
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999  
//-----------------------------------------------------------------------------
// interface CATICleanObject:
// 
// 
// This is the CATICleanObject interface
//
//-----------------------------------------------------------------------------
// Usage Notes:
//
//
//-----------------------------------------------------------------------------
// Creation by ygn - Dec  99
//-----------------------------------------------------------------------------

/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATClnBase.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCheckReport.h"

extern ExportedByCATClnBase IID IID_CATICleanObject ;
/**
 * Base interface to be implemented by objects to clean.
 * <BR><b>Role</b>:This interface provides the abstract methods
 * which can be used to collect information about all Rules.
 * It runs clean operation on the implementor object.<br> 
 * An object submitted to Clean must be seen as CodeExtension on CATICleanObject interface. 
 */

class ExportedByCATClnBase CATICleanObject : public CATBaseUnknown
{
	/** @nodoc */
  CATDeclareInterface;

  public:

/**
 * Retrieves all the possible cleaner rules on an object.
 * @return the list of rule ( CATCheckRule ) code <i>(XXX_ii)</i> which can be cleaned on an object. Rule code is a CATUnicodeString.
 */
  virtual CATListOfCATUnicodeString* GetCleanRules()=0;

/**
 * Cleans local basic rules on the implementation<br>
 * Cleans local basic rules on the implementation and put information
 * in the Report object passed in argument.
 * @param iCheckReport

 *		The CheckRepresentation report object. 
 * This object is used for communication with CheckRepresentation internal engine, and can not be null.
 * <BR>It is strongly advised to test in the beginning of the method this object using a strong test as: <DD><kbd>CATAssert(iCheckReport);</KBD></DD>
 * @return <UL>
 * <LI>S_OK: object has been successfully cleaned.
 * <DD>In that case, the Clean messages should be defined, explaining which kind of corruption has been cleaned, using CATCheckReport::<A HREF=<?php echo $ROOTUrl ?>_CheckRepresentation/Code_CATCheckReport.php#AddCleanMessage>AddCleanMessage</A> method</DD>
 * <LI>E_FAIL: 
 * <LI>S_FALSE:
 * </UL>
 * You can retrieve a pointer on the CATCheckRule which has detected the error in the Check step using the CATCheckReport::<A HREF=<?php echo $ROOTUrl ?>_CheckRepresentation/Code_CATCheckReport.php#GetCurrentRule>GetCurrentRule</A> method.
 */
  virtual HRESULT Clean(CATCheckReport * iCheckReport)=0;

};

CATDeclareHandler(CATICleanObject,CATBaseUnknown);

#endif 
