// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATSYPTriggerCollection.h
// Header definition of CATSYPTriggerCollection
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2007  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATSYPTriggerCollection_H
#define CATSYPTriggerCollection_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATISYPCollection.h>
#include <CATLISTV_CATBaseUnknown.h>

class CATSYPMappingTablePointerToPointer;
class CATISYPValues_var;

//-----------------------------------------------------------------------

/**
 * A CATSYPTriggerCollection is a collection of CATSYPTrigger and CATSYPEventTrigger.
 */
class ExportedByIntroInfra CATSYPTriggerCollection: public CATBaseUnknown
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATSYPTriggerCollection ();

  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
	/** @copydoc CATISYPCollection#GetAt */
	virtual CATBaseUnknown_var GetAt( int i_index );
	/** @copydoc CATISYPCollection#GetCount */
	virtual int GetCount();
	/** @copydoc CATISYPCollection#Append */
	virtual void Append( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#AppendList */
	virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Remove */
	virtual void Remove( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#RemoveList */
	virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Clear */
	virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#Append */
	virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list );
  /*@}*/

  CATISYPCollection_var GetItems(void) { return this; };

  void ReactOnPropertyChange( const CATUnicodeString &i_propertyName, const CATISYPValues_var& spValue );
  void ReactOnSendEvent( const CATUnicodeString &i_propertyName);

protected:
  virtual ~CATSYPTriggerCollection ();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPTriggerCollection (CATSYPTriggerCollection &);
  CATSYPTriggerCollection& operator=(CATSYPTriggerCollection&);
  CATLISTV(CATBaseUnknown_var) _children;
  friend class CATSYPIntrospectableAdapter;
};
//-----------------------------------------------------------------------

#endif