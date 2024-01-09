///////////////////////////////////////////////////////////////////////////
//  bug1.cpp
//   
// 
//   Created by jmaletic on 9/9/13.
// 
//   This code prints out a sets of random numbers, no duplicates per set.
//
//   There is a bug in this code.  It compiles but seems to get into an infinit loop.
//   Find the bug.
//
//   Step 1: Compile the program clang++ -Wall bug1.cpp -o buggy
//           Run it ./buggy  ctrl c to break it.
//   Step 2: Read over the code and figure out what it does a bit.
//           Insert print statements into the different loops to 
//           determine where the infinite loop is occurring.
//           Start in the main and work down the call stack.
//   Step 3: Once you figure out what loop is the problem try to 
//           figure out what it is supposed to do and why its broken.
//   Step 4: Make the fix and compile/run the program
//   Step 5: Does it work?  



#include <iostream>
#include <cstdlib>

const int MAX             = 6;
const int SIZE_OF_SAMPLES = 3;
const int REP             = 5;

bool inArray     (int[], int, int  );
void UniqRandInt (int,   int, int[]);



///////////////////////////////////////////////////////////////////////////
int main() {
    std::cerr<<"in main\n";

    int arr[SIZE_OF_SAMPLES];
    
    srand(9809);  //Seed random number generator.
    
    //     std::cerr<<"entering first loop\n";
    for (int i = 0; i < REP; i++) {
      // std::cerr<< "inside for loop\n";
      // std::cerr<< "i = " << i << std::endl;
        UniqRandInt(MAX, SIZE_OF_SAMPLES, arr);
	//	std::cerr << "function completed\n";
        for(int j = 0; j < SIZE_OF_SAMPLES; j++) {
	  //  std::cerr<<"inside nested loop\n";
            std::cout << arr[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////
// result[n] will be initialized with a set of random numbers, no duplicates
//           Values between 0 and max.
// 
void UniqRandInt(int max, int n, int result[]) {
  // std::cerr<< "inside function\n";
    int cntr = 0, r;

    while(cntr < n) {
      // std::cerr<<"inside while loop\n";
      //  std::cerr<< "cntr = " << cntr << std::endl;
        r = rand();  //Get random number
        r = r % (max + 1);
	//I added this
	while (inArray(result, cntr, r)){
	    r = rand();
	    r = r % (max + 1);
	    //  std::cerr<<"in my while loop\n";
	  }
	  // end of my addition
        if (!inArray(result, cntr, r)) {
	  //  std::cerr<< "inside if statement\n";
            result[cntr] =  r;
	    // std::cout << "result[" << cntr << "] = " << r << std::endl;
            cntr++;
        }
    }
    return;
}

///////////////////////////////////////////////////////////////////////////
// Check if x is included in array[] of arrSize.
// Returns: 1 if x is a member
//           0 if x is not a member
//

bool inArray(int array[], int arrSize, int x) {
    for (int i = 0; i < arrSize; ++i) {
        if (array[i] == x) {
	  // std::cout << array[i] << "=" << x << std::endl;
          return true;
        }
	//	if (array[i] != x)
	  // std::cout << array[i] << "!=" << x << std::endl;
    } return false;

}
