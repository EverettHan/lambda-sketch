//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVDragGestureRecognizer_H
#define IVDragGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVSingleHandedGestureRecognizer.h"
#include "IVDeviceAtomicType.h"

class IVDragGesture;

//-----------------------------------------------------------------------
class IVDragGestureRecognizer : public IVSingleHandedGestureRecognizer
{
	CATDeclareClass;

public:

	// Constructor/Destructor
	// -----------------------------------
	IVDragGestureRecognizer();
	virtual ~IVDragGestureRecognizer();

  // Get recognized gesture
  // -----------------------------------
	/*
	 * @return type : IVDragGesture
	 */
  virtual IVGesture* GetGesture();
  
protected:

	// Single handed Gesture - to overload in single handed each gesture
	// -----------------------------------
	virtual void OnMoveOver();
	virtual void OnDragBegan();
	virtual void OnDragChanged();
	virtual void OnDragEnded();

private:

  IVDragGesture* _pDragGesture;

	// Standard, Copy constructor and equal operator
	// -----------------------------------
	IVDragGestureRecognizer(IVDragGestureRecognizer &);
	IVDragGestureRecognizer& operator=(IVDragGestureRecognizer&);
};
//-----------------------------------------------------------------------
#endif
