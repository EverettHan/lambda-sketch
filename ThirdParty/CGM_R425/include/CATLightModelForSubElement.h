#ifndef CATLightModelForSubElement_H
#define CATLightModelForSubElement_H

//
//  copyright dassault systemes 2004
//  --------------------------------
//
//  FrameWork Visualization :
//  -------------------------
//
//          author : Sebastien VIDECOQ
//                    
//  ---------------------------------------------------------------------------
//

#include "SGInfra.h"
#include "CATModelForSubElement.h"


class CATGraphicPrimitive;
class CATRepWeakRef;

class  ExportedBySGInfra CATLightModelForSubElement : public CATModelForSubElement 
{
public :
  CATDeclareClass;

  CATLightModelForSubElement();
  ~CATLightModelForSubElement();

   /**
    * Returns the referenced graphical object.
    * It is up to the user to release the returned pointer when it is no more used.
    * The requester has to use the Release() method when he has finished using the returned
    * pointer.
    */
   virtual CATGraphicPrimitive * GetGraphicalObject();

   /** @nodoc **/
   void SetRepWeakRef(CATRepWeakRef* weakRef);

   /**
    * Returns the referenced V6 primitive.
    */
   virtual CATVizPrimitive* GetPrimitive();

protected:
   int _switchDone;
   CATRepWeakRef *_myRepWeakRef;
};


#endif

