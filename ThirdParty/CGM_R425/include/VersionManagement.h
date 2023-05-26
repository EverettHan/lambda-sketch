/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES  2001
//===========================================================================
// June. 2001   Creation                                 Y.Wallier
// Class VersionManagement : Objet de Gestion des Versions CATIA supportees
//===========================================================================

#ifndef VersionManagement_h
#define VersionManagement_h
 
#include "DLCDevLevel.h"

/** 
 *  @level Protected 
 *  @usage U1
 */
#define SHORTEXTERNALVERSIONNAME   1
#define LONGEXTERNALVERSIONNAME   2

/**
 * the string 'NotaV5Doc' defines a 'Not CATIAV5' document.
 */
#define NotaV5Doc   "Not a CATIA V5 Document" 
/**
 * the string 'DocPreV5R8' defines a Pre V5R8 document.
 */
#define DocPreV5R8  "Document pre V5R8"

#ifndef CATIAV5R16
#define CATIAV5R16
#endif

#ifndef CATIAV5R17
#define CATIAV5R17
#endif

#ifndef CATIAV5R18
#define CATIAV5R18
#endif

//Once R19 is available this code will be exposed.
//#ifndef CATIAV5R19
//#define CATIAV5R19
//#endif


#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATLibEx.h" // CATIALevelInfo
#include "ExportedByDataAdmin.h"
#ifdef HL_F045947 // SCALE_CONVERSION_AVAILABILITY
#include "CATCkeScale.h"
#endif

/**
 * This class contains a number of static methods designed to simplify and 
 * speed up the use of CATIA Version. 
 * <BR>All version handled by this class are internal named version (.i.e CATIAV5Rxx) except the internal/External name conversion methods.
 */

class ExportedByDataAdmin VersionManagement {
  public:

/*x
Section pure Version methods
Abstract This section contains methods to manage versions.
x*/

/**
 * Initialises the supported Versions.
 * <BR>Initialises the static object to supported Versions while listing all possible CATIAV5Versions ... 
 * <BR>This initialization is mandatory to use most of following methods.
* @return 
 *		Flag indicating status of operation.
 * <br><b>Legal values:</b><br>
 * <tt>0</tt>	 Success in Init<br>
 * <tt>-1</tt> Failure while initialising.<br>
 */
    static int Init (void);
/**
 * Cleans the list of supported Versions.
 */
    static int Clean (void);
/**
 * Returns last Targeted Version set by DownwardCompatibility application.
 * <BR>When no DownwardCompatibility process is running, the TargetedVersion is set to the CurrentVersion.
 * @return
 *		Last Targeted Version.
 */
    static CATUnicodeString GetTargetedVersion (void) ;    
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
    static int PutTargetedVersion (CATUnicodeString iLatestTargetedVersion) ;    
/**
 * Returns the minimal supported version.
 * @return 
 *			Minimal Supported version.
 */
	static CATUnicodeString GetMinimalVersion (void) ;    
/**
 * Sets the minimal supported version.
 * @param iMinimalVersion
 *			Internal name of the minimal Supported version.
 * @return 
 *		Success status.
 * <br><b>Legal values:</b><br>
 * <tt>0</tt>	 Success.<br>
 * <tt>1997</tt> iMinimalVersion is not supported.<br>
 */
    static int PutMinimalVersion (CATUnicodeString iMinimalVersion) ; 
/**
 * Verifies whether TestVersion is supported Version.
 * @param iTestVersion
 *			Test Version.
 * @return
 *		Success status.
 * <br><b>Legal values:</b><br>
 * <tt>1</tt>	 Success.<br>
 * <tt>0</tt> iTestVersion is not supported.<br>
 */
	static int IsaVersion (CATUnicodeString iTestVersion) ; 
/**
 * Get the list of versions
 * <BR>V5 Version only
 * <BR>Returns list of internal names supported versions.
 * @return 
 *			List of supported versions (internal names).
 */
	static CATListOfCATUnicodeString GetListOfVersion (void) ;    
/**
 * Get the Current version
 * <BR>V6 Version only
 * <BR>Returns Current version of In-Process CATIA document.
 * @return 
 *			Current version (internal name) of In-Process CATIA document.
 */
    static CATUnicodeString GetCurrentVersion (void) ;    

/**
* Compares two versions.
* <BR>Compares two versions (internal names : CATIAV5Rxx)
 * <BR>Support V5 and V6 Version
 * @param iVersion1 	First internal name of the version to be compared.
* @param iVersion2 	Second internal name of the version to be compared.
* @return 
*		Return following leagal values : <UL>
*		<LI>0 : If two versions are same.
*		<LI>1 : If first version is greater than second one.
*	   <LI>-1 : If first version is smaller than second one.
* </UL>
*/
static int Compare (CATUnicodeString iVersion1, CATUnicodeString iVersion2) ;    

/**
 * Returns last Known V5 Version.
 * <BR>V5 Version only
 * @return
 *		Internal name of the last known V5 Version (CATIAV5Rxx).
 */
    static CATUnicodeString GetLastV5Version (void) ;    

