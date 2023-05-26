#ifndef CATMonoWireRep_H
#define CATMonoWireRep_H

// COPYRIGHT DASSAULT SYSTEMES 2002

//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1996
//******************************************************************************

//******************************************************************************
//  Inheritance:
//  ------------
//              CATMonoWireRep
//                CAT3DGeomRep
//                  CAT3DRep
//                    CATRep 
//                      CATExtend (SYSTEM framework) 
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DGeomRep.h"

class CAT3DFaceGP;
class CATGraphicPrimitive;
class CAT3DEdgeGP;
class CAT3DMarkerGP;
class CAT3DLineGP;
class CATBodyIdentificators;
class CAT3DFixedArrowGP;
class CATDelegateRender;

#include "CATGraphicAttributeSet.h"

#include "CATVisMacroForInterfaces.h"
class IVisSG3DBody;

#include "CATIAV5Level.h"

//******************************************************************************
// Original geometry representation data structure:
// --------------------------------------------------------
//   
//   This structure has the following information:
//   - Array of CATGraphicPrimitives (BoundaryPoints, FreePoints, WireEdges)
//   - Number of elements for each array type
//   - Array of attributes for the FreePoints
//   - Array of attributes for the WireEdges
//   - A common attribute for all the Boundary Points
//
//******************************************************************************

/** 
 * @nodoc
 */
typedef struct
{
   CATGraphicPrimitive     ** elt[2];                  // cf CATGeomType
   int                        nbelt[2];                // nb of elements of each type
   CATGraphicAttributeSet  ** wireedge_attribut;       // 
   CATGraphicAttributeSet   * boundary_attribut;       // 

} WireRepGeometry;


/** 
 * @nodoc
 */
enum CATWireTypePos {
   CATBoundaryPointPos,
   CATWireEdgePos,
   CATMonoWireEdgeUnknownPos
};

//******************************************************************************
//*** CATMonoWireRep: **********************************************************
//******************************************************************************

/** 
* Class to define a Surfacic representation.
*/
class ExportedBySGInfra CATMonoWireRep : public CAT3DGeomRep
{
   
   /** @nodoc */
   //   friend class CATMarshallableSurfacicRep;
   /** @nodoc */
   //   friend class CATDmuStreamSurfacicRep;
   /** @nodoc */
   //   friend class CATVrmlMakerSurfacicRep;
   /** @nodoc */
   //   friend class CATVrml2MakerSurfacicRep;
   
   /** @nodoc */
   friend class CATDmuStreamMonoWireRep;
   friend class SGCGRStreamerForMonoWireRep;
   friend class SGCGRNodesFactoryA;

   CATDeclareClass;
   
   
public:

   CATVisDeclarePublicInterfaceAdhesion(CATMonoWireRep, IVisSG3DBody, CATMonoWireRepIVisSG3DBodyBOAImpl);
   
   // Construction of an empty representation and destruction:
   // --------------------------------------------------------
   
   /** @nodoc */
   static CATMonoWireRep* CreateRep();

   /** @nodoc */
   ~CATMonoWireRep (void);
   
   // Interface methods
   
   /** @nodoc */
   virtual int                              GeomNumberOfFaces    (void)                     const override;
   
   /** @nodoc */
   virtual CAT3DFaceGP            *         GeomFace             (const int num_face)       const override;
   
   /** @nodoc */
   virtual HRESULT                          GetGeomFaceAttribut  (const int num_face,CATGraphicAttributeSet& orGA)       const override;

   /** @nodoc */
   virtual HRESULT                          SetGeomFaceAttribut  (const int num_face,const CATGraphicAttributeSet& irGA) override;
   
   
   /** @nodoc */
   virtual int                              GeomNumberOfEdges    (void)                     const override;
   
   /** @nodoc */
   virtual CAT3DEdgeGP            *         GeomEdge             (const int num_edge)       const override;

   /** @nodoc */
   virtual HRESULT                          GetGeomEdgesAttribut (CATGraphicAttributeSet& orGA)       const override;

