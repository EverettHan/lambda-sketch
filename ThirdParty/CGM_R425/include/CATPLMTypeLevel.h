#ifndef CATPLMTypeLevel_H
#define CATPLMTypeLevel_H

//-----------------------------------------------------
//  Check that only authorized modules can link on the exported symbols
//----------------------------------------------------

// ----------------------------------------------------------------------
// List  of  forbidden  re-define  
// ----------------------------------------------------------------------
#if  defined  (private)  ||  defined(friend)  ||  defined  (protected)  
        #error  Forbidden  re-define  of  'private',  'friend'  or  'protected'  
        //  Fatal  error  on  solaris  
        @error    
#endif  

#define  AuthorizedModule  999  

// ----------------------------------------------------------------------
// Define  List  of    authorized  modules  using  CATDexInterfaces  private  intefaces  
// ----------------------------------------------------------------------
#define  CATPLMImplAdapterBase           AuthorizedModule// CATPLMImplAdapterQL
#define  CATPLMServicesItf               AuthorizedModule
#define  CATPLMDebugProviderImpl         AuthorizedModule
#define  CATTCLRecordBuilderMainThread   AuthorizedModule
#define  CATPLMxQueryDataSet             AuthorizedModule
#define  TSTCATPLMCATPLMTypeServices     AuthorizedModule
#define  TSTCATPLMMetadataOldNewTyping   AuthorizedModule

//  Check  authorization  
#if  _MK_MODNAME_  ==  AuthorizedModule  
#else  
    #error  Forbidden  Access  To  CATPLMServives  Services  from  a  non-authorized  module    
    //  Fatal  error  on  solaris  
    @error    
#endif  

// ----------------------------------------------------------------------
// Restore context (don t forget to do that!!!!!!):
// delete macros, de-associate module name  from int value above
// ----------------------------------------------------------------------
#undef CATPLMImplAdapterBase
#undef CATPLMServicesItf
#undef CATPLMDebugProviderImpl
#undef CATTCLRecordBuilderMainThread
#undef CATPLMxQueryDataSet
#undef TSTCATPLMCATPLMTypeServices
#undef TSTCATPLMMetadataOldNewTyping

// ----------------------------------------------------------------------
// ExportedBy
// ----------------------------------------------------------------------
#undef  ExportedByCATPLMServicesItf

#if defined __CATPLMServicesItf
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"

#include "PLMDictionaryDefinitions.h"

class VPMIDicClass;
class VPMIDicRelationClass;
class VPMIDicGenericClass;
class CATPLMType;

class ExportedByCATPLMServicesItf CATPLMTypeLevel
{
public:

  // types that are appli or spe or extension that are not top
  static HRESULT IsPureV2Type(CATPLMType* ipType);

  // types that are appli or spe or extension that are not top
  // SLOW service, use HRESULT IsV2Type(CATPLMType* ipType); if you can....
  static HRESULT IsPureV2Type(VPMIDicGenericClass* ipGenericClass);

  // Indique le niveau du type (sa couleur au sens nouveau typage)
  // Retourne S_FALSE si le CATPLMType est une extension
  // Retourne S_OK si on est bien sur un type (d'objet ou de relation, peu importe)
  static HRESULT GetTypeLevel(VPMIDicGenericClass* ipGenericClass, PLMDictionaryDefinitions::PLMTypeLevel &oLevel);

  // Indique le niveau de l'extension (sa couleur au sens nouveau typage)
  // Retourne S_FALSE si le CATPLMType est un type ou un relation type et non une extension
  // Retourne S_OK si on est bien sur une extension
  static HRESULT GetExtensionLevel (VPMIDicGenericClass* ipClass,PLMDictionaryDefinitions::PLMExtensionLevel &oLevel);

private:

  static HRESULT _IsExtension(VPMIDicGenericClass* ipGenericClass);

  static HRESULT _IsKindOf(VPMIDicGenericClass* ipGenericClass,const CATUnicodeString& iTypeName,CATBoolean& oIsKindOfTypeName);
};

#endif

