
#include<fstream>
#include<iostream>
using namespace std;



class ReadFile
{
  public:
    void readFile(std::string fileName);
};
void readFile(std::string fileName)
{
  bool windowBool = true;
  bool clockChangeBool = false;
  bool studentBool = false;
  bool studentNumBool = false;

  int studentNum = 0;
  int clockCurrent = 0;
  int clockPrevious = 0;
  int timeElapsed = 0;

  studentNum = 0;
  ifstream file(fileName);
  if(file.is_open())
  {
    while(!file.eof())
    {
      std::string local_string;
      file >> local_string;
      int tempInt;
      try
      {
        tempInt = std::stoi (local_string,nullptr,10);//converts to int
      }
      catch(const std::exception& e)
      {
        std::cout << "Input Error: Invalid format within file. Only use Integers."<< std::endl;
        break;
      }

      if(windowBool)//sets the initial number of windows
      {
        std::cout << "Window Num: " << tempInt << std::endl;
        windowBool = false;
        clockChangeBool = true;
      }
      else if(clockChangeBool)//manages the numbers that represent clock change
      {
        std::cout << "clock change(keep incrementing by one until this new time is met. Update variables and objects each increment.): " << tempInt << std::endl;
        clockChangeBool = false;
        studentBool = true;
        studentNumBool = true;
      }
      else if(studentBool)//manages the numbers that represent students shit

      {
        if(studentNumBool)//manages the numbers that represent how many students arrive
        {
          studentNum = tempInt;
          std::cout << "student Num (number of loops to create students): " << studentNum << std::endl;
          studentNumBool = false;
        }
        else//manages how much time each student spends
        {
          std::cout << "set student time (create new object here with the givin Issue Time. Then Add to Queue): " << local_string << std::endl;


          studentNum--;
          if(studentNum == 0)
          {
            studentBool = false;
            clockChangeBool = true;
          }
        }
      }
    }
    std::cout << "Calculate Mean/Median/Longest Times here." << std::endl;

  }
}
