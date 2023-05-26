// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyImportVizLayer.h
//
//===================================================================
// August 2008 Creation: ZFI
//===================================================================
#ifndef CATPolyBodyImportVizLayer_H
#define CATPolyBodyImportVizLayer_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATPolyBodyVisLayerSet.h"
#include "CATPolyBodyVisLayer.h"
#include "CATMapOfPtrToInt.h"

class CATMapOfPtrToPtr;
class CATPolyBody;
class CAT3DRep;
class CATGraphicMaterial;
class CATPolyCell;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class CATMapOfPtrToPtr;
class CATPolyFace;


class ExportedByPolyVizLayers CATPolyBodyImportVizLayer
{
public:
  //constrctor and destructor
  CATPolyBodyImportVizLayer ();
  virtual ~CATPolyBodyImportVizLayer ();

public:

  /**
   * Returns a CATPolyBodyVisLayerSet instance.
   */
  inline const CATPolyBodyVisLayerSet& GetPolyBodyVisLayerSet () const;

  /**
   * Returns a CATPolyBodyVisLayer for a CATPolyBody.  CATPolyBodyVisLayerSet
   */
  const CATPolyBodyVisLayer* GetPolyBodyVisLayer (const CATPolyBody* iPolyBody) const;

  /**
   * Returns a CATPolyBodyVisLayer for a CATPolyBody.
   * It adds one if there is none.
   */
  CATPolyBodyVisLayer* FetchPolyBodyVisLayer (const CATPolyBody* iPolyBody);

public:

  //INIT
  HRESULT Init();

  //REP MAPPING
  HRESULT EnableRepMapping();
  HRESULT DisableRepMapping();
  CATBoolean RepMapping() const {return _RepMapping;}

  HRESULT Set(const CATPolyBody* iPolyBody, const CAT3DRep* iRep);
  HRESULT Get(const CATPolyBody* iPolyBody, CAT3DRep*& oRep) const;

  // Association of CATGraphicAttributeSet to a CATPolyBody.
  // (NDO, October, 18, 2012)
  HRESULT Set (const CATPolyBody* iPolyBody, const CATGraphicAttributeSet* iGA);
  HRESULT Get (const CATPolyBody* iPolyBody, const CATGraphicAttributeSet*& oGA) const;

  //GRAPHIC MATERIAL MAPPING
  HRESULT EnableGMMapping();
  HRESULT DisableGMMapping();
  CATBoolean GMMapping() const {return _GMMapping;}

  HRESULT Set (const CATPolyBody* iPolyBody, const CATGraphicMaterial* iGM);
  HRESULT Get (const CATPolyBody* iPolyBody, CATGraphicMaterial*& oGM) const;
  HRESULT Get(const CATPolyBody* iPolyBody, const CATPolyFace* iPolyFace, CATGraphicMaterial*& oGM) const;

  //GRAPHIC PRIMITIVE MAPPING
  HRESULT EnableGPMapping();
  HRESULT DisableGPMapping();
  CATBoolean GPMapping() const{return _GPMapping;}

  HRESULT Set(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, const CATGraphicPrimitive* iGP);
  HRESULT Get(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, CATGraphicPrimitive*& oGP) const;

  //DIRECT PRIMITIVE MAPPING
  HRESULT EnableDirectGPMapping();
  HRESULT DisableDirectGPMapping();
  CATBoolean DirectGPMapping() const{return _DirectGPMapping;}

  HRESULT Set(const CATPolyCell* iPolyCell, const CATGraphicPrimitive* iGP);
  HRESULT Get(const CATPolyCell* iPolyCell, CATGraphicPrimitive*& oGP) const;

  //GRAPHIC ATTRIBUTE MAPPING
  HRESULT EnableGAMapping();
  HRESULT DisableGAMapping();
  inline CATBoolean GAMapping() const{ return _GAMapping;} 

  HRESULT Set(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, const CATGraphicAttributeSet& iGA);
  HRESULT Get(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, CATGraphicAttributeSet& oGA) const;
  
  //DIRECT GRAPHIC ATTRIBUTE MAPPING
  HRESULT EnableDirectGAMapping();
  HRESULT DisableDirectGAMapping();
  inline CATBoolean DirectGAMapping() const{ return _DirectGAMapping;} 

  HRESULT Set(const CATPolyCell* iPolyCell, const CATGraphicAttributeSet& iGA);
  HRESULT Get(const CATPolyCell* iPolyCell, CATGraphicAttributeSet& oGA) const;


  //DIRECT GRAPHIC MATERIAL FOR CELLS MAPPING
  HRESULT EnableDirectCellGMMapping();
  HRESULT DisableDirectCellGMMapping();
  inline CATBoolean DirectCellGMMapping() const{ return _DirectCellGMMapping;} 

  HRESULT Set(const CATPolyCell* iPolyCell, CATGraphicMaterial* iGraphicMaterial);
  HRESULT Get(const CATPolyCell* iPolyCell, CATGraphicMaterial*& oGraphicMaterial) const;

  // Sharpness - don't use
  int GetSharpness(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell) const;
  void SetSharpness(const CATPolyBody* iPolyBody, const CATPolyCell* iPolyCell, int sharpness);

private:

  CATBoolean _RepMapping, _GMMapping, _GPMapping, _GAMapping, _DirectGPMapping, _DirectGAMapping, _DirectCellGMMapping;

  CATPolyBodyVisLayerSet _PBVisLayerSet;

  CATMapOfPtrToPtr* _PolyBody2GPMap;

  CATMapOfPtrToPtr* _PolyCell2GPMap;
  CATMapOfPtrToPtr* _PolyCell2GAMap;
  CATMapOfPtrToInt  _PolyCell2SharpMap;
  CATMapOfPtrToPtr* _PolyCell2GMMap;

private:

  /**
   * Adds a CATPolyBodyVisLayer for a CATPolyBody.
   */
  CATPolyBodyVisLayer* AddPolyBodyVisLayer (const CATPolyBody* iPolyBody);

};


inline const CATPolyBodyVisLayerSet& CATPolyBodyImportVizLayer::GetPolyBodyVisLayerSet () const
{
  return _PBVisLayerSet;
}


#endif
