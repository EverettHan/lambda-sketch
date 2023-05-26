//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidCtlTweakerCATVidPalette_H
#define CATVidCtlTweakerCATVidPalette_H
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>
#include <CATVidPalette.h>
#include <CATVidBoxing.h>
#include <CATVidImageProcessing.h>
class CATVidCtlModelEditor;
class CATVidMdlStandardList;
class CATVidMdlStructureChangedEventArgs;
class CATSYPPropertiesChangedEventArgs;
//-----------------------------------------------------------------------

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidPalette: public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidPalette);
public:
  // Standard constructors and destructors
  // -------------------------------------
   CATVidCtlTweakerCATVidPalette ();
protected:
   virtual ~CATVidCtlTweakerCATVidPalette ();
   void TemplateDataUpdated();
   virtual void OnValueChanged();
private:
  void ListenDataBlock(CATSYPDataBlock* i_pBlock);
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlTweakerCATVidPalette (CATVidCtlTweakerCATVidPalette &);
  CATVidCtlTweakerCATVidPalette& operator=(CATVidCtlTweakerCATVidPalette& original);
  void UpdatePaletteFromModel();
  void OnRowsInserted(CATBaseUnknown * i_pSender, CATVidMdlStructureChangedEventArgs * i_pArgs);
  void OnRowsRemoved(CATBaseUnknown * i_pSender, CATVidMdlStructureChangedEventArgs * i_pArgs);
  void OnDataModified(CATBaseUnknown * i_pSender, CATSYPPropertiesChangedEventArgs * i_pArgs);
private:
  CATVidCtlModelEditor* _pModelEditor;
  CATVidMdlStandardList* _pStandardList;
  int _updatingPaletteFromModel;
  int _updatingModelFromPalette;
};
//-----------------------------------------------------------------------

#endif
