#ifndef PropertyMode_h
#define PropertyMode_h
//
// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
* Specification on property dialog object.
* @param Read
*        read only.
* @param Write
*        write mode.
* @see CATEditor#SetPropertyValue
*/
enum ModeReadWrite {Read ,Write} ;
/**
* Specification on state of the tabpage.
* @param Yes
*        the tabpage has been modified.
* @param Write
*        no modification done.
* @see CATEditorPage#SetPageModification
*/
enum ModeYesNo     {Yes  ,No   } ;
#endif
