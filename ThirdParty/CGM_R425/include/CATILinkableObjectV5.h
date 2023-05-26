#ifndef CATILinkableObjectV5_h
#define CATILinkableObjectV5_h

// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @level Protected
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "sequence_octet.h"

#include "CATOMY.h"
extern ExportedByCATOMY IID IID_CATILinkableObjectV5 ;

/**
 * Reserved for specific usages
 * Interface to retrieve the "V5" identification of FeatureModeler objects
 * @see CATILinkableObject
 */
class ExportedByCATOMY CATILinkableObjectV5 : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
   * Returns the "V5" identifier (based on the "diezele" for features).
   */ 
  virtual void GetIdentifier( SEQUENCE(octet) & identifier ) = 0;

};

CATDeclareHandler( CATILinkableObjectV5, CATBaseUnknown ) ;

#endif

