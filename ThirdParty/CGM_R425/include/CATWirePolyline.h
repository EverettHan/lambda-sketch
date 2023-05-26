/* -*-C++-*- */
//	COPYRIGHT DASSAULT SYSTEMES 1998
//===================================================================
//  CATWirePolyline :
//	Operator creates a CATBody containing a CATWire of which geometry
//	is a set of CATLine.
//-------------------------------------------------------------------
//  Notes : Creation for checking the memory size of CATWire
//===================================================================
#ifndef CATWirePolyline_h
#define CATWirePolyline_h

#include "CATSolidPrimitive.h"
#include "Primitives.h"

class CATMathPoint;

class ExportedByPrimitives CATWirePolyline : public CATSolidPrimitive
{
  CATCGMVirtualDeclareClass(CATWirePolyline);
//-------------------------------------------------------------------
public:
//-------------------------------------------------------------------
CATWirePolyline(CATGeoFactory      *iFactory, 
                const int           numberOfPoints, 
                CATMathPoint      **points,
                CATCGMJournalList  *iReport=NULL );
CATWirePolyline(CATGeoFactory      *iFactory, CATTopData * iData,
                const int           numberOfPoints, 
                CATMathPoint      **points );
  
virtual ~CATWirePolyline();

virtual void SetClosure(int iClosed);

};

ExportedByPrimitives CATWirePolyline * CATTopCreateWirePolyline (CATGeoFactory      *iFactory,
                                                               CATTopData         *iData,
                                                               const int           numberOfPoints, 
                                                               CATMathPoint      **points );

ExportedByPrimitives CATWirePolyline * CATCreateWirePolyline (CATGeoFactory      *iFactory,
                                                               CATTopData         *iData,
                                                               const int           numberOfPoints, 
                                                               CATMathPoint      **points );
#endif
