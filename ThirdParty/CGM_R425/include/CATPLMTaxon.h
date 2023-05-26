// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATPLMTaxon.h
//
//===================================================================
//
// Usage notes:
//
//  May 2010  Creation: LEC
//===================================================================
#ifndef CATPLMTaxon_H
#define CATPLMTaxon_H
#include "CATIAV5Level.h"


#include "CATBaseUnknown.h"
#include "CATPLMServicesItf.h"

#include "CATUnicodeString.h"
#include "CATOmxVector.h"

class CATPLMType;

/**
* @level Protected
* @usage U2
*/

/** @nodoc */
#include "CATPLMFTSAvailable.h"
#ifndef FTSAvailable
class ExportedByCATPLMServicesItf CATPLMTaxon : public CATBaseUnknown
{
  friend class TSTCATPLMTaxon; // For VPLMNav tests
public:
    CATPLMTaxon(CATUnicodeString & iVal,int iNum);
    HRESULT GetValueAsString ( CATUnicodeString &oString );
    HRESULT GetValueAsPLMType( CATPLMType** opPLMType );
    int GetCount();
    CATUnicodeString _val;
    int _num;
private:
    HRESULT _Append(CATPLMTaxon* ipTaxon);
};
#else
class ExportedByCATPLMServicesItf CATPLMTaxon : public CATBaseUnknown
{
  friend class CATPLMDataStreamHandler;// M1 implementation
  friend class CATPLMDataSetQueryHandler;// M1 implementation
  friend class CATPLMDebugSearchQueryHandler;// TST Provider implementation
  friend class CATPLMTaxonFunction;// M1 implementation
  friend class TSTCATPLMTaxon; // For VPLMNav tests
  friend class CATPLMFunctionFactory; // Adapter
public:

  CATPLMTaxon(CATUnicodeString & iVal,int iNum);
  virtual ~CATPLMTaxon();

  /** 
   * Retrieve the plmtype associated to the current taxon.
   *
   * @param opPLMType [out, CATBaseUnknown#Release]
   *   plmtype associated to the taxon retrieved.
   * @return
   *   Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dt>E_FAIL </dt>
   *   </dl>
  */
  HRESULT GetValueAsPLMType( CATPLMType** opPLMType );

  /** 
   * Number of elements retrieved for the current taxon.
  */
  int GetCount();

  /** 
   * Retrieve sub taxons.
   * Life cycle:
   *    - each element of the returned oSubTaxons array must be released
   *    - oSubTaxons must be deleted
   *
   *   CATPLMTaxon **subTaxons = NULL;
   *   int           nbSubTaxons = 0;
   *   if (SUCCEEDED(taxon->GetSubTaxons(subTaxons, nbSubTaxons))) {
   *       for (int i=0;i<nbSubTaxons;i++) {
   *           if (subTaxons[i]) {
   *               ...
   *               CATSysReleasePtr(subTaxons[i]);
   *           }
   *       }
   *       delete []subTaxons;
   *       subTaxons = NULL;
   *   }
   *
   * @param oSubTaxons
   *   List of Sub taxons. Each element must be released, array must be deleted.
   * @param oNbSubTaxons
   *   Number of sub taxons
   * @return
   *   Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dt>E_FAIL </dt>
   *   </dl>
  */
  HRESULT GetSubTaxons(CATPLMTaxon **&oSubTaxons, int &oNbSubTaxons);

  /** 
   * Get father taxon
   *
   * @param oFatherTaxon [out, CATBaseUnknown#Release]
   *   father taxon.
   * @return
   *   Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dt>E_FAIL </dt>
   *   </dl>
  */

  HRESULT GetFatherTaxon(CATPLMTaxon *&oFatherTaxon);

  /** 
   * Retrieve the current taxon value 'as is'.
   *
   * @param oSrting [out]
   *   The string value of the taxon, WARNING : may be unreadable by user (NLS ?).
   * @return
   *   Error code of function :
   *   <dl>
   *     <dt>S_OK if the taxon has a Count > 0</dt>
   *     <dt>E_FAIL otherwise</dt>
   *   </dl>
  */
  HRESULT GetValueAsString ( CATUnicodeString &oString );

private:
  HRESULT _Append(CATPLMTaxon* ipTaxon);

  CATOmxVector<CATPLMTaxon> _listOfTaxon;
  CATPLMTaxon *_father;

  CATUnicodeString _val;
  int _num;
};


#endif
#endif
