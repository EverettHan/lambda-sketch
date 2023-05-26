#ifndef CATPolyThreadPool_H_
#define CATPolyThreadPool_H_

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#ifdef _WINDOWS_SOURCE

#include <windows.h>
#include <processthreadsapi.h>

#endif



class CATPolySemaphore
{
public:
  CATPolySemaphore(int count_ = 0,char* debugdump=nullptr)
    : count(count_),
    debug(debugdump)
  {
    //printf("count %d\n", count);
  }
  char* debug=nullptr;

  void notify()
  {
    std::unique_lock<std::mutex> lock(mtx);
    count++;

    if (debug)
    {
      printf("%s notify : count  %d\n",debug, count);
      fflush(stdout);
    }
    cv.notify_one();
  }

  void unnotify()
  {
    std::unique_lock<std::mutex> lock(mtx);
    count--;
    if (debug)
    {
      printf("%s unnotify : count is now %d (before %d)\n",debug, count,count+1);
      fflush(stdout);
    }
    cv.notify_one();
  }

  void notifyall()
  {
    cv.notify_all();
  }

  void wait()
  {
    std::unique_lock<std::mutex> lock(mtx);

    if (debug)
    {
      printf("%s wait in : count %d vs 0\n",debug,  count);
      fflush(stdout);
    }
    while (count == 0)
    {
      cv.wait(lock);
    }
    count--;
    if (debug)
    {
      printf("%s wait out : count %d\n",debug, count);
      fflush(stdout);
    }
  }

  /*void waitanydiff()
  {
    std::unique_lock<std::mutex> lock(mtx);

    if (debug)
      printf("%s wait in : count %d\n",debug,  count);
    while (count == 0)
    {
      cv.wait(lock);
    }
    count--;
    if (debug)
      printf("%s wait out : count %d\n",debug, count);
  }*/

  void waitNot(int val=0.0)
  {
    //flushall();
    std::unique_lock<std::mutex> lock(mtx);
    if (debug)
      printf("%s wait count %d != %d\n",debug, count,val);
    //flushall();
    while (count == val)
    {
      if (debug)
      {
        printf("\t %s wait count %d/%d\n", debug, count,val);fflush(stdout);
      }
      //flushall();
      cv.wait(lock);
      if (debug)
      {
        printf("\t %s wait count evolve %d/%d\n\n", debug, count,val);fflush(stdout);
      }
    }
  }
  void waitCount(int val)
  {
    //flushall();
    std::unique_lock<std::mutex> lock(mtx);
    if (debug)
      printf("%s wait count %d vs %d\n",debug, count,val);
    //flushall();
    while (count != val)
    {
      if (debug)
      {
        printf("\t %s wait count %d/%d\n", debug, count,val);fflush(stdout);
      }
      //flushall();
      cv.wait(lock);
      if (debug)
      {
        printf("\t %s wait count evolve %d/%d\n\n", debug, count,val);fflush(stdout);
      }
    }
    if (debug)
    {
        printf("%s wait end  count %d\n!!!\n",debug, count);
        fflush(stdout);
    
    }
  }





private:
  std::mutex mtx;
  std::condition_variable cv;
  int count;
};



/*template<T>
class CATPolyThreadQueue
{
public:

  bool empty()
  {
    bool resu = false;
    _queue_mutex.lock();
    resu = _impl.empty();
    _queue_mutex.unlock();
    return resu;
  }

  bool push()
  {
    bool resu = false;
    _queue_mutex.lock();
    resu = _WorkingOperators.push(_operators.front());
    _queue_mutex.unlock();
    return resu;
  }

protected:
  std::queue<T> _impl;
  std::mutex _queue_mutex;
};*/
/**
  pure interface of a task execute by the pool
  you must implement the method ThreadRun
*/
class CATPolyThreadPoolTask
{
public:
  virtual void ThreadRun() = 0;
};

/**
  removing task is not allowed
  but adding task after starting is allowed
*/
class CATPolyThreadPool
{
public:
  CATPolySemaphore _AliveThread;
  CATPolySemaphore _IdleThread;
  CATPolySemaphore _TaskWorker;
  CATPolySemaphore _TaskNotFinish;
  CATPolySemaphore _AddOperators;
  CATPolySemaphore _TaskRunning;
  CATPolySemaphore _LaunchTasksIsRunning;

