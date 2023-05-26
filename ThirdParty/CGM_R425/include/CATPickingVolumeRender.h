#ifndef CATPickingVolumeRender_H
#define CATPickingVolumeRender_H

// COPYRIGHT DASSAULT SYSTEMES 2013

//------------------------------------------------------------------------------
// Inheritance: CATPickingVolumeRender
//                CATPickingRender
//                  CATRepRender
//                    CATRender
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CATPickingRender.h"
#include "CATGraphicPrimitive.h"
#include "CATVizPtrList.h"
#include "CATPickPathList.h"

//system fw
#include "CATBoolean.h"

class CATSupport;
class CATRep;


class ExportedBySGInfra CATPickingVolumeRender : public CATPickingRender
{
 CATDeclareClass_Deprec;

public :

   CATPickingVolumeRender (const CATSupport &support, const float x, const float y, const float dx, const float dy, CATPickPathList &pickPathList);
   CATPickingVolumeRender& operator=(const CATPickingVolumeRender &render);

   virtual ~CATPickingVolumeRender();

  virtual int DrawRepresentation (CATRep &iRep, int iInside, void* &iData);
  virtual int EndDrawRepresentation (CATRep &iRep, void* &iData);

  virtual void AddPickPath ();

 private :

   //copy constructor and = operator
   CATPickingVolumeRender (const CATPickingVolumeRender &render);

   //CATVizPtrList<CATPickPath> _subFaces;
   CATPickPathList _subFaces;
   CATBoolean _trackFaces;
};

#endif
