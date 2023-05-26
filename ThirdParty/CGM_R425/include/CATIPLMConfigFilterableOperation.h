// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMConfigFilterableOperation.h
// Define the CATIPLMConfigFilterableOperation interface
//
//===================================================================
//
//  Nov 2008  YCL
//===================================================================
/**
  * @level Protected
  * @usage U1
*/
#ifndef CATIPLMConfigFilterableOperation_H
#define CATIPLMConfigFilterableOperation_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMConfigFilterableOperation;
#else
extern "C" const IID IID_CATIPLMConfigFilterableOperation ;
#endif

class CATICfgOperationInput;
class CATIPLMConfigFilterable;
class CATListPtrCATIPLMComponent;

/*
 * Indicates that there is an error in the customer code
 */
#define E_CUSTO_CODE _HRESULT_TYPEDEF_(0x80070003L)

//------------------------------------------------------------------

/**
* Interface used to handle operations on a filterable PLM Entity (supporting effectivity)
*
*/
class ExportedByCATPLMComponentInterfaces CATIPLMConfigFilterableOperation: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

      enum CfgOperationInputCompatibility
      {
        EffBeyondCtxt          ,    // Object effectivity partially beyond context effectivity, a Split is required otherwise other configurations than the one defined by the context effectivity will be impacted
        EffCoveredByCtxt       ,    // Object effectivity included in context effectivity, so a Split is useless.
        EffIncompatibleWithCtxt,    // Object and context effectivities are incompatible, so a Split is impossible.
		EffCtxtNotFrozen            // Object effectivity is a named effectivity, so the context is not fully resolved but the split is possible
      };

	  /** 
	  * Checks the possibility/necessity of a Split of the object depending to its effectivity and the context effectivity.
	  *
	  * @param in_opInput [in]
	  *   The context effectivity used for the operation.
	  *
	  * @param out_status [out]
	  *   Information indicating whether a Configured Split is needed, useless or impossible depending to the 
      *   object and context effectivities.
	  *
	  * @return
	  *      A HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The method proceeded without encountering any problem.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>The method didn't execute properly until its supposed end.</dd>
	  *     </dl>
	  */
	  virtual HRESULT CheckOperationInputCompatibility(CATICfgOperationInput const      & in_opInput,
                                                       CfgOperationInputCompatibility   & out_status) = 0;

	  /** 
	  * Performs a Split of the object for the context effectivity.
	  *
	  * @param in_opInput [in]
	  *   The context effectivity for the operation.
	  *
	  * @param in_associatedObjectsToClone [in]
	  *   The objects that we also want to clone in the same scope as the filterable.
	  *   The objective is to allow to reroot links between objects of this scope on the new cloned objects.
      *   NOTE : All of these objects must be aggregated under the same owner as the filterable 
      *   NOTE #2 : In current implementation of corresponding Adapter, the associated objects are not cloned,
      *   and thus this list will be treated as an empty list. Will be fixed in a future release.
	  *
	  * @param out_clonedFilterable [out, CATBaseUnknown#Release]
	  *   The new filterable object resulting from the Split operation.
      *   Note : the current filterable may also be modified during the execution.
	  *
	  * @param out_clonesOfAssociatedObjects [out]
	  *   The clones of the asscoiated objects passed in input.
      *   NOTE : as mentioned above, associated objects are not cloned for the moment, so this output
      *   list will stay empty. Will be fixed in a future release.
	  *
	  * @return
	  *      A HRESULT value. 
	  *     <br><b>Legal values</b>:
	  *     <dl>
	  *     <dt><tt>S_OK</tt></dt>
	  *       <dd>The method proceeded without encountering any problem.</dd>
	  *     <dt><tt>E_FAIL</tt></dt>
	  *       <dd>The method didn't execute properly until its supposed end.</dd>
	  *     </dl>
	  */
	  virtual HRESULT PerformSplit(CATICfgOperationInput const      & in_opInput,
                                   CATListPtrCATIPLMComponent const & in_associatedObjectsToClone,
                                   CATIPLMConfigFilterable *        & out_clonedFilterable,
                                   CATListPtrCATIPLMComponent       & out_clonesOfAssociatedObjects) = 0;
};

//------------------------------------------------------------------
CATDeclareHandler(CATIPLMConfigFilterableOperation, CATBaseUnknown );

#endif

