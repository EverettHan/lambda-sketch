//=========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002 
//=========================================================================
//
// CATTopEuclideanProjection
//
//=========================================================================
//
// Usage notes:
//
//========================================================================= 
// Oct 02     Creation                       AOV 
//========================================================================= 

#ifndef CATTopEuclideanProjection_h
#define CATTopEuclideanProjection_h

class CATString;

#include "CATTopProjection.h"
#include "CATHybProject.h"
#include "CATMathDirection.h"
#include "BOHYBOPELight.h"


/**
* Class representing the operator that computes the euclidean projection 
* <br>There is no unique solution to the projection computation.
* <br>The CATTopEuclideanProjection operator satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
* <ul>
* <li>A CATTopEuclideanProjection operator is created with the <tt>CATCreateTopEuclideanProjection</tt> global method.
* It must be directly <tt>delete</tt>d after use. It is not streamable. 
* Asking for the computation with the <tt>Run</tt> method. 
* <li>The result is accessed with 
* <ul><li>the <tt>GetResult</tt> method: all the computed projections are put in the same resulting body.
* </ul> 
* If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove them from the 
* geometric factory, after the operator deletion.
*</ul>
*/


class ExportedByBOHYBOPELight CATTopEuclideanProjection : public CATTopProjection
{
	
public:
	
	/**
	* Constructor
	*/
    CATTopEuclideanProjection(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iPointToProject,CATBody * iWireSupport,CATMathDirection * iDirection);

	/**
	* Destructor
	*/
    virtual ~CATTopEuclideanProjection();
	
    /**
    * Run
    */
    virtual int Run();
	
    /**
	* Returns all the computed projections in a single body.
	* @return
	* The pointer to the resulting body. If you do not want to keep it, use the @href CATICGMContainer#Remove method
	* to remove it from the geometric factory after the <tt>delet</tt>ion</tt> of <tt>this</tt> operator.
	*/
    virtual CATBody * GetResult();
    virtual CATBody * GetResult(CATCGMJournalList * iJourn);
	
    /**
    * Defines which domain of the first body must be projected.
    * @param iDomain
    * The pointer to the domain to project
    */
    virtual void SetDomainToProject(CATDomain * iDomain);
	
	/**
	* Only compute best solution, the closest from point to project
	*/
	virtual void SetBestSolWanted(CATLONG32 bestsol=0);
	
    /**
    * Defines on which domain of the second body the projection is done.
    * @param iDomain
    * The pointer to the domain on which to project
    */
    virtual void SetDomainSupport(CATDomain * iDomain);
	
	/**
    * Maximal distance to compute solutions
    */
    virtual void SetMaxDistance(double iDistance);
	
    /**
    * Compute geodesic distnace between point to project and one of the solution
	* If no domain given, best distance is returned
    */
    virtual double GetDistance(CATDomain * iDomainOfResultBody=NULL);
	
	/**
	* Retrieve euclidean line between point to project and its closest projection
	* If no doamin is given, line between best result and point to project is returned
	*/
		virtual CATBody * GetLine(CATDomain * iDomainOfResultBody=NULL);

		/**
		* Retrieve distance max between BodyToProject and solution wanted by user
		*/
		virtual double GetMaxDistance();

		//KY1 : 03-01-2010

		/**	@nodoc @nocgmitf*/ 
		static const  CATString  *GetDefaultOperatorId();

protected:

	//KY1 : 03-01-2010
	/**	@nodoc*/
	int RunOperator();
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
	/**  @nodoc @nocgmitf */
	void   RequireDefinitionOfInputAndOutputObjects();

  protected:
    
    
    CATHybProject * _ProjectOpe;

    //the inputs bodies
    CATBody * _BodyToProject;
    CATBody * _BodySupport;
    CATMathDirection * _Direction;
	  CATCGMJournalList * _JournResult;

     CATDomain *_DomainToProject;
     CATDomain *_DomainSupport;

    double _Distance;
	  double _BestDistance;
    CATLONG32 _RelimitSupport;
	  CATLONG32 _BestSol;
	  double _IsGetted;
    short _IsInsert;

	  //body line retrieved between point to project
	  //and best solution
	  CATBody * _BestLine;

};
#endif 


