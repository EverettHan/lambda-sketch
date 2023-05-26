/*
* @quickReview PTO 20220428 R424AssessedForLinux CTF_EXPORTEDBY
*/

#ifndef CATSYPRemoveExportWarning_H
#define CATSYPRemoveExportWarning_H

/*
 * This include files disable the warning C4251 that is raised by
 * Microsoft Visual C++ compiler when an exported (i.e. __declspec(dllexport))
 * has some data members that are classes and those classes are
 * not exported.
 * This is typically the case when the data members are template
 * classes (such as CATSYPArray for example) since those classes
 * can't be exported.
 * Note that using this includes will disable the same warning
 * for all classes, not only for the template classes. But there
 * seem to be no way to deactivate the warning only for a specific
 * class.
 */

#ifdef _WINDOWS_SOURCE

#pragma warning( disable : 4251 )
#endif // _WINDOWS_SOURCE

#endif // CATSYPRemoveExportWarning_H
