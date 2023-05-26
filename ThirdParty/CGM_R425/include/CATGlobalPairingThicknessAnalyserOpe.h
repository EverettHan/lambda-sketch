// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : P. PHALIPPOU
//
// DESCRIPTION  : 
// --------------
//
//=============================================================================
// Creation PPU7 September 2020
//
//=============================================================================
#ifndef CATGlobalPairingThicknessAnalyserOpe_H
#define CATGlobalPairingThicknessAnalyserOpe_H

#include "AdvTrimOpe.h"
#include "CATAdvancedOperator.h"
#include "CATGMOperatorsInterfaces.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATlsoGTAPair.h"
#include "CATGlobalThicknessAnalyserOpe.h"

class CATGlobalPairingThicknessAnalyserImpl;
class CATGeoFactory;
class CATBody;
class CATEdgeHashTable;
class CATFaceHashTable;

class ExportedByAdvTrimOpe CATGlobalPairingThicknessAnalyserOpe : public CATAdvancedOperator
{
  CATCGMVirtualDeclareClass (CATGlobalPairingThicknessAnalyserOpe);

public:

  //==============================================================================
  // constructor: do not use, use CATCreateLiveSelectFaceOpe
  //==============================================================================
  CATGlobalPairingThicknessAnalyserOpe (CATGeoFactory                          * iFactory,
                                        CATTopData                             * iTopData,
                                        CATGlobalPairingThicknessAnalyserImpl  * iImp);

  //==============================================================================
  // destructor 
  //==============================================================================
  // @nocgmitf
  virtual ~CATGlobalPairingThicknessAnalyserOpe ();

  //==============================================================================
  // Set Methods
  //==============================================================================
  // @nocgmitf
  void SetNeedThicknessCategoryComputation(const double iThicknessTolerance, const double iSmoothAngleTolerance);
  // @nocgmitf
  void SetGTALateralEdges(const CATEdgeHashTable & iGTALateralEdges);
  // @nocgmitf
  void SetGTALateralFaces(const CATFaceHashTable & iGTALateralFaces);

  // 
  //==============================================================================
  // Get Methods
  //==============================================================================
  // @nocgmitf
  double GetMaxThicknessValue () const;
  // @nocgmitf
  double GetMinThicknessValue() const;
  // @nocgmitf
  void   GetPairs (ListPOfCATlsoGTASimplePair & oFinalPairList) const;
  // @nocgmitf
  void   GetLateralFaces(ListPOfCATFace& oLateralFaces) const;
  // @nocgmitf
  CATGTAThicknessCategory GetPairingThicknessCategory() const;
  // @nocgmitf
  void   DetectValidatedPairingFaces(ListPOfCATFace& iFaces, ListPOfCATFace& oPairingFaces) const;
  // @nocgmitf
  CATBoolean IsValidLateralFace(CATFace*& iLateralFace, ListPOfCATEdge& iNonLateralEdges) const;

  //==============================================================================
  // CGMREPLAY METHODES
  //==============================================================================
  /** @nodoc @nocgmitf */
  //void DumpOutput (CATCGMOutput &os);
  /** @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId ();
  /** @nodoc @nocgmitf */
  virtual void WriteInput (CATCGMStream  & os);
  /** @nodoc @nocgmitf */
  virtual void ReadInput (CATCGMStream  & ioStream, int VersionOfStream, short iNumReplayVersion = 1);
  /** @nodoc @nocgmitf */
  virtual void Dump (CATCGMOutput& os);
  /** @nodoc @nocgmitf */
  virtual int RunOperator ();

protected:
  CATGlobalPairingThicknessAnalyserImpl *GetCATGlobalPairingThicknessAnalyserImpl () const;

private:

};

//==============================================================================
// CATCreateGlobalPairingThicknessAnalyserOpe
//==============================================================================
/**
* Create operator, it call the constructor.<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iTopData</tt> : It represents the information about the configuration and
*                the journal. If iTopData is NULL , the operator create it.<br>
*    <li> <tt>iBody</tt> : The body to analyse. It have to be a thin wall body.<br>
*    <li> <tt>ipFaceList</tt> : The body's faces where the method search for the maxThickness.<br>
*    <li> <tt>iAverageThickness</tt> : The Average thickness used for maximal search distance.<br>
*  </ul>
**/
ExportedByAdvTrimOpe CATGlobalPairingThicknessAnalyserOpe * CATCreateGlobalPairingThicknessAnalyserOpe (
                             CATTopData                       * iTopData,
                             CATBody                          * iBody,
                             ListPOfCATFace                   * ipFaceList,
                             double                             iAverageThickness);


#endif
