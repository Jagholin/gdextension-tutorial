#include "register_types.h"
#include "gdexample.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
        return;
    
    ClassDB::register_class<GDExample>();
}

void deinitialize_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
        return;
}

extern "C" {
    GDExtensionBool GDE_EXPORT library_init(GDExtensionInterfaceGetProcAddress p_get_proc, const GDExtensionClassLibraryPtr library, GDExtensionInitialization *initialization) {
        auto init_object = godot::GDExtensionBinding::InitObject(p_get_proc, library, initialization);

        init_object.register_initializer(initialize_module);
        init_object.register_terminator(deinitialize_module);
        init_object.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_object.init();
    }
}
