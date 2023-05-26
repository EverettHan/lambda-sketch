// COPYRIGHT DASSAULT SYSTEMES 2012
#ifndef KnowledgeItfMonocode_H
#define KnowledgeItfMonocode_H

// Used to monocode tricky modifications, in order to easily come back to initial behavior

// PCS performance when accessing attributes in VPM Nav on BSM object: avoid to access the extension types when listing attributes
// Changes how to retrieve the physical type of an object (based on CATIInstance::Type instead of CATIInstance::ListSupportedTypes
// Associated IR-184436V6R2013x 
#define CATCkeModification_August30_2012

// Avoiding considering that V_discipline attribute is modified when operating PLM New of a secondary type
// In order to avoid having an error when propagating modifications on the proxy to the PLM object
#define CATCkeModification_September4_2012

// When valuating V_Discipline attribute, propagation of the modification to CATKweInstanceAdapter to improve PCS
#define CATCkeModification_March25_2013

// Changing CATCkeMyPLMObjectWrapper algorithm for PCS improvements 
#define CATCkeModification_March25_2013_2

// Changing Icon computation algorithm for PCS improvements
#define CATCkeModification_March25_2013_3

// Only one computation of the discipline type on CATKweInstanceAdapter
#define CATCkeModification_March26_2013

// For services listing attributes on PLM Extension types, removal of attributes that do not belong to the extension
#define CATCkeModification_September6_2013

// Supporting to have several deployment extensions !
#define CATCkeModification_October31_2013

// Keep policy if defined on the proxy
#define CATCkeModification_November08_2013

// Add checks on discipline valuation to be sure that we don't generate bad models
#define CATCkeModification_November15_2013

// Avoid calling computed attributes when building proxies: performances
#define CATCkeModification_November22_2013

// Preventing creation of proxies with a bad discipline
#define CATCkeModification_November29_2013

#endif
