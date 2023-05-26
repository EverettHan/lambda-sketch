// COPYRIGHT Dassault Systemes 2013
//===================================================================
//  Sept 2013 Defines StreamDescriptor accessing filters
//===================================================================
#ifndef CATOmbStreamDescriptorAccess_H
#define CATOmbStreamDescriptorAccess_H

/**
* @level  Protected
* @usage   U1
*/

namespace CATOmbSD
{
  /**
  * Filters to be applied on StreamDescriptor typing characteristics :
  * FormatAndRole : SDs filtered by their CATOmbStreamDescriptorFormat and Role
  * @param Authoring
  *   All Authoring Stream Descriptors
  * @param AuthoringVisu
  *   All AuthoringVisu Stream Descriptors
  * @param AuthoringVisuExtended
  *   All AuthoringVisu Stream Descriptors with Role Extended
  * @param AuthoringExtended
  *   All Authoring Stream Descriptors with Role Extended
  * @param AuthoringVisuAlternative
  *   All AuthoringVisu Stream Descriptors with Role Alternative 
  * @param Archive
  *   All Stream Descriptors with Role Archive
  */
  enum Family {All,Authoring, AuthoringVisu, AuthoringVisuExtended ,AuthoringExtended, AuthoringVisuAlternative, Archive};
}
#endif
