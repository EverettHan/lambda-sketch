#ifndef CATUVOutlineCell_h
#define CATUVOutlineCell_h

#include "CATVizPtrList.h"
#include "CAT3DLineGP.h"

typedef enum
{
  UNINITIALIZED = 0x00,
  FRONT     = 0x01,
  BACK      = 0x02,
  MIXED     = 0x03,
} UVOutlineTriangleStatus;

//----------------------------------------------------------------------------------------
//
//                                     CATUVOutlineCell
//
//----------------------------------------------------------------------------------------

class CATUVOutlineCell
{
  friend class CATUVOutlineConnectivityMatrix;
  
public:

  CATUVOutlineCell();
  CATUVOutlineCell(unsigned int iIndex1, unsigned int iIndex2, UVOutlineTriangleStatus itriangleStatus);
  CATUVOutlineCell(unsigned int iIndex1,
    unsigned int iIndex2,
    float *internalVertex,
    unsigned int nbInternalVertex,
    UVOutlineTriangleStatus *itriangleStatus,
    unsigned int nbTriangleStatus);
  virtual ~CATUVOutlineCell();

  void ReInit(unsigned int iIndex1, unsigned int iIndex2, UVOutlineTriangleStatus itriangleStatus);
  void SwapMe();

	inline unsigned int Index1() const;
	inline unsigned int Index2() const;
  inline void SetIndex1(unsigned int i);
	inline void SetIndex2(unsigned int i);
	inline CATUVOutlineCell* GetNextColumnCell() const;
	inline void SetNextColumnCell(CATUVOutlineCell *iCell);
  
  inline void GetTriangleStatus(const UVOutlineTriangleStatus *&triangleStatus, unsigned int &size) const;
  inline unsigned int GetNbBars() const;
  inline unsigned int IsPlanar() const;
  inline const float* GetInternalVertex() const;
  
  static CATUVOutlineCell *MergeUVCells(const CATVizPtrList<CATUVOutlineCell> &iCellList, const float *vertex);
  static void BuildOutlinesOnUVCells(
  unsigned int iI11, unsigned int iI12, unsigned int iNbBars1, const float *iInternalVertices1, unsigned int iNbTStatus1, const UVOutlineTriangleStatus * iTStatus1, const float *iVB1,
  unsigned int iI21, unsigned int iI22, unsigned int iNbBars2, const float *iInternalVertices2, unsigned int iNbTStatus2, const UVOutlineTriangleStatus * iTStatus2, const float *iVB2,
  float *&oVertices,  unsigned int &oNbPoints, int &oLineType);

private:
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
	CATUVOutlineCell (const CATUVOutlineCell &);
	CATUVOutlineCell & operator= (const CATUVOutlineCell &);

  
private:

  unsigned int	_index[2];

	unsigned int	_planar				: 1;
	unsigned int	_toTesselate	: 1;
	unsigned int	_nbBars				:30;

  float *_internalVertex;
  
  union triangle
  {
    UVOutlineTriangleStatus *list;
    UVOutlineTriangleStatus  single;
  } _triangle;
	
	CATUVOutlineCell	*_pNextIndex2;//Pointer on the next matrix element on the next Cell with a superior _Index1
};

inline unsigned int CATUVOutlineCell::Index1() const {return _index[0];};
inline unsigned int CATUVOutlineCell::Index2() const {return _index[1];};
inline void CATUVOutlineCell::SetIndex1(unsigned int i) {_index[0]=i;};
inline void CATUVOutlineCell::SetIndex2(unsigned int i) {_index[1]=i;};

inline CATUVOutlineCell*  CATUVOutlineCell::GetNextColumnCell()	const {return _pNextIndex2;};
inline void CATUVOutlineCell::SetNextColumnCell(CATUVOutlineCell* iCell) {_pNextIndex2=iCell;};

inline unsigned int CATUVOutlineCell::IsPlanar() const {return _planar;};
inline unsigned int CATUVOutlineCell::GetNbBars() const {return _nbBars;};
inline void CATUVOutlineCell::GetTriangleStatus(const UVOutlineTriangleStatus *&triangleStatus, unsigned int &size) const
{
  if (_planar)
  {
    triangleStatus = &(_triangle.single);
    size = 1;
  }
  else
  {
    triangleStatus = _triangle.list;
    size = _nbBars;
  }
};
inline const float * CATUVOutlineCell::GetInternalVertex() const {return _internalVertex;};

//----------------------------------------------------------------------------------------
//
//                                     CATUVOutlineCellPool
//
//----------------------------------------------------------------------------------------

class CATUVOutlineCellPool
{
public:
  CATUVOutlineCellPool(unsigned int iSize);
  virtual ~CATUVOutlineCellPool();
  inline void AddCell(CATUVOutlineCell *iCell);
  inline CATUVOutlineCell* GetCell();
  inline void AddRef();
  inline void Release();

private:
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
	CATUVOutlineCellPool();
  CATUVOutlineCellPool (const CATUVOutlineCell &);
	CATUVOutlineCellPool & operator= (const CATUVOutlineCell &);

  CATVizPtrList<CATUVOutlineCell> _cellList;
  unsigned int _nbRef;

  unsigned int _limitSize;//pour essayer d'eviter les reallocate trop frequents lors des addCell
                          //en particulier si une grosse matrice est detruite elle va essayer
                          //de mettre toutes ces cellules dans le pool et cela va creer trop
                          //de reallocate sur la liste.
                          //soit j'augmente la pas d'allocation au fur et a mesure soir je limite
                          //la taille de la liste (ici 400 en dur dans le constructeur)
};

inline CATUVOutlineCell *CATUVOutlineCellPool::GetCell()
{ 
  return _cellList.RemoveAt(_cellList.Length()-1);
};
inline void CATUVOutlineCellPool::AddCell(CATUVOutlineCell *iCell)
{
  if (iCell && _cellList.Length()<_limitSize)
    _cellList.AddTail(iCell);
  else
  {
    delete iCell;
    iCell = NULL;
  }
};
inline void CATUVOutlineCellPool::AddRef() {_nbRef++;};
inline void CATUVOutlineCellPool::Release()
{
  if (_nbRef>=1)
  {
    _nbRef--;
    if(_nbRef==0)
      delete this;
  }
};

#endif
