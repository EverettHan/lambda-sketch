#ifndef CATLayerFilter_h
#define CATLayerFilter_h

//********************************************************************
// CATIA Framework Visualization (FMN)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    defines the Layer filter mode 
//    
//
//********************************************************************
//
//  Usage:  used to apply layer filter on the graphic model 
//  ------                   
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATLayerFilter
//               CATFilter
//                CATBaseUnknown (SYSTEM framework)
//
//********************************************************************
//
//  Main Methods:
//  -------------
//              ApplyOnObject ( CATBaseUnknown * )
//
//********************************************************************

#include "SceneGraphManager.h"
#include "CATFilter.h"
#include "list.h"

class CATVisLayerFilter;
class ExportedBySceneGraphManager CATLayerFilter : public CATFilter
{
  CATDeclareClass;
  
public:
  
  enum Layer_Model_Apply { MODEL_LAYER, SETTING_LAYER, NO_LAYER};
  
  CATLayerFilter(unsigned char *iLayers=NULL,const int Nb_layers=0,int iModeApply=MODEL_LAYER);
  virtual ~CATLayerFilter (void) ;
  virtual CATFilter *Clone(void);
  // check if the filter is satisfied on the model object
  virtual Result ApplyOnObject ( CATBaseUnknown *object );

  static CATVisLayerFilter* ChangeCurrentVisFilter(CATVisLayerFilter* iFilter);

  static CATLayerFilter *_CurLayerFilter;

  private:
  ////////

   int  _ModeToApply;
   unsigned char *_Layers;
   int _NbLayers;

   static CATVisLayerFilter* _curVisLayerFilter;
};


#endif
