#ifndef CATSYPTranslatorTag_H
#define CATSYPTranslatorTag_H

#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>
#include <CATSYPTranslatorElement.h>
#include <CATISYPCollection.h>
#include <CATSYPHashMap.h>

class CATSYPTranslatorAttribute;

class ExportedByCATStyleProcessor CATSYPTranslatorTag : public CATSYPTranslatorElement
{
  CATDeclareClass;

public:
  CATSYPTranslatorTag();
  virtual ~CATSYPTranslatorTag();

  /**
   * Sets the father of this tag.
   */
  void SetFatherName(const CATUnicodeString& i_fatherName);
  /**
   * @return the father of this tag.
   */
  const CATUnicodeString& GetFatherName() const;
  /**
   * 
   */
  const CATUnicodeString& GetAttributeNameFromInput(const CATUnicodeString& i_input) const;

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

  CATISYPCollection_var GetItems();

private:
  CATSYPHashMap<CATUnicodeString, CATSYPTranslatorAttribute*> _attributesMap;

  CATUnicodeString _fatherName;
};



#endif
