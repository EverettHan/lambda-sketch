// COPYRIGHT DASSAULT SYSTEMES 2020 ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : UF9
//
// DESCRIPTION  : Automatically fill different types of holes with different 
//                  types of continuities according to the surrounding topology
//                
//=============================================================================
// Creation TCA1 March 2020
//=============================================================================

#ifndef CATThicknessComputationOpe_H
#define CATThicknessComputationOpe_H

#include "CATMathDef.h"
#include "CATTopOperator.h"

#include "ListPOfCATEdge.h"
#include "CATMathVector.h"

#include "CATCleverOffset.h"
#include "ListPOfCATFace.h"
#include "CATTopDefine.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATString;
class CATFace;

class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;

class CATThicknessComputationImpl; 

class CATCleverOffset;

//-----------------------------------------------------------------------------
// CATThicknessComputationOpe
//-----------------------------------------------------------------------------
class CATThicknessComputationOpe : public CATTopOperator
{
	CATCGMVirtualDeclareClass(CATThicknessComputationOpe);


	//-------------------------------------------------------------------
	// Operator Interface
	//-------------------------------------------------------------------



	//---------------------------------------------------------
	// CATCreateAutoSkinFillerOpe
	//---------------------------------------------------------
public:
	friend ExportedByCATCleverOffset CATThicknessComputationOpe * CATCreateThicknessComputationOpe(
		CATGeoFactory *     iFactory,
		CATTopData *        iTopData,
		CATBody *           iBody);

	CATThicknessComputationOpe(
		CATGeoFactory *             iFactory,
		CATTopData *                iTopData,
		CATThicknessComputationImpl *     iImpl);
	/*
	**************************************
	set ope

	**************************************
	
	*/

	ExportedByCATCleverOffset void SetFaceMode(short	ifaceMode);

	

	ExportedByCATCleverOffset void SetpointMode(short ipointMode);

		

	
	ExportedByCATCleverOffset void SetFace(CATFace *iface);

	ExportedByCATCleverOffset void Setdirection(CATMathVector *idirection);
	/* 
	//ExportedByCATCleverOffset void SetoListOfOppositeFaces(ListPOfCATFace & ioListOfOppositeFaces);
	*/
	ExportedByCATCleverOffset void SetMaxThickness(double iMaxThickness);
	
	ExportedByCATCleverOffset void SetListOfBodyFaces(const ListPOfCATCell  iListOfBodyFaces);

	ExportedByCATCleverOffset void SetInputBody(CATBody  *iInputBody);

	ExportedByCATCleverOffset void SetStarPoint(CATMathPoint*   StartPoint);

	ExportedByCATCleverOffset void SetOutgoingDirectionDiscard(CATBoolean iOutgoingDirectionDiscard);
	ExportedByCATCleverOffset void SetFaceToStartSearch(CATFace* iFaceToStart);
	ExportedByCATCleverOffset void SetModeLight(short iModeLight);

	// set new 

	




	/* 
	******************************************
	get ope

	******************************************
	*/

	ExportedByCATCleverOffset short GetfaceMode();

	ExportedByCATCleverOffset short GetpointMode();


	ExportedByCATCleverOffset CATMathPoint* GetStartPoint();


	CATFace*	Getface() ; 


	const ListPOfCATCell  GetListOfBodyFaces();

	/*
	const LidtPOfCATCell &   CATThicknessComputationImpl::GetiListofBodyFaces() {

		return iListofBodyFaces;

	}
	*/




	CATMathVector* Getdirection(); 



	CATListOfDouble     GetoListMinDist();
	CATListOfDouble     GetoListMaxDist();
	CATListOfDouble     GetoListAverageDist();
	ListPOfCATFace      GetoListOfOppositeFaces();

	ExportedByCATCleverOffset double  GetMaxThickness();


	ExportedByCATCleverOffset double         GetMinDist();

	ExportedByCATCleverOffset double         GetMaxDist();

	ExportedByCATCleverOffset double         GetAverageDist();




	


	



	//--------------------------------------------------------------
	// END OF OPERATOR INTERFACE
	//--------------------------------------------------------------

	//---------------------------------------------------------
	// Constructor & Destructor
	//---------------------------------------------------------
public:
	virtual ~CATThicknessComputationOpe();


	/*

	***********************************************************
	GetResult
	***********************************************************
	*/

	ExportedByCATCleverOffset int GetResult(double&   oMinDist, double &  oMaxDist, double&   oAverageDist, ListPOfCATFace&  oListOfOppositeFaces);

	ExportedByCATCleverOffset int GetResult(CATListOfDouble& oListMinDist, CATListOfDouble& oListMaxDist, CATListOfDouble& ListAverageDist, ListPOfCATFace&  oListOfOppositeFaces);

	ExportedByCATCleverOffset int GetResult(double&   oDistance, CATMathPoint&    oIntersectedPoint, CATFace*&   oIntersectedFace, CATSurParam&     oMinPointSurParamS,  CATLocation     oLocation);// j'ai ajouté des & et remplacé le * 

protected:


	//---------------------------------------------------------
	// RunOperator
	//---------------------------------------------------------
	int RunOperator();
	


private:
	//---------------------------------------------------------
	// GetImpl
	//---------------------------------------------------------
	CATThicknessComputationImpl * GetImpl();

	//-------------------------------------------------------------------
	// CGMReplay Methods
	//-------------------------------------------------------------------
public:
	static CATString const *  GetDefaultOperatorId();
	CATString const *         GetOperatorId();

	CATExtCGMReplay * IsRecordable(short& oLevelOfRuntime, short& oVersionOfStream);

	void WriteInput(CATCGMStream & oStr);
	void ReadInput(CATCGMStream & ioStr, int iVersionOfStream, short iCGMReplayVersion);
	void Dump(CATCGMOutput & os);
	void DumpOutput(CATCGMOutput& os); 

	void RequireDefinitionOfInputAndOutputObjects();

private:
	static CATString _OperatorId;
	

};

ExportedByCATCleverOffset CATThicknessComputationOpe * CATCreateThicknessComputationOpe(
	CATGeoFactory *     iFactory,
	CATSoftwareConfiguration * ipConfig,
	CATTopData *        iTopData,
	CATBody *           iBody);

#endif
