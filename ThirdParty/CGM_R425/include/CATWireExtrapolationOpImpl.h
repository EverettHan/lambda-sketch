/* -*-C++-*-*/

#ifndef CATWireExtrapolationOpImpl_h
#define CATWireExtrapolationOpImpl_h

// COPYRIGHT DASSAULT SYSTEMES 1999
//---------------------------------------------------------------------------
//      
// CATExtrapolationWireOpImpl : implementation class for wire extrapolation 
// operator. 
//                       
//       
//---------------------------------------------------------------------------
// Jun. 99  Creation                                             L. Alt
//===========================================================================


#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATTopOperator.h"
#include "ExportedBySHL.h"
#include "CATTopDef.h"
#include "CATListOfInt.h"
#include "ListPOfCATFace.h"
#include "CATMathInline.h"

class CATCGMJournalList;
class CATBody;
class CATWire;
class CATVertex;
class CATEdge;
class CATFace;
class CATPlane;
class CATEdgeCurve;
class CATPointOnEdgeCurve;
//class ListPOfCATFace;
//class CATListOfInt;


class CATxtContext;
class CATxtEdgeRep;
class CATxtVertexRep;

class ExportedBySHL CATWireExtrapolationOpImpl : public CATTopOperator
{
public:

  // Constructor
  //------------------------------------------------------------------------
  CATWireExtrapolationOpImpl( CATBody           * iBody, 
                              CATCGMJournalList * iJournal );

  CATWireExtrapolationOpImpl( CATBody    * iBody, 
                              CATTopData * iTopData,
                              CATBody * iBodySupport=NULL,
                              CATGeoFactory * iFacto=NULL);

  CATWireExtrapolationOpImpl( const CATWireExtrapolationOpImpl & iExtrapolationOrig);

  // Destructor
  //------------------------------------------------------------------------
  ~CATWireExtrapolationOpImpl();
    
  // SetExtrapolation
  //------------------------------------------------------------------------
  void SetExtrapolation( CATVertex * iVertex, double iLength );
  void SetExtrapolation( CATVertex * iVertex, CATPlane * iPlane);

  // Extrapolation UpTo
  //------------------------------------------------------------------------
  void SetWireTarget( CATBody * iTargetBody);

  // Initialise le numero de version
  //------------------------------------------------------------------------
  void SetVersionNumber( CATLONG32 iVersionNumber );

  // Run 
  //------------------------------------------------------------------------
  int  Run();
  void Run( CATBody   * iBody );
  void Run( CATVertex * iVertex );
  void Run( CATEdge   * iEdge );
  
  // Get result body (topological report cannot be read before run is com-
  // pleted).
  //------------------------------------------------------------------------
  CATBody * GetResult();


  // Freeze mode (determines whether modified entities within the body are 
  // enabled to be altered, or if the operator needs to clone them before). 
  // Default is NO (they cannot be altered).
  //------------------------------------------------------------------------
  INLINE short GetFreezeMode() const;
  INLINE void  SetFreezeMode(short iMode=1);

  static CATOrientation GetEdgeOriInBody( CATEdge * iEdge, CATBody * iBody );

#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
public:
	/**	@nodoc @nocgmitf */ 
	static const  CATString  *GetDefaultOperatorId();
#endif

#if  defined  (  CATIACGMV5R21  )
	//KY1 : 10-12-2010
	/**	@nodoc @nocgmitf */
	//int RunOperator();
//protected:
	/**	@nodoc @nocgmitf */
	static  CATString  _OperatorId;
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
	/**  @nodoc @nocgmitf */
	void   RequireDefinitionOfInputAndOutputObjects();
#endif

protected :

  // Initialisation des donnees de l'operateur.
  //------------------------------------------------------------------------
  void Init( CATBody * iBody, CATCGMJournalList * iJournal );

  // Clean up elements that bear extrapolation-related information (attributes)
  //------------------------------------------------------------------------
  void      ReleaseAttributes();

  // Create resuling body 
  //------------------------------------------------------------------------
  CATBody * CreateResultBody();

  // Propagate wire by appending (or inserting) edge-reps to a starting edge-
  // rep.
  //------------------------------------------------------------------------
  void PropagateWire( CATxtEdgeRep   * iFirstEdgeRep, 
                      CATOrientation   iPropagationDirection,
                      CATxtVertexRep * iStartVertex, 
                      CATWire        * iWire );

  
  CATCGMJournalList * GetJournal() ;
  CATBody           * GetInitialBody();

private :

  void RetrieveFacesOfSupport();
  void RetrieveStartFace(CATEdge * iboundedEdge);
  void RetrieveUnderlyingFaces();

  int  RelimitBodyOnSupport(CATBody *& iresultBody);

  void CheckConditionForExtrapolG2UpToPlane(CATEdgeCurve * iEdgeCurve,CATPointOnEdgeCurve * iPoec,CATOrientation Ori,CATSide Side);


  CATBody           * _ResultBody;
  CATBody           * _InitialBody;
  CATCGMJournalList * _Report;
  CATBody           * _SupportBody;
  CATFace           * _SupportFace;
  CATBody           * _TargetBody;
  CATPlane          * _TargetPlane;
  

  CATxtContext      * _Context;

  CATLISTP(CATCell)  _ListOfSupportFaces;
  CATLISTP(CATFace)  _ListOfFacesToAdd;
  CATListOfInt       _ListOfOriFacesToAdd;
};

INLINE short CATWireExtrapolationOpImpl::GetFreezeMode() const
{ return( _freezemode == CATBodyFreezeOn ) ? 1 : 0; }

INLINE void  CATWireExtrapolationOpImpl::SetFreezeMode( short iMode )
{ _freezemode = iMode ? CATBodyFreezeOn : CATBodyFreezeOff; }

#endif



