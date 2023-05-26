/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */

#ifndef CATBackPropertyAcess_h
#define CATBackPropertyAcess_h
// COPYRIGHT DASSAULT SYSTEMES 2001
//===========================================================================
// Usage Notes:   
//===========================================================================
// September 2001   Creation                  YWE 
// Moteur de CATBACK
//===========================================================================

/** 
 *  @level Protected 
 *  @usage U1
 */
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATDocument.h"
#include "ExportedByCATDWCInfra.h"

#ifndef CATBACKV6V5
#define CATBACKV6V5 "V6V5"
#endif

#ifndef CATBACKASSPECV6V5
#define CATBACKASSPECV6V5 "V6V5AsSpec"
#endif

class CATIDocId ;


/**
 * Serves the Minimal Version to Read for the document specified by 'DocId'
 * Supports CATIA V5 Documents only.
 * @param iDocId
 *   Document ID of CATIA Document.
 * @return The minimal CATIAV5 Version to Read (CATUnicodeString) which format is CATIAV5Rxx (no SP information)
 */
ExportedByCATDWCInfra CATUnicodeString GetMinimalVersionToRead ( CATIDocId * iDocId ) ;




/**
 * Retrieves CATDWC properties attached to an object specified by 'DocId'
 * <BR>Retrieves the BackVersion and  BackPath for an object specified by 'DocId'
 * Supports CATIA V5 Documents only.
 * @param iDocId
 *   Document ID of CATIA Document
 * @param oBackVersion
 *   Version of the CATIA Document
 * <DD>The format of a Version is CATIAV<I>x</I>R<I>y</I>. 
 * <DD>Because of the native SP compatibility, No SP information is needed.
 * @param oBackPath
 *   Reference of the V6 PLMObject which is linked to the V5 document
 * <DD>In case of a V5->V5 catbacked object, the property contains the paths of the original V5 object.
 * <DD>This field is Null in case of a V6->V5 catbacked object.
 * @param oBackLevel
 *   Phase info of the Object
 * <DD>This information is to define is the object is a V6->V5 object or not.
 * <UL>
 * <DD><LI><KBD>V6V5</KBD>: Object is a V6->V5 conversion As result
 * <DD><LI><KBD>V6V5AsSpec</KBD>: Object is a V6->V5 conversion AsSpec (for CATPart and CATShape only)
 * <DD><LI>else: Object is a current Version (V5 or V6) object (conversion or not)
 * </UL>

 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>          <dd>DocId maps to existing CATIA Document.
 *   <dt><tt>E_FAIL</tt>        <dd>DocId fails to map to existing CATIA Document.
 *   </dl>
 */
ExportedByCATDWCInfra HRESULT GetCATBackProperty ( CATIDocId * iDocId, CATUnicodeString & oBackVersion, CATUnicodeString & oBackPath, CATUnicodeString & oBackLevel ) ;



/**
 * Saves CATDWC properties attached to an object specified by 'PathName'
 * <BR>Retrieves the BackVersion and  BackPath for an object specified by 'DocId'
 * Supports CATIA V5 Documents only.
 * @param iDocId
 *   Document ID of CATIA Document
 * @param oBackVersion
 *   Version of the CATIA Document
 * <DD>The format of a Version is CATIAV<I>x</I>R<I>y</I>. 
 * <DD>Because of the native SP compatibility, No SP information is needed.
 * @param iBackPath
 *   reference of the V6PLM objects which is linked to the V5 document
 * <DD>In case of a V5->V5 catbacked object, the property contains the paths of the original V5 object.
 * <DD>This field is Null in case of a V6->V5 catbacked object.
 * @param iBackLevel
 *   Phase info of the Object
 * <DD>This information is to define is the object is a V6->V5 object or not.
 * <UL>
 * <DD><LI><KBD>V6V5</KBD>: Object is a V6->V5 conversion As result
  * <DD><LI><KBD>V6V5AsSpec</KBD>: Object is a V6->V5 conversion AsSpec (for CATPart and CATShape only)
 * <DD><LI>else: Object is a current Version (V5 or V6) object (conversion or not)
 * </UL>

 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>          <dd>DocId maps to existing CATIA Document.
 *   <dt><tt>E_FAIL</tt>        <dd>DocId fails to map to existing CATIA Document.
 *   </dl>
 */
ExportedByCATDWCInfra HRESULT SetCATBackProperty ( CATDocument * pV5Doc, CATUnicodeString iBackVersion, CATUnicodeString iBackPath, CATUnicodeString iBackLevel ) ;

#endif







