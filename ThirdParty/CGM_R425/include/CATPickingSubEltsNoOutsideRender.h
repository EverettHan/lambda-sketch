#ifndef CATPickingSubEltsNoOutsideRender_H
#define CATPickingSubEltsNoOutsideRender_H

//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    Render needed to draw the scene to determine what's lying inside the trap
//    selection. The whole sub-elements inside are added to the pickpath list.
//
//******************************************************************************
//  Usage:
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATPickingSubEltsNoOutsideRender
//                  CATPickingNoOutsideRender
//                    CATPickingRender
//                      CATRepRender
//                        CATRender
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************

#include "SGInfra.h"
#include "CATPickingNoOutsideRender.h"
#include "list.h"
#include "CATListOfInt.h"

class CATRep;
class CATSupport;
class CATGraphicAttributeSet;
class CAT2DBoundingBox;
class CAT3DBoundingSphere;
class CATGraphicMaterial;
class CATPickPathList;
class CAT2DGeometricTextGP;
class CAT3DEdgeGP;
class CAT3DFaceGP;
class CAT3DPlanarFaceGP;
class CAT3DCylinderGP;
class CAT3DCurvedPipeGP;
class CAT4x4Matrix;
class CAT3x3Matrix;
class CATViewpoint;
class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DLine;
class CATViz3DMarker;
class CATHashTable;

enum CATPickingSubEltsNoOutsideMode { CATPickingSubEltsNoOutside_All, CATPickingSubEltsNoOutside_VisibleAndAjoining};

class ExportedBySGInfra CATPickingSubEltsNoOutsideRender : public CATPickingNoOutsideRender
{
	CATDeclareClass_Deprec;

public:

	CATPickingSubEltsNoOutsideRender (const CATSupport& iSupport, const float iX, const float iY, const float iDx, const float iDy, CATPickPathList& ioPickPathList, const CATPickingSubEltsNoOutsideMode iMode = CATPickingSubEltsNoOutside_All);
	CATPickingSubEltsNoOutsideRender (const CATPickingSubEltsNoOutsideRender &);

	virtual ~CATPickingSubEltsNoOutsideRender();

	//  Stop selection of sub-elements and sub-reps
	//  -------------------------------------------
	virtual void BeginStopSubEltsPicking (const CATRep&);
	virtual void EndStopSubEltsPicking (const CATRep&);

	//  Begin/End Draw Rep
	//  ------------------
  virtual int DrawRepresentation (CATRep &iRep, int iInside, void* &iData);
  virtual int EndDrawRepresentation (CATRep &iRep, void* &iData);

	//  Draw
	//  ----
	virtual void Draw(list<CATViewpoint>& iViewpointList, const int iStereo, const float iGap);
	virtual void DrawFurtive(list<CATViewpoint>& iViewpointList, const int iStereo, const float iGap);
	virtual void DrawDialog(list<CATViewpoint>& iViewpointList, const int iStereo, const float iGap);

	//  Begin/End Draw
	//  --------------
	virtual void BeginDraw (CATViewpoint& iViewpoint);
	virtual void EndDraw   (CATViewpoint& iViewpoint);

