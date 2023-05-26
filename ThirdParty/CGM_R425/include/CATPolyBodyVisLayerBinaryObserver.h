/**
 * @fullreview JXO 15:05:15
 * @fullreview XXC 5:2017 Add NAryObserver support
 * @fullreview XXC 3:7:2017 Add certification tests for unedited cells
 */

// COPYRIGHT DASSAULT SYSTEMES 2015
#include "PolyVizLayers.h"

// Polyhedral
#include "CATPolyBodyBinaryObserver.h"
#include "CATPolyBodyNaryObserver.h"
#include "CATPolyBodyVisLayer.h"
#include "CATPolyBody.h"
#include "CATPolyCell.h"
#include "CATMapOfPtrToPtr.h"

class CATGraphicAttributeSet;
class CATIPolyIndexIterator;
class CATIPolyVertexPositionConstLayer;
class CATPolyBodyOperandCells;


class ExportedByPolyVizLayers CATPolyBodyVisLayerBinaryObserver : public CATPolyBodyBinaryObserver
{
public:
  enum UneditionTestResult
  {
    SuccessUnedition = 0,
    Fail_WrongNumberOfVertices,
    Fail_NullIterator,
    Fail_NullCoordinateLayer,
    Fail_WrongIteratorLayer,
    Fail_WrongPositionOrMap
  };

public:

  CATPolyBodyVisLayerBinaryObserver (const CATPolyBodyVisLayer* iVisLayer0, const CATPolyBodyVisLayer* iVisLayer1,
                                      CATPolyBodyVisLayer& oVisLayer);

  ~CATPolyBodyVisLayerBinaryObserver ();

public:

  void Begins (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, const int iTag0,
               const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1, const int iTag1);

  void BeginEdge () {}

  void EndVertex (CATPolyVertex* vertex, CATPolyCell* iCellOperand0, CATPolyCell* iCellOperand1);
  void EndEdge (CATPolyEdge* edge, CATPolyCell* iCellOperand0, CATPolyCell* iCellOperand1);
  void EndFace (CATPolyFace* face, CATPolyFace* iFaceOperand0, CATPolyFace* iFaceOperand1);

public:

  void UneditedSurface (CATPolyFace& iResultFace, 
                        const CATPolyFace& iInputFace, const CATPolyBody& iInputBody, const int iInputTag, 
                        int orientation, const CATMapOfIntToInt* vertexMap);

  void UneditedCurves (CATPolyEdge& iResultEdge, 
                       const CATPolyEdge& iInputEdge, const CATPolyBody& iInputBody, const int iInputTag,
                       int iOrientation);

  void UneditedPoints (CATPolyVertex& iResultVertex, 
                       const CATPolyVertex& iInputVertex, const CATPolyBody& iInputBody, const int iInputTag);

public:

  inline unsigned int GetNbMissingEdges () {return _CountMissingEdges;}

  inline unsigned int GetNbUneditedSurfaces () {return _CountUneditedSurfaces;}

  inline UneditionTestResult TestEditionOfUneditedCells () { return _CertifiedUnedited; }

  inline const CATPolyBody* GetPolyBody (unsigned int k) { return _PolyBody[k]; }

  inline const CATMathTransformation* GetPolyBodyPosition (unsigned int k) { return _PolyBodyPosition[k]; }

private:

  const CATPolyBodyVisLayer* _VisLayer0;
  const CATPolyBodyVisLayer* _VisLayer1;
  CATPolyBodyVisLayer& _VLResult;
  unsigned int _CountMissingEdges;
  unsigned int _CountUneditedSurfaces;
  UneditionTestResult _CertifiedUnedited;

  const CATPolyBody* _PolyBody[2];
  const CATMathTransformation* _PolyBodyPosition[2];
  int _Tag[2];

private:

  void EndCell (CATPolyCell* iResultCell, CATPolyCell* iCellOperand0, CATPolyCell* iCellOperand1);

  void TestUneditedVertices(CATIPolyIndexIterator & iResultIter, CATIPolyVertexPositionConstLayer & iResultPos,
                            CATIPolyIndexIterator & iInputIter, CATIPolyVertexPositionConstLayer & iInputPos,
                            const CATMapOfIntToInt* vertexMap, int orientation);

public:

  int m_DefaultIsIntersection;
  int m_MarkIntersection;
  CATGraphicAttributeSet& m_gaForIntersections;
  CATMapOfPtrToInt m_SetOfUneditedCells;

};


class ExportedByPolyVizLayers CATPolyBodyVisLayerNaryObserver : public CATPolyBodyNaryObserver
{

public:

  CATPolyBodyVisLayerNaryObserver (CATListPV & iPolyBodies, CATListPV & iVisLayers, CATPolyBodyVisLayer & oVisLayer);

  ~CATPolyBodyVisLayerNaryObserver ();

public:

  void Result(CATPolyBody& iPolyBody, const CATMathTransformation* iPosition);

  void EndVertex (CATPolyVertex* vertex, CATPolyBodyOperandCellIterator* iCellsOperand);

  void EndEdge (CATPolyEdge* edge, CATPolyBodyOperandCellIterator* iCellsOperand);

  void EndFace (CATPolyFace* face, CATPolyBodyOperandCellIterator* iFacesOperand);

  void UneditedSurface (CATPolyFace& iResultFace, 
                        const CATPolyFace& iInputFace, const CATPolyBody& iInputBody, const int iInputTag,
                        int iOrientation, const CATMapOfIntToInt* iVertexMap);

  void UneditedCurves (CATPolyEdge& iResultEdge, 
                       const CATPolyEdge& iInputEdge, const CATPolyBody& iInputBody, const int iInputTag,
                       int iOrientation);

  void UneditedPoints (CATPolyVertex& iResultVertex, 
                       const CATPolyVertex& iInputVertex, const CATPolyBody& iInputBody, const int iInputTag);

  inline unsigned int GetNbUneditedSurfaces () {return _CountUneditedSurfaces;}

private:

  void EndCell (CATPolyCell* iResultCell, CATPolyBodyOperandCells* iOperandCells);

  void GetPolyCellHistory(CATPolyCell * iCell, CATPolyBodyOperandCells*& oCells);

private:

  CATMapOfPtrToPtr _MapBodyToVisLayer;
  CATMapOfPtrToPtr _MapCellsHistory;
  CATMapOfPtrToInt _SetOfUneditedCells;
  CATPolyBodyVisLayer& _VLResult;
  unsigned int _CountUneditedSurfaces;
  bool _PartialUnedited;

public:

  int m_DefaultIsIntersection;
  int m_MarkIntersection;
  CATGraphicAttributeSet& m_gaForIntersections;

};
