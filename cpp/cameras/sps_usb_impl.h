#include "cameras/sps_usb.h"
#include <thread>
#include <iostream>

struct SpsUsb::Impl{
  bool initialize();  
  bool release();
  bool startRead(std::function<void(unsigned char*, int size)>callback);
  bool stopRead();

private:
  bool m_keepGoing;  
  std::thread m_thread;
  unsigned char m_buffer[256];
};

SpsUsb::SpsUsb() : m_impl(std::make_unique<Impl>()) {}

bool SpsUsb::initialize() {
  return m_impl->initialize();
}

bool SpsUsb::release() {
  return m_impl->release();
}

bool SpsUsb::startRead(std::function<void(unsigned char*, int size)>callback) {
  return m_impl->startRead(callback);
}

bool SpsUsb::stopRead() {
  return m_impl->stopRead();
}