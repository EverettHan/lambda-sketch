/* -*-c++-*- */
#ifndef CATIOleInsertion_h
#define CATIOleInsertion_h
// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//
// Interface CATIOleInsertion :
//    - Should Be Implemented On A Document
//	  - The "Insert" Command Checks whether the current document adheres to 
//		this interface and then:
//				* creates the inserted object in a "CATSpecOleSite" spec
//				  inside a Container given by ProcessBeforeInsertion
//				* calls ProcessAfterInsertion to give back to the document the feature
//
//	( Interface used By The Insert Command which is implemented in CATIADataFrame )
//
//=============================================================================
// Usage Notes:
//

//=============================================================================
//	Jan.98   Creation                                slg
//=============================================================================

/**
 * @level Private 
 * @usage U3
 */

// BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATBaseUnknown.h"
// ObjectModelerBase
#include "AC0WINLNK.h"

class CATIContainer_var;
class CATListValCATISpecObject_var;
class CATUnicodeString;


extern ExportedByAC0WINLNK IID IID_CATIOleInsertion ;

class ExportedByAC0WINLNK CATIOleInsertion : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  //
  //	INSERT COMMAND
  //	--------------

  // Called Before Insertion, returns the container where to create the feature
  virtual
    CATIContainer_var ProcessBeforeInsertion ( ) = 0;

  // Called Before Insertion, gives in argument the container where to create the feature 
  //											  and the late type of the ole site
#ifdef CATIAR419
  virtual
    HRESULT ProcessBeforInsertion(CATIContainer_var& oContainer, CATUnicodeString& oType, CATUnicodeString& oCatalogName) = 0;
#else
  virtual
    HRESULT ProcessBeforInsertion(CATIContainer_var& oContainer, CATUnicodeString& oType) = 0;
#endif

  // Called After Insertion, Gives In Aggument The Corresponding Object
  virtual
    void ProcessAfterInsertion ( const CATBaseUnknown_var& iNewInsertionSpec) = 0;

  //
  //	EDIT LINKS COMMAND
  //	------------------
  virtual
    CATListValCATISpecObject_var* GetOLELinks () = 0;
  
  virtual
    HRESULT HasOleLinks(int * oOleLinks) = 0;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIOleInsertion, CATBaseUnknown ) ;

#endif
