#ifndef CATDistanceMinImplNew_h
#define CATDistanceMinImplNew_h

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "CATDistanceMinImpl.h"
#include "CATIACGMLevel.h"

class CATDistanceBodyBodyImpl;

/**
 * Wrapper around new distance operator
 */

class CATDistanceMinImplNew : public CATDistanceMinImpl
{
  public :
    /** @nodoc */
    CATDistanceMinImplNew(CATGeoFactory  *iFactory,CATTopData * iData,
                           CATBody        *iBody1,
                           CATBody        *iBody2);
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   virtual ~CATDistanceMinImplNew();     

 		/**
		 * Defines a maximum distance between the two bodies (<tt>ADVANCED</tt> mode).
		 * @param iDistance
		 * The value of the distance known to be an upper bound of the distance between the 
		 * two bodies. This can optimize the performance of the computation.
		 */
    void    SetDistanceMax(double iDistance);

	   /**  @nodoc @nocgmitf */
    double GetDistanceMax();

		/** 
		* Defines another computation (<tt>ADVANCED</tt> mode).
		* <br>If points were computed, they are deleted.
		* @param iBodyToReplace
		* The pointer to the body to be replaced in the definition of the operator.
		* @param iNewBody
		* The pointer to the body replacing <tt>iBodyToReplace</tt> in this operator.
		*/
    void    ReplaceBody(CATBody *iBodyToReplace, CATBody *iNewBody);

    //-------------------------------------------------------------------------
    // Run and Result Access
    //-------------------------------------------------------------------------
		/**
		 * Computes the distance (<tt>ADVANCED</tt> mode).
		 */
    virtual int    Run();

		/**
		 * Returns the computed minimum distance between the two bodies.
		 * @return
		 * The minimum distance. If the distance could not be computed, returns <tt>-1</tt>.
		 */
    double  GetDistance();

		/**
		 * Returns the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 * <br>The life cyle of the points is managed by the operator.
		 * @param oPoint1
		 * The pointer to the point on the first body.
		 * @param oPoint2
		 * The pointer to the point on the second body.
		 */
    void    GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2);

    CATBoolean GetMathPoints(CATMathPoint& oP1, CATMathPoint& oP2);

    /**
		 * Returns the cells on which are the points realizing the minimum distance (<tt>ADVANCED</tt> mode).
		 * <br>The life cyle of the cells is managed by the operator.
		 * @param oCell1
		 * The pointer to the cell on the first body.
		 * @param oCell2
		 * The pointer to the cell on the second body.
		 */
    void    GetSupportCells(CATCell *&oCell1, CATCell *&oCell2);


    //-------------------------------------------------------------------------
    // Legacy methods
    //-------------------------------------------------------------------------

    // does nothing in this operator
    CATBoolean GetPointComputationMode();
    
    // does nothing in this operator
    void    SetPointComputationMode(CATBoolean iTrueOrFalse);

    // does nothing in this operator
    void    SetMaxNumberOfTests(CATLONG32 iMaxNumberOfTests); 

    // does nothing in this operator
    void SetEnvironment(CATTopOpEnvironment * iEnviron);
    
    // shoud never be called
    void ErasePoint(CATPoint *&oPoint);

    // shoud never be called
    void    GetBody(CATLONG32 iNum, CATBody *& oBody);

    // shoud never be called
    CATBoolean    Done();

    // shoud never be called
     void  SetDone(CATBoolean idone);
		 
    // shoud never be called
    CATLONG32 GetMaxNumberOfTests(); 

    // shoud never be called
    CATBody* GetBody1(); 

    // shoud never be called
    CATBody* GetBody2(); 


#ifdef CATIACGMR419CAA

protected:

  //------------------------------------------------------------------------
  // Polyhedral/Hybrid input data authorization/management
  //------------------------------------------------------------------------

  /**  @nodoc @nocgmitf */
  virtual CATBoolean Is_PolyInputs_Allowed();  

  /**  @nodoc @nocgmitf */
  virtual CATBoolean Is_MixedPolyExactInputs_Allowed();

#endif


protected:		 
	   /**  @nodoc @nocgmitf */
	   void   RequireDefinitionOfInputAndOutputObjects();
     
     /**  @nodoc @nocgmitf */
     void    GetPoints_forDebug(CATPoint *&oPoint1, CATPoint *&oPoint2);
protected:		 
     CATDistanceBodyBodyImpl* _NewOpe;
     CATLONG32 _nb_tests;
};

#endif










