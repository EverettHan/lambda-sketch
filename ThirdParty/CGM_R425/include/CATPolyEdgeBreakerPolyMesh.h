// Creation: November 2021 - TCT5

#ifndef _AIX_SOURCE

#ifndef CATPolyEdgeBreakerPolyMesh_h
#define CATPolyEdgeBreakerPolyMesh_h

#include "PolyStream.h"

#include "CATSysErrorDef.h"
#include "CATDataType.h"

class CATIPolyMesh;
class CATPolyEdgeBreakerCornerTable;
class CATPolyEdgeBreakerStreamable;

#include <vector>
#include <unordered_map>

class ExportedByPolyStream CATPolyEdgeBreakerPolyMesh
{
public:
  CATPolyEdgeBreakerPolyMesh();
  virtual ~CATPolyEdgeBreakerPolyMesh();

public:
  /**
  * Return value:
  * -S_OK: OK to compress
  * -S_FALSE: Do not attempt to compress
  * -E_FAIL: Something went wrong
  */
  HRESULT CheckMeshCompatibility(const CATIPolyMesh& iMesh, const CATULONG64 iOptions, const CATULONG32 iVersion);

  /**
* Return value:
* -S_OK: EdgeBreaker is likely to yield a good compression ratio
* -S_FALSE: Compression ratio will probably be disappointing, consider using a DEFLATE/LZMA-based approach instead
* -E_FAIL: Something went wrong
*/
  HRESULT CheckIfEdgeBreakerIsRelevant(const CATIPolyMesh &iMesh, const unsigned int iNbOfVerticesToCheck = 2000);

  HRESULT Compress(const CATIPolyMesh &iMesh, CATPolyEdgeBreakerStreamable &ioStreamable);
  HRESULT Uncompress(const CATPolyEdgeBreakerStreamable &iStreamable, CATIPolyMesh &oMesh);

public:  /* For debug purpose only */
  void SetKeepCornerTable(bool iKeepCornerTable);
  CATPolyEdgeBreakerCornerTable* GetCornerTable();

protected:
  HRESULT PolyMeshToCornerTable(const CATIPolyMesh &iMesh, CATPolyEdgeBreakerCornerTable *&opCornerTable, bool iPersistIndices);
  HRESULT CornerTableToPolyMesh(const CATPolyEdgeBreakerCornerTable &iCornerTable, const CATPolyEdgeBreakerStreamable &iStreamable, int iNbSplitVertices, CATIPolyMesh &oMesh);

protected:
  std::vector<int> m_CornerTableVerticesToUnstreamVertices;

  /* For debug purpose only */
  bool m_DoKeepCornerTable;
  CATPolyEdgeBreakerCornerTable* m_pSavedCornerTable;
};

#endif // !CATPolyEdgeBreakerPolyMesh_h

#endif // AIX
