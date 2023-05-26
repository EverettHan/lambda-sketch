/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1998
 
 DESCRIPTION : Smoothify method
               Assemble two wires thanks to a third wire tangent to others

=============================================================================
*/
#ifndef CATGetParamOnEdge_H
#define CATGetParamOnEdge_H

class CATVertex;
class CATEdge;
class CATCrvParam;

#include "ParallelLight.h"
#include "CATErrorDef.h"

ExportedByParallelLight HRESULT GetParamOnEdge(CATVertex * iVertex, CATEdge * iEdge, CATCrvParam & CurParam);

#endif
