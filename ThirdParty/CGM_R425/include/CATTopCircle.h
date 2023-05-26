#ifndef CATTopCircle_H
#define CATTopCircle_H

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "ParallelLight.h"
#include "CATTopOperator.h"
#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATCGMJournalList.h"
class CATDistanceTool;
class CATICGMDistanceTool;
//

/**
* Class representing the operator that computes a circle body.
* <br>The CATTopCircle operator follows the global frame of the topological operators
* and satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A CATTopCircle operator is created with the <tt>CATCreateTopCircle</tt> global function.
* It must be directly <tt>delete</tt>d after use. It is not streamable. 
*<li>The computation is done by the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory, after the operator deletion.
*</ul>
*/
class ExportedByParallelLight CATTopCircle : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopCircle);
  public :
/**
* @nodoc
* Constructor. Cannot be called. Use The CreateTopOpCircle.
*/
	CATTopCircle(	CATGeoFactory		* iFactory,
					CATTopData			* iData);

//	CATTopCircle(	CATGeoFactory		* iFactory);					
/*
* Destructor
*/
	virtual ~CATTopCircle();

/**
* Runs <tt>this</tt> operator.
*/
	virtual int			Run() = 0;
/**
 * Returns the created body.
 * @param iJournal
 * The pointer to the journal. If <tt>NULL</tt>, the journal is not output.
 */
	virtual CATBody *	GetResult(CATCGMJournalList * iJournal) = 0;

    /**
     * Checks the input values.
     * @return
     * Not <tt>NULL</tt> in case of error.
     */
	virtual CATLONG32		CheckInput( ) = 0;
/**
 * Defines the first limitation of the circle.
 * @param iVdeb
 * The pointer to the body defining the first limitation of the circle.
 */
	virtual void		SetFirstLimit(CATBody * iVdeb, CATLISTP(CATBody) * iDebSup=NULL) = 0;

/**
 * Returns the first limitation of the circle.
 * @return
 * The pointer to the body defining the first limitation of the circle.
 */
	virtual CATBody *	GetFirstLimit() const = 0;

 /**
 * Defines the last limitation of the circle.
 * @param iVfin
 * The pointer to the body defining the last limitation of the circle.
 */
	virtual void		SetLastLimit(CATBody * iVfin, CATLISTP(CATBody) * iFinSup=NULL) = 0;

/**
 * Returns the last limitation of the circle.
 * @return
 * The pointer to the body defining the last limitation of the circle.
 */
	virtual CATBody *	GetLastLimit() const = 0;


    virtual void SetAngleOrigin(const CATMathPoint & iOrigin) = 0;

	virtual void GetAngleOrigin (CATMathPoint & oOrigin) const = 0;

	virtual void		SetFirstAngle(CATAngle iFirstAngle) = 0;

	virtual CATAngle	GetFirstAngle(CATLONG32 &oHas) const = 0;

	virtual void		SetLastAngle(CATAngle iSecondAngle) = 0;

	virtual CATAngle	GetLastAngle(CATLONG32 &oHas) const = 0;

	virtual void GetCircularData( CATMathPoint     &oCenter,
                                   double           &oRadius,
                                   CATMathDirection &oFirst,
                                   CATMathDirection &oSecond,
                                   double           &oStartAngle,
                                   double           &oEndAngle ) const = 0;
};


//
/**
* Creates a CATTopOpCircle operator that computes a trimmed circle 
* (according to given ray, a center and two limit points) along a 
* supporting Shell
* <b>Orientation</b>: The resulting wire is oriented from the first point to the second one.<br>
* @param iFactory
* The pointer to the factory of the resulting body.
* @param iCenter
* The pointer to the body center of the circle
* @param iSupport
* The pointer to the body defining the support of the input (and output) wire.
* @param Ray
* Ray of the resulting circle
* @param iReport
* The pointer to the journal. If <tt>NULL</tt>, the journal is not filled in.
* @return
* The pointer to the created operator.
*/
/*
ExportedByParallelLight
CATTopCircle * CreateTopOpCircle (CATGeoFactory		*iFactory,
                                  CATCGMJournalList	*iReport,
								  CATBody			*iCenter,
								  CATBody			*iSupport,
								  double			iRay);	*/
/** @nodoc */								
/* Not implemented
ExportedByParallelLight
CATTopCircle * CreateTopOpCircle (CATGeoFactory		*iFactory,
                                  CATTopData		*iReport,
								  CATBody			*iCenter,
								  CATBody			*iSupport,
								  double			iRay);
*/

/**
 * Creates a topological operator that builds a circle body.
 * <br> After creating the operator, use the </tt>Setxxx</tt> methods to tune
 * your parameters. Then run it, retrieve the resulting body, and delete the operator.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iCenter
 * The pointer to the point body defining the center of the circle.
 * @param iSupport
 * The pointer to the skin body defining the support of the circle.
 * @param iRadius
 * The radius of the circle
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByParallelLight
CATTopCircle * CATCreateTopCircle (CATGeoFactory		*iFactory,
                                  CATTopData		*iReport,
								  CATBody			*iCenter,
								  CATBody			*iSupport,
								  double			iRadius);
/**
* @nodoc
*/
ExportedByParallelLight
CATTopCircle * CATCreateTopCircle (CATGeoFactory		*iFactory,
                                  CATTopData		*iReport,
								  CATBody			*iCenter,
								  CATBody			*iSupport,
										CATDistanceTool * iDistance);
/**
* @nodoc
* @nocgmitf
*/
ExportedByParallelLight
CATTopCircle * CATCreateTopCircle (CATGeoFactory		*iFactory,
                                   CATTopData		*iReport,
                                   CATBody			*iCenter,
                                   CATBody			*iSupport,
                                   CATICGMDistanceTool * iDistance);

#endif
