#ifndef VisTouchGesture_H
#define VisTouchGesture_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
// Class  :  	VisTouchGesture
// Date   :  	28/06/11
//-----------------------------------------------------------------------------
//  Inheritance : VisTouchGesture
//-----------------------------------------------------------------------------
// Abstract : gesture recognized from a touch event sequence
//            class for gesture data.
//-----------------------------------------------------------------------------
//  Main Methods :
//      GetGestureId() gesture type
//-----------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
#include "CATMathPoint2Df.h"
#include "CATMathVector2Df.h"
#include "CATMathDirection2Df.h"
#include "CATITouchEditor.h"
#include "CATUnicodeString.h"
#include "CATMathConstant.h"

enum VisTouchBasicGestureId {
   VisTouchGesture_None,
   VisTouchGesture_Down,
   VisTouchGesture_Move,
   VisTouchGesture_Up,
   VisTouchGesture_Tap,
   VisTouchGesture_DownHold,
   VisTouchGesture_MediumDownHold,
   VisTouchGesture_LongDownHold,
   VisTouchGesture_Flick,
   VisTouchGesture_DoubleTap,
   VisTouchGesture_Pan,
   VisTouchGesture_Pinch,
   VisTouchGesture_Rotate,
   VisTouchGesture_UnInterpreted,
   VisTouchGesture_NewDown,
   VisTouchGesture_NewUp,
   VisTouchGesture_DoubleTapUp,
   VisTouchGesture_Navigation,
   VisTouchGesture_TwoFingersHold,
   VisTouchGesture_TwoFingersManipulation,
   VisTouchGesture_ThreeFingersHold,
   VisTouchGesture_ThreeFingersManipulation,
   VisTouchGesture_Custom,
   VisTouchGesture_TwoFingersRotate,
   VisTouchGesture_TwoFingersTap,
   VisTouchGesture_HoldAndDrag
};

enum VisTouchNavigationGestureId {
   VisTouchGesture_TwoFingersNavigation,
   VisTouchGesture_Recentring,
   VisTouchGesture_Reframe,
   VisTouchGesture_ThreeFingersNavigation
};

class ExportedByCATVisFoundation VisTouchGesture : public CATBaseUnknown
{
  CATDeclareClass;
public:
  VisTouchGesture();
  VisTouchGesture(VisTouchBasicGestureId iGestureId);
  virtual ~VisTouchGesture();

  VisTouchBasicGestureId GetGestureId() const;

  const CATMathPoint2Df& GetGesturePoint() const;
  virtual int IsClosedTapDown() const;

  virtual const CATMathPoint2Df& GetTouchPoint() const;
  void SetName  (CATUnicodeString& gestureName);
  CATUnicodeString& GetName  () ;
  
  void SetIsClosedDown  ();
  //virtual CATTouchInteraction_Id GetInteractionId () const;

  void SetElapsedTime(int ielapsedTime);
  int GetElapsedTime() const;

  void SetOriginTime(int iTime);
  int GetOriginTime() const;

  //virtual const CATMathPoint2Df& GetOriginPoint() const;
 // void SetOriginPoint(CATMathPoint2Df& iPoint);


 

private:
  VisTouchBasicGestureId _gestureId;
  CATMathPoint2Df _touchPoint;
//  CATMathPoint2Df _originPoint;
  int _isClosedTapDown;
  CATUnicodeString _Name;
  int _elapsedTime;
  int _originTime;

};
  
class ExportedByCATVisFoundation VisDownTouchGesture : public VisTouchGesture
{
  CATDeclareClass;


public:

  VisDownTouchGesture(const CATMathPoint2Df& iTouchPoint);
  virtual ~VisDownTouchGesture();

  virtual const CATMathPoint2Df& GetTouchPoint() const;

 // virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisMoveTouchGesture : public VisTouchGesture
{
  CATDeclareClass;


  friend class VisTouchGestureRecognizer;

public:

  VisMoveTouchGesture(const CATMathPoint2Df& iTouchPoint, const CATMathVector2Df& iTouchVector);
  virtual ~VisMoveTouchGesture();

  /**
  * GetTouchPoint gives the point on the window currently touched 
  * X and Y are the pixels
  */
  virtual const CATMathPoint2Df& GetTouchPoint() const;

  /*-----------------------------Vectors */
  /**
  * GetTouchVector gives last motion vector. 
  * It concerns the current move from last touched point 
  * up to the current touch point
  *
  */
  const CATMathVector2Df& GetTouchVector() const;

  /**
  * GetDirectionFromOrigin gives the vector originating in the first touched point and 
  * pointing towards the current touched point
  */
  const CATMathVector2Df& GetDirectionFromOrigin() const;

  /**
  * GetDirection gives the vector originating in the last touched point (from the last move)
  * and pointing towards the current touched point
  
  const CATMathVector2Df& GetDirection() const;
  */
  /*-----------------------------Distnances */
  /**
  * GetDistanceFromOrigin gives the length of the segment connecting the first touched point
  * up to the current touched point
  */
  float GetDistanceFromOrigin() const;

  /**
  * GetTraveledDistance gives the length of the segment connecting the last touched point
  * (from the last move)
  * up to the current touched point
  */
  float GetTraveledDistance() const;

  /**
  * GetTraveledDistanceFromOrigin gives the length total of all Travelled distances from the first point touched
  */
  float GetTraveledDistanceFromOrigin() const;



private:
  CATMathPoint2Df _touchPoint;
  CATMathVector2Df _touchVector;
 
  CATMathVector2Df _DirectionFromOrigin;
  CATMathVector2Df _Direction;

  //float _DistanceFromOrigin;
 // float _DistanceTraveledFromLast;
  float _DistanceTraveledFromOrigin;

  // 
 // void SetDistanceFromOrigin(float iDist);
 // void SetTraveledDistance(CATAngle& iDir);
  void SetTraveledDistanceFromOrigin(float iDist);

 // void SetDirection(CATMathVector2Df& iDir);
  void SetDirectionFromOrigin(CATMathVector2Df& iDir);

};

class ExportedByCATVisFoundation VisUpTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisUpTouchGesture(const CATMathPoint2Df& iTouchPoint);
  virtual ~VisUpTouchGesture();

  virtual const CATMathPoint2Df& GetTouchPoint() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisTapTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisTapTouchGesture(const CATMathPoint2Df& iTouchPoint);
  virtual ~VisTapTouchGesture();

  virtual const CATMathPoint2Df& GetTouchPoint() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisDownHoldTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisDownHoldTouchGesture(const CATMathPoint2Df& iTouchPoint);
  virtual ~VisDownHoldTouchGesture();

  virtual const CATMathPoint2Df& GetTouchPoint() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisMediumDownHoldTouchGesture : public VisTouchGesture
{
	CATDeclareClass;
public:

	VisMediumDownHoldTouchGesture(const CATMathPoint2Df& iTouchPoint);
	virtual ~VisMediumDownHoldTouchGesture();

	virtual const CATMathPoint2Df& GetTouchPoint() const;

	//virtual CATTouchInteraction_Id GetInteractionId () const;

private:
	CATMathPoint2Df _touchPoint;
};
class ExportedByCATVisFoundation VisLongDownHoldTouchGesture : public VisTouchGesture
{
	CATDeclareClass;
public:

	VisLongDownHoldTouchGesture(const CATMathPoint2Df& iTouchPoint);
	virtual ~VisLongDownHoldTouchGesture();

	virtual const CATMathPoint2Df& GetTouchPoint() const;

	//virtual CATTouchInteraction_Id GetInteractionId () const;

private:
	CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisFlickTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisFlickTouchGesture(const CATMathPoint2Df& iFlickOrigin, const CATMathVector2Df& iFlickVector, int iFlickDuration);
  virtual ~VisFlickTouchGesture();

 // virtual CATTouchInteraction_Id GetInteractionId () const;

  const CATMathPoint2Df& GetFlickOrigin() const;
  const CATMathVector2Df& GetFlickVector() const;
  int GetFlickDuration() const;

private:
  CATMathPoint2Df _flickOrigin;
  CATMathVector2Df _flickVector;
  int _flickDuration;
};

class ExportedByCATVisFoundation VisDoubleTapTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisDoubleTapTouchGesture(const CATMathPoint2Df& iTouchPoint);
  virtual ~VisDoubleTapTouchGesture();

  virtual const CATMathPoint2Df& GetTouchPoint() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisPinchTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
  friend class VisTouchGestureRecognizer;

public:

