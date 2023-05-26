//=============================================================================
// COPYRIGHT Microsoft 2012/08/28 
//=============================================================================
// CATVidDefaultTransferHandler.cpp
// Header definition of class CATVidDefaultTransferHandler
//=============================================================================
//  2012/08/28 Creation: LD5
//=============================================================================

#ifndef CATVidDefaultDataSupport_H
#define CATVidDefaultDataSupport_H

#include "CATVidDnDDataSupport.h"
class CATVidCtl;

/**
 * Helper class associated with each @ref CATVidDefaultTransferHandler.
 *
 * @ref CATVidDnDDataSupport
 */
class ExportedByVisuDialog CATVidDefaultDataSupport : public CATVidDnDDataSupport
{
  CATDeclareClass;
public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the control whose data needs to be transfered. Cannot be
   * @c NULL. A weak reference is kept on the input pointer.
   */
  CATVidDefaultDataSupport(CATVidCtl * i_pOwner);
  /** Destructor. */
  virtual ~CATVidDefaultDataSupport();
  /** @copydoc CATVidDnDDataSupport#IsDataPresent */
  virtual CATBoolean IsDataPresent(CATVidDnDDataSupport::DataType_e i_dataType)const;
  /** @copydoc CATVidDnDDataSupport#GetData */
  virtual CATBoolean GetData(DataType_e i_type, CATBaseUnknown_var& o_output)const;
  /** 
   * @return a not @c NULL pointer on the control whose data needs to be 
   * transfered.
   */
  CATVidCtl * GetOwner() const; 

protected:
  /** @copydoc CATVidDnDDataSupport#PopulateDataInOleDataObject */
  virtual void PopulateDataInOleDataObject();

private:
  /** Weak reference on the control whose data needs to be transfered. */
  CATBaseUnknown_WR _wrOwner;
};
//-----------------------------------------------------------------------------

#endif
