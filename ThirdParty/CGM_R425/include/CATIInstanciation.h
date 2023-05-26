#ifndef CATIInstanciation_h
#define CATIInstanciation_h

// COPYRIGHT DASSAULT SYSTEMES 2000

// inherited class 
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "CATIDynamicAttributes.h"

// load module
#include "CATLifSpecs.h"
#include "CATIForwardsDecl.h"
#include "CATUnicodeString.h"
class CATInstanciationContext;

class CATICkeObject_var;

// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIInstanciation;
#else
extern "C" const IID IID_CATIInstanciation;
#endif

#define CATIInstanciation_SubType

class ExportedByCATLifSpecs CATIInstanciation : public CATBaseUnknown
{
public :
	/**
	 * Creates an instance oInstanciated, of type typeName,
	 * in owner iOwner, and named iKey.
	 */
	virtual HRESULT InstanciateObject ( const CATICkeObject_var& iOwner, const CATUnicodeString& iKey, CATICkeObject_var& oInstanciated, const CATInstanciationContext *iContext, const CATUnicodeString &iSubType = "" ) = 0;
	
    virtual HRESULT AdviseInstanciated( const CATUnicodeString& iKey,const CATICkeObject_var &iValue)=0;
 
private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIInstanciation, CATBaseUnknown);

#endif