  VisPinchTouchGesture(const CATMathPoint2Df& iPinchCenter, float iPinchDisplacement, const CATMathVector2Df& iFirstTouchDisplacement, const CATMathVector2Df& iSecondTouchDisplacement);
  virtual ~VisPinchTouchGesture();

  const CATMathPoint2Df& GetPinchCenter() const;
  float GetPinchDisplacement() const;
  const CATMathVector2Df& GetPinchFirstTouchDisplacement() const;
  const CATMathVector2Df& GetPinchSecondTouchDisplacement() const;

  // returns position of the first finger 
  const CATMathPoint2Df&  GetFirstTouchPosition() const;
  // returns position of the second finger
  const CATMathPoint2Df&  GetSecondTouchPosition() const;

  // returns the distnace between two fingers at the initial time
  float GetInitialDistance() const;
  // returns the distnace between two fingers : result of pinch
  float GetDistance() const;



  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  CATMathPoint2Df _pinchCenter;
  float _pinchDisplacement;
  CATMathVector2Df _pinchFirstTouchDisplacement;
  CATMathVector2Df _pinchSecondTouchDisplacement;

  CATMathPoint2Df _FirstTouch;
  CATMathPoint2Df _SecondTouch;
  void SetFirstTouch(CATMathPoint2Df& ipoint);
  void SetSecondTouch(CATMathPoint2Df& ipoint);

  void SetInitialDistance(float idist);
  void SetDistance (float idist);
  float _InitialDist;  // distance between two fingers before pinch or spread
  float _Dist;         // distance between two fingers obtained by this pinch or spread
};

class ExportedByCATVisFoundation VisPanTouchGesture : public VisTouchGesture
{
	CATDeclareClass;
	friend class VisTouchGestureRecognizer;
public:

	VisPanTouchGesture(const CATMathVector2Df& iPanDisplacement);
	virtual ~VisPanTouchGesture();

	//-----------------------
	// directions 
	//-------------------------
	/**
	* GetPanDisplacement gives last motion vector.
	* It concerns the current move from last touched point
	* up to the current touch point
	*
	*/
	const CATMathVector2Df& GetPanDisplacement() const;
	/**
	* GetDirectionFromOrigin gives the vector originating in the first touched point and
	* pointing towards the current touched point
	*/
	const CATMathVector2Df& GetDirectionFromOrigin() const;

	//-----------------------
	// distances 
	//-------------------------
	/**
	  * GetTraveledDistance gives the length of the segment connecting the last touched point
	  * (from the last move)
	  * up to the current touched point
	  */
	float GetTraveledDistance() const;

	/**
	* GetTraveledDistanceFromOrigin gives the length total of all Travelled distances from the first point touched
	*/
	float GetTraveledDistanceFromOrigin() const;

	// returns position of the first finger 
	const CATMathPoint2Df&  GetFirstTouchPosition() const;
	// returns position of the second finger
	const CATMathPoint2Df&  GetSecondTouchPosition() const;


private:
	CATMathPoint2Df _FirstTouch;
	CATMathPoint2Df _SecondTouch;
	void SetFirstTouch(CATMathPoint2Df& ipoint);
	void SetSecondTouch(CATMathPoint2Df& ipoint);

private:
	CATMathVector2Df _panDisplacement; // last direction
	CATMathVector2Df _DirectionFromOrigin; // direction from origin
	float _DistanceTraveledFromOrigin;

	void SetTraveledDistanceFromOrigin(float iDist);

	void SetDirectionFromOrigin(CATMathVector2Df& iDir);
};

class ExportedByCATVisFoundation VisRotateTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisRotateTouchGesture(const CATMathPoint2Df& iRotateCenter, const CATMathPoint2Df& iPreviousRotationPoint, const CATMathVector2Df& iRotateDisplacement);
  virtual ~VisRotateTouchGesture();

  //virtual CATTouchInteraction_Id GetInteractionId () const;

  const CATMathPoint2Df& GetRotateCenter() const;
  const CATMathPoint2Df& GetPreviousRotationPoint() const;
  const CATMathVector2Df& GetRotateDisplacement() const;

private:
  CATMathPoint2Df _rotateCenter;
  CATMathPoint2Df _previousRotationPoint;
  CATMathVector2Df _rotateDisplacement;
};

