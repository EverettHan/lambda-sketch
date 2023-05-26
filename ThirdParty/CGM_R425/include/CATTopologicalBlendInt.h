#ifndef CATTopologicalBlendInt_H
#define CATTopologicalBlendInt_H

// COPYRIGHT DASSAULT SYSTEMES  2005

// JSX Cration 10 10 05

// Header de CATTopologicalBlend dans protectedinterfaces
// DeCAAifié CATTopologicalBlend
//
// La migration du code DS sur cette interface permet de detruire l'interface CAA
// Les CATCreates sont detruits en R17 mais le source est conservé (CGM livre en r15 et r16)
// En R19 faire une adl_mv de publicinterface vers protectedinterface si il reste des applis non migrées

#include "CATTopologicalBlendPROTECTED.h"
#include "CATBlendValue.h"
#include "FrFTopologicalOpe.h"
#include "CATTopOperator.h"

class CATFrFCCvLimits;
class CATFrFCCvParam;
class CATLaw;
class CATFrFNurbsMultiForm;
class CATVertex;
class CATFrFSweepChecker;
class CATTopData;
class CATGeoFactory;

/**
 * @deprecated V5R10 CATTopBlend
 * Class defining the topological operator that connects two wires with a skin.
 * <br> Continuity criteria can be precised: G0, G1 or G2 if the supporting surfaces of the wires
 * are given, G0 otherwise.
 * <br>The CATTopologicalBlend operator creates the resulting blend
 * separately from the inputs: the topology of the input bodies is not used to define the topology
 * of the resulting body.  
 *<ul>
 * <li>A CATTopologicalBlend operator is created with the <tt>CATCreateTopologicalBlend</tt> global function;
 * it must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is is not streamable. 
 *<li>Options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.Although several sucessive 
 * <tt>Run</tt>s with different inputs
 * are possible, it is strongly recommended to <tt>Run</tt> it only once.
 * <li>The journal corresponding to the blend operation is not yet implemented.
 *</ul>
 */
class ExportedByFrFTopologicalOpe CATTopologicalBlendInt:public CATTopologicalBlend
{
public :

//
           CATTopologicalBlendInt(CATGeoFactory*  iFactory, CATTopData *iTopData)
          :CATTopologicalBlend(iFactory,iTopData) 
           {};

  virtual ~CATTopologicalBlendInt()
    {};

  virtual CATLONG32 GetDefaultTopologicalOrientation()=0;

};

// BLEND
//=========
/**
 * Creates a topological operator that computes a connecting surface between two wires.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.  <br>The journal is not yet implemented.
 * @param iWire1
 * The pointer to the first wire to connect.
 * @param iWire2
 * The pointer to the second wire to connect.
 * @param iSupport1
 * The pointer to the supporting surface of the first wire to connect, thus allowing you to define G1 and G2
 * continuity criteria.
 * @param iSupport2
 * The pointer to the supporting surface of the second wire to connect, thus allowing you to define G1 and G2
 * continuity criteria.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator afer use.
 * @see CATTopologicalBlend
 */
ExportedByFrFTopologicalOpe
CATTopologicalBlendInt *CATCreateTopologicalBlendInt(       CATGeoFactory  * iFactory,
                                                            CATTopData     * iTopData,
                                                      const CATBody        * iWire1,
                                                      const CATBody        * iWire2,
                                                      const CATBody        * iSupport1,
                                                      const CATBody        * iSupport2 );
/** 
 * Not yet implemented. 
 */
ExportedByFrFTopologicalOpe
CATTopologicalBlendInt *CATCreateTopologicalBlendInt(       CATGeoFactory  * iFactory,
                                                            CATTopData     * iTopData,
                                                      const CATBody        * iWire1,
                                                      const CATBody        * iWire2,
                                                      const CATBody        * iSupport1,
                                                      const CATBody        * iSupport2,
                                                            CATLONG32        iKindOfOutput);

/** 
 * Not yet implemented. 
 */
ExportedByFrFTopologicalOpe
CATTopologicalBlendInt * CATCreateTopologicalBlendInt(      CATGeoFactory  * iFactory,
                                                            CATTopData     * iTopData,
                                                      const CATBody        * iWire,
                                                      const CATBody        * iSupport,
                                                            CATLONG32        iKindOfOutput );


#endif
