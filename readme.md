# Application for reproducing msgpack_0.5.7 bug #1469090

Link: https://bugs.launchpad.net/ubuntu/+source/msgpack/+bug/1469090

## Testing environment
```bash
docker run -ti --name=msgpack-bug-1469090 ubuntu:utopic bash
apt-get install libmsgpack-dev
apt-get install git
apt-get install cmake
apt-get install valgrind
apt-get install g++
```
## Usage
```bash
git clone https://github.com/shilkin/msgpack_0.5.7-bug-1469090.git
cd msgpack_0.5.7-bug-1469090
cmake .
make
make check
tail ./valgrind.log
```
## Valgrind output
```bash
==4656== 1 errors in context 1 of 1:
==4656== Mismatched free() / delete / delete []
==4656==    at 0x4C2C2E0: operator delete(void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4656==    by 0x40302B: std::auto_ptr<msgpack::zone>::reset(msgpack::zone*) (in /root/msgpack_0.5.7-bug-1469090/msgpack_0.5.7-bug-1469090-reproduce)
==4656==    by 0x402BD8: msgpack::unpacker::next(msgpack::unpacked*) (in /root/msgpack_0.5.7-bug-1469090/msgpack_0.5.7-bug-1469090-reproduce)
==4656==    by 0x402807: main (in /root/msgpack_0.5.7-bug-1469090/msgpack_0.5.7-bug-1469090-reproduce)
==4656==  Address 0x5c3f920 is 0 bytes inside a block of size 8,248 alloc'd
==4656==    at 0x4C2ABA0: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4656==    by 0x4E3AAD1: msgpack_zone_new (in /usr/lib/libmsgpack.so.3.0.0)
==4656==    by 0x4E39229: msgpack_unpacker_init (in /usr/lib/libmsgpack.so.3.0.0)
==4656==    by 0x402A31: msgpack::unpacker::unpacker(unsigned long) (in /root/msgpack_0.5.7-bug-1469090/msgpack_0.5.7-bug-1469090-reproduce)
==4656==    by 0x402733: main (in /root/msgpack_0.5.7-bug-1469090/msgpack_0.5.7-bug-1469090-reproduce)
```

## Conclusion
Mixing malloc/delete in msgpack::unpacker::next() causes an undefined behaviour. It's a serious problem for production systems.
In msgpack 0.5.9 many bugs are fixed. Maybe it's a time to bump version of msgpack in ubuntu repo?

