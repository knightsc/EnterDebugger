#include "EnterDebuggerUserClient.hpp"

#define super IOUserClient

OSDefineMetaClassAndStructors(com_scottknight_EnterDebuggerUserClient, IOUserClient)

const IOExternalMethodDispatch
com_scottknight_EnterDebuggerUserClient::sMethods[kEnterDebuggerRequestMethodCount] =
{    
    { sEnterDebugger, 0, 0, 0, 0 }
};

bool com_scottknight_EnterDebuggerUserClient::initWithTask (task_t owningTask, void* securityToken, UInt32 type, OSDictionary* properties)
{
    if (!owningTask) {
        return false;
    }
    
    if (! super::initWithTask(owningTask, securityToken , type, properties)) {
        return false;
    }
    
    m_task = owningTask;
    
    IOReturn ret = clientHasPrivilege(securityToken, kIOClientPrivilegeAdministrator);
    if ( ret == kIOReturnSuccess ) {
        m_taskIsAdmin = true;
    }
    
    return true;
}

void com_scottknight_EnterDebuggerUserClient::free (void)
{
    super::free();
}


bool com_scottknight_EnterDebuggerUserClient::start (IOService* provider)
{
    if (! super::start(provider)) {
        return false;
    }
    
    m_driver = OSDynamicCast(com_scottknight_EnterDebugger, provider);
    
    if (!m_driver) {
        return false;
    }
    
    return true;
}

IOReturn com_scottknight_EnterDebuggerUserClient::clientClose (void)
{
    terminate();
    return kIOReturnSuccess;
}

void com_scottknight_EnterDebuggerUserClient::stop (IOService *provider)
{
    super::stop(provider);
}

IOReturn com_scottknight_EnterDebuggerUserClient::externalMethod (uint32_t selector, IOExternalMethodArguments* arguments,
                                                                   IOExternalMethodDispatch* dispatch, OSObject* target,
                                                                   void* reference)
{
    // Ensure the requested control selector is within range.
    if (selector >= kEnterDebuggerRequestMethodCount) {
        return kIOReturnUnsupported;
    }
    
    dispatch = (IOExternalMethodDispatch*)&sMethods[selector];
    target = this;
    reference = NULL;
    
    return super::externalMethod(selector, arguments, dispatch, target, reference);
}

IOReturn com_scottknight_EnterDebuggerUserClient::sEnterDebugger(OSObject *target, void *reference, IOExternalMethodArguments *args)
{
    IOLog("EnterDebuggerUserClient::sEnterDebugger\n");
    PE_enter_debugger("EnterDebugger.kext");
    return KERN_SUCCESS;
}
