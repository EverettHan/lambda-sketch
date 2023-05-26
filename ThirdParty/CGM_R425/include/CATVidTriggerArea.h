#ifndef CATV3DTriggerArea_H
#define CATV3DTriggerArea_H

#include <VisuDialog.h>
#include <CATVidWidget.h>
#include <CATMathPointf.h>
#include <CATMathVector.h>
#include <string> 
#include <CATSYPSimpleEventListener.h>

class CAT4x4Matrix;

class ExportedByVisuDialog CATVidTriggerArea : public CATSYPSimpleEventListener{
public:
  /** Constructor*/
  CATVidTriggerArea();
  /** Destructor */
  ~CATVidTriggerArea();

  //Handle Event
  static CATSYPEvent* ChangeState();

  /*Used for collision pick mode and collision test to know if the controller is in the trigger area*/
  virtual bool CollisionTest(const CAT4x4Matrix& i_absoluteToRelativeMatrix, const CATMathPoint2Df& i_dimension, const CATMathPoint& i_eyePosition, const CATMathVector& i_offset, CATMathPointf& o_pickPosition, double& o_distance) = 0;

  /*Used for laser and wand pick modes*/
  virtual bool LineTest(const CAT4x4Matrix& i_absoluteToRelativeMatrix, const CATMathPoint2Df& i_dimension, const CATMathPoint& i_eyePosition, const CATMathVector& i_offset, const CATMathLine& i_line, bool i_isWandMode, CATMathPointf& o_pickPosition, double& o_pickDistance) = 0;

  /*Create the points needed for displaying the hit area around the GP*/
  virtual double* DrawHitAreaDebug(CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) = 0;
  /*Create the points needed for displaying the trigger area around the V3D top widget*/
  virtual double* DrawTriggerAreaDebug(CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) = 0;
  /*Create the points needed for displaying the collision sphere around the controller*/
  virtual double* DrawCollisionDebug(int& arraySize) = 0;

  /*@return the bool _isControllerInArea, true if the controller is in the area, false otherwise*/
  inline bool GetIsControllerInArea() { return _isControllerInArea; };
  /*Set _isControllerInArea, true for the controller in the area, false otherwise*/
  inline void SetIsControllerInArea(bool iIsCollided) { _isControllerInArea = iIsCollided; };

  /*@return the radius of the sphere around the controller*/
  inline float GetControllerSphereRadius() { return _controllerSphereRadius; };

  //return the state (collision with triggerArea)
  inline int GetState() { return _state; };

  //Check if there is a colllision  with trigger area 
  void OnStateChange(const CAT4x4Matrix& i_AbsoluteToRelativeMatrix, const CATMathPoint2Df& i_dimension, const CATMathPoint& i_eyePosition, const CATMathVector& i_offset);

protected:
  /*Main debug draw function, used by DrawHitAreaDebug and DrawTriggerAreaDebug
  * i_useCenteringOffset is used for centering the drawing because the origin is different between GPs and layouts
  */
  virtual double* DrawAreaDebug(bool i_useCenteringOffset, CATVidWidget* i_associatedWidget, const CATMathVector& i_offset, int& arraySize) = 0;

  CATMathPoint _eyePosition;            //The controller position, used for computing distance in line test and for debug draw
  float _controllerSphereRadius = 50.f; //Radius of the sphere around the controller, used for collision test and debug draw
  float	_wandSize = 200.f;              //Length of the line in wand mode (line test function)
  bool _isControllerInArea;             //Keep track if the controller is in the trigger area, set in V3D top widget BeginPick, used in V3D top widget BeginDraw

private:
/*State of the collision ; 0 no Collision/ 1 Collision*/
	int _state;
};
#endif
