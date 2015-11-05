#include "Core/Timer.h"
#include "Util/Definitions.h"

Timer::Timer() {}

void Timer::Start() {
     start_ticks_ = std::chrono::high_resolution_clock::now();
}

void Timer::Reset() {
    start_ticks_ = std::chrono::high_resolution_clock::now();
}

void Timer::Update() {
    delta_time_ = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_ticks_).count();
    start_ticks_ = std::chrono::high_resolution_clock::now();
}

float32 Timer::DeltaTime() {
    //std::cout << delta_time_ << std::endl;
    return delta_time_;
}