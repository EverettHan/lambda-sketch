// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlGroupBox.h
// Header definition of CATVidCtlGroupBox
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlGroupBox_H
#define CATVidCtlGroupBox_H

#include <VisuDialog.h>
#include <CATVidCtlHeaderedContent.h>

/**
* Base class for groupBox.
* <b>Role</b>:
* This widget is used to display a component inside a frame. 
* It inherits the generic component CATVidCtlHeaderedContent.
* <br>
* Create this CATVidCtlGroupBox by using factory static method CreateGroupBox.
* @ingroup VIDControls
*/
class ExportedByVisuDialog CATVidCtlGroupBox: public CATVidCtlHeaderedContent
{
  CATDeclareClass;

public:
  /**
  * Constructs a CATVidCtlGroupBox.
  * No associsated style, use static factory CreateGroupBox
  */
  CATVidCtlGroupBox();
  /**
  * Constructs a CATVidCtlGroupBox with standard style.
  * @param i_pParent
  *   The parent of the widget.
  * @param i_pIdentifier
  *   The name of the widget.
  */
  static CATVidCtlGroupBox* CreateGroupBox(CATCommand *i_pParent, const CATString & i_pIdentifier);
protected:
  virtual ~CATVidCtlGroupBox ();
    
  void ComputeDefaultDataTemplateName(CATUnicodeString& o_dataTemplateName, CATUnicodeString& o_styleSheet) const;
  /**copydoc CATVidCtl#TemplateDataUpdated */
  virtual void TemplateDataUpdated();
private:
  CATVidCtlGroupBox(CATCommand *i_pParent, const CATString & i_pIdentifier);
};
//-----------------------------------------------------------------------
#endif
