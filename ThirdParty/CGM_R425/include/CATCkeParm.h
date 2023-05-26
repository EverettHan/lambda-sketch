/**
* @level Protected
* @usage U1
*/

// COPYRIGHT DASSAULT SYSTEMES 1999 2000
#ifndef CATCkeParm_h
#define CATCkeParm_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Engineering Equations
// 	declaration of Parameter
//
//      C++ implementation of the parameters.
//			Impelemenation of the nodes paramters of an expression.
//			Hence they do not implement some characteristics of the feature
//			parameter.				
//          - Events
//          - Units
//
//////////////////////////////////////////////////////////////////////////
//
// Dec 98 Revision  GetFacet, SetFacet for facet management     C.Lenguin
//
//////////////////////////////////////////////////////////////////////////

// BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATCallbackManager.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxAutoPtr.h"
#include "CATOmxPortability.h"
// KnowledgeInterfaces
#include "CATCke.h"
#include "CATICkeInst.h"
#include "CATICkeMKS.h"
#include "CATICkeMKSUnit.h"
#include "CATICkeParm.h"
#include "CATICkeUnit.h"
#include "CATIParmEvents.h"
#include "CATIParmFormat.h"
#include "CATIParmManipulator.h"
#include "CATIParmPublisher.h"
#include "CATIParmValuator.h"
#include "CATIParmVariable.h"
#include "CATIValue.h"
// LiteralFeatures
#include "CATCkeMacros.h"
#include "CATLifDictionary.h"
class CATTime;

struct CATCkeParmData
{
  CATOmxArray<double> _tolerance;
  CATOmxArray<double> _range;
  CATOmxArray<double> _listOfDoubleValues;
  CATOmxArray<CATUnicodeString> _listOfStringValues;
  CATICkeMKSUnit_var _mks;
  CATIParmFormat_var _format;
  CATIParmManipulator_var _mp;
  CATBaseUnknown_var _context;
#if OMX_CODE_PHASE == 2
  CATUnicodeString _displayUnit;
#endif
};

class  ExportedByCATLifDictionary CATCkeParm : public CATCallbackManager
{
  CATDeclareClass;

public:

  CATCkeParm(const CATICkeType_var &, CATUnicodeString = "", const CATCke::Boolean outside = CATCke::True, CATICkeInst * iInitialValue = NULL); // from type. unset/non-const
  CATCkeParm(const CATICkeInst_var &, CATUnicodeString = "", const CATCke::Boolean outside = CATCke::True); // from instance. const

  void * operator new(size_t iSize);
  void operator delete(void * iAddr);

  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  virtual ~CATCkeParm();

  virtual CATUnicodeString   Name() const;

  virtual CATICkeType_var Type() const;
  virtual void     Rename(const CATUnicodeString & s);

  // A parameter can be local to a relation set or shared
  CATCke::Boolean IsLocal() const { return CATCke::True; }
  virtual CATCke::Boolean IsNamed() const;

  // the pathname of a parameter is its location in Feature Tree
  virtual CATUnicodeString  Pathname(const CATIParmPublisher_var & context = NULL_var) const;
  virtual CATUnicodeString  RelativeName(const CATIParmPublisher_var & context = NULL_var) const;


  CATCke::Boolean  IsConst() const { return _const; }
  virtual CATCke::Boolean  IsSet() const;
  virtual CATICkeInst_var Value() const;	// raises UnsetParameter
  virtual CATUnicodeString   Family() const;

  virtual void     Unset();
  virtual void     Valuate(const CATICkeInst_var &);	// raises ConstObject, InvalidType
  virtual void     Valuate(const double v);      // raises InvalidType, ConstObject 
  virtual void     Valuate(const int v);      // raises InvalidType, ConstObject 
  virtual void     Valuate(const CATUnicodeString v);    // raises InvalidType, ConstObject 
  virtual void     Valuate(const CATCke::Boolean v);   // raises InvalidType, ConstObject 
  virtual void     ValuateObject(const CATBaseUnknown_var & v);   // raises InvalidType, ConstObject 
  void     ValuateReal(const CATUnicodeString v);   // raises InvalidType, ConstObject 
  void Valuate(const CATTime & iValue);

  void     SetConst(CATCke::Boolean b);
  void     SetFamily(CATUnicodeString s);
  virtual  CATICkeParm::UserAccessMode UserAccess() const;
  virtual void           SetUserAccess(CATICkeParm::UserAccessMode m);
  CATCke::Boolean IsReadOnly() const;

  // support de CATIValue
  boolean GetReadOnly() const;
  void SetReadOnly(const boolean iReadOnly);

  void	   CheckVal(const CATICkeInst_var &) const; // raises ConstObject, InvalidType

  // inherited services
  virtual CATUnicodeString   Show() const;
  virtual CATUnicodeString   ShowReal(const CATICkeUnit_var &) const;
  virtual CATUnicodeString   Content() const;

  CATIParmValuator_var Relation() const { return NULL_var; }
  void SetRelation(const CATIParmValuator_var & rel, const CATCke::Boolean & b = CATCke::False);


  CATListValCATBaseUnknown_var * ImpactedRelations(const int b) { return NULL; }

  // Le parametre est-il interne a une expression ou externe
  CATCke::Boolean            IsOutside() const;

