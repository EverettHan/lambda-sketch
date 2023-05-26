#ifndef CATVidLayIndexedWidget_h
#define CATVidLayIndexedWidget_h

// COPYRIGHT Dassault Systemes 2015

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidWidget.h>
#include <CATVidLayConstraints.h>

// System framework
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_WR.h>

/**
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayIndexedWidget : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATVidLayIndexedWidget(CATVidWidget * i_pWidget, CATVidLayConstraints * i_pConstraints, unsigned int i_index)
  {
    _index = i_index;
    _widgetWR = i_pWidget;
    _constraintsWR = i_pConstraints;
  };
  ~CATVidLayIndexedWidget()
  {
  };

  int GetIndex() const {return _index;};
  CATVidWidget * GetWidget() const;
  CATVidLayConstraints * GetConstraints() const;

private:

  int _index;
  CATBaseUnknown_WR _widgetWR; 
  CATBaseUnknown_WR _constraintsWR; 
};

#endif // CATVidLayIndexedWidget_h
