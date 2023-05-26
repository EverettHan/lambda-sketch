#ifndef CATModelForSubElements_H
#define CATModelForSubElements_H

//
//  copyright dassault systemes 2011
//  --------------------------------
//
//  FrameWork Visualization :
//  -------------------------
//
//          author : Sebastien Videcoq
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
#include "CATVizPtrList.h"

class CATVizPrimitive;

class CATGraphicPrimitive;

class  ExportedBySGInfra CATModelForSubElements : public CATBaseUnknown 
{
public :
	CATDeclareClass;

	CATModelForSubElements();
	virtual ~CATModelForSubElements();

	unsigned int GetNumberOfPrimitives();
	unsigned int GetIndex(unsigned int i);
	/**
	* Adds a V5 graphic primitive within the structure
	*/
	void AddGraphicalObject(unsigned int pickIndex, CATGraphicPrimitive * iGp);

	/**
	* Returns the referenced graphical object.
	* It is up to the user to release the returned pointer when it is no more used.
	* The requester has to use the Release() method when he has finished using the returned
	* pointer.
	*/
	virtual CATGraphicPrimitive * GetGraphicalObject(unsigned int index);

	/**
	* Adds a V6 primitive within the structure
	*/
	void AddPrimitive(unsigned int pickIndex, CATVizPrimitive * primitive);

	/**
	* Returns the referenced V6 primitive.
	* It is up to the user to release the returned pointer when it is no more used.
	* The requester has to use the Release() method when he has finished using the returned
	* pointer.
	*/
	virtual CATVizPrimitive * GetPrimitive(unsigned int index);

	/**
	* Compares implementations pointed by interfaces.
	* @param iobject
	*   The second object to be compared to.
	* @return 1 if the implementations are identical.
	*/
	virtual int IsEqual(const CATBaseUnknown *iobject) const;

private:
	unsigned int _nbPrimitives;
	unsigned int _primitiveType;
	CATVizPtrList<unsigned int> _pickIndices;
	CATVizPtrList<void> _primitives;
};


#endif
