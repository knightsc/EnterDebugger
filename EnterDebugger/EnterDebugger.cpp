#include "EnterDebugger.hpp"

#define super IOService

OSDefineMetaClassAndStructors(com_scottknight_EnterDebugger, IOService)

bool com_scottknight_EnterDebugger::init (OSDictionary* dict)
{
    bool res = super::init(dict);
    IOLog("EnterDebugger::init\n");
    return res;
}

void com_scottknight_EnterDebugger::free (void)
{
    IOLog("EnterDebugger::free\n");
    super::free();
}

IOService* com_scottknight_EnterDebugger::probe (IOService* provider, SInt32* score)
{
    IOService *res = super::probe(provider, score);
    IOLog("EnterDebugger::probe\n");
    return res;
}

bool com_scottknight_EnterDebugger::start (IOService *provider)
{
    bool res = super::start(provider);
    IOLog("EnterDebugger::start\n");
    
    super::registerService();
    
    return res;
}

void com_scottknight_EnterDebugger::stop (IOService *provider)
{
    IOLog("EnterDebugger::stop\n");
    super::stop(provider);
}