  // Gets the facet (bounds, tolerance, list of authorized values)
  void GetFacet(CATICkeMKS::FacetType iFacetType, void * oFacet);
  // Sets the facet (bounds, tolerance, list of authorized values)
  void SetFacet(CATICkeMKS::FacetType iFacetType, void * iFacet);

  // Gets the facet (bounds, tolerance, list of authorized values)
  HRESULT GetFacet(CATICkeMKS::FacetType iFacetType, CATListOfDouble & oList) const;
  HRESULT GetFacet(CATICkeMKS::FacetType iFacetType, CATListOfCATUnicodeString & oList) const;

  // Sets the facet (bounds, tolerance, list of authorized values)
  HRESULT SetFacet(CATICkeMKS::FacetType iFacetType, const CATListOfDouble & iList);
  HRESULT SetFacet(CATICkeMKS::FacetType iFacetType, const CATListOfCATUnicodeString & iList);

  CATICkeMKSUnit_var GetMKS() const;
  CATCke::Boolean    SetMKS(CATICkeMKSUnit_var const & iMKSUnit);


  // The visibility is the fact that the literal participate to the 
  // feature definition or not 
  CATCke::Boolean Visibility() const { return _visibility; }
  void    SetVisibility(const CATCke::Boolean b);

  CATCke::Boolean IsHidden() const { return _hidden; }
  void    SetHidden(const CATCke::Boolean b);

  // Manipulator management
  CATIParmManipulator_var Manipulator() const;
  void                    SetManipulator(const CATIParmManipulator_var & m);
  CATIParmManipulator_var CreateManipulator() const;

  // --------------------------
  // implements CATIParmEvents
  // --------------------------
  static CATCallbackEvent GetRenameNotification();
  static CATCallbackEvent GetChangeValueNotification();
  static CATCallbackEvent GetChangeVisuNotification();
  static CATCallbackEvent GetDeleteNotification();
  static CATCallbackEvent GetChangeParmValuatorNotification();

  // Ask the parameter to send the change Visu notification
  void SendChangeVisuNotification();
  void DefineSendBehavior(const CATIParmEvents::SendBehavior sb);
  void SendChangeValueNotification(const CATCke::Boolean & changed);


  // Special access to stored value CATIParmAsStored
  virtual void ValuateStored(const double v);
  double ValueStored() const;

  // defines current format for parameter (used in Show method)
  void                SetFormat(const CATIParmFormat_var & pf);
  CATIParmFormat_var  Format() const { return _data ? _data->_format : CATIParmFormat_var(); }


  virtual CATUnicodeString Role(const CATIParmPublisher_var & des = NULL_var) const;

  // Ask the parameter to send the change Visu notification
  void SendRenameNotification();

  /**
  * Returns the internal role of parameter in its context.
  * It is the name given to the parameter at its creation
  */
  CATUnicodeString InternalRole() const;


  void SetInternalRole(const CATUnicodeString & iRole);

  virtual CATUnicodeString ContentIso() const;
  virtual CATUnicodeString ShowIso() const;
  virtual CATUnicodeString ShowRealIso(const CATICkeUnit_var & u) const;

#if OMX_CODE_PHASE == 2
  // Modif frh 29 sept 2006: implementation of CATIParmVariable
  // This service returns the identification of a parameter 
  virtual HRESULT IdentifyParameter(CATIParmVariable::ParameterIdentification & oIdentification) const;

  // Returns the type of the variable (opposed to the type of the value, which is the same in most cases but not all.
  virtual CATICkeType_var VariableType() const;

  /*
  * A CATICkeParm is a variable in any case (meaning that it can be manipulated as a variable in the Knowledge Language
  * But some are just variables (volatile value, volatile list, volatile pointer, volatile valuePointer) and some are objects
  * that can be referenced by a relation (literal, new literal, list, pointer, value pointer, and object reference)
  * this method indicates that the parameter is a pure volatile variable (watch out, answers false for an object reference)
  */
  virtual CATCke::Boolean IsVolatile() const;

#endif 
  virtual void DoValuate(const CATCke::Boolean & changed, const CATICkeInst_var & i);

  static HRESULT MlkTrackerPrettyPrint(const IUnknown & iObject, class CATOmxMlkTrackerInfoPrinter & ioPrinter);

#if OMX_CODE_PHASE == 2
  inline CATBaseUnknown_var GetScaleContext() const { return _data ? _data->_context : CATBaseUnknown_var(); }
  HRESULT SetScaleContext(CATBaseUnknown * iContext);

  void GetDisplayUnit(CATUnicodeString & oDisplayUnit) const;
  void SetDisplayUnit(CATUnicodeString const & iDisplayUnit);
#endif

  CATCkeParm & operator=(const CATCkeParm &);
protected:

  CATICkeInst_var _value;
  CATCkeParm(const CATCkeParm &);

private:

  CATICkeType_var _type;
  CATUnicodeString   _name;
  CATOmxAutoPtr<CATCkeParmData> _data;
  CATCkeParmData & AllocateData();

#ifdef _WINDOWS_SOURCE
#pragma pack(push,1) // optimize packing
#endif
  CATICkeParm::UserAccessMode _uam : 8;
  CATIParmEvents::SendBehavior sb_ : 8;
  unsigned int _set : 1;
  unsigned int _hidden : 1;
  unsigned int _outside : 1;
  unsigned int _visibility : 1;
protected:
  unsigned int  _const : 1;
#ifdef _WINDOWS_SOURCE
#pragma pack(pop) // optimize packing
#endif
};

#endif


