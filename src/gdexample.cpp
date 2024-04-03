#include "gdexample.h"

using namespace godot;

void GDExample::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("_process", "delta"), &GDExample::_process);
}

GDExample::GDExample() {
    time_passed = 0.0;
}

GDExample::~GDExample() {
    // Destructor code here
}

void GDExample::_process(double delta) {
    time_passed += delta;
    // Add your processing code here

    Vector2 newPosition = Vector2(10.0 + (10.0 * sin(time_passed)), 10.0 + (10.0 * cos(time_passed)));
    set_position(newPosition);
}
