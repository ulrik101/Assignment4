#include <iostream>
#include "StudentObject.h"
using namespace std;
class WindowObject
{
  public:
    WindowObject();
    ~WindowObject();
    StudentObject getStudent();
    void setStudent(StudentObject studentObject);


    bool isIdle();
    void setIdle(bool value);

    int getIdleTime();
    void addIdleTime(int number);
    void resetIdleTime();

    bool isIdleForOverFive();
    void setIdleForOverFive(bool value);

  private:
    bool idle;
    int idleTime;
    bool idleForOverFive;
    StudentObject student;
};
WindowObject::WindowObject()
{
  idle = true;
  idleTime = 0;
  idleForOverFive = false;
}
WindowObject::~WindowObject()
{

}
StudentObject WindowObject::getStudent()
{
  return student;
}
void WindowObject::setStudent(StudentObject studentObject)
{
  student = studentObject;
}

bool WindowObject::isIdle()
{
  return idle;
}

void WindowObject::setIdle(bool value)
{
  idle = value;
}

int WindowObject::getIdleTime()
{
  return idleTime;
}

void WindowObject::addIdleTime(int number)
{
  idleTime += number;
  if(idleTime >= 5)
  {
    idleForOverFive = true;
  }
}

void WindowObject::resetIdleTime()
{
  idleTime = 0;
  idleForOverFive = false;
}

bool WindowObject::isIdleForOverFive()
{
  return idleForOverFive;
}

void WindowObject::setIdleForOverFive(bool value)
{
  idleForOverFive = value;
}
