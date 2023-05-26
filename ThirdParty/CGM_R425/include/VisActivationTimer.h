#ifndef VisActivationTimer_H
#define VisActivationTimer_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/** 
 * Enumerates the different type of activation timer for touch devices.
 * <b>Role</b>: It can be used in CATViewer
 * to specify the activation timer for touch devices.
 * @param VisActivationTimer_Small
 * Use this enum to enable small short and long hold
 * @param VisActivationTimer_Normal
 * Use this enum to enable normal short and long hold
 * @param VisActivationTimer_Large
 * Use this enum to enable large short and long hold
 */

enum VisActivationTimer
{
 VisActivationTimer_Small=0,
 VisActivationTimer_Normal,
 VisActivationTimer_Large
};

#endif
