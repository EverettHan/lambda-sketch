#ifndef __omb_cst_H
#define __omb_cst_H

#include "AC0XXLNK.h"
#include "CATUnicodeString.h"
#include "CATOmxKeyString.h"

/**
* Ad hoc Collection of strings frequently used in Omb
* All data members hold a CATUnicodeString which value is EXACTLY the data member name.
*/
struct CATOmbConstants
{
  CATOmbConstants();
  ~CATOmbConstants();

  //Loading modes
  const CATUnicodeString Index_Mode;
  const CATUnicodeString PLM_Mode;
  const CATUnicodeString AuthoringVisu_Mode;
  const CATUnicodeString AuthoringVisu2_Mode;
  const CATUnicodeString VisuRep_Mode;
  const CATUnicodeString Authoring_Mode;
  const CATUnicodeString PartBRep_Mode;
  const CATUnicodeString PartEdit_Mode;
  const CATUnicodeString AuthoringFullEdit_Mode;
  const CATUnicodeString FullLoadingOfAll_Mode;
  const CATUnicodeString AuthoringVisuExtended_Mode;
  const CATUnicodeString AuthoringVisuAlternative_Mode;
  const CATUnicodeString AuthoringFullExtended_Mode;
  const CATUnicodeString Migration_Mode;
  const CATUnicodeString V5INV6_Mode;
  const CATUnicodeString V5Visu_Mode;
  const CATUnicodeString Thumbnail_Mode;
  const CATUnicodeString Archive_Mode;
  const CATUnicodeString CollaborativeEdit_Mode;
  const CATUnicodeString AuthoringXCAD_Mode;

  //Loading order
  const CATUnicodeString Sequential_LoadingOrder;
  const CATUnicodeString Parallel_LoadingOrder;
private:
  const void* LoadingModesPadding[4];
public:

  //Document late types
  const CATUnicodeString cgr;
  const CATUnicodeString CGM;
  const CATUnicodeString uvr;
  const CATUnicodeString fea;
  const CATUnicodeString CATPart;
  const CATUnicodeString CATDrawing;
  const CATUnicodeString CATSimulation;
  const CATUnicodeString CATProcess;
  const CATUnicodeString CATMaterial;
  const CATUnicodeString CATSwl;
  const CATUnicodeString CATAnalysis;
  const CATUnicodeString CATKnowledge;
  const CATUnicodeString CATProduct;
  const CATUnicodeString catalog;
  const CATUnicodeString xmlgeom;
  const CATUnicodeString jpeg;
  const CATUnicodeString model;
  const CATUnicodeString CATData;
  const CATUnicodeString CATNature;
  const CATUnicodeString CATShape;
  const CATUnicodeString SWXDwDocument;
  const CATUnicodeString drwLight;
  const CATUnicodeString dwg;
  const CATUnicodeString CATDocumentImage;
  const CATUnicodeString CATDMURepSpec;
  const CATUnicodeString CATNonCATIADocument;
  const CATUnicodeString CATXCADDocument;
  const CATUnicodeString CATXCAD2DDocument;
  const CATUnicodeString CATXCAD3DDocument;
  const CATUnicodeString CATV5ArchiveDocument;
  const CATUnicodeString SMASim;
  const CATUnicodeString LargeFileDoc;
  const CATUnicodeString ArchiveDocument;
  const CATUnicodeString CATFeatureDocument;
  const CATUnicodeString feat;
  const CATUnicodeString CATfct;
  const CATUnicodeString CATSpecClip;
  const CATUnicodeString SVG;
  const CATUnicodeString UDL;
  const CATUnicodeString sldprt;
  const CATUnicodeString slddrw;
  const CATUnicodeString OmbTxtCAT;
  const CATUnicodeString OmbTxtCAT1;
  const CATUnicodeString OmbTxtCATVisu1;
  const CATUnicodeString OmbTxtCATVisu2;
  const CATUnicodeString OmbTxtCATVisu3;
  const CATUnicodeString OmbTSTDoc;
  const CATUnicodeString json;

private:
  const void* DocumentLateTypesPadding[4];
public:

  //Stream descriptors roles
  const CATUnicodeString EXTENDED;
  const CATUnicodeString ALTERNATIVE;
  const CATUnicodeString CATIAV5;
  const CATUnicodeString CATIAV5INV6;
  const CATUnicodeString DefaultVisuRep;
  const CATUnicodeString DefaultNavRep;
  const CATUnicodeString Jpeg_64x48;
  const CATUnicodeString Archive;
  const CATUnicodeString WebFormat;
  const CATUnicodeString Collaborative;
  const CATUnicodeString InvalidCollaborative;
  const CATUnicodeString DerivedFromCollaborative;
  const CATUnicodeString Distilled;
private:
  const void* RolesPadding[4];
public:

  //Stream descriptors formats
  const CATUnicodeString UNKNOWN;
  const CATUnicodeString Authoring;
  const CATUnicodeString AuthoringVisu;
  const CATUnicodeString VisuRep;
  const CATUnicodeString NavRep;
  const CATUnicodeString IndexRep;
  const CATUnicodeString Jpeg_thumbnail;
  const CATUnicodeString RCA;
  const CATUnicodeString AuthoringVisu2;
  const CATUnicodeString Similar;

  //miscellaneous
  const CATUnicodeString CATSummaryInformation;
  const CATUnicodeString File;
  const CATUnicodeString TeamPDM;
  const CATUnicodeString IterationChecker;
  const CATUnicodeString CreationChecker;
  const CATUnicodeString LRMark;
  const CATUnicodeString DownwardOriginLevel;
  const void* MiscellaneousPadding[4];

  //Export context parameters
  const CATUnicodeString EXPORT_STATUS;
  const CATUnicodeString SYNCHRO_DEF_CTX_COMP;
  const CATUnicodeString SynchronizeExtendedVisu;
  const CATUnicodeString SynchronizeAlternativeVisu;
  const CATUnicodeString DeclareExtendedVisu;
  const CATUnicodeString DeclareAlternativeVisu;
  const CATUnicodeString CATOmbRole;
  const CATUnicodeString CATOmbUsage;
  const CATUnicodeString CATOmbExtension;
  const CATUnicodeString OMB_ForceCollaborativeUpdate;

  // OMB Session Capabilities keywords
  const CATOmxKeyString OMB_Outliner;
  const CATOmxKeyString OMB_AccessMode;

  //containers late types
  const CATUnicodeString CATFeatCont;
  const CATUnicodeString CATCGRCont;

private:
  const void* ContainerLateTypesPadding[4];
};

ExportedByAC0XXLNK const CATOmbConstants& omb_cst();

enum RepRefDataAccess { UnknownAccess = 0, NativeAccess = 1, CollaborativeAccess = 2, CollaborativeAccessWrite = 3 };

/**CATDevelopmentStage() && !CATGetEnv("TEST_INDUS_PERFO")*/
int CATOmbHeavyDebugChecks();

class CATMetaClass* CATNonCATIADocumentMetaObject();

#endif
