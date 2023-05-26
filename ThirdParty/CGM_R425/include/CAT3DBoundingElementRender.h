#ifndef CAT3DBoundingElementRender_H_
#define CAT3DBoundingElementRender_H_

//*****************************************************************************
//  CATIA Version 5 Release 14 Framework VisualizationBase
//  Copyright Dassault Systemes 2004
//*****************************************************************************
//  Abstract:
//  ---------
//  Simple render to compute the 3D bounding sphere of a representation.
//  The 3D mask is taken in to acount.
//
//*****************************************************************************
//  Usage:
//  ------
//  The render is created with a given CATSupport.
//  The render is called each time a Draw() is executed.
//  The 3D bounding sphere is returned by calling GetBoundingElement.
//
//  example:
//  -------- 
//  CATSupport support (100, 100);
//
//  CAT3DBoundingElementRender* render = new CAT3DBoundingElementRender (support);
//    
//  list<CATViewpoint> vplist;
//  vplist.fastadd(viewpoint);
//
//  render -> Draw (vplist, 0, 0.5f);
//
//  CAT3DBoundingSphere bs3D = render -> GetBoundingElement();
//
//*****************************************************************************
//  Inheritance:
//  ------------
//                    CAT3DBoundingElementRender
//                      CATCullingRender
//
//*****************************************************************************
//  Main Methods:
//  -------------
//  Overload draw methods for all 3D graphical primitives.
//
//  Overload DrawRepresentation and End DrawRepresentation methods for 
//  calculate the bounding sphere of representation.
//*****************************************************************************

//  Visualization
#include "SGInfra.h"
#include "CATCullingRender.h"
#include "CATRepRender.h"
#include "CAT3DBoundingSphere.h"
//#include "CATSupport.h"

class CATRep;
class CATSupport;

class ExportedBySGInfra CAT3DBoundingElementRender : public CATCullingRender
{
   public:

      //  Constructors/destructors
      //--------------------------
      CAT3DBoundingElementRender (const CATSupport & iSupport);
         
      CAT3DBoundingElementRender (const CAT3DBoundingElementRender & iRender);
      
      ~CAT3DBoundingElementRender();
      
      virtual int DrawRepresentation (CATRep & iRep, int iInside, void* &iData);
      virtual int EndDrawRepresentation (CATRep & iRep, void* & iData);
      
      virtual int IsDrawable (const float x, const float y, const float z);

      virtual int CheckTriangleVersusBox(const float  *iTriangle,
                                         CAT4x4Matrix *iNonRectangularBox = NULL,
                                         const float   iTol=0.f);
      
      virtual int CheckTriangleStripVersusBox(const float  *iStrip,
                                              const int     iNbPts,
                                              const void   *iIndices = NULL,
                                              const int     iIndexType = 1,
                                              CAT4x4Matrix *iNonRectangularBox = NULL,
                                              const float iTol=0.f);
      
      virtual int CheckTriangleFanVersusBox(const float  *iFan,
                                            const int     iNbPts,
                                            const void   *iIndices = NULL,
                                            const int     iIndexType = 1,
                                            CAT4x4Matrix *iNonRectangularBox = NULL,
                                            const float   iTol=0.f);
      
      virtual int CheckPolylineVersusBox(const float  *iPolyline,
                                         const int     iNbPts,
                                         const int     iClosedPolyline = 0,
                                         const void   *iIndices = NULL,
                                         const int     iIndexType = 0,
                                         const int     iIndexFactor = 1,
                                         CAT4x4Matrix *INonRectangularBox = NULL,
                                         const float   iTol=0.f);

      // Graphical elements draw methods:
      // --------------------------------
      virtual void DrawDynamicGP (CATDynamicGP & iGP);
      /*
      virtual void Draw3DMarker       (CAT3DMarkerGP &);
      virtual void Draw3DLine         (CAT3DLineGP &);
      virtual void Draw3DEdge         (CAT3DEdgeGP &);
      virtual void Draw3DFace         (CAT3DFaceGP &);
      virtual void Draw3DPlanarFace   (CAT3DPlanarFaceGP &);
      virtual void Draw3DCylinder     (CAT3DCylinderGP &, const int = 0);
      virtual void Draw3DCurvedPipe   (CAT3DCurvedPipeGP &);
      */
     
      // Result query
      //-------------
      inline const CAT3DBoundingSphere & GetBoundingElement () const {return (_boundingSphere);};
         
   private:
      
      int   _detailCulling;    // mask info

      CAT3DBoundingSphere _boundingSphere;
   
      //Surcharge de l'opérateur =
      CAT3DBoundingElementRender & operator = (const CAT3DBoundingElementRender &);

      // filtre DetailCulling
      int TestDetailCulling (CATGraphicPrimitive & GP);
};

#endif
