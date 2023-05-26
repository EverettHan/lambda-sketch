#ifndef CATVidDnDBaseFactory_H
#define CATVidDnDBaseFactory_H

#include "VisuDialog.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_WR.h"
class CATVidCtl;

/** @ingroup groupVidDnD
 *
 * Base class for drag-and-drop related factories.
 */
class ExportedByVisuDialog CATVidDnDBaseFactory: public CATBaseUnknown
{
  CATDeclareClass;

protected:
  /** 
   * Constructor.
   *
   * @param i_pOwner the control that this factory is associated to. A weak 
   * reference is kept on the input pointer.
   *
   * @see CATVidCtl#SetDragMode
   * @see CATVidCtl#SetDropMode
   */
  CATVidDnDBaseFactory(CATVidCtl * i_pOwner);
  /** Destructor. */
  virtual ~CATVidDnDBaseFactory();
  /** 
   * @return a not @c NULL pointer on the control which is owns the 
   * drag-and-drop factory.
   */
  CATVidCtl * GetOwner() const;

private:
  /** Copy constructor. */
  CATVidDnDBaseFactory(CATVidDnDBaseFactory &);
  /** Equal operator. */
  CATVidDnDBaseFactory& operator=(CATVidDnDBaseFactory&);

private:
  /** @see #GetOwner */
  CATBaseUnknown_WR _wrOwner;
};

//-----------------------------------------------------------------------------

#endif
