// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : L. Marini 
//
// DESCRIPTION  : MAX THICKNESS
// ----------------------------
//                Evaluate a rough THICKNESS estimation value of a thin wall Body.
//
//                The algorithm is designed for simple thin wall Body WITHOUT Fillet and Chamfer.
//                The returned MAX THICKNESS value is only an estimate.
//                If you need an exact value, use CATIPGMTopWallThickness3D or CATIPGMTopWallThickness.
//
//                HOW TO CHECK THE ESTIMATION
//                ---------------------------
//                double maxThickness       = CATPGMGlobalThicknessAnalyse(..,MAX_THICKNESS_TYPE);
//                double signatureThickness = CATPGMGlobalThicknessAnalyse(..,SIGNATURE_THICKNESS_TYPE);
//                if (maxThickness > 2*signatureThickness)  you'b better use the CATIPGMTopWallThickness               
//
// DESCRIPTION  : SIGNATURE THICKNESS
// ----------------------------------
//                Compute the SIGNATURE THICKNESS value of a VOLUMIC body.
//                It's an average thickness value depending on volume and area of the body.
//
// DESCRIPTION  : MAX THICKNESS LIMIT
// ----------------------------------
//                Compute the limit of max thickness.
//                It's the upper bound of max Thickness for a thin wall body.
//                
//                HOW TO USE IT for regular cases (it is not suitable for all cases)
//                ------------------------------------------------------------------
//                double maxThickness      = CATPGMGlobalThicknessAnalyse(..,MAX_THICKNESS_TYPE);
//                double maxThicknessLimit = CATPGMGlobalThicknessAnalyse(..,MAX_THICKNESS_LIMIT_TYPE);
//                double rayMargin         = 1.1; or 1.5; or 2.0; 
//                double rayThreshold      = CATMin(maxThickness*rayMargin , maxThicknessLimit);
//
//=============================================================================
// Creation LAP February 2014
//
//=============================================================================
#ifndef CATGlobalThicknessAnalyserOpe_H
#define CATGlobalThicknessAnalyserOpe_H

#include "AdvTrimOpe.h" // pour access dans la dll
#include "CATAdvancedOperator.h"
#include "CATIPGMGlobalThicknessAnalyserOpe.h" // For Thickness Type
#include "ListPOfCATFace.h"
#include "ListPOfCATLateralFaceResult.h"

class CATGlobalThicknessAnalyserImpl;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATBody;

#define CATGTAThicknessCategory                   CATGlobalThicknessAnalyserOpe::GTAThicknessCategory
#define CATGTAThicknessCategory_Unknown           CATGlobalThicknessAnalyserOpe::UNKNOWN
#define CATGTAThicknessCategory_ConstantMono      CATGlobalThicknessAnalyserOpe::CONSTANTMONO
#define CATGTAThicknessCategory_ConstantByPieces  CATGlobalThicknessAnalyserOpe::CONSTANTBYPIECES
#define CATGTAThicknessCategory_ConstantWithStep  CATGlobalThicknessAnalyserOpe::CONSTANTWITHSTEP
#define CATGTAThicknessCategory_Variable         CATGlobalThicknessAnalyserOpe::VARIABLE

class ExportedByAdvTrimOpe CATGlobalThicknessAnalyserOpe : public CATAdvancedOperator
{
  CATCGMVirtualDeclareClass(CATGlobalThicknessAnalyserOpe);

public:

  //==============================================================================
  // constructor: do not use, use CATCreateLiveSelectFaceOpe
  //==============================================================================
  CATGlobalThicknessAnalyserOpe(CATGeoFactory                   * iFactory,
                                CATTopData                      * iTopData,
                                CATGlobalThicknessAnalyserImpl  * iImp);

  //==============================================================================
  // destructor 
  //==============================================================================
  // @nocgmitf
  virtual ~CATGlobalThicknessAnalyserOpe();

  //==============================================================================
  // CATGTAThicknessCategory
  //==============================================================================
  enum GTAThicknessCategory {
    UNKNOWN = 0,
    CONSTANTMONO = 1,
    CONSTANTBYPIECES = 2,
    CONSTANTWITHSTEP = 3,
    VARIABLE = 4
  };

