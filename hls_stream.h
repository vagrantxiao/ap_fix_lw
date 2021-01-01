
#include <queue>
#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <cxxabi.h>
#include <stdlib.h>

namespace hls {

template<typename __STREAM_T__, int SIZE=102400>
class stream
{
  protected:
	std::string _name;
	__STREAM_T__ _data[SIZE];
	unsigned int _head = 0;
	unsigned int _tail = 0;
  public:
    /// Constructors
    // Keep consistent with the synthesis model's constructors
    stream() {

    }

    stream(const std::string name) {
    // default constructor,
    // capacity set to predefined maximum
        _name = name;
    }

  public:
    /// Destructor
    /// Check status of the queue
    virtual ~stream() {
       ;
    }



    __STREAM_T__ read() {
        __STREAM_T__ elem;
        if(_tail==SIZE-1){
			elem = _data[_tail];
			_tail = 0;
			std::cout<< _name << ": fifo empty!" << std::endl;
		} else if(_tail==_head){
			elem = _data[_tail];
			std::cout<< _name << ": empty!" << std::endl;
		} else {
			//std::cout<< _name << " tail = " << _tail << std::endl;
			elem = _data[_tail];
			_tail++;
		}
        return elem;
    }

    /// Blocking write
    void write(const __STREAM_T__& tail) { 
		if(_head==SIZE-1){
			_data[_head]=tail;
			_head = 0;
			std::cout<< _name << " full!" << std::endl;
		} else {
			_data[_head]=tail;
			//std::cout<< _name << " head = " << _head << std::endl;
			_head++;

		}

    }

    void write(unsigned int tail) {
		if(_head==SIZE-1){
			_data[_head].data=tail;
			_head = 0;
			std::cout<< _name << " full!" << std::endl;
		} else {
			_data[_head].data=tail;
			//std::cout<< _name << " head = " << _head << std::endl;
			_head++;
		}

    }

};

} // namespace hls



