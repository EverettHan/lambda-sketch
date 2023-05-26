// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATlsoProtrusionUtil.cpp
// Header definition of CATlsoProtrusionUtil
//
//===================================================================

//===================================================================
//
//  June 2012 - VB7
//  September 2013 - Review by QF2
//===================================================================
#ifndef CATLSOPROTRUSIONUTIL_H
#define CATLSOPROTRUSIONUTIL_H

#include "CATlsoProtrusionDef.h"
#include "ListPOfCATFace.h"
#include "CATBoolean.h"
#include "AdvTrimOpe.h"

class CATBody;
class CATPersistentBody;
class CATPersistentCellInfra;
class CATSoftwareConfiguration;

class ExportedByAdvTrimOpe CATlsoProtrusionUtil
{
public:
  
  static CATlsoProtrusionType ComputeType(CATBody                 * iBody,
                                          CATLISTP(CATFace)       & iFaceList,
                                          CATBoolean                iLiveBodyAllowed,
                                          CATSoftwareConfiguration *iConfig = NULL);

  static CATlsoProtrusionType ComputeType(CATPersistentBody           * iPersistentBody,
                                          CATPersistentCellInfra      & iInfra,
                                          CATLISTP(CATFace)           & iFaceList,
                                          CATBoolean                    iLiveBodyAllowed,
                                          CATSoftwareConfiguration    * iConfig = NULL);
  
  //return TRUE if a big part of FirstBody is lost to obtain SecondBody
  static CATBoolean CheckProtrusionHasBeenDeleted(CATPersistentBody * iSecondPBody, 
                                                  CATPersistentBody * iFirstPBody, 
                                                  CATPersistentCellInfra * persistentInfra, 
                                                  CATSoftwareConfiguration *iConfig = NULL, 
                                                  ListPOfCATFace *oDeleteProtusionList = NULL);
};

#endif 

