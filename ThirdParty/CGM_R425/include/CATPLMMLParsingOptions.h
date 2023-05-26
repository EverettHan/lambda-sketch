//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATPLMMLParsingOptions.h
//  Define  the  CATPLMMLParsingOptions  object
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language:_Navigation
//===================================================================
//
// Usage  notes:
// Modeler language (ML) describes navigation on Modeler level (To sum up, we
// recall that it exists 3 different levels: Core Level, Modeler Level, Custo Level)
// Using the current object, we are able to specify parsing options:
// -ability to query internal attributes...
//
// difference between CATPLMMLEngineParameters and CATPLMMLParsingOptions:
// CATPLMMLEngineParameters dedicated to manage PLM (custo, plmids, fiter).
// CATPLMMLParsingOptions dedicated to parsing option.
// CATPLMMLNavInGraphOptions dedicated to avoid cyclicity during navigation accross the graph.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATPLMMLParsingOptions_H
#define CATPLMMLParsingOptions_H

enum CATPLMMLParsingOptions{QueryOnInternalAttrAuthorized,QueryOnInternalAttrNotAuthorized};

#endif 
