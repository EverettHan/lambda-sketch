// COPYRIGHT Dassault Systemes 2005

#ifndef CATGraphicPropertiesManager_H
#define CATGraphicPropertiesManager_H

#include "CATGraphicProperties.h"
#include "CATVisGeomType.h"
#include "CATVisPropertyType.h"
#include "CATErrorDef.h"

#define CATGraphicPropertiesColor           0x01
#define CATGraphicPropertiesOpacity         0x02
#define CATGraphicPropertiesLineType        0x04
#define CATGraphicPropertiesWidth           0x08
#define CATGraphicPropertiesSymbol          0x10
#define CATGraphicPropertiesRenderingStyle  0x20

class CATBaseUnknown;
class CATIVisProperties;
class CATIStandardValue;
class CATVisPropertiesValues;
class ExportedByCATGraphicProperties CATGraphicPropertiesManager
{
public:
    static HRESULT ApplyDefault(CATBaseUnknown* iObj, CATBaseUnknown* iStandard, 
                                 const char* iFileName, const char* iStandardName);

    static HRESULT ApplyDefaultCreation(CATBaseUnknown* iObj, unsigned int iFilteredProperties = 0);

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
    static HRESULT ApplyStandard(CATBaseUnknown* iObj, CATBaseUnknown* iStandard, 
                                 const char* iFileName, const char* iStandardName);

    static HRESULT ApplyStandard(CATBaseUnknown* iObj, CATBaseUnknown* iStandard, 
                                 const char* iFileName, const char* iStandardName, 
                                 CATVisGeomType iGeomType, CATVisPropertyType iPropertyType = CATVPAllPropertyType);

    static HRESULT ApplyStandard(CATIVisProperties* iPtrToVP, CATIStandardValue* iStandard, 
                                 const char* iFileName, const char* iStandardName);

    static HRESULT ApplyStandard(CATIVisProperties* iPtrToVP, CATIStandardValue* iStandard, 
                                 const char* iFileName, const char* iStandardName, 
                                 CATVisGeomType iGeomType, CATVisPropertyType iPropertyType = CATVPAllPropertyType);

private:
    static HRESULT GetStandard(CATIStandardValue* iStandard, 
                               const char* iFileName, const char* iStandardName, 
                               CATVisGeomType iGeomType, CATVisPropertyType iPropertyType,  
                               CATVisPropertiesValues &value);

    CATGraphicPropertiesManager ();
    ~CATGraphicPropertiesManager ();
};

#endif
