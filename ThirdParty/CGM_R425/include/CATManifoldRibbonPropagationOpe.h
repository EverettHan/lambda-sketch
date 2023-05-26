// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//=============================================================================
// <ClassName>  : CATManifoldRibbonPropagationOpe
//
// DESCRIPTION  : From a history free body and a list of selected faces,
//                the selection is propagated (using LiveContext), to the whole
//                Ribbon which is necessary to remove according to user scenario.
//
//                Following modes are considered:
//                - Erase: EraseFace or EraseFace with User Limitings 
//
//                - Remove-Redo: To preserve Joints stability
//                               --> set LimitingUse variable
//
//                
//=============================================================================
// Creation       ST5       April 2011
//  operator created by VB7 May   2016 from CATManifoldRibbonPropagation object
//=============================================================================

#ifndef CATManifoldRibbonPropagationOpe_H
#define CATManifoldRibbonPropagationOpe_H

#include "CATLiveBody.h"
#include "ListPOfCATPersistentFaces.h"
#include "ListPOfCATDeclarativeManifold.h"
#include "ListPOfCATBoneFillet.h"
#include "ListPOfCATJointFillet.h"

#include "CATAutoBaseThreadContext.h"
#include "CATPersistentOperator.h"
#include "AdvOpeInfra.h"


class CATPersistentCellInfra;
class CATManifoldRibbonPropagationImpl;
class CATLiveBody;

/** @nocgmitf */
class ExportedByAdvOpeInfra CATManifoldRibbonPropagationOpe : public CATPersistentOperator
{
public:

  // Constructors
  CATManifoldRibbonPropagationOpe(CATGeoFactory             * iFactory,
                                  CATTopData                * iTopData,
                                  CATManifoldRibbonPropagationImpl * iImpl);
                                   

  // Destructor
  virtual ~CATManifoldRibbonPropagationOpe();

  //Set Methods
  /** @nocgmitf */
  void SetEraseMode();
  /** @nocgmitf */
  void SetDefeatureMode();
  /** @nocgmitf */
  void SetKeepAllSelectedRibbons();
  /** @nocgmitf */
  void SetLimitingsUse(CATBoolean iState=TRUE);
  /** @nocgmitf */
  void SetUserRestrictionFaces(ListPOfCATFace & iUserRestrictionFaces);  
  /** @nocgmitf */
  void SetNotMandatoryDeclarativeManifoldsToRemove(ListPOfCATDeclarativeManifold &iNotMandatoryDeclarativeManifoldsToRemove);
  void SetPropagateThroughWall();

  //Get Methods
  /** @nocgmitf */
  void GetManifoldsToRemove(ListPOfCATDeclarativeManifold & oManifoldsToRemove);
  /** @nocgmitf */
  void GetManifoldsNotToRemove(ListPOfCATDeclarativeManifold & oManifoldsNotToRemove);
  /** @nocgmitf */
  void GetHeavyManifoldsToRemove(ListPOfCATDeclarativeManifold & oHeavyManifoldsToRemove);
  /** @nocgmitf */
  void GetPropagatedFacesToRemove(ListPOfCATFace & oPropagatedFacesToRemove);
  /** @nocgmitf */
  CATBoolean GetPropagationStoppedOnJoint();

  /*Call CATManifoldRibbonPropagationImpl::PropagateDeclarativesThroughWall*/
  static void PropagateDeclThroughWall(CATSoftwareConfiguration * iConfig, CATPersistentCellInfra &iCellInfra, CATPersistentBody *iPersistentBody, int inumOperIDForFollower, ListPOfCATDeclarativeManifold &ioDeclarativeManifoldsToRemove);
  /*Call CATManifoldRibbonPropagationImpl::PropagateChamferThroughWall*/
  static void PropagationChamfersThroughWall(CATSoftwareConfiguration * iConfig, CATPersistentCellInfra &iCellInfra, CATPersistentBody *iPersistentBody, int inumOperIDForFollower, ListPOfCATDeclarativeManifold &ioDeclarativeManifoldsToRemove);
  /*Call CATManifoldRibbonPropagationImpl::PropagateFilletThroughWall*/
  static void PropagationFilletsThroughWall(CATSoftwareConfiguration * iConfig, CATPersistentCellInfra &iCellInfra, CATPersistentBody *iPersistentBody, int inumOperIDForFollower, ListPOfCATDeclarativeManifold &ioDeclarativeManifoldsToRemove);

