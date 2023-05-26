#ifndef CAT2DManipulatorAgent_h
#define CAT2DManipulatorAgent_h

// COPYRIGHT DASSAULT SYSTEMES 2000
#include "CATAfrSelection.h"

#include "CATManipulatorAgent.h"

#include "CATIEditMove2D.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATListPV.h"

#include "CATMathTransformation2D.h"
#include "CATMathPoint2D.h"
#include "CATMathDirection2D.h"

class CATCommand;
class CATNotification;
class CAT2DVisuHandle;

class ExportedByCATAfrSelection CAT2DManipulatorAgent : public CATManipulatorAgent
{
  CATDeclareClass;

public:
  CAT2DManipulatorAgent(CATBaseUnknown * iElement);
  virtual ~CAT2DManipulatorAgent();

  //Methods that should be called in usual CATIEdit implementation

  void Set1DAxis(CATMathPoint2D iOrigin, CATMathDirection2D iDir);
  void Set2DAxis(CATMathPoint2D iOrigin, CATMathDirection2D iDir1, CATMathDirection2D iDir2);
  
  void Set1DBounds(CATMathPoint2D iPoint1, CATMathPoint2D iPoint2);
  void Set2DBounds(CATMathPoint2D iPoint1, CATMathPoint2D iPoint2);

  void AddTranslationHandle(CAT2DVisuHandle * iVisuHandle);

  void Add1DRotationHandle(CAT2DVisuHandle * iVisuHandle[2]);
  void Add2DRotationHandle(CAT2DVisuHandle * iVisuHandle[4]);

  void Add1DScaleHandle(CAT2DVisuHandle * iVisuHandle[2]);
  void Add2DScaleHandle(CAT2DVisuHandle * iVisuHandle[4]);

  //Current position of object
  CATMathPoint2D GetOrigin();
  CATMathDirection2D GetDirection(int iIndex);

  //Actions on model
  virtual void ManipulateModel(int iManipulatorIndex);
  virtual void EndManipulateModel(int iManipulatorIndex);
  virtual void BeginManipulateModel(int iManipulatorIndex);

  //Actions on manipulators
  virtual void MoveManipulators();
  virtual void BeginMoveManipulators();
  virtual void EndMoveManipulators();
  
  //CallBacks
  virtual void TranslateBeginManipulate(CATCommand *, CATNotification *, CATCommandClientData);
  virtual void TranslateEndManipulate  (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void TranslateManipulate     (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void TranslatePreactivate    (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void TranslateEndPreactivate (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void TranslateActivate       (CATCommand *, CATNotification *, CATCommandClientData);
  // Specific callback when manipulator is on object rep
  virtual void TranslateActivateObject (CATCommand *, CATNotification *, CATCommandClientData);

  virtual void RotateBeginManipulate   (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void RotateEndManipulate     (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void RotateManipulate        (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void RotatePreactivate       (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void RotateEndPreactivate    (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void RotateActivate          (CATCommand *, CATNotification *, CATCommandClientData);
  
  virtual void ScaleBeginManipulate    (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void ScaleEndManipulate      (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void ScaleManipulate         (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void ScalePreactivate        (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void ScaleEndPreactivate     (CATCommand *, CATNotification *, CATCommandClientData);
  virtual void ScaleActivate           (CATCommand *, CATNotification *, CATCommandClientData);

  //ManipulatorList
  virtual void AddTranslationManipulator(CATCommand * iManipulator);
  virtual void RemoveTranslationManipulator(CATCommand * iManipulator);

  virtual void AddRotationManipulator(CATCommand * iManipulator);
  virtual void RemoveRotationManipulator(CATCommand * iManipulator);
  
  virtual void AddScaleManipulator(CATCommand * iManipulator);
  virtual void RemoveScaleManipulator(CATCommand * iManipulator);

  // Methods needed to manage four scale manipulators at
  // each corner of the object
  virtual CATMathPoint2D GetScaleXOrigin(int iManipulatorIndex);
  virtual CATMathPoint2D GetScaleYOrigin(int iManipulatorIndex);
  static int CompareScaleManipulator(CATBaseUnknown * iP1,CATBaseUnknown * iP2);
  virtual void SortScaleManipulator();
  
  CATLISTP(CATBaseUnknown) & GetScaleManipulatorList();  
  CATLISTP(CATBaseUnknown) & GetTranslationManipulatorList();
  CATLISTP(CATBaseUnknown) & GetRotationManipulatorList();

  CATMathTransformation2D & GetCurrentMove();
  void SetCurrentMove(CATMathTransformation2D & tra);

  void SetRotationWithPanelAvailability(CATBoolean iCanRotate);
  CATBoolean GetRotationWithPanelAvailability();

protected:
   // Empty method to trap unwanted notifications
  void DoNothingCB(CATCommand *, CATNotification *, CATCommandClientData);
 
  
private:
  //Surcharge du constructeur par copie et de l'opérateur =
  CAT2DManipulatorAgent(const CAT2DManipulatorAgent&);
  CAT2DManipulatorAgent& operator = (const CAT2DManipulatorAgent&);

  void InitializeMove();

  // Dedicated manipulator lists
  CATLISTP(CATBaseUnknown) _TranslationManipulatorList;
  CATLISTP(CATBaseUnknown) _RotationManipulatorList;
  CATLISTP(CATBaseUnknown) _ScaleManipulatorList;

  // Scale management
  CATMathPoint2D _ScaleXOrigin;
  CATMathPoint2D _ScaleYOrigin;

  // Object axis and bounding box management
  int                _ModelObjectDimension;
  CATMathPoint2D     _ModelObjectOrigin;
  CATMathDirection2D _ModelObjectDirection[2];
  CATMathPoint2D     _BoundingBoxPoint[4];

  // Move management
  CATIEditMove2D          * _EditMove2D;
  int                       _GrabbedManipulatorIndex;
  int                       _FirstMove;
  CATMathTransformation2D   _CurrentMove;

  //Initial position storage
  CATMathPoint2D _InitModelObjectOrigin;
  CATListPV      _InitPositionList;
  CATListPV      _InitRotationPointList;
  CATListPV      _InitTranslationDirectionList;

  // Unstrained move
  CATMathTransformation2D _UnstrainedMove;

  //Handle on object rep
  CAT2DVisuHandle * _HandleOnObjectRep;

  // Store mouse position at begin move
  int _MousePositionX;
  int _MousePositionY;

  CATBoolean _canRotateWithPanel;

};
#endif
