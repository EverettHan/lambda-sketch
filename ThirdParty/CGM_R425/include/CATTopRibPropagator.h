/* -*-C++-*- */

#ifndef CATTopRibPropagator_H
#define CATTopRibPropagator_H


// COPYRIGHT DASSAULT SYSTEMES 1999

//===================================================================
//===================================================================
//
// CATTopRibPropagator
//
// Operateur de propagation d'un ruban
//
// known children : CATTopRibCompletionPropagator
//
//===================================================================

//===================================================================
// Jul 2002     Creation                         JHG 
//===================================================================
//===================================================================
#include "CATTopRibObject.h"
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopDef.h"
#include "CATCGMNewArray.h"

class CATSoftwareConfiguration;
class CATTopRib;


class ExportedByRIBLight CATTopRibPropagator : public CATTopRibObject
{
public:

  CATCGMNewClassArrayDeclare;      // Pool allocation
//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
  CATTopRibPropagator(CATTopRib *iRibToPropag, CATOrientation iDirToPropag, CATSoftwareConfiguration *iSoftwareConfiguration);

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
  virtual ~CATTopRibPropagator();

//------------------------------------------------------------------------------
// Lance la propagation
//------------------------------------------------------------------------------
  virtual void Run() = 0;

protected:
  // ruban a propager
  CATTopRib *_RibToPropag;
  // direction de propagation
  CATOrientation _DirToPropag;
  CATSoftwareConfiguration *_SoftwareConfiguration;
};
#endif

