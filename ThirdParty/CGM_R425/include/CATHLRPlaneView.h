#ifndef CATHLRPLANEVIEW_H
#define CATHLRPLANEVIEW_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRPlaneView : Principal interface object that handle the HLR
//
// DESCRIPTION : this object is the center of the HLR, that handles
// the computation.
// The class OutputMaker manages the creation of the output, which depends on
// the application that uses the HLR. It is called in the method ComputeHLR()
// with the result of the HLR.
// 
// Main Methods :
//     - constructor
//     - SetDisplayList()
//     - SetViewpoint()
//     - ComputeHLR()
// 
//=============================================================================
// Abstract Class     : Yes
// Template Code      : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Jan. 97      Creation              Jose CHILLAN (jch)
//
//=============================================================================

#include "SGInfra.h"

#include "CATMathPointf.h"

class CAT3DViewpoint;
class CATHLRDisplayList;
class CATHLROutputMaker;
class CAT4x4Matrix;

class ExportedBySGInfra CATHLRPlaneView
{
public:
  enum CATHLRTypeView {Cylindrical, Conical}; 

// Default constructor
  CATHLRPlaneView();

// Destructor
  virtual ~CATHLRPlaneView();

// Other methods
// the display list is included and deleted by the CATHLRPlaneView
  void SetDisplayList(CATHLRDisplayList *iDispList);

// The view point is just a link to get the first transformation
  virtual void SetViewPoint(CAT3DViewpoint *iViewPoint);

// The view point is just a link to get the first transformation
  void SetSceneToleranceScale(float iTol) {if (iTol>0.f) _sceneToleranceScale = iTol;};

// the CATHLROutputMaker is deleted by the CATHLRPlaneView
  void SetOutputMaker(CATHLROutputMaker *iMaker);

// Computation of the HLR : the output will be created by
// the method that will exist in the derived class of the HLR
// This method verifiies the input and call the method Computation
  virtual void ComputeHLR();
  
  inline void SetViewMode(const int i_viewMode);
  inline void ForcePolyhedralHLRMode();//1 to force polyhedral mode

protected:
// Computation of the HLR. The output is made with the function
// pointer by _OutputMaker, which should have been set before
  virtual void Computation()=0;

// Internal datas
  CATHLRDisplayList *_DisplayList;
  CAT4x4Matrix      *_FirstMatrix;
  CATHLROutputMaker *_OutputMaker;
// Eyes position
  CATMathPointf      _Observer;
// Projection plane ( orthogonal to the vector defined by Observer and
// target and containing target )
  CATMathPointf      _Target;
// The type of view is 0 for cylindrical, 1 for conical
  CATHLRTypeView     _TypeOfView;
  int                _ViewMode;
  int				 _forcePolyhedralMode;
  float				 _sceneToleranceScale;
};

inline void CATHLRPlaneView::SetViewMode (const int i_viewMode)
{
  _ViewMode = i_viewMode;
}

inline void CATHLRPlaneView::ForcePolyhedralHLRMode() {_forcePolyhedralMode=1;};

#endif



