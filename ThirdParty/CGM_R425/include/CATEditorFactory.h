#ifndef CAT_EDITOR_FACTORY_H
#define CAT_EDITOR_FACTORY_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrProperties.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

/**
* Base class to create an editor factory.
* <b>Role</b>: To create a factory class for your editor, 
* use the macro @href CAT_EDITOR_DECLARE_FACTORY for the header file (.h) and 
* for the source file (.cpp)   
* the @href CAT_EDITOR_DEFINE_FACTORY for an Edit Properties Editor, and 
* the @href CAT_EDITOR_DEFINE_FACTORY2 for an Tools Options Editor.
* @see CATIUserSettings, CATIEditProperties
*/
class ExportedByCATAfrProperties CATEditorFactory : public CATBaseUnknown
{
public :
  /**
  * @nodoc
  */
  CATEditorFactory() ;
  ~CATEditorFactory() ;
  /**
  * @nodoc
  */
  int IsAuthorized(const char *) const;
  
  /**
  * @nodoc
  */
  virtual unsigned char       Support( const CATUnicodeString& editName ) const = 0 ;

  /**
  * @nodoc
  */
  virtual CATBaseUnknown* Create ( const CATUnicodeString& intfName ) const = 0 ;
  
protected :
  
  CATEditorFactory( const CATEditorFactory& base ) ;
  CATEditorFactory& operator=( const CATEditorFactory& base ) ;
}; 


#undef CAT_PX_DECLARE_FACTORY
/**
 * Declares an editor.
 * <b>Role</b>:macro used to implement an editor factory interface.
 * @param MODULE
 *      module defining editor. 
 * <br><b>Legal values:</b> NOTHING
 * @param EDITOR
 *		This object, which derives from @href CATEditor, is created by the factory.
 * @param TYPE
 *      not used, has to be the same as editor.
 * @see CATIUserSettings,CATIEditProperties
 */
#define CAT_EDITOR_DECLARE_FACTORY(MODULE, EDITOR, TYPE)		 \
  									 \
class ExportedBy##MODULE EDITOR##Factory : public CATEditorFactory	 \
{									 \
  CATDeclareClass;							 \
  									 \
public:									 \
  EDITOR##Factory();							 \
  ~EDITOR##Factory();							 \
  									 \
  unsigned char        Support(const CATUnicodeString & editName) const; \
  CATBaseUnknown * Create (const CATUnicodeString & intfName) const; \
  									 \
protected :								 \
  EDITOR##Factory(const EDITOR##Factory & base);			 \
  EDITOR##Factory & operator=(const EDITOR##Factory & base);		 \
};

#ifndef CATFrmMkStringFromDefine
/** @nodoc */
#define CATFrmMkStringFromDefine1(x) #x
/** @nodoc */
#define CATFrmMkStringFromDefine(x) CATFrmMkStringFromDefine1(x)
#endif

#undef CAT_PX_DEFINE_FACTORY
/**
 * Defines an editor.
 * <b>Role</b>:macro used to implement an editor factory interface.
 * This implementation is done for an Edit properties Editor 
 * @param EDITOR
 *		This object, which derives from @href CATEditor, is created by the factory.
 * @param TYPE
 *      not used, has to be the same as editor.
 * @see CATIEditProperties
 */
#define CAT_EDITOR_DEFINE_FACTORY(EDITOR, TYPE)					      \
CATImplementClass(EDITOR##Factory, CodeExtension, CATEditorFactory,		      \
		  CATEditorManager);						      \
										      \
EDITOR##Factory::EDITOR##Factory(): CATEditorFactory() {}			      \
										      \
EDITOR##Factory::~EDITOR##Factory() {}						      \
										      \
unsigned char EDITOR##Factory::Support(const CATUnicodeString & editName) const	      \
{										      \
  const CATUnicodeString editType = #TYPE;					      \
  return (editType == editName);						      \
}										      \
										      \
CATBaseUnknown * EDITOR##Factory::Create(const CATUnicodeString & intfName) const \
{										      \
  if (!IsAuthorized(CATFrmMkStringFromDefine(_MK_FWNAME_)))			      \
    return NULL;								      \
  CATEditor * edit = new EDITOR;						      \
  CATBaseUnknown * itf = edit->QueryInterface((const char *)intfName);	              \
  edit->Release();                                                                    \
  return itf;	                                                                      \
}										      \
										      \
