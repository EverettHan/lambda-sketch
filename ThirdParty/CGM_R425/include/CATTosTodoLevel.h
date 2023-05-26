#ifndef CATTosTodoLevel_H
#define CATTosTodoLevel_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of the TOS level for retrieving one handle.
 * The component todo status can be evaluated globally or from the last local save operation.
 *
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CatTosTodoLevel_Undefined</tt>         <dd>The appropriate level will be choose according to working context.
 * @param <tt>CatTosTodoLevel_Global</tt>            <dd>Choose the global log status (LOG:Standard).
 * @param <tt>CatTosTodoLevel_Differential</tt>      <dd>Choose the differential log status (LOG2:LocalSave).
 * </dl>
 */
enum CATTosTodoLevel
{
  CatTosTodoLevel_Undefined,
  CatTosTodoLevel_Global,
  CatTosTodoLevel_Differential
};

#endif



