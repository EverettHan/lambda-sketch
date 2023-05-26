// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidGPRuler.h
// Header definition of CATVidGPRuler
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidGPRuler_H
#define CATVidGPRuler_H

#include <VisuDialog.h>
#include <CATVidGP.h>
#include <CATVid.h>
#include <CATVidColor.h>
class CATPickingRender;

//-----------------------------------------------------------------------
/**
 * @ingroup VIDGP
 */
class ExportedByVisuDialog CATVidGPRuler: public CATVidGP
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidGPRuler ();
  CATVidGPRuler (CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetHideTicksOnTheEdgesFlag(CATBoolean i_HideTicksOnTheEdgesFlag);
  CATBoolean GetHideTicksOnTheEdgesFlag() const;

  void SetInvertedAppearanceFlag(CATBoolean i_invertedAppearanceFlag);
  CATBoolean GetInvertedAppearanceFlag() const;

  void SetMaximumValue(int i_maximumValue);
  int GetMaximumValue() const;

  void SetMinimumValue(int i_minimumValue);
  int GetMinimumValue() const;

  void SetSide(CATVid::Side i_direction);
  CATVid::Side GetSide() const;

  void SetTickInterval (int i_tickInterval);
  int GetTickInterval() const;

  // Set Color
  // ---------
  void SetTickColor(const CATVidColor& i_tickColor);
  CATVidColor GetTickColor() const;


protected:
  virtual ~CATVidGPRuler ();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGPRuler (CATVidGPRuler &);
  CATVidGPRuler& operator=(CATVidGPRuler& original);
};
//-----------------------------------------------------------------------

#endif
