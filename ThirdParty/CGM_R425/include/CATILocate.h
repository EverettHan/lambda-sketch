/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATILocate_h
#define CATILocate_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

#include "sequence_octet.h"
#include "CATUnicodeString.h"

class CATIBindParameters;
class CATDocument;

#include "CATObjectModelerBase.h"
extern ExportedByCATObjectModelerBase IID IID_CATILocate ;

class ExportedByCATObjectModelerBase CATILocate : public CATBaseUnknown
{
  CATDeclareInterface;

public:

		/** @nodoc */
  virtual HRESULT Seek ( const SEQUENCE(octet)& name
				    ,const SEQUENCE(octet)& type
				    ,const SEQUENCE(octet)& hint
				    ,CATDocument          * doc
				    ,CATIBindParameters   * params
				    ,const CATIdent 	   interfaceID
					,CATBaseUnknown*& CBU )=0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATILocate, CATBaseUnknown ) ;


#endif



