//===================================================================
// CATGroupOfFacesWithMaterials.h
// Header definition of class CATGroupOfFacesWithMaterials
// COPYRIGHT DASSAULT SYSTEMES 2014
//===================================================================


#ifndef CATGroupOfFacesWithMaterials_H
#define CATGroupOfFacesWithMaterials_H

#include "SGInfra.h"

#include "list.h"
#include "CATListOfInt.h"
#include "CATUnicodeString.h"

#include "CATEventSubscriberTypedefs.h"

class CATMaterialApplication;
class CATStreamer;

//-----------------------------------------------------------------------

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

/** CATGroupOfFacesWithMaterials Class Definition.
* This class contains information about a group of CAT3DFaceGP and CATMaterialApplication applied to it.
* @member _ListOfFaces
* List of CAT3DFaceGP indices in the CATSurfacicRep they belong to.
* Be careful : the first element has index 1.
* @member _MatAppList
* List of CATMaterialApplication applied to the _ListOfFaces.
* It is semi-resolved : at any time, the effective CATMaterialApplication applied to the group,
* according to new materials inheritance rules, is at the queue of the list.
* @member _Name
* Name of the CATGroupOfFacesWithMaterials, for identification purpose.
* @member _cb
* Callback on the group, used in order to react to material panel interaction.
*
* @href CATMaterialApplication
*/
class ExportedBySGInfra CATGroupOfFacesWithMaterials
{
public:

	/** Constructor of an empty CATGroupOfFacesWithMaterials */
	CATGroupOfFacesWithMaterials();
	/** Constructor of a CATGroupOfFacesWithMaterials, with name initilization */
	CATGroupOfFacesWithMaterials(const CATUnicodeString& name);
	/** Destructor */
	virtual ~CATGroupOfFacesWithMaterials();

	// FACES MANAGEMENT //

	/** Adds a face to the group */
	void AddFace(int num_face);
	/** Remove a face from the group */
	void RemoveFace(int num_face);
	/** Gets the number of faces in the group */
	int GetNumberOfFaces() const;
	/** Sets the list of faces */
	void SetListOfFaces(const CATListOfInt& iList);
	/** Gets the list of faces */
	const CATListOfInt& GetListOfFaces() const;

	// MATERIALS MANAGEMENT //

	/** Adds a CATMaterialApplication to the group */
	void AddMaterialApplication(const CATMaterialApplication& iMatApp);
	/** Removes a CATMaterialApplication from the group */
	void RemoveMaterialApplication(const CATMaterialApplication& iMatApp);
	/** Gets the number of CATMaterialApplication in the group */
	int GetNumberOfMaterialApplication() const;
	/** Gets the effective CATMaterialApplication applied to the group, after resolution of the list of CATMaterialApplication, according to new materials inheritance rules */
	CATMaterialApplication* GetMaterialApplication() const;
	/** Sets the list of CATMaterialApplication */
	void SetListOfMaterialApplication(const list<CATMaterialApplication>& iMatAppList);
	/** Gets the list of CATMaterialApplication */
	const list<CATMaterialApplication>& GetListOfMaterialApplication() const;

	// NAME MANAGEMENT //

	/** Sets the name of the group */
	void SetName(const CATUnicodeString& name);
	/** Gets the name of the group */
	CATUnicodeString GetName() const;

  // CALLBACK MANAGEMENT //

  /** Sets the callback of the group */
  void SetMaterialCallback(const CATCallback& cb);
  /** Gets the callback of the group */
  CATCallback GetMaterialCallback() const;

  // STREAMING MANAGEMENT //

  /** @nodoc */
  void Stream( CATStreamer& str );
  /** @nodoc */
  void Unstream( CATStreamer& str );
  /** @nodoc */
  CATBoolean GetStreamable();

private:

	CATGroupOfFacesWithMaterials (CATGroupOfFacesWithMaterials &);
	CATGroupOfFacesWithMaterials& operator=(CATGroupOfFacesWithMaterials&);

	CATListOfInt									_ListOfFaces;
	list<CATMaterialApplication>	_MatAppList;
	CATUnicodeString							_Name;

  CATCallback                   _cb;

};

//-----------------------------------------------------------------------

#endif
