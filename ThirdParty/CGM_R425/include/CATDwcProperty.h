/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//============================================================================
// COPYRIGHT DASSAULT SYSTEMES   2002
//============================================================================
// Usage notes : 
//       CATDwcProperty definition for CATICATBack implementation
//       Provide implementation to interface CATICreateInstance
//============================================================================
//  September 2004 - Creation : YWE
//============================================================================
/** @level Protected 
* @usage U1
*/
#ifndef CATDwcProperty_H_
#define CATDwcProperty_H_

#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "ExportedByCATDWCInfra.h"
class CATUnicodeString;
class CATIProperty;
class CATIDocId;

//=============================================================================
// class CATDwcProperty : Write properties in doc in CATBack session
//=============================================================================

class  ExportedByCATDWCInfra CATDwcProperty: public CATBaseUnknown {
  CATDeclareClass;
public:
 
	         CATDwcProperty();          // Constructor
virtual ~CATDwcProperty();          // Destructor


    /**
     * Checks if a document is the result of a V6->V5 conversion
     *  @param iDocId [in]      *    The document to check.
     *  @param oIsCATBackedfromV6 [out] status on the document:<UL>

     *    <LI>TRUE: document is the result of a V6->V5 conversion
     *    <LI>FALSE: document isn't a V6->V5 conversion
     * </UL>
     *  @param oV6ConvertMode [out] the conversion mode :<UL>
     * <LI>Null when not from V6 object (oIsCATBackedfromV6=FALSE)
     * <LI>V6V5 for a AsResult conversion
     * <LI>V6V5AsSpec for a AsSpec conversion (for CATPart and CATShape only)
     * </UL>
*  @return
     *  <UL>
     *    <LI>S_OK, information successfully retrieved
     *    <LI>E_FAIL, if an error happened. <DD>Mainly invalid or Null input iDocId</LI>
     *  </UL>
     */
  
static HRESULT IsCATBackedFromV6(CATIDocId * iDocId , CATBoolean & oIsCATBackedFromV6, CATUnicodeString &oV6ConvertMode) ;


    /**
     * Save Properties about CATBack information in a document.
     * @param iProperty [in]
     *  The given property where CATBack information will be added.
     * @return
     *  <UL>
     *    <LI>S_OK, if everything goes well.</LI>
     *    <LI>S_FALSE, if CATBack environment is not defined.</LI>
     *    <LI>E_FAIL, if an error happened.</LI>
     *  </UL>
     */

HRESULT CATBackSaveProperties(CATIProperty*&  iProperty) ;


    /**
     * Checks if CATBack informations must be marshalled
     *  @param iCurrenVersion [in]
     *    The version compared with current CATBack information.
     *  @param oStatus [out]
     *    This method compares iCurrentVersion with current CATBack information.
     *    oStatus is the result of this comparison. If oStatus > 0, current CATBack must be
     *    marshalled.
     *  @return
     *  <UL>
     *    <LI>S_OK, the information about the CATBackVersion and CATBackPath must be marshalled.</LI>
     *    <LI>S_FALSE, the information about the CATBackVersion and CATBackPath must not be marshalled.</LI>
     *    <LI>E_FAIL, if an error happened.</LI>
     *  </UL>
     */

HRESULT CATBackMarshalling(CATUnicodeString& iCurrentVersion) ;

    /**
     * Checks if a document is the result of a V6->V5 conversion
     *  @param iDocId [in]
     *    The document to check.
     *  @param oIsCATBackedfromV6 [out] status on the document:<UL>
     *    <LI>TRUE: document is the result of a V6->V5 conversion
     *    <LI>FALSE: document isn't a V6->V5 conversion
     * </UL>
     *  @return
     *  <UL>
     *    <LI>S_OK, information successfully retrieved
     *    <LI>E_FAIL, if an error happened. <DD>Mainly invalid or Null input iDocId</LI>
     *  </UL>
     */

HRESULT IsCATBackedFromV6(CATIDocId * iDocId , CATBoolean & oIsCATBackedFromV6) ;
  


/**
  * Checks if a DownwardCompatibility transaction is opened
  *  @param oIsCATBack [out] status on the DownwardCompatibility transaction:<UL>
  *    <LI>TRUE: a DownwardCompatibility transaction is currently opened
  *    <LI>FALSE: no DownwardCompatibility transaction 
  * </UL>
  *  @return
  *  <UL>
  *    <LI>S_OK, 
  *  </UL>
  */
 HRESULT IsCATBack(CATBoolean & oIsCATBack) ;
/**
 * Returns last Targeted Version set by DownwardCompatibility application.
 * <BR>When no DownwardCompatibility process is running, the TargetedVersion is set to the CurrentVersion.
 * @return
 *		Last Targeted Version.
 */
CATUnicodeString GetTargetedVersion (void) ;    

/**
* Sets the CATDWC transaction status.
* @param iCatBack
*			 CATDWC transaction status value.
* <br><b>Legal values:</b><UL>
* <LI>0: Current process is not in a CATDWC transaction </LI>
* <LI>1: Current process is a V6-V5 CATDWC transaction </LI>
* <LI>2: Current process is a V6-V6 CATDWC transaction </LI>
* </UL>
*/
void SetCatback(int iCatBack);


/**
* Sets latest Targeted Version.
* <BR>Set teh targeted version in case of a DownwardCompatibility application.
* @param iLatestTargetedVersion
*			Internal name of the targeted Version (CATIAV5Rxx).
* @return
*		Success status.
* <br><b>Legal values:</b><br>
* <tt>0</tt>	 Success.<br>
* <tt>1997</tt> iLatestTargetedVersion is not supported.<br>
*/
int PutTargetedVersion(CATUnicodeString iLatestTargetedVersion);
  
protected:
private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATDwcProperty (CATDwcProperty &);
  CATDwcProperty & operator=(CATDwcProperty&);
} ;

#endif 
