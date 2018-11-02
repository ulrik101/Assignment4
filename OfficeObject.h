#include <iostream>
//#include "StudentObject.h"
#include "WindowObject.h"
//#include "DoubleLinkedList.h"
#include "Queue.h"

using namespace std;
class OfficeObject
{
  public:
    OfficeObject();
    ~OfficeObject();
    void printStudentWaitTimeList();
    void printWindowIdleTimeList();
    void addStudentTime(const int waitTime);
    void addWindowTime(const int waitTime);
    void calcAll();


    void addStudent(int issueTime);

    void setWindowNum(int num);
    void updateTime();
    void TEMPPRINT();

    //void windowFinished();

    /*
    float calculateMeanStudentWaitTime();
    float calculateMedianStudentWaitTime();
    int getLongestStudentWaitTime();
    int getNumberStudentsThatWaitOverTen();*/
  private:
    void addSortTime(DoubleLinkedList<int> &list, int waitTime);

    int newTime;
    int oldTime;
    int elapsedTime;

    float meanStudentWaitTime;
    float medianStudentWaitTime;
    int longestStudentWaitTime;
    int numberStudentsThatWaitOverTen;

    float meanWindowIdleTime;
    int longestWindowIdleTime;
    int numberWindowsThatWaitOverFive;

    float calcMeanTime(DoubleLinkedList<int> &list);
    float calcMedianTime(DoubleLinkedList<int> &list);
    DoubleLinkedList<StudentObject> studentList;
    DoubleLinkedList<WindowObject> windowList;
    DoubleLinkedList<int> studentWaitTimeList;
    DoubleLinkedList<int> windowIdleTimeList;

    Queue<StudentObject> queue;

};
OfficeObject::OfficeObject()
{
  meanStudentWaitTime = 0;
  medianStudentWaitTime = 0;
  longestStudentWaitTime = 0;
  numberStudentsThatWaitOverTen = 0;

  meanWindowIdleTime = 0;
  longestWindowIdleTime = 0;
  numberWindowsThatWaitOverFive = 0;

}
OfficeObject::~OfficeObject()
{

}
void OfficeObject::setWindowNum(int num)
{
    for(int i = 1; i <= num; i++)
    {
      WindowObject *window = new WindowObject();
      windowList.insertBack(*window);
    }
}

void OfficeObject::TEMPPRINT()
{
  /*DoubleLinkedNode<StudentObject> *studentPointer = studentList.getFrontNode();
  //DoubleLinkedNode<WindowObject> *windowPointer = windowList.getFrontNode();

  while(studentPointer)//for all students
  {
      StudentObject student = studentPointer->data;
      std::cout << "Wait: " << student.getWaitTime() << "   Issue: " << student.getIssueTime() << std::endl;

      studentPointer = studentPointer->next;
  }*/
  std::cout << "Queue Empty: " << queue.isEmpty() << std::endl;

  //queue.printQueue();
}


void OfficeObject::addStudent(int issueTime)
{
  StudentObject *student = new StudentObject(issueTime);
  //studentList.insertBack(*student);
  queue.insert(*student);
}







void OfficeObject::updateTime()
{

  DoubleLinkedNode<WindowObject>* windowPointer = windowList.getFrontNode();

  while(windowPointer)//for all windows
  {
    //WindowObject window = windowPointer->data;

    if(windowPointer->data.isIdle())//if window is idle
    {

      if(!queue.isEmpty())//if student in queue
      {
        std::cout << "Window Empty, Student in Queue Added: " << std::endl;

        windowPointer->data.setStudent(queue.remove());//add next student to window
        windowPointer->data.setIdle(false);
      }
      else//no students in queue
      {
        windowPointer->data.addIdleTime(1);//add 1 to window idle time
        std::cout << "Window Empty, Going Idle: " << windowPointer->data.getIdleTime() << std::endl;

      }
    }
    else//if window has student
    {
      StudentObject student = windowPointer->data.getStudent();
/*
      if(student.reduceIssueTime(1))//subtrace one from student issue time
      {//if student issue is 0
        student.setDone(true);//remove student from window
        windowPointer->data.setIdle(true);//set to idle
      }*/

      std::cout << "Student in Window: Wait: " << windowPointer->data.getStudent().getWaitTime() << "   Issue: " << windowPointer->data.getStudent().getIssueTime() << std::endl;

    }
    //windowPointer->data = window;
    windowPointer = windowPointer->next;
  }


DoubleLinkedNode<StudentObject>* studentPointer = queue.peekNode();


while(studentPointer)
{
  StudentObject student = studentPointer->data;
  student.addWaitTime(1);//add 1 to student wait time
  std::cout << "Student in queue: Student Wait: " << student.getWaitTime() << "   Issue: " << student.getIssueTime() << std::endl;

  studentPointer->data = student;//commits data


  studentPointer=studentPointer->next;
}






  /*
  //need a no student check
  DoubleLinkedNode<StudentObject>* studentPointer = studentList.getFrontNode();
  while(studentPointer)//for all students
  {
    std::cout << "Student: 1" << std::endl;

    StudentObject student = studentPointer->data;
    if(!student.isDone())
    {
      std::cout << "Student: 2" << std::endl;
      if(student.isWaiting())//if student is waiting
      {
        std::cout << "Student: 3" << std::endl;
        student.addWaitTime(1);//add 1 to student wait time
      }
      else//if student is talking at window
      {
        if(student.reduceIssueTime(1))//subtrace one from student issue time
        {//if student issue is 0
          WindowObject window = student.getWindow();
          student.setDone(true);//remove student from window
          window.setIdle(true);//set to idle
        }
      }
      studentPointer->data=student;
    }
    studentPointer = studentPointer->next;
  }
  studentPointer = NULL;



  DoubleLinkedNode<WindowObject>* windowPointer = windowList.getFrontNode();
  while(windowPointer)//for all windows
  {
    WindowObject window = windowPointer->data;
    if(window.isIdle())//if window is idle
    {
      if(!queue.isEmpty())//if student in queue
      {
        StudentObject student = queue.remove();//add student to window
        student.setWaiting(false);//student no longer waiting
        window.setIdle(false);//no longer idle
        student.setWindow(window);
        addWindowTime(window.getIdleTime());//add time to window idle time list
      }
      else //no student in queue
      {
        window.addIdleTime(1);//add 1 to window idle time
      }
    }
    else //student at window
    {

    }
  windowPointer = windowPointer->next;
  }
  windowPointer = NULL;*/
}

