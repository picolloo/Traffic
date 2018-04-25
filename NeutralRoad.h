#ifndef INCLUDED_NEUTRALROAD_H
#define INCLUDED_NEUTRALROAD_H

#pragma once

#include "Road.h"

class NeutralRoad : public Road
{
public:
   ~NeutralRoad() = default;
   NeutralRoad(const int _vel,
      const int _length,
      const int semaphoreTimer) :
      Road(_vel, _length, semaphoreTimer)
   {}  

   void getNotify(const int time) override;

};

#endif