/**
 * @level Protected
 * @usage U1
 */

// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATIAServicesForFilterLayer.h
//  definition of several services for V4 filters access
//
//===================================================================
//
// Usage notes:
//===================================================================
//
//  Dec 2002  Creation: OGM
//===================================================================

#ifndef CATIAServicesForFilterLayer_H
#define CATIAServicesForFilterLayer_H

#include "IUnknown.h"
#include "ExportedByCATIAEntity.h"

class CATIAModel ;

// This structure will be usefull to build and decode the stream.
struct FilterInStream
{
  char name[72] ;
  char description[32] ;
} ;

// This method is used to get a stream ( unsigned char tab ), corresponding to the definition of
// all the filters stored in iModel ( V4 model ).
//   oFilterStream is allocated inside the method, but must be destroyed outside, by the caller, with delete []
//   the length of oFilterStream is : 8 + ( oNbFilter * sizeof(FilterInStream) )
//   If there's no filter, result will be S_OK, oNbFilter=0 and oFilterStream=NULL

// The content of the stream is :
//  2 bytes for the number of filters ( one short )
//  6 bytes free for possible evolution
//  104 bytes for each filter :
//    72 bytes for the name
//    32 bytes for the description of the filter

HRESULT ExportedByCATIAEntity GetFilterStream( CATIAModel* const iModel,
                                               short&            oNbFilter,
                                               char*&            oFilterStream ) ;

// This method is used to getthe definition of the current layer's filter
// of iModel. oLayer tab contains values that can be :
//  0x00 if the the layer is non visible
//  0xFF if the layer is visible
// ------------------------------------------------------------------------
HRESULT ExportedByCATIAEntity GetCurrentFilter( CATIAModel* const iModel,
                                                unsigned char     oLayer[255] ) ;

#endif
