#ifndef MASTERHEADER_H_
#define MASTERHEADER_H_

#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif


#include <iostream>
#include <fstream>
#include <iterator>
#include <thread>
#include <Windows.h>
#include <processthreadsapi.h>
#include <string>
#include <vector>
#include <conio.h>
#include <random>
#include <array>

#define MAX_LEVEL 5
#define MAX_BIRD 6
#define MAX_DINOSAUR 6
#define MAX_TRUCK 6
#define MAX_CAR 6
#define WIDTH 800
#define HEIGHT 600
#define TOP_EDGE 10
#define LOW_EDGE 30
#define LEFT_EDGE 20
#define RIGHT_EDGE 70

extern bool FINISH_FLAG;
#endif MASTERHEADER_H_
