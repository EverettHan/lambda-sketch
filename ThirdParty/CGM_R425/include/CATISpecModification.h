/**
 * @level Private
 * @usage U3
 */
#ifndef CATISpecModification_H
#define CATISpecModification_H

#include "CATBaseUnknown.h"

#include "CATObjectModelerItf.h"
extern ExportedByCATObjectModelerItf IID IID_CATISpecModification;

class CATISpecAttrKey;
class CATISpecObject;

/**
 * Interface to manage the SpecsModeler Modifications introspection during UndoRedo
 */
enum CATAttrModifcationStatus {Created,Modified,Deleted};

class ExportedByCATObjectModelerItf CATISpecModification : public CATBaseUnknown
{
  CATDeclareInterface;
  public:

/**
 * Returns The Object which is concenred by the modification
 * @param <tt>CATISpecObject*& oObject</tt>
 * [out]A pointer to the modified object
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> if Object is correctly returned
 * <dt> <tt>E_FAIL</tt>   <dd> if not
 * </dl>
 */
    virtual HRESULT GetObject(CATISpecObject** oObject)=0 ;

/**
 * Provide the status of the modification
 * @param <tt>int * oStatus</tt>
 * [out] 1 Object Created
 *       2 Object Modified
 *       3 Object Deleted
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> if status ios defined
 * <dt> <tt>E_FAIL</tt>   <dd> if not
 * </dl>
 */
    virtual HRESULT GetStatus(CATAttrModifcationStatus & oStatus) = 0;

/**
 * Provide a key to the modied attribut of the object concerned by the modification
 * The Object has to be Modified by the modifications.
 * @param <tt>CATISpecAttrKey*& oKey</tt>
 * [out] The key corresponding to the attribut modified
 * @param <tt>int * oIndex</tt>
 * [in]The index if the attribut is a list
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Get the Modified Key
 * <dt> <tt>E_FAIL</tt>   <dd> No keuy Modified On Object
 * </dl>
 */
    virtual HRESULT GetKey(CATISpecAttrKey** oKey,int * oIndex=0) = 0;
};

// Macro for Handlers  //
//======================
CATDeclareHandler( CATISpecModification , CATBaseUnknown );
#endif
