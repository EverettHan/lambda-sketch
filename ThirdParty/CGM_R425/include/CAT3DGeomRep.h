#ifndef CAT3DGeomRep_H
#define CAT3DGeomRep_H

// COPYRIGHT DASSAULT SYSTEMES 2002

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1996
//******************************************************************************
//
//  Abstract:
//  ---------
//    CAT3DGeomRep is an interface for all classes that wants to manage the 
//    following CATIA elements representations:
//      - Solids (exacts or mock-up),
//      - Volumes,
//      - Faces,
//      - Surfaces,
//      - Skins.
//
//******************************************************************************
//
//  Inheritance:
//  ------------
//                CAT3DGeomRep
//                  CAT3DRep
//                    CATRep 
//                      CATExtend (SYSTEM framework) 
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DRep.h"
#include "CATGeomType.h"

#include "CATIAV5Level.h"
#include "CATCGMScaleCategoryDef.h"

class CATBodyIdentificators;
class CATModelIdentificator;
class CATGraphicAttributeSet;
class CAT3DFaceGP;
class CAT3DLineGP;
class CAT3DEdgeGP;
class CATVizVertexBuffer;

//++ E8C : Multi Materials
class CATMaterialApplication;
class CATGroupOfFacesWithMaterials;
//-- E8C : Multi Materials


//******************************************************************************
//*** CAT3DGeomRep: **********************************************************
//******************************************************************************

/** 
* Class to define a Geometric representation.
*/
class ExportedBySGInfra CAT3DGeomRep : public CAT3DRep
{
   CATDeclareClass;

   friend class CATMonoWireRep;
   friend class CATSurfacicRep;

   
public:

   // INTERFACE FOR THE ORIGINAL GEOMETRY (called Geom):
   // --------------------------------------------------
   // All inheriting classes must implement how they manage the basic geometry.
   //
   //   - AddGeom*: Only a reference to the existing data is stored. Data is
   //     not duplicated within the object.
   //   - ReplaceGeomElt: the <iInd> gp becomes <iNewGP>. the old <iInd> gp is
   //     released. 
   
   /** @nodoc */
   virtual int                              GeomNumberOfFaces    (void)                     const                 = 0;

   /** @nodoc */
   virtual CAT3DFaceGP            *         GeomFace             (const int num_face)       const                 = 0;

   /** @nodoc */
   virtual HRESULT                          GetGeomFaceAttribut  (const int num_face,CATGraphicAttributeSet& orGA)       const =0;

   /** @nodoc */
   virtual HRESULT                          SetGeomFaceAttribut  (const int num_face,const CATGraphicAttributeSet& irGA) = 0;
   
   /** @nodoc */
   virtual int                              GeomNumberOfEdges    (void)                     const                 = 0;
   
   /** @nodoc */
   virtual CAT3DEdgeGP            *         GeomEdge             (const int num_edge)       const                 = 0;
   
   /** @nodoc */
   virtual HRESULT                          GetGeomEdgesAttribut (CATGraphicAttributeSet& orGA)       const   = 0;

   /** @nodoc */
   virtual HRESULT                          SetGeomEdgesAttribut (const CATGraphicAttributeSet& irGA)         = 0;

   /** @nodoc */
   virtual int                              GeomNumberOfElt      (const CATGeomType iType)  const                 = 0;

   /** @nodoc */
   virtual CATGraphicPrimitive    *         GeomElt              (const CATGeomType iType,
                                                                  const int num_elt)        const                 = 0;

   /** @nodoc */
   virtual HRESULT                          GetGeomEltAttribut   (const CATGeomType iType,
                                                                  const int num_elt,CATGraphicAttributeSet& orGA   )     const = 0;
   /** @nodoc */
   virtual HRESULT                          SetGeomEltAttribut   (const CATGeomType iType,
                                                                  const int num_elt,const CATGraphicAttributeSet& irGA  ) = 0;
   /** @nodoc */
   virtual int                              GeomNumberOfIsos     (void)                     const                 = 0;
   
   /** @nodoc */
   virtual CAT3DLineGP           **         GeomIso              (const int num_face,
                                                                  int *oIsoCount)           const                 = 0;
   
   /** @nodoc */
   virtual HRESULT                          GetGeomIsoAttribut   (const int num_iso,CATGraphicAttributeSet& orGA)       const = 0;

   /** @nodoc  */
   virtual HRESULT                          SetGeomIsoAttribut   (const int num_face,const CATGraphicAttributeSet& irGA) = 0;
   
   /** @nodoc */
   virtual HRESULT                          AddGeomFace          (CAT3DFaceGP *face,CATGraphicAttributeSet *att)  = 0;
   
   /** @nodoc */
   virtual HRESULT                          AddGeomEdge          (CAT3DEdgeGP *edge)                              = 0;
   
   /** @nodoc */
   virtual HRESULT                          AddGeomIso           (CAT3DLineGP  **iIso,
                                                                  CATGraphicAttributeSet *iAtt,
                                                                  int iIsoCount)                                  = 0;

   /** @nodoc */
   virtual HRESULT                          AddGeomElt           (const CATGeomType iType,
                                                                  CATGraphicPrimitive *iGP,
                                                                  CATGraphicAttributeSet *iAtt=NULL)              = 0;
  
   /** @nodoc */
   virtual HRESULT                          ReplaceGeomElt       (const CATGeomType iType,
                                                                  CATGraphicPrimitive *iNewGP,
                                                                  const int iInd)                                 = 0;
   
   /** @nodoc */
   virtual CATVizVertexBuffer *             GetVertexBuffer      (void)                     const                 ;

   /** @nodoc */
   virtual int                              NumberOfLODs         (void)                     const;
                                            
