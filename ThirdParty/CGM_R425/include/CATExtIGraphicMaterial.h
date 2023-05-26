#ifndef CATExtIGraphicMaterial_H
#define CATExtIGraphicMaterial_H

//******************************************************************************
//  Abstract:
//  ---------
//     This is a default adapter for CATIGraphicMaterial
//
//******************************************************************************
//  Usage:
//  ------
//     see CATIGraphicMaterial
//******************************************************************************
//  Inheritance:
//  ------------
//     CATExtIGraphicMaterial 
//        CATBaseUnknown
//
//******************************************************************************
// COPYRIGHT DASSAULT SYSTEMES 1999

//  Main Methods:
//  -------------
//    AddGraphicMaterial()
//    RemoveGraphicMaterial()
//    GetGraphicMaterial()
//    InitMaterial()
//    
//******************************************************************************
#include "CATBaseUnknown.h"
#include "CATEventSubscriber.h"
#include "SGInfra.h"
#include "list.h"

#include  "CATString.h"

//++ E8C : Multi Materials
#include "CATMaterialApplication.h"
//-- E8C : Multi Materials

// basic strucure of the stack
struct MAT_STACK
{
	 CATMaterialApplication _MatApp;
   CATCallback						_cb;
   CATString							_sId;
	 MAT_STACK() : _MatApp(),_cb(0),_sId(CATString()) {}
};

class ExportedBySGInfra CATExtIGraphicMaterial : public CATBaseUnknown
{
  
  CATDeclareClass;
  
public:
    
  CATExtIGraphicMaterial();
  ~CATExtIGraphicMaterial();

  // Material Stack : AddGraphicMaterial
  // -----------------------------------
  // This will tempt to push a material on the top of the stack,
	// associated to an inheritance number and an identifier.
  // If the stack is locked, it will be pushed in second place.
	// If layerMode is set, it will be compared to the top material,
	// and will maybe take its place in the stack, according to new materials inheritance rules.
  virtual void AddGraphicMaterial(CATGraphicMaterial* iMat, int iInheritance, CATString iIdentifier);

  // Material Stack : RemoveGraphicMaterial
  // -----------------------------------
  // This will remove a material (associated to an identifier) from the stack, whatever is the state of the lock
  // The material is destroyed within the method if iLife = 0
  // otherwise, the user has to do it himself.
  virtual void RemoveGraphicMaterial(CATGraphicMaterial* iMat, CATString iIdentifier, int iLife = 0);
  
  // Material Stack : RemoveAll
  // --------------------------
  // This will remove all the material with the identifier specified
  // You can choose to let them live or to  let them implicitly be destoyed
  virtual void RemoveAll(CATString iIdentifier, int iLife = 0);
  
  // Stack Lock : Lock
  // -----------------
  // Use it to lock the manipulation of the stack of materials
  // Be sure to unlock it when you won't need it
  virtual void Lock();

  // Stack Lock : Unlock
  // -----------------
  // Use it to unlock the manipulation of the stack of materials
  virtual void Unlock();

  // Material Access : GetGraphicMaterial
  //-------------------------------------
  // Allow to change all the parameters of the material. Any 
  // change send a notification to the interface notification
  // which send  a notification to the visu interface
  virtual CATGraphicMaterial * GetGraphicMaterial();

  // Material Access : GetInheritanceMode
  // ------------------------------------
  // return the inheritance of the material
  // see CATRep.h for an explaination of its meaning
  virtual int GetInheritanceMode();

  // Material Access : SetInheritanceMode
  // ------------------------------------
  // Set the inheritance of the iMat material,
  // if iMat=NULL, it will change the inheritance of the top material
  virtual void SetInheritanceMode(const int mode, CATGraphicMaterial* iMat=NULL);

  // Deprecated
  virtual void SetGraphicMaterial(CATGraphicMaterial * iMat);

	// Material Stack : AddGraphicMaterialWithLayer
  // --------------------------------------------
  // This will tempt to push a material on the top of the stack.
	// associated to an inheritance number, an identifier and a layer.
  // If the stack is locked, it will be pushed in second place.
	// If layerMode is set, it will be compared to the top material,
	// and will maybe take its place in the stack, according to new materials inheritance rules.
	virtual void AddGraphicMaterialWithLayer(CATGraphicMaterial* iMat, int iInheritance, CATString iIdentifier, CATULONG32 iLayer);

