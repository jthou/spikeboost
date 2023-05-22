#include <memory>
#include <functional>

class SpsUsb {
public:
  virtual bool initialize();
  virtual bool release();
  virtual bool startRead(std::function<void(unsigned char*, int size)>callback);
  virtual bool stopRead();
  SpsUsb();
  virtual ~SpsUsb() = default;
private:
  struct Impl;
  std::unique_ptr<Impl> m_impl;
};