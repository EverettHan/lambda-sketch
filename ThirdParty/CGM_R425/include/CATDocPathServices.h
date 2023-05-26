// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef		CATDocPathServices_h
#define		CATDocPathServices_h

////////////////////////////////////////////////////////////////////////////////
//
//
//
//	Purpose : 
//	=========
//			1- File Services
//			1- General services
//				- conversion CAUuid -> CATUnicodeString
//				- container -> List Of All Container Hierarchy
//				- ...
//			2- Services On Doc storage names
//			(corresponds to file name for standard documents
//               	and to more complicated path names for embedded documents)
//		         
//               	ex: "/tmp/prod.CATProduct!Part1.CATPart" represents an embedded "CATPart" document inside the
//                   	the "CATProduct" document stored in file "/tmp/prod.CATProduct"
//
//	Authors : 	slg
//	=======
//
//
//
////////////////////////////////////////////////////////////////////////////////
/**
 * @level Protected 
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATIAV5Level.h"
#include "CATListPV.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATFile.h"
#include "booleanDef.h"
#include "CATUnicodeString.h"
#include "sequence_octet.h"
#include "CATDocumentsInSession.h"
#include "CATListOfCATUnicodeString.h"

/*******************************************
 * THIS CODE MUST BE THE SAME IN V5 AND V6 *
 *     PLEASE REPORT MODIFICATIONS         *
 *******************************************/

//
class CATUuid;
class CATIContainer_var;
class CATIBindParameters;
class CATILinkableObject_var;
class CATDocument;
class CATIDocId;
class CATIProjectFlag_var;

#ifndef CATIAR213
//USED ONLY ONCE IN DNB...TO REMOVE
ExportedByAC0XXLNK
int CompareUnicodeStrings(const CATUnicodeString& iUnicodeString1, const CATUnicodeString& iUnicodeString2);
#endif
// ==========================================================================
//	File Services
//	-------------

ExportedByAC0XXLNK
CATUnicodeString GetFileName ( const CATUnicodeString& iDocStorageName);

// test access mode of stored document from its storage name
#ifndef CATIAR213
ExportedByAC0XXLNK
#endif
boolean GetDocAccessMode ( const CATUnicodeString& iDocStorageName);

/**
 * Gets the position of the extension and the position of the remainder in a file name.<br>
 * Sample:<pre>
 *          123456789012345678901234567
 * Position 012345678901234567890123456  Length  oExtPos  oExtSize oRemPos  oRemSize
 *         "xxx/yyy/Part1"                 13      -1         0      -1         0
 *         "xxx/yyy/Part1.CATPart"         21      14         7      -1         0
 *         "xxx/yyy/Part1.CATPart.45547"   26      14         7      22         5
 * </pre>
 * @param iDocStorageName
 *   The document storage name.
 * @param oExtPos
 *   The position of the extension (0 to length - 1). If it's negative, no extension has been found.
 * @param oExtSize
 *   The size of the extension
 * @param oRemPos
 *   The position of the remainder (0 to length - 1). If it's negative, no remainder has been found.
 * @param oRemSize
 *   The size of the remainder
 */
ExportedByAC0XXLNK void GetFileNamePosExtAndRem(const CATUnicodeString &iDocStorageName, int &oExtPos, int &oExtSize, int &oRemPos, int &oRemSize);

// tget file extension name
ExportedByAC0XXLNK
CATUnicodeString GetFileExtensionName ( const CATUnicodeString& FileExtensionName );


// ===========================================================================
//	General Services
//	----------------
ExportedByAC0XXLNK
CATLISTV(CATBaseUnknown_var)* GetListContainers( const CATIContainer_var& Cont );

ExportedByAC0XXLNK
CATULONG32  CATwcslen ( const WCHAR* s);
 
ExportedByAC0XXLNK
CATUnicodeString BuildNameFromUuid ( CATUuid& TheUUID);

ExportedByAC0XXLNK 
CATUnicodeString GetFileFromName_B (const SEQUENCE(octet)& nameB );

ExportedByAC0XXLNK 
CATUnicodeString GetDocTypeFromName_B (const SEQUENCE(octet)& nameB );

ExportedByAC0XXLNK 
void IsDocFoundAndLoaded (const SEQUENCE(octet)& nameB, 
                          boolean& docIsFound, 
                          boolean& docIsLoaded );

#ifndef CATIAR213
ExportedByAC0XXLNK HRESULT FindDoc(const CATUnicodeString& PointingDocPath,CATUnicodeString& PointedDocPath,const CATUnicodeString& LastPointingDocPath="");
#endif

//
//  Bind Service
//
ExportedByAC0XXLNK
CATILinkableObject_var BindInSession(const SEQUENCE(octet)& Name);

//
//
//
ExportedByAC0XXLNK
HRESULT UpdateDocumentLinks(CATDocument * iDocument);


ExportedByAC0XXLNK
HRESULT CATResetLinksOnDoc(CATIDocId * iDocId);

#ifndef _WINDOWS_SOURCE
#define FSTRCMP(x,y)	  strcmp(x,y)
#else
	// On windows, filenames are note case sensitive 
#define FSTRCMP(x,y)	  _stricmp(x,y)
#endif
//
ExportedByAC0XXLNK
HRESULT IsCatalogType(const CATUnicodeString* type);

ExportedByAC0XXLNK
HRESULT IsCatalogFileType(const CATUnicodeString* type);

#ifndef CATIAR213
///////////////////////////
//  DO NOT USE
//  FOR SLG/GDC ONLY : interop VPM/V5
///////////////////////////
ExportedByAC0XXLNK
HRESULT CATOpenDocument(CATDocument*& oDocument, CATIDocId* iDocId=NULL, const CATUnicodeString& iDocType="", const CATUnicodeString& iPath="", boolean ReadOnly=FALSE);



ExportedByAC0XXLNK 
CATUnicodeString CATGetDefaultDocName(const CATUnicodeString& iDocType);
#endif

#endif		/* CATDocPathServices_h */
