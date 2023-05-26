#ifndef CATGraphicPathElement_h
#define CATGraphicPathElement_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/*
 * HISTORY : 
 *   17 Juillet 2001 - CDT : on surcharge le new/delete pour augmenter les perfos
 */


#include "SceneGraphManager.h"

#include "CATPathElement.h"
#include "CATEventSubscriber.h"
#include "CATMathPointf.h"
#include "CATMathPoint.h"
#include "CATMathDirectionf.h"
#include "CATBaseUnknown_WR.h"

class CATViewer;


/**
* Class representing a CATPathElement with graphical informations.
* <br><b>Role</b> : these object define a particular @href CATPathElement that
* keep informations of picking (intersection coordinates and normal at the intersection
* point with the graphical representation - @href CATRep - ).
* <BR>
* <BR>This class is used by CATManipulator and CATSelector to generate a CATPathElement
* without loosing all informations of picking. These informations are :
* <BR>  - coordinates of intersection in model units ;
* <BR>  - normal at the point of intersection ;
* <BR>  - viewer in wich the picking was realised.
* <BR>
* @see CATPathElement, CATViewer, CATManipulator, CATSelector
*/
class ExportedBySceneGraphManager CATGraphicPathElement : public CATPathElement
{

  /** @nodoc */ 
  CATDeclareClass;

    
  
public:
  
  /**
  * Main constructor of CATGraphicPathElement.
  * 
  * @param iTopObject
  *        First object to add in the path.
  *        <BR> Replace the first call to @href CATPathElement#AddElement .
  *        <br><b>Cyclic reference</b> : A copy of <tt>iTopObject</tt> is kept and a AddRef
  *         is done on it.
  *
  * @param iViewer.
  *        The viewer in wich the pickpath was created (where the the object was picked).
  *
  * @param iIntersectionPoint
  *        The intersection with the graphic representation using coordinates of model.
  *        <BR>Be carreful that the intersection is compute with tersselation of visualization.
  *
  * @param iNormal
  *        The normal at the intersection of the picking with the graphic representation.
  *
  * @param iGlobalNormal
  *        The normal at the intersection of the picking with the graphic representation
  *        given in the global coordinary system.
  */
  CATGraphicPathElement ( const CATBaseUnknown* iTopObject,
                          CATViewer*            iViewer,
                          CATMathPointf         iIntersectionPoint,
                          CATMathDirectionf     iNormal,
                          CATMathDirectionf     iGlobalNormal=CATMathDirectionf() );
						  
						  /**
  * Main constructor of CATGraphicPathElement.
  * 
  * @param iTopObject
  *        First object to add in the path.
  *        <BR> Replace the first call to @href CATPathElement#AddElement .
  *        <br><b>Cyclic reference</b> : A copy of <tt>iTopObject</tt> is kept and a AddRef
  *         is done on it.
  *
  * @param iViewer.
  *        The viewer in wich the pickpath was created (where the the object was picked).
  *
  * @param iIntersectionPoint
  *        The intersection with the graphic representation using coordinates of model.
  *        <BR>Be carreful that the intersection is compute with tersselation of visualization.
  *
  * @param iNormal
  *        The normal at the intersection of the picking with the graphic representation.
  *
  * @param iGlobalNormal
  *        The normal at the intersection of the picking with the graphic representation
  *        given in the global coordinary system.
  */
  CATGraphicPathElement ( const CATBaseUnknown* iTopObject,
                          CATViewer*            iViewer,
                          CATMathPoint          iIntersectionPoint,
                          CATMathDirectionf     iNormal,
                          CATMathDirectionf     iGlobalNormal=CATMathDirectionf() );				

  /**
   * Default constructor.
   */
  CATGraphicPathElement ();
  
  /**
  * Copy constructor of a CATGraphicPathElement.
  *
  * @param iBrother
  *        The other CATGraphicPathElement used to construct this one.
  */
  CATGraphicPathElement ( const CATGraphicPathElement& iBrother );
  

