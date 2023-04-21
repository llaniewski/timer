#include "timer.hpp"

//std::set<avg_timer*> avg_timer::all;

std::set<avg_timer*>& avg_timer::all() {
    static std::set<avg_timer*> all_;
    return all_;
}