class ExportedByCATVisFoundation VisTwoFingersRotateTouchGesture : public VisTouchGesture
{
	CATDeclareClass;
public:

	VisTwoFingersRotateTouchGesture(const CATMathPoint2Df& iFirstTouch, const CATMathPoint2Df& iSecondTouch, const CATMathVector2Df& iLastDir, const CATMathVector2Df& iOriDir);
	virtual ~VisTwoFingersRotateTouchGesture();

	const CATMathPoint2Df& GetFirstTouchPosition() const;
	const CATMathPoint2Df&  GetSecondTouchPosition() const;
	const CATMathVector2Df& GetOriginDirection() const;
	const CATMathVector2Df& GetLastDirection() const;
	const CATMathVector2Df GetCurrentDirection() const;

private:
	CATMathPoint2Df _FirstTouch;
	CATMathPoint2Df _SecondTouch;
	
	CATMathVector2Df _OriginDirection;
	CATMathVector2Df _LastDirection;
};

class ExportedByCATVisFoundation VisNewDownTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisNewDownTouchGesture(const CATMathPoint2Df& iTouchPoint, int iTouchCount);
  virtual ~VisNewDownTouchGesture();

  //virtual CATTouchInteraction_Id GetInteractionId () const;

  virtual const CATMathPoint2Df& GetTouchPoint() const;
  int GetTouchCount() const;

private:
  CATMathPoint2Df _touchPoint;
  int _touchCount;
};

class ExportedByCATVisFoundation VisNewUpTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisNewUpTouchGesture(const CATMathPoint2Df& iTouchPoint, int iTouchCount);
  virtual ~VisNewUpTouchGesture();

  virtual const CATMathPoint2Df& GetTouchPoint() const;
  int GetTouchCount() const;
   //virtual CATTouchInteraction_Id GetInteractionId () const;
private:
  CATMathPoint2Df _touchPoint;
  int _touchCount;
};

class ExportedByCATVisFoundation VisDoubleTapUpTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisDoubleTapUpTouchGesture(const CATMathPoint2Df& iTouchPoint);
  virtual ~VisDoubleTapUpTouchGesture();

  //virtual CATTouchInteraction_Id GetInteractionId () const;

  virtual const CATMathPoint2Df& GetTouchPoint() const;

private:
  CATMathPoint2Df _touchPoint;
};

class ExportedByCATVisFoundation VisTouchUnInterpretedGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

  VisTouchUnInterpretedGesture();
  virtual ~VisTouchUnInterpretedGesture();

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
};

class ExportedByCATVisFoundation VisCustomTouchGesture : public VisTouchGesture
{
  CATDeclareClass;
public:

//  virtual CATTouchInteraction_Id GetInteractionId () const;

  VisCustomTouchGesture();
  virtual ~VisCustomTouchGesture();
};

class ExportedByCATVisFoundation VisTouchNavigationGesture : public VisTouchGesture
{
  CATDeclareClass;
public:
  VisTouchNavigationGesture(VisTouchNavigationGestureId iNavGestureId);
  virtual ~VisTouchNavigationGesture();
  //virtual CATTouchInteraction_Id GetInteractionId () const;

  VisTouchNavigationGestureId GetNavGestureId() const;

private:
  VisTouchNavigationGestureId _navGestureId;
};
  
class ExportedByCATVisFoundation VisTwoFingersNavigationTouchGesture : public VisTouchNavigationGesture
{
  CATDeclareClass;

public:
  VisTwoFingersNavigationTouchGesture(const CATMathPoint2Df& iPreviousPoint1, const CATMathPoint2Df& iPreviousPoint2, const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2);
  virtual ~VisTwoFingersNavigationTouchGesture();
  const CATMathPoint2Df& GetPreviousPoint1() const;
  const CATMathPoint2Df& GetPreviousPoint2() const;
  const CATMathPoint2Df& GetPoint1() const;
  const CATMathPoint2Df& GetPoint2() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  
  CATMathPoint2Df _prevPoint1;
  CATMathPoint2Df _prevPoint2;
  CATMathPoint2Df _point1;
  CATMathPoint2Df _point2;
};
//
// VisRecentringTouchGesture can be seen as HoldAndTap in creative Experience
class ExportedByCATVisFoundation VisRecentringTouchGesture : public VisTouchNavigationGesture
{
  CATDeclareClass;

