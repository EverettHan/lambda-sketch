// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATTopoGeodesic:
// Interface class of the CornerOnSupport Operator.
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// July 98     Creation                       JBX
//  11 01 02  ALV   Ajout de iNbWires dans le constructeur 
//                  pour l'indexation des corners solutions.
//========================================================================== 
//
#ifndef CreateTop3DCorner_H
#define CreateTop3DCorner_H
//
#include "BasicTopology.h"
//
class CATTopCorner;
class CATGeoFactory;
class CATTopData;
class CATBody;
/**
 * Creates the operator defining a 3D corner between two wires. 
 * The wire can be degenerated by one vertex.
 * @param iFactory
 * The pointer to the factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. 
 * If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iCurveOrPoint1
 * The first wire or point.
 * @param iCurveOrPoint2
 * The second wire or point.
 * @param iCylinderDirection
 * @param iRadius
 * The radius
 * @return
 * The pointer to the created operator. 
 * To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBasicTopology
CATTopCorner * CreateTop3DCorner ( CATGeoFactory * iFactory,
                                   CATTopData    * iTopData,
				                   CATBody       * iCurveOrPoint1,
				                   CATBody       * iCurveOrPoint2,
				                   double          iRadius);

#endif

