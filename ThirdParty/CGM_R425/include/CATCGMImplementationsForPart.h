/* -*-c++-*- */
#ifndef CATCGMImplementationsForPart_H_
#define CATCGMImplementationsForPart_H_
// COPYRIGHT DASSAULT SYSTEMES  2000
//=============================================================================
// Dynamic invokation of CGMV5Interoperability framework
// Dec.  01 Modification interface CATGeoTemporary pour :                 HCN
//               - iOriginalFeature passe en CATBaseUnknown
// Jun. 02 Creation d'un container pour la geometrie temporaire           HCN
// Apr. 03 _GetDualLoadingJustOccuredCode()                               HCN
// May  03 _GetDocumentName(...)                                          HCN
// Jun. 03 GetCATBackCGMVersionDef(...)                                   HCN
// Jul. 04 _GetDocumentLastStreamVersion (...)                            MNA
//=============================================================================
#include "CATCGMExtensionsForPart.h"
#include "CGMV5Interop.h"

class CATGeoFactory;
class CATIContainer;
class CATDocument;
class CATRootSharedDataCGM;

class ExportedByCGMV5Interop CATCGMImplementationsForPart : public CATCGMExtensionsForPart
{
public:
  CATCGMImplementationsForPart();
  ~CATCGMImplementationsForPart();
  
  static int CATCGMImplementationsForPartAtExit();

  static CATGeoFactory * GetGeoTemporaryFactory();
  static void            CleanGeoTemporaryFactory();

  static CATIContainer * GetGeoTemporaryContainer();
  static void            CleanGeoTemporaryContainer();
 

protected :
  //---------------------------------------------------------------------------------
  // Pour implementation CATGeoTemporary
  //---------------------------------------------------------------------------------
  HRESULT _Create(CATSoftwareConfiguration * iConfig,
                  CATBaseUnknown* iOriginalFeature,
                  CATGeometry* iOriginalGeom,
                  const CATMathTransformation &iTransfo,
                  CATGeoTemporary *& ioResult,
                  CATBoolean iForCoverage = FALSE);


 //---------------------------------------------------------------------------------
  // Pour gestion interne (Debug)
  //---------------------------------------------------------------------------------
  CATULONG32  _GetSessionIdNumber(CATGeoFactory *iFactory);


  //---------------------------------------------------------------------------------
  // CATCGMStreamDifferentialSave
  //---------------------------------------------------------------------------------
  virtual CATCGMStreamDifferentialSave * _CreateDifferentialSave(CATGeoFactory* iFactory, CATStreamArea *iStreamArea) ;
  
  //---------------------------------------------------------------------------------
  // CATCGMStreamIncrementalOpen and utilities
  //---------------------------------------------------------------------------------
  virtual CATCGMStreamIncrementalOpen * _CreateIncrementalOpen(const char iFilename[])  ;
  virtual CATCGMStreamIncrementalOpen * _CreateIncrementalOpen(CATGeoFactory *iReadFactory)  ;
  
  CATCGMStreamIncrementalOpen * _CreateIncrementalOpenStandard(CATGeoFactory *iFactory, 
                                                               CATStreamArea *iPartStreamArea);
  CATCGMStreamIncrementalOpen * _CreateIncrementalOpenODT(CATGeoFactory *iFactory, 
                                                          const CATDocument *iDocResult = NULL,
                                                          const CATRootSharedDataCGM *iDefinition = NULL);
   
  //---------------------------------------------------------------------------
  // DualLoadingJustOccured (INTERNAL USE)
  //     Synchronisation GenericNaming apres chargement du Dual
  //---------------------------------------------------------------------------
  virtual void _DualLoadingJustOccured(CATGeoFactory* iFactory);

  //---------------------------------------------------------------------------
  // FullLoadingJustOccured (INTERNAL USE)
  //     Synchronisation GenericNaming apres chargement du Dual
  //---------------------------------------------------------------------------
  virtual void _FullLoadingJustOccured(CATGeoFactory* iFactory);

