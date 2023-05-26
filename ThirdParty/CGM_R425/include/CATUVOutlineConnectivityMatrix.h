#ifndef CATUVOutlineConnectivityMatrix_h
#define CATUVOutlineConnectivityMatrix_h

//COPYRIGHT DASSAULT SYSTEMES 2009

//------------------------------------------------------------------------------
//  Abstract:
//  ---------
//    When parsing an array of points in order to build tesselation edges,
//    we need to know what tesselation edge has already been built in order
//    to get a structure of single tesselation edges.
//    The easiest way to do this is to build a Matrix, in which each (i, j) couple
//    represents a points couple, and each M(i,j) is the address of the corresponding
//    tesselation edge. At a first glance, we can notice that we get there a symetric matrix.
//    So, a first way to save memory, would be to store only the superior triangular part
//    of the regular matrix. But it's not enough.
//    The good solution id to build a "hollow matrix". This matrix is in fact
//    an array representing the ligns and each case of this arrays holds the couple
//    representing which column of that lign are filed and what they hold.
//    So basically we have an array of lists.
//
//------------------------------------------------------------------------------
//  Usage:
//  ------
//    
//
//------------------------------------------------------------------------------
//  Inheritance:
//  ------------
//                 
//
//------------------------------------------------------------------------------
//  Main Methods:
//  -------------
//------------------------------------------------------------------------------

#include "CATUVOutlineCell.h"
#include "CATVizVertexBuffer.h"
#include "CATBooleanDef.h"

//----------------------------------------------------------------------------------------
//
//                                  CATUVOutlineConnectivityMatrix
//
//----------------------------------------------------------------------------------------

class CATUVOutlineConnectivityMatrix
{
public:

  //Constructor
  CATUVOutlineConnectivityMatrix(CATVizVertexBuffer *iVB, unsigned int iNbVertices, CATUVOutlineCellPool *iPool = NULL);
  CATUVOutlineConnectivityMatrix(const float *vertices, unsigned int nbVertices, CATUVOutlineCellPool *iPool = NULL);

  //Destructor
  virtual ~CATUVOutlineConnectivityMatrix();

  //Adds a cell to the connectivity matrix
  void AddCell(CATUVOutlineCell *iCell, float *& oVertices, unsigned int &oNbPoints, int &oLineType);

  void ManageSimpleCell(unsigned int i, unsigned int j, UVOutlineTriangleStatus iStatus, float *& oVertices, unsigned int &oNbPoints, int &oLineType);

  //Get a cell identified by its index
  //return cell or NULL if not found
  //if iDetachCell is set to TRUE, the cell will be detach from matrix (!!_matrix can be NULL after such an operation!!)
  CATUVOutlineCell *GetCell(unsigned int i, unsigned int j, boolean iDetachCell=FALSE);

  //Get a the first whose one of index is i
  //return cell or NULL if not found
  //if iDetachCell is set to TRUE, the cell will be detach from matrix (!!_matrix can be NULL after such an operation!!)
  CATUVOutlineCell *GetFirstCell(unsigned int i, boolean iDetachCell=FALSE);

  inline const float * GetVertexArray() const;
  inline CATVizVertexBuffer * GetVertexBuffer() const;

  inline void AddRef();
  inline void Release();

private:

  CATUVOutlineConnectivityMatrix ();
  CATUVOutlineConnectivityMatrix (const CATUVOutlineConnectivityMatrix &);
  CATUVOutlineConnectivityMatrix & operator= (const CATUVOutlineConnectivityMatrix &);

  inline CATUVOutlineCell *BuildCell(unsigned int i, unsigned int j, UVOutlineTriangleStatus iStatus); 

    //Adds a cell to the connectivity matrix
  void InternalAddCell(unsigned int i, unsigned int j, UVOutlineTriangleStatus iStatus, CATUVOutlineCell *iCell, float *& oVertices, unsigned int &oNbPoints, int &oLineType);
  inline void DetachCell(CATUVOutlineCell *iCellToDetach, unsigned int iLine, CATUVOutlineCell *iPreviousColumnCell, CATUVOutlineCell *iNextColumnCell);

  void GenerateOutlines (const CATUVOutlineCell *iCell1, const CATUVOutlineCell *iCell2, float *& oVertices, unsigned int &oNbPoints, int &oLineType) const;
  void GenerateOutlines (const CATUVOutlineCell *iCell1, unsigned int i, unsigned int j, UVOutlineTriangleStatus iStatus, float *& oVertices, unsigned int &oNbPoints, int &oLineType) const;

  CATUVOutlineCell         **_matrix;
  unsigned int              _nbLines;
  
  CATUVOutlineCellPool      *_cellPool;
  CATVizVertexBuffer        *_vb;
  const float               *_vertices;

  unsigned int _nbRef;
};

inline const float * CATUVOutlineConnectivityMatrix::GetVertexArray() const
{
  if (_vertices)  return _vertices;
  else if (_vb)   return _vb->GetVerticesReadOnly();
  else            return NULL;
};
inline CATVizVertexBuffer * CATUVOutlineConnectivityMatrix::GetVertexBuffer() const {return _vb;};
inline void CATUVOutlineConnectivityMatrix::DetachCell(CATUVOutlineCell *iCellToDetach, unsigned int iLine, CATUVOutlineCell *iPreviousColumnCell, CATUVOutlineCell *iNextColumnCell)
{
  if (!iCellToDetach) return;

  if (iPreviousColumnCell)
    iPreviousColumnCell->SetNextColumnCell(iNextColumnCell);
  else
    _matrix[iLine] = iNextColumnCell;
  
  iCellToDetach->SetNextColumnCell(NULL);
}

inline CATUVOutlineCell *CATUVOutlineConnectivityMatrix::BuildCell(unsigned int i, unsigned int j, UVOutlineTriangleStatus iStatus)
{
  CATUVOutlineCell *newCell = (_cellPool) ? _cellPool->GetCell() : NULL;
  if (newCell)
  {
    newCell->ReInit(i, j, iStatus);
    return newCell;
  }
  else
    return new CATUVOutlineCell(i,j,iStatus);
}

inline void CATUVOutlineConnectivityMatrix::AddRef() {_nbRef++;};
inline void CATUVOutlineConnectivityMatrix::Release()
{
  if (_nbRef>=1)
  {
    _nbRef--;
    if(_nbRef==0)
      delete this;
  }
};

#endif
