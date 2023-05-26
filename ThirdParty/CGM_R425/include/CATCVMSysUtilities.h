/* -*-C++-*- */

#ifndef CATCVMSysUtilities_H
#define CATCVMSysUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 2005

//===================================================================
//===================================================================
//
// CATCVMUtilties
//
// Internal utilities for Collaborative Variational
// Modelling (CVM)
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMSysObjects.h"
#include "ListPOfCATCVMRelation.h"
#include "ListPOfCATCVMSystem.h"
//#include "CATCVMOccurrence.h"
#include "CATCVMDef.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "ListPOfCATCVMInstancePath.h"
#include "ListPOfCATCVMContainer.h"

class CATCVMPort;
class CATCVMSystem;
class CATCVMComponent;
class CATCVMContainer;
class CATCVMObject;
class CATCVMAtom;
class CATCVMInstancePath;
class CATCVMReference;
class CATMathTransformation;
class CATCGMHashTable;
class CATCVMPSContainer;

class ExportedByCATCVMSysObjects CATCVMSysUtilities
{
  //------------------------------------------------------------------------------
  // Propagate a port from a subsystem up to a higher owner component
  //------------------------------------------------------------------------------
  public:
  static CATCVMPort *PropagatePort(CATCVMPort      *iSubSystemPort,
                                   CATCVMSystem    *iSubSystem,
                                   CATCVMComponent *iComponent);

  //------------------------------------------------------------------------------
  // FindObjectFromTag
  //------------------------------------------------------------------------------
  public:
  static CATCVMObject *FindObjectFromTag(CATULONG32       iTag,
                                         CATCVMSystem    *iSystem    = NULL,
                                         CATCVMContainer *iContainer = NULL);


  //------------------------------------------------------------------------------
  // Generate, if necessary, the port to export the atom from its system
  //------------------------------------------------------------------------------
  static CATCVMPort *CreatePortIfNecessary(CATCVMAtom *iAtom);

  //------------------------------------------------------------------------------
  // Get all CVM systems (recursive) in a container
  //------------------------------------------------------------------------------
  static void GetAllCVMSystems(CATCVMContainer      *iCVMContainer,
                               ListPOfCATCVMSystem  &oCVMSystemList,
                               CATCVMSystem         *iRootSystem);

  //------------------------------------------------------------------------------
  // Get all CVM systems under a system
  //------------------------------------------------------------------------------
  static void GetAllCVMSystems(CATCVMSystem        *iCVMSystem,
                               ListPOfCATCVMSystem &ioCVMSystemList,
                               CATCVMObjectType     iCVMType,
                               CATCGMHashTable     *iWorkingHashTable=NULL);

  //------------------------------------------------------------------------------
  // Get a CVMReference with a given name
  //------------------------------------------------------------------------------
  static CATCVMReference * GetCVMReferenceFromName(CATCVMPSContainer *iCVMPSContainer,
                                                   CATUnicodeString &iRefName, 
                                                   CATBoolean HasBeenImportedInSessionOnly=FALSE); 

  //------------------------------------------------------------------------------
  // Get all CVM data containers under a reference
  //------------------------------------------------------------------------------
  static void GetAllDataContainers(CATCVMReference        *iReference,
                                   ListPOfCATCVMContainer &oDataContainerList);

  //------------------------------------------------------------------------------
  // Create the empty root component inside the reuse component if necessary
  //------------------------------------------------------------------------------
  static CATCVMReference *GetRootReference(CATCVMComponent *iReuseComponent,
                                           CATBoolean       iCreateIfNecessary = FALSE);

  //------------------------------------------------------------------------------
  // Get the unfolded component
  //------------------------------------------------------------------------------
  //static HRESULT GetUnfoldedComponent(CATCVMOccurrence * iOccurrence, CATCVMComponent *& ioUnfoldedComponent);

  //------------------------------------------------------------------------------
  // Get the list of occurrences corresponding to a given instance path
  //------------------------------------------------------------------------------
  //static HRESULT GetOccurrence(CATCVMInstancePath  *iInstancePath,
  //                             CATCVMOccurrence   *&oOccurrence);

  //------------------------------------------------------------------------------
  // Get the list of all georep corresponding to a given reference
  // REQUESTED : ioGeoRepList must be empty in upper call !!!!
  // (optinal = utility for GeoDrag) and apply a transformation to each instance found
  //------------------------------------------------------------------------------
  public:
  static HRESULT FindAllCVMGeoRep(CATCVMReference * iReference, ListPOfCATCVMSystem * ioGeoRepList, 
                                  CATMathTransformation * iTransformation = NULL);

