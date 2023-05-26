#ifndef CATTopBodyExtremum_h
#define CATTopBodyExtremum_h

//COPYRIGHT DASSAULT SYSTEMES  2003

/**
* @level Protected
* @usage U1
*/

#include "AnalysisTools.h"

#ifndef NULL
#define NULL 0
#endif

#include "CATTopOperator.h"
#include "CATMinMax.h"

class CATBody;
class CATMathVector;
class CATMathPoint;
class CATCGMJournalList;

//-----------------------------------------------------------------------------
/**
* Class defining the operator that computes the point the furthest away from a given point
* in a given direction.
*<br>
* The CATTopBodyExtremum operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input body is not modified. The result is a body
* containing vertices (for isolated solutions), wires or skins.
*<ul>
* <li>A CATTopBodyExtremum operator is created with the <tt>CATCreateDirBodyExtremum</tt> 
* global method. It must be directly <tt>delete</tt>d after use. It is not streamable. 
*<li>The computation is done with the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/
class ExportedByAnalysisTools CATTopBodyExtremum : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopBodyExtremum);
  public :

  /**
  * Constructors - NOT TO BE USED
      */ 
      CATTopBodyExtremum(CATGeoFactory* iFactory, CATTopData* iTopData);
      CATTopBodyExtremum(CATGeoFactory* iFactory, CATCGMJournalList* iJournal);
      
      virtual ~CATTopBodyExtremum();
      
      /**
      * Runs <tt>this</tt> operator.
      */ 
      virtual int  Run() = 0;
      
      /**
      * Returns the distance between the origin and the extremum projection
      * along the specified direction.
      * @return
      * The value.
      */
      virtual double  GetExtremum() = 0;
      
      /**
      * Returns the created body.
      * @return
      * The pointer to the created body containing the vertices, wires or surfaces representing
      * the body extremum.
      */
      virtual CATBody * GetResult() = 0;
};

/**
* @deprecated V5R22 CATCreateDirNewBodyExtremum
* Creates the operator that computes the point(s) the furthest away from a given point
* in a given direction.
* @param iFactory
* The pointer to the geometry factory.
* @param iBody
* The pointer to the body.
* @param iTypeOfExtremum
* The type of extremum: minimum or maximum.
* @param iDirection
* The direction.
* @param iPtOrig
* The origin from which the distance returned by GetExtremum is computed.
* By default, the CATMathPoint is (0,0,0).
* @param iJournal
* The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
* @return
* The pointer to the created operator. To be <tt>delete</tt>d after use.
*/
ExportedByAnalysisTools 
CATTopBodyExtremum * CATCreateDirBodyExtremum(CATGeoFactory *    iFactory,
                                              CATTopData *       iTopData,
                                              CATBody *          iBody, 
                                              CATMinMax          iTypeOfExtremum, 
                                              const CATMathVector & iDirection,
                                              const CATMathPoint  & iPtOrig);
/**
* Creates the operator that computes the point(s) the furthest away from a given point
* in a given direction.
* @param iFactory
* The pointer to the geometry factory.
* @param iBody
* The pointer to the body.
* @param iTypeOfExtremum
* The type of extremum: minimum or maximum.
* @param iDirection
* The direction.
* @param iPtOrig
* The origin from which the distance returned by GetExtremum is computed.
* By default, the CATMathPoint is (0,0,0).
* @param iJournal
* The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
* @return
* The pointer to the created operator. To be <tt>delete</tt>d after use.
*/
ExportedByAnalysisTools 
CATTopBodyExtremum * CATCreateDirNewBodyExtremum(CATGeoFactory *    iFactory,
                                              CATTopData *       iTopData,
                                              CATBody *          iBody, 
                                              CATMinMax          iTypeOfExtremum, 
                                              const CATMathVector & iDirection,
                                              const CATMathPoint  & iPtOrig);

#endif
