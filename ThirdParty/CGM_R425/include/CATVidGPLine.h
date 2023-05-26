// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidGPLine.h
// Header definition of CATVidGPLine
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidGPLine_H
#define CATVidGPLine_H

#include <VisuDialog.h>
#include <CATVidGP.h>
#include <CATUnicodeString.h>
#include <list.h>
#include <CATVidColor.h>

class CATPixelImage;
class VidColorizeStruct;
class CATDrawRender;
class CATPickingRender;
//-----------------------------------------------------------------------


class ExportedByVisuDialog CATVidGPLine: public CATVidGP
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATVidGPLine ();
  CATVidGPLine (CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag = FALSE);

  void SetFirstPoint(const CATMathPoint2Df& i_firstPoint);
  const CATMathPoint2Df& GetFirstPoint() const;
  void SetSecondPoint(const CATMathPoint2Df& i_secondPoint);
  const CATMathPoint2Df& GetSecondPoint() const;

  // Set Color
  // ---------
  void SetColor(const CATVidColor& i_color);
  CATVidColor GetColor() const;

  // Set LineType
  // ------------
  void SetLineType(unsigned int i_lineType);
  unsigned int GetLineType() const;

  void SetLineThickness(unsigned int i_lineThickness);
  unsigned int GetLineThickness() const;

  // Set Length
  // ------------
  void SetLength(const float& i_length);
  float GetLength() const;

  // Set Length
  // ------------
  void SetOffset(const float& i_offset);
  float GetOffset() const;  
  
  // Set Outline Color
  // -----------------
  void SetOutlineColor(const CATVidColor& i_outlineOutlineColor);
  CATVidColor GetOutlineColor() const;

  // Set Outline Line type
  // ---------------------
  void SetOutlineLineType(unsigned int i_outlineLineType);
  unsigned int GetOutlineLineType() const;

protected:
  virtual ~CATVidGPLine ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGPLine (CATVidGPLine &);
  CATVidGPLine& operator=(CATVidGPLine&);
};

//-----------------------------------------------------------------------

#endif
