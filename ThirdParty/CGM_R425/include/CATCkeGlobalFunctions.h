// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */


#ifndef CATCkeGlobalFunctions_h
#define CATCkeGlobalFunctions_h

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATICkeParmFactory.h"
#include "CATIParmDictionary.h"
#include "CATICkeScalesServices.h"
#include "CATICkeFunctionFactory.h"
class CATIKweModelServices_var;
class CATIKweErrorManager_var;
class CATICkeExpressionFactory_var;
class CATIParmPublisher_var;


//-------------------------------------------------------------------
/**   
 * Returns global dictionnaries and factories.
 * <p>
 * @see CATIParmDictionary, CATICkeParmFactory, CATICkeFunctionFactory, CATIKweModelServices, CATIParmPublisher
 */
//-----------------------------------------------------------------------
class  ExportedByCATLifSpecs CATCkeGlobalFunctions
{

public :

/** 
 * Returns the volatile factory of values (that generates volatile values).
 */
static CATICkeParmFactory_var GetVolatileFactory ();

/** 
 * Returns the dictionary of types of values.
 */
static CATIParmDictionary_var GetParmDictionary ();

/** 
 * Returns the factory of knowledge functions.
 */
static CATICkeFunctionFactory_var GetFunctionFactory ();

/**
 * Initializes the magnitude and unit dictionary.<br>
 * After this initialisation, it becomes possible to access to CATIParmDictionary and volatile and function factory.<br>
 * In most scenarios, this intialization has already been performed. For example, it is performed when loading PLM data in the session.<br>
 * This method can be called several times, it doesn't matter.
 */
static void InitializeLiteralsEnvironment();

/** 
 * @nodoc
 * Not used in CAA
 * Returns the volatile expression factory (that generates volatile expressions).
 */
static CATICkeExpressionFactory_var GetVolatileExpressionFactory ();

/** 
 * Returns an interface that provides services on Knowledge Modeler.
 */
static CATIKweModelServices_var GetModelServices ();

/** 
 * Returns an interface that provides a way to catch Knowledge errors raised by methods (syntaxic or evaluation error).
 */
static CATIKweErrorManager_var GetErrorManager ();

/** 
 * Services equivalent to CATIParmPublisher::AppendElement.
 * @param iPublisher the parameter publisher on which we will append the iObject.
 * @param iObject the aggregated object.
 * @return classic HRESULT
 */
static HRESULT AppendElement  (const CATIParmPublisher_var &iPublisher,const CATBaseUnknown_var & iObject )    ;

/** 
 * Services equivalent to CATIParmPublisher::RemoveElement.
 * @param iPublisher the parameter publisher on which we will remove the iObject.
 * @param iObject the to be removed object.
 * @return classic HRESULT
 */
static HRESULT RemoveElement  (const CATIParmPublisher_var &iPublisher,const CATBaseUnknown_var & iObject )    ;


/** 
 * Services equivalent to CATIParmPublisher::GetFactory.
 * @param iPublisher the parameter publisher.
 * @return The factory.
 */
static CATICkeParmFactory_var GetFactory (const CATIParmPublisher_var &iPublisher) ;

/** 
 * Returns the interface providing some services about design range (model scale) services
 * @return the services interface handler
 */
static CATICkeScalesServices_var GetScalesServices();

};
   
#endif
