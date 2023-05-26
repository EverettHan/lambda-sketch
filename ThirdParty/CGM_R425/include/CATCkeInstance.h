// Copyright Dassault Systemes 2006
#ifndef CATCkeInstance_h
#define CATCkeInstance_h

//----------------------------------------------------------------------------------------------------------------
// The CATCkeInstance is a generic volatile object that implements CATIInstance
// DO NOT USE THIS CLASS IF YOU'VE NOT DISCUSSED WITH US BEFORE!!!
//----------------------------------------------------------------------------------------------------------------

#include "CATLifInstance.h" // Module definition (exported by)

#include "CATKweInstanceAdapter.h" // Inherited class

#include "CATICkeForwards.h"
#include "CATUnicodeString.h"
#include "CATIType.h"
#include "CATListValCATIType.h" 

#include "CATBoolean.h"
class CATICkeObject_var;
class CATIInstance_var;

class CATCkeInstanceModifications;

//----------------------------------------------------------------------------------------------------------------------------------------------------------
// A CATCkeInstance is a volatile object that contains a list of CATICkeParm for parameters and a list of CATIInstance as children
// It implements CATIInstance / CATIAttributesDescription / CATIDynamicAttributes
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class ExportedByCATLifInstance CATCkeInstance : public CATKweInstanceAdapter
{


public:

  // if iType is NULL, it will be replaced by feature type
  // The 2 lists in input are used as is and deallocated by this object. As a consequence they must be allocated by the caller and not deleted by it
  CATCkeInstance(const CATUnicodeString &iName,
    const CATIType_var &iType,  // ATTENTION CE TYPE EST LE MAINTYPE (celui rendu par CATIInstance::Type)
    CATLISTV(CATBaseUnknown_var) *pListAttributes = NULL,
    CATLISTV(CATBaseUnknown_var) *pListChildren = NULL,
    CATBoolean iManageModifiedAttributes = TRUE// Doit on gerer l'information sur les attributs modifies
  );
  virtual ~CATCkeInstance();

  //===========================================================
  // CATIInstanceModifiedAttributes: returns the list of modified attributes
  //===========================================================
  HRESULT GetModifiedAttributes(CATListOfCATUnicodeString &oList, const CATBoolean iFlush = TRUE);
  HRESULT RemoveModifiedTagOnAttribute(const CATUnicodeString &iAttributeName);
  virtual HRESULT GetAddedExtensionTypes(CATLISTV(CATIType_var) &oList, const CATBoolean iFlush = TRUE);
  HRESULT GetAddedAttributes(CATListOfCATUnicodeString &oList, const CATBoolean iFlush = TRUE);
  HRESULT GetSuppressedAttributes(CATListOfCATUnicodeString &oList, const CATBoolean iFlush = TRUE);
  HRESULT GetSuppressedExtensionTypes(CATLISTV(CATIType_var) &oList, const CATBoolean iFlush = TRUE);
  void Flush();


  //===========================================================
  // CATIAlias
  //===========================================================
  virtual CATUnicodeString GetAlias() const { return _name; };
  virtual void SetAlias(const CATUnicodeString &name) { _name = name; };

  //=========================================================================
  // DUMP
  //=========================================================================
  //void Dump (CATUnicodeString &iMessage,int indentation = 0) const;

  //===========================================================
  // CATIInstance gets the owner
  //===========================================================
  virtual CATIInstance* GetOwner() const;

  //===========================================================
  // CATIDynamicAttributes working on the list of attributes
  //===========================================================

  // Add a CATIDynamicAttributes if it does not exist already. Mark it with a UserAccess User
  virtual HRESULT Add(const CATUnicodeString& iKey, const CATIType_var& iType, const CATIValue_var& iValue, boolean iIsComponent);

  // Not implemented yet
  virtual HRESULT Remove(const CATUnicodeString& iKey);

  // Not implemented yet
  virtual HRESULT Rename(const CATUnicodeString& iOldKey, const CATUnicodeString& iNewKey) { return E_FAIL; };

  // CATIDynamicAttributes
  virtual HRESULT AddTypeSupport(const CATIType_var &iTypeAdded);

  virtual HRESULT RemoveTypeSupport(const CATIType_var &iTypeAdded);

  //===========================================================
  // CATIAttributesDescription (not implemented): should list the attributes on the object
  //===========================================================
  virtual HRESULT List(CATListValCATAttributeInfos* oListOfAttributeInfos, boolean recursively) const;

  //===========================================================
  // CATIChildrenAccess working on list of children
  //===========================================================
  virtual boolean AllowAppend() const { return TRUE; }

  // navigate recursively in childrens
  virtual HRESULT VisitComponents(CATIVisitor* iVisitor, const int recur = 0);

  // Adding a children (if not yet aggregated)
  virtual HRESULT AddComponent(const CATICkeObject_var & iKBwareObject);

  // Removing a children
  virtual HRESULT RemoveComponent(const CATICkeObject_var & iKBwareObject);


  // Static function to instanciate a volatile instance identified as such 
  static HRESULT InstanciateVolatileInstance(const CATICkeObject_var & iOwner,
    const CATUnicodeString& iKey,
    CATICkeObject_var& oInstanciated);

  // Static function to instanciate a volatile instance identified as such 
  static HRESULT InstanciateVolatileInstance2(const CATICkeObject_var & iOwner,
    const CATUnicodeString& iKey,
    CATICkeObject_var& oInstanciated,
    CATBoolean iComputeModifiedAttributes = FALSE);

  // Static function to instanciate a Rule Context identified as such 
  static HRESULT InstanciateRuleContext(const CATICkeObject_var & iOwner,
    const CATUnicodeString& iKey,
    CATICkeObject_var& oInstanciated);
  // Returns the type volatile instance
  static CATIType_var GetVolatileInstanceType();

  //===========================================================
  // CATIVolatileInstance to indicate that this object is not protected in case of business rules
  // By default it is protected. Only BRContext are not protected
  //===========================================================
  virtual int ShouldBeProtected() const { return 1; }
  virtual CATBoolean CanBeExtendedByAnykindOfExtension() const { return FALSE; }
  virtual HRESULT ForceAttributeModification(const CATUnicodeString& iName);

  // Methodes internes de gestion du pere: a pour effet de conserver un pointeur !
  // A appeler a vide pour resetter
  HRESULT SetOwner(const CATIInstance_var &owner);

  HRESULT SetValueOnProtectedAttribute(const CATUnicodeString& iName,
    const CATUnicodeString& iKey,
    const CATIValue_var& iValue);

  //===========================================================
  // CATIKbeObject to provide access to reference of parameters
  //===========================================================
  CATICkeParm_var GetReferenceOnAttribute(const CATUnicodeString& iKey, const boolean Evaluate);


  // Pour eviter de toucher aux attributs modifiés pendant certaines opérations
  void LockModificationsReset(const CATBoolean &iValue);
  virtual int propagateConstOnAdd() { return 1; }

protected:
  //===========================================================
  // CATIInstance working on the list of attributes
  //===========================================================
  // Returns the type of the object. returns the type passed in constructor
  virtual CATIType* TypeInternal() const;

  // Gets a value from the list of attribute (recognized by name)
  virtual CATIValue* GetValueInternal(const CATUnicodeString& iKey);

  // Sets a value from the list of attributes (recognized by name)
  virtual HRESULT SetValueInternal(const CATUnicodeString& iKey, const CATIValue_var& iValue);

  // Do we want to propagate Unset status when valuating an attribute of a volatile instance
  virtual CATCke::Boolean WantPropagateUnset(const CATICkeParm_var &oValue);

  // Adds the extensions if any to the list
  virtual HRESULT ListSupportedTypesInternal(CATListValCATIType_var& oListOfCATIType) const;

protected:

  CATUnicodeString				 _name;					// The name of the object (provided in constructor)
  CATIType_var					 _type;	    			// the type (provided in constructor)
  CATLISTV(CATBaseUnknown_var)	*_plistAttributes;		// list of attributes (simple one: can be boolean, int, string, or a reference to an object)
  CATLISTV(CATBaseUnknown_var)	*_plistChildrens;		// list of childrens (reference to objects but that belong(aggregated) to the object)

  CATCkeInstanceModifications *_pModifications;           // Contains the modifications

  // Find the attribute by its name
  void FindAttributeByName(const CATUnicodeString &iName, CATICkeParm_var &) const;

  CATBoolean _ManageModifiedAttributes; // Do we need to keep track of modified attributes

  CATBoolean _KeepModifiedAttributes; // Do not execute RemoveModifiedTagOnAttribute

  // Find the children by its name, will be usefull in the future
  // CATIInstance_var CATCkeInstance::FindComponentByName (const CATUnicodeString &iName) const;

  CATBaseUnknown *_owner; // father of an object that has been aggregated with SetOwner method

  virtual CATBoolean AuthorizeModicationOfReadOnlyAttributes() const { return  FALSE; }

  // Permet de zapper un certain nombre de tests
  // (préexistance d'un attribut, choses qui sont
  // uniquement pour les proxies...)
  // pour améliorer les perfos dans Knowledge Graph
  virtual CATBoolean IsOptimizedMode() { return FALSE; };

private:
  CATLISTV(CATIType_var) *_pListExtensions;


  // Sets a value from the list of attributes (recognized by name)
  virtual HRESULT _SetValueInternal_Reuse(const CATUnicodeString& iKey, const CATIValue_var& iValue, const CATBoolean iForceOnReadOnly = FALSE);

  CATDeclareClass;

};

#endif

