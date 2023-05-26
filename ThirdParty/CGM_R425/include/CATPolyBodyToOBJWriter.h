// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyToOBJWriter.h
//
//===================================================================
// Mars 2009 Creation: zfi
//===================================================================
#ifndef CATPolyBodyToOBJWriter_h
#define CATPolyBodyToOBJWriter_h

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"

class CATUnicodeString;
class CATPolyBody;
class CAT4x4Matrix;

class CATPolyBodyVisLayerSet;
class CATPolyBodyVisLayer;


class ExportedByPolyVizUtils CATPolyBodyToOBJWriter
{

public:

  static HRESULT Write (const CATUnicodeString& iFileName, 
                        const CATListPV& iPolyBodies, 
                        const CATListPV& iPositionMatrices,
                        const CATPolyBodyVisLayerSet* iVisLayerSet = 0);

  static HRESULT Write (const CATUnicodeString& iFileName, 
                        const CATPolyBody& iPolyBody, 
                        const CAT4x4Matrix* iPositionMatrix,
                        const CATPolyBodyVisLayer* iVisLayer = 0);

private:

  static HRESULT WritePrivate (const CATUnicodeString& iFileName, 
                               const CATListPV& iPolyBodies, 
                               const CATListPV& iPositionMatrices,
                               const CATPolyBodyVisLayerSet* iVisLayerSet,
                               CATListPV& oFilesList);

  static HRESULT WritePrivate (const CATUnicodeString& iFileName, 
                               const CATPolyBody& iPolyBody, 
                               const CAT4x4Matrix* iPositionMatrix,
                               const CATPolyBodyVisLayer* iVisLayer,
                               CATListPV& oFilesList);

};

#endif
