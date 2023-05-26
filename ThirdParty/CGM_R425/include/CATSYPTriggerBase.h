#ifndef CATSYPTriggerBase_h
#define CATSYPTriggerBase_h

// COPYRIGHT Dassault Systemes 2007

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATISYPIntrospectable.h>
#include <CATISYPCollection.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <UIVCoreToolsInline.h>

class CATISYPValues_var;

class ExportedByIntroInfra CATSYPTriggerBase: public CATISYPCollection
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPTriggerBase ();

  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
	/** @copydoc CATISYPCollection#GetAt */
	CATBaseUnknown_var GetAt( int i_index );
	/** @copydoc CATISYPCollection#GetCount */
  INLINE int GetCount()
  {
    return _children.Size();
  }
	/** @copydoc CATISYPCollection#Append */
	void Append( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#AppendList */
	void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Remove */
	void Remove( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#RemoveList */
	void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Clear */
	void Clear();
  /** @copydoc CATISYPCollection#Contains */
  int Contains( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#Append */
	void Append( const CATLISTV(CATBaseUnknown_var) &i_list );
  /*@}*/

  INLINE CATISYPCollection_var GetItems() { return this; };

  virtual void ReactOnPropertyChange(const CATISYPValues_var& spValue) {};

protected:

  virtual ~CATSYPTriggerBase();
  CATISYPIntrospectable_var GetIntrospectable();

private:
  // Copy constructor and equal operator
  CATSYPTriggerBase (CATSYPTriggerBase &);
  CATSYPTriggerBase& operator=(CATSYPTriggerBase&);
  CATLISTV(CATBaseUnknown_var) _children;
};

#endif // CATSYPTriggerBase_h