  //------------------
  // CGMReplay methods
  //------------------
  /** @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nocgmitf ID pour CGMReplay */
  const CATString * GetOperatorId();

  /** @nocgmitf Declaration integre au CGMReplay */
  CATExtCGMReplay * IsRecordable( short & LevelOfRuntime, short &VersionOfStream );

  /** @nocgmitf pour CGMReplay */
  void ReadInput( CATCGMStream  & iStr, int iVersionOfStream );

  /** @nocgmitf Pour CGMReplay */
  void WriteInput( CATCGMStream  & Str );

  /** @nocgmitf Pour CGMReplay */
  void Dump( CATCGMOutput& os ) ;

  /** @nocgmitf ID pour CGMReplay */
  void DumpOutput( CATCGMOutput &os );

  /** @nocgmitf ID pour CGMReplay */
  void WriteOutput(CATCGMStream & Str);

  /** @nodoc ID pour CGMReplay */
  CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

  /** @nodoc ID pour CGMReplay */
  CATBoolean   ValidateTopOutput   (CATTopCheckJournal* iEquivalent, CATCGMOutput& os);

  /** @nodoc ID pour CGMReplay */
  CATBoolean   ValidateOutput      (CATCGMStream & Str, CATCGMOutput & os, int VersionNumber=1);

  /** @nodoc ID pour CGMReplay */
  CATBoolean   ReadReferenceOutput (CATCGMStream & Str);

  /** @nodoc ID pour CGMReplay */
  void         DumpOutput(CATCGMStream & Str , CATCGMOutput & os , int VersionNumber);

  /** @nocgmitf Definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nocgmitf */
  void UnStreamParameters(CATCGMStream & iStr, int iNumOpeId, CATLiveBody* iLiveBody);

protected:

  CATManifoldRibbonPropagationImpl * GetManifoldRibbonPropagationImpl();
};

// ----------------------
// CATCreateManifoldRibbonPropagationOpe
// ----------------------
ExportedByAdvOpeInfra CATManifoldRibbonPropagationOpe * CATCreateManifoldRibbonPropagationOpe(CATGeoFactory             & iFactory,
                                                                                              CATTopData                & iTopData,
                                                                                              CATPersistentBody         & iPersistentBody,
                                                                                              ListPOfCATPersistentFaces * iListOfPersistentFaces,
                                                                                              CATPersistentCellInfra    & iInfra,
                                                                                              int                         iNumOperatorId);

ExportedByAdvOpeInfra CATManifoldRibbonPropagationOpe * CATCreateManifoldRibbonPropagationOpe(CATGeoFactory                 & iFactory,
                                                                                              CATTopData                    & iTopData,
                                                                                              CATPersistentBody             & iPersistentBody,
                                                                                              ListPOfCATDeclarativeManifold * iManifoldsToPropagate,
                                                                                              CATPersistentCellInfra        & iInfra,
                                                                                              int                             iNumOperatorId);
//For CGMReplay only
ExportedByAdvOpeInfra CATManifoldRibbonPropagationOpe * CATCreateManifoldRibbonPropagationOpe(CATGeoFactory             & iFactory,
                                                                                              CATTopData                & iTopData,
                                                                                              CATBody                   & iBody,
                                                                                              ListPOfCATFace            * iListOfFaces,
                                                                                              int                         iNumOperatorId);
//For CGMReplay only
ExportedByAdvOpeInfra CATManifoldRibbonPropagationOpe * CATCreateManifoldRibbonPropagationOpe(CATGeoFactory                 & iFactory,
                                                                                              CATTopData                    & iTopData,
                                                                                              CATBody                       & iBody,
                                                                                              ListPOfCATDeclarativeManifold * iManifoldsToPropagate,
                                                                                              int                             iNumOperatorId);

#endif
