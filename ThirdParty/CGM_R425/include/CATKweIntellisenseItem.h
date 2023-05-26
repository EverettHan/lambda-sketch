#ifndef CATKweIntellisenseItem_h
#define CATKweIntellisenseItem_h

// COPYRIGHT Dassault Systemes 2007

// Local framework
#include "CATLifSpecs.h"

// System framework
#include "CATLISTV_Declare.h"
#include "CATUnicodeString.h"

/**
 * Class used to represent the Intellisense items used in Knowledge editors.
 */

class CATListValCATKweIntellisenseItem;
class CATKweIntellisenseItem
{
  public:

	  /**
	   * Possible item types for Intellisense.
	   */
	  enum CatIntellisenseItemType
	  {
		  Type,
		  Method,
		  Attribute,
		  Function,
		  Variable,
		  SearchType,
		  IndexedSearchType,
		  History,
		  More,
		  Resource,
		  UnknownItemType,
		  Library
	  };

	  CATKweIntellisenseItem(
		  const CATUnicodeString& iName, 
		  const CATUnicodeString& iDisplayName, 
		  CatIntellisenseItemType iType) 
		  : _name(iName), _displayName(iDisplayName), _type(iType), _function(NULL)
	  {};
	  ~CATKweIntellisenseItem() {};

	  /**
	   * Returns the item name.
	   */
	  inline CATUnicodeString GetName() {return _name;};

	  inline void (*GetFunction(void))(CATListValCATKweIntellisenseItem& oPossibleItems, CATUnicodeString &oText){return _function;}
	  inline void SetFunction(void (*function)(CATListValCATKweIntellisenseItem& oPossibleItems, CATUnicodeString &oText)){_function=function;};

	  /**
	   * Returns the item display name.
	   */
	  inline CATUnicodeString GetDisplayName() {return _displayName;};

	  /**
	   * Returns the item type.
	   */
	  inline CatIntellisenseItemType GetType() {return _type;};

	  int operator ==(const CATKweIntellisenseItem& iItem) const;

	  int operator !=(const CATKweIntellisenseItem& iItem) const;

  private:

	  CATUnicodeString _name;
	  CATUnicodeString _displayName;
	  CatIntellisenseItemType _type;
	  void (*_function)(CATListValCATKweIntellisenseItem& oPossibleItems, CATUnicodeString &oText);
};

#define CATLISTV_RemoveDuplicatesCount
#define	CATLISTV_QuickSort
#include "CATLISTV_Declare.h"

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif

#define CATCOLLEC_ExportedBy ExportedByCATLifSpecs
CATLISTV_DECLARE(CATKweIntellisenseItem);

#endif // CATKweIntellisenseItem_h

