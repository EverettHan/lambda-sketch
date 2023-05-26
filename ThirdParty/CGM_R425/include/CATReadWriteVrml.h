#ifndef CATReadWriteVrml_h
#define CATReadWriteVrml_h

class CATRep;
class CAT3DRep;
class CAT3DViewer;
class CATUnicodeString;
class CATColorMap;
#include "SceneGraphManager.h"


/**
 * Flag to specify the kind of graphic data we want to store in a Vrml2 file.
 * <br>This flag is used in <tt>CATReadVrml2</tt> and <tt>CATWriteVrml2</tt> methods.
 * @param SAVE_NONE
 *    To save nothing
 * @param SAVE_EDGES
 *    To save the edges
 * @param USE_NORMALS
 *    To save the normals (better quality but file larger in size)
 * @param USE_EDGES_NORMALS
 *    To save edges and normals
 */


// COPYRIGHT DASSAULT SYSTEMES	<1998>
//=============================================================================
//
// Function CATWriteVrml :
// This Function is the interface with the Vrml converter.
//
//=============================================================================
// Usage Notes:
//
//  InRep      : is an array of CATRep : all models present in the viewer.
//  InNbRep    : Number of Rep in the array.
//  In3DViewer : Is necessary to get the Color Map.
//  InFileName : The name of the Vrml Output file. Default is /tmp/Vrml.out
//  SaveEdgeFlag : Flag to say if you want to save edges, default is on 
//
//  Return 0 : Ok
//  Return 1 : Open of Output File Failed
//=============================================================================

ExportedBySceneGraphManager int CATWriteVrml(CATRep ** InRep, int InNbRep, CAT3DViewer * In3DViewer, const CATUnicodeString & InFileName, int iSaveEdgeFlag = 1);

//=============================================================================
//
// Function CATWriteVrml2 :
// This Function is the interface with the Vrml2 converter.
//
//=============================================================================
// Usage Notes:
//
//  InRep      : is an array of CATRep : all models present in the viewer.
//  InNbRep    : Number of Rep in the array.
//  In3DViewer : Is necessary to get the Color Map.
//  InFileName : The name of the Vrml Output file. Default is /tmp/Vrml.out
//  iSetting   : The CATSettingCgr flag to specify the kind of graphic data we want to store in the Vrml file. 
//
//  Return 0 : Ok
//  Return 1 : Open of Output File Failed
//=============================================================================

ExportedBySceneGraphManager int CATWriteVrml2(CATRep ** InRep, int InNbRep, CAT3DViewer * In3DViewer, const CATUnicodeString & InFileName, int iSetting = 1);

//=============================================================================
//
// Function CATReadVrml :
// This Function is the interface with the Vrml file.
//
//=============================================================================
// Usage Notes:
//
//  ifilename   : is the save file name
//  Return   : CAT3DRep * if OK  
//  Return   : NULL if  Ko
//
//=============================================================================
extern ExportedBySceneGraphManager CAT3DRep * CATReadVrml(const char *ifilename);

#endif







