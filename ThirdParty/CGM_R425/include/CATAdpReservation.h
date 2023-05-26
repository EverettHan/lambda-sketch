#ifndef CATAdpReservation_H
#define CATAdpReservation_H

/**
 * Definition in TOS of Reservation Status of the opened component.
 *
 *
 *  <tt> Possible values:</tt>
 *  <dl>
 *      @param <tt>CatAdpReservation_Undefined</tt>   <dd> Default status when it is not explicitely set.
 *      @param <tt>CatAdpReservation_ByLock</tt>    <dd> Status when a component has been switched into Editable at open, because it's locked by the currently connected user.
 *      @param <tt>CatAdpReservation_BySwitch</tt>   <dd> Status when a component has been switched into Editable with "Switch To Editable" command.
 * </dl>
 */

/**
 * @level Private
 * @usage U1
 */

enum  CATAdpReservation 
{
    CatAdpReservation_Undefined,
    CatAdpReservation_ByLock,
    CatAdpReservation_BySwitch
};

#endif
