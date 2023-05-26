// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbVOBuilder.h
// Define the CATIOmbVOBuilder interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jul 2006  Creation: Code generated by the CAA wizard  dem
//===================================================================
#ifndef CATIOmbVOBuilder_H
#define CATIOmbVOBuilder_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbVOBuilder;
#else
extern "C" const IID IID_CATIOmbVOBuilder ;
#endif

/**
 * @level Private
 * @usage U5
 */ 
//------------------------------------------------------------------

class CATIVOFactory;

/**
 * <p>
 * Interface for PLM first instances which can be part of a VO.
 * <b>Role:</b> Each instances which can be part of a VO has to implement this interface. 
 * <br>This interface retrieves the factory of a VO which is used to create and name VO.
 * @see CATIVOFactory CATIVO
 */
class ExportedByCATObjectModelerBase CATIOmbVOBuilder: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Retrieves the factory responsible of the creation of a VO corresponding to the instance.
     * @param oFactory  [out, CATBaseUnknown#Release]
     *   The retrieved factory of the VO.
		 *   <br>The caller has to release it.
     * @return
     * <dl>
     * <dt> E_FAIL if the factory has not been found
		 * <dt> S_OK else
     * </dt>
     */

    virtual HRESULT GetVOFactory(CATIVOFactory*& oFactory ) const = 0;
};

CATDeclareHandler(CATIOmbVOBuilder,CATBaseUnknown);


//------------------------------------------------------------------

#endif
