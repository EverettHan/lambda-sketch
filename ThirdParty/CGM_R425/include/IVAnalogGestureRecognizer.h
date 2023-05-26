//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVAnalogGestureRecognizer_H
#define IVAnalogGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVGestureRecognizer.h"
#include "IVDeviceAtomicType.h"

class IVAnalogGesture;

// IVAnalogGestureType
// -----------------------------------
typedef enum
{
	IVAnalogGestureUnknown
	, IVAnalogGestureFree
	, IVAnalogGestureHorizontal
	, IVAnalogGestureVertical
} IVAnalogGestureType;

//-----------------------------------------------------------------------
class IVAnalogGestureRecognizer : public IVGestureRecognizer
{
	CATDeclareClass;

public:

	// Constructor/Destructor
	// -----------------------------------
	IVAnalogGestureRecognizer();
	virtual ~IVAnalogGestureRecognizer();


  // Get recognized gesture
  // -----------------------------------
  /*
   * @return type : IVAnalogGesture
   */
  virtual IVGesture* GetGesture();
  
  // Methods For Subclasses
	// -----------------------------------
	virtual void OnAnalogEvent(CATBaseUnknown* ipSender, const IVAnalogEvtArgs* ipArgs);
  virtual void StopEventProcessing();

  // Getter/Setter
  // -----------------------------------
  inline IVAtomicID xAnalogAtomicID() const { return _xAnalogAtomicID; };
  inline void SetXAnalogAtomicID(IVAtomicID iID) { _xAnalogAtomicID = iID; };
  inline IVAtomicID yAnalogAtomicID() const { return _yAnalogAtomicID; };
  inline void SetYAnalogAtomicID(IVAtomicID iID) { _yAnalogAtomicID = iID; };

	/**
	* @param iListenedAxis
	*   0 -> both axis (x, y)
	*   1 -> x axis only
	*   2 -> y axis only
	*/
	void SetListenedAxis(const CATINT32 &iListenedAxis);
	const CATINT32& GetListenedAxis() const;

	void SetLockAxis(const CATBoolean &iLockAxis);
	const CATBoolean& GetLockAxis() const;

	// Reset
	// -----------------------------------
	void Reset();

	// Values
	// -----------------------------------
	// Données à mettre dans les notifications des State()
	const double& GetXAxisValue() const;
	const double& GetXAxisPreviousValue() const;
	const double& GetXAxisFirstValue() const;
	const double& GetYAxisValue() const;
	const double& GetYAxisPreviousValue() const;
	const double& GetYAxisFirstValue() const;

	// Gesture Type
	// -----------------------------------
	inline IVAnalogGestureType AnalogGestureType() const { return _analogGestureType; };

protected:

	// Inner Data custo
	//-----------------------------
	IVAtomicID _xAnalogAtomicID;
  IVAtomicID _yAnalogAtomicID;
  CATINT32 _listenedAxis; // 0 -> (x,y) ----- 1 -> (x) ---- 2 -> (y)
	CATBoolean _lockAxis; // Allows to lock an axis while manipulating
	CATINT32 _currentLockedAxis; // 0 -> Unknown, 1 -> X Axis, 2 -> Y Axis

	// Values
	//-----------------------------
	double _xAxisValue;
	double _xPrevAxisValue;
	double _xFirstAxisValue;
	double _yAxisValue;
	double _yPrevAxisValue;
	double _yFirstAxisValue;

	// Gesture Type
	//-----------------------------
	inline void SetAnalogGestureType(const IVAnalogGestureType & iType) {_analogGestureType = iType;};
	IVAnalogGestureType _analogGestureType;

private:
	// Il y a des incoherences dans les valeurs qu'on recoit pendant les evts.
	// Lors d'un tap, on va recevoir en X, un valeur 0.3 puis immédiatement après, une valeur 0.9
	// On va donc croire qu'il y a eu un drag alors que c'est faux...
	// On permet donc d'ignorer un nombre N d'evts avant de commencer les verifications
	CATINT32 _ignoreValue;

  IVAnalogGesture* _pAnalogGesture;

	// Standard, Copy constructor and equal operator
	// -----------------------------------
	IVAnalogGestureRecognizer(IVAnalogGestureRecognizer &);
	IVAnalogGestureRecognizer& operator=(IVAnalogGestureRecognizer&);
};
//-----------------------------------------------------------------------
#endif


