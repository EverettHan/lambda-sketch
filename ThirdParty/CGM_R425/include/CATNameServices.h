/* -*-c++-*- */
#ifndef CATNAMESERVICES_H
#define CATNAMESERVICES_H
// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//
// Global Methods :
//     
//       Utilities for Name Manipulations 
//
//=============================================================================
// Usage Notes:
//
//    - read comments 
//=============================================================================
// Jun. 96   Creation                                
//=============================================================================

/**
 * @level Private
 * @usage U1
 */

#include "stringDef.h"
#include "booleanDef.h"
#include "sequence_octet.h"
#include "sharedSequence_octet.h"
#include "CATBaseUnknown.h"
#include "CATIContainer.h"
#include "CATILinkableObject.h"
#include "CATUnicodeString.h"
#include "AC0XXLNK.h"

class CATINamingContext ;
class CATIDocId;


ExportedByAC0XXLNK boolean  CATSplitHint_B( const SEQUENCE(octet)& completehint
					   ,SHAREDSEQUENCE(octet)&	docType
					   ,SHAREDSEQUENCE(octet)&	docStorageName
					   ,SHAREDSEQUENCE(octet)&	complementaryInfos
					   ,SHAREDSEQUENCE(octet)&	TimeStamp);

ExportedByAC0XXLNK boolean  CATSplitNewHint_B( const SEQUENCE(octet)& iHint
					   ,SHAREDSEQUENCE(octet)&	oDocEnvironment
					   ,SHAREDSEQUENCE(octet)&	oDocType
					   ,SHAREDSEQUENCE(octet)&	oDocStorageName
					   ,SHAREDSEQUENCE(octet)&	oComplementaryInfos
					   ,SHAREDSEQUENCE(octet)&	oTimeStamp);

ExportedByAC0XXLNK SEQUENCE(octet)  CATAssembleHint_B( const SEQUENCE(octet)& doctype
						      ,const SEQUENCE(octet)& docStorageName
						      ,const SEQUENCE(octet)& addinfos
						      ,const SEQUENCE(octet)& TimeStamp);
        
// Service plus performant ?
ExportedByAC0XXLNK
HRESULT CATAssembleHint_B (SEQUENCE(octet)& oHint,
			   const SEQUENCE(octet)& iDocType,
			   const SEQUENCE(octet)& iDocStorageName,
			   const SEQUENCE(octet)& iAddInfos,
			   const SEQUENCE(octet)& iTimeStamp);
				   

//=====================================================================
//
// Transform a binary UUID in Printable UUID :
//    unsigned char []  must have length bytes
//    char []           must have 2*length+1 bytes  
//
//    each byte is transformed to its equivalent in hexa on two bytes 
//       0  <-> "00"
//       16 <-> "10" ...
//
ExportedByAC0XXLNK void  BinaryToPrintableUUID(const unsigned char[], char[] , int length);


//=====================================================================
//
// Transform a Printable UUID into a binary UUID:
//    char []           must have 2*length+1 bytes  
//    unsigned char []  must have length bytes
//
// The printable UUID must be written using hexa characters
// It returns 0 if everything is OK 
//            1 if the printable UUID format is incorrect
//
ExportedByAC0XXLNK int   PrintableToBinaryUUID(const char[], unsigned char[] , int length);


//=====================================================================
//
// get object from naming context and relative name
//
ExportedByAC0XXLNK 
CATBaseUnknown*  CATGetObjectFromRelativeName (  CATINamingContext     * ctx
					       , const SEQUENCE(octet) & rn
					       , CATClassId              InterfaceId
					       , CATIBindParameters    * params );



//=====================================================================
//
// assemble a name
//
ExportedByAC0XXLNK
SEQUENCE(octet) CATAssembleName_B (const SEQUENCE(octet)&	uuid,
				   const SEQUENCE(octet)&	relativeName,
				   const SEQUENCE(octet)&	type,
				   const SEQUENCE(octet)&	hint) ;
				   
// Service plus performant ?
ExportedByAC0XXLNK
HRESULT CATAssembleName_B (SEQUENCE(octet)& oName,
			   const SEQUENCE(octet)& iUuid,
			   const SEQUENCE(octet)& iRelativeName,
			   const SEQUENCE(octet)& iType,
			   const SEQUENCE(octet)& iHint);
				   
ExportedByAC0XXLNK
char* CATAssembleName (char* const	&	uuid,
		       char* const	&	relativeName,
		       char* const	&	type,
		       char* const	&	hint) ;



//=====================================================================
//
// split a name
//
// The strings returned by CATSplitName (const  string&, ...) use a static 
// buffer that is reinitialized every time that this function is used.
// If you need these values for a CATLONG32 time, it is better to duplicate them
// somewhere else.
// An important consequence is that theses strings do not need to (CAN NOT) be 
// deleted by the calling program.
//
ExportedByAC0XXLNK
boolean CATSplitName_B (const SEQUENCE(octet)&	absoluteName,
			SHAREDSEQUENCE(octet)&	uuid,
			SHAREDSEQUENCE(octet)&	relativeName,
			SHAREDSEQUENCE(octet)&	type,
			SHAREDSEQUENCE(octet)&	hint) ;

ExportedByAC0XXLNK
boolean CATSplitName (char* const	absoluteName,
		      char*&		uuid,
		      char*&		relativeName,
		      char*&		type,
		      char*&		hint) ;

ExportedByAC0XXLNK
CATUnicodeString  SequenceToUnicode(const SEQUENCE(octet)& seq);

ExportedByAC0XXLNK
SEQUENCE(octet)  UnicodeToSequence(const CATUnicodeString& unicode);
     
ExportedByAC0XXLNK
void UnicodeToSequence(const CATUnicodeString& unicode,SEQUENCE(octet)& result);
//=====================================================================
//
// CATReplaceDocStorageName (bpe aug.98)
// Allows to replace docStorageName in sequence hint 
// 
ExportedByAC0XXLNK
SEQUENCE(octet) CATReplaceDocStorageName (const SEQUENCE(octet)&  oldSequence,
					  const CATUnicodeString& newDocStorageName) ;

ExportedByAC0XXLNK
HRESULT CATReplaceDocStorageName (SEQUENCE(octet)& oNewSequence,
				  const SEQUENCE(octet)&  iOldSequence,
				  const CATUnicodeString& iNewDocStorageName) ;

ExportedByAC0XXLNK
HRESULT CATReplaceDocInfo (SEQUENCE(octet)& oNewSequence,
			   const SEQUENCE(octet)&  iOldSequence,
			   CATIDocId *iDocId) ;


//=====================================================================
//
// Services concernant les id de doclink et docid (hhm  mars.98)
//
ExportedByAC0XXLNK
const SEQUENCE(octet)& CATGetDocIdId ();

ExportedByAC0XXLNK
boolean CATIsDocId (const SEQUENCE(octet)& doc_type);


#endif



