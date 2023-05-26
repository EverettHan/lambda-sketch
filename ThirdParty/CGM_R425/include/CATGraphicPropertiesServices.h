#ifndef CATGraphicPropertiesServices_H
#define CATGraphicPropertiesServices_H

//
//  copyright dassault systemes 1998
//  --------------------------------
//
//  FrameWork GeometryVisualization :
//  -------------------------------
//
//          author : FBJ
//
//  ---------------------------------------------------------------------------

#include "CATGraphicProperties.h"
#include "CATBaseUnknown.h"
#include "CATIVisProperties.h"

class CATIStandardValue;
class CATIVisProperties;

//----------------------------------------------------------------------------------
//		Standard
//----------------------------------------------------------------------------------

// applique les proprietes graphiques standard "standardName" a l'objet "obj"
// cette fonction ne peut pas etre appelee si de nouveau CATVisGeomtype ont ete crees
// Elle ne fonctionne qu'avec les Geomtype courants :
//	* CATVPMesh
//	* CATVPEdge
//	* CATVPLine
//	* CATVPAsm
//	* CATVPPoint
//	* CATVPGlobaleType
// Cette fonction applique sur un objet tous les Geomtype qui sont definis sur cet objet
//	ex :	si un objet a des standards Mesh et Edge definis pour lui
//			alors on va lui appliquer dessus ces deux standards
//

// fonction pour migrer en douceur
ExportedByCATGraphicProperties HRESULT ApplyStandardVisuProperties(CATIStandardValue* standard, CATIVisProperties* ptrToVP,  char* standardName);


//----------------------------------------------------------------------------------
//		Application proprietes graphiques d'un objet a un autre
//----------------------------------------------------------------------------------

// applique toutes les proprietes graphiques d'un objet1 a un objet2 pour un geomtype donne
ExportedByCATGraphicProperties HRESULT ApplyVisPropertiesFromObjectToObject(CATBaseUnknown* objToRead, CATBaseUnknown* objToModified, CATVisGeomType geomtype);

// idem avant avec des CATIVisProperties*
ExportedByCATGraphicProperties HRESULT ApplyVisPropertiesFromObjectToObject(CATIVisProperties* objToRead, CATIVisProperties* objToModified, CATVisGeomType geomtype);

// applique toutes les proprietes graphiques d'un objet1 a un objet2 pour un geomtype donne
// la value passee entree contient a sa sortie les differentes modifications effectuees sur l'objet
// cele permet de la passer en argument d'une notif pour remettre a jour la visu
ExportedByCATGraphicProperties HRESULT ApplyVisPropertiesFromObjectToObject(CATBaseUnknown* objToRead, CATBaseUnknown* objToModified, CATVisGeomType geomtype, CATVisPropertiesValues& value);

// idem avant avec des CATIVisProperties*
ExportedByCATGraphicProperties HRESULT ApplyVisPropertiesFromObjectToObject(CATIVisProperties* objToRead, CATIVisProperties* objToModified, CATVisGeomType geomtype, CATVisPropertiesValues& value);

//----------------------------------------------------------------------------------
//		Application du layer courant
//----------------------------------------------------------------------------------

// fonction a appeler lors de la creation d'un nouvel objet
// pour lui appliquer le layer courant
ExportedByCATGraphicProperties HRESULT ApplyCurrentLayerToObj(CATBaseUnknown * obj);

ExportedByCATGraphicProperties HRESULT ApplyCurrentLayer(CATIVisProperties * obj);

//----------------------------------------------------------------------------------
//		Fonction de migration des proprietes graphiques inferieures a R4
//----------------------------------------------------------------------------------

ExportedByCATGraphicProperties HRESULT MigrateGraphicProperties(CATBaseUnknown* iObj);

//----------------------------------------------------------------------------------
//		vieille fonction de service
//----------------------------------------------------------------------------------

ExportedByCATGraphicProperties int IsLineicPropertyDefined(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsMeshPropertyDefined(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsAsmPropertyDefined(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsEdgePropertyDefined(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsPointPropertyDefined(CATBaseUnknown * obj);


ExportedByCATGraphicProperties int IsLineicPropertyMigrate(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsMeshPropertyMigrate(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsAsmPropertyMigrate(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsEdgePropertyMigrate(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int IsPointPropertyMigrate(CATBaseUnknown * obj);


ExportedByCATGraphicProperties int DeleteLineicProperties(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int DeleteMeshProperties(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int DeleteAsmProperties(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int DeleteEdgeProperties(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int DeletePointProperties(CATBaseUnknown * obj);

ExportedByCATGraphicProperties int DeleteGlobalProperties(CATBaseUnknown * obj);


// Geomtype specifique, utilise par l'extension des proprietes graphiques
// dans certains cas tres cibles, pour forcer la lecture d'autres geomtype
typedef int CATVisGeomType;
#define CATVPForceReading   65536

#endif