  //------------------------------------------------------------------------------
  // Get the list of all CVMGeoRep/InstancePath from a given instance path
  //------------------------------------------------------------------------------
  static HRESULT FindAllCVMGeoRepInstancePath(CATCVMInstancePath * iInstancePath, ListPOfCATCVMSystem & ioCVMGeoRepList, ListPOfCATCVMInstancePath & ioInstancePathList, CATBoolean iCVMBodyOnly = FALSE);

  //------------------------------------------------------------------------------
  // Create a new instance path cloned from the input one 
  //------------------------------------------------------------------------------
  static CATCVMInstancePath * CloneInstancePath(CATCVMInstancePath * iInstancePath);

  //------------------------------------------------------------------------------
  // Test if 2 instance paths are equals 
  //------------------------------------------------------------------------------
  static CATBoolean IsEqual(CATCVMInstancePath * iInstancePath1, CATCVMInstancePath * iInstancePath2);

  public:
  static CATCVMComponent * FindNearestCommonAncestor(CATCVMSystem * iSystem1, CATCVMSystem * iSystem2);
  static CATCVMPort * GetMultiLevelPort(CATCVMPort * iPort, CATCVMComponent * iCVMComponent);

  private:
  CATCVMSysUtilities();

   //------------------------------------------------------------------------------
  // Other debug activations
  //------------------------------------------------------------------------------
  
  public:
  static int  Get_CVM_Perfo_Level();
  static int  Get_CVM_CheckUp_Level();
#if defined CVM_PurgeUndo_EB_Version1 
  static void Put_CVM_CheckUp_Level(int iLevel);
#endif
  static CATBoolean Is_CGM_Boolean_Activated ();
  static CATBoolean Is_CVM_Debug_Activated ();
  static CATBoolean Is_CVM_CATDevelopmentStage_Activated ();
  static CATBoolean Is_CVM_Debug_CellNavigator_Activated ();
  static CATBoolean Is_CVM_Debug_Extract_Activated ();
  static CATBoolean Is_CVM_GeomMesh_Convert_Activated();
  static CATBoolean Is_CVM_Save_After_Operator_Activated();
  static CATBoolean Is_CVM_StreamDump_Activated ();
  static CATBoolean Is_CGM_FullModel_Activated ();
  static CATBoolean Is_StreamMigration_Activated();
  static CATBoolean Is_CollisionInhibitor_Activated();
  static CATBoolean Is_CVM_FlexibleBRep_Activated(int *oVal = NULL);
  static CATBoolean Is_3DSk_PartialImportExport_Activated();
  static CATBoolean Is_ForceCVMVersion_Activated(char *ForcedCVMVersion);
  static CATBoolean Is_CVM_LoopCyl_Activated();
  static CATBoolean Is_CVM_Timer_Activated(int iLevel=0);
  static CATBoolean Is_CVM_Body_Connexity_Activated();
  static CATBoolean Is_CVM_CCP_XY_Target_Plane_Activated();
  static CATBoolean Is_CGM_Extrusion_Activated();
  static CATBoolean Is_CVM_CGMBodyKeeper_Activated ();
  static CATBoolean Is_CVM_CurrentGeoStreamVersion_Activated();
  
  //0: Checkup not active
  //1: Checkup active, failure can be retrieved in CATCVMGeoOperator
  //2: Checkup active, failure provoque crash
  static int        CVM_OLK_Detection();
  
  //0: Checkup not active
  //1: Checkup active, failure can be retrieved in CATCVMGeoOperator
  //2: Checkup active, failure provoque crash
  static int GetCheckupLevel();
  static void  Reset_CVM_Timer( const char *  texttoprint=NULL, int iLevel=0 );
  static void  Print_CVM_Timer( const char *  texttoprint=NULL, int iLevel=0, int iFailed=0, int *oCPU=NULL );
  //2: Checkup active, failure provoque crash sinon throw
  static CATBoolean IsExit66Activated(); 
    
  //for NXGSave3DXMLCmd (jma le 15 01 07)
  static CATBoolean Is_CVM_StreamAsNCGM_Activated();
  static CATBoolean Is_CVM_StreamAsCATPart_Activated();
  
  //for UndoRedo StackSize
  //static int  CVM_UndoRedoStackSize();
  
  // for failure
  static HRESULT Failure(HRESULT *oResult = NULL);
};
#endif