//void OfficeObject::windowFinished();





























void OfficeObject::printStudentWaitTimeList()
{
  studentWaitTimeList.printList();
}
void OfficeObject::printWindowIdleTimeList()
{
  windowIdleTimeList.printList();
}

void OfficeObject::addStudentTime(const int waitTime)
{
  if(waitTime > 10)
  {
    numberStudentsThatWaitOverTen += 1;
  }
  if(waitTime > longestStudentWaitTime)
  {
    longestStudentWaitTime = waitTime;
  }
  addSortTime(studentWaitTimeList, waitTime);
}
void OfficeObject::addWindowTime(const int waitTime)
{
  if(waitTime > 5)
  {
    numberWindowsThatWaitOverFive +=1;
  }
  if(waitTime > longestWindowIdleTime)
  {
    longestWindowIdleTime = waitTime;
  }
  addSortTime(windowIdleTimeList, waitTime);
}

void OfficeObject::addSortTime(DoubleLinkedList<int> &list, int waitTime)
{
  DoubleLinkedNode<int> *node = list.getFrontNode();
  if(node)
  {
    while(node && waitTime < node->data)
    {
      node=node->next;
    }
    if(!node)
    {
      list.insertBack(waitTime);
    }
    else
    {
      list.insertBefore(node, waitTime);
    }
  }
  else
  {
    list.insertFront(waitTime);
  }

  /*
  int index = 0;
  if(list.isEmpty()==false)//if list is not empty
  {
    while(index < list.getSize())
    {
      if(waitTime >= list.returnData(index))
      {
        list.insertPos(waitTime, index);

        break;
      }
      else
      {
        if(waitTime==index)
        {
          list.insertBack(waitTime);

          break;
        }
      }
      index++;
    }
  }
  else//list is empty, so just add it.
  {
    list.insertFront(waitTime);

  }
  //std::cout << std::endl;
*/
}
void OfficeObject::calcAll()
{
  std::cout << "Student Mean: " << calcMeanTime(studentWaitTimeList) << std::endl;
  std::cout << "Student Median: " << calcMedianTime(studentWaitTimeList) << std::endl;
  std::cout << "Longest Wait: " << longestStudentWaitTime << std::endl;
  std::cout << "Number over 10: " << numberStudentsThatWaitOverTen << std::endl;


}
float OfficeObject::calcMeanTime(DoubleLinkedList<int> &list)
{
  float mean = 0;
  int counter = 0;
  DoubleLinkedNode<int> *node = list.getFrontNode();
  while(node)
  {
    mean+=node->data;
    node=node->next;
    counter++;
  }
  mean = mean/counter;
  return mean;
}
float OfficeObject::calcMedianTime(DoubleLinkedList<int> &list)
{
  DoubleLinkedNode<int> *node = list.getFrontNode();
  int counter = 0;
  while(node)
  {
    node=node->next;
    counter++;
  }

  float median = 0.0;
  float dividorFloat = ((counter/2)+.5);
  int dividor = (int)(dividorFloat);


  bool even = (counter%2==0);
  counter = 0;
  node = list.getFrontNode();
  while(node)
  {
    counter++;
    if(even)
    {
      if(counter == dividor)
      {
        median = ((node->data) + (node->next->data));
        median = median/2;
        return median;
      }
    }
    else
    {
      if(counter == (dividor+1))
      {
        median = node->data;
        return median;
      }
    }


    node=node->next;

  }
  return median;
}