   /** @nodoc */                                                 
   virtual CAT3DFaceGP     *                LODFace              (const int num_lod)        const;

   /** @nodoc */                                                                                 
   virtual HRESULT                          GetLODFaceAttribut   (const int num_lod,CATGraphicAttributeSet& orGA)       const ;

   /** @nodoc */
   virtual HRESULT                          SetLODFaceAttribut   (const int num_lod,const CATGraphicAttributeSet& irGA) ;
                                            
   /** @nodoc */                                                 
   virtual float                            LODSag               (const int num_lod)        const;

   /** @nodoc */
   virtual int                              IsWire               (void)                     const                 ;

   /** @nodoc */
   virtual int                              IsMonoWire           (void)                     const                 ;

   /** @nodoc */
   virtual int                              IsSurfacic           (void)                     const                 ;

   /////////////////////////////////////////////////////////////////////////


   // SAG, STEP & ANGLE

   /** 
    * Defines the sag of the object.
    * @param iSag
    *   The sag value to define
    */
   void           SetGeomSag     (const float iSag);
   /** @nodoc */
   inline float   GeomSag        (void)                    const;

   /** @nodoc */
   void           SetGeomStep    (const float iStep);
   /** @nodoc */
   inline float   GeomStep       (void)                    const;

   /** @nodoc */
   void           SetGeomAngle   (const float iAngle);
   /** @nodoc */
   inline float   GeomAngle      (void)                    const;

   /** @nodoc */
   void           SetGeomScale   (const CATCGMScaleCategory iScale);
   /** @nodoc */
   inline CATCGMScaleCategory   GeomScale      (void)                    const;

		


	/** @nodoc */
	void	SetRegularizationSettingForTessellation(const int iRegularizedTessellationSetting);
	/** @nodoc */
	inline int	RegularizationSettingForTessellation() const;

	/** @nodoc */
	void	SetAdaptiveQualityForTessellation(const int iAdaptiveQualityTessellation);
	/** @nodoc */
	inline int	AdaptiveQualityForTessellation() const;
	
	/** @nodoc */
	void SetMaxTriangleThresholdForTessellation(const CATULONG32 iMaxTriangleCountForTessellation);
	/** @nodoc */
	inline CATULONG32 MaxTriangleThresholdForTessellation() const;
   

   // BODY IDENTIFICATOR

   /** @nodoc */
   inline void  SetBodyIdentificators (const CATBodyIdentificators * ident);
   /** @nodoc */
   inline const CATBodyIdentificators * GetBodyIdentificators() const;

   /** @nodoc */
   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

   /** @nodoc */
   virtual CATBoolean HasGeomFaceMaterials() const;

   /** @nodoc */
   virtual HRESULT GetGeomFaceMaterial(const unsigned int num_face, CATGraphicMaterial*& oMat) const;

   /** @nodoc */
   virtual HRESULT GetGeomFaceMappingOperator(const unsigned int num_face, CATMappingOperator*& oOp) const;

	 /** @nodoc */
	 virtual unsigned int GetNumberOfGroups() const;

	 /** @nodoc */
	 virtual HRESULT GetGroupOfFacesWithMaterials( const CATULONG32 num_group, CATGroupOfFacesWithMaterials*& oGroup ) const;

	 /** @nodoc */
  virtual HRESULT GetGeomFaceListOfMaterialApplication( const unsigned int num_face, ::list<CATMaterialApplication>& oList ) const;

  /** @nodoc */
  virtual HRESULT GetGeomFaceMaterialApplication( const unsigned int num_face, CATMaterialApplication*& oMatApp ) const;
   
  #if defined(REMOVE_USELESS_INCLUDE)
    #pragma message(" BADREM : AZX 06072022 " __FILE__ " Can't derive this class" )
  #endif
BEGIN_MIGRATE_REP_CTOR_PRIVATE

   CAT3DGeomRep();
   
   CAT3DGeomRep(CATModelIdentificator &id,void *ctrl=NULL);
   
protected:

   /** @nodoc */
   const CATBodyIdentificators * _bodyIdent;

   float _sag;                      // geometry precision
   float _angle;                    // max angle between consecutive normals
   float _step;                     // max size for edges
   CATCGMScaleCategory _scale;      // scale category
   unsigned short _RegularizationSettingForTessellation;   // Setting for regularized tesselation (0: no regularization)
   unsigned short _AdaptiveQualityTessellationVersion;   // Setting for adaptive quality tessellation (0: without)
   CATULONG32 _MaxTriangleThresholdForTessellation; // threshold for the pre-tesselation check. default is 10 000 000

private:

   void Init();
};


//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

inline float CAT3DGeomRep::GeomSag (void) const
{
   return _sag;
}

inline float CAT3DGeomRep::GeomAngle (void) const
{
   return _angle;
}

inline float CAT3DGeomRep::GeomStep (void) const
{
   return _step;
}

inline int	CAT3DGeomRep::RegularizationSettingForTessellation() const
{
	return _RegularizationSettingForTessellation;
}

inline int	CAT3DGeomRep::AdaptiveQualityForTessellation() const
{
	return _AdaptiveQualityTessellationVersion;
}

inline CATULONG32 CAT3DGeomRep::MaxTriangleThresholdForTessellation() const
{
	return _MaxTriangleThresholdForTessellation;
}


inline CATCGMScaleCategory CAT3DGeomRep::GeomScale (void) const
{
   return _scale;
}

inline void CAT3DGeomRep::SetBodyIdentificators(const CATBodyIdentificators * ident)
{
   _bodyIdent = ident;
}

inline const CATBodyIdentificators * CAT3DGeomRep::GetBodyIdentificators() const
{
   return _bodyIdent;
}

#endif
