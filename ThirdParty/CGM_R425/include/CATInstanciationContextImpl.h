#ifndef CATInstanciationContextImpl_h
#define CATInstanciationContextImpl_h

/**
 * @level Protected
 * @usage U1
 */


// COPYRIGHT DASSAULT SYSTEMES 2002

// include module definition
#include "CATLifDictionary.h"
#include "CATUnicodeString.h"
//#include "CATICkeObject.h"

// base class
#include "CATInstanciationContext.h"
class CATICkeObject_var;

/**   
 * Class dedicated to instanciation management.
 * <b>Role</b>: When instanciating an object through CATIInstanciation, this class is used to pass some arguments.<br>
 */
class ExportedByCATLifDictionary CATInstanciationContextImpl :public CATInstanciationContext
{

public:

	/**
     * @nodoc
	 */
	CATInstanciationContextImpl (const CATUnicodeString &iStringInfo, const CATICkeObject_var &iProxy);
  /** @nodoc */
	CATInstanciationContextImpl (const CATUnicodeString &iStringInfo = "");

	/**
     * @nodoc
	 */
	virtual ~CATInstanciationContextImpl ();

	/**
     * @nodoc
	 */
    CATInstanciationContextImpl (const CATInstanciationContextImpl &);

	/**
     * @nodoc. Returns a string information.
	 */
	virtual CATUnicodeString StringInfo () const ;
	

private:
	CATUnicodeString _StringInfo;
};

#endif


