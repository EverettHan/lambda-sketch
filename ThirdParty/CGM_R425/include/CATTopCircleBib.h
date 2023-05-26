#ifndef CATTopCircleBib_H
#define CATTopCircleBib_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByPARLight.h"
#include "CATTopCircle.h"
#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATCGMJournalList.h"
#include "CATTopDefine.h"

//
class CATBody;
class CATMathPoint;
class CATLISTP(CATBody);
class CATFace;
class CATEdge;

/**
* Class representing the operator that computes a circle.
* <br>The CATTopCircle operator follows the global frame of the topological operators
* and satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A CATTopCircle operator is created with the <tt>CreateTopOpCircle</tt> global method.
* It must be directly <tt>delete</tt>d after use. It is not streamable. 
*<li>The computation is done by the <tt>Run</tt> method. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory, after the operator deletion.
*</ul>
*/
class CATTopCircleBib : public CATTopCircle
{
  public :
/**
* Constructor. Cannot be called. Use The CreateTopOpCircle.
*/

  CATTopCircleBib(CATGeoFactory   * iFactory,
                  CATTopData      * iReport,
                  CATBody         * iCenter,
                  CATBody         * iSupport,
                  double            iRay);
          
/*
* Destructor
*/
  virtual ~CATTopCircleBib();

/*
* BASICS METHODS
*/
  int         Run();

  CATBody *   GetResult(CATCGMJournalList * );

  CATLONG32   CheckInput();

  void        SetFirstLimit(CATBody * Vdeb, CATLISTP(CATBody) * iDebSup=NULL);

  CATBody *   GetFirstLimit() const;

  void        SetLastLimit(CATBody * Vfin, CATLISTP(CATBody) * iFinSup=NULL);

  CATBody *   GetLastLimit() const;

  void        SetAngleOrigin(const CATMathPoint & iOrigin);

  void        GetAngleOrigin (CATMathPoint & oOrigin) const;

  void        SetFirstAngle(CATAngle iFirstAngle);

  CATAngle    GetFirstAngle(CATLONG32 & oHas) const;

  void        SetLastAngle(CATAngle iSecondAngle);

  CATAngle    GetLastAngle(CATLONG32 & oHas) const;

  void        GetCircularData( CATMathPoint      &oCenter,
                               double            &oRadius,
                               CATMathDirection  &oFirst,
                               CATMathDirection  &oSecond,
                               double            &oStartAngle,
                               double            &oEndAngle ) const;
  
  void        ClearJournal();
  void        NoLayDownReported(CATLONG32 iNoLay);
  int         ComputeStartingFace(int               iNbFacesDebOK, 
                                  CATFace        ** iFacesDebOK,
                                  CATSurParam     * iSurParmsDebOK,
                                  CATOrientation  * OrientFaceDebOK,
                                  CATEdge        ** iEdgesDebOK);

	/**	@nodoc @nocgmitf*/ 
	static const  CATString  *GetDefaultOperatorId();

protected:

	//KY1 : 03-01-2010
	/**	@nodoc*/
	int RunOperator();
protected:
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
	/**  @nodoc @nocgmitf */
	void   RequireDefinitionOfInputAndOutputObjects();


  private:

    CATBody             * _TargetBody;  //Result
    CATCGMJournalList   * _Report;
    CATBody             * _Support;     //Shell Support
    CATBody             * _Center;      //Vertex :Center of circle
    CATBody             * _PosePt;      //Vertex: Center laid on _Support
    CATBody             * _VDeb;        //Vertex :First Vertex for Trim
    CATBody             * _VFin;        //Vertex : Second Vertex for Trim
    double                _Rayon;      //Ray of circle

    int                   _ReadBody;
    int                   _ReadReport;
    CATLONG32             _NoLay;
    CATLISTP(CATBody)   * _DebSupport;
    CATLISTP(CATBody)   * _FinSupport;


};

ExportedByPARLight CATTopCircle * CATCreateTopCircleNoOnWire(CATGeoFactory     *iFactory,
                                 CATTopData        *iTopData,
                                 CATBody           *iCenter,
                                 CATBody           *iSupport,
                                 double            Ray);

#endif
