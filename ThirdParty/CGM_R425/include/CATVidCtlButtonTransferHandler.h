#ifndef CATVidCtlButtonTransferHandler_H
#define CATVidCtlButtonTransferHandler_H

#include <CATVidDefaultTransferHandler.h>
#include <CATVidDnDDataSupport.h>
#include <CATVidCtlButtonDataSupport.h>
class CATVidCtlButton;

//-----------------------------------------------------------------------------
/**
 * @deprecated Use @ref CATVidCtl drag-and-drop instead.
 *
 * This class provides support of drag and drop operation of a CATVidCtlButton.
 *
 * @see CATVidDefaultTransferHandler
 */
class ExportedByVisuDialog CATVidCtlButtonTransferHandler: public CATVidDefaultTransferHandler
{
   CATDeclareClass;
public:
  /**
   * Constructor.
   *
   * @param i_pOwner the button whose data needs to be transfered by Drag&Drop
   */
  CATVidCtlButtonTransferHandler(CATVidCtlButton* i_pOwner);
  /** Destructor. */
  virtual ~CATVidCtlButtonTransferHandler();
  /** @copydoc CATVidDefaultTransferHandler#DropDone */
  virtual void DropDone(CATBoolean i_bDropSuccess);
  /** @copydoc CATVidDefaultTransferHandler#CanImport */
  virtual CATBoolean CanImport();
  /** @copydoc CATVidDefaultTransferHandler#ImportData */
  virtual CATBoolean ImportData();

protected:
   /** @copydoc CATVidDefaultTransferHandler#CreateDataSupport */
   virtual CATVidDnDDataSupport* CreateDataSupport();
};
//-----------------------------------------------------------------------------

/**
 * @deprecated. Use @ref CATVidButtonDataSupport instead.
 */
class CATVidCtlButtonDnDDataSupport : public CATVidCtlButtonDataSupport
{
  CATDeclareClass;
public:
  CATVidCtlButtonDnDDataSupport(CATVidCtlButton * i_pOwner);
  virtual ~CATVidCtlButtonDnDDataSupport();
private:
  CATVidCtlButtonDnDDataSupport (CATVidCtlButtonDnDDataSupport &);
  CATVidCtlButtonDnDDataSupport& operator=(CATVidCtlButtonDnDDataSupport&);
};

#endif
