#ifndef CATSYPTranslatorGroup_H
#define CATSYPTranslatorGroup_H

#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>
#include <CATSYPTranslatorElement.h>
#include <CATISYPCollection.h>
#include <CATBaseUnknown.h>
#include <CATSYPHashMap.h>

class CATSYPTranslatorTag;


class ExportedByCATStyleProcessor CATSYPTranslatorGroup : public CATSYPTranslatorElement
{
  CATDeclareClass;

public:
  CATSYPTranslatorGroup();
  virtual ~CATSYPTranslatorGroup();

  const CATUnicodeString& GetClassNameFromInput(const CATUnicodeString& i_input) const;
  const CATUnicodeString& GetAttributeName(const CATUnicodeString& i_localTagName, const CATUnicodeString& i_attributeName) const;

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


protected:
  const CATSYPTranslatorTag* GetTranslatorTagFromName(const CATUnicodeString& i_tagName) const;

private:
  CATSYPHashMap<CATUnicodeString, CATSYPTranslatorTag*> _tagsMap;
};



#endif
