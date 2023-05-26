#ifndef CATDraftParams_h
#define CATDraftParams_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "Draft.h"

#include "CATMathDef.h"
#include "CATMathDirection.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATCrvParam.h"
#include "CATListPV.h"
#include "CATListOfCATCurves.h"
#include "CATCurve.h"
#include "CATListOfCATCrvLimits.h"
#include "CATCrvLimits.h"
#include "CATTopDefine.h"

class    CATGeoFactory;
class    CATBody;
class    CATWire;
class    CATFace;
class    CATLaw;
class    CATSoftwareConfiguration;

#include "CATSafe.h"
CATSafeDefine(CATDraftParams);

class ExportedByDraft CATDraftParams
{
public:
	//------------------------------------------------------------------------------
	// Define the possible types of inversion:
	//------------------------------------------------------------------------------
	enum InversionParamsType
	{
		NoInversion,
		InversionAngleOnly,
		InversionDirectionOnly,
		BothInversion
	};
	//------------------------------------------------------------------------------
	// Constructors
	//------------------------------------------------------------------------------
	CATDraftParams(CATBody * iNeutralWireBody = NULL, CATWire * iNeutralWire = NULL);

	// Copy constructor
	CATDraftParams(CATDraftParams & iDraftParams);

	// = operator
	CATDraftParams & operator = (const CATDraftParams & iDraftParams);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
	virtual ~CATDraftParams();

	//------------------------------------------------------------------------------
	// Get for draft constant (direction and angle)
	//------------------------------------------------------------------------------
	void GetAngle(CATAngle &oAngle);
	void GetDirection(CATMathDirection &oDirection);

	//------------------------------------------------------------------------------
	// Get number of draft specifications
	// Return : 0 if the draft is constant
	//------------------------------------------------------------------------------
	int GetNbSpecs();

	//------------------------------------------------------------------------------
	// Get one draft specification
	//------------------------------------------------------------------------------
	void             GetSpecLocation  (int NumSpec, int & oNumEdge, double & oParamOnEdge);
	CATAngle         GetSpecAngle     (int NumSpec);
	void             GetSpecDirection (int NumSpec, CATMathDirection &oDirection);

	//------------------------------------------------------------------------------
	// Get neutral wire and its body - Variable draft only
	//------------------------------------------------------------------------------
	CATBody * GetNeutralWireBody();
	CATWire * GetNeutralWire();

	//------------------------------------------------------------------------------
	// Add one draft specification
	//------------------------------------------------------------------------------
	int AddSpec(CATEdge * iEdge, double iParamOnEdge,
		CATAngle iAngle, CATMathDirection * iDirection);

	//------------------------------------------------------------------------------
	// Add Reference Direction
	//------------------------------------------------------------------------------
	void SetReferenceDirection (CATMathDirection * iDirection);

	//------------------------------------------------------------------------------
	// Get the list of edges and orientations - Variable draft only
	//------------------------------------------------------------------------------
	ListPOfCATEdge * GetEdges(CATListOfInt *& Orientations);

	//------------------------------------------------------------------------------
	// Interpretation des angles
	//------------------------------------------------------------------------------
	void SetInvertedParamsStatus(InversionParamsType);
	CATDraftParams::InversionParamsType GetInvertedParamsStatus();

	//------------------------------------------------------------------------------
	// Type de Draft
	//------------------------------------------------------------------------------
	void SetConeEnvelopMode(CATBoolean IsConeEnvelopMode);
	CATBoolean IsConeEnvelopMode();

	//------------------------------------------------------------------------------
	// Creation d'une loi angle
	//------------------------------------------------------------------------------
	CATLaw * CreateVariableLaws(CATGeoFactory                * iFactory,
		CATSoftwareConfiguration     * iConfig,
		const ListPOfCATEdge         * iListOfEdges,
		const CATListOfInt           * iEdgesOrn,
		int                            iStartCheckEdge,
		int                            iEndCheckEdge,
		CATBoolean                     iClosedLaw,
		//Les mappings : la iListeOfCurves[i] va de iListOfEdges[iMappingEdgeWithCurve[i-1]]
		//a iListOfEdges[iMappingEdgeWithCurve[i]], avec iMappingEdgeWithCurve[0]=1 (i commence a 1).
		const CATListOfInt           * iMappingEdgeWithCurve,
		const CATLISTP(CATCurve)     * iListeOfCurves,
		const CATLISTP(CATCrvLimits) * iLimitsOnCrv,
		CATLaw                     *** oMappingLaw);

	//------------------------------------------------------------------------------
	//  Is Neutral Wire Orientation Inverted
	//------------------------------------------------------------------------------
	void SetIsNtrlWireOriInverted(CATBoolean IsNtrlWireOriInverted); // DSH1 Feb-2015
	CATBoolean IsNtrlWireOriInverted();	// DSH1 Feb-2015


private :

	//------------------------------------------------------------------------------
	// Private Data
	//------------------------------------------------------------------------------
	struct ExportedByDraft Spec
	{
		int              EdgeNum;    // Numero de l'edge dans _Edges
		double           Param;      // Parametre curviligne sur l'edge
		CATAngle         Angle;      // Angle
		CATMathDirection Direction;  // Direction
	};

	CATBoolean          _IsConeEnvelopMode;  // Mode du draft
	CATMathDirection  * _ReferenceDirection; // Direction necessaire sans spec
	CATListPV           _Specs;              // Liste des specs
	ListPOfCATEdge      _Edges;              // Liste des edges du wire
	// (sur lesquelles on pose les specs)
	CATListOfInt        _Orientations;       // Orientations des edges dans le wire
	InversionParamsType _InversionParamsType;// Comprendre la direction et l'angle
	CATBody           * _WireBody;           // Body du wire ci-dessous
	CATWire           * _Wire;               // Wire sur lequel sont posees les specs
	CATBoolean _IsNtrlWireOriInverted;				//	Is Neutral Wire Orientation Inverted DSH1 Feb-2015

	//------------------------------------------------------------------------------
	// Valide la liste entree avec le wire initial
	//------------------------------------------------------------------------------
	CATOrientation CheckWire(CATGeoFactory        * iFactory,
		const ListPOfCATEdge * iListOfEdges,
		const CATListOfInt   * iEdgesOrn,
		int                    iStartCheckEdge,
		int                    iEndCheckEdge);

	//REN Wk35, 2012 
	CATBoolean _AutoUntwistMode;

	//D1A: July 2012: Start: MultiAngleDraft:
	CATLISTP(CATFace) _MADFacesToDraft;
	CATAngle _MADAngle;
	CATBoolean _MultiAngleDraft;
public:    
	void SetMultiAngleDraft(CATBoolean DraftMultiAngle) ;
	CATBoolean IsMultiAngleDraft();
	//If the case is of MultiAngleDraft, then following methods work otherwise error is thrown
	void SetInputsForMAD (const CATLISTP(CATFace) & iFacesToDraft, CATAngle iAngle); 
	void GetMADFaces(CATLISTP(CATFace) & oListOfFaces) ;        
	//D1A: End

	CATBoolean GetAutoUntwistMode();
	void SetAutoUntwistMode(CATBoolean iAutoUntwistMode);
};

#endif
