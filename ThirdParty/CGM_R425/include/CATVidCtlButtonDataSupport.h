//=============================================================================
// COPYRIGHT Microsoft 2012/08/31
//=============================================================================
// CATVidCtlButtonDataSupport.cpp
// Header definition of class CATVidCtlButtonDataSupport
//=============================================================================
//  2012/08/31 Creation: LD5
//=============================================================================

#ifndef CATVidCtlButtonDataSupport_H
#define CATVidCtlButtonDataSupport_H

#include "CATVidDefaultDataSupport.h"
class CATVidCtlButton;

/**
 * Helper class associated with each CATVidDnDButtonTransferHandler that
 * manages data operations and interactions.
 */
class ExportedByVisuDialog CATVidCtlButtonDataSupport : public CATVidDefaultDataSupport
{
  CATDeclareClass;
public:
  /**
   * Constructor.
   */
  CATVidCtlButtonDataSupport(CATVidCtlButton * i_pOwner);
  /** Destructor. */
  virtual ~CATVidCtlButtonDataSupport();
  /**  @copydoc CATVidDnDDataSupport#IsDataPresent */
  virtual CATBoolean IsDataPresent(CATVidDnDDataSupport::DataType_e i_dataType) const;
  /** @copydoc CATVidDnDDataSupport#GetPixelImage */
  virtual CATBoolean GetPixelImage(CATPixelImage& o_imgOut) const;
  /** @copydoc CATVidDnDDataSupport#GetText */
  virtual CATBoolean GetText(CATUnicodeString& o_textOut) const;
  /** @copydoc CATVidDnDDataSupport#GetData */
  virtual CATBoolean GetData(DataType_e i_type, CATBaseUnknown_var& o_output) const;
};
//-----------------------------------------------------------------------

#endif
