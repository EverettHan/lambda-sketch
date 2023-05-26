// COPYRIGHT Dassault Systemes 2008

#ifndef CATViewUtility_H
#define CATViewUtility_H

// SCA : Modification des valeurs de style
//       Il y en a partout, c'est n'importe quoi !
//       voir CATIObjectViewModel.h
//       voir CATListViewSort.h
//       voir CATIListViewModel.h
//       Donc regroupement dans CATViewUtility.h de tous les styles.

// voir CATIListViewModel.h
// Standard cell look
#define CATViewItemStyleNormal   (1 << 0)
// Green cell
#define CATViewItemStyleOK       (1 << 1)
// Red cell
#define CATViewItemStyleKO       (1 << 2)
// Orange cell
#define CATViewItemStyleWarning  (1 << 3)
// Custom cell
#define CATViewItemStyleCustom   (1 << 4)
// Custom cell
#define CATViewItemStyleColor    (1 << 5)

// voir CATListViewSort.h
// The format modifier for date (use with CATTime) is %x
#define CATObjectViewStyleDate   (1 << 7)
// Alphabetic sorting
#define CATObjectViewStyleString (1 << 8)
// Use with numerical data. Numbers cannot be sorted like strings (ex. 1,10,11,12,2,20,3,4,5,55,6..)
#define CATObjectViewStyleNumber (1 << 9)

// voir CATIObjectViewModel.h
#define CATObjectViewStyleNormal        0x0000
#define CATObjectViewStyleRightJustify  (1 << 11)
#define CATObjectViewStyleCenterJustify (1 << 12)

// Voir CATScrollbarView
#define CAT3DNSBVertical             (1 << 13 )
#define CAT3DNSBHorizontal           (1 << 14 )

// Voir CATDrawView
#define CATDrawViewVPCompassPriority (1 << 23 )

// Text before icon
#define CATViewItemStyleTextbIcon    (1 << 24)
#define CATViewItemStyleNoCropIcon   (1 << 25)

#endif
