#ifndef VISSGVISITORSTRATEGYDEFINE_H
#define VISSGVISITORSTRATEGYDEFINE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "CATSysErrorDef.h"


/** 
 * Basic class of strategy definition for Scene Graph Visit.
 * <b>Role</b>: This is the class that Scene Graph Visit has to C++ use to define its visit strategy.
 * It manages the SceneGraph visit according to the strategy defined.
*/
class ExportedBySGInfra VisSGVisitorStrategyDefine
{

public:

  VisSGVisitorStrategyDefine();
  ~VisSGVisitorStrategyDefine();
  VisSGVisitorStrategyDefine(const VisSGVisitorStrategyDefine& iStrategyDefine);
  VisSGVisitorStrategyDefine& operator = (const VisSGVisitorStrategyDefine& iStrategyDefine);

  /** 
   * Defines the visit level. The visit could be stopped at IVisSGNode leaf or at IVisSGPrimitive leaf or 
   * at primitive item leaf or the tessellation could be visited.
   * Default: VisSGVisitorStrategy_TessellationVisit
   **/
  enum VisSGVisitorStrategy_Level
  {
    VisSGVisitorStrategy_TessellationVisit,
    VisSGVisitorStrategy_PrimitiveItemVisit,
    VisSGVisitorStrategy_PrimitiveVisit,
    VisSGVisitorStrategy_PrimitiveCollectionVisit
  };

  HRESULT GetVisitLevel(VisSGVisitorStrategy_Level& oStrategy) const;
  HRESULT SetVisitLevel(VisSGVisitorStrategy_Level iStrategy);

  /** 
   * Defines the filters to apply that will lead to not visit some elements. 
   * VisSGVisitorStrategy_Use_Hide_Filter : element with hidden attribute will not be visited. 
   * Default: VisSGVisitorStrategy_Use_Hide_Filter = 0
   * VisSGVisitorStrategy_Use_Show_Filter : element with shown attribute will not be visited. 
   * Default: VisSGVisitorStrategy_Use_Show_Filter = 0
   * VisSGVisitorStrategy_Use_NoPick_Filter : element with no pick attribute will not be visited.
   * Default: VisSGVisitorStrategy_Use_NoPick_Filter = 0
   * VisSGVisitorStrategy_Use_Clipping_Filters : clipped element will not be visited. 
   * Default: VisSGVisitorStrategy_Use_Clipping_Filters = 1
   * VisSGVisitorStrategy_Use_Layer_Filter : layer filter is applied. 
   * Default: VisSGVisitorStrategy_Use_Layer_Filter = 1
   * VisSGVisitorStrategy_Use_Context_Filter : context filter is applied. 
   * Default: VisSGVisitorStrategy_Use_Context_Filter = 1
   * VisSGVisitorStrategy_Use_2DMode_Filter : 2D mode filter is applied. 
   * Default: VisSGVisitorStrategy_Use_2DMode_Filter = 1
   * VisSGVisitorStrategy_Use_Scissor_Filter : polygonal and circular scissor filters are applied. 
   * Default: VisSGVisitorStrategy_Use_Scissor_Filter = 1
   **/
  enum VisSGVisitorStrategy_GeomRemoval
  {
    VisSGVisitorStrategy_Use_Hide_Filter,
    VisSGVisitorStrategy_Use_Show_Filter,
    VisSGVisitorStrategy_Use_NoPick_Filter,
    VisSGVisitorStrategy_Use_Clipping_Filters,
    VisSGVisitorStrategy_Use_Layer_Filter,
    VisSGVisitorStrategy_Use_Context_Filter,
    VisSGVisitorStrategy_Use_2DMode_Filter,
    VisSGVisitorStrategy_Use_Scissor_Filter,
  };
  unsigned char IsFilterApply(VisSGVisitorStrategy_GeomRemoval iStrategy) const;
  HRESULT GetFilterApply(VisSGVisitorStrategy_GeomRemoval iStrategy, unsigned char& oMode) const;
  HRESULT SetFilterApply(VisSGVisitorStrategy_GeomRemoval iStrategy, unsigned char iMode);

  /** 
   * Defines the attributes to apply. 
   * VisSGVisitorStrategy_Apply_Inheritance : use the inheritance mode that will modify the children attributes according to their father ones..
   * Default: VisSGVisitorStrategy_Apply_Inheritance = 1
   **/
  enum VisSGVisitorStrategy_AttributeApply
  {
    VisSGVisitorStrategy_Apply_Inheritance
  };
  unsigned char IsAttributeApply(VisSGVisitorStrategy_AttributeApply iStrategy) const;
  HRESULT GetAttributeApply(VisSGVisitorStrategy_AttributeApply iStrategy, unsigned char& oMode) const;
  HRESULT SetAttributeApply(VisSGVisitorStrategy_AttributeApply iStrategy, unsigned char iMode);

  /** 
   * Defines the components to visit.
   * Default: VisSGVisitorStrategy_Normal = 1
   * Default: VisSGVisitorStrategy_Diffuse_Color = 1
   * Default: VisSGVisitorStrategy_Tex_Coord = 1
   * Default: VisSGVisitorStrategy_User = 1
   */
  enum VisSGVisitorStrategy_VertexCompVisit
  {
    VisSGVisitorStrategy_Normal,
    VisSGVisitorStrategy_Diffuse_Color,
    VisSGVisitorStrategy_Tex_Coord,
    VisSGVisitorStrategy_User
  };
  unsigned char IsVertexCompVisit(VisSGVisitorStrategy_VertexCompVisit iStrategy) const;
  HRESULT GetVertexCompVisit(VisSGVisitorStrategy_VertexCompVisit iStrategy, unsigned char& oMode) const;
  HRESULT SetVertexCompVisit(VisSGVisitorStrategy_VertexCompVisit iStrategy, unsigned char iMode);

private:

  // Visit Level
  VisSGVisitorStrategy_Level _VisitLevel;
  
  // Filters Use
  unsigned char _Use_Hide_Filter;
  unsigned char _Use_Show_Filter;
  unsigned char _Use_NoPick_Filter;
  unsigned char _Use_Clipping_Filters;
  unsigned char _Use_Layer_Filter;
  unsigned char _Use_Context_Filter;
  unsigned char _Use_2DMode_Filter;
  unsigned char _Use_Scissor_Filter;

  // Attributes Apply
  unsigned char _Apply_Inheritance;

  // Vertex Component Visit
  unsigned char _Normal_VertexComp_Visit;
  unsigned char _Diffuse_Color_VertexComp_Visit;
  unsigned char _Tex_Coord_VertexComp_Visit;
  unsigned char _User_VertexComp_Visit;
};

#endif
