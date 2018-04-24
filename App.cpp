#include "stdafx.h"
#include "App.h"
#include <iostream>


App::App() : userIO(new UserIO())
{
   clock = new Clock(userIO->getExecTime());

   const auto semaphoreTime = userIO->getSemaphoreTime();
}


App::~App()
{
   delete clock;
   delete userIO;
}

void App::notifyAll()
{
   std::cout << "NOTIFYING" << std::endl;
}

void App::addEvent(const std::string description)
{
   events.push(new Event(clock->getCurrentTimeFormated(), description));
}
