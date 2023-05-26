// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVizSurfacicRepProxy.h
// Header definition of CATVizSurfacicRepProxy
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2003  Creation: Code generated by the CAA wizard  jut
//===================================================================
#ifndef CATVizSurfacicRepProxy_H
#define CATVizSurfacicRepProxy_H

#include "SGInfra.h"
#include "CATVizVertexBufferRep.h"
#include "CATVizPtrList.h"
#include <string.h>

class CAT3DGeomRep;
class CATVizPrimitive;
class CATCGRRep;
class CATRender;
class CATOutlineBuilder;
class CATGraphicAttributeSet;
class vImplDrawable_CATVizSurfacicRepProxy;
class CATProtocolLODUpdateSurfacicRepProxy;

//-----------------------------------------------------------------------

/**
* Describe your class here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
*/
class ExportedBySGInfra CATVizSurfacicRepProxy: public CATVizVertexBufferRep
{
  friend class vImplDrawable_CATVizSurfacicRepProxy;
  friend class CATProtocolLODUpdateSurfacicRepProxy;
  CATDeclareClass;
   
public:
   
   // Standard constructors and destructors
   // -------------------------------------

  static CATVizSurfacicRepProxy* CreateRep();

protected:

   CATVizSurfacicRepProxy ();

public:

   virtual ~CATVizSurfacicRepProxy ();
   
   void BuildFrom(CAT3DGeomRep *iRep, int allocmode=1);

   virtual int  GetRepPosInStreamer();
   virtual void SetRepPosInStreamer(int pos);


   // AZX: (A2X migration) Making draw functions final 
   virtual void DrawShading(CATRender&, int) override final;
   virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
   virtual void Draw(CATRender& iRender, int iInside) override final;
   virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

   virtual int IsAProxy();

   void     SwitchTo(CATVizSemanticLevel iTargetLevel);
   CATRep * SwitchToFull();

   CATCGRRep * GetCGRRep();
	
	virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);


  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

protected:
  // Managing outlines:
  // ------------------
  //   The graphical attribute that should be used for outlines is the same as
  //   the one used for all edges of the representation.

  /** @nodoc */
  CATOutlineBuilder      *GetOutlineBuilder(void);


  void DrawPath_Outlines1st(CATRender& render, CATGraphicAttributeSet const& att_dmu, CATGraphicAttributeSet*& dominant_att, CATGraphicAttributeSet& oAttOut, CATOutlineBuilder*& oBuilder, int& oNbSegments, float*& oLines, int**& oId);

  void DrawPath_Outlines2nd(CATRender& render, CATGraphicAttributeSet const& att_dmu, CATGraphicAttributeSet const& iAttOut, int iNbSegments, float* iLines, bool iFurtif);

  //NB : The calling function has to call ViewMode(VIEW_OUTLINE) to check for the mode.
  void DrawOutlines(CATRender& render, CATGraphicAttributeSet*& att_dmu, CATGraphicAttributeSet*& dominant_att);

  void ComputeAttDMU(CATRender& render, CATGraphicAttributeSet*& att_dmu, CATGraphicAttributeSet*& dominant_att);

  int HasTransparencyFace(CATRender &render);

  void SetInheritElementType(CATGraphicAttributeSet const& pGA, CATRender &render);

  /** @nodoc */
  CATGraphicAttributeSet     GeomDrawingEdgeAttribute(CATRender &render,
    CATVizGeomType edge_type,
    CATGraphicAttributeSet **iopDominant_att = NULL) const;

  /** @nodoc */
  void MergeColorsInFirst(CATGraphicAttributeSet* att_edge, CATGraphicAttributeSet** dominant_att);

  void     CommitSwitch(TemporarySwitchData* iTemporaryData = NULL);

private:

   // Copy constructor and equal operator
   // -----------------------------------
   CATVizSurfacicRepProxy (CATVizSurfacicRepProxy &);
   CATVizSurfacicRepProxy& operator=(CATVizSurfacicRepProxy&);

   CATVizPtrList<CATVizPrimitive> * _primitivesToDestroy;
   /** @nodoc */
   CATOutlineBuilder          *_builder;             // Outline generator.

   int _repPosInStreamer;
};



//-----------------------------------------------------------------------

#endif