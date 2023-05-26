#ifndef CATVidTabDnDData_H
#define CATVidTabDnDData_H

#include "VisuDialog.h"
#include "CATVidDnDData.h"
#include "CATBaseUnknown_WR.h"
class CATVidCtlTabButton;

/**
 * Data container for tab reorder.
 */
class ExportedByVisuDialog CATVidTabDnDData: public CATVidDnDData
{
  CATDeclareClass;

public:
  /** 
   * Constructor.
   *
   * @param i_pButton the button of the dragged tab.
   */
  CATVidTabDnDData(CATVidCtlTabButton * i_pButton);
  /** Destructor. */
  virtual ~CATVidTabDnDData();
  /** @return the button of the dragged tab. */
  CATVidCtlTabButton * GetButton() const;

private:
  /** Copy constructor. */
  CATVidTabDnDData (CATVidTabDnDData &);
  /** Assignment operator. */
  CATVidTabDnDData& operator=(CATVidTabDnDData&);

private:
  /** @see ::GetButton */
  CATBaseUnknown_WR _buttonWR;
};

//-----------------------------------------------------------------------------

#endif
