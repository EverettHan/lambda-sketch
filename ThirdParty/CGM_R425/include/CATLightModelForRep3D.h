#ifndef CATLightModelForRep3D_H
#define CATLightModelForRep3D_H

//
//  COPYRIGHT DASSAULT SYSTEMES 2003
//  --------------------------------
//

#include "SceneGraphManager.h"
#include "CATModelForRep3D.h"

class CATRepWeakRef;

class ExportedBySceneGraphManager CATLightModelForRep3D : public CATModelForRep3D
{
   CATDeclareClass;

public:
   
  /** Default constructor. 
   */
   CATLightModelForRep3D();
   virtual ~CATLightModelForRep3D();
   /**
    * Associates a graphic representation.
    *
    * @param iRep
    *   The given representation which you want <i>CATModelForRep3D</i> to be associated with.
    *   Once the representation iRep has been associated with a <i>CATModelForRep3D</i> 
    *   component its lifecycle is
    *   managed by the @href CATVisManager .
    *   <br>iRep is a pointer to an instance of a class which derives from
    *   @href CAT3DRep .
    */
   virtual void SetRep (CATRep * iRep);
   virtual void SetWeakRef(CATRepWeakRef * iWeakRef);

   /** @nodoc */
   virtual CATRep *GiveRep();
   CATRep * GiveLightRep();
   
private:
   int _switchDone;
   CATRepWeakRef *_weakRef;
};

#endif
