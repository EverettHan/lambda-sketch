#ifndef __CATFmuPath_H
#define __CATFmuPath_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2003
//=============================================================================
/**
 * @level Protected
 * @usage U1
 */
#include "CATUnicodeString.h"
#include "ExportedByCATFmuTools.h"

/**
 * This class deals with path of a document in session for opening/saving etc.
 */
class ExportedByCATFmuTools CATFmuPath
{

   public :
   
   CATFmuPath ();
   CATFmuPath ( const CATUnicodeString iPath );
   ~CATFmuPath ();

   /**
    * Extract Location from Path (If exists)
	*/
   CATUnicodeString GetDocLocation   ( );  // 
   /**
    * Extract Name from Path
	*/
   CATUnicodeString GetDocName       ( );  // 
   /**
    * Extract Extension from Path (If exists)
	*/
   CATUnicodeString GetDocExtension  ( );  // 
   /**
    * Returns the Path of the document
	*/
   CATUnicodeString GetPath          ( );
   /**
    * Converts only the Name in UpperCase.
	*/
   CATUnicodeString GetUpperCasePath ( );  // 
   /**
    * Depending on the OS windows or unix, this mehtod Compares the iPath from acutal Path & returns:
	* For windows this method returns 0 (path not identical), 1(path identical but there is difference in case) or 2 (path identical even casewise)
	* For unix this method  and 0 (path not identical) or 2 (path identical)
	*/
   int Compare ( const CATUnicodeString &iPath );
   private : 

   CATUnicodeString _Path;
   CATUnicodeString _Location;
   CATUnicodeString _Name;
   CATUnicodeString _Extension;

};

#endif
