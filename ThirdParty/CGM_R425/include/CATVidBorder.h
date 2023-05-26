// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATVidBorder.h
// Header definition of CATVidBorder
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2010  Creation: tuv
//===================================================================
#ifndef CATVidBorder_H
#define CATVidBorder_H

#include <VisuDialog.h>
#include <CATSYPFactoryResult.h>
#include <UIVCoreToolsInline.h>
/**
 * Class CATVidBorder used to define margin, padding, etc...
 */
class ExportedByVisuDialog CATVidBorder
{
public:
  /** Constructor*/
  CATVidBorder ();
  /** Constructor*/
  CATVidBorder (float i_top, float i_right, float i_bottom, float i_left);
  /** Constructor*/
  CATVidBorder(float i_top, float i_rightAndLeft, float i_bottom);
  /** Constructor*/
  CATVidBorder(float i_topAndBottom, float i_rightAndLeft);
  /** Constructor*/
  CATVidBorder(float i_all);
  /** Destructor*/
  ~CATVidBorder ();
  /** Copy constructor*/
  CATVidBorder (const CATVidBorder &i_original);
  /** operator=*/
  CATVidBorder& operator=(const CATVidBorder& i_original);
  /** operator==*/
  CATBoolean operator==(const CATVidBorder& i_right) const;
  /** operator !==*/
  CATBoolean operator!=(const CATVidBorder& i_right) const;

  INLINE float GetTop() const {return _top;}
  INLINE float GetBottom() const {return _bottom;}
  INLINE float GetRight() const {return _right;}
  INLINE float GetLeft() const {return _left;}

  INLINE void SetTop(float i_value)  {_top = i_value;}
  INLINE void SetBottom(float i_value)  {_bottom = i_value;}
  INLINE void SetRight(float i_value)  {_right = i_value;}
  INLINE void SetLeft(float i_value)  {_left = i_value;}

private:
  float _top    ;
  float _right  ;
  float _bottom ;
  float _left   ;
};
//-----------------------------------------------------------------------

extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidBorderFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidBorderSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif
