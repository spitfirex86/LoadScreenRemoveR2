#include "framework.h"


#define C_SegCodePtr	((void*)0x401000)
#define C_SegCodeSize	0x9b000

__declspec(dllexport)
int ModMain( BOOL bInit )
{
	if ( bInit )
	{
		/* disable load screens */
		DWORD op, np = PAGE_EXECUTE_READWRITE;
		VirtualProtect(C_SegCodePtr, C_SegCodeSize, np, &op);

		*(unsigned char *)0x45F7E0 = 0xC3;
		*(unsigned char *)0x45F530 = 0xC3;
		*(unsigned char *)0x45EED0 = 0xC3;
		*(unsigned char *)0x45EDF0 = 0xC3;
		*(unsigned char *)0x45EE10 = 0xC3;

		VirtualProtect(C_SegCodePtr, C_SegCodeSize, op, &np);
	}
	else
	{
		/* no deinitialization */
	}

	return 0;
}
