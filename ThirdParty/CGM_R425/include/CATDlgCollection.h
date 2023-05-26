#ifndef CATDlgCollection_H
#define CATDlgCollection_H

#include <DialogDeclarativeEngine.h>
#include <CATBaseUnknown.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATSYPArray.h>

class CATDialog;
class CATISYPCollection_var;

/**
 * This is the base class for all objects in Dialog that can layout
 * multiple elements in a declarative file
*/

class ExportedByDialogDeclarativeEngine CATDlgCollection : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /** Destructor */
  virtual ~CATDlgCollection ();

  virtual CATBaseUnknown_var GetAt( int i_index );
  virtual int GetCount();
  virtual void Append( const CATBaseUnknown_var &i_spObject );
  virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  virtual void Remove( const CATBaseUnknown_var &i_spObject );
  virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  virtual void Clear();
  virtual int Contains( const CATBaseUnknown_var &i_spObject );

protected:

  /** Constructor */
  CATDlgCollection ();

  /** 
  * The Dialog elements
  * ripped out from the collection
  * during Append
  **/
  CATSYPDynArray<CATDialog*> _pDlgItems;

  /** 
   * A pointer on the collection widget
   * casted to Dialog
   */
  CATDialog* _pCollection;

private:

  void coverage();
  inline void InitializeCollection();
  
};

#endif
