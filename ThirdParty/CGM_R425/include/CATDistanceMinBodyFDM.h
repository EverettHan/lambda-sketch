/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
// CATDistanceMinBodyFDM : 
// Computes minimal distance between two BodyFDM. 
//=============================================================================
// WARNING : DO NOT USE
//=============================================================================
// May. 99   Creation                                   L. Mahe
//=============================================================================
#ifndef CATDistanceMinBodyFDM_h
#define CATDistanceMinBodyFDM_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByBOOLight.h"
#include "CATMathDef.h"
#include "CATTopOperator.h"


class CATGeoFactory;
class CATTopologicalOperator;
class BodyFDM;
class CellFDM;
class CATPoint;
class CATCell;
class CATDistanceMinCellFDM;
class CATTopOpEnvironment;

//-----------------------------------------------------------------------------
class ExportedByBOOLight CATDistanceMinBodyFDM : public CATTopOperator
{
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
		  
	CATDistanceMinBodyFDM(CATGeoFactory  *iFactory,
						  CATTopData     * iData,
                          BodyFDM        *iBody1,
                          BodyFDM        *iBody2);

	// will be disapear ...	  
	/*CATDistanceMinBodyFDM(CATGeoFactory  *iFactory,
                          BodyFDM        *iBody1,
                          BodyFDM        *iBody2);
	*/
    virtual ~CATDistanceMinBodyFDM();     

    //-------------------------------------------------------------------------
    // Settings
    //-------------------------------------------------------------------------
    void   SetPointComputationMode(CATBoolean iTrueOrFalse);
    void   SetDistanceMax(double iDistance);
    void   SetMaxNumberOfTests(CATLONG32 iMaxNumberOfTests);


    //-------------------------------------------------------------------------
    // Run and Result Access
    //-------------------------------------------------------------------------
    int   Run();
    double GetDistance();
    void   GetPoints(CATPoint *&oPoint1,CATPoint *&oPoint2);
    void   GetSupports(CATCell *&oCell1,CATCell *&oCell2);
    void   ReplaceBody(BodyFDM *iBodyToReplace,BodyFDM *iNewBody);
    void SetEnvironment(CATTopOpEnvironment * iEnviron);


  protected :
    
    CATGeoFactory          *_factory;
    CATTopologicalOperator *_topo;
    double                  _distance;
    double                  _d_max;
    CATPoint               *_point_1;
    CATPoint               *_point_2;
    CATCell                *_support_1;
    CATCell                *_support_2;
    CATBoolean              _compute_pts;
    CATBoolean              _done;
    CATBoolean              _pts_asked;
    double                  _tol;
    short                  show_trace; // while debugging, set this value to 1 and ...
                                       // you will see .. heaven
    CATTopOpEnvironment     *_Environment;
    CATBoolean               _ImportedEnvironment;

    void ClearPoints();

  private:

    // Private Data
    BodyFDM   *_body_1;
    BodyFDM   *_body_2;
    CellFDM   *_prev_1;
    CellFDM   *_prev_2;
    CATDistanceMinCellFDM *_child;
    CATLONG32       _optimize;
    CATLONG32      *_list_perf_1;
    CATLONG32      *_list_perf_2;
    double    _ConvergenceTol;

    // Internal Methods
    void IdentifyClosestCells();
    void RunHighPerformance();
    virtual void InvertData();
    CATBoolean BoxesAreTooFar(CellFDM *iCell1,CellFDM *iCell2);
    CATBoolean IsAlreadyTested(CATLONG32 iRank1,CATLONG32 iRank2);
};
#endif