EDITOR##Factory::EDITOR##Factory(const EDITOR##Factory & base):			      \
  CATEditorFactory(base) {}							      \
										      \
EDITOR##Factory & EDITOR##Factory::operator=(const EDITOR##Factory & base)	      \
{										      \
  CATEditorFactory::operator=(base);						      \
  return (*this);								      \
}

#undef CAT_PX_DEFINE_FACTORY2
/**
 * Defines an editor.
 * <b>Role</b>:macro used to implement an editor factory interface. 
 * This implementation is done for an  Tools Options Editor.
 * @param EDITOR
 *		This object, which derives from @href CATEditor, is created by the factory.
 * @param TYPE
 *      not used, has to be the same as editor.
 * @see CATIUserSettings
 */
#define CAT_EDITOR_DEFINE_FACTORY2(EDITOR, TYPE)				      \
CATBeginImplementClass(EDITOR##Factory,  CodeExtension,            \
                  CATEditorFactory,	CATEditorManager2);     \
CATAddClassExtension(CATUserSettingsManager);					      \
CATEndImplementClass(EDITOR##Factory);						      \
								      \
EDITOR##Factory::EDITOR##Factory(): CATEditorFactory() {}			      \
										      \
EDITOR##Factory::~EDITOR##Factory() {}						      \
										      \
unsigned char EDITOR##Factory::Support(const CATUnicodeString & editName) const	      \
{										      \
  const CATUnicodeString editType = #TYPE;					      \
  return (editType == editName);						      \
}										      \
										      \
CATBaseUnknown * EDITOR##Factory::Create(const CATUnicodeString & intfName) const \
{										      \
  if (!IsAuthorized(CATFrmMkStringFromDefine(_MK_FWNAME_)))			      \
    return NULL;								      \
  CATEditor * edit = new EDITOR;						      \
  CATBaseUnknown * itf = edit->QueryInterface((const char *)intfName);	              \
  edit->Release();                                                                    \
  return itf;	                                                                      \
}										      \
										      \
EDITOR##Factory::EDITOR##Factory(const EDITOR##Factory & base):			      \
  CATEditorFactory (base) {}							      \
										      \
EDITOR##Factory & EDITOR##Factory::operator=(const EDITOR##Factory & base)	      \
{										      \
  CATEditorFactory::operator=(base);						      \
  return (*this);								      \
}


#undef CAT_PX_DEFINE_FACTORY12
/** @nodoc */
#define CAT_EDITOR_DEFINE_FACTORY12( EDITOR, TYPE )				      \
CATBeginImplementClass(EDITOR##Factory,  CodeExtension,          \
                       CATEditorFactory, CATEditorManager);					      \
CATAddClassExtension(CATEditorManager2);					      \
CATAddClassExtension(CATUserSettingsManager);					      \
CATEndImplementClass(EDITOR##Factory);						      \
										      \
EDITOR##Factory::EDITOR##Factory(): CATEditorFactory() {}			      \
										      \
EDITOR##Factory::~EDITOR##Factory() {}						      \
										      \
unsigned char EDITOR##Factory::Support(const CATUnicodeString & editName) const	      \
{										      \
  const CATUnicodeString editType = #TYPE;					      \
  return (editType == editName);						      \
}										      \
										      \
CATBaseUnknown * EDITOR##Factory::Create(const CATUnicodeString & intfName) const \
{										      \
  if (!IsAuthorized(CATFrmMkStringFromDefine(_MK_FWNAME_)))			      \
    return NULL;								      \
  CATEditor * edit = new EDITOR;						      \
  CATBaseUnknown * itf = edit->QueryInterface((const char *)intfName);	              \
  edit->Release();                                                                    \
  return itf;	                                                                      \
}										      \
										      \
EDITOR##Factory::EDITOR##Factory(const EDITOR##Factory & base):			      \
  CATEditorFactory(base) {}							      \
										      \
EDITOR##Factory& EDITOR##Factory::operator=(const EDITOR##Factory & base)	      \
{										      \
  CATEditorFactory::operator=(base);						      \
  return (*this);								      \
}

#endif 










