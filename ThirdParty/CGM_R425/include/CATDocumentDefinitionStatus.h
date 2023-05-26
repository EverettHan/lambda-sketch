/* -*-c++-*- */
#ifndef CATDocumentDefinitionStatus_h
#define CATDocumentDefinitionStatus_h

// COPYRIGHT DASSAULT SYSTEMES   2002

/**
 * The document definition statut.
 * @param CATDefinitionInSettings 
 *   The definition is stored in setting file. 
 * @param CATDefinitionInDocument
 *  The definition is stored within the document. 
 * @param CATDefinitionAlwaysInDocument 
 *  The current object definition is to be read in the document.
 * @see CATIDocumentFiltersDefinition
 */

typedef unsigned long CATDocumentDefinitionStatus;

#define CATDefinitionInSettings       (1<< 0)
#define CATDefinitionInDocument       (1<< 1)
#define CATDefinitionAlwaysInDocument (1<< 2)

#endif
