/* -*-c++-*- */
#ifndef CATISymbolProperty_h
#define CATISymbolProperty_h

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/*
 *
 *  CATISymbolProperty :
 *     - interface supported by CATStorageProperty
 *     - used get a storage property
 */
//================================================================
//  Usage notes :
//
//
//		07/98		slg
//================================================================

/**
 * @level Private
 * @usage U3
 */

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
//
#include "sequence_octet.h"
#include "CATUnicodeString.h"
class CATUnicodeString;

extern ExportedByCATObjectModelerBase IID IID_CATISymbolProperty ;



class ExportedByCATObjectModelerBase CATISymbolProperty : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
      virtual
	HRESULT GetPointedFileName ( CATUnicodeString& oFileName) =0;

	  virtual 
	SEQUENCE(octet) GetName_B () = 0;
      virtual 
	SEQUENCE(octet) GetStoredName_B () = 0;

      virtual 
	int NeedToSavePointed () = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATISymbolProperty, CATBaseUnknown ) ;


#endif
