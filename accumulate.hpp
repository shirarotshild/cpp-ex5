# pragma once 

namespace itertools {
    
	typedef struct{
        template <typename T>
        T operator ()(T x, T y) const{
            T temp = x+y;
            return temp;
        }
    } add;
   
   template <typename container,typename function = add>
    class accumulate {
         container cont;
         function func;

        public:
          accumulate(container c, function f = add()) : cont(c), func(f) {}  

        class iterator {
           decltype(*(cont.begin())) sum;
           typename container::iterator current;
           typename container::iterator end;
           function func_it;

            public:
                iterator(typename container::iterator it, typename container::iterator e, function f) : sum(*it), current(it), end(e), func_it(f) {}
               auto operator*() const {
                    return sum;
                }
                iterator& operator++() {
                    ++current;
                    if(current != end)
                        sum = func_it(sum,*current);
                    return *this;
                }
               
                const iterator operator++(int) {
                    iterator temp = *this;
                    ++current;
                    if(current != end)
                        sum = func_it(sum,*current); 
                    return temp;
                    
                }
                bool operator==(const iterator& it) const {return current == it.current;}

                bool operator!=(const iterator& it) const {return current != it.current;}
        };

        iterator begin() {
            return iterator{cont.begin(),cont.end(), func};
        }

        iterator end() {
            return iterator{cont.end(),cont.end(), func};
        }
    };
}