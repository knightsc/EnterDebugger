# EnterDebugger

On macOS, when you have kernel debugging set up there are two ways to trigger
a NMI. One is the two command buttons and the power button (this doesn't seem
to work in VMs) the other is Cmd-Opt-Ctrl-Shift-Esc. The Esc key combination
seems to not work after upgrading to Sierra so this kext provides a way
to trigger the needed call to PE_enter_debugger. Additionally there is
an Automator service include to call the user space client that can then
be bound to a keystroke.

See https://computers.tutsplus.com/tutorials/how-to-launch-any-app-with-a-keyboard-shortcut--mac-31463
for more info on the Automator service.