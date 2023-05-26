#ifndef _CATDebugCGRRep_
#define _CATDebugCGRRep_

#include "SGInfra.h"
#include "CAT3DBagRep.h"
class ExportedBySGInfra CATDebugCGRRep : public CAT3DBagRep
{
   CATDeclareClass;

public:	
   
   /** @nodoc */
   static CATDebugCGRRep* CreateRep();
   /** @deprecated R417 : Use CreateRep instead.*/
   CATDebugCGRRep();

   // AZX: (A2X migration) Making draw functions final 
   /** @nodoc */
   virtual void DrawShading(CATRender&, int) override final;
   /** @nodoc */
   virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;
   /** @nodoc */
   virtual void Draw(CATRender &iRender, int iInside) override final;
   /** @nodoc */
   virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) override final; 
   /** @nodoc */
   virtual list<CATRep> * GetChildren();
   /** @nodoc */
   virtual const CAT3DBoundingSphere &GetShowBoundingElement();
   /** @nodoc */
   const CAT3DBoundingSphere &GetNoshowBoundingElement(int & ioIsOneRepNoshow);

};

#endif
