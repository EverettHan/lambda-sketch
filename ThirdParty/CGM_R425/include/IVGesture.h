// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// IVGesture.h
// Header definition of IVGesture
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2020  Creation: 
//===================================================================
#ifndef IVGesture_H
#define IVGesture_H

#include "IVInterfaces.h"
#include "IVGestureRecognizer.h"
#include "CATUnicodeString.h"

// System
// -----------------------------------
#include "CATBaseUnknown.h"


//struct IVButtonData

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVGesture : public CATBaseUnknown
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVGesture(const CATUnicodeString& iName);
  virtual ~IVGesture();

  CATULONG32 Time() const;
  void SetTime(const CATULONG32& iTime);


  IVGestureRecognizerState State() const;
  void SetState(const IVGestureRecognizerState& iState);

  inline void SetName(const CATUnicodeString& iName) { _gestureName = iName; };
  inline CATUnicodeString Name() const { return _gestureName; };

protected:

private:

  CATUnicodeString _gestureName;
  CATULONG32 _time;		// CPU Time when the event occured
  IVGestureRecognizerState _state;
  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVGesture(IVGesture &);
  IVGesture& operator=(IVGesture&);
};
//-----------------------------------------------------------------------

#endif




