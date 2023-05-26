#ifndef CATCreateTopAssemble_H 
#define CATCreateTopAssemble_H 

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
* @level Protected
* @usage U1
*/ 

#include "CATHybDef.h"
#include "CATHybAssemble.h"
#include "BOHYBOPELight.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"

/**
* Constructs a CATHybAssemble that assembles bodies. 
* THIS FUNCTION CAN BE USED FOR SHELLS AND WIRES.
* THIS FUNCTION SHOULD BE PREFERRED OVER CATCreateTopAssemble.
* In the case of shell domains the operator detects the edges
* of shell domains laying on curves that are geometrically coiencident,
*  gathers them in one edge, and manages the topology to return a valid body.
* The operator only scans the shell domains. It can create closed shells.
* <br><b>Orientation</b>: The orientation of a resulting shell is the orientation of the first
* face (obtained by the <tt>CATDomain::GetCell</tt> method) of the first shell 
* (obtained by the <tt>CATBody::GetDomain</tt> method). 
* Even if a shell cannot be assembled,
* it is put in the resulting body. However, its orientation may have been changed,
* if the orientation of its first face and its own orientation are
* opposite. 
* In the case of wire domains the operator detects the vertices 
* of wire domains laying on points that are geometrically  
* coiencident, gathers them in one vertex, and manages the topology to return a valid body.
* The operator only scans the wire domains. It can create closed wires.
* <br>Each input body each can contain several disconnected wires.
* If all the wires of the input bodies can be connected in one resulting wire, the orientation
* of the result is the orientation of the first wire (CATBody::GetWire(1)) of the first body.
* If not, the result contains several disconnected wires, which orientation is given by the first wire
* found in the list and belonging to this portion.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBodiesToAssemble
* The pointer to the list of bodies containing the domains to assemble. These bodies must contain at least one 
* shell domain. Wires and lumps domains are ignored.
* The operator does not any self-intersecting tests.
* If shells are intersecting each other, the operator does not assemble them. However, it put
* them into the resulting body. 
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*
*/
ExportedByBOHYBOPELight CATHybAssemble * CATCreateNewTopAssemble(CATGeoFactory*  iFactory, 
                                                            CATTopData*     iData, 
                                                            ListPOfCATBody* iBodiesToAssemble);

/**
* Constructs a CATHybAssemble that assembles bodies.
* THIS FUNCTION CAN BE USED FOR SHELLS AND WIRES. HOWEVER, THE
* CATCreateNewTopAssemble FUNCTION SHOULD BE PREFERED OVER CATCreateTopAssemble.
* CAA DEVELOPERS USING THIS FUNCTION ARE RECOMMENDED TO MIGRATE
* TO CATCreateNewTopAssemble WHICH IS MORE ROBUST.
* In the case of shell domains the operator detects the edges
* of shell domains laying on curves that are geometrically coiencident,
*  gathers them in one edge, and manages the topology to return a valid body.
* The operator only scans the shell domains. It can create closed shells.
* <br><b>Orientation</b>: The orientation of a resulting shell is the orientation of the first
* face (obtained by the <tt>CATDomain::GetCell</tt> method) of the first shell 
* (obtained by the <tt>CATBody::GetDomain</tt> method). 
* Even if a shell cannot be assembled,
* it is put in the resulting body. However, its orientation may have been changed,
* if the orientation of its first face and its own orientation are
* opposite. 
* In the case of wire domains the operator detects the vertices 
* of wire domains laying on points that are geometrically  
* coiencident, gathers them in one vertex, and manages the topology to return a valid body.
* The operator only scans the wire domains. It can create closed wires.
* <br>Each input body each can contain several disconnected wires.
* If all the wires of the input bodies can be connected in one resulting wire, the orientation
* of the result is the orientation of the first wire (CATBody::GetWire(1)) of the first body.
* If not, the result contains several disconnected wires, which orientation is given by the first wire
* found in the list and belonging to this portion.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iBodiesToAssemble
* The pointer to the list of bodies containing the domains to assemble. These bodies must contain at least one 
* shell domain. Wires and lumps domains are ignored.
* The operator does not any self-intersecting tests.
* If shells are intersecting each other, the operator does not assemble them. However, it put
* them into the resulting body. 
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/

ExportedByBOHYBOPELight CATHybAssemble * CATCreateTopAssemble(CATGeoFactory*     iFactory,
                                                         CATTopData*        iData,
                                                         ListPOfCATBody*    iBodiesToAssemble);

/**
* The same as CATCreateNewTopAssemble with a complete report in the journal. For CVM use only.
*/
ExportedByBOHYBOPELight CATHybAssemble * CATCreateNewTopAssembleForCVM(CATGeoFactory*  iFactory, 
                                                                          CATTopData*     iData, 
                                                                          ListPOfCATBody* iBodiesToAssemble);

#endif


