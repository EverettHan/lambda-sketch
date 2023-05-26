// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// IVAnalogGesture.h
// Header definition of IVAnalogGesture
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2020  Creation: 
//===================================================================
#ifndef IVAnalogGesture_H
#define IVAnalogGesture_H

#include "IVInterfaces.h"

// System
// -----------------------------------
#include "IVGesture.h"


enum IVAnalogGestureChannel {
  IV_ANALOG_X = 0,
  IV_ANALOG_Y,
  IV_ANALOG_XY,
};

enum IVAnalogGestureState {
  IV_ANALOG_PRESSED = 0,
  IV_ANALOG_RELEASED,
};

struct IV2DAxisData
{
  IVAtomicID deviceID; // Controller or hand
  IVAtomicID analogID;
  IVAnalogGestureState analogState;
  IVAnalogGestureChannel _channel;
  double _xValue;  //[-1,1]
  double _yValue;  //[-1,1]

  bool operator == (const IV2DAxisData& data) const {
    return analogID == data.analogID && deviceID == data.deviceID && _channel == data._channel && _xValue == data._xValue && _yValue == data._yValue;
  };

  bool operator != (const IV2DAxisData& mapping) const {
    return !(*this == mapping);
  };

};

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVAnalogGesture : public IVGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVAnalogGesture(const CATUnicodeString& iName);
  virtual ~IVAnalogGesture();

  IVAnalogGesture(IVAnalogGesture const&);
  IVAnalogGesture& operator=(IVAnalogGesture const&);

  IV2DAxisData AxisData() const;

protected:

  friend class IVAnalogGestureRecognizer;

  IV2DAxisData _axisData;
};
//-----------------------------------------------------------------------

#endif




