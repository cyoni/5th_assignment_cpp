

#include <iostream>
#include <sstream>  
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"


#include "badkan.hpp"
#define COMMA ,

using namespace itertools;

/*

template<typename Iterable>
 string iterable_to_string(const Iterable &it) {
	
		ostringstream ostr;
		for (decltype(it.begin()) i: it)
		ostr << i << ",";
		return ostr.str();
}
*/

/*
		template<typename Iterable>
		string iterable_to_string(const Iterable &iterable){
		ostringstream ostr;
		for (decltype(iterable.begin()) i: iterable)
		ostr << i << ",";
		return ostr.str();
	}
*/
class Test{
	public:
	Test(){}

void clean(string& r){r="";}


};//end class

int main() {

	Test test;

	string range1 = "5678", actual1 = ""; for (int i: range(5,9))	actual1 += to_string(i);
	string range2 = "123", actual2 = ""; for (int i: range(1,4))	actual2 += to_string(i);
	string range3 = "5.56.57.58.5", actual3 = ""; for (double i: range(5.5,8.5))	actual3 += to_string(i);
	string range4 = "shalom", actual4 = ""; for (char i: string("shalom"))	actual4 += to_string(i);

	string chain1 = "567810111213", actual5 = ""; for (int i: chain(range(5,9), range(10,14)))	actual5 += to_string(i);
	string chain2 = "abdshalom", actual6 = ""; for (char i: chain(range('a','d'), string("shalom")))	actual6 += to_string(i);
	string chain3 = "12345hello", actual7 = ""; for (int i: chain(range(1,6), string("hello")))	actual7 += to_string(i);

	string zip1 = "1,5 2,6 3,7", actual8 = ""; for (auto i:  zip(range(1,4), range(5,8)))	actual8 += to_string(i);
	string zip2 = "1,c 2,+ 3,+", actual9 = ""; for (auto i:  zip(range(1,4), string("c++")))	actual9 += to_string(i);
	string zip3 = "1,x,a,6  2,y,b,7  3,z,c,8", actual10 = ""; for (auto i:  zip(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9))))	actual10 += to_string(i);
	
	string product1 = "1,h  1,e  1,l  1,l  1,o  2,h  2,e  2,l  2,l  2,o  3,h  3,e  3,l  3,l  3,o", actual11 = ""; for (auto i: product(range(1,4), string("hello")))	actual11 += to_string(i);
	string product2 = "1,5  1,6  1,7  1,8  1,9  2,5  2,6  2,7  2,8  2,9  3,5  3,6  3,7  3,8  3,9", actual12 = ""; for (auto i: product(range(1,4), range(5,9)))	actual12 += to_string(i);

//	string powerset1 = "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}", actual13 = "";   iterable_to_string(powerset(chain(range('a','c'),range('x','z'))));
	//string powerset2 = "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}", actual14 = ""; for (auto i:  iterable_to_string(powerset(range(1,4))))	actual14 += to_string(i);
	
	
	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// MY TESTS 

			testcase.setname("range test")
			.CHECK_EQUAL(actual1 , range1)
			.CHECK_EQUAL(actual2 , range2)
			.CHECK_EQUAL(actual3 , range3)
			.CHECK_EQUAL(actual4 , range4)
			;
			
			testcase.setname("chain test")
			.CHECK_EQUAL(actual5 , chain1)
			.CHECK_EQUAL(actual6 , chain2)
			.CHECK_EQUAL(actual7 , chain3)
			;
			
			testcase.setname("zip test")
			.CHECK_EQUAL(actual8 , zip1)
			.CHECK_EQUAL(actual9 , zip2)
			.CHECK_EQUAL(actual10 , zip3)
			;
	
			testcase.setname("product test")
			.CHECK_EQUAL(actual11 , product1)
			.CHECK_EQUAL(actual12 , product2)
			;
	
			testcase.setname("powerset test")
		//	.CHECK_EQUAL(actual13 , powerset1)
		//	.CHECK_EQUAL(actual14 , powerset2)
			;	
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
	}


