/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATTopoFrFOffset:
// Interface class of the CATTopoFrFOffset Operator.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// Mar.  99 NDN Creation                                                 NDN
// Sep.  99 OSN New Create
// Dec.  00 NDN TopData Migration
// 09/01/18 NLD Shunt du constructeur avec journal
//              Shunt des deux CreateTopoFrFOffset()
//==========================================================================
//
#ifndef CATTopoFrFOffset_H
#define CATTopoFrFOffset_H

#define CATTopoFrFOffset_ShuntOldConstructorForCoverage
#define CATTopoFrFOffset_ShuntOldCreateForCoverage

//
#include "PowerTopologicalOpe.h"
#include "CATSkillValue.h"
#include "CATTopOperator.h"
//
class CATBody;
class CATGeoFactory;
class CATNurbsSurface;
class CATTopData;
class CATCGMJournalList;
//
//-----------------------------------------------------------------------------
class ExportedByPowerTopologicalOpe CATTopoFrFOffset : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopoFrFOffset);
public :
  
  virtual ~CATTopoFrFOffset() {};
  virtual int               Run()             =0;
  //-------------------------------------------------------------
  //GET Methods
  //-------------------------------------------------------------
  //Getting the result surface
  virtual CATBody         * GetResult()       =0;
  
  //Getting the max error between real and result offset
  virtual double            GetMaxDeviation() =0;
  
  //-------------------------------------------------------------
  //SET Methods - In order to call this method, you should create
  //this operator with an ADVANCED CATSkillValue, make your Set
  //and then call the Run method.
  //-------------------------------------------------------------
  //If you want to set the max degree allowed
  virtual void              SetMaxDegree(CATLONG32 MaxDegreeU,CATLONG32 MaxDegreeV) =0;
  
  virtual void              SetOffsetValues(const double iOffsetLaw[]) =0;
  
  //To get the geometric result (previsu)
  virtual CATNurbsSurface * LightRun() =0;
  
  //To set the input tolerance
  virtual void              SetTolerance(double iTolerance) =0;
  
protected :
  
  /** @nodoc */
  CATTopoFrFOffset(CATGeoFactory* iFactory,
                   CATTopData   * iTopData)
    :CATTopOperator(iFactory,iTopData)
  {
  };

  #ifndef CATTopoFrFOffset_ShuntOldConstructorForCoverage
  /** @nodoc */
  CATTopoFrFOffset(CATGeoFactory    * factory,
                   CATCGMJournalList* journal=0)
    :CATTopOperator(factory,journal)
  {
  };
  #endif
  
};

//-----------------------------------------------------------------------------
#ifndef CATTopoFrFOffset_ShuntOldCreateForCoverage
ExportedByPowerTopologicalOpe  CATTopoFrFOffset * CreateTopoFrFOffset   (      CATGeoFactory * Factory     ,
                                                                         const CATBody       * iSurface    ,
                                                                         const double          iOffsetLaw[],
                                                                         const double          iTol        ,
                                                                               CATSkillValue   iMode       = BASIC);

ExportedByPowerTopologicalOpe  CATTopoFrFOffset * CreateTopoFrFOffset   (      CATGeoFactory * Factory     ,
                                                                         const CATBody       * iSurface    ,
                                                                         const double          iOffsetLaw[],
                                                                         const double          iTol        ,
                                                                         const CATLONG32       iKeepKnots  ,
                                                                               CATSkillValue   iMode       = BASIC);
#endif
ExportedByPowerTopologicalOpe  CATTopoFrFOffset * CATCreateTopoFrFOffset(      CATGeoFactory * Factory     ,
                                                                               CATTopData    * iTopData    ,
                                                                         const CATBody       * iSurface    ,
                                                                         const double          iOffsetLaw[],
                                                                               double          iTol        ,
                                                                               CATLONG32       iKeepKnots  ,
                                                                               CATSkillValue   iMode       = BASIC);

// @nocgmitf
ExportedByPowerTopologicalOpe void Remove(CATTopoFrFOffset *&iOffset);
#endif
