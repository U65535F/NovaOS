#include "../Include/stdint.h"
#include "../Graphics/graphics.h"
#include "../Font/text.h"
#include "../Interrupts/idt.h"
#include "../Timer/timer.h"
#include "../Drivers/keyboard.h"
#include "../Drivers/mouse.h"
#include "../Hardware/cpu.h"
#include "../Hardware/pci.h"
#include "../Hardware/disk.h"
#include "../Hardware/cmos.h"
#include "../FileSystem/memfs.h"
#include "../Shell/shell.h"
#include "../Userspace/GUI/gui.h"
#include "../Userspace/userspace.h"

void main(void)
{
    Debug("VESA 640x480 8BPP Started!\n", 0x00);

    Debug("Kernel loaded!\n", 0x00);
    
    SetupIDT();
    Debug("IDT Loaded!\n", 0x00);

    InitFileSystem();
    Debug("MemFS File System Loaded!\n", 0x00);

    InitTimer();
    Debug("Timer Started!\n", 0x00);

    InitKeyboard();
    Debug("Keyboard Started!\n", 0x00);

    InitMouse();
    Debug("Mouse Started!\n", 0x00);

    ShowCMOSMem();
    ListDisks();
    ShowCPUInfo();
    ShowPCIDevices();
    
    Sleep(2);

    ClearScreen();
    DrawBootScr();

    StartShellNoGUI();
    UserSpace();
}