  //==============================================================================
  // Set Methods
  //==============================================================================
  // The default mode is : max thickness
  void SetThicknessType(CATIPGMGlobalThicknessAnalyserOpe::ThicknessType iThicknessType);

  // @nocgmitf
  // It's a CGM internal use for AutoMidsurface performance to compute the lateral faces
  void SetUserMaxThickness(double iUserMaxThickness);

  // @nocgmitf
  // Default value is FALSE
  void SetNeedListOfLateralFaceResult(const CATBoolean iBool);

  // @nocgmitf
  // Search for maxThickness inside the body.
  // Default value is FALSE
  void SetComputePairingThickness (const CATBoolean iBool);

  // @nocgmitf
  // Only for AutoMidSurface (cost performance)
  // Default value : iThicknessTolerance = 0.1 mm and iSmoothAngleTolerance = 0.04 (2.3°)
  // Need SetComputePairingThickness(TRUE)
  void SetNeedThicknessCategoryComputation(const double* iThicknessTolerance = NULL, const double* iSmoothAngleTolerance = NULL);

  //==============================================================================
  // Get Methods
  //==============================================================================

  // Return the expected  thickness value.
  double GetResultThicknessValue() const;

  // Only for CATIPGMGlobalThicknessAnalyserOpe::MAX_THICKNESS_TYPE
  double GetResultThicknessLimitValue() const;

  // @nocgmitf
  double GetMaxThicknessWithoutPairing() const; // LAP - August 2021 : Temporary code

  // @nocgmitf
  // Return the lateral face list
  void   GetResultLateralFaceList(ListPOfCATFace & oLateralFaceList) const;

  // @nocgmitf
  // Return the candidate lateral face list (NOT INDUSTRIAL CODE Y2020)
  void   GetCandidateLateralFaceList(ListPOfCATFace & oLateralFaceList) const;

  // @nocgmitf
  // Return the partially lateral face list (NOT INDUSTRIAL CODE Y2023)
  void   GetPartiallyLateralFaceList(ListPOfCATFace& oPartiallyLateralFaceList) const;

  // Return if the inputBody is a good candidate for the internal equation.
  // In practice there is a check if the part is a thin wall body.
  // For example, a sphere is not compliant.
  CATBoolean IsACompliantBody() const;

  // Return if the inputBody is a thin wall body.
  // In practice the width has to be at least twice bigger than the average thickness.
  CATBoolean IsAThinWallBody() const;

  // DO NOT USED : Deprecated since R418 : Use GetResultThicknessValue()
  double GetMaxThicknessValue() const;

  // @nocgmitf
  // Internal use for performance
  void GetVolumeAndSurfaceAreaOfInputBody( double &oVolume, double &oSurface) const;

  // @nocgmitf
  // Return the list of CATLateralFaceResult containing the border edges couples
  // IMPORTANT: User have to delete oLateralFaceResultList after
  // (NOT INDUSTRIAL CODE Y2020)
  void GetListOfLateralFaceResult(ListPOfCATLateraFaceResult & oLateralFaceResultList);

  // @nocgmitf
  double GetMinThicknessValue() const;
  
  // @nocgmitf
  CATGTAThicknessCategory GetThicknessCategory() const;

  // @nocgmitf
  // Only for SheetMetal context
  double GetLateralFaceThicknessForSheetMetal() const;

  // @nocgmitf
  void GetSquareLateralFaceList(ListPOfCATFace& oSquareLateralFaceList) const;

  //==============================================================================
  //
  // CGMREPLAY METHODES
  //
  //==============================================================================
  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMOutput &os);
  /** @nodoc @nocgmitf */
  virtual void WriteInput(CATCGMStream  & os);
  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);
  /** @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os ) ;
  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  // @nocgmitf
  void DumpOutput(CATCGMStream & Str , CATCGMOutput & os , int iVersionNumber=1);
  /** @nodoc @nocgmitf */
  CATBoolean ReadReferenceOutput(CATCGMStream &Str);
  /** @nodoc @nocgmitf */
  void WriteOutput(CATCGMStream & ioStream);
  /** @nodoc @nocgmitf */
  CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);
  // @nocgmitf
  CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
  // @nocgmitf
  CATBoolean ValidateOutput(CATCGMStream & Str, CATCGMOutput & os, int VersionNumber=1);

