
// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATDocPath.h
// Header definition of CATDocPath
//
//===================================================================
//
// Usage notes:
//   This object is used to manage document paths for listener
//===================================================================
//
//  Oct 2008  Creation: CRM
//===================================================================

/**
* @level Private 
* @usage U1 
*/
#ifndef CATDocPath_H
#define CATDocPath_H

#include "CATUnicodeString.h" 
#include "ExportedByCATIAEntity.h"

class ExportedByCATIAEntity CATDocPath
{
  public:
    /**
	  * Constructs a CATDocPath.
  	*/
    CATDocPath() ;

    virtual ~CATDocPath() ;

    /**
	  * Inits the object and stores a document path.
  	* @param iDocPath
  	*  the document path
  	*/
    static void             Init( const CATUnicodeString & iDocPath) ;

     /**
	  * Gets the document path previously stored.
  	*/
    static CATUnicodeString GetDocPath ();
} ;

#endif
