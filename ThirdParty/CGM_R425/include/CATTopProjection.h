/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
//      
// class for Hybrid Projection : euclidean or geodesic
//       
//------------------------------------------------------------------------------
#ifndef CATTopProjection_h
#define CATTopProjection_h

/**
* Class defining the operator that projects a body on another one.
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATProjection is created with the <tt>CATCreateTopProjection</tt> global function.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
* <li>The projection can be restricted on a given domain on each body with the methods
* <tt>SetFirstDomainToIntersect</tt> and <tt>SetSecondDomainToIntersect</tt>
* <li>The projection can be restricted on a given domain on each body with the methods
* <tt>SetFirstDomainToIntersect</tt> and <tt>SetSecondDomainToIntersect</tt>
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopProjection
*/


#include "BOHYBOPELight.h"
#include "CATTopOperator.h"

class CATDomain;


class ExportedByBOHYBOPELight CATTopProjection : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATTopProjection);
  public :
   
   //  Constructor
   /** @nodoc */
   CATTopProjection(CATGeoFactory* iGeoFactory,CATTopData*    iTopData);

   virtual ~CATTopProjection();
   
   /**
   * Run
   */
   virtual int Run()                                          =0;

   /**
	 * Returns all the computed projections in a single body.
	 * @return
	 * The pointer to the resulting body. If you do not want to keep it, use the @href CATICGMContainer#Remove method
	 * to remove it from the geometric factory after the <tt>delet</tt>ion</tt> of <tt>this</tt> operator.
	 */
   virtual CATBody * GetResult()                              =0;
   virtual CATBody * GetResult(CATCGMJournalList * iJourn)    =0;

   /**
   * Defines which domain of the first body must be projected.
   * @param iDomain
   * The pointer to the domain to project
   */
   virtual void SetDomainToProject(CATDomain * iDomain)       =0;

   /**
   * Defines on which domain of the second body the projection is done.
   * @param iDomain
   * The pointer to the domain on which to project
   */
   virtual void SetDomainSupport(CATDomain * iDomain)         =0;

   /**
    * Permit to compute only solutions at a given distance from the point to project
    * @param iDistance
    * the distance.
    */
   virtual void SetMaxDistance (double iDistance)                 =0;

   /**
   * Only compute the best solution, the closest from the original point
   * @param bestsol=1 to compute the best solution
   */
   virtual void SetBestSolWanted(CATLONG32 bestsol=0)=0;

   /**
    * Returns the maximum distance of projection for a given domain of the resulting body.
	* if no domain given, shortest distance is returned 
    * @param iDomainOfResultBody
    * The pointer to the domain.
    * @return
    * The distance.
    */
   virtual double GetDistance(CATDomain * iDomainOfResultBody=NULL)=0; 

   /**
    * Return the line between point to project and the given domain of the result
	* if no domain given, line between closest solution and point to project is returned 
    * @param iDomainOfResultBody
    * The pointer to the domain.
    * @return
    * The line.
    */
   virtual CATBody * GetLine(CATDomain * iDomainOfResultBody=NULL)=0;

   /**
   * Retrieve distance max between BodyToProject and solutions
   */
   virtual double GetMaxDistance()                              =0;

};
#endif

