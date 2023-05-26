//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATPLMMLNavInGraphOptions.h.h
//  Define  the  CATPLMMLEngineParameters  object
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Modeler language (ML) describes navigation on Modeler level.
// Using current object, you are able to avoid cyclicity during navigation accross the graph.
//
// difference between CATPLMMLEngineParameters and CATPLMMLParsingOptions:
// CATPLMMLEngineParameters dedicated to manage PLM (custo, plmids, fiter).
// CATPLMMLParsingOptions dedicated to parsing option.
// CATPLMMLNavInGraphOptions dedicated to avoid cyclicity during navigation accross the graph.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATPLMMLNavInGraphOptions_H
#define CATPLMMLNavInGraphOptions_H

enum CATPLMMLNavInGraphOptions{CyclicityDetected,CyclicityNotDetected,CATPLMMLNavInGraphUnset};

#endif 
