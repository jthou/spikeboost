#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include "cameras/sps_usb.h"

namespace py = pybind11;

//class PySpsUsb {
//public:
//  PySpsUsb() {
//    m_sps_usb = SpsUsb::create();
//  }
//  bool initialize() {
//    return m_sps_usb->initialize();
//  }
//  bool release() {
//    return m_sps_usb->release();
//  }
//  //bool startRead(py::function callback) {
//  //  return m_sps_usb->startRead([callback](unsigned char* data, int size) {
//  //    callback(data, size);
//  //  });
//  //}
//  bool stopRead() {
//    return m_sps_usb->stopRead();
//  }
//private:
//  std::unique_ptr<SpsUsb> m_sps_usb;
//};

PYBIND11_MODULE(sps_usb_py, m) {
  py::class_<SpsUsb>(m, "SpsUsb")
    .def(py::init<>())
    .def("initialize", &SpsUsb::initialize)
    .def("release", &SpsUsb::release)
    //.def("start_read", &SpsUsb::startRead)
    .def("stop_read", &SpsUsb::stopRead);
}