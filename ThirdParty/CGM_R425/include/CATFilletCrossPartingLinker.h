/* -*-c++-*- */
#ifndef CATFilletCrossPartingLinker_H
#define CATFilletCrossPartingLinker_H

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005

//===================================================================
//===================================================================
//
// Class dedicated to Fillet Cross Parting for AutoFillet 
//
//===================================================================
//===================================================================

#include "RibbonLight.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATEdge.h"
class CATBody;
class CATEdge;
class CATVertex;

#include "CATSafe.h"
CATSafeDefine(CATFilletCrossPartingLinker);

class CATSoftwareConfiguration;

class ExportedByRibbonLight CATFilletCrossPartingLinker
{
  // ----------------------------------------------------------------------------
  public:
 
  CATFilletCrossPartingLinker(CATSoftwareConfiguration *iConfig);  

  CATCGMNewClassArrayDeclare;        // Pool allocation

  virtual ~CATFilletCrossPartingLinker();

  virtual void GetEdges(CATBody*           iBody,
                        CATVertex*        &ioVertexOnParting, 
                        CATEdge*           iEdgeOnParting1, 
                        CATEdge*           iEdgeOnParting2, 
                        CATLISTP(CATEdge) &oEdges );

  CATSoftwareConfiguration *GetSoftwareConfiguration();
  
  // ----------------------------------------------------------------------------
  private:

  CATSoftwareConfiguration *_Config;
  // ----------------------------------------------------------------------------
};


#endif
