#ifndef VIS3DNODEGROUPREP_H
#define VIS3DNODEGROUPREP_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "CAT3DBagRep.h"

class CAT4x4Matrix;
class CATVisuController;


#include "CATVisMacroForInterfaces.h"
class IVisSG3DNodeGroup;
class Vis3DNodeGroupRepIVisSG3DNodeGroupBOAImpl;
class VisAttribute;



class ExportedBySGInfra Vis3DNodeGroupRep : public CAT3DBagRep
{
  
  CATDeclareClass;
  
  friend class CATDmuStreamVis3DNodeGroupRep;
  friend class Vis3DFixedSizeNodeGroupRep;

public:
   

  virtual ~Vis3DNodeGroupRep();

  static Vis3DNodeGroupRep* CreateRep();

protected:

  BEGIN_MIGRATE_REP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Can't derive this class" )
#endif
  /** @deprecated R417 : Use CreateRep instead.*/
  Vis3DNodeGroupRep();
  END_MIGRATE_REP_CTOR

public:

  /** @nodoc */
  CATVisDeclarePublicInterfaceAdhesion(Vis3DNodeGroupRep, IVisSG3DNodeGroup, Vis3DNodeGroupRepIVisSG3DNodeGroupBOAImpl);

  /** @nodoc */
  virtual HRESULT GetAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue);

  /** @nodoc */
  virtual HRESULT SetAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue);


  /** @nodoc */
  virtual void DrawShading(CATRender &ioRender, int iInside);
  
  /** @nodoc */
  virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath);

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  const VisAttribute* GetVisAttribute() const;

private:
  void _NotifyObservers(VisAttributeID iAttributeID);

protected:
  VisAttribute *_visAttribute;  

};

#endif // VIS3DNODEGROUPREP_H