  CATPolyThreadPool(unsigned int nbthread=4)
    : _IdleThread(0,nullptr)//*/"IDLE")
    , _AliveThread(0,nullptr)
    , _TaskWorker(0,nullptr)//"_TaskWorker")
    , _AddOperators(0)
    , _TaskRunning(0,nullptr)//,*/"_TaskRunning")
    , _LaunchTasksIsRunning(0,nullptr)//,*/"_LaunchTasksIsRunning")
  {
    _end = false;
    _NbThread = nbthread;

    for (unsigned int i = 0; i < nbthread; i++)
    {
      _threads.push_back(std::thread(&CATPolyThreadPool::ThreadRun, this, i));
    }
  }

  void _CleanThreads()
  {
    _AliveThread.waitCount(_NbThread);
    //flag to say stop your works
    _end =true;
    //
    for (unsigned int  i = 0; i < _NbThread; i++)
      _TaskWorker.notify();

    //now we wait that all thread are dead
    _AliveThread.waitCount(0);

    //_IdleThread.waitCount(_NbThread);
    /*for (unsigned int  i = 0; i < _NbThread; i++)
      _IdleThread.unnotify();*/

    /*_queue_mutex_operators.lock();
    _operators = std::queue<CATPolyThreadPoolTask*>();
    _queue_mutex_operators.unlock();
    */
    if (_launcher.joinable())
      _launcher.detach();
    for (unsigned int  i = 0; i < _NbThread; i++)
    {
      //_threads[i].join();
      if (_threads[i].joinable())
        _threads[i].join();
    }

    for (unsigned int  i = 0; i < _NbThread; i++)
    {
      if (_threads[i].joinable())
        _threads[i].detach();
    }

    _threads.resize(0);


  }

  void ResetNbThreads(unsigned int nbThread)
  {
    if (nbThread==_NbThread)
      return;
    //printf("ResetNbThreads(%d)\n",nbThread );
    //first wait that all the thread are correctly started
    _CleanThreads();
    
    _end = false;
    _NbThread = nbThread;
    for (unsigned int  i = 0; i < nbThread; i++)
    {
      _threads.push_back(std::thread(&CATPolyThreadPool::ThreadRun, this, i));

    }
 


  }

  ~CATPolyThreadPool()
  {
    //printf(" ~CATPolyThreadPool()\n");fflush(stdout);
    //remove all task not done
    _queue_mutex_operators.lock();
    _operators = std::queue<CATPolyThreadPoolTask*>();
    _queue_mutex_operators.unlock();

    _CleanThreads();
    if (_WorkingOperators.size() > 0)
    {
      _WorkingOperators = std::queue<CATPolyThreadPoolTask*>();
    }

  }

  unsigned int GetNbThread() const
  {
    return _NbThread;
  }

  void AddTask(CATPolyThreadPoolTask* task)
  {
    _queue_mutex_operators.lock();
    _operators.push(task);
    _AddOperators.notify();
    _queue_mutex_operators.unlock();
  }

  CATPolyThreadPoolTask* PopTask()
  {
    CATPolyThreadPoolTask* task = nullptr;
    _AddOperators.wait();//wait for a task
    _queue_mutex_operators.lock();
    task = _operators.front();
    _operators.pop();
    _queue_mutex_operators.unlock();
    return task;
  }

  unsigned int NbTask()
  {
    unsigned int nb = 0;
    _queue_mutex_operators.lock();
    nb = (unsigned int) _operators.size();
    _queue_mutex_operators.unlock();
    return nb;
  }

  unsigned int NbWorkingTask()
  {
    unsigned int nb = 0;
     _queue_mutex.lock();
    nb = (unsigned int) _WorkingOperators.size();
    _queue_mutex.unlock();
    return nb;
  }

  
  
  

  /*
    Not threaded version
  */
  void RunInSequence()
  {
    while (NbTask() != 0)
    {
      CATPolyThreadPoolTask* task = PopTask();
      if (task)
        task->ThreadRun();
    }
  }

  void RunInParallel()
  {
    
    _end=false;
    if (_NbThread != 0)
    {
      _LaunchTasksIsRunning.waitCount(0);//make sure nobodyelse where running
      _LaunchTasksIsRunning.notify();
      _launcher =std::thread(&CATPolyThreadPool::LaunchTasks, this);
    }
    else
    {
      RunInSequence();
    }
  }

  void WaitAll()
  {

    if (_NbThread != 0)
    {
      //while(NbTask()!=0)
      _LaunchTasksIsRunning.waitCount(0);
      /*if (_launcher.joinable())
        _launcher.detach();*/
        /*while(NbTask()!=0)
        {
          //attend qu'un thread sur les _NbThread soit libre
          _IdleThread.waitCount(_NbThread);
          _TaskRunning.waitCount(0);//wait that all task are finished
          if (NbTask()!=0)
          {
            NotifyOneTasks();
            _IdleThread.notifyall();//unlock task
          }

        }*/
    }
    //printf("wait all %d\n",_NbThread);
    //flushall();
  }