  // Material Stack : RemoveGraphicMaterialWithLayer
  // -----------------------------------------------
  // This will remove a material (associated to an identifier and a layer) from the stack, whatever is the state of the lock
  // The material is destroyed within the method if iLife = 0
  // otherwise, the user has to do it himself.
	virtual void RemoveGraphicMaterialWithLayer(CATGraphicMaterial* iMat, CATString iIdentifier, CATULONG32 iLayer, int iLife = 0);

	// Layer Mode : SetLayerMode
  //--------------------------
	// This will set the layer mode.
  // '0' : no use of material layers.
	// '1' : use of material layers.
	virtual void SetLayerMode(const CATBoolean layerMode);

	// Layer Mode : GetLayerMode
  //--------------------------
  // This will return the layer mode.
	// '0' : no use of material layers.
	// '1' : use of material layers.
	virtual CATBoolean GetLayerMode();

	// Material Stack : GetStackSize
  //------------------------------
  // This will return the size of the material stack.
	virtual unsigned int GetStackSize();

  // Material Stack : GetElementsFromStack
  //--------------------------------------
  // This will retrieve info from the ith object in the material stack.
  // ith : index of the object in the stack
  // oMatApp : output CATMaterialApplication
  // oIdentifier : output CATString
  virtual void GetElementsFromStack(const unsigned int &ith, CATMaterialApplication &oMatApp, CATString &oIdentifier);

  // Material Stack : GetTopLayer
  //-----------------------------
  // This will retrieve the layer of the material
  // which is on the top of the stack.
  virtual CATULONG32 GetTopLayer();

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
	virtual void AddMaterialApplication( const CATMaterialApplication &iMatApp, CATString iIdentifier );

  // Material Stack : RemoveMaterialApplication
  // -----------------------------------------------
  // This will remove a CATMaterialApplication (associated to an identifier) from the stack, whatever is the state of the lock
	virtual void RemoveMaterialApplication( const CATMaterialApplication &iMatApp, CATString iIdentifier );

protected :

  // Material Initialization : InitMaterial
  // -------------------------------------- 
  // to use only in the Extension Constructor 
  //
  // The material of the extension is initialized,
	// with its inheritance number and identifier,
	// but the CATExtIVisu receives nothing.
  virtual void InitMaterial(CATGraphicMaterial *iMat, int iInheritance, CATString iIdentifier);

  // Material Presence in Stack : IsInStack
  // --------------------------------------
  virtual int IsInStack(CATGraphicMaterial* iMat);

	// Material Initialization : InitMaterialWithLayer
  // -----------------------------------------------
  // to use only in the Extension Constructor 
  //
  // The material of the extension is initialized,
	// with its inheritance number, its identifier and its layer.
	// but the CATExtIVisu receives nothing.
	virtual void InitMaterialWithLayer(CATGraphicMaterial *iMat, int iInheritance, CATString iIdentifier, CATULONG32 iLayer);

  // Material Initialization : InitMaterialApplication
  // -----------------------------------------------
  // to use only in the Extension Constructor 
  //
  // The material application of the extension is initialized,
	// but the CATExtIVisu receives nothing.
	virtual void InitMaterialApplication( const CATMaterialApplication &iMatApp, CATString iIdentifier );

private :

  // Notification interpretation 
  // ---------------------------
  // When a material in attached to an interface (SetGraphicMaterial),
  // we put a Callback on the material interface for each notification
  // send by the material. So the material interface could
  // send a message to the visu interface to make modification on the 
  // rendering.
  void InterpreteMaterialNotification(CATCallbackEvent,
                                      void *,
                                      CATNotification *event,
                                      CATSubscriberData,
                                      CATCallback);

  
  //Remove callbacks from all visible materials
  void _RemoveCallbacks();

  //Add callbacks to all visible materials
  void _AddCallbacks();

  list<MAT_STACK> _stack;
  int             _nLockState;
	CATBoolean			_layerMode;
}; 

#endif
