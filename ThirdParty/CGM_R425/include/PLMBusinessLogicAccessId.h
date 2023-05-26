/* COPYRIGHT DASSAULT SYSTEMES 2007
===================================================================

* @fullreview SKN14 HQQ 21:04:15 TSK6968437 CheckAccessBL

===================================================================*/

#ifndef PLMBusinessLogicAccessId_H
#define PLMBusinessLogicAccessId_H

/**
* @level Protected
* @usage U1
*/

// Export
#include "PLMBusinessLogicInterfaces.h"

/**
* Class that declares the business logic access interfaces identifiers.
*/
class ExportedByPLMBusinessLogicInterfaces PLMBusinessLogicAccessId
{

public:

    /** List of supported business logic access opening.*/
    enum AccessId {
        InstanceAggregation = 0,
        IdentificationInitialization = 1,
        AttributesValuation = 2,
        AttributesPropagation = 3,
        Delete = 4,
        PLMImportExportAttributesValuation = 5,
        AttributesFinalize = 6,
        PortAggregation = 7,
		ValidationForReusable = 8,
		RelationEstablishment = 9,
		CustoTypeMapping = 10,
		AttributesMapping = 11,
		PublicUIDValuation= 12,
		PLMMigrationAttributesValuation = 13,
		RelationSuppression = 14,
		PLMFinalizationForOffline = 15,
		CoexDelete = 16,
		CoexCheckMode = 17,
		PLMUserOperationExecuted = 18,
    DeleteUI = 19,
		PLMBLClientSaveAction=20,
        CommandInputValidation = 21,
		PLMImportExportPnOAndAttributeValuations=22 //SKN14 FUN110016 BL CheckAccess
    };

private:

    PLMBusinessLogicAccessId();
    ~PLMBusinessLogicAccessId();

    PLMBusinessLogicAccessId(PLMBusinessLogicAccessId &);
    PLMBusinessLogicAccessId & operator=(PLMBusinessLogicAccessId &);

};
#endif
