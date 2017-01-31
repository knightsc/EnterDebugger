#include <IOKit/IOLib.h>
#include <IOKit/IOUserClient.h>
#include "EnterDebugger.hpp"
#include "EnterDebuggerUserClientShared.h"

#ifndef EnterDebuggerUserClient_hpp
#define EnterDebuggerUserClient_hpp

class com_scottknight_EnterDebuggerUserClient : public IOUserClient
{
    OSDeclareDefaultStructors(com_scottknight_EnterDebuggerUserClient)
    
private:
    task_t m_task;
    bool m_taskIsAdmin;
    com_scottknight_EnterDebugger* m_driver;
    
public:
    virtual bool initWithTask (task_t owningTask, void* securityToken, UInt32 type, OSDictionary* properties) override;
    virtual bool start (IOService* provider) override;
    virtual IOReturn clientClose (void) override;
    virtual void stop (IOService* provider) override;
    virtual void free (void) override;
    
    IOReturn externalMethod(uint32_t selector, IOExternalMethodArguments *args, IOExternalMethodDispatch *dispatch,
                            OSObject *target, void *reference) override;
    
protected:
    static const IOExternalMethodDispatch sMethods[kEnterDebuggerRequestMethodCount];
    
    static IOReturn sEnterDebugger(OSObject *target, void *reference, IOExternalMethodArguments *args);
};

#endif /* EnterDebuggerUserClient_hpp */
