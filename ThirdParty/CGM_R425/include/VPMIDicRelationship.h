//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicRelationship_h
#define _VPMIDicRelationship_h

#include "VPMIDicInterfaces.h"

#include "CATCORBABoolean.h"
#include "VPMIDicAttribute.h"
#include "VPMDicCOLLECTION.h"
#include "VPMDicACCESSMODE.h"

class VPMIDicPackage;
class VPMIDicCollection;
class VPMIDicClass;
class VPMIDicInverse;
class CATString ;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicRelationship;
#else
extern "C" const IID IID_VPMIDicRelationship;
#endif


/** @deprecated
  * mkchecksource UNIPAT1: please remove usage of this interface.  
  */

#if defined(REMOVE_USELESS_INCLUDE)

  #pragma message ("BADREM : FRH 140316 " __FILE__ "  Usage of VPMIDicRelationship  is deprecated. You must remove it ")

#else
class  ExportedByVPMIDicInterfaces VPMIDicRelationship: public VPMIDicAttribute
{
    CATDeclareInterface;

    public:


   //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------


        /**
  	     * @deprecated
		 * mkchecksource UNIPAT1: please remove usage of this method.  
        * @nodoc
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetTarget ( const VPMIDicClass *iClass ) = 0;

        /**
  	     * @deprecated
		 * mkchecksource UNIPAT1: please remove usage of this method.  
        * @nodoc
        * @param oClass [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetTarget ( VPMIDicClass **oClass ) = 0;


        /**
  	     * @deprecated
		 * mkchecksource UNIPAT1: please remove usage of this method.  
         * Retrieves the Role property.
         * @param oRole
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetRole ( CATUnicodeString * oRole ) = 0;
};
#endif
#endif




