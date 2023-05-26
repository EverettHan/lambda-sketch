/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATOmbOsmBindingService.h
// Gets the CATIOmbOsmBinder interface binding between Omb and Osm 
//
//------------------------------------------------------------------
//

#ifndef CATOmbOsmBindingService_H
#define CCATOmbOsmBindingService_H

#include "AD0XXBAS.h"
#include "CATIOmbOsmBinder.h"

//------------------------------------------------------------------

class ExportedByAD0XXBAS CATOmbOsmBindingService
{
public:
  /**
   * Gets a pointer on the interface realizing the binding between Omb and Osm:
   * Services implemented specifically by OSM on this interface are usable from OMB entities
   * @return
   *   the interface to be used by OMB to access OSM implemented services it needs.
   *   The interface MUST be returned by this service as OMB/OSM are always packaged together
   */
  static CATIOmbOsmBinder& GetBinder();

};

//------------------------------------------------------------------

#endif
