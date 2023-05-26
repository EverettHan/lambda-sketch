//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVMultiDirectionalGestureRecognizer_H
#define IVMultiDirectionalGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVSingleHandedGestureRecognizer.h"
#include "IVDeviceAtomicType.h"

// Mathematics
// -----------------------------------
#include "CATLISTV_CATMathVector.h"

class IVSpatialMultiDirectionalGesture;

//-----------------------------------------------------------------------
class IVMultiDirectionalGestureRecognizer : public IVSingleHandedGestureRecognizer
{
	CATDeclareClass;

public:

	//Constructor/Destructor
	// -----------------------------------
	IVMultiDirectionalGestureRecognizer();
	virtual ~IVMultiDirectionalGestureRecognizer();

  // Get recognized gesture
  // -----------------------------------
	/*
	 * @return type : IVSpatialMultiDirectionalGesture
	 */
  virtual IVGesture* GetGesture();

  void SetAsDragBegan();

	// Manage list of directions
	// -----------------------------------
	void AddDirection(CATMathVector & iVector);
	void AddDirections(CATLISTV(CATMathVector) & iVectors);
	void RemovePosition(int iIndex);
	void RemoveDirection(CATMathVector &iVector);
	void RemoveAll();

	// Detection options
	// -----------------------------------
	inline CATMathVector Plane() const { return _plane; };
	inline void SetPlane(const CATMathVector & iPlane) { _plane = iPlane; };

	inline double DetectionRadius() const { return _radius; };
	inline void SetDetectionRadius(const double iRadius) { _radius = iRadius; };

	inline double DetectionThreshold() const { return _threshold; };
	inline void SetDetectionThreshold(const double iThreshold) { _threshold = iThreshold; };

	inline double DetectionSpeed() const { return _speed; };
	inline void SetDetectionSpeed(const double iSpeed) { _speed = iSpeed; };

	inline double ProjectionMax() const { return _projection; };
	inline void SetProjectionMax(const double iProjection) { _projection = iProjection; };

	// Gesture control
	inline CATMathVector Direction() { return _bestDirection; };

	// Debug
	// -----------------------------------
	virtual CATBoolean Debug() { return FALSE; };

protected:

	// Single handed Gesture - to overload in single handed each gesture
	// -----------------------------------
  virtual void OnMoveOver();
  virtual void OnDragBegan();
  virtual void OnDragChanged();
  virtual void OnDragEnded();

	// ALGO
	// -----------------------------------
	void DetectDirection();

private:

	CATLISTV(CATMathVector) _directionList;
	CATMathVector _bestDirection;
	CATMathVector _plane;
	double _radius;
	double _threshold;
	double _speed;
	double _projection;

  IVSpatialMultiDirectionalGesture* _pMultiDirectionalGesture;

	// Standard, Copy constructor and equal operator
	// -----------------------------------
	IVMultiDirectionalGestureRecognizer(IVMultiDirectionalGestureRecognizer &);
	IVMultiDirectionalGestureRecognizer& operator=(IVMultiDirectionalGestureRecognizer&);
};
//-----------------------------------------------------------------------
#endif
