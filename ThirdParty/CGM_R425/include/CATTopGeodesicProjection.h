//=========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002 
//=========================================================================
//
// CATTopGeodesicProjection
//
//=========================================================================
//
// Usage notes:
//
//========================================================================= 
// Oct 02     Creation                       AOV 
//========================================================================= 

#ifndef CATTopGeodesicProjection_h
#define CATTopGeodesicProjection_h

#include "CATTopProjection.h"
#include "FrFTopologicalOpe.h"
#include "CATListOfCATPoints.h"

class CATVertex;



/**
* Class representing the operator that computes the geodesic projection of a point on a wire lying on a shell domain.
* <br>There is no unique solution to the projection computation.
* <br>The CATTopGeodesicProjection operator satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
* <ul>
* <li>A CATTopGeodesicProjection operator is created with the <tt>CATCreateTopGeodesicProjection</tt> global method.
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


class ExportedByFrFTopologicalOpe CATTopGeodesicProjection : public CATTopProjection
{

  public:

    //constructor
    CATTopGeodesicProjection(CATGeoFactory * iFactory       ,
                             CATTopData    * iData          ,
                             CATBody       * iPointToProject,
                             CATBody       * iWireSupport   ,
                             CATBody       * iShell         );
    virtual ~CATTopGeodesicProjection();

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
    * Defines on which domain of the second body the projection is done.
    * @param iDomain
    * The pointer to the domain on which to project
    */
    virtual void SetDomainSupport(CATDomain * iDomain);

    /**
    * Only compute the best solution, closest from point to project
    */
    virtual void SetBestSolWanted(CATLONG32 bestsol=0);

    /**
    * Maximal distance to compute solutions
    */
    virtual void SetMaxDistance (double iDistance);

    /**
    * Compute geodesic distance between point to project and one of the solution
    * If no domain is given, shortest distance is returned
    */
    virtual double GetDistance(CATDomain * iDomainOfResultBody=NULL);

    /**
    * Retrieve geodesic line between point to project and its closest projection
    * If no domain is given, line between closest result and point to project is returned
    */
    virtual CATBody * GetLine(CATDomain * iDomainOfResultBody=NULL);

    /**
    * Retrieve distance max between BodyToPorject and solution
    */
    virtual double GetMaxDistance();

    //KY1 : 03-01-2010

    /**  @nodoc @nocgmitf*/ 
    static const  CATString  *GetDefaultOperatorId();

protected:

  //KY1 : 03-01-2010
  /**  @nodoc*/
  int RunOperator();
  /**  @nodoc @nocgmitf */
  static  CATString  _OperatorId;
  /**  @nodoc @nocgmitf */
  const  CATString  *GetOperatorId();
  /**  @nodoc @nocgmitf */
  void   RequireDefinitionOfInputAndOutputObjects();
  

  protected:

    void    BuildJournal                (CATCGMJournalList * iJourn);
    void    ComputeProjection           (CATGeoFactory     * iFactory      ,
                                         CATTopData        * iData         ,
                                         CATBody           * iBodyToProject,
                                         CATBody           * iBodySupport  );
    int     ComputeRadiusForRelimitation();
    double  AdjustBestDistanceUsingGaps (double iDistance, double iCrossedGaps);

    CATLISTP(CATPoint) SortSolution();


    
    //the inputs bodies
    CATBody           * _BodyToProject;
    CATBody           * _BodySupport;
    CATBody           * _BodyShell;


    CATDomain         * _DomainToProject;
    CATDomain         * _DomainSupport;

    //journal
    CATCGMJournalList * _JournResult;
    short               _IsInsert;

    //array of solution
    CATLISTP(CATBody)  _ListOfProjection;
    CATLISTP(CATPoint) _ListOfPoint;
    CATLONG32          _NbSolution;

    //line retrieved between point
    //to project and best solution
    CATBody          * _BestLine;
    
    //datas for relimitation
    double             _BestDistance;
    double             _Radius;
    CATLONG32          _RelimitWire;
    CATLONG32          _BestSol;
    CATLONG32          _ConsiderGapsForBestDistance;
    short              _IsGetted;

    double             _Resolution;
};



#endif 


