#ifndef CATPLMIGEngineNavigateOptions_H
#define CATPLMIGEngineNavigateOptions_H

/**
* @level Private
* @usage U5       
*/
#if ! defined ( CATPLMIGEngineNavigateOptions_definition )
#define CATPLMIGEngineNavigateOptions_definition
typedef unsigned int CATPLMIGEngineNavigateOptions;
#endif


/** 
* Drives the navigate options.
* @param CATPLMIGEngineNavigateOptions_None
*  No options.
* @param CATPLMIGEngineNavigateOptions_ExcludeNeutrals
*  The navigate query excludes neutrals.
*/
#define CATPLMIGEngineNavigateOptions_Cardinality                1
#define CATPLMIGEngineNavigateOptions_None                       0x00000000
#define CATPLMIGEngineNavigateOptions_ExcludeNeutrals            0x00000001


#endif
