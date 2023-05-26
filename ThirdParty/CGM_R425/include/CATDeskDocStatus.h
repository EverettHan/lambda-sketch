#ifndef CATDeskDocStatus_h
#define CATDeskDocStatus_h

// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * Status of a document..
 * @param CATDeskDocStatusOK
 *   The document is found and it's loaded.
 * @param CATDeskDocStatusUnloadable
 *   A document is found with the storage information, but it's not a CATIA document.
 * @param CATDeskDocStatusNotLoaded
 *   A document is found with the storage information, but it's not loaded.
 * @param CATDeskDocStatusNotFound
 *   No document can be found with the storage information.
 * @param CATDeskDocStatusUnknown
 *   An error occured.
 */
enum CATDeskDocStatus
{
  CATDeskDocStatusOK,
  CATDeskDocStatusUnloadable,
  CATDeskDocStatusNotLoaded,
  CATDeskDocStatusNotFound,
  CATDeskDocStatusUnknown
};
// NOTICE: the elements are sorted by severity. CATDeskDocStatusUnknown must be the last element.

#endif
