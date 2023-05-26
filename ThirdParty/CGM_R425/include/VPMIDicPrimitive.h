//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicPrimitive_h
#define _VPMIDicPrimitive_h

#include "VPMIDicInterfaces.h"

#include "CATCORBABoolean.h"
#include "VPMDicTYPE.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"
#include "VPMDicPRIMITIVEType.h"

class CATDbBinary;
class CATString;

/**
 * VPMIDicPrimitive is the interface that access a DicPrimitive
 * a DicPrimitive contains a set of object description
 * related to a VPM application
 *<p>
 * ENOVIA Primitives are :
 *<p> INTEGER
 *<p> DOUBLE
 *<p> STRING
 *<p> BINARY
 *<p> DATE
 *<p> BOOLEAN
 * <br>
 */

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicPrimitive;
#else
extern "C" const IID IID_VPMIDicPrimitive;
#endif
class  ExportedByVPMIDicInterfaces VPMIDicPrimitive: public VPMIDicElement

{
    CATDeclareInterface;

    public:

        /**
        * @deprecated
        * Use the PritiveType instead.
        * Retrieves the PRIMITYPEType of the Primitive.
        * @return
        */
        virtual VPMDicPRIMITIVEType Primitive     () =0;

        /**
        * Retrieves the PRIMITYPEType of the Primitive.
        * @return
        */
        virtual VPMDicPRIMITIVEType PrimitiveType () =0;


};
#endif