   /** @nodoc */
   virtual HRESULT                          SetGeomEdgesAttribut (const CATGraphicAttributeSet& irGA) override;


   /** @nodoc */
   virtual int                              GeomNumberOfElt      (const CATGeomType iType)  const override;
   
   /** @nodoc */
   virtual CATGraphicPrimitive    *         GeomElt              (const CATGeomType iType,
                                                                  const int num_elt)        const override;
   /** @nodoc */
   virtual HRESULT                          GetGeomEltAttribut   (const CATGeomType iType,
                                                                  const int num_elt,CATGraphicAttributeSet& orGA   )     const override;
   /** @nodoc */
   virtual HRESULT                          SetGeomEltAttribut   (const CATGeomType iType,
                                                                  const int num_elt,const CATGraphicAttributeSet& irGA  ) override;
   
   /** @nodoc */
   virtual int                              GeomNumberOfIsos     (void)                     const override;
   /** @nodoc */
   virtual CAT3DLineGP           **         GeomIso              (const int num_face,
                                                                  int *oIsoCount)           const override;
   /** @nodoc */
   virtual HRESULT                          GetGeomIsoAttribut   (const int num_iso,CATGraphicAttributeSet& orGA)       const override;

   /** @nodoc  */
   virtual HRESULT                          SetGeomIsoAttribut   (const int num_face,const CATGraphicAttributeSet& irGA) override;
   
   /** @nodoc */
   virtual HRESULT                          AddGeomFace          (CAT3DFaceGP *face,CATGraphicAttributeSet *att) override;
   
   /** @nodoc */
   virtual HRESULT                          AddGeomEdge          (CAT3DEdgeGP *edge) override;

   /** @nodoc */
   virtual HRESULT                          AddGeomIso           (CAT3DLineGP  **iIso,
                                                                  CATGraphicAttributeSet *iAtt,
                                                                  int iIsoCount) override;
   
   /** @nodoc */
   virtual HRESULT                          AddGeomElt           (const CATGeomType iType,
                                                                  CATGraphicPrimitive *iGP,
                                                                  CATGraphicAttributeSet *iAtt=NULL) override;
   /** @nodoc */
   virtual HRESULT                          ReplaceGeomElt       (const CATGeomType iType,
                                                                  CATGraphicPrimitive *iNewGP,
                                                                  const int iInd) override;
   
   /** @nodoc */
   virtual int                              IsMonoWire           (void)                      const override;

   // Drawing and texturing:
   // ----------------------
   
   /** @nodoc */
   CATGraphicAttributeSet     GeomDrawingEdgeAttribute   (CATRender &render,
                                                          CATGeomType edge_type) const;
   /** @nodoc */
   virtual void DrawShading   (CATRender &render, int inside) override final;
   /** @nodoc */
   virtual void DrawPath      (CATRender &render,int inside,CATRepPath &path) override final;
   /** @nodoc */
   virtual void Draw(CATRender& iRender, int iInside) override final;
   /** @nodoc */
   virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

   /////////////////////////////////////////END DEPRECATED METHODS ////////////////////////////////////

	 /** @nodoc */
   virtual CATGraphicPrimitive* GetGeomElement(int iIndice) override;

	 /** @nodoc */
	 virtual int GetGeomIndex(const CATGraphicPrimitive * gp) override;
   
protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CATMonoWireRep(void);

  virtual const vDrawInformation* GetDrawInformation() override;

  virtual void DrawPath_Legacy(CATRender &render, int inside, CATRepPath &path, CATDelegateRender* delRender);


protected:
   
   WireRepGeometry _geom;
   
private:
   
   // Internal functions:
   // -------------------
   
   /** @nodoc */
   void EmptyInit (void);
   
   // Internal Statics
   // ----------------

};

inline CATWireTypePos GetPosFromType(CATGeomType iType)
{
   switch (iType)
   {
   case CATBoundaryPoint:  return CATBoundaryPointPos;   break;
   case CATWireEdge:       return CATWireEdgePos;        break;
   }
   return  CATMonoWireEdgeUnknownPos;
}

#endif

