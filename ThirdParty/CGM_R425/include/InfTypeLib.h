#include "CATIAV5Level.h"

#ifndef INFITF_IDL
#define INFITF_IDL
/*IDLREP*/
// COPYRIGHT DASSAULT SYSTEMES 2002

#pragma REPID INFITF "DCE:14f197b2-0771-11d1-a5b100a0c9575177"
#pragma HELPID INFITF 1000
#pragma REPBEGIN INFITF

// ---
#include "CATBaseUnknown.idl"
#include "CATBaseDispatch.idl"

#include "CATIABase.idl"
#include "CATIACollection.idl"
#include "CATIASystemService.idl"
#include "CATIASystemConfiguration.idl"

#include "CATIALightSource.idl"
#include "CATIALightSources.idl"
#include "CATIAApplication.idl"
#include "_CATIAApplicationEvents.idl"
#include "CATIAVisuServices.idl"
#include "CATIAPlayerServices.idl"
#include "CATIAWindow.idl"
#include "CATIAWindows.idl"
#include "CATIADocument.idl"
#include "CATIADocuments.idl"
#include "CATIAEditor.idl"
#include "CATIAEditors.idl"
#include "CATIAViewer.idl"
#include "CATIAViewer2D.idl"
#include "CATIAViewer3D.idl"
#include "CATIAViewers.idl"
#include "CATIAViewpoint2D.idl"
#include "CATIAViewpoint3D.idl"
#include "CATIASelection.idl"
#include "CATIAVisPropertySet.idl"
#include "CATIACamera.idl"
#include "CATIACamera2D.idl"
#include "CATIACamera3D.idl"
#include "CATIACameras.idl"
#include "CATIAPageSetup.idl"
#include "CATIAPrinter.idl"
#include "CATIAPrinters.idl"
#include "CATIAService.idl"
#include "CATIASpecsViewer.idl"
#include "CATIASpecsAndGeomWindow.idl"
#include "CATIAMove.idl"
#include "CATIAPosition.idl"
#include "CATIAReference.idl"
#include "CATIAReferences.idl"
#include "CATIAWorkbench.idl"

//text files management

#include "CATIAFileComponent.idl"
#include "CATIAFile.idl"
#include "CATIAFiles.idl"
#include "CATIAFolder.idl"
#include "CATIAFolders.idl"
#include "CATIATextStream.idl"
#include "CATIAFileSystem.idl"

//batches 
#include "CATIABatch.idl"
#include "CATIABatchElement.idl"
#include "CATIABatchElements.idl"
#include "CATIABatchLog.idl"
#include "CATIABatchOutput.idl"

// Enums
#include "CatArrangeStyle.idl"
#include "CatBannerPosition.idl"
#include "CatCameraType.idl"
#include "CatCaptureFormat.idl"
#include "CatClippingMode.idl"
#include "CatImageRotation.idl"
#include "CatLightingMode.idl"
#include "CatNavigationStyle.idl"
#include "CatPaperOrientation.idl"
#include "CatPaperSize.idl"
#include "CatPrintQuality.idl"
#include "CatPrintColor.idl"
#include "CatPrintRenderingMode.idl"
#include "CatProjectionMode.idl"
#include "CatRenderingMode.idl"
#include "CatSpecsAndGeomWindowLayout.idl"
#include "CatSpecsLayout.idl"
#include "CatWindowState.idl"
#include "CatVisPropertyStatus.idl"
#include "CatVisPropertyShow.idl"
#include "CatVisPropertyTypes.idl"
#include "CatVisPropertyPick.idl"
#include "CatVisLayerType.idl"
#include "CatFileSelectionMode.idl"
#include "CatScriptLibraryType.idl"
#include "CATScriptLanguage.idl"
#include "CATSelectionFilter.idl"
#include "CATMultiSelectionMode.idl"
#include "CATPPRTreeItemType.idl"
#include "CATInteractionType.idl"
#include "CatPrinterDirState.idl"

//macro selection
#include "CATIASelectedElement.idl"

//Settings
#include "CATIASetting.idl"
#include "CATIASettings.idl"

// Model Element API
#include "CATIAModelElement.idl"


// Settings 
#include "CATIASettingControllers.idl"
#include "CATIASettingController.idl"
#include "CATIASettingRepository.idl"
#include "CATIARootApp.idl"

#include "CATIACacheSettingAtt.idl" 
#include "CATIADLNameSettingAtt.idl"
//#include "CATIAPrintersSettingAtt.idl"

// Macros
#include "CATIAMacrosSettingAtt.idl"




//Licensing
#include "CATIALicenseSettingAtt.idl"
#include "CATIADynLicenseSettingAtt.idl"
// coclass enabling the Application object to have the _CATIAApplicationEvents outgoing interface
#pragma ID CATIAApplicationCoClass "DCE:87fd6f40-e252-11d5-80400010b5fa1031"
component /*IDLAPPOBJECT*/ CATIAApplicationCoClass {
	incoming CATIAApplication;
	outgoing _CATIAApplicationEvents;
};
#pragma REPEND INFITF


#endif
