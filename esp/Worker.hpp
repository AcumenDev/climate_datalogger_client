#ifndef WORKER_HPP
#define WORKER_HPP

class Worker {
  public:
    virtual    void setup() = 0;
    virtual    void loop() = 0;

};
#endif
