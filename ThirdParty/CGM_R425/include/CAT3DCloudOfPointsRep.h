#ifndef CAT3DCloudOfPointsRep_H
#define CAT3DCloudOfPointsRep_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract:
//    Cloud of points representation.
//
//------------------------------------------------------------------------------
// Usage:    xxxxxxxxxxx
//------------------------------------------------------------------------------
// Inheritance:
//    CAT3DCloudOfPointsRep
//      CAT3DRep
//        CATBaseUnknown (SYSTEM framework)
//------------------------------------------------------------------------------
// Main methods:
//
//------------------------------------------------------------------------------
#include "SGInfra.h"

#include "CAT3DRep.h"
#include "CAT3DMarkerGP.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG3DPrimitiveIterator;
class CAT3DCloudOfPointsRepIVisSG3DPrimitiveIteratorBOAImpl;

class ExportedBySGInfra CAT3DCloudOfPointsRep : public CAT3DRep
{
 friend class CATMarshallable3DCloudOfPointsRep;
 CATDeclareClass;
   
 public:

   CATVisDeclarePublicInterfaceAdhesion(CAT3DCloudOfPointsRep, IVisSG3DPrimitiveIterator, CAT3DCloudOfPointsRepIVisSG3DPrimitiveIteratorBOAImpl);
    
   static CAT3DCloudOfPointsRep* CreateRep();
	 static CAT3DCloudOfPointsRep* CreateRep(float points[], const int nb_points, SymbolType symbol);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DCloudOfPointsRep();
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DCloudOfPointsRep(float points[], const int nb_points, SymbolType symbol);
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DCloudOfPointsRep(float points[], const int nb_points, SymbolType symbol, CATModelIdentificator& iModelId, void* iCntl = NULL);

public:

   void SetSymbolType(SymbolType symbol);
    
protected:

   virtual ~CAT3DCloudOfPointsRep ();
  
public:
  // AZX: (A2X migration) Making draw functions final 
  virtual void DrawShading(CATRender&, int) override final;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);
     
  protected:
  virtual const vDrawInformation* GetDrawInformation();

   CAT3DMarkerGP *_Geometry3;
   
};

#endif 