 //---------------------------------------------------------------------------
  // GetMainstreamChangeSetStamp   GetFederators
  //---------------------------------------------------------------------------
 
    /** 
   * GetMainstreamChangeSetStamp : Access current session change set stamps.
   *    helpfull only for quick comparison but mandatory as prerequiste of other services.
   *
   *    @param iOnCGMGEOM
	 *        Geometrical contents.
   *
   *    @param oStamp
	 *        current session change stamp 
   *
   * @return
   *     Failed if prerequisite internal management is not available 
   *        associated minimal original data format is 2012Spring  .
   *        applied and specified dedicated management is implemented 
   *               with minor increment each times 
   *               with major increment each times dedicated times.
   *
  */ 
  virtual HRESULT _GetMainStreamChangeSetStamp( CATExtCGMGeom    * iOnCGMGEOM ,
                                                     CATULONG64       & oStamp ) const  ;
 

  /** 
   * GetFederators :  Access current change set values (roots of persistency), so necessary relative.
   *
   *    @param iOnCGMGEOM
	 *        Geometrical contents.
   *
   *    @param oSet
	 *        current change set.
   *    @param iPurpose
   *       Default purpose for default selection of main roots of persistency
   *         Keep original default value of CATOGMCORE_OBJECTIVE_PERSISTENCY 
   *    @param iComparisonSet
   *        As Change Set is necessary relative to a previous state,
   *
   * @return
   *     Failed if previous method (GetMainstreamChangeSetStamp) is not feasible  unavailable
    *     for instance, minimal original data format is 2012Spring  .
  */ 
  virtual HRESULT _GetFederators( CATExtCGMGeom              *   iOnCGMGEOM ,
                                  CATOGMCoreSet              * & oSet, 
                                  const CATOGMCoreObjective  &   iPurpose,
                                  CATOGMCoreSet              *   iPreviousState = NULL ) const  ;
 

  //---------------------------------------------------------------------------
  // ForceFullLoading (For Mechanichal Modeler)
  //     Synchronisation GenericNaming apres chargement du Dual
  //---------------------------------------------------------------------------
  virtual void _ForceFullLoading(CATGeoFactory* iFactory, CATBoolean & ioComplementaryLoadingOccured );

 

  //---------------------------------------------------------------------------
  // GetDocumentName (INTERNAL USE)
  //     Recuperation du nom de fichier CATPart associe a une factory
  //---------------------------------------------------------------------------
  virtual void _GetDocumentName(CATGeoFactory* iFactory, CATUnicodeString& oFileName);


  //---------------------------------------------------------------------------
  // GetDocumentLastStreamVersion (INTERNAL USE)
  // Recuperation de la Version Part du document
  //---------------------------------------------------------------------------
  virtual void _GetDocumentLastStreamVersion (CATGeoFactory* iFactory,CATUnicodeString& oVersion);
 
  //---------------------------------------------------------------------------
  // GetCATBackCGMVersionDef (INTERNAL USE)
  //     Recuperation de la version de sauvegarde lors d'une transaction CATBack
  //---------------------------------------------------------------------------
  virtual const CATCGMVersionDefinition* _GetCATBackCGMVersionDef(CATCGMStreamVersion& ioRequiredTargetStreamVersion);

 //---------------------------------------------------------------------------
  // ParseDocumentNotification (INTERNAL USE)
  //---------------------------------------------------------------------------
  virtual CATBaseUnknown * _ParseDocumentNotification(CATNotification* iNotification) ;

  //---------------------------------------------------------------------------------
  // Pour implementation CATGeoTemporary
  //---------------------------------------------------------------------------------
  static CATGeoFactory *_TheCATGeoTemporaryFactory;
  static CATIContainer *_TheCATGeoTemporaryContainer;

};

#endif
