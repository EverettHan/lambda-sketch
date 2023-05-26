/* -*-c++-*- */
#ifndef CATIStorageData_h
#define CATIStorageData_h

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/*
 *
 *  CATIStorageData :
 *     - interface supported by CATStorageData
 *     - used get storage properties: 
 *		- via CATIStorageProperty [ Storage Type(value from enum)
 *					  , Type (late typing), UserID]
 *		- Storage name
 *		- Storage alias
 */
//================================================================
//  Usage notes :
//
//
//		05/98		slg/lbf
//================================================================

/**
 * @level Private
 * @usage U3
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
//
#include "booleanDef.h"

class CATUnicodeString;
class CATIStorageProperty_var;
class CATIStorageData_var;


extern ExportedByAC0XXLNK IID IID_CATIStorageData ;







class ExportedByAC0XXLNK CATIStorageData : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    virtual CATUnicodeString GetStoragePath () = 0;
    virtual CATIStorageProperty_var GetStorageProperty () = 0;
    virtual CATUnicodeString GetAlias () = 0;
    virtual CATIStorageData_var GetFatherData () = 0;
    virtual HRESULT AreDataLoaded () = 0; // returns S_FALSE if not loaded
    virtual HRESULT LoadData( CATBaseUnknown_var& oDataLoaded) = 0;// oDataLoaded output data
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIStorageData, CATBaseUnknown ) ;


#endif
