/* -*-C++-*- */
#ifndef CATTopRibConnectNuplet_H
#define CATTopRibConnectNuplet_H
// COPYRIGHT DASSAULT SYSTEMES 2002

//===================================================================
//
// Utilitaire de CATTopRib 
//
//===================================================================

//===================================================================
// Jan. 02    Creation                         R. Rorato
//===================================================================

//TopologicalOperators
#include "CATTopRibDef.h"
#include "ListPOfCATTopRibNuplets.h"

class CATTopRibNupletConnexion;


void CATTopRibConnectNuplet(ListPOfCATTopRibNuplets& iPrevList,
    	                    CATTopRibSign            iPrevDir,
                            int                     &ioPrevPos,
    			    ListPOfCATTopRibNuplets& iNextList,
    			    CATTopRibSign            iNextDir,
    			    int                     &ioNextPos,
    			    CATTopRibNupletConnexion*iConnexion);  

#endif
