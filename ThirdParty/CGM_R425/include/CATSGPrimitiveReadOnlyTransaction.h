#pragma once

#include "CATStdLib.h"
#include "CATUnicodeString.h"
#include "CATSGTransaction.h"
#include "SGInfra.h"

class CATRep;
class CATSGPrimitiveReadOnlyTransactionImpl;
class VisPrimitive;
class CATGraphicPrimitive;
class CATSceneGraphImpl;

enum CATSGPrimitiveBufferType
{
	VertexBufferFloat,			// 3 floats per vertex
	IndexBuffer16,				// 16 bits per index
	IndexBuffer32,				// 32 bits per index
	TextureCoordinatesFloat,	// 2 floats per texture coordinate
	TextureCoordinatesFloat3,	// 3 floats per texture coordinate
	UVCoordinatesFloat,				// 2 floats per uv coordinate
	NormalBufferFloat			// 3 floats per normal
};

class ExportedBySGInfra CATSGPrimitiveReadOnlyTransaction
{
public:			

	/**
	Moves to the next primitive
	Fails if the current primitive was the last
	*/
	HRESULT					MoveToNextSibling();

	/**
	Moves to the previous primitive
	Fails if the current primitive was the first
	*/
	HRESULT					MoveToPrevSibling();

	/**
	Returns the current primitive. NULL if the current primitive is a VisPrimitive.
	Does not AddRef.
	*/
	CATGraphicPrimitive *	GetCurrentPrimitive() const;

	/**
	Returns the current primitive. NULL if the current primitive is a CATGraphicPrimitive.
	Does not AddRef.
	*/
	VisPrimitive *			GetCurrentVisPrimitive() const;


	/**
	@return TRUE if the current primitive is a seam edge or point
	*/
	CATBoolean				IsASeamPrimitive() const;

	HRESULT		GetPrimitiveID(CATUnicodeString &oID) const;


	
	CATBoolean  IsCurrentACAT3DFaceGP() const;
	CATBoolean  IsCurrentACAT3DPlanarFaceGP() const;
	CATBoolean  IsCurrentACAT3DEdgeGP() const;
	CATBoolean  IsCurrentACAT3DLineGP() const;
	CATBoolean  IsCurrentACAT3DMarkerGP() const;
	CATBoolean  IsCurrentACAT3DFixedArrowGP() const;
	CATBoolean  IsCurrentACAT3DFixedPlanGP() const;
	CATBoolean  IsCurrentAVisPrimitive() const;

	CATBoolean  IsCurrentACAT2DLineGP() const;
	CATBoolean  IsCurrentACAT2DMarkerGP() const;
	CATBoolean  IsCurrentACAT2DArcEllipseGP() const;
	CATBoolean  IsCurrentACAT2DRectangleGP() const;
	CATBoolean  IsCurrentACAT2DPolygonGP() const;
	CATBoolean  IsCurrentACAT2DArcCircleGP() const;
	CATBoolean  IsCurrentACAT2DAnnotationTextGP() const;
	CATBoolean  IsCurrentACAT2DFixedArrowGP() const;
	CATBoolean  IsCurrentACAT2DImagePixelGP() const;
	CATBoolean  IsCurrentACAT2DNurbsGP() const;
	CATBoolean  IsCurrentACAT2DPolyBezierGP() const;
	CATBoolean  IsCurrentACAT2DPolyPolygonGP() const;
	CATBoolean  IsCurrentACAT2DTextGP() const;
	CATBoolean  IsCurrentACAT2DGeometricTextGP() const;

	/**
	Returns the size of the buffer, in bytes
	*/
	CATULONG32 GetBufferSize(CATSGPrimitiveBufferType iType) const;

	/**
	Fills oBuf with the content of the primitive buffer (specified by iType)	
	Fails if oBuf is too short, or if the primitive does not hold the requested buffer
	*/
	HRESULT FillBuffer(void * oBuf, CATULONG32 iBufSize, CATSGPrimitiveBufferType iType) const;

private:

	// private ctor & dtor. Use CATSGReadOnlyTransaction to create those
	CATSGPrimitiveReadOnlyTransaction(CATSceneGraphImpl * iSG, CATRep * iParent, CATGraphicPrimitive * iPrim);
	CATSGPrimitiveReadOnlyTransaction(CATSceneGraphImpl * iSG, CATRep * iParent, VisPrimitive * iPrim);
	virtual ~CATSGPrimitiveReadOnlyTransaction();

	CATSGPrimitiveReadOnlyTransactionImpl * _Impl;

	friend class CATSGReadOnlyTransactionImpl;
	
};
