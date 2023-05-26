#ifndef CATModelForRep2D_H
#define CATModelForRep2D_H

//
//  copyright dassault systemes 2001
//  --------------------------------
//
/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */
/**
 *  Class for dialog help 2D objects.
 *  <br>This class is the main class (implementation) of a component that 
 *  implements the @href CATI2DGeoVisu interface.
 *  It is dedicated to hold a graphic representation of an object that is 
 *  not part of the document, but is used to ease the dialog. This
 *  representation is to be built outside and set to the component thanks to 
 *  the @href #SetRep method.
 *
 *  <br>You can visualize the component thanks to a <i>CATISO</i> object and
 *  you can select it. Create a @href 
 *  CATPathElement with the component, and use the 
 *  @href CATHSO and the @href CATPSO to highlight, and 
 *  to prehighlight respectively.
 * 
 *  <br><br><b>Sample:</b>
 *   
 *  <pre>
 *  ...
 *  CAT2DxxxRep * pMyRep = new CAT2DxxxRep();
 *
 *  CATModelForRep2D * pFor2DModel = new CATModelForRep2D(); 
 *  pFor2DModel-><b>SetRep</b>(pMyRep);
 *  pMyRep = NULL;
 *  
 *  CATISO *pISO = .... // to retrieve from the CATFrmEditor 
 *  pISO-><b>AddElement</b>(pFor2DModel);
 *  ...
 *
 *  pISO-><b>RemoveElement</b>(pFor2DModel);  //pMyRep is deleted 
 *  ...
 *
 *  <b>// To do a new visualization </b>
 *  pMyRep = new CAT2DxxxRep();
 *  pFor2DModel-><b>SetRep</b>(pMyRep);
 *  pISO->AddElement(pFor2DModel);
 *  ...
 *
 *  pISO->RemoveElement(pFor2DModel);  //pMyRep is deleted 
 *  ...
 *
 *  //No more need of the model
 *  pFor2DModel->Release();
 *  pFor2DModel=NULL;
 *  ...
 *  </pre>
 *  <b>Life Cycle of the graphic representation</b>
 *  <br>The graphic representation associated with the current class is managed 
 *  by the @href CATVisManager . So after the <i>SetRep</i> method, it will be deleted
 *  when the <i>CATModelForRep2D</i> instance will be removed from the ISO (but not from
 *  the  HSO and PSO). A new graphic representation must be created whenever you call <code>
 *  AddElement</code> to add such a component into the ISO.
 *  <br><br><b>Why to derive from this class?</b>
 *  <br>To understand, here is an extract of the <code>BuildGraph</code> 
 *  method of a <i>CATStateCommand:</i></b>
 *  <pre>
 *  ...
 *  _daPathElement = new CATPathElementAgent("MyAgentName");
 *  _daPathElement-><b>AddElementType</b>(IID_CATI2DGeoVisu);
 *  ...
 *  </pre>
 *  With this agent, <code>_daPathElement</code>, your component will be selectable since it 
 *  implements the <i>CATI2DGeoVisu</i> interface. But unfortunately, this criterion is not 
 *  enough discriminating, because all the 2D visualized objects are also selectable. 
 *  To filter the selection, you can
 *  create a new component which derives from the <i>CATModelForRep2D</i> component and which  
 *  implements a dedicated interface. In short:
 *  <ul>
 *     <li>Create a new interface without method, named <code>MyNewInterface</code></li>
 *     <li>Create a new component, named <code>MyModelForRep</code>, which OM and C++ derives from CATModelForRep2D</li>
 *     <ul>
 *     <li>Its header class is:</li>
 *     <pre>
 *      #include "CATModelForRep2D.h"  
 *      class  MyModelForRep : public CATModelForRep2D
 *      {
 *         // Used in conjunction with CATImplementClass in the .cpp file
 *         CATDeclareClass;
 *
 *         MyModelForRep() ;
 *         virtual ~MyModelForRep();
 *
 *         private:
 *
 *         // Copy constructor, not implemented
 *         // Set as private to prevent from compiler automatic creation as public.
 *         MyModelForRep(const MyModelForRep &iObjectToCopy);
 *
 *         // Assignment operator, not implemented
 *         // Set as private to prevent from compiler automatic creation as public.
 *         MyModelForRep & operator = (const MyModelForRep &iObjectToCopy);
 *      };
 *     </pre>
 *     <li>Its source class is:</li>
 *     <pre>
 *     #include "MyModelForRep.h"
 *
 *     // To declare that the class is a component main class which OM derives from
 *     // CATModelForRep2D
 *     CATImplementClass(MyModelForRep, Implementation, CATModelForRep2D, CATNull);
 *     
 *     MyModelForRep::MyModelForRep();
 *     {
 *     }
 *
 *     MyModelForRep::~MyModelForRep();
 *     {
 *     }
 *
 *     // The component implements MyNewInterface interface
 *     #include "TIE_MyNewInterface.h"
 *     TIE_MyNewInterface(MyModelForRep);
 *     </pre>
 *     </ul>
 *     <li>Modify the interface dictionary</li>
 *     <pre>
 *     MyModelForRep  MyNewInterface libxxxx
 *     </pre>
 *  </ul>
 */



#include "SceneGraphManager.h"
#include "CATModelForRep.h"


class ExportedBySceneGraphManager CATModelForRep2D : public CATModelForRep
{
  CATDeclareClass;
public :

   /** Default constructor. 
    */
   CATModelForRep2D();

  /**
   * Associates a graphic representation.
   *
   * @param iRep
   *   The given representation which you want <i>CATModelForRep2D</i> to be associated with.
   *   Once the representation iRep has been associated with a <i>CATModelForRep2D</i> 
   *   component its lifecycle is
   *   managed by the @href CATVisManager .
   *   <br>iRep is a pointer to an instance of a class which derives from
   *   @href CAT2DRep .
   */
  virtual void SetRep (CATRep * iRep);
};


#endif
