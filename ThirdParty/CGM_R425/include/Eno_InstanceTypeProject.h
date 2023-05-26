#ifndef __Eno_InstanceTypeProject_h__
#define __Eno_InstanceTypeProject_h__ 

#include "CATBoolean.h"
#include "VPMIDicInterfaces.h"

#define Eno_ActivateInstanceType 
#define Eno_InstanceTypeProject_PathTypeMappingSuppressed_defined
#define Eno_InstanceTypeProject_RoleAndCategoryReplaced_defined

// Modif frh le 13 dec 2013: j'essaie de faire en sorte que le systeme fonctionne meme s'il n'y a pas de target définie 
// En gros pas de relationship 
// Je monocode via la variable Unicorn runtime
// Enleve finalement le test d'integrite des relationships pour qu'elles sachent vivre sans Relation
// Ignore aussi dans le parser l'appel a l'enregistrement du TargetName

//#define _SUPPRESS_SUPERREF_ 

ExportedByVPMIDicInterfaces CATBoolean Eno_InstanceTypeProject_InstanceTypeMappingSuppressed ();
ExportedByVPMIDicInterfaces CATBoolean Eno_InstanceTypeProject_InstanceTypeMappingSuppressed_Traces ();
ExportedByVPMIDicInterfaces CATBoolean Eno_InstanceTypeProject_BasicsMappingSuppressed ();

ExportedByVPMIDicInterfaces CATBoolean Eno_InstanceTypeProject_PathTypeMappingSuppressed ();
ExportedByVPMIDicInterfaces CATBoolean Eno_InstanceTypeProject_RoleAndCategoryReplaced ();

ExportedByVPMIDicInterfaces CATBoolean Eno_IncrementalDictionaryLoading ();



#endif
