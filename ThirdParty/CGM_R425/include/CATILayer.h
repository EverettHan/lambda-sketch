#ifndef CATILayer_H
#define CATILayer_H

///////////////////////////////////////////////////////////////////////////////
//    CATILayer.h                                               //
///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ApplicationFrame                                  //
//    AUTEUR:............Eric Ropars                                         //
//    DATE:..............24/01/1997                                          //
//             -----------------------------------------------               //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1997                                          //
///////////////////////////////////////////////////////////////////////////////

// COPYRIGHT DASSAULT SYSTEMES 1999

// ==========================================================================
//
// Interface for Layer management on Features
//
// ==========================================================================

#include "CATBaseUnknown.h"
#include "SceneGraphManager.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATILayer;
#else
extern "C" const IID IID_CATILayer;
#endif

//===================================================================================
//              CATILayer :  D E C L A R A T I O N S
//===================================================================================

class ExportedBySceneGraphManager CATILayer : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
  
public:

  virtual int	SetLayerId    (int id)	= 0;

  virtual int GetLayerId    ()	= 0;

  virtual int	IsVisible     ()	= 0;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATILayer, CATBaseUnknown ) ;

#endif
