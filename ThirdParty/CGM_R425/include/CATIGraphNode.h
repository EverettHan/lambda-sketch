/* -*-c++-*- */
#ifndef CATIGraphNode_h
#define CATIGraphNode_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Level L1 
  * @CAA2Usage U3
  */


#include <CATBaseUnknown.h>
#include "CATListOfInt.h"

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATIGraphNode;

class CATIGraphLink;
class CATIGraphContainer;
class CATUnicodeString;
class CATDlgContextualMenu;
class CATListValCATUnicodeString;
class CATPixelImage;

/**
* Specification on node to define whether it is expand or not.
* @param HasChildrenCollapsed
*        The node has children, and they are not expanded, with an activator +.
* @param HasChildrenExpanded
*        The node has children, and they are expanded, with an activator -.
* @param NoShowChildrenCollapsed
*        The node has children, and they are not expanded, without activator
* @param NoShowChildrenExpanded
*        The node has children, and they are expanded, without activator
* @see CATIGraphNode#UpdateState
*/

enum CATNavigNodeState {
	HasChildrenCollapsed=0,
	HasChildrenExpanded=1,
	NoShowChildrenCollapsed=2,
	NoShowChildrenExpanded=3
};

/**
* Interface to customize graph's nodes physical representation.
* <b>Role:</b> This interface is automatically implemented on tree nodes.
*  If you use the <tt>CATIGraphNode</tt> methods in the @href CATINavigModify#UpdateElem 
* method, the update of the node is automatically done, otherwise call the 
* @href CATINavigElement#Update method to refresh the visualization.
* <br><br>A node is a text with or without:
*  <ul>
*     <li>A fill background: @href #SetFillStyle </li>
*     <li>A frame around: @href #SetDecoration </li>
*     <li>A frame shadow: @href #SetShadowOut </li>
*  </ul>
*/
class ExportedByCATOmnMain CATIGraphNode: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/** @nodoc 
   * Returns the father container.  
   * @return 
   *    The father container
   * Returned pointer must be released.  
	*/
	virtual CATIGraphContainer* GetGraphContainer()=0;
	
	/**
	* Returns number of father links.
    * @return 
    *    The number of father links
	*/
	virtual int GetNbFatherLinks()=0;

	/**
	 * Returns a father link by its index.
   * @param iIndex
   *    The index of the link
   * @return 
   *    The father link
   * Returned pointer must be released. 
	 */
	virtual CATIGraphLink* GetIndexedFatherLink(int iIndex)=0;
	
	/**
	 * Returns number of child links.
     * @return 
     *    The number of child links
	 */
	virtual int GetNbChildLinks()=0;

	/** 
	 * Returns a child link by its index.
     * @param iIndex
     *    The index of the link
     * @return 
     *    The child link
     * Returned pointer must be released. 
	 */
	virtual CATIGraphLink* GetIndexedChildLink(int iIndex)=0;

	/** @nodoc */
	virtual void SortChild(CATListOfInt& ordre)=0;

	/**
	* Sets node text.
    * <br><b>Role:</b>This method enables you to modify the text associated 
    * with the node. The default text being the text returned by the
    * @href CATINavigateObject#GetIdentificators method. 
    * <br>However, modify the 
    * text should be used temporary, because the Search mechanism is based on 
    * the text returned by the @href CATINavigateObject#GetIdentificators method. 
	* @param iText
	*     The text associated to node. There are as many strings as lines.  
	*/
	virtual void SetText(const CATListValCATUnicodeString& iText)=0;

	/**
	* Sets icon on the node.
	* @param iChaine
	*     The name of the icon.
	*/
	virtual void SetPixelImage(const CATUnicodeString& iChaine)=0;

	/**
	* Sets node color.
    * <br><b>Role:</b>This method enables you to modify the background color of the text.
    * The text color being automatically computed to have enought contrast.
    * <br>This color is useless if the node is without background, i.e. the @href #GetFillStyle 
    *  method returns <tt>0</tt>. 
	* @param iCouleur
	*       The index of the color.
    *       <br><b>Legal values:</b><tt>iCouleur</tt> ranges from 0 to 255. 
    *       You can use the <tt>CATColorMap#GetColor</tt> method to retrieve the
    *       r,g and b components associated with an index color.
	*/
	virtual void SetColor(int iCouleur)=0;

	/**
	* Sets node highlight mode.
	* @param iMode
    *      The highlight mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The node has to be highlighted, 
    *       <tt>0</tt>: otherwise.
	*/
	virtual void SetHighlight(int iMode)=0;

	/**
	* Retrieves node highlight mode.
	* @return 
    *      The highlight mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The node is highlighted, 
    *       <tt>0</tt>: otherwise.
	*/
	virtual int IsHighlighted()=0;

	/**
	* Sets node frame shadow mode. 
    * <br><b>Role:</b>This method enables you to set or not a shadow on the frame. The value
    * of this mode is useless if the node is without frame, i.e. the @href #IsDecorated method 
    * returns <tt>0</tt>. 
	* @param iMode
    *      The frame shadow mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The frame has a shadow, 
    *       <tt>0</tt>: otherwise.
	*/

	virtual void SetShadowOut(int iMode)=0;

	/**
	* Retrieves node frame shadow mode. 
	* @return 
    *      The frame shadow mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The icon has a shadow, 
    *       <tt>0</tt>: otherwise.
	*/
	virtual int IsShadowOut()=0;

	/**
	* Sets node frame mode. 
    * <br><b>Role:</b>This method enables you to set or not a frame around the text of
    * the node.
	* @param iMode
    *      The node frame mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The node has a frame,
    *       <tt>0</tt>: otherwise.
	*/
	virtual void SetDecoration (int iMode)=0;

	/**
	* Retrieves node frame mode. 
	* @return 
    *      The node frame mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The node has a frame,
    *       <tt>0</tt>: otherwise.
	*/
	virtual int IsDecorated()=0;

	/**
	* Sets node background mode. 
    * <br><b>Role:</b>This method enables you to set or not a background behind the text.
    * The color of the background being defined by the @href #SetColor method.
	* @param iFill
    *     The background mode
    *      <br><b>Legal values:</b> <tt>1</tt>: The background is filled,
    *       <tt>0</tt>: otherwise.
	*/
	virtual void SetFillStyle(int iFill)=0;

	/**
	* Retrieves node background mode. 
	* @return 
	*      The background mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The background is filled,
    *       <tt>0</tt>: otherwise.
	*/
	virtual int GetFillStyle()=0;

	/**
	* Sets node underline mode.
	* @param iMode
    *      The node underline mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The text is underlined
    *       <tt>0</tt>: otherwise
	*/

	virtual void SetUnderlineMode ( int iMode )=0;
	
    /**
	* Retrieves node underline mode.
	* @return 
    *      The node underline mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The text is underlined
    *       <tt>0</tt>: otherwise
	*/
	virtual int GetUnderlineMode()=0;

	/**
	* Sets node expand mode.
	* @param iState
	*      The node state.
	*/
	virtual void UpdateState(CATNavigNodeState iState)=0;

	/**
	* Retrieves node expand mode.
    * @return
    *      The expand node mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The node is expanded
    *       <tt>0</tt>: The node is collapsed
	*/
	virtual int IsExpanded()=0;

	/**
	* Retrieves node contextual menu.
    * <br><b>Role:</b>This method is useful to modify the default contextual menu associated
    * with a node. In the @href CATINavigElement#ProcessAfterMethod you can call this method
    * and add items to the returned menu.
    * @return
    *    The node contextual menu.
	*/
	virtual CATDlgContextualMenu* GetContextualMenu()=0;

	/**
	* Adds a mask on an icon.
	* @param iFile
	*        path of the mask to add
	* @param XVal
	*        coordinate of mask ( usually 0 )
	* @param YVal
	*        coordinate of mask ( usually 0 )
	* @param TransVal
	*        Flag to activate the transparency of the mask.
  * <ul>
  *       <li>if TransVal=0, the mask is completely opaque. </li>
  *       <li>if TransVal=1, the mask is transparent for all pixels which have the same color than this one on the top left.</li>
  * </ul>
	*/
	virtual void AddMask ( const CATUnicodeString& iFile,int XVal,int YVal,int TransVal=0)=0;
	
    /**
	* Removes last mask of an icon.
	* @return 
	*       0 if succeeded
	*   <br>-1 otherwise. 
	*/
	virtual int RemoveLastMask()=0;

	/**
	* Removes all masks of an icon.
	*/
	virtual void RemoveAllMasks()=0;

  /**
   * Returns the pixel image associated with the node.
   * @return
   *    The pixel image.
   */
	virtual const CATPixelImage* GetPixelImage()=0;

	/** @nodoc */
	virtual void SetPixelImage( const CATPixelImage* image )=0;

};

CATDeclareHandler ( CATIGraphNode, CATBaseUnknown);


#endif

