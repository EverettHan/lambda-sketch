// COPYRIGHT Dassault Systemes 2004
//===================================================================

/** 
  * @CAA2Level L1
  * @CAA2Usage U3
  */ 

#ifndef CATIIniLayer_H
#define CATIIniLayer_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIniLayer;
#else
extern "C" const IID IID_CATIIniLayer ;
#endif

class CATUnicodeString;

//------------------------------------------------------------------

/**
 * Interface to a layer.
 * <b>Role</b>:
 * This interface gives a read access to a layer.
 * <br>This interface is implemented on all the layers. The @href CATIIniDocumentLayersDefinition interface returns pointers to CATIIniLayer
 * and you can use CATIIniLayer methods to retrieve the name or the comment of the corresponding layer.
 */
class ExportedByUIModelInterfaces CATIIniLayer: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** 
     * Retrieves the layer number.
     * @return
     *   The layer number.
     * @return
     * <br><b>Legal values</b>:<ul>
     * <li>S_OK if the read access succeeded</li>
     * <li>E_FAIL if the interface pointer is wrong</li></ul>
     */
     virtual HRESULT GetNumber (int & oLayerNumber) = 0;

    /** 
     * Retrieves the layer name.
     * @return
     *   The layer name.
     * @return
     * <br><b>Legal values</b>:<ul>
     * <li>S_OK if the read access succeeded</li>
     * <li>E_FAIL if the interface pointer is wrong</li></ul>
     */
    virtual HRESULT GetName (CATUnicodeString & oLayerName) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
