/* -*-c++-*- */
#ifndef CATImportContextType_h
#define CATImportContextType_h
// COPYRIGHT DASSAULT SYSTEMES   2000

/**
 * The import context type list.
 * <br><b>Legal values</b>: <ul>
 * <li><tt>CATSelectionInCurrentContext</tt>: the selected element is in the current editor context (Part, Sketch...).</li>
 * <li><tt>CATSelectionInPassiveContext</tt>: the selected element is in another editor context which is not active for a complete selection.</li>
 * <li><tt>CATSelectionInOtherDocument</tt>: the selected element is in another mechanical part.</li>
 * <li><tt>CATSelectionInOtherSketch</tt>: the selected element is in the current mechanical sketch.</li></ul>
 */

typedef unsigned long CATULong;
#define CATSelectionInCurrentContext (0)
#define CATSelectionInOtherDocument  (1<< 0)
#define CATSelectionInOtherSketch    (1<< 1)
#define CATSelectionInPassiveContext (1<< 2)

#endif
