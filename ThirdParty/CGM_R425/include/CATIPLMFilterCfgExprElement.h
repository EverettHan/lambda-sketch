#ifndef CATIPLMFilterCfgExprElement_H
#define CATIPLMFilterCfgExprElement_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMFilterCfgLimitedAccess.h"

#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMFilterCfgLimitedAccess IID IID_CATIPLMFilterCfgExprElement;
#else
extern "C" const IID IID_CATIPLMFilterCfgExprElement;
#endif


/**
 * Common interface of elements that can be used in configuration query expression
 */
class ExportedByCATPLMFilterCfgLimitedAccess CATIPLMFilterCfgExprElement : public CATBaseUnknown
{
    CATDeclareInterface;

    public:

        /**
        * Specifies the concrete type of expression element
        */
        enum CfgExprElementType 
        {
            /**
            * Operator containing one or more other expression elements as operands
            */
            CFG_OPERATOR,

            /**
            * Configuration variable
            */
            CFG_VARIABLE,

            /**
            * Boolean value
            */
            CFG_BOOLEAN
        };

        /**
	    * Get concrete type value of expression element.
        * @param oType
        *    Expression element type.
  	    */
        virtual HRESULT GetType( CfgExprElementType & oType ) const = 0;	    
};

#endif
