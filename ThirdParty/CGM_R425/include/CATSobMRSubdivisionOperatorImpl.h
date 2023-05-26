//====================================================================
// Copyright Dassault Systemes Provence 2004, All Rights Reserved 
//====================================================================
//
// CATSobMRSubdivisionOperatorImpl.h
//
//====================================================================
//
// Usage notes: Opérateur de subdivision
//
//====================================================================
// March, 2021 : RJY1 : Creation
//====================================================================
#ifndef CATSobMRSubdivisionOperatorImpl_H
#define CATSobMRSubdivisionOperatorImpl_H

#include "CATSobMRSubdivisionOperator.h"


class CATSobMeshBase;
class CATSobOneRingData;

class CATSobMRSubdivisionOperatorImpl : public CATSobMRSubdivisionOperator
{

public:

	//Destructeur
	virtual ~CATSobMRSubdivisionOperatorImpl();

	//construceur
	CATSobMRSubdivisionOperatorImpl(CATSobMeshBase* iMesh, const int iLevel);

	virtual void SetSubdivideAll();
	virtual void SetSubdivideDetailsOnly();
	virtual CATSobDiag SubdivideFace(CATSobFace*, const int);

	// Runs the operator
	virtual CATSobDiag Run();

	//Subdivision d'une edge
	CATSobDiag SubdivideEdge(CATSobEdge*, const int);

	//Subdivision d'un vertex pour les niveaux > 1
	virtual CATSobDiag SubdivideVertex(CATSobVertex*, const int);

	//Récupération du OneRing de points autour d'un vertex fermé
	virtual CATSobDiag GetOneRingOfPointsAroundClosedVertex(CATSobVertex* ipVertex, CATSobOneRingData& oOneRingData, const int iLevel);
	
	//Diag de l'opérateur
	CATSobDiag GetDiag();

	// --------------- Subdivision des Edges --------------------------//
	virtual CATSobDiag SubdivideEdgeImpl(CATSobEdge& iEdge, const int iLevel);

	//Local frame dans la subdivision des vertex pour une edge non bord libre
	 virtual void ComputeLocalFrameForVertexAtEdge(const double* iBeta1, const double* iBeta2,
		const double* iGamma1, const double* iGamma2, const double* iGamma3, const double* iGamma4,
		const char iIsStartVertex, double*& ioLocalFrameForEdge);

	//Local frame dans la subdivision des vertex pour une edge bord libre
	virtual void ComputeLocalFrameForVertexAtEdge(const double* iPoint1, const double* iPoint2, const double* iPoint3, const double* iPoint4,
		double*& ioLocalFrameForEdge);
	virtual void EvalGlobalDetail(double*& iLocalFrame, double*& iLocalDetail, double*&
		ioGlobalDetail);


	virtual CATSobDiag SubdivideVertexImplOpened(CATSobVertex * iVertex, const int iLevel); 
	virtual CATSobDiag SubdivideVertexImplClosed(CATSobVertex* iVertex, const int iLevel, CATSobOneRingData* iopOneRingData = 0);

	CATSobDiag SubdivideEdgeGlobalFrame(CATSobEdge * iEdge, const int iLevel);
	CATSobDiag SubdivideEdgeGlobalFrameOpened(CATSobEdge * iEdge, const int iLevel);
	virtual CATSobDiag SubdivideEdgeGlobalFrameClosed(CATSobEdge* iEdge, const int iLevel);

	virtual CATSobDiag SubdivideEdgeLocalFrameOpened(CATSobEdge * iEdge, const int iLevel);
	virtual CATSobDiag SubdivideEdgeLocalFrameClosed(CATSobEdge* iEdge, const int iLevel);


protected:

	// Attributes
	CATSobDiag _Diag;
	CATBoolean _UseLocalFrame;
	unsigned char _Level;

	//Calcul de puissance de 2
	inline int Power2(const int iExp);

	//Pour les modulo
	int Modulo(const int iX, const int iN);

	CATSobMRSubdivisionOperatorImpl(CATSobMRSubdivisionOperatorImpl&);
	CATSobMRSubdivisionOperatorImpl & operator=(CATSobMRSubdivisionOperatorImpl&);
};

////////////////////
// Puissance de 2
////////////////////
inline int CATSobMRSubdivisionOperatorImpl::Power2(const int iExp)
{
	return (1 << iExp);
}

#endif

