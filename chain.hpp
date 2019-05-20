#include <iostream>
using namespace std;


namespace itertools{

	template <typename C1, typename C2> 
	class chain{
	public:

	C1 c1;
	C2 c2;
	
	chain<C1,C2>(const C1 r1, const C2 r2) : c1(r1),c2(r2) {} // constructor  of chain class

	;// end class
	
	class const_iterator{

 	private:
 		typename C1::const_iterator i1; // typename: to specify to the compiler that this is a type (of const_iterator of range) and not value
 		typename C2::const_iterator i2; 
 		
 		bool secondIter;					
	public:

		const_iterator(typename C1::const_iterator c_1, typename C2::const_iterator c_2) : i1(c_1), i2(c_2) {// constructor of the iterator  
		secondIter=false;		
		}

		auto operator*() const{ 
		if (secondIter==true) return *i2;
		else
			return *i1; 
		}

		//C1* operator->() const{
			// ?? 	FIXME
		//}

		const_iterator& operator++(){//++i
		if (secondIter==true) i2++;
		else i1++;
		return *this;	
		}
	
		const const_iterator operator++(int){//i++
		const_iterator tmp=*this;
		if (secondIter==true) i2++;
		else i1++;
		return tmp;	
		}
	
		bool operator==(const const_iterator& other) {
			return (i1 == other.i1);
		}
	
		bool operator!=(const const_iterator& other) {
		if (secondIter==true){
			return (i2 != other.i2);		
		}			
			else
				if (i1 == other.i1) { // if you have reached the end of the first iterator
						secondIter = true;	return true; 
					}
					else
						return true;
					}
			};// end class
	
	
			const_iterator begin() const{
			return chain<C1,C2>::const_iterator(c1.begin(), c2.begin()); 
			}
		
			const_iterator end() const{
			return chain<C1,C2>::const_iterator(c1.end(), c2.end());
			}
	
		}; // end main class

}
// end namespace