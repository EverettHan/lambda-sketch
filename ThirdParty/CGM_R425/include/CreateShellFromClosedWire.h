/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//===================================================================
//  Create a CATShellFromClosedWire operator. Operator creates a
//  CATBody containing CATShell limited by closed CATWire of Input
//  CATBody.
//
//  - Input CATBody must only contains closed CATWire.
//  - Every CATEdge of CATWire must have a CATPCurve on Input CATSurface.
//-------------------------------------------------------------------
//  Usage Notes :
//  ------------
//  - one constructor with one CATBody and one CATSurface.
//  - one constructor with a list of CATBody and a list of CATSurface.
//    Every CATWire must lie at least on one CATSurface.
//-------------------------------------------------------------------
//  WARNING :
//  --------
//  Operator can generate invalid topology if inputs are confused or 
//  intersecting wires. Thus, user have to check the empty intersection
//  between every input wires.
//===================================================================
#ifndef CREATESHELLFROMCLOSEDWIRE_H 
#define CREATESHELLFROMCLOSEDWIRE_H 
//#include "Primitives.h"
#include "BONEWOPE.h"
#include "CATTopDef.h"
#include "ListPOfCATBody.h"
#include "CATListOfCATSurfaces.h"

class CATShellFromClosedWire;
class CATGeoFactory;
class CATBody;
class CATSurface;
class CATCGMJournalList;

//
/**
 * @nodoc
 * Deprecated. Use CATCreateShellFromClosedWire (CATShellFromClosedWire.h).
*/
ExportedByBONEWOPE CATShellFromClosedWire * CreateShellFromClosedWire(
                                                                      CATGeoFactory      *iFactory,
                                                                      const CATBody      *iBody,
                                                                      const CATSurface   *iSupport,
                                                                      CATCGMJournalList  *iReport=NULL);

#endif










