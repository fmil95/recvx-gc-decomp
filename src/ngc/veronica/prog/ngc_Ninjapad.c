#include "structs.h"

// TODO: move the typedef below elsewhere
typedef PDS_PERIPHERAL NJS_PERIPHERAL;

const NJS_PERIPHERAL* njGetPeripheral(Uint32 port);

const NJS_PERIPHERAL* njGetPeripheral(Uint32 port)
{ 
    pdGetPeripheral(port);
}
