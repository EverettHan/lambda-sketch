// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyExportVizLayer.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008 Creation: ZFI
// December 2018 Modification JXO: ReportCGMIdsToGPs
//===================================================================

#ifndef CATPolyBodyExportVizLayer_H
#define CATPolyBodyExportVizLayer_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"


class CATMapOfPtrToPtr;
class CATPolyBody;
class CATSurfacicRep;
class CATGraphicMaterial;
class CATPolyCell;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class CATMapOfPtrToPtr;
class VisPrimitiveGroupRep;
class IVisSG3DPrimitive;
class CAT3DRep;

class ExportedByPolyVizLayers CATPolyBodyExportVizLayer
{
public:
  //constrctor and destructor
  CATPolyBodyExportVizLayer ();
  virtual ~CATPolyBodyExportVizLayer ();

public:

  //INIT
  HRESULT Init();

  //POLYBODY MAPPING
  HRESULT EnablePolyBodyMapping();
  HRESULT DisablePolyBodyMapping();
  CATBoolean PolyBodyMapping() {return _PolyBodyMapping;}

  HRESULT Set(const CATSurfacicRep* iRep, const CATPolyBody* iPolyBody);
  HRESULT Get(const CATSurfacicRep*& iRep, CATPolyBody*& oPolyBody) const;

  //POLYCELL MAPPING
  HRESULT EnablePolyCellMapping();
  HRESULT DisablePolyCellMapping();
  CATBoolean PolyCellMapping() {return _PolyCellMapping;}

  HRESULT Set(const CATSurfacicRep* iRep, const CATGraphicPrimitive* iGP, const CATPolyCell* iPolyCell);
  HRESULT Get(const CATSurfacicRep* iRep, const CATGraphicPrimitive* iGP, CATPolyCell*& oPolyCell) const;

  HRESULT Set(const CAT3DRep* iRep, const void* iVP, const CATPolyCell* iPolyCell);
  HRESULT Get(const CAT3DRep* iRep, const void* iVP, CATPolyCell*& oPolyCell) const;

  //GP Mapping
  HRESULT EnableGPMapping();
  HRESULT DisableGPMapping();
  CATBoolean GPMapping() {return _GPMapping;}

  HRESULT Set(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, const CATGraphicPrimitive* iGP);
  HRESULT Get(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, CATGraphicPrimitive*& oGP) const;


  HRESULT Set(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, const void* iVP);
  HRESULT Get(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, void*& oVP) const;

  void ReportCGMIdsToGPs(const CATPolyBody & iBody);

private:
  CATBoolean _PolyBodyMapping, _PolyCellMapping, _GPMapping;

  CATMapOfPtrToPtr* _Rep2PolyBody;
  CATMapOfPtrToPtr*_GP2PolyCellMap;
  CATMapOfPtrToPtr* _PolyBody2GPMap;
};

#endif
