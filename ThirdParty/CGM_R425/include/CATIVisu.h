#ifndef CATIVISU_H
#define CATIVISU_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U6
 */

#include "CATVisItf.h"
#include "CATBaseUnknown.h"


class CATRep;
class CATPickPath;
class CATNotification;
class CATPathElement;
class CATRepPath;
class CATVisRepContext;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIVisu;
#else
extern "C" const IID IID_CATIVisu;
#endif
/** 
 * Basic class of any visualization interface used to make objects visualized.
 * <b>Role</b>: This is the basic class that any visualization interface has to C++ 
 * derive from. 
 * <br>Components that implement any specialized <tt>CATIVisu</tt> interface 
 * are able to be visualized and  highlighted. 
 * <br><br>All visualization mecanisms are controlled by the @href CATVisManager. 
 * <br><br><b>How to create the specialized interface:</b>
 * <br> The new interface is named IMyNewVisu. 
 * <ul>
 * <li>The new interface must C++ derives from <tt>CATIVisu</tt> </li>
 * <br>Extract from IMyNewVisu.h
 * <pre>
 *    .....
 *    class  IMyNewVisu : public <b>CATIVisu</b>
 *    {
 *      CATDeclareInterface;
 *      public: 
 *         ....
 *    } ; 
 *
 * </pre>
 * <li>The new interface must OM-derives from @href CATBaseUnknown </li>
 * <br>Extract from IMyNewVisu.cpp
 * <pre>
 *    CATImplementInterface(IMyNewVisu, <b>CATBaseUnknown</b>);
 * </pre>
 * </ul>
 * This allows you to make a given component implement several visualization 
 * interfaces.
 * <br><br><b>Caution:</b>A specialized interface must never derive from an another one. The  interface must always 
 * derive from <tt>CATIVisu</tt>. In particular, do not derive from @href CATI3DGeoVisu or 
 * @href CATI2DGeoVisu to create a 3D ou 2D visualization interface.
 * <br><br>To implement the specialized interface used the @href CATExtIVisu adapter.
 */
