/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2010
//------------------------------------------------------------------------------
//      
// class for Top Slicing multibody
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATTopCreateSlicingOperator_h
#define CATTopCreateSlicingOperator_h
/**
 * @nodoc
 */ 
//=========================
//initial plane 
//=========================
//plane equation: Ax +By + Cz -D = 0
// double A= _PlaneEquation[0];
// double B= _PlaneEquation[1];
// double C= _PlaneEquation[2];
// double D= _PlaneEquation[3];
////=========================

#include "BasicTopology.h"
#include "ListPOfCATBody.h"

class CATTopSlicingOperator;
class CATGeoFactory;
class CATTopData;
class CATBody;
//class ListPOfCATBody; 

 ExportedByBasicTopology CATTopSlicingOperator * 
 CATTopCreateSlicingOperator(CATGeoFactory*    iFactory, 
                                             CATTopData*       iData, 
                                             CATLISTP(CATBody) *iBodyList,
                                             double * iPlaneEquation,
                                             double    iOffset,
                                             int           NbSlices);
  
#endif
