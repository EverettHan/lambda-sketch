//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014 => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef PLMExchangeWorkbenchServices_H
#define PLMExchangeWorkbenchServices_H
// COPYRIGHT DASSAULT SYSTEMES 2013
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class enabling to provide services to Interactive context (workbench categories...).
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//    Enable to test different interactive context.
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  May      2013  (JLM) Initial Revision for V6R2014
//
// ****************************************************************

/**  
  *  @level  Protected    
  *  @usage  U1    
  */

// -- PLMExchangeServices
#include "PLMExchangeGlobalServices.h"

// -- System & SpecialAPI
#include "CATSysErrorDef.h"
#include "CATString.h"

/**  Not define Workbench categories. */
#define PLMExchangeWorkbench_Unknown            0x00000000
/**  Search result type Workbench. */
#define PLMExchangeWorkbench_Search             0x00000001
/**  VPM Navigator like Workbench. */
#define PLMExchangeWorkbench_VPMNavigator       0x00000002
/**  Catalog editor. */
#define PLMExchangeWorkbench_CatalogEditor      0x00000004
/**  Folder editor. */
#define PLMExchangeWorkbench_FolderEditor       0x00000008
/**  PPR editor. */
#define PLMExchangeWorkbench_PPREditor          0x00000010
/**  Simulation editor. */
#define PLMExchangeWorkbench_SimulationEditor   0x00000020
/**  Examine editor. */
#define PLMExchangeWorkbench_ExamineEditor      0x00000040
/**  SolidWorks editor. */
#define PLMExchangeWorkbench_SolidWorksEditor   0x00000080
/**  RFLP editor. */
#define PLMExchangeWorkbench_RFLPEditor         0x00000100
/**  Universal editor. */
#define PLMExchangeWorkbench_UniversalEditor    0x00000200
/**  LifeCycle Workbench. */
#define PLMExchangeWorkbench_LifeCycle          0x00000400

/**
  * Class enabling to provide services to Interactive context.
  *
  * <b>Role</b>:
  *  This class provides a unique service to check if we are in a specific interactive context:
  * <ul>
  * <li>Workbench categories such as Search result, VPM Navigator, PPR editor, Catalog, folder...
  * </ul>
  */
//-----------------------------------------------------------------------
class ExportedByPLMExchangeGlobalServices PLMExchangeWorkbenchServices
{
   public:
    /** 
      * Check if workbench name belongs to a certain catagories of workbench.
      *
      * <br><b>Role</b>: Check if workbench name belongs to a certain catagories of workbench to
      *   reduce cost of mogration when workbench or editor name is changing (cf Search, UWP...)
      *
      * @param icWorkbenchName
      *    Name of the workbench to be tested.
      *
      * @param inWorkbenchTypes
      *    Mask of bits defining the different workbench categories.
      * <br><b>Legal values</b>: It can a bit concatenation (OR boolean operator) of the following values:
      * <dl>
      * <dt>PLMExchangeWorkbench_Search</dt>            <dd>Search result type Workbench.</dd>
      * <dt>PLMExchangeWorkbench_VPMNavigator</dt>      <dd>VPM Navigator like Workbench.</dd>
      * <dt>PLMExchangeWorkbench_CatalogEditor</dt>     <dd>Catalog editor.</dd>
      * <dt>PLMExchangeWorkbench_FolderEditor</dt>      <dd>Folder editor.</dd>
      * <dt>PLMExchangeWorkbench_PPREditor</dt>         <dd>PPR editor.</dd>
      * <dt>PLMExchangeWorkbench_SimulationEditor</dt>  <dd>Simulation editor.</dd>
      * <dt>PLMExchangeWorkbench_ExamineEditor</dt>     <dd>Examine editor.</dd>
      * <dt>PLMExchangeWorkbench_SolidWorksEditor</dt>  <dd>SolidWorks editor.</dd>
      * <dt>PLMExchangeWorkbench_RFLPEditor</dt>        <dd>RFLP editor.</dd>
      * <dt>PLMExchangeWorkbench_UniversalEditor</dt>   <dd>Universal editor.</dd>
      * <dt>PLMExchangeWorkbench_LifeCycle</dt>         <dd>LifeCycle WorkBench</dd>
      * </dl>
      *
      * @return
      *    Returns error code.
      * <br><b>Legal values</b>:
      *  <dl>
      *     <dt>S_OK</dt>    <dd>the input workbench belongs to the defined workbench categories.</dd>
      *     <dt>S_FALSE</dt> <dd>the input workbench does not belong to the defined workbench categories.</dd>
      *     <dt>E_FAIL</dt>  <dd>Error during test.</dd>
      *  </dl>
      */
      static HRESULT CheckIfBelongToWorkbenchTypes( const CATString & icWorkbenchName , int inWorkbenchTypes ) ;
} ;
//-----------------------------------------------------------------------
#endif
 
