//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014/04/19
//===================================================================

#ifndef EKBindExperienceKernel_H
#define EKBindExperienceKernel_H

#ifdef __EKESBinding
# define ExportedByBindExperienceKernel DSYExport
#else
# define ExportedByBindExperienceKernel DSYImport
#endif /*__EKESBinding*/
#include "DSYExport.h"

namespace ES
{
class World;
}

namespace EK
{
class Context;

/**
 * This function adds the ExperienceKernel binding to an existing ECMAScript World
 * Once this binding done, you can use EK.Node and/or EK.Store
 */
ExportedByBindExperienceKernel void addExperienceKernel(ES::World& world, const Context& context);

/**
 * This function adds the ExperienceKernel binding to an existing ECMAScript World
 * Only functionalities that does not require an Hypervisor can be used
 */
ExportedByBindExperienceKernel void addExperienceKernel(ES::World& world);

/**
 * Before you delete the associated World, you need to call this function
 * to stop the nodes properly and to avoid any possible deadlocks
 */
ExportedByBindExperienceKernel void removeExperienceKernel(ES::World& world);
}

#endif /*EKBindExperienceKernel_H*/
