#include "sps_usb_impl.h"
#include <iostream>
#include <chrono>

std::unique_ptr<SpsUsb> SpsUsb::create() {
  return std::make_unique<SpsUsb::Impl>();
}

bool SpsUsb::Impl::initialize() {
  std::cout << "[Device]Initializing" << std::endl;
  m_keepGoing = false;
  return true;
}

bool SpsUsb::Impl::release() {
  std::cout << "[Device]Releasing" << std::endl;
  return true;
}

bool SpsUsb::Impl::startRead(std::function<void(unsigned char*, int size)>callback) {
  std::cout << "[Device]Starting read" << std::endl;
  m_keepGoing = true;
  m_thread = std::thread([callback, this]() {
    while(m_keepGoing) {
      printf("[Device] Reading %p %d\n", m_buffer, 256);
      callback(m_buffer, 256);
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
  });
  return true;
}

bool SpsUsb::Impl::stopRead() {
  std::cout << "[Device]Stopping read" << std::endl;
  m_keepGoing = false;
  m_thread.join();
  return true;
}