#ifndef CATVidInputEventArgs_H
#define CATVidInputEventArgs_H

#include <VisuDialog.h>

#include <CATSYPEventArgs.h>

/** @ingroup VIDGP
 * Base class for dispatching arguments of input events.
 *
 * It offers a common way to know when the event was emitted.
 */
class ExportedByVisuDialog CATVidInputEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;
protected:
  /** 
   * Initialize this class.
   *
   * The constructor is protected since this class should be a base
   * class for other events.
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   *
   * @param i_timestamp the timestamp in milli-seconds of the
   * interaction represented by the dispatch of the event.
   */
  CATVidInputEventArgs(CATSYPEvent *i_pEvent, CATULONG32 i_timestamp);

public:
  /** Destroy this class */
  virtual ~CATVidInputEventArgs();

  /**
   * Get the timestamp in milli-seconds of the interaction represented
   * by the dispatch of the event.
   */
  CATULONG32 GetTimestamp() const;

    /**
   * Transaction type enumeration : permit to "tag" an event to avoid conflicts in touch
   */
  enum TransactionType{
    //Normal transaction
    StandardTransactionType,
    //Scroll transaction
    ScrollTransactionType,
    //Drag and Drop transaction
    DnDTransactionType,
    //Affichage des tooltips
    HoldTransactionType, 
    //Flick transaction
    FlickTransactionType,
    //Scroll consume transaction type
    ScrollConsumeTransactionType,
    //Ondrag sur un Ctl
    DragWeakTransactionType,
  };
  void SetTransactionType(CATVidInputEventArgs::TransactionType i_pStandartTransactionType);
  CATVidInputEventArgs::TransactionType GetTransactionType() const;
private:
  CATVidInputEventArgs(const CATVidInputEventArgs &);
  CATVidInputEventArgs &operator=(const CATVidInputEventArgs &);
private:
  /** the timestamp in milli-seconds of the interaction represented by
      the dispatch of the event */
  const CATULONG32 _timestamp;
  //Mark the event of the GP
  TransactionType _eType;
};

#endif // CATVidInputEventArgs_H
