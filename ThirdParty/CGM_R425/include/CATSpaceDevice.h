#ifndef CATSpaceDevice_H
#define CATSpaceDevice_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATDevice.h"
#include "CATVisFoundation.h"
#include "CATSpaceButtonEvent.h"

//++vxg - 23:04:20
#define IR_951339
//--vxg - 23:04:20

class CAT4x4Matrix;
class CATMathVectorf;

class ExportedByCATVisFoundation CATSpaceDevice : public CATDevice
{
  CATDeclareClass;

public:
  CATSpaceDevice ( CATVizViewer* viewer, CATViewerEvent* event, CATDeviceEvent* deviceEvent, CATViewerEvent* ipViewerEvent);
  ~CATSpaceDevice ();
  virtual void SetViewpointEditor( CATViewpointEditor *Editor);
  virtual void OnCurrentViewerChange();

  static void CAT4x4MatrixToQuaternion(const CAT4x4Matrix &iMatrix,
                                       double  oV[7]);
  static void CAT4x4MatrixToQuaternion(const CAT4x4Matrix &iMatrix,
                                       CATMathVectorf &T, double oV[4]);
  static int  QuaternionToRotation(double iQ[4], CATMathVectorf &axis, double &angle);

//++vxg - 23:04:20
#ifdef IR_951339
  bool IsEventInterpret(void) const
  { return (0 != m_EventInterpret); }
#endif  // IR_951339
//--vxg - 23:04:20

private:
  virtual int InterpretDeviceEvent( CATNotification *event, 
                                    CATSubscriberData data);
  int _animation;

	CATSpaceButtonEvent _spaceButtonEvent;
  
//++vxg - 23:04:20
#ifdef IR_951339
  int m_EventInterpret;
#endif  // IR_951339
//--vxg - 23:04:20
};

#endif