	//  IsDrawable
	//  ----------
	virtual int IsDrawable (const CATGraphicAttributeSet&, const CAT2DBoundingBox&, const CATRep&);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const CAT2DBoundingBox&, const int iSubElementId);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const float* ipCenter, const float iRadius, const int iSubElementId);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const CAT3DBoundingSphere&, const CATRep& , CATGraphicMaterial* ipMat=0);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const int iSubElementId, const int iType);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const list<int>& ipSubElementIdList, const int iType);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const int iSubElementId);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const list<int>& ipSubElementIdList);
	virtual int IsDrawable (const CATGraphicAttributeSet&, const CATRep& ,CATGraphicMaterial* ipMat=0);
	virtual int IsDrawable (const CATGraphicAttributeSet&, CATGraphicMaterial* ipMat);
	virtual int IsDrawable (const CATGraphicAttributeSet&);
	virtual int IsDrawable (const int);
	virtual int IsDrawable (const list<int>&);

	//  Draw GPs
	//  ----------
	virtual void Draw2DGeometricText       (CAT2DGeometricTextGP&);
	virtual void Draw3DEdge                (CAT3DEdgeGP&);
	virtual void Draw3DFace                (CAT3DFaceGP&);
	virtual void Draw3DPlanarFace          (CAT3DPlanarFaceGP&);
	virtual void Draw3DCylinder            (CAT3DCylinderGP&, const int=0);
	virtual void Draw3DCurvedPipe          (CAT3DCurvedPipeGP&);

  virtual void DrawVisPrimitive     (VisPrimitive &);

	virtual void DrawCATViz3DFace			(CATViz3DFace*);
	virtual void DrawCATViz3DEdge			(CATViz3DEdge*);
	virtual void DrawCATViz3DLine			(CATViz3DLine*);
	virtual void DrawCATViz3DMarker         (CATViz3DMarker*);

	virtual void ImmediateDraw3DMarker         (const float* ipPoints, const int iPointCount, SymbolType iSymbolType);
	virtual void ImmediateDraw3DAnnotationText (const float* ipPoint, const CATUnicodeString& iText, AnchorPoint iPosition = BASE_LEFT, const float iHeight = 0.f, const int iContour = 0);
	virtual void ImmediateDraw3DLine           (const float* ipPoints, const int iPointCount, const int iLinetype = 0, TessFlag iTessStatus = LINE);
	virtual void ImmediateDraw3DImagePixel     (const float* ipPoint, const CATPixelImage* ipPixelImage, const int iXOffset, const int iYOffset, const int iAlpha);

	virtual void ImmediateDraw2DImagePixel     (const float* ipPoint, const CATPixelImage* ipPixelImage, const int iAlpha, const int iXOffset = 0, const int iYOffset = 0);
	virtual void ImmediateDraw2DLine           (const float* ipPoints, const int iPointCount, const int iLineType = 0, TessFlag iTessStatus = LINE);
	virtual void ImmediateDraw2DPolygon        (const float* ipPoints, const int iPointCount, const int iFill, const int iTriangleCount = 0, const int* ipType = 0, const int* ipTriangles = 0, const int* ipVertex = 0, TessFlag iTessStatus = LINE);
	virtual void ImmediateDraw2DQuadStrip      (const float* ipPoints, const int iPointCount, const float* ipVertexcolors, const CATBoolean& iFormatRGBAFlag);
	virtual void ImmediateDraw2DMarker         (const float* ipPoints, const int iPointCount, SymbolType iSymbolType);
	virtual void ImmediateDraw2DAnnotationText (const float* ipPoint, const CATUnicodeString& iText, AnchorPoint iPosition = BASE_LEFT, const float iHeight = 0.f, const int iContour = 0, const CATGraphicAttributeSet* iContour1 = NULL, const CATGraphicAttributeSet* iContour2 = NULL);
	virtual void ImmediateDrawFreeTypeText     (const CATFreeTypeTextGP* iTextGP);

	//  Matrix
	//  ------
	virtual void PopMatrix(CATRender* ipRender);

	//  Reference
	//  ---------
  virtual void PushReference();
	virtual void PopReference();

private :

	CATPickingSubEltsNoOutsideRender();
	CATPickingSubEltsNoOutsideRender & operator= (const CATPickingSubEltsNoOutsideRender &);

  virtual void SetCurrentAttribute(const CATGraphicAttributeSet&, const int iType);
  virtual void SetCurrentAttribute(const CATGraphicAttributeSet&);
  void SetCurrentPath(const CATRep*);
	int IsTriangleInside(const float *p1, const float *p2, const float *p3);
	void AddPickPathAsNotSelected();

	void ComputeSubEltsVisibility(list<CATViewpoint>& iViewpointList);
	void CreateSupport();
	void DrawPickPath(CATSupport* iprSupport, CATPickPathList& iPickPathList, list<CATViewpoint>& iViewpointList, unsigned int iColorInc, CATListOfInt& oPickPathColorList);
	void ReframeViewpoint(CAT3DViewpoint* iprViewpoint3D);
	static unsigned int HashFunction(const void* iEntry);
	static int CompareFunction(const void* iEntry1, const void* iEntry2);
	void GetDrawnColors(CATPixelImage* iprPixelImage, CATHashTable& oDrawnColorHashTable, list<unsigned int>& oEntryList);
	void GetVisiblePickPath(CATPickPathList& iPickPathList, const CATListOfInt& iPickPathColorList, const CATHashTable& iDrawnColorHashTable, CATPickPathList& oPickPathList);

	CATBoolean _pickingSubEltsOutsideClippedViewpoint;
	int _subEltsCount;
	CATBoolean _IsRepDrawn;
	CATPickingSubEltsNoOutsideMode _subEltsNoOutsideMode;
	CATSupport* _pSupport;
	CATPixelImage* _pPixelImage;
	const CATRep* _prRepWithoutSubEltsPicking;
	int _allowAddCurrentPath;
	int _previousAllowAddPickPath;
	int _OkToAddForGlobalElt;
};

#endif
