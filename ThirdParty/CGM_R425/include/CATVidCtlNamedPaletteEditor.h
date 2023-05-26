//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidCtlNamedPaletteEditor_H
#define CATVidCtlNamedPaletteEditor_H
#include <VisuDialogEx.h>
#include <CATVidCtl.h>
#include <CATVidPalette.h>
#include <CATVidBoxing.h>
#include <CATVidImageProcessing.h>
class CATVidCtlModelEditor;
class CATVidMdlStandardList;
class CATVidMdlStructureChangedEventArgs;
class CATSYPPropertiesChangedEventArgs;
//-----------------------------------------------------------------------

class ExportedByVisuDialogEx CATVidCtlNamedPaletteEditor: public CATVidCtl
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
   CATVidCtlNamedPaletteEditor (int iInitWithPresetsflag=0);
protected:
   virtual ~CATVidCtlNamedPaletteEditor ();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlNamedPaletteEditor (CATVidCtlNamedPaletteEditor &);
  CATVidCtlNamedPaletteEditor& operator=(CATVidCtlNamedPaletteEditor& original);
   void ListenDataBlock(CATSYPDataBlock* i_pBlock);
  void UpdatePaletteFromModel();
  void OnRowsInserted(CATBaseUnknown * i_pSender, CATVidMdlStructureChangedEventArgs * i_pArgs);
  void OnRowsRemoved(CATBaseUnknown * i_pSender, CATVidMdlStructureChangedEventArgs * i_pArgs);
  void OnDataModified(CATBaseUnknown * i_pSender, CATSYPPropertiesChangedEventArgs * i_pArgs);
private:
  CATVidCtlModelEditor* _pModelEditor;
  CATVidMdlStandardList* _pStandardList;
};
//-----------------------------------------------------------------------

#endif
