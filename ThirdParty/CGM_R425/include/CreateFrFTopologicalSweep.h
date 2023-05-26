#ifndef CREATEFRFTOPOLOGICALSWEEP_H 
#define CREATEFRFTOPOLOGICALSWEEP_H

#include "CATIACGMLevel.h"
//#ifdef CATIACGMR421CAA
//#define ShuntDeprecatedCreateFrFTopologicalSweep "TROP TARD. Use CATCreateFrFTopologicalSweep"
//#endif

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/ 

#include <FrFTopologicalOpe.h>
#include <CATSkillValue.h>
#include <CATFrFTopologicalSweep.h>
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATCGMJournalList;
class CATSweepSolverEngineRoadInt;

#ifndef NULL
/** 
 * Defines the null pointer.
 */
#define NULL 0
#endif

/**
 * Creates a topological sweep operator from a profile and a guide.
 * <br>The constructor generates an "unspec sweep" operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iGuide
 * The pointer to the wire body defining the sweep guide.
 * @param iProfile
 * The pointer to the wire body defining the sweep profile.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator after use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalSweep
   ( CATGeoFactory              * iFactory,
     CATTopData                 * iTopData,
     CATBody                    * iGuide  ,
     CATBody                    * iProfile) ;
#ifndef ShuntDeprecatedCreateFrFTopologicalSweep
/**
 * @nodoc
 * Deprecated.
 * Creates a topological sweep operator from a profile and a guide.
 * <br>The constructor generates an "unspec sweep" operator.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iGuide
 * The pointer to the wire body defining the sweep guide.
 * @param iProfile
 * The pointer to the wire body defining the sweep profile.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CreateFrFTopologicalSweep
   ( CATGeoFactory              * iFactory,
     CATBody                    * iGuide  ,
     CATBody                    * iProfile,
     CATSkillValue                iMode   = BASIC, 
     CATCGMJournalList          * iReport = NULL) ;
 
#endif
/**
 * Creates a topological sweep operator from several profiles and guides.
 * <br>This constructor generates:
 * <ul><li> an "unspec sweep" operator, if one guide and one profile.
 *<li> a "bi-rail sweep" operator, if two guides and one profile.
 * <li>a "multi-profiles sweep" operator, in the other cases.
 * </ul>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iGuides
 * The list of the pointers to the wire bodies defining the sweep guides.
 * @param iProfiles
 * The list of the pointers to the wire bodies defining the sweep profiles.
 * @param iSweepType
 * The type of the generated sweep. <br>To be set to <tt>CATFrFTopologicalSweepType_Multi</tt> in order
 * to force the multi-profile sweep in any cases.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalSweep
   ( CATGeoFactory              * iFactory ,
     CATTopData                 * iTopData ,
     CATLISTP(CATGeometry)      * iGuides  ,
     CATLISTP(CATGeometry)      * iProfiles,
     CATFrFTopologicalSweepType   iSweepType  = CATFrFTopologicalSweepType_Std) ;
#ifndef ShuntDeprecatedCreateFrFTopologicalSweep
/**
 * @nodoc
 * Deprecated.
 * Creates a topological sweep operator from several profiles and guides.
 * <br>This constructor generates:
 * <ul><li> an "unspec sweep" operator, if one guide and one profile.
 *<li> a "bi-rail sweep" operator, if two guides and one profile.
 * <li>a "multi-profiles sweep" operator, in the other cases.
 * </ul>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iGuides
 * The list of the pointers to the wire bodies defining the sweep guides.
 * @param iProfiles
 * The list of the pointers to the wire bodies defining the sweep profiles.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @param iSweepType
 * The type of the generated sweep. <br>To be set to <tt>CATFrFTopologicalSweepType_Multi</tt> in order
 * to force the multi-profile sweep in any cases.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CreateFrFTopologicalSweep
   ( CATGeoFactory              * iFactory ,
     CATLISTP(CATGeometry)      * iGuides  ,
     CATLISTP(CATGeometry)      * iProfiles,
     CATSkillValue                iMode      = BASIC,
     CATCGMJournalList          * iReport    = NULL,
     CATFrFTopologicalSweepType   iSweepType = CATFrFTopologicalSweepType_Std) ;
#endif

/**
 * Creates a topological segment sweep operator.
 * <br>The profiles are segments between the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, two
 * guides define a bi-rail segment sweep.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalSegmentSweep
   ( CATGeoFactory              * iFactory,
     CATTopData                 * iTopData,
     CATLISTP(CATGeometry)      * iLimitGuides) ;
#ifndef ShuntDeprecatedCreateFrFTopologicalSweep
/**
 * @nodoc
 * Deprecated.
 * Creates a topological segment sweep operator.
 * <br>The profiles are segments between the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, two
 * guides define a bi-rail segment sweep.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CreateFrFTopologicalSegmentSweep
   ( CATGeoFactory              * iFactory    ,
     CATLISTP(CATGeometry)      * iLimitGuides,
     CATSkillValue                iMode       = BASIC,
     CATCGMJournalList          * iReport     = NULL) ;
#endif

/**
 * Creates a topological circle sweep operator.
 * <br>The profiles are circles passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, three guides
 * are needed.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalCircleSweep
   ( CATGeoFactory              * iFactory    ,
     CATTopData                 * iTopData    ,
     CATLISTP(CATGeometry)      * iLimitGuides) ;
#ifndef ShuntDeprecatedCreateFrFTopologicalSweep
/**
 * @nodoc
 * Deprecated.
 * Creates a topological circle sweep operator.
 * <br>The profiles are circles passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, three guides
 * are needed.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CreateFrFTopologicalCircleSweep
   ( CATGeoFactory              * iFactory    ,
     CATLISTP(CATGeometry)      * iLimitGuides,
     CATSkillValue                iMode       = BASIC,
     CATCGMJournalList          * iReport     = NULL) ;
#endif

/**
 * Creates a topological conic sweep operator.
 * <br>The profiles are conic curves passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, five guides
 * are needed.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalConicSweep
   ( CATGeoFactory              * iFactory    ,
     CATTopData                 * iTopData    ,
     CATLISTP(CATGeometry)      * iLimitGuides) ;
#ifndef ShuntDeprecatedCreateFrFTopologicalSweep
/**
 * @nodoc
 * Deprecated.
 * Creates a topological conic sweep operator.
 * <br>The profiles are conic curves passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, five guides
 * are needed.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CreateFrFTopologicalConicSweep
   ( CATGeoFactory              * iFactory    ,
     CATLISTP(CATGeometry)      * iLimitGuides,
     CATSkillValue                iMode       = BASIC,
     CATCGMJournalList          * iReport     = NULL) ;
#endif
/**
 * @nodoc
 * Creates a topological interpolation sweep operator.
 * <br>The profiles are interpolation curves passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data of the operation.
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, five guides
 * are needed.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalInterpolationSweep
   ( CATGeoFactory              * iFactory    ,
     CATTopData                 * iTopData    ,
     CATLISTP(CATGeometry)      * iLimitGuides) ;

/**
 * @nodoc
 * Creates a topological blend sweep operator.
 * <br>The profiles are interpolation curves passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data of the operation.
 * @param iLimitGuides
 * The list of the pointers to the wire bodies defining the sweep guides. In <tt>BASIC</tt> mode, five guides
 * are needed.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalBlendSweep
   ( CATGeoFactory              * iFactory    ,
     CATTopData                 * iTopData    ,
     CATLISTP(CATGeometry)      * iLimitGuides) ;

/**
 * @nodoc
 * Creates a topological road specialized sweep operator.
 * <br>The profiles are interpolation curves passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data of the operation.
 * @param iGuide
 * The pointer to the wire body defining the sweep guide.
 * @param iProfile
 * The pointer to the wire body defining the sweep profile.
 * (free geometry but must intersect guide and describe sweeping profile topology)
 * @param ioSweepSolver
 * The pointer to solver; input or output
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */

ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalRoadSweep
   ( CATGeoFactory                    *  iFactory      ,
     CATTopData                       *  iTopData      ,
     CATGeometry                      *  iGuide        ,
     CATGeometry                      *  iProfile      ,
     CATSweepSolverEngineRoadInt      *& ioSweepSolver   // aussi rendu en sortie si créé en interne
   ) ;

/**
 * @nodoc
 * Creates a topological road specialized sweep operator.
 * <br>The profiles are interpolation curves passing thru the guides.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data of the operation.
 * @param iGuide
 * The pointer to the wire body defining the sweep guide.
 * @param iGuide2
 * The pointer to the wire body defining the sweep second guide.
 * @param iProfile
 * The pointer to the wire body defining the sweep profile.
 * (free geometry but must intersect guide and describe sweeping profile topology)
 * @param ioSweepSolver
 * The pointer to solver; input or output
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATFrFTopologicalSweep
 */
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweep          * CATCreateFrFTopologicalRoadSweep
   ( CATGeoFactory                    *  iFactory      ,
     CATTopData                       *  iTopData      ,
     CATGeometry                      *  iGuide        ,
     CATGeometry                      *  iGuide2       ,
     CATGeometry                      *  iProfile      ,
     CATSweepSolverEngineRoadInt      *& ioSweepSolver   // aussi rendu en sortie si créé en interne
   ) ;

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
/**
 * @nodoc
 */
ExportedByFrFTopologicalOpe
void Remove
   ( CATFrFTopologicalSweep *&iTopologicalSweep) ;


#endif
