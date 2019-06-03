# RBA Demo
Sample C code replicating how the Reverse Bottle Adventure glitch may have been implemented in Ocarina of Time

### Usage:
```
make
./rba
```

The current demo just shows ammo counts changing, but as long as the inventory struct is packed and ordered correctly, the code should work just fine for subsequent addresses.

Since this is intended to replicate a bug, and relies on undefined behavior, it comes with the obvious caveat of "may not work on every machine." It works for me, on this laptop, with this version of gcc, with these compiler flags. For demonstration/academic purposes, I'm just targeting x86(-64) and hoping for the best. If anybody wants to target MIPS architecture and see if we can get some bytecode that's *really* similar to what ended up in the OoT binary, be my guest.
