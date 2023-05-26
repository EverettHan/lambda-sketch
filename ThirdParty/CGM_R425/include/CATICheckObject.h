/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
#ifndef CATICheckObject_h
#define CATICheckObject_h
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999  
//-----------------------------------------------------------------------------
// interface CATICheckObject:
// 
// 
// This is the CATICheckObject interface
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
#include "CATCheckReport.h"
#include "CATListOfCATUnicodeString.h"

extern ExportedByCATClnBase IID IID_CATICheckObject ;

/**
 * Base interface to be implemented by objects to check.
 * <BR><b>Role</b>:This interface provides the abstract methods
 * which can be used to collect information about all Rules.
 * It runs check operation on the implementor object.<br> 
 * An object submitted to Check must be seen as CodeExtension on CATICheckObject interface. 
 */

class ExportedByCATClnBase CATICheckObject : public CATBaseUnknown
{
  /** @nodoc */
  CATDeclareInterface;

  public:
/**
 * Retrieves all the possible check rules code on an object.
 * @return the list of rule ( CATCheckRule ) code <i>(XXX_ii)</i> which can be checked on an object. Rule code is a CATUnicodeString.
 *		
 */
  virtual CATListOfCATUnicodeString* GetCheckRules()=0;
/**
 * Checks local basic rules on the implementation<br>
 * Checks local basic rules on the implementation and put information
 * in the Report object passed in argument.
 * @param iCheckReport
 *		The CheckRepresentation report object. 
 * This object is used for communication with CheckRepresentation internal engine, and can not be null.
 * <BR>It is strongly advised to test in the beginning of the method this object using a strong test as: <DD><kbd>CATAssert(iCheckReport);</KBD></DD>
 * @return <UL>
 * <LI>S_OK: no error has been detected. Object is 'safe'.
 * <LI>E_FAIL: at least one error ( CATCheckRule ) has been detected. 
 * <DD>In that case, both CATCheckRule short and long messages should be defined, explaining which kind of corruption has been detected.
 * <DD>Then log the couple object-rule in the iCheckReport object using iCheckReport::<A HREF=<?php echo $ROOTUrl ?>_CheckRepresentation/Code_CATCheckReport.php#AddRunAndObject>AddRunAndObject</A> method</DD>
 * <LI>S_FALSE: rule can not be checked due to an internal problem (object allocation failed, ...)
 * </UL>
 * <!--LOCAL-->  <P><IMG SRC=<?php echo $ROOTUrl ?>_GIF/ZWork.gif BORDER=0 ALIGN=LEFT WITDH=30><DD>
 * In any case, it is more the list of object-rule which may decide if Check operation has detected errors than the HRESULT, which is more  
 * an `informative` result, than an operational one.</DD>
 * <P>Before running any check, test that error to check on the object is active in the current environment using the test:<DD><KBD>if ( !iCheckReport->IsActive(ErrorCode)) return S_OK ;</KBD>
 * </DD>
 * <BR>Then, call before the 'father' method on your object. For instance, if your object is a Container:
 * <PRE><BR>HR = CATCheckContainer::DetectAllRules(iCheckReport);
 * <BR>if ( ! SUCCEEDED(HR) ) ... ; // up to you to decide if you exit now ...
 * <BR>if ( iCheckReport->IsActive(ErrorCode)) {
 * <BR><DD>myCATCheckRuleClass * myCATCheckRuleObj = new  myCATCheckRuleClass; 
 * <BR><DD>if ( ! myCATCheckRuleObj ) return S_FALSE; // test can not be done
 * <BR><DD>HR = myCATCheckRuleObj->CheckObject(this);
 * <BR><DD>if ( ! SUCCEEDED(HR) ) iCheckReport->AddRunAndObject(myCATCheckRuleObj,this);
 * <BR><DD>else { delete myCATCheckRuleObj ; myCATCheckRuleObj = NULL ; // delete }
 * <BR>}
 * <BR>return HR ;
 * </PRE>
 */
  virtual HRESULT DetectAllRules(CATCheckReport * iCheckReport)=0;

/**
 * Checks specific rules on the implementation <FONT COLOR=RED><B>OBSOLETE</B></FONT>
 * <br>Checks specific rules on the implementation and put information
 * in the Report object passed in argument.
 * <P><FONT COLOR=RED><B>This method is obsolete with phase2 as no more called by CheckRepresentation engine</B></FONT>
 * @param iRuleCodeList
 *		List of specific Rules to check on object.<br>
 * @param iCheckReport
 *		The CheckRepresentation report object. 
 * This object is used for communication with CheckRepresentation internal engine, and can not be null.
 * <BR>It is strongly advised to test in the beginning of the method this object using a strong test as: <DD><kbd>CATAssert(iCheckReport);</KBD></DD>
 * @return <UL>
 * <LI>S_OK: no error has been detected. Object is 'safe'.
 * <LI>E_FAIL: at least one error ( CATCheckRule ) has been detected. 
 * <DD>In that case, both CATCheckRule short and long messages should be defined, explaining which kind of corruption has been detected.</DD>
 * <LI>S_FALSE:
 * </UL>
 * Before running any check, test that error to check on the object is active in the current environment using the test:<DD><KBD>if ( !iCheckReport->IsActive(ErrorCode)) return S_OK ;</KBD>
 * </DD>
 */
  virtual HRESULT DetectSpecificRules(CATListOfCATUnicodeString iRuleCodeList, CATCheckReport * iCheckReport)=0;

};

CATDeclareHandler(CATICheckObject,CATBaseUnknown);

#endif 