  /**
  * Copy constructor of a CATGraphicPathElement taking a CATPathElement
  * <BR>in parameter.
  *
  * @param iBrother
  *        The CATPathElement used to construct this one.
  *        <BR>if you use this constructor, picking informations are not valued.
  */
  CATGraphicPathElement ( const CATPathElement& iBrother );

  
  /**
  * Operator of assignment.
  *
  * @param iBrother
  *        The other CATGraphicPathElement to assign to this.
  *
  * @return
  *        A Reference on CATGraphicPathElement that contains the same datas
  *        <BR>that the parameter iBrother.
  */
  CATGraphicPathElement& operator = ( const CATGraphicPathElement& iBrother);
  
  
  virtual ~CATGraphicPathElement ();
  
  
  /**
  * Creates a new CATGraphicPathElement by dupplication of this.
  *
  * @return
  *        A pointer on the new CATGraphicPathElement.
  *        <BR>Don't forget to delete this variable after use.
  */
  virtual CATPathElement* Clone () const;
  
  
  /**
  * Finds an element in the CATGraphicPathElement.
  * <BR>This function could be used as @href CATPathElement#FindElement
  * <BR>but you can also find on of the particular datas of the CATGraphicPathElement.
  *
  * @param iid
  *        The interface of the object you look for.
  *        <BR>The following values are accepted :
  *        <dl>
  *          <dt>CATViewer::ClassId()</dt>
  *          <dd>Return a pointer on the CATViewer in wich the picking was done.</dd>
  *          <dt>CAT3DViewer::ClassId()</dt>
  *          <dd>Return a pointer on the CAT3DViewer in wich the picking was done.</dd>
  *          <dt>CAT2DViewer::ClassId()</dt>
  *          <dd>Return a pointer on the CAT2DViewer in wich the picking was done.</dd>
  *          <dt>CATGraphicElementIntersection::ClassId()</dt>
  *          <dd>Return a pointer on a CATGraphicElementIntersection that defined
  *              the intersection between the picking and the graphic representation.</dd>
  *          <dt>CATGraphicElementNormale::ClassId()</dt>
  *            <dd>Return a pointer on a CATGraphicElementNormale that defined
  *              the normal on the graphic representation at the picking point.</dd>
  *          <dt>Otherwise </dt>
  *          <dd>Call @href CATPathElement#FindElement </dd>
  *         </dl>
  *
  * @return
  *        A pointer on the asking element.
  *        <BR>A AddRef is done before returning the pointer, you have to
  *        <BR>call the Release function after use of it.
  */
  virtual CATBaseUnknown* FindElement (const IID& iid);

  
  /**
  * @nodoc
  * internal use only.
  */
  virtual CATPathElement* GetSubPath ( const CATListOfCATString iList_Interfaces, int &oPos ) const;
  
  
  /**
  * @nodoc
  * internal use only.
  */
  virtual void SaveOriginalPath (CATPathElement* iPath);

  /**
  * @nodoc
  * internal use only.
  */
  virtual CATPathElement* GetOriginalPath ();
  
  /**
  * @nodoc
  * internal use only.
  */
  virtual void SetOffsetForSearch (int iOffset); 
  
  /**
  * @nodoc
  * deprecated - use FindElement.
  */
  virtual CATBaseUnknown* FindObject(const IID &iid) ;

  /**
  * Defines the interactive context.
  * <br><b>Role</b> : precise if the graphic representation 
  * <br>must be drawn taking account the context defined in parameter.
  *
  * @param iContext
  *        The context defines by @href CATVisInteractiveContext enum.
  */

  void SetInteractiveContext ( CATVisInteractiveContext iContext );


  /**
  * Gets the interactive context.
  * <br><b>Role</b> : gives the interactive context that
  * <br>will be use to draw the graphic representation.
  *
  * @return
  *        The @href CATVisInteractiveContext of the context.
  */
  CATVisInteractiveContext GetInteractiveContext () const;
  
  /** @nodoc */
  void SetViewObject(const CATBaseUnknown_var& i_pViewObject);
  /** @nodoc */
  CATBaseUnknown_var GetViewObject() const;

private:
  
  void CleanReference (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback ); 
  
  CATViewer*        _viewer;
  CATMathPoint      _intersection;
  CATMathDirectionf _globalNormale;
  CATMathDirectionf _normale;
  CATVisInteractiveContext _context;  
  // embedded path element ; useful for OtherSelection/DrillingSelector
  CATPathElement*   _OriginalPath;
  CATBaseUnknown_WR _visViewWR;
 
};

#endif
