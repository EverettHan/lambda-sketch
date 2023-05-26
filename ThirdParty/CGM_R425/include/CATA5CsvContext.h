#ifndef __CATA5Context__
#define __CATA5Context__

#include "CATA5ParserExport.h"

#include "CATOmxVector.h"
#include "CATOmxList.h"
#include "CATOmxOMap.h"
#include "CATOmxKeyString.h"

#include "CATA5CsvRowDefinition.h"

namespace CATA5
{
  /**
  * Interface to provide row definitions
  */
  class ExportedByCATA5Parser DefinitionLoader : public CATOmxSharable
  {
  public:
    /*
    * Returns a dynamic prototype.
    * The code MUST BE THREAD SAFE.
    * @param iPrototypeName the prototypeName
    */
    virtual CATOmxSR<CsvRowDefinition> Load(const CATOmxKeyString &iPrototypeName) = 0;
  };

  /**
   * This class hold the CsvParse context.
   */
  class CsvContext
  {
   public:
    // Constructor / Destructor
    CsvContext() : _size_tagged(false), _size(0) {};

    /*
    * Returns the CsvRowDefinition for the given tag.
    * In the server's answer this is the "label".
    * Example:
    *   ..."body": {"result": [{}, {}, {}, {"label": "expand"...
    *
    * The returned CsvRowDefinition is not addrefed.
    * Returns NULL if there is no definition for the given label.
    */
    CsvRowDefinition* Locate(const CATOmxKeyString& iTag);
    
    /*
    * Adds csv row definitions.
    */
    HRESULT Configure(CATOmxList<CsvRowDefinition>& iDefinitions);
    
    /*
    * Adds a csv row definition.
    */
    HRESULT Add(CsvRowDefinition* ipDefinition);
    
    /*
    * Adds a definition loader to load defered definition.
    */
    void AddDefinitionLoader(DefinitionLoader* ipDefinitionLoader);
    
    /*
    * Dumps loaded definition.
    */
    void TCLDump(CATOmxTextStream& iStream) const;
    
    /*
    * Builds a field according to the definition.
    * Used by TclParser.
    */
    HRESULT BuildField(const FieldDescription &def, TclNode &toMap, CATOmxAny &target);

    /*
    * Builds a field according to the definition.
    * Used by JsonParser.
    */
    HRESULT BuildField(const FieldDescription& iFieldDescription, const CATOmxAny& iValue, CATOmxAny& oTarget);
   
  private:
    // Methods: Tcl related
    HRESULT _BuildAtom(const FieldDescription &def, TclNode &toMap, CATOmxAny &target);
    HRESULT _BuildFieldWithRank(const FieldDescription &def, TclNode *node, CATOmxAny &target);

    // Methods: Json related
    HRESULT _BuildAtom(const FieldDescription& iFieldDescription, const CATOmxAny& iValue, CATOmxAny& oTarget);

    // Methods:Both Tcl and Json related
    bool _IsEmptyValue(const CATOmxAny& iValue);
    void _BuildEmptyTarget(const FieldDescription& iFieldDescription, CATOmxAny& oTarget);

    // Attributes
    CATOmxList<DefinitionLoader> _DefinitionLoaders;
    CATOmxList<CsvRowDefinition> _LoadedDefinitions;
    CATOmxOMap<CATOmxKeyString, CsvRowDefinition*,CATOmxDefaultCollecManager<CATOmxKeyString>::manager,naive_manager> _TagToDefinitions;
    int _size;
    bool _size_tagged;
  };
}
#endif
