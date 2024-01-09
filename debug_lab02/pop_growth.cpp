#include <iostream>

const int STRING_SIZE = 512 ;   //increase the size

int calculatePopulation(int, int);

int main(int argc, const char * argv[]) {

  
  std::cout << "Enter the name of the university\n";
  char univName [STRING_SIZE];   // Is length a issue here 
  std::cin.getline(univName, STRING_SIZE);

  char done = 'N';
  
  while ((done == 'N') || (done == 'n')) { // "=" or "=="
    
    std::cout << "What is the current population? ";
    int pop;
    std::cin >> pop;
    while(pop < 1) {
      std::cout << ": Invalid Input Error!\n";
      return -1;
    }
        
    std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
    int growth;
    std::cin >> growth;
    while(growth < 0) {
      std::cout << ": Invalid Input Error!\n";
      return -1;
    }
        
    std::cout << "\nYear\tNew Population" << std::endl;
    int *newpop = new int;
    int i = 1;   //Iniitilize it 
    for (; i <= 5; i++) {
      *newpop = calculatePopulation( pop , growth );
      pop = *newpop;
      std::cout << i << "\t \t" << *newpop << std::endl;
      //delete newpop;   //Delete here will create trouble
    }
   

    std::cout << "\nFinal population of " << univName;
    std::cout << " is " << *newpop << std::endl;
    delete newpop;  //Delete here
    
    std::cout << "Done? (Y/N) ";
    std::cin >> done;
    switch (toupper(done)) {
      case 'Y':
	done = 'Y';
	std::cout << "Exiting...\n";
	break;
      case 'y':
	done = 'y';
	std::cout << "Exiting...\n";
	break;
      case 'N':
	done = 'N';
	std::cout << "Starting again\n";
	std::cout << "------------------------------\n";
	break;
      case 'n':
	done = 'n';
	std::cout << "Starting again\n";
	std::cout << "------------------------------\n";
	break;
      default:
	std::cout << ": Invalid input\n";
	std::cout << "The program will exit\n";
	std::cout << "------------------------------\n";
	return -1;
    }
   }
  return 0;
}

int calculatePopulation( int pop, int growth) {
  double growthRate = (double) growth / 100;
  double increase = (double) pop * growthRate;
  return (pop + increase);
    
}
