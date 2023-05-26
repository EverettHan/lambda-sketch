#ifndef CATICkeForwards_h
#define CATICkeForwards_h

// COPYRIGHT DASSAULT SYSTEMES 1999
 
/** 
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/*  CAA2Reviewed by FRH */

// base class
#include "CATCke.h"
#include "CATBaseUnknown.h"

// forwards
class CATICkeType_var;
class CATICkeInst_var;
class CATICkeMKSUnit_var;
class CATIEnumere_var;
class CATICkeArg_var;
class CATICkeSignature_var;
class CATIParmPublisher_var;

// typedef for interface list pointer definition

#include "CATCkeListOfInterface.h"

/** 
 * List of types.
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfType;

/** 
 * List of instances.
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfInst;

/** 
 * List of signatures.
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfSignature;

/** 
 * List of arguments.
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfArg;

#endif

