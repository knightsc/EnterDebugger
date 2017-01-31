#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>

#ifndef EnterDebugger_hpp
#define EnterDebugger_hpp

class com_scottknight_EnterDebugger : public IOService
{
    OSDeclareDefaultStructors(com_scottknight_EnterDebugger)
    
public:
    virtual bool init (OSDictionary* dictionary = NULL) override;
    virtual void free (void) override;
    
    virtual IOService* probe (IOService* provider, SInt32* score) override;
    virtual bool start (IOService* provider) override;
    virtual void stop (IOService* provider) override;
};


#endif /* EnterDebuggerUserClient_hpp */