  friend class VisTouchGestureRecognizer;

public:

  VisRecentringTouchGesture(const CATMathPoint2Df& iRecentringPoint);
  virtual ~VisRecentringTouchGesture();

  const CATMathPoint2Df& GetRecentringPoint() const;
  
  // returns position of the first finger 
  const CATMathPoint2Df&  GetFirstTouchPosition() const;
  // returns position of the second finger
  const CATMathPoint2Df&  GetSecondTouchPosition() const;

  int GetIntervalTime() const;

private:
  CATMathPoint2Df _FirstTouch;
  CATMathPoint2Df _SecondTouch;
  void SetFirstTouch(CATMathPoint2Df& ipoint);
  void SetSecondTouch(CATMathPoint2Df& ipoint);
  
  CATMathPoint2Df _recentringPoint;
  int _IntervalTime;

  void SetIntervalTime(int ielapsedInterval);
};

class ExportedByCATVisFoundation VisReframeTouchGesture : public VisTouchNavigationGesture
{
  CATDeclareClass;
public:

  VisReframeTouchGesture();
  virtual ~VisReframeTouchGesture();

 // virtual CATTouchInteraction_Id GetInteractionId () const;
};

class ExportedByCATVisFoundation VisTwoFingersHoldTouchGesture : public VisTouchGesture
{
  CATDeclareClass;

public:
  VisTwoFingersHoldTouchGesture(const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2);
  virtual ~VisTwoFingersHoldTouchGesture();
  const CATMathPoint2Df& GetPoint1() const;
  const CATMathPoint2Df& GetPoint2() const;

 // virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  
  CATMathPoint2Df _point1;
  CATMathPoint2Df _point2;
};

class ExportedByCATVisFoundation VisTwoFingersTapTouchGesture : public VisTouchGesture
{
	CATDeclareClass;

public:
	VisTwoFingersTapTouchGesture(const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2);
	virtual ~VisTwoFingersTapTouchGesture();
	const CATMathPoint2Df& GetFirstTouchPosition() const;
	const CATMathPoint2Df& GetSecondTouchPosition() const;

	// virtual CATTouchInteraction_Id GetInteractionId () const;

private:

	CATMathPoint2Df _point1;
	CATMathPoint2Df _point2;
};

class ExportedByCATVisFoundation VisHoldAndDragTouchGesture : public VisTouchGesture
{
	CATDeclareClass;


	friend class VisTouchGestureRecognizer;

public:

	VisHoldAndDragTouchGesture(const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2, const CATMathVector2Df& iTouchVector);
	virtual ~VisHoldAndDragTouchGesture();

	const CATMathPoint2Df& GetFirstTouchPosition() const;
	const CATMathPoint2Df& GetSecondTouchPosition() const;
	int GetDragTime() const;
	
	/*-----------------------------Vectors */
	/**
	* GetTouchVector gives last motion vector.
	* It concerns the current move from last touched point
	* up to the current touch point
	*
	*/
	const CATMathVector2Df& GetTouchVector() const;

	/**
	* GetDirectionFromOrigin gives the vector originating in the first touched point and
	* pointing towards the current touched point
	*/
	const CATMathVector2Df& GetDirectionFromOrigin() const;

	/**
	* GetDirection gives the vector originating in the last touched point (from the last move)
	* and pointing towards the current touched point

	const CATMathVector2Df& GetDirection() const;
	*/
	/*-----------------------------Distnances */
	/**
	* GetDistanceFromOrigin gives the length of the segment connecting the first touched point
	* up to the current touched point
	*/
	float GetDistanceFromOrigin() const;

	/**
	* GetTraveledDistance gives the length of the segment connecting the last touched point
	* (from the last move)
	* up to the current touched point
	*/
	float GetTraveledDistance() const;

	/**
	* GetTraveledDistanceFromOrigin gives the length total of all Travelled distances from the first point touched
	*/
	float GetTraveledDistanceFromOrigin() const;



private:
	CATMathPoint2Df _point1;
	CATMathPoint2Df _point2;
	int _dragTime;
	CATMathVector2Df _touchVector;

	CATMathVector2Df _DirectionFromOrigin;
	CATMathVector2Df _Direction;

	//float _DistanceFromOrigin;
	// float _DistanceTraveledFromLast;
	float _DistanceTraveledFromOrigin;

