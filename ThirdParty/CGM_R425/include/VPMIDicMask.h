//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicMask_h
#define _VPMIDicMask_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicElement.h"
#include "VPMDicACCESSMODE.h"

class VPMIDicClass;
class VPMIDicRelationClass;
class VPMIDicGenericClass;
class VPMIDicUsingAttributeMask;
class VPMIDicAttributeMask;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicMask;
#else
extern "C" const IID IID_VPMIDicMask;
#endif

struct  CATAnonymousUsingAttributeMaskDefinition 
{
  int order;
  int prepared_size;
  int mandatory;
  VPMDicACCESSMODE accessMode;
  CATAnonymousUsingAttributeMaskDefinition() : order(0), prepared_size(1), mandatory(0), accessMode(VPMDicREAD) {}
};

/**
* To manage the definition of an Mask object
*/

class  ExportedByVPMIDicInterfaces VPMIDicMask : public VPMIDicElement
{
  CATDeclareInterface;

public:
  /**
  * Get the Operation for which the current Mask is defined.
  * @param oOperation Operation name
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetOperation              ( CATUnicodeString * oOperation ) = 0;

  /**
  * Get the Class or RelationClass element referred by the current Mask.
  * @param oDicElement The Class or RelationClass element which is referred by the current Mask [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetTarget                 ( VPMIDicElement ** oDicElement) = 0;


  /**
  * Set the Generic Class element referred by the current Mask.
  * @param iDicClass Class element referred by the current Mask
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetTarget                 ( const VPMIDicGenericClass * iDicClass ) = 0;


  /**
  * Create a UsingAttributeMask element in the current Mask.
  * A UsingAttributeMask refers to an AttributeMask
  * @param oUsingAttributeMask the UsingAttributeMask [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateUsingAttributeMask  ( const CATUnicodeString * iName, const CATDbBinary * iUuid, VPMIDicUsingAttributeMask ** oUsingAttributeMask ) = 0;


  /**
  * Get the list of all UsingAttributeMask elements belonging to the current Mask.
  * @param ioElements the list of all UsingAttributeMask elements belonging to the current Mask
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetElements               ( CATLISTP(IUnknown) * ioElements, int iVolatileOnly = 0 ) = 0;


  /**
  * Set the Operation for which the current Mask is defined.
  * @param iOperation Operation name
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetOperation              ( const CATUnicodeString * iOperation ) = 0;





  /** 
  * Create an anomynous AttributeMask.
  * @param iTarget the target item
  * @param oAttrMask the created object
  */
  virtual HRESULT CreateAnonymousAttributeMask ( VPMIDicElement *iTarget, VPMIDicAttributeMask ** oAttrMask ) = 0;

  /**
  * Create an anomynous UsingAttributeMask
  * @param iTarget the target attribute mask
  * @param iOrder the order
  * @param oUsingAttributeMask the created object
  */
  virtual HRESULT CreateAnonymousUsingAttributeMask (  VPMIDicAttributeMask *iMask, CATAnonymousUsingAttributeMaskDefinition &iDef) = 0;

  /**
  * @nodoc
  */
  virtual void dump () = 0;

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING" __FILE__ " VPMIDicMask::GetTarget should be replaced by non obsolete method with same name")

#else

  /**
  * Get the Class element referred by the current Mask.
  * @param oDicClass Class element which is referred by the current Mask [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetTarget                 ( VPMIDicClass ** oDicClass ) = 0;
#endif
};

CATDeclareHandler(  VPMIDicMask,  VPMIDicElement  );

#endif
