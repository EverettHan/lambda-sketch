#ifndef CATISO3DBagRep_H
#define CATISO3DBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2016

#include "SGInfra.h"
#include "CAT3DBagRep.h"

/**
* @class CATISO3DBagRep is a bag which sets a drawing priority for its children and siblings.
* There are only 4 layers : from 0 to 3 for the backest to the frontest elements (background, normal, foreground, topmost). The other values give undetermined behaviors.
* Per default, all the CATReps have a layer value equal to 1.
* 
* Rules for a CATISOBagRep with a layer 'l' :
*   1. The CATISOBagRep sets the layer 'l' for all its sub-tree until another CATISO3DBagRep is reached in the sub-hierarchy.
*   2. The CATISOBagRep sets the layer 'l+1' for all its next-siblings (and their sub-trees) until another CATISO3DBagRep is reached in the list of siblings.
**/
class ExportedBySGInfra CATISO3DBagRep : public CAT3DBagRep
{
	CATDeclareClass;
	
public:

	/**
	* @return create a CATISO3DBagRep instance with a given layer
	* @param iDrawLayer authorized values: 0 to 3
	*/
  static CATISO3DBagRep* CreateRep(int iDrawLayer);

	/**
	* Reset the layer of the current instance.
	* @param iDrawLayer authorized values: 0 to 3.
	*/
	void SetDrawLayer(unsigned int iDrawLayer);

	/**
	* @return the layer of the current instance.
	*/
  unsigned int GetDrawLayer();

	virtual ~CATISO3DBagRep();
	
	// AZX: (A2X migration) Making draw functions final 
	virtual void DrawShading(CATRender&, int) override final;
	virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
	virtual void Draw(CATRender& iRender, int iInside) override final;
	virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

protected:

	CATISO3DBagRep(int iDrawLayer);

private :
  unsigned int _drawLayer;
};

#endif // CATISO3DBagRep_H