class ExportedByCATVisItf CATIVisu : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
 
  /**
   * Builds the graphical representation.
   * @return 
   * A pointer to the graphical representation of one extension of any visualization interface.
   */
  virtual CATRep * BuildRep () = 0 ;

 /**
  * Returns the pointer of the graphical representation.
  * <br><b>Role</b>: With this method you get the graphic representation for this interface. But in most
  * case to get it you must use the @href CATVisManager#GenerateRepPathFromPathElement. 
  */
  virtual CATRep * GiveRep () = 0 ;

  /**
   * @nodoc
   */
  virtual HRESULT GiveContextualRep( CATVisRepContext & iContext, CATRep *& oRep ) = 0;

  /**
   * Processes visualization notifications.
   * <br><b>Role</b>: 
   * It is the usual method called by the @href CATVisManager for processing 
   * all types of visu notifications concerning 
   * any graphical change of one component. Such visu notifications have to derive from @href CATModify. 
   * For instance
   * when the color of one component is changed, a visualization event @href CATModifyVisProperties is 
   * sent, then received by the 
   * @href CATVisManager and finally processed by any visualization extension of the component through 
   * the <tt>ModifyRep</tt> method. 
   *
   * @param iInfo
   * the input visu event deriving from @href CATModify
   * 
   * @return
   * status of processing:
   * <ul>
   * <li> 0 when the input visu event has not been processed </li>
   * <li> 1 when the input visu event has been procesed </li>
   * </ul>
   */
  virtual int ModifyRep ( const CATNotification & iInfo ) = 0 ;

 /**
  * Makes visualization extension not point to their graphical representation anymore and conversely.
  * <br><b>Role</b>:
  * When one graphical representation is deleted, the @href CATVisManager provides a mechanism which ensures to find
  * the component and the visualization interface to which the deleting graphical representation is linked. This operation
  * can be done thanks to the model identifier enclosed into the graphical representation.
  * Then it is possible to update the corresponding visualization extension: this is typically where   
  * the @href #UnreferenceRep method is useful.
  *
  */
   virtual void UnreferenceRep () = 0 ;

   /**
    * Adds the graphical representation of one visualization extension into the output path of graphical representations.
    * <br><b>Role</b>:
    * This method is part of the usual mechanism of generating a path of graphical representations from a path of
    * components. And this mechanism is managed by the @href CATVisManager. 
    * @param iPathElt
    * path of components from which the current component is extracted.
    * @param ioPathRep
    * output path of graphical representations to fill in.
    * @return 
    * an HRESULT value.
    * <br><b>Legal values</b>:
    * <ul>
    * <li>S_OK if the operation succeeds </li>
    * <li>E_FAIL otherwise </li>
    * </ul>
    */
  virtual HRESULT BuildRepPath(const CATPathElement & iPathElt, CATRepPath & ioPathRep ) = 0;

  /**
    * Adds the graphical representation of one visualization extension into the output path of graphical representations.
    * <br><b>Role</b>:
    * The same as @href #BuildRepPath but it is for (pre)highlight purposes only.
    * @param iPathElt
    *  path of components from which the current component is extracted.
    * @param ioPathRep
    * output path of graphical representations to fill in.
    * @return 
    * an HRESULT value.
    * <br><b>Legal values</b>:
    * <ul>
    * <li>S_OK if the operation succeeds </li>
    * <li>E_FAIL otherwise </li>.
    * </ul>
    */
  virtual HRESULT BuildHighlightLook(const CATPathElement & iPathElt, CATRepPath & ioPathRep ) = 0;

  /**
   * Adds the component of the current visualization extension into the output path of components.
   * <br><b>Role</b>:
    * This method is part of the usual mechanism of generating a path of components from a path of graphical
    * representations. And this mechanism is managed by the @href CATVisManager. 
    * @param iPickPath
    * input path of graphical representations from which the graphical representation of the current extension is extracted.
    * @param ioPathElt
    * output path of components to fill in.
    * @return 
    * an HRESULT value.
    * <br><b>Legal values</b>:
    * <ul>
    * <li>S_OK if the operation succeeds </li>
    * <li>E_FAIL otherwise </li>.
    * </ul>
   */
  virtual HRESULT DecodeGraphic(const CATPickPath &iPickPath, CATPathElement &ioPathElt ) = 0;

  /**
  * @nodoc
  * Builds the graphical representation and sets a model identifier onto it.
  * <br><b>Role</b>:
  * <br><b>Deprecated</b>
  * <br>If no graphical representation exists, this method asks for its building
  * through the @href #BuildRep() method.
  * This method also sets a <tt>model identifier</tt> onto  the graphical representation so as to keep a link
  * to its object.
  * This method should not be overriden if you implement a visualization interface with the @href CATExtIVisu 
  * adapter.
  * @return 
  * a pointer to the graphical representation of one extension of any visualization interface.
  */
  virtual CATRep * GetRep () = 0 ;

  /**
   * Tests if the elements of a CATPathElement are valid for highlight.
   * <br><b>Role</b>: in the default implementation, calls recursively the method IsHighlightValid
   * on the elements of the CATPathElement that implement CATIVisu.
   * @param iPathElt
   * input path of components from which the current component is extracted.
   * @return 
   * an HRESULT value.
   * <br><b>Legal values</b>:
   * <ul>
   * <li>S_OK if the component is to be highlighted </li>
   * <li>E_FAIL otherwise </li>.
   * </ul>
   */
  virtual HRESULT IsHighlightValid(CATPathElement & iPathElt) = 0;

 
  /**
   * @nodoc
   */
  virtual HRESULT SetVisuRep(CATRep * iRep) = 0;

  /**
   * Sets the graphical representation of this component to an not uptodate state.
   *
   */
   virtual void SetRepNotUpToDate() = 0;

  /**
   * Tests whether or not the graphical representation of the current component is uptodate.
   * @return 
   * <ol>
   * <li>1 if the graphical representation of the component is uptodate</li>
   * <li>0 if the graphical representation of the component is not uptodate</li>
   * </ol>
   *
   */
  virtual int IsRepUpToDate() = 0;

}; 

/** @nodoc */
CATDeclareHandler(CATIVisu,CATBaseUnknown);

#endif
