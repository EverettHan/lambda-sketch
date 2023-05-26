// COPYRIGHT DASSAULT SYSTEMES 2008

#ifndef CATIVisuFilter_h
#define CATIVisuFilter_h
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#include <CATVisItf.h>

#include <CATBaseUnknown.h>
#include "CATListOfInt.h"

ExportedByCATVisItf extern IID IID_CATIVisuFilter;

/**
* Interface for visibility in layer filter.
* <br>Interface implemented by the @href CATVisManager that you retrieve by the
* static function @href CATVisManager#GetVisManager . 
*/
class ExportedByCATVisItf CATIVisuFilter: public CATBaseUnknown
{
  CATDeclareInterface;
  
 public :

  /**
  * Returns the visibility state of an object or a layer in the current layer filter.
  * <br><br>Role</b>: This method gives the visibility state of an object or a layer. Two usages for this
  * method:
  * <ul>
  * <li>iObject=NULL, and you only set iLayerNumber</li>
  * <p>In this case, you want to know whether a layer is visible in the current filter.</p>
  * <li>iObject!=NULL, and you don't set iLayerNumber</li>
  * <p>In this case, you want to know whether an object is visible in the current filter.</p>
  * </ul>
  * <p>The reference layer filter for the query is the layer filter currently applied on the currently edited object.
  * The currently edited object is the UIActive object in the current editor (CATFrmEditor).
  * <p>This means an interactive context is needed for this method to work correctly. It may not work correctly
  * if used in a batch context because there will be no current editor and no UIActive objects in editors.
  * In a batch context the method will work fine only if the context contains only one editor and if this editor
  * edits a single object and no assembly (i.e. no hierarchy of UIActivable objects).
  * @param iObject
  * The object you want to query. Remember objects placed in no layer are always visible.
  * @param iLayerNumber
  * The number of the layer you want to query:
  * <br>
  * <ul>
  * <li>a valid value ranges between 0 and 999,  </li>
  * <li>-1, the method ignores the value. </li>
  * </ul>
  * Remember the current layer is always visible.
  * @return
  * S_OK if the layer or object is visible, E_FAIL if not visible.
  */
  virtual HRESULT IsVisible (const CATBaseUnknown *iObject,int iLayerNumber=-1) = 0;

  /** @nodoc */
  virtual HRESULT SaveCurrentLayer (const unsigned int layerNumber) = 0;
  /** @nodoc */
  virtual HRESULT LoadCurrentLayer (unsigned int *layerNumber) = 0;
  /** @nodoc */
  virtual void SetModelFilter(unsigned char * iLayerTab, unsigned int iSize) = 0;
  /** @nodoc */
  virtual HRESULT GetModelFilter (const unsigned char*& ioLayerTab, unsigned int& oSize) = 0;  
  /** @nodoc */
  virtual HRESULT GetVisibleLayerList (const CATBaseUnknown *iObject, CATListOfInt * opLayerNumberList) = 0;

};

#endif
