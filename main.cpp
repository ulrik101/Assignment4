#include <iostream>
//#include "ReadFile.h"
//#include "OfficeObject.h"
#include "FileInput.h"
#include "ReadFile.h"

//#include "Queue.h"

//#include "DoubleLinkedList.h"

using namespace std;


int main()
{
  std::cout << "See ReadMe.txt File. Most of the Assignment is done but lacking a critical function." << std::endl<< std::endl;

  std::string fileName = getFileName("Enter File Name and Path Starting from this folder.");//gets file name from user
  readFile(fileName);


















/*
  OfficeObject office;
  office.setWindowNum(2);
  office.addStudent(5);
  office.addStudent(3);
    office.TEMPPRINT();

  office.updateTime();
  std::cout << std::endl;

  office.updateTime();
  office.TEMPPRINT();

  std::cout << std::endl;

  office.updateTime();
  office.TEMPPRINT();
  //office.updateTime();*/
/*
Queue<int> queue;

std::cout << "Empty: " << queue.isEmpty() << std::endl;
queue.insert(5);
queue.insert(7);
queue.insert(10);
queue.insert(3);
//queue.printQueue();
std::cout <<queue.peek()<< std::endl;
queue.remove();
//queue.printQueue();
std::cout << "Empty: " << queue.isEmpty() << std::endl;
std::cout << "Size: " << queue.getSize() << std::endl;

*/



  //readFile("poop");
  std::cout << std::endl;


  //std::cout << "Size: " <<test.getSize() << std::endl;

  std::cout << "END" << std::endl;
  return EXIT_SUCCESS;
}
