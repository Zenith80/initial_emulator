#include <CPU/peripherals/DeviceController.hpp>
#include <zenith80.hpp>

#include <CPU/peripherals/GenericDevice.hpp>

#include "./Screen.cpp"
#include "./Keyboard.cpp"
#include "./Z80Controller.cpp"

ZENITH_HEADER

DeviceController::DeviceController(){
	devices=new vector<Z80Device*>;
	devices->push_back(new GenericDevice(&screenOutput,nullptr));
	devices->push_back(new GenericDevice(&integerOutput,&keyboardInput));
	devices->push_back(new GenericDevice(&Z80Controller,nullptr));
	int i=2;
	for(;i<65535;i++)
		devices->push_back(new GenericDevice(nullptr,nullptr));
}

void DeviceController::out(uint16_t port,uint8_t value){
	(*this->devices)[port]->out(value);
}

uint8_t DeviceController::in(uint16_t port){
	return (*this->devices)[port]->in();
}

ZENITH_FOOTER
