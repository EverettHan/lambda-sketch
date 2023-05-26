// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATVizExtendedPrimitiveSetWithMaterial_H
#define CATVizExtendedPrimitiveSetWithMaterial_H

#include "SGInfra.h"
#include "CATVizExtendedPrimitiveSet.h"
#include "CATVisAppliedMaterial.h"

class CATVizPrimitive;
//class CATVizVertexBuffer;
class CATGraphicAttributeSet;
class CATMappingOperator;

//++ E8C : Multi Materials
#include "CATListOfInt.h"
class CATMaterialApplication;
class CATGroupOfFacesWithMaterials;
//-- E8C : Multi Materials


class ExportedBySGInfra CATVizExtendedPrimitiveSetWithMaterial : public CATVizExtendedPrimitiveSet
{

public:

	/** Constructor of an empty CATVizExtendedPrimitiveSetWithMaterial */
	CATVizExtendedPrimitiveSetWithMaterial();
	/** Constructor of a CATVizExtendedPrimitiveSetWithMaterial with primitives, GAS, materials and type initialization */
	CATVizExtendedPrimitiveSetWithMaterial(unsigned int nbPrimitives, CATVizPrimitive** primitives, CATGraphicAttributeSet* attributes, CATGraphicMaterial** materials, CATVizGeomType type);
	/** Constructor of a CATVizExtendedPrimitiveSetWithMaterial with primitives, GAS, materials, groups and type initialization */
  CATVizExtendedPrimitiveSetWithMaterial(unsigned int nbPrimitives, CATVizPrimitive** primitives, CATGraphicAttributeSet* attributes, list<CATMaterialApplication>* matapps, unsigned int nbGoup, CATGroupOfFacesWithMaterials** groups, CATVizGeomType type);

protected:
	
	/** Destructor */
	virtual ~CATVizExtendedPrimitiveSetWithMaterial();

public:

	/** Gets the ith CATGraphicMaterial */
	virtual CATGraphicMaterial* GetGraphicMaterial(unsigned int i);
	/** Sets the ith CATGraphicMaterial */
	void SetGraphicMaterial(unsigned int i, CATGraphicMaterial* ipMat);
	/** Gets the ith CATMappingOperator */
	virtual CATMappingOperator* GetMappingOperator(unsigned int i);

	/** Streaming */
	virtual void Stream(CATStreamer &oStr, int savetype = 0);
	/** Unstreaming */
	virtual void UnStream(CATStreamer &iStr);

	/** Is there at least one CATGraphicMaterial ? */
	virtual CATBoolean WithGraphicMaterial();

	//++ VBO MANAGEMENT
	virtual void AllocateVBOPrimitives(unsigned int nbPrimitives);
	virtual CATGraphicMaterial *GetVBOGraphicMaterial(unsigned int i);
	virtual void SetVBOPrimitive(unsigned int i, CATVizPrimitive * iFace, CATGraphicAttributeSet * iGAS=NULL, CATGraphicMaterial * iMat=NULL);
	//-- VBO MANAGEMENT

	/** Is the at least one CATGroupOfFacesWithMaterials ? */
	virtual CATBoolean WithGroupsOfFacesWithMaterials() const;
	/** Gets the ith CATVisAppliedMaterial */
	virtual CATVisAppliedMaterial* GetVisAppliedMaterial( unsigned int i ) const;
	/** Gets the ith CATGroupOfFacesWithMaterials */
	virtual CATGroupOfFacesWithMaterials* GetGroupOfFacesWithMaterials( unsigned int i ) const;
	/** Gets the number of CATGroupOfFacesWithMaterials */
	virtual unsigned int GetNumberOfGroups() const;

private:

	// Copy not allowed
	CATVizExtendedPrimitiveSetWithMaterial (const CATVizExtendedPrimitiveSetWithMaterial &);
	CATVizExtendedPrimitiveSetWithMaterial & operator=(const CATVizExtendedPrimitiveSetWithMaterial &);

	// The size of _materials is the same as _nbPrimitives defined in the base class
	list<CATVisAppliedMaterial>					_materials;

	list<CATGroupOfFacesWithMaterials>	_groups;																// list of CATGroupOfFacesWithMaterials
};

#endif
