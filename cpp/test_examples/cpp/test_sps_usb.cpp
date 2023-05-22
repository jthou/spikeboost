#include <Windows.h>
#include <iostream>
#include "cameras/sps_usb.h"

void callback(unsigned char* data, int size) {
    std::cout << "[Device]Callback" << std::endl;
} 

int main(int argc, char **argv)
{
    std::cout << "sps usb test cpp" << std::endl;
    auto sps_usb = SpsUsb::create();
    sps_usb->initialize();
    sps_usb->startRead(callback);
    Sleep(2000);
    sps_usb->stopRead();
    sps_usb->release();
    return 0;
}