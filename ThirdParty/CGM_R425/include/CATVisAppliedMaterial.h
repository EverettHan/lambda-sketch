// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATVisAppliedMaterial_H
#define CATVisAppliedMaterial_H

/**
* Class representing a list of materials as they are applied on a face.
*
* <br><b>Role</b>:
* The Mapping Operator is separated from the Graphic Material,
* since a given material can be mapped in many differnet ways.
* Ideally, CATVisAppliedMaterial should play the role of an envelope.
* Indeed the purpose of a CATVisAppliedMaterial should be to aggregate all the aspects of a CATGraphicMaterial:
* ColorPoperites, TextureProperties, ShaderProperties, MapingOperator etc.
* <p>
*
* @href CATGraphicMaterial, CATMaterialApplication, CATMappingOperator
*/

#include "SGInfra.h"

class CATGraphicMaterial;
class CATMappingOperator;

//++ E8C : Multi Materials
#include "list.h"
#include "CATSysBoolean.h"
class CATMaterialApplication;

//-- E8C : Multi Materials

  
class ExportedBySGInfra CATVisAppliedMaterial
{

public:

	/** Constructor of an empty CATVisAppliedMaterial */
  CATVisAppliedMaterial();
	/** Destructor */
  virtual ~CATVisAppliedMaterial();

	// MATERIAL MANAGEMENT //

	/** Sets the effective applied CATGraphicMaterial */
  void SetGraphicMaterial(CATGraphicMaterial* ipMat);
	/** Gets the effective applied CATGraphicMaterial */
  CATGraphicMaterial* GetGraphicMaterial();

	// MAPPING OPERATOR MANAGEMENT //

	/** Sets the Mapping Operator */
  void SetMappingOperator(CATMappingOperator* ipOp);
	/** Gets the Mapping Operator */
  CATMappingOperator* GetMappingOperator();

	// INHERITANCE MANAGEMENT //

	/** Sets the effective applied inheritance number */
  void SetMaterialInheritance (unsigned int iInheritance);
	/** Gets the effective applied inheritance number */
  unsigned int GetMaterialInheritance();

	// LIST OF MATERIALS MANAGEMENT //

	/** Adds a CATMaterialApplication to the list
  * Returns TRUE if MappingOperator has changed, FALSE otherwise
  */
  CATBoolean AddMaterialApplication( const CATMaterialApplication& iMatApp );
	/** Removes a CATMaterialApplication from the list
  * Returns TRUE if MappingOperator has changed, FALSE otherwise
  */
  CATBoolean RemoveMaterialApplication( const CATMaterialApplication& iMatApp );
  /** Removes a CATMaterialApplication pointer from the list
  * Returns TRUE if MappingOperator has changed, FALSE otherwise
  */
  CATBoolean RemoveMaterialApplication( const CATMaterialApplication* ipMatApp );
	/** Gets the effective applied CATMaterialApplication, after resolution of the list of CATMaterialApplication, according to new materials inheritance rules */
	CATMaterialApplication * GetMaterialApplication();
	/** Sets the list of CATMaterialApplication */
	void SetListOfMaterialApplication( const list<CATMaterialApplication>& iMatAppList );
	/** Gets the list of CATMaterialApplication */
	const list<CATMaterialApplication>& GetListOfMaterialApplication() const;
	/** Gets the number of CATMaterialApplication in the group */
	unsigned int GetNumberOfMaterialApplication() const;
  /** Remove all CATMaterialApplication from the list */
  void RemoveAllMaterialApplication();

private:

  // copy not allowed
  CATVisAppliedMaterial (const CATVisAppliedMaterial &);
  CATVisAppliedMaterial & operator=(const CATVisAppliedMaterial &);

	/** list of CATMaterialApplication
  * It is semi-resolved : at any time, the effective CATMaterialApplication applied to the 3DRep,
  * according to new materials inheritance rules, is at the queue of the list.
  */
  list<CATMaterialApplication> 	_MatAppList;

  CATMappingOperator*						_pOperator;

};

#endif
