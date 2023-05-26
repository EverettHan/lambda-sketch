/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
 *  @level Protected 
 *  @usage U1
 */

#ifndef Cleaner_Tags_Property
//#define Cleaner_Tags_Property
#endif

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByCATClnBase.h"
#include "CATString.h"

class CATDocument;

/**
 * Tests whether a file can be processed by DUA.
 *<br><b>Role:</b> Need this test since only CATProduct, CATDrawing, CATPart, CATAnalysis, CATProcess are allowed.
 * @param iFiletotest
 *			Name of File to test.
 * @param iGiveType
 *			Type of file.
 * @param iODTDocCheckCtxt
 *			Flag indicating DocCheckContext for ODT.
 * return 
 *			Type of File.	
 * <br><b>Legal values:</b><br>
 * <tt>1</tt>  For CATPRODUCT<br>
 * <tt>2</tt>  For CATDRAWING<br>
 * <tt>3</tt>  For CATPART<br>
 * <tt>4</tt>  For CATANALYSIS<br>
 * <tt>5</tt>  For CATPROCESS<br>
 * <tt>6</tt>  For MODEL<br>
 * <tt>7</tt>  For CATALOG<br>
 * <tt>8</tt>  For CATMATERIAL<br>
 */
ExportedByCATClnBase short IsFileValid(char * iFiletotest, short iGiveType, short iODTDocCheckCtxt=0);

/**
 * Computes the list of files pointed by a root document.
 * @param iAssemblyName
 *			The document name.
 * @return
 *			The list returnesd is ordered from leafs up to root
 */
ExportedByCATClnBase CATListOfCATUnicodeString * OrderFilesForRootDoc(CATUnicodeString iAssemblyName);


/**
 * Marks document after SaveAs and process by DUA
 * @param iDoc
 *			Pointer to Document to process.
 */
ExportedByCATClnBase HRESULT MarkAfterDUA(CATDocument* iDoc);

#ifdef Cleaner_Tags_Property
/**
 * Returns the last Release and SP on which the document has been processed by DUA.
 * @param iDoc
 *			Pointer to Document to process.
 * @param oReleaseNb
 *			DUA Release.
 * @param oServicePackNb
 *			DUA Servie Pack.
 */
ExportedByCATClnBase HRESULT GetLastDUALevel(CATDocument* iDoc, int& oReleaseNb, int& oServicePackNb);
#endif
/**
 * Sets the DUA working mode.
 * @param iMode
 *		  Flag indicating working status.
 * <br><b>Legal values:</b><br>
 * <tt>TRUE</tt>  DUA is going to work<br>
 * <tt>FALSE</tt>  DUA is not going to work<br>
 */
ExportedByCATClnBase void SetDUAMode(boolean iMode=TRUE);

/**
 * To know if DUA is working.
 */
ExportedByCATClnBase boolean IsDUARunning();

/** 
 * Returns the Repository Name.
 */
ExportedByCATClnBase HRESULT GetValidRepositoryName(CATUnicodeString & ioRepName);


/**
 *  set the domains/kwrds/sev according to admin list if available
 *  @param oAllButMode
 *         To get Status Whether AllBut Mode or Not
 *  @param oExternalError
 *         External Error List
 */
ExportedByCATClnBase void GetAdminErrorList(int & oAllButMode,CATListOfCATUnicodeString & oExternalError);
/** 
 * Service reads the Warning/Error Message from NLS Catalog.
 * @param iKey
 *			NLS string to read
 * @param iNom_catalog
 *			Catalog Name
 * @param iMsgParameters
 *			Action Params for message
 * @return 
 *		NLSed warning/error message
 */
ExportedByCATClnBase CATUnicodeString read_ChkRepMsg (CATString iKey , CATString iNom_catalog, CATUnicodeString *iMsgParameters = NULL, int iMsgParamSize=1);
