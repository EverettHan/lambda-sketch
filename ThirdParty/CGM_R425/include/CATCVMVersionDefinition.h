// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATCVMVersionDefinition_H
#define CATCVMVersionDefinition_H

#include "CATCVMSysObjects.h"
//#include "CATCVMGeoObjects.h"
#include "CATListPOfCATCVMStreamVersions.h"
#include "CATBoolean.h"

class CATGeoFactory;
class CATBody;

enum CATCVMStreamVersionId 
{ 
  CatCVMStream_BetaVolatile = +0,
  CatCVMStream_BetaVolatile01 = +1, // stream du MaxTag
  CatCVMStream_BetaVolatile02 = +2, // modelisation nouvelles textures (sur attribut) 
  CatCVMStream_BetaVolatile03 = +3, // modelisation couleurs comme textures (sur attribut) 
  CatCVMStream_BetaVolatile04 = +4, // save des donnees applicatives 
  CatCVMStream_BetaVolatile05 = +5, // nouvelle modelisation des textures ref (avec CATCVMImage et CATCVMVisuData)
  CatCVMStream_BetaVolatile06 = +6, // bug sur CATCVMVisuData
  CatCVMStream_BetaVolatile07 = +7, // stream du reuse
  CatCVMStream_BetaVolatile08 = +8, // stream du CATCVMTextureSkewData
  CatCVMStream_BetaVolatile09 = +9, // ajout dans le stream de CATCVMVisuData 

  CatCVMStream_BetaVolatile10 =+10, // Nouvelle donnee de Texture : Integration TransfoUV pour mapping UV 

  UnknownVersion            = 999
};
#define CATMaxIdentifierNAME  32


class ExportedByCATCVMSysObjects CATCVMVersionDefinition 
{
public:
  //CATCVMVersionDefinition();
  //~CATCVMVersionDefinition();
  static void CleanAtExit();

  static void CATCVMStreamVersionsAvailable();

  static const CATCVMStreamVersion *QueryVersionDefinition(const char *iVersionName);

  static const CATCVMStreamVersion *QueryVersionDefinition(CATCVMStreamVersionId iVersionNumber);

  static int MakeSureInitDone(); 

  static const CATCVMStreamVersion *GetCurrentVersion();

  static const int _NbAvailableVersions;

  static CATBoolean IsNewerThanOrEqualTo(const CATCVMStreamVersionId newVersion, const CATCVMStreamVersionId oldVersion);


private :
  static const CATCVMStreamVersion               *_Current ;

  static CATLISTP(CATCVMStreamVersion)    _AvailableVersions ;

  static int _MakeSureInitDone;  

 

  static void CATCVMStreamName(const CATCVMStreamVersionId input, char *&ioName);

};

#endif