  void StopAll()
  {
      //remove all task not done
    _queue_mutex_operators.lock();
    _operators = std::queue<CATPolyThreadPoolTask*>();
    _queue_mutex_operators.unlock();

    //then notify that the job can finish
    //for (unsigned int i = 0; i < _NbThread; i++)
      //_TaskWorker.notify();

  }
protected:


  void NotifyOneTasks()
  {

    {
      _queue_mutex.lock();
      _WorkingOperators.push(PopTask());
      _TaskWorker.notify();//notify that new task are select
      _queue_mutex.unlock();
    }
  }

  void LaunchTasks()
  {

#ifdef _WINDOWS_SOURCE
    HRESULT r;

    //remark SetThreadDescription does not exist on all version of windows
    //https://github.com/BuckeyeSoftware/rex/issues/1
    decltype(&SetThreadDescription) set_thread_description;
    *(void **)&set_thread_description =
      GetProcAddress(GetModuleHandleA("kernel32.dll"), "SetThreadDescription");
    if (set_thread_description!=nullptr)
    {
      //set_thread_description = &set_thread_description_fallback;

      r = set_thread_description(
          GetCurrentThread(),
          L"CATPolyThreadPool::LaunchTasks"
      );
    }
#endif

    while(NbTask() !=0 ){
        while (NbTask() !=0 )
        {
          _IdleThread.waitNot(0);//wait for idle thread
          NotifyOneTasks();

          //_operators.pop();
        }
        //printf("Consume all the task \n");fflush(stdout);
        while(NbWorkingTask()!=0)
        {
          _TaskRunning.waitCount(0);
        }
        //printf("end all the task \n");fflush(stdout);
        
        //wait that last subtask finis;
        _IdleThread.waitCount(_NbThread);
        //may be new task arrived after last execution
        //printf("all thread idle \n");fflush(stdout);

    }
    //printf("no task all thread are idle end\n");fflush(stdout);
    _LaunchTasksIsRunning.unnotify();
    _launcher.detach();

  }

  void ThreadRun(unsigned int index)
  {
    _AliveThread.notify();
#ifdef _WINDOWS_SOURCE
    HRESULT r;
    //remark SetThreadDescription does not exist on all version of windows
    //https://github.com/BuckeyeSoftware/rex/issues/1
    decltype(&SetThreadDescription) set_thread_description;
    *(void **)&set_thread_description =
      GetProcAddress(GetModuleHandleA("kernel32.dll"), "SetThreadDescription");
    if (set_thread_description!=nullptr)
    {
      //set_thread_description = &set_thread_description_fallback;

      r = set_thread_description(
          GetCurrentThread(),
          L"CATPolyThreadPool::ThreadRun"
      );
    }



#endif
     _IdleThread.notify();
    //printf("Thread %d is created waiting for work...\n", index);fflush(stdout);
    //flushall();
    bool enterwhile = false;
    while (_end == false)
    {
      enterwhile=true;
      //printf("Thread %d after while \n", index);fflush(stdout);
      CATPolyThreadPoolTask* op = NULL;
      _TaskWorker.wait(); //waiting new task
      _IdleThread.unnotify();
      _TaskRunning.notify();
      {
        _queue_mutex.lock();
        //get the task
        if (_WorkingOperators.size() > 0)
        {
          op = _WorkingOperators.front();
          _WorkingOperators.pop();
        }

        _queue_mutex.unlock();
      } // notify the new task can be added

      if (op)
      {

        //printf("Thread %d working...\n", index);
        op->ThreadRun();
        //printf("Thread %d working end\n", index);
      }

      //printf("Thread %d renotify...\n", index);fflush(stdout);
      _IdleThread.notify();//notify that this thread is ready to accept new task
      _TaskRunning.unnotify();
    }
    //if (enterwhile==false)//specific case where we stop the threads before enter the while loop.
      _IdleThread.unnotify();
    //printf("Thread %d is deleted\n", index);fflush(stdout);

    _AliveThread.unnotify();
  };

  unsigned int _NbThread;

  bool _end;
  bool _waited;

  std::queue<CATPolyThreadPoolTask*> _operators;
  std::queue<CATPolyThreadPoolTask*> _WorkingOperators;
  std::mutex _queue_mutex;
  std::mutex _queue_mutex_operators;

  std::vector<std::thread> _threads;
  std::thread _launcher;
};

#endif
