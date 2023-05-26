// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATVidCtlColorGradient.h
// Header definition of CATVidCtlColorGradient
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  ISP created.
//===================================================================
#ifndef CATVidCtlColorGradient_H
#define CATVidCtlColorGradient_H

#include <VisuDialog.h>
#include <CATVid.h>
#include <CATVidCtl.h>

class CATIVidMdl_var;
class CATVidColor;
class CATMathPoint2Df;

class ExportedByVisuDialog CATVidCtlColorGradient: public CATVidCtl
{
  CATDeclareClass;  

public:

  static CATVidCtlColorGradient * CreateColorGradient();

  CATVidCtlColorGradient ();

  virtual ~CATVidCtlColorGradient ();

  virtual void TemplateDataUpdated();

  CATIVidMdl_var GetSourceModel()const;

  void SetSourceModel(const CATIVidMdl_var & i_spSourceModel);

  void SetEditableFlag(int i_editableFlag);

  int GetEditableFlag()const;  

  CATMathPoint2Df GetElementDimension()const;
  //void SetElementDimension(const CATMathPoint2Df & i_ElementDimension);
  float GetLabelWidth()const;
  void SetLabelWidth(const float & i_labelWidth);
  float GetGradientWidth()const;
  //void SetGradientWidth(const float & i_gradientWidth);
  CATVidColor GetBackgroundColor()const;
  //void SetBackgroundColor(const CATVidColor & i_backgroundColor);

  void SetLabelCropPolicy(CATVid::CropPolicy i_labelcropPolicy);
  CATVid::CropPolicy GetLabelCropPolicy() const;


protected:
  CATVidCtlColorGradient (CreateLetterFunc i_pCreateLetterFunc);


private:

  CATVidCtlColorGradient (CATVidCtlColorGradient &);
  CATVidCtlColorGradient& operator=(CATVidCtlColorGradient&);  

};

//-----------------------------------------------------------------------

#endif
