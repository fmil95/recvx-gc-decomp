#include <sg_xpt.h>

// TODO: move two structs below elsewhere

typedef struct 
{
	Uint32 type;            
	Uint32 reserved[3];       
	Uint8 is_root;            
	Uint8 area_code;           
	Uint8 connector_dir[2];   
	char product_name[32];     
	char license[64];        
	Uint16 stdby_pow;     
	Uint16 max_pow;            
} PDS_PERIPHERALINFO;

typedef struct 
{
	Uint32 id;                            
	Uint32 support;                       
	Uint32 on;                            
	Uint32 off;                           
	union 
    {
		Uint32 push;                      
		Uint32 press;
	};
	union
    {
		Uint32 pull;                      
		Uint32 release;
	};
	Uint16 r;                             
	Uint16 l;                             
	Sint16 x1;                            
	Sint16 y1;                            
	Sint16 x2;                            
	Sint16 y2;                        
	char* name;                       
	void* extend;                      
	Uint32 old;                        
	PDS_PERIPHERALINFO* info;         
} PDS_PERIPHERAL;

typedef PDS_PERIPHERAL NJS_PERIPHERAL;

const NJS_PERIPHERAL* njGetPeripheral(Uint32 port);

const NJS_PERIPHERAL* njGetPeripheral(Uint32 port)
{ 
    pdGetPeripheral(port);
}
