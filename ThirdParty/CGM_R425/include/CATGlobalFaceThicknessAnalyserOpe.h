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
// Creation QF2 September 2016
//
//=============================================================================
#ifndef CATGlobalFaceThicknessAnalyserOpe_H
#define CATGlobalFaceThicknessAnalyserOpe_H

#include "AdvTrimOpe.h" // pour access dans la dll
#include "CATAdvancedOperator.h"
#include "ListPOfCATEdge.h"

class CATGlobalFaceThicknessAnalyserImpl;
class CATSoftwareConfiguration;
class CATFace;
class CATBody;
class CATTopData;
class CATGlobalLateralFace;

class ExportedByAdvTrimOpe CATGlobalFaceThicknessAnalyserOpe : public CATAdvancedOperator
{
  CATCGMVirtualDeclareClass(CATGlobalFaceThicknessAnalyserOpe);

public:


  //==============================================================================
  // Destructor 
  //==============================================================================
  // @nocgmitf
  virtual ~CATGlobalFaceThicknessAnalyserOpe();

  //==============================================================================
  // Set Methods
  //==============================================================================
  HRESULT AppendLateralEdges(const ListPOfCATEdge &iLateralEdges, const CATListOfDouble &iEdgesLength);
  void    SetMaxThickFilter(double iMaxFilterValue);

  //==============================================================================
  // Get Methods
  //==============================================================================
  CATBoolean  IsThinFace()       const;
  double      GetMaxWidth()      const;
  double      GetAverageWidth()  const;
  double      GetAverageLength() const;

  const ListPOfCATEdge & GetLateralEdges  () const;
  const ListPOfCATEdge & Get90DegreeEdges () const;

  void GetLocalLateralEdges (ListPOfCATEdge & oLocalLateralEdges, CATListOfDouble & oLocalEdgeLength) const;

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

  //==============================================================================
  // DEBUG - Internal Use ONLY !
  //==============================================================================
  // @nocgmitf
  void SetShowDebugAnnotation(CATBoolean iShow=TRUE);

protected:

  //==============================================================================
  // constructor: do not use, use CATCreateLiveSelectFaceOpe
  //==============================================================================
  CATGlobalFaceThicknessAnalyserOpe(CATGeoFactory                       * iFactory,
                                    CATTopData                          * iTopData,
                                    CATGlobalFaceThicknessAnalyserImpl  * iImpl);


  CATGlobalFaceThicknessAnalyserImpl * GetGlobalFaceThicknessAnalyserImpl() const;

private :

  friend ExportedByAdvTrimOpe CATGlobalFaceThicknessAnalyserOpe * CATCreateGlobalFaceThicknessAnalyserOpe(CATTopData            * iTopData,
                                                                                                          CATBody               * iBody,
                                                                                                          CATFace               * iFace,
                                                                                                          const ListPOfCATEdge  * iLateralEdges);
  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATGlobalFaceThicknessAnalyserOpe (CATGlobalFaceThicknessAnalyserOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATGlobalFaceThicknessAnalyserOpe& operator=(CATGlobalFaceThicknessAnalyserOpe&);


  //==============================================================================
  // Data
  //==============================================================================

};

//==============================================================================
// CATGlobalFaceThicknessAnalyse 1 : MAX THICKNESS
//==============================================================================
/**
* static methode to get the directly the ResultFaceList<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iBody</tt> : The body to analyse. It have to be a thin wall body.<br> 
*    <li> <tt>oMaxThickness</tt> : The result max thickness of the given iFace.<br>
*    <li> <tt>HRESULT<tt> : S_OK , S_FALSE means the body is not compliant but a value is returned, E_FAIL means there are an error during computation.<br>
*  </ul>
**/   

ExportedByAdvTrimOpe HRESULT CATGlobalFaceThicknessAnalyser(CATBody                     * iBody,
                                                           CATFace                      * iFace,
                                                           CATSoftwareConfiguration     * iConfig,                                                          
                                                           double                       & oMaxWidth,
                                                           ListPOfCATEdge               * o90DegreeEdges=NULL,
                                                           const ListPOfCATEdge         * iLateralEdges=NULL);


//==============================================================================
// CATGlobalFaceThicknessAnalyse 2 : MAX THICKNESS
//==============================================================================
/**
* static methode to get the directly the ResultFaceList<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iBody</tt> : The body to analyse. It have to be a thin wall body.<br> 
*    <li> <tt>oMaxThickness</tt> : The result max thickness of the given iFace.<br>
*    <li> <tt>HRESULT<tt> : S_OK , S_FALSE means the body is not compliant but a value is returned, E_FAIL means there are an error during computation.<br>
*  </ul>
**/  
ExportedByAdvTrimOpe HRESULT CATGlobalFaceThicknessAnalyser(CATBody                     * iBody, 
                                                            const CATGlobalLateralFace  * iGlobalFace, 
                                                            CATSoftwareConfiguration    * iConfig, 
                                                            double                      & oMaxWidth,
                                                            double                      & oAverageWidth,
                                                            ListPOfCATEdge              * o90DegreeEdges=NULL,
                                                            double                      * iMaxThickFilter=NULL);


//==============================================================================
// CATCreateGlobalFaceThicknessAnalyserOpe
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
ExportedByAdvTrimOpe CATGlobalFaceThicknessAnalyserOpe * CATCreateGlobalFaceThicknessAnalyserOpe( CATTopData * iTopData,
                                                                                                  CATBody    * iBody,
                                                                                                  CATFace    * iFace,
                                                                                                  const ListPOfCATEdge * iLateralEdges=NULL);


//==============================================================================
// CATCreateGlobalFaceThicknessAnalyserOpe 
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



#endif

