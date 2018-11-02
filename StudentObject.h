#include <iostream>
//#include "WindowObject.h"
using namespace std;
class StudentObject
{
  public:
    StudentObject();
    StudentObject(int newIssueTime);
    ~StudentObject();
    //WindowObject getWindow();
    //void setWindow(WindowObject windowObject);
    void setIssueTime(int number);
    int getIssueTime();
    bool reduceIssueTime(int number);
    void addWaitTime(int number);
    bool isWaiting();
    void setWaiting(bool value);
    bool isDone();
    void setDone(bool value);
    int getWaitTime();
    void setOverTenWaitTime(bool value);
    bool isOverTenWaitTime();
  private:
    int issueTime;
    int waitTime;
    bool waiting;
    bool overTenWaitTime;
    bool done;
    //WindowObject window;


};

StudentObject::StudentObject()
{
  issueTime = 0;
  waitTime = 0;
  waiting = true;
  overTenWaitTime = false;
}
StudentObject::StudentObject(int newIssueTime)
{
  issueTime = newIssueTime;
  waitTime = 0;
  waiting = true;
  overTenWaitTime = false;
}
StudentObject::~StudentObject()
{

}
/*
WindowObject StudentObject::getWindow()
{
  return window;
}
void StudentObject::setWindow(WindowObject windowObject)
{
  window = windowObject;
}*/
void StudentObject::setIssueTime(int number)
{
  issueTime = number;
}
int StudentObject::getIssueTime()
{
  return issueTime;
}
bool StudentObject::reduceIssueTime(int number)//reduces the remaining issue time. if the student issue time has reached zero, it returns true to signify the student has finished.
{
  if(issueTime > number)
  {
    issueTime-=number;
    return false;
  }
  else
  {
    issueTime = 0;
    return true;
  }

}
void StudentObject::addWaitTime(int number)
{
  waitTime+=number;
  if(waitTime >= 10)
  {
    overTenWaitTime = true;
  }
}
bool StudentObject::isWaiting()
{
  return waiting;
}
void StudentObject::setWaiting(bool value)
{
  waiting = value;
}
bool StudentObject::isDone()
{
  return done;
}
void StudentObject::setDone(bool value)
{
  done = value;
}
int StudentObject::getWaitTime()
{
  return waitTime;
}
void StudentObject::setOverTenWaitTime(bool value)
{
  overTenWaitTime == value;
}
bool StudentObject::isOverTenWaitTime()
{
  return overTenWaitTime;
}
