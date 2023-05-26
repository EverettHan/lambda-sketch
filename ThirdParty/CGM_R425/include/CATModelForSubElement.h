#ifndef CATModelForSubElement_H
#define CATModelForSubElement_H

//
//  copyright dassault systemes 1999
//  --------------------------------
//
//  FrameWork Visualization :
//  -------------------------
//
//          author : Franck Coffin
//                    
//  Abstract:
//  --------
//         Local Object that the model part of a rep, that is an object that has
//         an extension adhering to CATI3DGeoVisu and CATI2DGeoVisu which refer
//         a given rep.
//         It is useful in order to be Model-Visu architecture compliant as far as 
//         decoding and highlight are concerned. 
//  ---------------------------------------------------------------------------
//

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CAT4x4Matrix.h"
#include "CATMathPointf.h"
#include "CATMathDirectionf.h"
class CATVizPrimitive;

class CATGraphicPrimitive;
class CATRepWeakRef;

class  ExportedBySGInfra CATModelForSubElement : public CATBaseUnknown 
{
public :
  CATDeclareClass;

  CATModelForSubElement();
  virtual ~CATModelForSubElement();

	void SetIndex (int ind);
	int GetIndex();
   /**
    * Sets a graphical data within the structure
   */
   void SetGraphicalObject( CATGraphicPrimitive * iGp);

   /**
    * Returns the referenced graphical object.
    * It is up to the user to release the returned pointer when it is no more used.
    * The requester has to use the Release() method when he has finished using the returned
    * pointer.
    */
   virtual CATGraphicPrimitive * GetGraphicalObject();

   /**
    * Sets the V6 primitive within the structure
   */
   void SetPrimitive( CATVizPrimitive * primitive);

   /**
    * Returns the referenced V6 primitive.
    */
   virtual CATVizPrimitive * GetPrimitive();

   /**
   * Compares implementations pointed by interfaces.
   * @param iobject
   *   The second object to be compared to.
   * @return 1 if the implementations are identical.
   */
   virtual int IsEqual(const CATBaseUnknown *iobject) const;

   /**@nodoc*/
   void SetRepWeakRef(CATRepWeakRef* wr);

private:
  unsigned int _index : 31;
  unsigned int _primitiveType : 1;
  union
  {
    CATGraphicPrimitive *_gp;
    CATVizPrimitive *_vizPrimitive;
    void *_value;
  } _graphicalObject;

public :
  CAT4x4Matrix _matrix3D;
  CATMathPointf _intersection; 
  CATMathDirectionf _normal; 
private:
  CATRepWeakRef *_repWeakRef;
};


#endif
