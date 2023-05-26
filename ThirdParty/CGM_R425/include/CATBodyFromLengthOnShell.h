/* -*-c++-*- */
#ifndef CATBodyFromLengthOnShell_h
#define CATBodyFromLengthOnShell_h
// COPYRIGHT DASSAULT SYSTEMES 1999
//-------------------------------------------------------------------------
// Usage :  Creates a CATVertex in a Body at a given distance on a shell !!
//
// This method uses the geodesic behavier used in the FreeFrom framework.
//
//-------------------------------------------------------------------------
//
//-  The solution may contain multiple vertex,  it may be rare
//-  but one who uses this method should be carefull on the 
//-  solution he or she takes... 
//
//-
//-  If the vertex is not on the shell,  then a point is computed
//-  from the input Vertex that is closest to the shell.  
//-  
//-  WARNING :
//-   Any null pointer given in input will cause a throw.
//-
//-
//  
//-------------------------------------------------------------------------

#include "YJ000GSM.h"
#include "CATBaseUnknown.h"
#include "CATTopOperator.h"
#include "ListPOfCATVertex.h"
#include "CATSkillValue.h"
#include "CATMathDef.h"
#include "CATMathPoint.h"
#include "CATSurParam.h"
#include "CATMathDirection.h"
#include "CATLengthType.h"


class CATExtBodyFromLengthOnShell;
class CATShell;
class CATVertex;
class CATBody;
class CATPoint;
class CATGeoFactory;
class CATCGMJournalList;
class CATTopData;
class CATFace;

class ExportedByYJ000GSM CATBodyFromLengthOnShell : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATBodyFromLengthOnShell);
public:
  // Prepares Vertex solution at given distance on a given Wire.

  //- ----------------------------------------
  //- ABSOLUTE_L = The distance is an absolute value, 
  //-              but the sign indecates the direction 
  //-              on the wire for finding the vertex.
  //- RELATIVE_L = The distance is a fraction of the 
  //-              total length of the wire.  Since 
  //-              its a fraction,  its value must be
  //-              equal to or between -1 and 1. 
  //-              A throw is made if that condition is 
  //-              not met.
  //- The RELATIVE_L DOES NOT MAKE ANY SENSE FOR THIS OPERATOR
  //- ----------------------------------------
  enum CATLengthType 
  { 
    ABSOLUTE_L = CATLengthType_ABSOLUTE_L, 
    RELATIVE_L = CATLengthType_RELATIVE_L 
  };

  //- ----------------------------------------
  // Constructor:  if type is RELATIVE, the ABSOLUTE value will be calculated.
  //- ----------------------------------------
  CATBodyFromLengthOnShell( CATGeoFactory    *iFactory,
	        CATTopData             *iTopData,
          const CATBody          *iShell, 
			    const CATBody          *iVertex,
          const CATMathDirection  &iDirection,
			    const CATLength         iDistance,
			    const CATLengthType     itype    = ABSOLUTE_L,
			    const CATSkillValue     imodev   = BASIC);

  /**
  * @nodoc
  * Deprecated
  */
  CATBodyFromLengthOnShell( CATGeoFactory    *iFactory,
			    const CATBody          *iShell, 
			    const CATBody          *iVertex,
          const CATMathDirection  &iDirection,
			    const CATLength         iDistance,
			    const CATLengthType     itype    = ABSOLUTE_L,
			    const CATSkillValue     imodev   = BASIC,
			    CATCGMJournalList *Journal = NULL);

  //- ----------------------------------------
  //- General method to compute the necessary data.
  //- If Run() was already used, all previous results will be lost
  //- ----------------------------------------
  int Run();
  
  //- ----------------------------------------
  //- Since there is only one possible result for a wire,
  //- those methods are useless.
  void Begin();
  void Next();
  //- ----------------------------------------
  
  
  //- ----------------------------------------
  // Returns the vertex computed by the run.
  //- If the ouput ( i.e. the CATBody or the CATVertex ) is 
  //- NULL, then the run has not been done.
  //- ----------------------------------------
  CATBody    *GetResult();

	//- ----------------------------------------
	//- To use these, CATSkillValue must be declared 
	//- as ADVANCED when the operator is created.
	//- ----------------------------------------
	void SetFactory  ( CATGeoFactory *iFactory );
	void SetShell   ( const CATBody   *iNewShell );
	void SetVertex  ( const CATBody   *iNewVertex );
	//   void SetLength  ( CATLength     aNewDistance, 
	//                     CATLengthType aNewType = ABSOLUTE_L);

	//- ----------------------------------------
	//- Destructor.
	//- ----------------------------------------
	~CATBodyFromLengthOnShell();

	//KY1 : 10-12-2010
	/**	@nodoc @nocgmitf*/ 
	static const  CATString  *GetDefaultOperatorId();
  virtual void RequireDefinitionOfInputAndOutputObjects();

protected:

	//KY1 : 10-12-2010
	/**	@nodoc*/
	int RunOperator();


  /** @nodoc @nocgmitf */
  virtual int RunExactOperator();
  /** @nodoc @nocgmitf */
  virtual int RunPolyOperator();
  /** @nodoc @nocgmitf */
  CATExtBodyFromLengthOnShell * GetBodyFromLengthOnShellExtensible();


private:
 
  //void CreateTheVertex( CATMathPoint &ThePoint );
  void SetInternalData( );
  void BuildPointOnFace(CATFace * iFace, const CATSurParam & iParm, CATBody *& BodyProj );

  CATGeoFactory*      _factory;

  //- Start Data,   -> The shell 
  //-               -> The start vertex on a shell.
  //-               -> The Param of the vertex on a face of the shell
  //-               -> The face that supports the input face.
  CATBody            *_shell;
  CATBody            *_vertex;
  CATSurParam         _StartParam;
  CATFace            *_StartFace;
  int                 _indexOfFace;
  CATMathPoint        _FirstPoint;

  CATLength           _distance;
  CATMathDirection    _Direction;

  CATCGMJournalList  *_journal;
  CATTopData         *_TopData;

  CATBody            *_ResultBody;  
};

/**
* Creates a CATBodyFromLengthOnShell operator.
* @param iFactory
* The factory of the geometry. 
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iShellBody
* The pointer to the target surfacic body on which the offset is expected. 
* @param iVertexBody
* The body containing the point to offset. 
* @param iDirection
* The offset direction.
* @param iDistance
* The offset value.
* @return [out, IUnknown#Release]
* The pointer to the created operator.  To be delete with the destructor method after use.
*/
ExportedByYJ000GSM CATBodyFromLengthOnShell * CATCreateBodyFromLengthOnShell(CATGeoFactory          * iFactory,
                                                                             CATTopData             * iTopData,
                                                                             const CATBody          * iShellBody,
                                                                             const CATBody          * iVertexBody,
                                                                             const CATMathDirection & iDirection,
                                                                             const CATLength          iDistance,
                                                                             const CATLengthType      itype = CATLengthType_ABSOLUTE_L,
                                                                             const CATSkillValue      imodev = ADVANCED);

#endif
