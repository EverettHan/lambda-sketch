//#ifndef CATUFOServiceOutputImpl_H
//#define CATUFOServiceOutputImpl_H
///**
// * @level Protected
// * @usage U1       
// */
//
//#define AuthorizedModule 999
//#define CATUFO  AuthorizedModule
//#define CATOmbUFO AuthorizedModule
//#define CATPLMLinksImpacts AuthorizedModule
//#define OmbTST_RerouteUseCasesFactory AuthorizedModule
//
//#if _MK_MODNAME_ == AuthorizedModule
//#else
//  #error Forbidden access to UFO internals from a non-infrastructure module
//    @error
//#endif
//#undef CATUFO
//#undef CATOmbUFO
//#undef CATPLMLinksImpacts
//#undef OmbTST_RerouteUseCasesFactory
//#undef AuthorizedModule
//
//
//#include "ExportedByCATPLMIdentification.h"
//#include "CATUFOServiceOutput.h"
//#include "CATError.h"
//
//class CATUFOServiceOutputForEditLinks;
//
//class ExportedByCATPLMIdentification CATUFOServiceOutputImpl: public CATUFOServiceOutput
//{
//public:
//  CATUFOServiceOutputImpl(const CATUnicodeString& iErrorMessage);
//  virtual ~CATUFOServiceOutputImpl();
//
//  virtual CATUnicodeString GetNLSMessage() = 0;
//
//  virtual CATUFOServiceOutputForEditLinks* GetOutputForEditLinks() {return NULL;};
//
//private:
//  CATError *_Error;
//};
//
//class CATUFOServiceOutputError: public CATError
//{
//protected:
//  friend class CATUFOServiceOutputImpl;
//  CATDeclareErrorClass(CATUFOServiceOutputError, CATError);
//
//  CATUFOServiceOutputError(const char * msgId);
//
//private:
//  static const CATUnicodeString Catalog;
//  static const CATErrorId ErrorId;
//};
//
//#endif