	/**
 * From internal name to external name.
 * <BR>Support V5 and V6 Version
 * @param iInternalVersion the Internal V5 Version name (CATIAV5Rxx or V5Rxx) or V6 Version name (CATIAV6R2xx or V6R2xx) for which we search the external name.
  * @param InfoTyp the type of external ersion requested:
  * <UL>
  * <LI>1: Short Name
  * <LI>2: Long name
  * </UL>
* @return
 *		External name of the V5 Version (CATIAV5-6R201x) or V6 Version (CATIAV6R201xX or 3DEXPERIENCE Platform V6R201xX).
  * <BR>Correspondance is as follow:
  * <CENTER><TABLE><TR><TD>
  * <TABLE BORDER=1 BORDERCOLOR=GRAY CELLPADDING=5 CELLSPACING=0>
  * <?php echo $LINE.$HROWYELLOW ; ?>Internal V5 Name <?php echo $HROWYELLOW ; ?>External short V5 Name <?php echo $HROWYELLOW ; ?>External long V5 Name
  * <?php echo $LINE.$ROW ; ?>CATIAV5R25 <?php echo $ROW ; ?>V5-6R2015<?php echo $ROW ; ?>Version 5-6 Release 2015
  * <?php echo $LINE.$ROW ; ?>CATIAV5R24 <?php echo $ROW ; ?>V5-6R2014<?php echo $ROW ; ?>Version 5-6 Release 2014
  * <?php echo $LINE.$ROW ; ?>CATIAV5R23 <?php echo $ROW ; ?>V5-6R2013<?php echo $ROW ; ?>Version 5-6 Release 2013
  * <?php echo $LINE.$ROW ; ?>CATIAV5R22 <?php echo $ROW ; ?>V5-6R2012<?php echo $ROW ; ?>Version 5-6 Release 2012
  * <?php echo $LINE.$ROW ; ?>CATIAV5R21 <?php echo $ROW ; ?>V5R21	  <?php echo $ROW ; ?>Version 5-6 Release 21
  * <?php echo $LINE.$ROW ; ?>CATIAV5R20 <?php echo $ROW ; ?>V5R20	  <?php echo $ROW ; ?>Version 5-6 Release 20
  * <?php echo $LINE.$ROW ; ?>CATIAV5R19 <?php echo $ROW ; ?>V5R19	  <?php echo $ROW ; ?>Version 5-6 Release 19
  * <?php echo $LINE.$ROW ; ?>CATIAV5R18 <?php echo $ROW ; ?>V5R18	  <?php echo $ROW ; ?>Version 5-6 Release 18
  * <?php echo $LINE.$ROW ; ?>CATIAV5R17 <?php echo $ROW ; ?>V5R17	  <?php echo $ROW ; ?>Version 5-6 Release 17
  * <?php echo $LINE.$ROW ; ?>CATIAV5R16 <?php echo $ROW ; ?>V5R16	  <?php echo $ROW ; ?>Version 5-6 Release 16
  * </TABLE> 
  * <TD WIDTH=50><TD>
 * <TABLE BORDER=1 BORDERCOLOR=GRAY CELLPADDING=5 CELLSPACING=0>
  * <?php echo $LINE.$HROWYELLOW ; ?>Internal V6 Name <?php echo $HROWYELLOW ; ?>External short V6 Name <?php echo $HROWYELLOW ; ?>External long V6 Name
 * <?php echo $LINE.$ROW ; ?>CATIAV6R217 <?php echo $ROW ; ?>V6R2015x  <?php echo $ROW ; ?>3DEXPERIENCE R2015x
 * <?php echo $LINE.$ROW ; ?>CATIAV6R216 <?php echo $ROW ; ?>V6R2014x  <?php echo $ROW ; ?>3DEXPERIENCE R2014x
 * <?php echo $LINE.$ROW ; ?>CATIAV6R215 <?php echo $ROW ; ?>6R2014    <?php echo $ROW ; ?>Version 6 Release 2014
 * <?php echo $LINE.$ROW ; ?>CATIAV6R214 <?php echo $ROW ; ?>V6R2013x  <?php echo $ROW ; ?>Version 6 Release 2013x
 * <?php echo $LINE.$ROW ; ?>CATIAV6R213 <?php echo $ROW ; ?>V6R2013   <?php echo $ROW ; ?>Version 6 Release 2013
 * <?php echo $LINE.$ROW ; ?>CATIAV6R212 <?php echo $ROW ; ?>V6R2012x  <?php echo $ROW ; ?>Version 6 Release 2012x
 * <?php echo $LINE.$ROW ; ?>CATIAV6R211 <?php echo $ROW ; ?>V6R2012   <?php echo $ROW ; ?>Version 6 Release 2012
 * <?php echo $LINE.$ROW ; ?>CATIAV6R210 <?php echo $ROW ; ?>V6R2011x  <?php echo $ROW ; ?>Version 6 Release 2011x
 * <?php echo $LINE.$ROW ; ?>CATIAV6R209 <?php echo $ROW ; ?>V6R2011   <?php echo $ROW ; ?>Version 6 Release 2011
 * </TABLE>
 * </TABLE></CENTER>
*/

