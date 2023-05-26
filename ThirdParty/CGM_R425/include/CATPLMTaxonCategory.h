// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATPLMTaxonCategory.h
//
//===================================================================
//
// Usage notes:
//
//  May 2010  Creation: LEC
//===================================================================
#ifndef CATPLMTaxonCategory_H
#define CATPLMTaxonCategory_H
#include "CATPLMFTSAvailable.h"
#include "CATIAV5Level.h"
#include "CATBaseUnknown.h"
#include "CATPLMServicesItf.h"
#include "CATUnicodeString.h"
#include "CATOmxVector.h"

class CATPLMTaxon;

#ifndef FTSAvailable
class ExportedByCATPLMServicesItf CATPLMTaxonCategory : public CATBaseUnknown
{
public:
  int Count() {return 0;}
  HRESULT GetTaxon( const int & iIndex, CATPLMTaxon** opTaxon ) {return E_NOTIMPL;}
};
#else

/**
* @level Protected
* @usage U2
*/

/** @nodoc */
class ExportedByCATPLMServicesItf CATPLMTaxonCategory : public CATBaseUnknown
{
  friend class CATPLMDataSetQueryHandler;// M1 implementation
  friend class CATPLMDataStreamHandler;// M1 implementation
  friend class CATPLMDebugSearchQueryHandler;// TST Provider implementation
  
public:
  CATPLMTaxonCategory( const CATUnicodeString & iName );
  virtual ~CATPLMTaxonCategory();

  /** 
   * Retrieve name of the taxon category returned by the provider.
  */
  CATUnicodeString GetName();

  /** 
   * Number of taxon retrieve for the current category.
  */
  int Count();

  /** 
   * Retrieve taxon(s) returned by the provider.
   *
   * @param iIndex [o...size-1]
   *   index of taxon you want to retrieve
   * @param opTaxon [out, CATBaseUnknown#Release]
   *   object representing the taxon
   * @return
   *   Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dt>E_FAIL </dt>
   *   </dl>
  */
  HRESULT GetTaxon( const int & iIndex, CATPLMTaxon** opTaxon );

private:
  HRESULT _Append(CATPLMTaxon* ipTaxon);

  CATOmxVector<CATPLMTaxon> _listOfTaxon;

  CATUnicodeString _taxonCategoryName;
  int              _taxonCategoryCount;

};


#endif
#endif
