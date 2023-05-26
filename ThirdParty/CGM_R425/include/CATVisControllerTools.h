
// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATVisControllerTools_H
#define CATVisControllerTools_H

#include "SceneGraphManager.h"    

#include "CATVizBaseTools.h"
#include "CATPathElement.h"
#include "CATPickPath.h"
#include "CATReadWriteCgr.h"

class CATRep;
class CATBaseUnknown;
class CATRGBAColor;
class CATVisPropertiesValues;

enum CATVisCheckUpValue { CATVISCHECKUP_SURFACICREP = 0	};

extern HRESULT ExportedBySceneGraphManager GenerateRepPathFromModelPath (CATRep *iRep, const CATPathElement & modLocalization, CATRepPath & vueLocalization );
extern HRESULT ExportedBySceneGraphManager GenerateModelPathFromRepPath (CATBaseUnknown *iModel, const CATPickPath& vueInformation, CATPathElement& oPathElement);

// --- Graphical Attributes Services -------------------------------------------------------------
extern ExportedBySceneGraphManager HRESULT GetRGBAColorFromSceneGraph(CATRep *iSceneGraphRoot, CATULONG32 &oTabSize, CATRGBAColor *&oColorTab);

extern ExportedBySceneGraphManager 
  HRESULT GetRGBAColorFromSceneGraph(  CATULONG32 iId , /* */
  int iContext , /* */
  CATRep * iSceneGraphRoot , /* */
  CATRGBAColor &oRequestedRGBA, /* */
  int &oSubElementSize, /* */
  CATULONG32 *&oSubElementIdTab , /* */
  CATRGBAColor *&oSubElementRGBATab /* */);

extern ExportedBySceneGraphManager 
  HRESULT GetGraphicAttributeFromSceneGraph(  
  CATULONG32 iId , /* input Identifier of one object */
  int iContext , /* input Context of the object user would like to find out (example: 2 for Geometric object, 1 for Feature of PrtCont */
  CATRep * iSceneGraphRoot , /* input scene graph */
  CATGraphicAttributeSet &oRequestedGraphicAttribute, /* requested graphic attribute*/
  int &oSubElementSize, /* number of subelements of the object referenced by iId*/
  CATULONG32 *&oSubElementIdTab , /* Array of dimension oSubElementSize holding in the identifier of each sub-elements of object iId */
  CATGraphicAttributeSet *&oSubElementGraphicAttributeTab /* Array of dimension oSubElementSize holding in the identifier of each sub-elements of object iId */);


/**
* This function retrieving graphics properties values of requested sub element.
*
*  @param  iId
*      Input Identifier of one object . <br>
*  @param  iContext
*      input Context of the object user would like to find out (example: 2 for Geometric object, 1 for Feature of PrtCont . <br>
*  @param  iSceneGraphRoot
*      input scene graph. <br>
*  @param  oRequestedGraphicAttribute
*       requested VisProperties Values. <br>
*  @param  oSubElementSize
*       number of subelements of the object referenced by iId. <br>
*  @param  oSubElementIdTab
*       Array of dimension oSubElementSize holding in the identifier of each sub-elements of object iId . <br>
*  @param  oSubElementGraphicAttributeTab
*       Array of graphics properties values holding in the identifier of each sub-elements of object iId. <br>
*/ 

extern ExportedBySceneGraphManager HRESULT GetGraphicAttributeFromSceneGraph ( CATULONG32 iId,int iContext , CATRep * iSceneGraphRoot, CATVisPropertiesValues &oRequestedGraphicAttribute,int &oSubElementSize, CATULONG32 *&oSubElementIdTab , CATVisPropertiesValues *&oSubElementGraphicAttributeTab ); 

// --- CHECK UP Services ---------------------------------------------------------------------------
extern ExportedBySceneGraphManager HRESULT CATVisCheckUp(const CATRep * iRep, CATVisCheckUpValue iV, FILE * oFile = NULL);

//Permit to specify if a cgr buffer to transform is used in CATDMUUtility context
extern HRESULT ExportedBySceneGraphManager CATVisSetTransformCGRContext ( int iCGRContext=0 );

extern HRESULT ExportedBySceneGraphManager CATTransformCgrBufferForPart ( char *iBuffer, int iLength, char*& oBuffer, int& oLength, CATSettingCgr& oSetting ); 
extern HRESULT CATVisIsApplicativeContainerOK(char *iBuffer, int iLength);
extern HRESULT CATVisCopyApplicativeContainers(char * iBuffer, int iLength, char * & oBuffer, int & oLength);
extern CATSettingCgr ExportedBySceneGraphManager CATGetVisuToolsCgrSettings (CGRSettingContext iContext);

#endif
