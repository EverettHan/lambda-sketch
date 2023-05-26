// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATVidMinMax.h
// Header definition of CATVidMinMax
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2006  Creation: jov
//===================================================================
#ifndef CATVidMinMax_H
#define CATVidMinMax_H

#include <VisuDialog.h>
#include <CATBoolean.h>
//-----------------------------------------------------------------------

/*
 *
 * Class CATVidMinMax
 *
 */

class ExportedByVisuDialog CATVidMinMax
{
public:
  // Standard constructors
  // ---------------------
  CATVidMinMax ();
  CATVidMinMax (float i_minX, float i_minY, float i_maxX, float i_maxY);
  virtual ~CATVidMinMax ();

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidMinMax (const CATVidMinMax &i_original);
  CATVidMinMax& operator=(const CATVidMinMax& i_original);

  CATBoolean operator==(const CATVidMinMax& i_right) const;
  CATBoolean operator!=(const CATVidMinMax& i_right) const;

  void Set(float i_minX, float i_minY, float i_maxX, float i_maxY);
  void Get(float &o_minX, float &o_minY, float &o_maxX, float &o_maxY) const;

  float minX, minY, maxX, maxY;
};
//-----------------------------------------------------------------------

#endif
