// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPDuration.h
// Header definition of CATSYPDuration
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPDuration_H
#define CATSYPDuration_H

#include <IntroInfra.h>
#include <CATBoolean.h>
//-----------------------------------------------------------------------

class ExportedByIntroInfra CATSYPDuration
{
public:
  // Standard constructor
  // --------------------
  CATSYPDuration (float i_valueInSeconds = 0);
  virtual ~CATSYPDuration ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPDuration (const CATSYPDuration & i_duration);
  CATSYPDuration& operator=(const CATSYPDuration& i_duration);

  CATBoolean operator==(const CATSYPDuration& i_right) const;
  CATBoolean operator!=(const CATSYPDuration& i_right) const;

  void SetValueInSec(float i_valueInSec);
  float GetValueInSec() const;

protected:

private:
  float _valueInSec;
};
//-----------------------------------------------------------------------

#endif
