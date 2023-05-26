//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCDSEngineImp.h
// CDS driver implementation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 14.05.2009  Creation                                          JSX
//===================================================================

#ifndef CATCDSVarSweepGossip_H
#define CATCDSVarSweepGossip_H
#include "VarSweepDriver.h"


//#include "CATListPV.h"

#include "CATLISTP_Clean.h"
#include "CATLISTP_PublicInterface.h"

//#define CATLISTP_Append            // Request the methods to create
//#define CATLISTP_RemoveValue
//#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"      // Include macros
class CATCDSVarSweepGossip;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByVarSweepDriver
CATLISTP_DECLARE(CATCDSVarSweepGossip);         // Declare the collection class

class ExportedByVarSweepDriver CATCDSVarSweepGossip
  {
  public:
  CATCDSVarSweepGossip() {;};
  virtual ~CATCDSVarSweepGossip()     {;};
  enum Error {CDSW_Gp_OK,
             CDSW_Gp_ErrorInputSketch,
             CDSW_Gp_ErrorRun,
             CDSW_Gp_ErrorSolve,
             CDSW_Gp_ErrorMarching,
             CDSW_Gp_Error};

  enum Info_Sketch{IS_BadType_ShellMarck,
                   IS_WrongHelpParam,
                   IS_InitialPrositionning};

  };


#endif 
