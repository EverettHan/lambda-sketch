// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : L. Marini 
//
// DESCRIPTION  : Check the Fillet/Chamfer Radius on LiveBody to find the best Industry.
//
//=============================================================================
// Creation LAP January 2015
//
//=============================================================================
#ifndef CATGMLiveShapeIndustryAssistantOpe_H
#define CATGMLiveShapeIndustryAssistantOpe_H

#include "AdvTrimOpe.h" // pour access dans la dll
#include "CATAdvancedOperator.h"
#include "CATDeclarativeContext.h"
#include "CATListOfInt.h"
#include "ListPOfCATCell.h"

class CATGMLiveShapeIndustryAssistantImpl;
class CATSoftwareConfiguration;

class ExportedByAdvTrimOpe CATGMLiveShapeIndustryAssistantOpe : public CATAdvancedOperator
{
  CATCGMVirtualDeclareClass(CATGMLiveShapeIndustryAssistantOpe);

public:

  //==============================================================================
  // constructor: do not use, use CATCreateLiveSelectFaceOpe
  //==============================================================================
  CATGMLiveShapeIndustryAssistantOpe(CATGeoFactory                          * iFactory,
                                      CATTopData                            * iTopData,
                                      CATGMLiveShapeIndustryAssistantImpl   * iImp);

  //==============================================================================
  // destructor 
  //==============================================================================
  // @nocgmitf
  virtual ~CATGMLiveShapeIndustryAssistantOpe();

  //==============================================================================
  // Set Methods
  //==============================================================================
  // Set the list of Industry to check
  void SetCandidateIndustryList(CATListOfInt & iCandidateIndustryList);

  //==============================================================================
  // Get Methods
  //==============================================================================

  // Return the Recommended Industry List
  void GetRecommendedIndustryList(CATListOfInt & oRecommendedIndustryList) const;

  void GetLostFilletList (CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oLostFilletList,
                          double                        & oMinLostRadius,
                          double                        & oMaxLostRadius) const;

  void GetRecognizedFilletList (CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oRecognizedFilletList,
                          double                        & oMinRecogRadius,
                          double                        & oMaxRecogRadius) const;

  void GetLostChamferList(CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oLostChamferList,
                          double                        & oMinLostDistance,
                          double                        & oMaxLostDistance) const;

  void GetRecognizedChamferList (CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oRecognizedChamferList,
                          double                        & oMinRecogDist,
                          double                        & oMaxRecogDist) const;

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
  CATGMLiveShapeIndustryAssistantImpl *GetCATGMLiveShapeIndustryAssistantImpl() const;

private :
  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATGMLiveShapeIndustryAssistantOpe (CATGMLiveShapeIndustryAssistantOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATGMLiveShapeIndustryAssistantOpe& operator=(CATGMLiveShapeIndustryAssistantOpe&);


  //==============================================================================
  // Data
  //==============================================================================

};


//==============================================================================
// CATCreateDRepIndustryAssistantOpe
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
ExportedByAdvTrimOpe CATGMLiveShapeIndustryAssistantOpe * CATCreateDRepIndustryAssistantOpe(
                             CATTopData * iTopData,
                             CATBody    * iBody);

#endif