	static CATUnicodeString GetExternalVersion(CATUnicodeString iInternalVersion,int InfoTyp=1); 

/**
 * From external name to internal name.
  * @param iExternalVersion the EXternal version name (CATIAV5-6R201x) for which we search the external name.
 * @return
 *		internal name of the V5 Version (CATIAV5Rxx or V5Rxx) or V6 Version (CATIAV6R2xx or V6R2xx).
 */
	static CATUnicodeString GetInternalVersion(CATUnicodeString iExternalVersion); 

  /*x
Section Dedicated methods to DownwardCompatibility (conversion between versions)
Abstract This section contains methods to manage DownwardCompatibility whihch has nothing to
 do at this place but no better place.
x*/

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
	static void SetCatback (int iCatBack) ;    
/**
 * Returns the current CATDWC.
 * @return
 *		Current CATDWC value.
 * <br><b>Legal values:</b><br>
 * <tt>0</tt> : (default) Current process is not in a CATDWC transaction	 <br>
 * <tt>1</tt> : Current process is not in a CATDWC transaction <br>
 */
    static int IsCatback  (void) ; 

#ifdef HL_F045947 // SCALE_CONVERSION_AVAILABILITY
/**
 * Returns the current CATDWC scale.
 * @param oScale 
 *		Current CATDWC scale value
 */
    static void GetCatbackScale  (CATCkeScale & oScale) ;    

    /**
 * Sets the CATDWC scale.
 * @param iScale
 *		Current CATDWC scale value
 */
    static void SetCatbackScale  (CATCkeScale iScale) ;    
#endif

  private:
	static CATUnicodeString GetCurrentVersionUsingCATIALevelInfo();
    static CATListOfCATUnicodeString _ListOfV5Version ;
    static CATListOfCATUnicodeString _ListOfV6Version ;
    static CATUnicodeString _TargetedVersion ;
    static CATUnicodeString _MinimalVersion ;
    static CATUnicodeString _CurrentVersion ;
    static CATUnicodeString _LastV5Version  ;    
    static int  _isCatback ;
#ifdef HL_F045947 // SCALE_CONVERSION_AVAILABILITY
    static CATCkeScale _CatbackScale ;
#endif
	};
#endif
