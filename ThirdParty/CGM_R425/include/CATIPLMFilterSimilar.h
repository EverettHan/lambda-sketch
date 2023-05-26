// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMFilterSimilar.h
// Define the CATIPLMFilterSimilar interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2004  Creation: Code generated by the CAA wizard  jsy
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterSimilar_H
#define CATIPLMFilterSimilar_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

class CATBinary;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterSimilar;
#else
extern "C" const IID IID_CATIPLMFilterSimilar ;
#endif


/**
 * Interface to retrieve similar search informations on query
 */
class ExportedByCATPLMServicesItf CATIPLMFilterSimilar: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    enum  SimilarType
    {
      KNN   = 1,      // Kind Near Neighbor  (Default)
      Range = 2
    };

    /** 
    * Get and set the similar type to use.
    * Default = KNN
    */
    virtual HRESULT GetSimilarType ( CATIPLMFilterSimilar::SimilarType &oSimType ) = 0;
    virtual HRESULT SetSimilarType ( CATIPLMFilterSimilar::SimilarType iSimType ) = 0;

    /** 
    * Get and set the signature to search in the index.
    */
    virtual HRESULT GetSignature   ( CATBinary &oSignature ) = 0;
    virtual HRESULT SetSignature ( const CATBinary &iSignature ) = 0;


    /** 
    * Get and set the max number of elements to retrieve.
    * Default = 20
    */
    virtual HRESULT GetResultLimit ( int &oResultLimit ) = 0;
    virtual HRESULT SetResultLimit ( int iResultLimit ) = 0;

    /** 
    * Get and set the range limit ( between 50 - 99 percent )
    */
//    virtual HRESULT GetrangeLimit ( int &oLowLimitRange ) = 0;
//    virtual HRESULT SetRangeLimit ( int iLowLimitRange ) = 0;

}; 

//------------------------------------------------------------------

#endif
