#ifndef CatKweAppRscItemType_h
#define CatKweAppRscItemType_h

//----------------------------------
//
// Any new value must be added at the end, so as not to chage the position of the previous enums,
// which are streamed !!
//
//----------------------------------

/**
 * Possible types of an Application Resource Item.
 * @see CATIKweAppResourceItem
 * @param CatKweAppRscAnyType
 * The resource item is of any type.
 * @param CatKweAppRscCatalog
 * The resource item is a Catalog.
 * @param CatKweAppRscChapter
 * The resource item is a Chapter.
 * @param CatKweAppRscIcon
 * The resource item is an Icon.
 * @param CatKweAppRscPLMDirectory
 * The resource item is a PLM Directory.
 * @param CatKweAppRscPLMReference
 * The resource item is a PLM Reference.
 * @param CatKweAppRscPLMRepReference
 * The resource item is a PLM RepReference.
 * @param CatKweAppRscPLMRuleSet
 * The resource item is a PLM Rule Set.
 * @param CatKweAppRscPLMTemplate
 * The resource item is a PLM Template.
 * @param CatKweAppRscPowerCopy
 * The resource item is a Power Copy.
 * @param CatKweAppRscUserDefinedFeature
 * The resource item is a User Defined Feature.
 * @param CatKweAppRscSheet
 * The resource item is a Sheet.
 * @param CatKweAppRscVBScriptProgram
 * The resource item is a VBScript Program.
 * @param CatKweAppRscVBAProgram
 * The resource item is a VBA Program.
 * @param CatKweAppRscDocument
 * The resource item is a Non CATIA Document (for example an MS Office document).
 * @param CatKweAppRscTextDocument
 * The resource item is a Text Document.
 * @param CatKweAppRscXMLDocument
 * The resource item is a XML Document.
 * @param CatKweAppRscPLMResourceSet
 * The resource item is a PLM Resource Set.
 * @param CatKweAppRscDesignTable
 * The resource item is a Design Table.
 * @param CatKweAppRscPLMBusinessRule
 * The resource item is a PLM Business Rule.
 * @param CatKweAppRscCustoDialogTopFrame
 * The resource item is a Knowledge-based Dialog frame for a Customized PLM Type.
 * @param CatKweAppRscPLMKnowledgeAppliComponent
 * The resource item is a PLM Knowledge-based Applicative Component.
 * @param CATKweAppRscMaterial
 * The resource item is a Material.
 * @param CATKweAppRscPLMPosProxyRef
 * The resource item is a PLMPosProxyRef.
 * @param CATKweAppRscRFLVPMLogicalReference
 * The resource item is a RFLVPMLogicalReference.
 * @param CATKweAppRscEnsEndStyleTable
 * The resource item is a Ens_EndStyleTable.
 * @param CATKweAppRscEnsFluidTable
 * The resource item is a Ens_FluidTable.
 * @param CATKweAppRscEnsInsulationSpecification
 * The resource item is a Ens_InsulationSpecification.
 * @param CATKweAppRscEnsInsulationTypeTable
 * The resource item is a Ens_InsulationTypeTable.
 * @param CATKweAppRscEnsLogicalPartSubTypeTable
 * The resource item is a Ens_LogicalPartSubTypeTable.
 * @param CATKweAppRscEnsMappingPartSubTypeTable
 * The resource item is a Ens_MappingPartSubTypeTable.
 * @param CATKweAppRscEnsMaterialTable
 * The resource item is a Ens_MaterialTable.
 * @param CATKweAppRscEnsPartSubTypeTable
 * The resource item is a Ens_PartSubTypeTable.
 * @param CATKweAppRscEnsStandardTable
 * The resource item is a Ens_StandardTable.
 * @param CATKweAppRscPipInsulationDimensionTable
 * The resource item is a PipInsulationDimensionTable.
 * @param CATKweAppRscPipNominalSizeTable
 * The resource item is a PipNominalSizeTable.
 * @param CATKweAppRscPipRatingTable
 * The resource item is a PipRatingTable.
 * @param CATKweAppRscPipReferenceDimensionTable
 * The resource item is a PipReferenceDimensionTable.
 * @param CATKweAppRscPipSpecification
 * The resource item is a PipSpecification.
 * @param CATKweAppRscSPPSpaceFolder
 * The resource item is a SPP_SpaceFolder.
 * @param CATKweAppRscSRSReferencePlanes
 * The resource item is a SRS_Reference_Planes.
 * @param CATKweAppRscPLMKHLibrary
 * The resource item is a PLM Know How Library
 * @param CATKweAppRscGeolocationCoordinateReferenceSystem
 * The resource item is a GeolocationCoordinateReferenceSystem.
 * @param CatKweAppRscPLMProfile
 * The resource item is a PLM Profile.
 * @param CATKweAppRscMachiningProcess
 * The resource item is a Machining process.
 * @param CATKweAppRscRcwNominalSizeTable
 * The resource item is a Raceway nominal size table.
 * @param CATKweAppRscRcwRealisationTypeTable
 * The resource item is a Raceway realization type table.
 * @param CATKweAppRscRcwSpecification
 * The resource item is a Raceway Specification.
 * @param CATKweAppRscRcwTrayReferenceDimensionTable
 * The resource item is a Raceway tray reference dimension table.
 * @param CATKweAppRscGenGraph
 * The resource item is a Generative Graph
 * @param CATKweAppRscAECSketch
 * The resource item is an AEC sketch
 * @param CATKweAppRscKBETLibrary
 * The resource item is a KML Library
 * @param CATKweAppRscNCMachiningTemplate
 * The resource item is an NC machining template
 * @param CatKweAppRscJSONDocument
 * The resource item is a JSON Document.
 * @param CatKweAppRscLastValue
 * For internal use only.
 */
