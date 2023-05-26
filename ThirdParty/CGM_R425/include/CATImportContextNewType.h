/* -*-c++-*- */
#ifndef CATImportContextNewType_h
#define CATImportContextNewType_h
// COPYRIGHT DASSAULT SYSTEMES   2000
//
//  *****************************************************************
//  * Nouveaux types créés en cours de SP de CATImportContextType.h *
//  *    Ne pas inclure ce fichier dans une ProtectedInterfaces !   *
//  *****************************************************************
//  * New types created with SP releases of CATImportContextType.h  *
//  *  Do not include this file within a ProtectedInterfaces file!  *
//  *****************************************************************
/**
 * The import context new type list.
 * <br><b>Legal values</b>: <ul>
 * <li><tt>CATSelectionInCurrentContext</tt>: the selected element is in the current document context (Part, Sketch...).</li>
 * <li><tt>CATSelectionInPassiveContext</tt>: the selected element is in another document context which is not active for a complete selection.</li>
 * <li><tt>CATSelectionInOtherDocument</tt>: the selected element is in another document context (mechanical part...).</li>
 * <li><tt>CATSelectionInOtherSketch</tt>: the selected element is in the another sketch.</li></ul>
 * <li><tt>CATSelectionInPublishedObjectsNode</tt>: the selected element has been selected in the graph published objects node.</li></ul>
 */

#define CATSelectionInBRepModeContext      (1<<  3)
#define CATSelectionInPublishedObjectsNode (1<< 10)

#endif
