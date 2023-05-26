#ifndef CATHLRVISUOUTPUTMAKER_H
#define CATHLRVISUOUTPUTMAKER_H

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
#include "CATHLROutputMaker.h"
#include "CATMathPlane.h"
#include "CAT3DLineGP.h"
#include "CAT3DCustomRep.h"
#include "CAT3DFilterBagRep.h"

class CAT3DRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;




class ExportedBySGInfra CATHLRVisuOutputMaker : public CATHLROutputMaker
{
  
  public:
    
    CATHLRVisuOutputMaker            (void);
    virtual ~CATHLRVisuOutputMaker   (void);
    
    inline void SetAssociatedNotHandledRep  (CAT3DBagRep *brep);
		inline void SetAssociatedHandledRep			(CAT3DBagRep *arep);
    
    virtual void CreateOutputVectors(int iIdxInDisplayList,
				     int iCntPoints,
				     float *iPointsArray,
             const CATGraphicAttributeSet &iGAS,
						 const int iLineType = LINE_STRIP,
						 const TessFlag iLineTessStatus = LINE);

	virtual void CreateOutput2DVectors(int iIdxInDisplayList,
				     int iCntPoints,
				     float *iPointsArray,
             const CATGraphicAttributeSet &iGAS,
						 CATMathPlane plan,
						 const int iLineType = LINE_STRIP,
						 const TessFlag iLineTessStatus = LINE);

    virtual void CreateOutputNurbs(int iIdxInDisplayList, int order, float *controls, int nb_controls, float *nodes, int nb_nodes, float start, float end, float *weights, float *bezierKnots, int nb_bezierKnots, CATMathPlane plane, const CATGraphicAttributeSet &iGAS);

    virtual void AddNonHandledRep(int iIdxInDisplayList);
		virtual void AddNonHandledRep(CAT3DRep *iRep, const CAT4x4Matrix *iMatrix) ;

		virtual void StartNewResult();
		virtual void StopCurrentResult();

		virtual void ActivateFilterOnCurrentResult(CATVisFilter *iFilter = NULL);

    
  protected:
    
    CAT3DBagRep			*_AssociatedHandledRep;
		CAT3DBagRep			*_AssociatedNotHandledRep;

		CAT3DFilterBagRep	*_currentResultRep;
		CAT3DCustomRep		*_currentCustomRep;
    
  private:
	  void Add2DGP(CATGraphicPrimitive* pGP, const CATGraphicAttributeSet &iGAS,  CATMathPlane plan);
    
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline void CATHLRVisuOutputMaker::SetAssociatedNotHandledRep (CAT3DBagRep *brep)
{
  _AssociatedNotHandledRep=brep;
} 

inline void CATHLRVisuOutputMaker::SetAssociatedHandledRep (CAT3DBagRep *brep)
{
  _AssociatedHandledRep=brep;
} 

#endif