	// 
	// void SetDistanceFromOrigin(float iDist);
	// void SetTraveledDistance(CATAngle& iDir);
	void SetTraveledDistanceFromOrigin(float iDist);

	// void SetDirection(CATMathVector2Df& iDir);
	void SetDirectionFromOrigin(CATMathVector2Df& iDir);
	void SetDragTime(int iDragTime);

};


class ExportedByCATVisFoundation VisTwoFingersManipulationTouchGesture : public VisTouchGesture
{
  CATDeclareClass;

public:
  VisTwoFingersManipulationTouchGesture(const CATMathPoint2Df& iPreviousPoint1, const CATMathPoint2Df& iPreviousPoint2, const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2);
  virtual ~VisTwoFingersManipulationTouchGesture();
  const CATMathPoint2Df& GetPreviousPoint1() const;
  const CATMathPoint2Df& GetPreviousPoint2() const;
  const CATMathPoint2Df& GetPoint1() const;
  const CATMathPoint2Df& GetPoint2() const;

 // virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  
  CATMathPoint2Df _prevPoint1;
  CATMathPoint2Df _prevPoint2;
  CATMathPoint2Df _point1;
  CATMathPoint2Df _point2;
};

class ExportedByCATVisFoundation VisThreeFingersNavigationTouchGesture : public VisTouchNavigationGesture
{
  CATDeclareClass;

public:
  VisThreeFingersNavigationTouchGesture(const CATMathPoint2Df& iPreviousPoint1, const CATMathPoint2Df& iPreviousPoint2, const CATMathPoint2Df& iPreviousPoint3, const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2, const CATMathPoint2Df& iPoint3);
  virtual ~VisThreeFingersNavigationTouchGesture();
  const CATMathPoint2Df& GetPreviousPoint1() const;
  const CATMathPoint2Df& GetPreviousPoint2() const;
  const CATMathPoint2Df& GetPreviousPoint3() const;
  const CATMathPoint2Df& GetPoint1() const;
  const CATMathPoint2Df& GetPoint2() const;
  const CATMathPoint2Df& GetPoint3() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  
  CATMathPoint2Df _prevPoint1;
  CATMathPoint2Df _prevPoint2;
  CATMathPoint2Df _prevPoint3;
  CATMathPoint2Df _point1;
  CATMathPoint2Df _point2;
  CATMathPoint2Df _point3;
};

class ExportedByCATVisFoundation VisThreeFingersManipulationTouchGesture : public VisTouchGesture
{
  CATDeclareClass;

public:
  VisThreeFingersManipulationTouchGesture(const CATMathPoint2Df& iPreviousPoint1, const CATMathPoint2Df& iPreviousPoint2, const CATMathPoint2Df& iPreviousPoint3, const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2, const CATMathPoint2Df& iPoint3);
  virtual ~VisThreeFingersManipulationTouchGesture();
  const CATMathPoint2Df& GetPreviousPoint1() const;
  const CATMathPoint2Df& GetPreviousPoint2() const;
  const CATMathPoint2Df& GetPreviousPoint3() const;
  const CATMathPoint2Df& GetPoint1() const;
  const CATMathPoint2Df& GetPoint2() const;
  const CATMathPoint2Df& GetPoint3() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  
  CATMathPoint2Df _prevPoint1;
  CATMathPoint2Df _prevPoint2;
  CATMathPoint2Df _prevPoint3;
  CATMathPoint2Df _point1;
  CATMathPoint2Df _point2;
  CATMathPoint2Df _point3;
};

class ExportedByCATVisFoundation VisThreeFingersHoldTouchGesture : public VisTouchGesture
{
  CATDeclareClass;

public:
  VisThreeFingersHoldTouchGesture(const CATMathPoint2Df& iPoint1, const CATMathPoint2Df& iPoint2, const CATMathPoint2Df& iPoint3);
  virtual ~VisThreeFingersHoldTouchGesture();
  const CATMathPoint2Df& GetPoint1() const;
  const CATMathPoint2Df& GetPoint2() const;
  const CATMathPoint2Df& GetPoint3() const;

  //virtual CATTouchInteraction_Id GetInteractionId () const;

private:
  
  CATMathPoint2Df _point1;
  CATMathPoint2Df _point2;
  CATMathPoint2Df _point3;
};

#endif
