/* -*-c++-*- */
#ifndef CATIDocumentProvider_h
#define CATIDocumentProvider_h

// COPYRIGHT DASSAULT SYSTEMES 2001
//=============================================================================
/**
 *  CATIDocumentProvider :
 */
//================================================================
//  Usage notes :
//
//
//		01/01		bpe
//================================================================

/**
 * @level Private
 * @usage U3
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
//
#include "CATUnicodeString.h"


extern ExportedByAC0XXLNK IID IID_CATIDocumentProvider ;


class ExportedByAC0XXLNK CATIDocumentProvider : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
      virtual
	HRESULT GetDocumentType(const CATUnicodeString& iFileName, CATUnicodeString& oDocumentType) = 0;
		
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocumentProvider, CATBaseUnknown ) ;


#endif
