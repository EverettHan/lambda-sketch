#ifndef CATTessV4POL_h
#define CATTessV4POL_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1999
//
// CATTessV$POL
//
// DESCRIPTION :
// 
// Extraction a partir d'une face V5 d'une description polyedrique V4
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Mar. 99 HKL Creation
// Sep. 99 HKL Gestion des wires (RI234240A)
// Sep. 2000 TPD On veut des POL avec ou sans (conique) PLL
// Mars 2002 TPD On calcule la taille des listes des faces et des edges pour le HLR
// Aout 2003 SGE passage en 64 bits 
//
//=============================================================================

#include "TessAPI.h"
#include "CATTessStore.h"

#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "ListPOfCATCell.h"
#include "CATCGMNewArray.h"

class CATTessSettings;
class CATTessOutHlr;

class CATFace;
class CATBody;
class CATMathDirection;
class CATTessObjectLinker;

class ExportedByTessAPI CATTessV4POL : public CATTessStore
{
public:
  /**
   * CONSTRUCTOR
   */
  CATTessV4POL(CATBody*iBody, CATTessSettings * iSettings, int iL4Pll);
  ~CATTessV4POL();
  
  /**
   * Retrieves the polyedral description and its size
   * The oData array should be freed by the caller
   */
  void GetNbData(CATLONG32 & oSizeOfData);
  // On remplit TabPol ( il doit être alloué )
  CATLONG32 GetData(CATLONG32  iSizeOfData, double * oTabPol);

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

protected:
  CATLONG32               _SizefacesData, _SizeedgesData, _SizeedgesBarData; 
  ListPOfCATCell     _computedFaces, _computedEdges;

  CATListOfInt       _facesData ;

  CATListPV          _edgesBarData;

  CATListOfInt       _edgesData ;

  CATListOfDouble    _ptData;

  CATTessObjectLinker * _edgeTable[2];
  CATTessObjectLinker * _edgeFaceTable[2];
  CATTessObjectLinker * _faceToPol;


  CATBody          * _body;
  CATTessSettings  * _settings;

  int                _initialized;
  int                _numPol;
  int                _LPass;

  void StoreFace(CATFace * iFace, CATTessOutHlr * iOutHlr);
  void BuildEdgeData();
  void BuildWireData();
  
};

#endif
