/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIGraphLink_h
#define CATIGraphLink_h

/**
  * @CAA2Level L1 
  * @CAA2Usage U3
  */

#include <CATBaseUnknown.h>

#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATIGraphLink;

class CATIGraphNode;

/**
* Interface to customize graph's link physical representation.
* <b>Role:</b> This interface is automatically implemented on tree nodes.
*  
*/
class ExportedByCATOmnMain CATIGraphLink: public CATBaseUnknown
{
	CATDeclareInterface;
public:

    /**
    * Retrieves the father node.
    * @return 
    *  The father node.
    */
	virtual CATIGraphNode* GetFatherNode()=0;

    /**
    * Retrieves the child node.
    * @return 
    *  The child node.
    */
	virtual CATIGraphNode* GetChildNode()=0;

	/**
    * Sets the link color.
    * @param iLinkColor
	*       The index of the color.
    *       <br><b>Legal values:</b><tt>iCouleur</tt> ranges from 0 to 255. 
    *       You can use the <tt>CATColorMap#GetColor</tt> method to retrieve the
    *       r,g and b components associated with an index color.
    */
	virtual void SetColor(int iLinkColor)=0;

	/**
	* Sets link highlight mode.
	* @param iMode
    *      The highlight mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The link has to be highlighted, 
    *       <tt>0</tt>: otherwise.
	*/
	virtual void SetHighlight(int iMode)=0;

	/**
	* Retrieves link highlight mode.
	* @return 
    *      The highlight mode.
    *      <br><b>Legal values:</b> <tt>1</tt>: The link is highlighted, 
    *       <tt>0</tt>: otherwise.
	*/
	virtual int IsHighlighted()=0;

};

// Declaration du handler

CATDeclareHandler ( CATIGraphLink, CATBaseUnknown);


#endif

