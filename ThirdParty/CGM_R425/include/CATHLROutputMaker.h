#ifndef CATHLROUTPUTMAKER_H
#define CATHLROUTPUTMAKER_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    Generates HLR output on the associated representation.
//
//******************************************************************************
//  Usage:
//  ------
//    Don't even think about it.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATHLRVisuOutputMaker
//                  CATHLROutputMaker
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************

#include "SGInfra.h"
#include "CATMathPlane.h"
#include "CAT3DLineGP.h"

class CATHLRDisplayList;
class CAT3DRep;
class CATGraphicAttributeSet;
class CAT4x4Matrix;
class CATVisFilter;

class ExportedBySGInfra CATHLROutputMaker
{
  public:
    
    CATHLROutputMaker          (void);
    virtual ~CATHLROutputMaker (void);
    
    inline void SetDisplayList(CATHLRDisplayList *iDList);
		
    
    virtual void CreateOutputVectors(int iIdxInDisplayList,
				     int iCntPoints,
				     float *iPointsArray,
             const CATGraphicAttributeSet &iGAS,
						 const int iLineType = LINE_STRIP,
						 const TessFlag iLineTessStatus = LINE) = 0;

	virtual void CreateOutput2DVectors(int iIdxInDisplayList,
				     int iCntPoints,
				     float *iPointsArray,
             const CATGraphicAttributeSet &iGAS,
						 CATMathPlane plan,
						 const int iLineType = LINE_STRIP,
						 const TessFlag iLineTessStatus = LINE)=0;

    virtual void CreateOutputNurbs(int iIdxInDisplayList, int order, float *controls, int nb_controls, float *nodes, int nb_nodes, float start, float end, float *weights, float *bezierKnots, int nb_bezierKnots, CATMathPlane, const CATGraphicAttributeSet &iGAS) = 0;

    virtual void AddNonHandledRep(int iIdxInDisplayList) = 0;
		virtual void AddNonHandledRep(CAT3DRep *iRep, const CAT4x4Matrix *iMatrix) = 0;

		virtual void StartNewResult() = 0;
		virtual void StopCurrentResult() = 0;

		virtual void ActivateFilterOnCurrentResult(CATVisFilter *iFilter = NULL) = 0;

  
  protected:
    
    CATHLRDisplayList *_DisplayList;
  
  private:
    
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline void CATHLROutputMaker::SetDisplayList (CATHLRDisplayList *iDList)
{
  _DisplayList=iDList;
}


#endif
