/**
 * Created 26.06.2021 by N5P
 * An API to load .gltf and .glb files into a CAT3DBagRep SG scene
 *
 * Change History
 *  - 
 */
#ifndef VISGLTFREADER_H_
#define VISGLTFREADER_H_

#include "VisGltf.h"

class CAT3DBagRep;

/* Used to configure VisGltfReader on what and how to load a GLTF file into SG CAT3DBagRep */
struct ExportedByVisGltf VisGltfImportSettings {
	const char* m_pImportFilename = 0; // the full qualified path name of the .gltf or .glb file to load
	int m_LogLevel = 1; // set to > 1 to log more information besides error and warnings

	float m_ImportModelScale = 1000.0f; // scale put into the matrix of the m_pRootBagRep
	bool m_AdjustRootNodeMatrixRotation = true; // adjust the matrix of m_pRootBagRep to rotate model from glTF XYZ to NRE XZ(-Y)

	VisGltfImportSettings();
	~VisGltfImportSettings();
};

/* The result data after a succesul import of a GLTF file */
struct ExportedByVisGltf VisGltfImportResult {
	CAT3DBagRep* m_pRootBagRep = 0; // this will be the scene root after a succesful load

	VisGltfImportResult();
	~VisGltfImportResult();
};

class ExportedByVisGltf VisGltfReader
{
public:
	VisGltfReader();
	~VisGltfReader();

	bool Open(VisGltfImportResult& o_ImportResult, VisGltfImportSettings& i_Settings);
};


#endif