protected:
  CATGlobalThicknessAnalyserImpl *GetCATGlobalThicknessAnalyserImpl() const;

private :
  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATGlobalThicknessAnalyserOpe (CATGlobalThicknessAnalyserOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATGlobalThicknessAnalyserOpe& operator=(CATGlobalThicknessAnalyserOpe&);


  //==============================================================================
  // Data
  //==============================================================================

};

//==============================================================================
// CATGlobalThicknessAnalyse : MAX THICKNESS or SIGNATURE THICKNESS or MAX THICKNESS LIMIT
//==============================================================================
/**
* static methode to get the directly the ResultFaceList<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iBody</tt> : The body to analyse. It have to be a thin wall body.<br> 
*    <li> <tt>oResultThickness</tt> : This value depends on ThicknessType.<br>
*    <li> <tt>iThicknessType</tt> : The default value is MAX_THICKNESS_TYPE.<br>
*    <li> <tt>HRESULT<tt> : S_OK , S_FALSE means the body is not compliant but a value is returned, E_FAIL means there are an error during computation.<br>
*  </ul>
**/   

ExportedByAdvTrimOpe HRESULT CATGlobalThicknessAnalyse(
                             CATBody                                           * iBody,
                             CATSoftwareConfiguration                          * iConfig,
                             double                                            & oResultThickness,
                             CATIPGMGlobalThicknessAnalyserOpe::ThicknessType    iThicknessType=CATIPGMGlobalThicknessAnalyserOpe::MAX_THICKNESS_TYPE);

/**
* double call for perfo of MAX_THICKNESS_TYPE and MAX_THICKNESS_LIMIT_TYPE
*/
ExportedByAdvTrimOpe HRESULT CATGlobalThicknessAnalyse(
                             CATBody                                           * iBody,
                             CATSoftwareConfiguration                          * iConfig,
                             double                                            & oResultMaxThickness,
                             double                                            & oResultMaxThicknessLimit);

//==============================================================================
// CATCreateGlobalThicknessAnalyserOpe
//==============================================================================
/**
* Create operator, it call the constructor.<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iTopData</tt> : It represents the information about the configuration and
*                the journal. If iTopData is NULL , the operator create it.<br>
*    <li> <tt>iBody</tt> : The body to analyse. It have to be a thin wall body.<br>
*  </ul>
**/
ExportedByAdvTrimOpe CATGlobalThicknessAnalyserOpe * CATCreateGlobalThicknessAnalyserOpe(
                             CATTopData * iTopData,
                             CATBody    * iBody);

//==============================================================================
// CATGlobalThicknessAnalyse
//  Usage of oLateralFaceList
//   - Filter the pairing in AutoMidSurface
//   - Detection of PartEdge on SheetMetal Part for CloudDFM.
//  Do not use :
//   - opCandidateFaceList is a NOT INDUSTRIAL CODE
//   - opPartiallyLateralFaceList is a NOT INDUSTRIAL CODE
//==============================================================================
ExportedByAdvTrimOpe HRESULT CATGlobalThicknessAnalyse(
                             CATBody                     * iBody,
                             CATSoftwareConfiguration    * iConfig,
                             double                      & oResultThickness,
                             ListPOfCATFace              & oLateralFaceList,
                             ListPOfCATFace              * opCandidateFaceList=NULL,          // opCandidateFaceList is not in the Application Interface.
                             CATBoolean                    iComputePairingThickness = FALSE,  // iComputePairingThickness is not in the Application Interface.
                             ListPOfCATFace              * opPartiallyLateralFaceList = NULL);

//==============================================================================
// CATGlobalThicknessAnalyse  (NOT INDUSTRIAL CODE Y2020)
//==============================================================================
// @nocgmitf
ExportedByAdvTrimOpe HRESULT CATGlobalThicknessAnalyse(
  CATBody                      * iBody,
  CATSoftwareConfiguration     * iConfig,
  double                       & oResultThickness,
  ListPOfCATLateraFaceResult  & oListOfLateralFaceResult);

// -----------------------------------------------------------------------------
// =============================================================================


#endif

