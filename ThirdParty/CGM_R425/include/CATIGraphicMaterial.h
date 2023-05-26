/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATIGraphicMaterial
//    CATBaseUnknown
//
//==============================================================================
// Abstract
// --------
// This interface allows that the visualization process 
// takes account of a material properties of a Modeler object 
//
//==============================================================================
// Usage
// -----
// If you want to put a graphic material on a feature, you can call the method
// AddGraphicMaterial(), this will add your material on the stack of materials.
// You can also remove it from the stack with RemoveGraphicMaterial().
//
// If you absolutly need your material to be displayed, you can lock the stack.
// In this case, any material added after will be put in second place
//==============================================================================
// History
// -------
//     - ---- --, ---: Created.
//     - 2001 02, TPA: Add the possibility to store many materials on one feature
//=============================================================================

#ifndef CATIGraphicMaterial_H
#define CATIGraphicMaterial_H

class CATGraphicMaterial;
class CATString;
class CATMaterialApplication;

#include "CATBaseUnknown.h"

#include "CATVisItf.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIGraphicMaterial;
#else
extern "C" const IID IID_CATIGraphicMaterial;
#endif

enum MAT_LIFE {DIE = 0, LIVE = 1};

class ExportedByCATVisItf CATIGraphicMaterial : public CATBaseUnknown
{
public:
// macros
CATDeclareInterface;

	// Material Stack : AddGraphicMaterial
  // -----------------------------------
  // This will tempt to push a material on the top of the stack,
	// associated to an inheritance number and an identifier.
	// The identifier string is used to have a 'local control',
  // for example, you can use the same identifier for all your
  // application, this prevent you from destroying a material
  // from an other application.
  // If the stack is locked, it will be pushed in second place.
	// If layerMode is set, it will be compared to the top material,
	// and will maybe take its place in the stack, according to new materials inheritance rules.
  virtual void AddGraphicMaterial(CATGraphicMaterial* iMat, int iInheritance, CATString iIdentifier) = 0;

  // Material Stack : RemoveGraphicMaterial
  // -----------------------------------
  // This will remove a material (associated to an identifier) from the stack, whatever is the state of the lock
  // The material is destroyed within the method if iLife = DIE
  // otherwise, the user has to do it himself.
  virtual void RemoveGraphicMaterial(CATGraphicMaterial* iMat, CATString iIdentifier, MAT_LIFE iLife = DIE) = 0;

  // Material Stack : RemoveAll
  // --------------------------
  // This will remove all the material with the identifier specified
  // You can choose to let them live or to  let them implicitly be destoyed
  virtual void RemoveAll(CATString iIdentifier, MAT_LIFE iLife = DIE) = 0;

  // Material Access : GetGraphicMaterial
  // ------------------------------------
  // return a pointer on the material which is on the top of the stack
  // you can modify the returned material, the Visualization process
  // changes soons the rendering.
  // You must not delete this material 
  virtual CATGraphicMaterial* GetGraphicMaterial() = 0;

  // Material Access : GetInheritanceMode
  // ------------------------------------
  // return the inheritance of the material
  // see CATRep.h for an explaination of its meaning
  virtual int  GetInheritanceMode() = 0;

  // Material Access : SetInheritanceMode
  // ------------------------------------
  // Set the inheritance of the iMat material,
  // if iMat=NULL, it will change the inheritance of the top material
  virtual void SetInheritanceMode(const int mode, CATGraphicMaterial* iMat=NULL) = 0;

  // Stack Lock : Lock
  // -----------------
  // Use it to lock the manipulation of the stack of materials
  // Be sure to unlock it when you won't need it
  virtual void Lock() = 0;

  // Stack Lock : Unlock
  // -------------------
  // Use it to unlock the manipulation of the stack of materials
  virtual void Unlock() = 0;

  ///////////////////////////////////////////////////////////////
  // DEPRECATED : Will disappear very SOON
  ///////////////////////////////////////////////////////////////
  virtual void SetGraphicMaterial(CATGraphicMaterial* iMat)  = 0;

	// Material Stack : AddGraphicMaterialWithLayer
  // --------------------------------------------
  // This will tempt to push a material on the top of the stack.
	// associated to an inheritance number, an identifier and a layer.
	// The identifier string is used to have a 'local control',
  // for example, you can use the same identifier for all your
  // application, this prevent you from destroying a material
  // from an other application.
	// The inheritance number and the layer concern new material inheritance rules.
  // If the stack is locked, it will be pushed in second place.
	// If layerMode is set, it will be compared to the top material,
	// and will maybe take its place in the stack, according to new materials inheritance rules.
	virtual void AddGraphicMaterialWithLayer(CATGraphicMaterial* iMat, int iInheritance, CATString iIdentifier, CATULONG32 iLayer) = 0;

  // Material Stack : RemoveGraphicMaterialWithLayer
  // -----------------------------------------------
  // This will remove a material (associated to an identifier and a layer) from the stack, whatever is the state of the lock
  // The material is destroyed within the method if iLife = 0
  // otherwise, the user has to do it himself.
	virtual void RemoveGraphicMaterialWithLayer(CATGraphicMaterial* iMat, CATString iIdentifier, CATULONG32 iLayer, int iLife = 0) = 0;

	// Layer Mode : GetLayerMode
  //--------------------------
  // This will return the layer mode.
	// '0' : no use of material layers.
	// '1' : use of material layers.
	virtual CATBoolean GetLayerMode() = 0;

	// Material Stack : GetStackSize
  //------------------------------
  // This will return the size of the material stack.
	virtual unsigned int GetStackSize() = 0;

  // Material Stack : GetElementsFromStack
  //--------------------------------------
  // This will retrieve info from the ith object in the material stack.
  // ith : index of the object in the stack
  // oMatApp : output CATMaterialApplication
  // oIdentifier : output CATString
  virtual void GetElementsFromStack(const unsigned int &ith, CATMaterialApplication &oMatApp, CATString &oIdentifier) = 0;

  // Material Stack : GetTopLayer
  //-----------------------------
  // This will retrieve the layer of the material
  // which is on the top of the stack.
  virtual CATULONG32 GetTopLayer() = 0;

  // Material Stack : AddMaterialApplication
  // --------------------------------------------
  // This will tempt to push a CATMaterialApplication and its material on the top of the stack.
	// The identifier string is used to have a 'local control',
  // for example, you can use the same identifier for all your
  // application, this prevent you from destroying a material
  // from an other application.
  // If the stack is locked, it will be pushed in second place.
	// If layerMode is set, it will be compared to the top material application,
	// and will maybe take its place in the stack, according to new materials inheritance rules.
	virtual void AddMaterialApplication( const CATMaterialApplication &iMatApp, CATString iIdentifier ) = 0;

  // Material Stack : RemoveMaterialApplication
  // -----------------------------------------------
  // This will remove a CATMaterialApplication (associated to an identifier) from the stack, whatever is the state of the lock.
	virtual void RemoveMaterialApplication( const CATMaterialApplication &iMatApp, CATString iIdentifier ) = 0;
};

CATDeclareHandler(CATIGraphicMaterial,CATBaseUnknown);

#endif // CATIGraphicMaterial