enum CatKweAppRscItemType {
  CatKweAppRscAnyType = 0,
  CatKweAppRscCatalog = 1,
  CatKweAppRscChapter = 2,
  CatKweAppRscIcon = 3,
  CatKweAppRscPLMDirectory = 4,
  CatKweAppRscPLMReference = 5,
  CatKweAppRscPLMRepReference = 6,
  CatKweAppRscPLMRuleSet = 7,
  CatKweAppRscPLMTemplate = 8,
  CatKweAppRscPowerCopy = 9,
  CatKweAppRscUserDefinedFeature = 10,
  CatKweAppRscSheet = 11,
  CatKweAppRscVBScriptProgram = 12,
  CatKweAppRscVBAProgram = 13,
  CatKweAppRscDocument = 14,
  CatKweAppRscTextDocument = 15,
  CatKweAppRscXMLDocument = 16,
  CatKweAppRscPLMResourceSet = 17,
  CatKweAppRscDesignTable = 18,
  CatKweAppRscPLMBusinessRule = 19,
  CatKweAppRscCustoDialogTopFrame = 20,
  CatKweAppRscPLMKnowledgeAppliComponent = 21,
  CATKweAppRscKBEConcept = 22,
  CATKweAppRscKBETemplate = 23,
  CATKweAppRscMaterial = 24,
  CATKweAppRscPLMPosProxyRef = 25,
  CATKweAppRscRFLVPMLogicalReference = 26,

  CATKweAppRscEnsEndStyleTable = 27,
  CATKweAppRscEnsFluidTable = 28,
  CATKweAppRscEnsInsulationSpecification = 29,
  CATKweAppRscEnsInsulationTypeTable = 30,
  CATKweAppRscEnsLogicalPartSubTypeTable = 31,
  CATKweAppRscEnsMappingPartSubTypeTable = 32,
  CATKweAppRscEnsMaterialTable = 33,
  CATKweAppRscEnsPartSubTypeTable = 34,
  CATKweAppRscEnsStandardTable = 35,
  CATKweAppRscPipInsulationDimensionTable = 36,
  CATKweAppRscPipNominalSizeTable = 37,
  CATKweAppRscPipRatingTable = 38,
  CATKweAppRscPipReferenceDimensionTable = 39,
  CATKweAppRscPipSpecification = 40,
  CATKweAppRscSPPSpaceFolder = 41,

  CATKweAppRscHvaSpecification = 42,
  CATKweAppRscHvaEquivalentDiameterTable = 43,
  CATKweAppRscHvaDuctReferenceDimensionTable = 44,
  CATKweAppRscHvaInsulationDimensionTable = 45,

  CATKweAppRscSRSReferencePlanes = 46,
  CATKweAppRscPLMKHLibrary = 47,
  CATKweAppRscGeolocationCoordinateReferenceSystem = 48,

  CatKweAppRscPLMProfile = 49,

  CATKweAppRscMachiningProcess = 50,

  CATKweAppRscRcwNominalSizeTable = 51,
  CATKweAppRscRcwRealisationTypeTable = 52,
  CATKweAppRscRcwSpecification = 53,
  CATKweAppRscRcwTrayReferenceDimensionTable = 54,

  CATKweAppRscKweAction = 55,
  CATKweAppRscKweLaw = 56,

  CATKweAppRscGeneralLibrary = 57,
  CATKweAppRscGeneralClass = 58,

  CATKweAppRscEns_InsulationCustomerAdditionalSpec = 59,
  CATKweAppRscHvaCustomerAdditionalSpec = 60,
  CATKweAppRscPipCustomerAdditionalSpec = 61,
  CATKweAppRscRcwCustomerAdditionalSpec = 62,
  CATKweAppRscGenGraph = 63,

  CATKweAppRscAECSketch = 64,
  CATKweAppRscNCMachiningTemplate = 65,
  CATKweAppRscKBELibrary = 66,

  CatKweAppRscJSONDocument = 67,
  CATKweSys3D_Specification = 68,
  CATKweSys3D_ClassificationTable = 69,
  CatKweAppRscCATComponentFamily = 70,

  CATKweAppRscEngSpecBasicTechnologicalTable = 71,
  CATKweAppRscEngSpecBasicSpecification = 72,

  CATKweAppRscEns_ComponentCategoryTable = 73,

  CATKweAppRscMaterialCore = 74,
  CATKweAppRscCegXSectionMainSet = 75,

  CATKweAppRscDocumentCBP = 76,

  CATKweAppRscKwePythonScript = 77,

  CATKweAppRscInsSpecification          = 78,
  CATKweAppRscInsCustomerAdditionalSpec = 79,
  CATKweAppRscSppSpecification          = 80,
  CATKweAppRscSptSpecification          = 81,

  CatKweAppRscLastValue
};

#endif // CatKweAppRscItemType_h

