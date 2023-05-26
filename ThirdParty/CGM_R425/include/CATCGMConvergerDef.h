#ifndef CATCGMConvergerDef_H
#define CATCGMConvergerDef_H

// COPYRIGHT DASSAULT SYSTEMES 2022
 
  enum CATCVG_ApplicationName
  {    
    CATCVG_APPLI_CGM                = 1,
    CATCVG_APPLI_Machining,
    CATCVG_APPLI_PartDesign,
    CATCVG_APPLI_SheetMetal
  };

  enum CATCVG_CreationType
  {
    CATCVG_CREATE_Undef             = 0,
    CATCVG_CREATE_ExtrPrim          = 1,
    CATCVG_CREATE_ExtrReco,
    CATCVG_CREATE_LiveBody,
    CATCVG_CREATE_BRepDRep
  };

  enum CATCVG_FeatureType
  {
    CATCVG_FEAT_BTD_Hole            = 1, // BTD = BRepToDRep
    CATCVG_FEAT_BTD_Slot,
    CATCVG_FEAT_BTD_PPoc,
    CATCVG_FEAT_BTD_Notc,
    CATCVG_FEAT_BTD_TapH,
    CATCVG_FEAT_BTD_TapP,
    CATCVG_FEAT_BTD_LocP,
    CATCVG_FEAT_BTD_CutO,           // Cutouts
    CATCVG_FEAT_BTD_WalB            // Wall & Bend
  };

  enum CATCVG_GSL_PrimitiveType
  {
    CATCVG_FEAT_GSL_Undef           = 0,  // GSL = Capture of GS-SL results
    CATCVG_FEAT_GSL_Wall            = 1, 
    CATCVG_FEAT_GSL_CylBend,
    CATCVG_FEAT_GSL_CneBend,    
    CATCVG_FEAT_GSL_Cutout,
    CATCVG_FEAT_GSL_Stamp,
    CATCVG_FEAT_GSL_Hole,
    CATCVG_FEAT_GSL_RefFace
  };

  enum CATCVG_PrimShapeType
  {
    CATCVG_SHAPE_ExtrOnly           = 1,
    CATCVG_SHAPE_WithDeco,
    CATCVG_SHAPE_WithSupp
  };



#endif
// Ne rien ecrire sous cette ligne
//==============================================================================
