#ifndef TIMER_HPP
#include <chrono>
#include <thread>
#include <list>
#include <set>

class avg_timer {
    int n;
    double tot;
    public:
        static std::set<avg_timer*>& all();
        std::string name;
        avg_timer(std::string name_): name(name_), n(0), tot(0.0) { all().emplace(this);};
        ~avg_timer() { all().erase(this);};
        void add(double dt) { n += 1; tot += dt; }
        void print() { printf("%s: %lg (%lg/%d)\n", name.c_str(), tot/n, tot, n); }
};


template <class A> class timer {
public:
    static avg_timer avg;
    typedef std::chrono::time_point<std::chrono::steady_clock> timetype;
    timetype t1;
    timer() {
        t1 = std::chrono::steady_clock::now();
    }
    ~timer() {
        timetype t2 = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        double dt = ms_double.count();
        avg.add(dt);
    }
};

template <class A> avg_timer timer<A>::avg(A().name);

#define TIMER(_name) struct ttyp_##_name { const std::string name = #_name; }; timer< ttyp_##_name > tvar_##_name;

#endif // TIMER_HPP