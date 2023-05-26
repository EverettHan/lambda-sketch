#ifndef CATBodyExtremumCoord_h
#define CATBodyExtremumCoord_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "AnalysisTools.h"
#include "CATExtremumCoordCrv.h"
#ifndef NULL
#define NULL 0
#endif

//#include "CATTopOperator.h"
#include "CATTopBodyExtremum.h"
#include "CATDir.h"

class CATBody;
class CATMathVector;
class CATMathPoint;
class CATCGMJournalList;


/**
 * The type of extremum.
 * @param CATMax
 * The extremum in the direction.
 * @param CATMin
 * The extremum in the opposite direction.
 */
 
//enum CATMinMax
// {CATMinimum, CATMaximum};
 

//-----------------------------------------------------------------------------
/**
* Class defining the operator that compute the farest points of a body in a given direction.
*<br>
* The CATBodyExtremumCoord operator follows the global frame of the topological operators 
* and satisfies the smart mechanism: the input body is not modified. The result is a body
* containing vertices (for isolated solutions), wires or skins.
*<ul>
* <li>A CATBodyExtremumCoord operator is created with the <tt>CATCreateAllBodyExtremumCoord</tt> 
* global method. It must be directly <tt>delete</tt>d after use. It is not streamable. 
*<li>The computation is done with the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory. 
*</ul>
*/
class ExportedByAnalysisTools CATBodyExtremumCoord : public CATTopBodyExtremum
{

  CATCGMVirtualDeclareClass(CATBodyExtremumCoord);
  public :
/**
 * Virtual constructor.<br>
 * Cannot be called. Use the <tt>CATCreateTopX</tt> global functions
 * to create the Xxx operator.
 */
   
   CATBodyExtremumCoord(CATGeoFactory* iFactory, CATTopData* iTopData);
   
   // will be disappear ...
   CATBodyExtremumCoord(CATGeoFactory* factory, CATCGMJournalList* journal=0);

    virtual ~CATBodyExtremumCoord();

/**
 * Runs <tt>this</tt> operator.
 */ 
    virtual int  Run() = 0;

/**
 * nodoc.
 */
    virtual void  GetOnlyExtremum(CATLONG32 & oOnly) = 0;
/**
 * nodoc
 */
    virtual void  SetOnlyExtremum(CATLONG32 iOnly) = 0;
/**
 * Returns the value of the extremum in the choosen direction.
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

//-----------------------------------------------------------------------------
/**
 * @nodoc
 */
ExportedByAnalysisTools 
CATBodyExtremumCoord * CATCreateBodyExtremumCoord(CATBody *          iBody, 
                                                  MinMax             iTypeOfExtremum, 
                                                  Direction          iDirection,
                                                  CATCGMJournalList* iJournal=NULL);
ExportedByAnalysisTools 
CATBodyExtremumCoord * CATCreateBodyExtremumCoord(CATBody *          iBody, 
                                                  CATTopData *       iData,
                                                  MinMax             iTypeOfExtremum, 
                                                  Direction          iDirection);

//-----------------------------------------------------------------------------
/**
 * Creates the operator to compute the extremum of a body in one direction.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBody
 * The pointer to the body.
 * @param iTypeOfExtremum
 * The type of extremum.
 * @param iDirection
 * The direction.
 * @param iJournal
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
/*ExportedByAnalysisTools 
CATBodyExtremumCoord * CATCreateAllBodyExtremumCoord(CATGeoFactory *    iFactory,
                                                     CATBody *          iBody, 
                                                     CATMinMax          iTypeOfExtremum, 
                                                     CATDir             iDirection,
                                                     CATCGMJournalList* iJournal=NULL);*/
//-----------------------------------------------------------------------------
/**
 * @nodoc
 * Creates the operator to compute the extremum of a body in one direction.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBody
 * The pointer to the body.
 * @param iTypeOfExtremum
 * The type of extremum. Minimum or maximum.
 * @param iDirection
 * The direction.
 * @param iPtOrig
 * The origin to compute the distance get by GetExtremum method. default (0,0,0).
 * @param iJournal
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByAnalysisTools 
CATBodyExtremumCoord * CATCreateDirBodyExtremumCoord(CATGeoFactory *    iFactory,
                                                     CATBody *          iBody, 
                                                     CATMinMax          iTypeOfExtremum, 
                                                     const CATMathVector & iDirection,
                                                     const CATMathPoint  & iPtOrig,
                                                     CATCGMJournalList* iJournal=NULL);

//-----------------------------------------------------------------------------
/**
 * @nodoc
 * Creates the operator to compute the extremum of a body in one direction.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBody
 * The pointer to the body.
 * @param iTypeOfExtremum
 * The type of extremum. Minimum or maximum.
 * @param iDirection
 * The direction.
 * @param iPtOrig
 * The origin to compute the distance get by GetExtremum method. default (0,0,0).
 * @param iJournal
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByAnalysisTools 
CATBodyExtremumCoord * CATCreateDirBodyExtremumCoord(CATGeoFactory *    iFactory,
																										 CATTopData *       iTopData,
                                                     CATBody *          iBody, 
                                                     CATMinMax          iTypeOfExtremum, 
                                                     const CATMathVector & iDirection,
                                                     const CATMathPoint  & iPtOrig);

//-----------------------------------------------------------------------------
/**
 * @nodoc
 * Creates the operator to compute the extremum of a body in one direction.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBody
 * The pointer to the body.
 * @param iTypeOfExtremum
 * The type of extremum. Minimum or maximum.
 * @param iDirection
 * The direction.
 * @param iPtOrig
 * The origin to compute the distance get by GetExtremum method. default (0,0,0).
 * @param iJournal
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByAnalysisTools 
CATBodyExtremumCoord * CATCreateDirNewBodyExtremumCoord(CATGeoFactory *    iFactory,
																										 CATTopData *       iTopData,
                                                     CATBody *          iBody, 
                                                     CATMinMax          iTypeOfExtremum, 
                                                     const CATMathVector & iDirection,
                                                     const CATMathPoint  & iPtOrig);

#endif
