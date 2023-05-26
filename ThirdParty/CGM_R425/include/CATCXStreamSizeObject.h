#ifndef CATCXStreamSizeObject_H
#define CATCXStreamSizeObject_H
//---------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES  2002
//  Classification des Objets de la CATGeoFactory
//---------------------------------------------------

//=============================================================================
// Jui  02  Portage 64 bits                                      HCN
//
// Mar. 04  Ajout des methodes pour mes besoins perfos d'Eval de
//          Taille de Stream dans le cadre du Stream Compact 
//  CATBoolean IsATopologicalObject(GMTypeClassify* iCurType);
//  CATBoolean IsAGeometricObject(GMTypeClassify* iCurType);
//  CATBoolean IsATopoGeometricObject(GMTypeClassify* iCurType);
//
// Apr.  04 Ajout d'un argument par defaut dans la methode StreamSizeObject
//=============================================================================

#include "CATCGMEvents.h"
#include "CGMTypeClassify.h"
#include "CATListOfCGMTypeClassify.h"
#include "CATHashTableOfCGMTypeClassify.h"
#include "CATHashTableOfCGMObjULong.h"
#include "ObjectTypesCGM.h"
#include "CGMV5Interop.h"

class CATDlgEditor;

#define CATCXStrBigObj 10

class ExportedByCGMV5Interop CATCXStreamSizeObject : public CATCGMEventStreamSizeObject 
{
public:
  //      kindofStreamSizeObject : champ de bits
  //             1 : taille de Stream par Type d'Objet 
  //             2 : taille de Stream pour chaque Object
  CATCXStreamSizeObject(CATGeoFactory *iFactory, short kindofStreamSizeObject);
  ~CATCXStreamSizeObject();

  CATCGMNewClassArrayDeclare;

  void StreamSize(short itp, CATCGMObject *impl, size_t streamSize, short iAddTransversMod=0);
  void UnStreamSize(short itp, CATCGMObject *impl, size_t streamSize);

  void StreamAttributeSize(short itp,   CATCGMAttributeDef *  iDefinition, size_t iCoreSize, size_t iAppliSize, short iAddTransversMod=0) ;
  void UnStreamAttributeSize(short itp, CATCGMAttributeDef *  iDefinition, size_t iCoreSize, size_t iAppliSize) ;
 
  void Dump(ostream & outputText, CATDlgEditor  *iEditor = NULL);
  
  CATULONG32  GetNbInstancesForType(short itp);
  CATULONG32  GetCumulatedSizeForType(short itp);

  int         GetNbInstancesForAll();
  CATULONG32  GetCumulatedSizeForAll();
  
  CATHashTabCGMTypeClassify * _HashTypes;
  CATLISTP(CGMTypeClassify) * _ListOfTypes;
  CATHashTabCGMObjULong     * _HashSize;
  
  int           nbBigFive,lowIdx;
  short         BigTyp[CATCXStrBigObj];
  CATCGMObject *BigObj[CATCXStrBigObj];
  CATULONG32  BigSize[CATCXStrBigObj];

private :

  void RegisterSize(const char *iCGMType, short itp, CATCGMObject *impl, CATCGMAttributeDef *  iDefinition,  CATULONG32  streamSize, short iAddTransversMod=0 );

  short        _kindofStreamSizeObject;

  CATBoolean IsATopologicalObject(int iCurType);
  CATBoolean IsAGeometricObject(int iCurType);
  CATBoolean IsATopoGeometricObject(int iCurType);
  CATBoolean IsAnAttribute(int iCurType);
  CATBoolean IsASharpness(int iCurType);
  CATBoolean IsALyingOn(int iCurType);


  // Switch generation of report (Full / Reduced)
  void _DumpFullReport(ostream & outputText, CATDlgEditor  *iEditor = NULL);
  void _DumpForCartography(ostream & outputText, CATDlgEditor  *iEditor = NULL);

};


#endif
