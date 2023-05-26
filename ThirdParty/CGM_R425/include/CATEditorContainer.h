#ifndef CATEditorContainer_h
#define CATEditorContainer_h

//---------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1996
//---------------------------------------------------------------------------
// CATEditorContainer :
// Abstract: Class to define the TabPage for the properties editors
//                                                                 
//---------------------------------------------------------------------------
// Inheritance:  CATEditorContainer
//                    CATDlgTabPage
//                 
//---------------------------------------------------------------------------

#include"CATDlgTabPage.h"
#include "CATAfrProperties.h"

class CATDlgTabContainer;
class CATEditorPage;
  
class ExportedByCATAfrProperties CATEditorContainer: public CATDlgTabPage
{
public:

  CATEditorContainer(CATDlgTabContainer *, const CATString&);
  ~CATEditorContainer();

  CATEditorPage * GetEditorPage();
  void SetRectDimensions(int nX, int nY, int nHeight, int nWidth);  
  void SetPageSize( int size );
  
//friend class CATPropertyDialog;
//friend class CATSettingsDialog;
  
 private:
  
  CATEditorPage * _container; 
};

#endif
