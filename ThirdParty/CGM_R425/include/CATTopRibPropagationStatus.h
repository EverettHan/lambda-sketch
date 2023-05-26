/* -*-C++-*- */

#ifndef CATTopRibPropagationStatus_H
#define CATTopRibPropagationStatus_H


// COPYRIGHT DASSAULT SYSTEMES 1999

//===================================================================
//===================================================================
//
// CATTopRibPropagationStatus
//
//
//===================================================================

//===================================================================
// Nov 2002     Creation                         JHG 
//===================================================================
//===================================================================
#include "CATTopRibObject.h"
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATCGMNewArray.h"

class ExportedByRIBLight CATTopRibPropagationStatus : public CATTopRibObject
{
public:

  enum StatusCode
  { 
    Normal, TryComplete, Completed, NextIncluded, OutPropag, Stop
  };

  CATCGMNewClassArrayDeclare;      // Pool allocation
//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
  CATTopRibPropagationStatus();
//  CATTopRibPropagationStatus(StatusCode iCode);
  CATTopRibPropagationStatus(const CATTopRibPropagationStatus &iStatus);

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
  virtual ~CATTopRibPropagationStatus();

  CATBoolean IsNormal();
  CATBoolean IsCompleted();
  CATBoolean IsNextIncluded();
  CATBoolean IsOutPropag();
  CATBoolean IsStop();
  CATBoolean IsTryComplete();

  CATBoolean GetNormalPropag();
  void SetNormalPropag(CATBoolean iNormalPropag);

  void SetStatus(StatusCode iCode);

  void SetSupp(int iSupp);
  int GetSupp();
private:
  StatusCode _Code;
  int _Supp;
  CATBoolean _NormalPropag;
};
#endif

