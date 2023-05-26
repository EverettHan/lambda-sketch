// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATVidMargin.h
// Header definition of CATVidMargin
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2010  Creation: tuv
//===================================================================
#ifndef CATVidMargin_H
#define CATVidMargin_H

#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATBaseUnknown.h>
#include <CATListOfCATUnicodeString.h>
#include <CATSYPFactoryResult.h>

//-----------------------------------------------------------------------
/*
 *
 * Class CATVidMargin
 *
 */

class ExportedByVisuDialog CATVidMargin
{
public:
  // Standard constructors
  // ---------------------
  CATVidMargin ();
  CATVidMargin (const int i_left, const int i_right, const int i_top, const int i_bottom);
  virtual ~CATVidMargin ();

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidMargin (const CATVidMargin &i_original);
  CATVidMargin& operator=(const CATVidMargin& i_original);

  CATBoolean operator==(const CATVidMargin& i_right) const;
  CATBoolean operator!=(const CATVidMargin& i_right) const;

  CATBoolean    Set(const int i_left, const int i_right, const int i_top, const int i_bottom);
  void          Get(int &o_left, int &o_right, int &o_top, int &o_bottom)const;

  void SetLeftMargin(int i_leftMargin);
  void SetRightMargin(int i_rightMargin);
  void SetTopMargin(int i_topMargin);
  void SetBottomMargin(int i_bottomMargin);

  int GetLeftMargin() const;
  int GetRightMargin() const;
  int GetTopMargin() const;
  int GetBottomMargin() const;

private:
  int _leftMargin   ;
  int _rightMargin  ;
  int _topMargin    ;
  int _bottomMargin ;
};
//-----------------------------------------------------------------------

extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidMarginFactory(const CATUnicodeString& i_string);

extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidMarginSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif
